<template>
  <div>
    <van-popup v-model="show" :round="true">
      <div class="sk_box">
        <div class="leftBox">
          <div class="title">收款信息</div>
          <div class="items">
            <div class="name">手机号</div>
            <div class="val" @click="inputType = 'phone'">
              {{ phone }}
              <span class="inputLine" v-if="inputType == 'phone'"></span>
            </div>
          </div>
          <div class="items">
            <div class="name">订单金额（元）</div>
            <div class="val" @click="inputType = 'price'">
              {{ price }}
              <span class="inputLine" v-if="inputType == 'price'"></span>
            </div>
          </div>
        </div>
        <div class="rightBox">
          <keyboard
            @keyClick="inputKeyClick"
            @done="inputDone"
            @del="inputDel"
          />
        </div>
      </div>
    </van-popup>
    <van-popup
      v-model="codeWaitShow"
      :round="true"
      :close-on-click-overlay="false"
    >
      <div class="waitBox">
        <input
          style="opacity: 0; position: absolute; top: 0"
          v-model="payCode"
          ref="payCodeInput"
          type="text"
          @keypress.enter="toPay"
        />
        <div class="title">等待顾客扫码支付</div>
        <div class="waitImg">
          <img src="@/assets/codeWait.gif" alt="" />
        </div>
        <div class="btn" @click="cancel">{{waitBtnText}}</div>
      </div>
    </van-popup>
    <van-popup
      v-model="codeSuccessShow"
      :round="true"
      :close-on-click-overlay="false"
    >
      <div class="waitBox">
        <div class="title">收款信息</div>
        <div class="successImg">
          <img src="@/assets/codeSuccess.png" alt="" />
        </div>
        <div class="successText">{{ successText }}</div>
        <div class="btn" @click="back('success')">{{ time }}s后自动返回</div>
      </div>
    </van-popup>
    <van-popup
      v-model="codeFailShow"
      :round="true"
      :close-on-click-overlay="false"
    >
      <div class="waitBox">
        <div class="title">收款信息</div>
        <div class="successImg">
          <img src="@/assets/codeFail.png" alt="" />
        </div>
        <div class="successText">{{ failText }}</div>
        <div class="btn" @click="back('fail')">{{ time }}s后自动返回</div>
      </div>
    </van-popup>
  </div>
</template>

<script>
import { payForMoney, payStatusGet } from "@/api/pay";
import { printPayInfo } from "@/api/printer";
import { xflx } from "@/utils/pay";
import keyboard from "@/components/keyboard";
export default {
  data() {
    return {
      show: false,
      codeWaitShow: false,
      codeSuccessShow: false,
      codeFailShow: false,
      timer: null,
      time: null,

      inputType: "",
      phone: "",
      price: "",
      payCode: "",
      waitBtnText: "取消",
      waitTimer: null,
      successText: "付款已完成",
      failText: "付款失败",
    };
  },
  watch: {
    show(newVal) {
      if (newVal) {
        this.phone = "";
        this.price = "";
      }
    },
    codeWaitShow(newVal) {
      if (newVal) {
        this.waitBtnText = "取消";
        this.$nextTick(() => {
          this.$refs.payCodeInput.focus();
        });
      } else {
        this.$refs.payCodeInput.blur();
        this.payCode = "";
      }
    },
    codeSuccessShow(newVal) {
      if (newVal) {
        this.showTimer("success");
      }
    },
    codeFailShow(newVal) {
      if (newVal) {
        this.showTimer("fail");
      }
    },
  },
  components: {
    keyboard,
  },
  methods: {
    cancel() {
      if (this.waitBtnText != "取消") return;
      this.codeWaitShow = false;
    },
    inputKeyClick(e) {
      console.log(e);
      if (e == null) {
        if (this.inputType == "phone") {
          this.phone = "";
        } else if (this.inputType == "price") {
          this.price = "";
        }
      } else {
        if (this.inputType == "phone") {
          this.phone += e;
        } else if (this.inputType == "price") {
          this.price += e;
        }
      }
    },
    inputDone() {
      if (this.price == "") {
        this.$message({
          message: "请输入金额",
          type: "warn",
        });
        return;
      }
      this.inputType = "";
      this.show = false;
      this.codeWaitShow = true;
    },
    inputDel() {
      if (this.inputType == "phone") {
        if (this.phone.length)
          this.phone = this.phone.substr(0, this.phone.length - 1);
      } else if (this.inputType == "price") {
        if (this.price.length)
          this.price = this.price.substr(0, this.price.length - 1);
      }
    },
    toPay(e) {
      this.$refs.payCodeInput.blur();
      console.log(this.payCode);
      const payCode = this.payCode;
      this.payCode = "";
      console.log(payCode);
      const orderNum = "orderstr" + new Date().getTime();
      let data = {
        member_mobile: this.phone,
        xfje: this.price,
        sn: payCode,
        ddh: orderNum,
      };
      payForMoney(data).then((res) => {
        console.log(res);
        if (res.code == 200) {
          if (res.datas.res.sub_resp_code == "00000000") {
            this.codeWaitShow = false;
            this.successText = res.datas.res.sub_resp_desc;
            this.codeSuccessShow = true;
            console.log(res);
          } else if (res.datas.res.sub_resp_code == "00000100") {
            this.waitBtnText = "交易正在处理中...";
            let intervalCount = 0;
            this.waitTimer = setInterval(() => {
              if(intervalCount < 60) // 最多查询后台接口一分钟
                this.getPayStatus(orderNum);
              else
                clearInterval(this.waitTimer);
            }, 1000);
          } else {
            this.codeWaitShow = false;
            this.failText = res.datas.res.sub_resp_desc;
            this.codeFailShow = true;
          }
        }
      });
    },
    showTimer(type) {
      this.time = 5;
      this.timer = setInterval(() => {
        this.time--;
        console.log(this.time);
        if (this.time == 0) {
          clearInterval(this.timer);
          if (type == "success") {
            this.codeSuccessShow = false;
          } else {
            this.codeFailShow = false;
          }
        }
      }, 1000);
    },
    back(type) {
      if (this.timer) {
        clearInterval(this.timer);
      }
      if (type == "success") {
        this.codeSuccessShow = false;
      } else {
        this.codeFailShow = false;
      }
    },
    getPayStatus(orderStr) {
      let data = {
        ddh: orderStr,
      };
      payStatusGet(data).then((res) => {
        if (res.code == 200) {
          if (res.datas.res.sub_resp_code == "00000000") {
            clearInterval(this.waitTimer);
            this.codeWaitShow = false;
            this.successText = res.datas.res.sub_resp_desc;
            this.codeSuccessShow = true;
            let data = res.data.data.list;
            printPayInfo({store_name:res.datas.store_name, print_text:`
              支付场景：反扫支付\n
              订单金额：${data.xfze}\n
                券抵扣：${data.xjq}\n
              红包抵扣：${data.pd}\n
              实付金额：${data.xfje}\n
              推广提成：${data.tgfz}\n
                服务费：${data.fwf}\n
              下单用户：${data.member_name}\n
              下单日期：${data.addtime}\n
              支付方式：${xflx(data.xflx)}\n
              订单编号：${orderStr}\n
            `});
          } else if (res.datas.res.sub_resp_code == "00000100") {
          } else {
            clearInterval(this.waitTimer);
            this.codeWaitShow = false;
            this.failText = res.datas.res.sub_resp_desc;
            this.codeFailShow = true;
          }
        }
      });
    },
  },
};
</script>

<style lang='scss' scoped>
.sk_box {
  width: 712px;
  height: 352px;
  background: #ffffff;
  box-shadow: 0px 4px 12px 0px rgba(14, 92, 133, 0.1);
  border-radius: 8px;
  display: flex;

  .leftBox {
    width: 50%;
    padding: 24px 32px 0 32px;
    box-sizing: border-box;

    .title {
      text-align: center;
      font-size: 20px;
      font-family: PingFangSC-Medium, PingFang SC;
      font-weight: 500;
      color: #333333;
      line-height: 20px;
    }

    .items {
      margin-top: 32px;

      .name {
        font-size: 16px;
        font-family: PingFangSC-Regular, PingFang SC;
        font-weight: 400;
        color: #333333;
        line-height: 16px;
      }

      .val {
        width: 100%;
        height: 52px;
        background: #ffffff;
        border-radius: 4px;
        border: 1px solid #e5e5e5;
        font-size: 20px;
        font-family: PingFangSC-Semibold, PingFang SC;
        font-weight: 600;
        color: #333333;
        padding-left: 16px;
        display: flex;
        align-items: center;
        margin-top: 14px;
      }
    }
  }

  .rightBox {
    width: 50%;
    background: #f3f4f5;
    display: flex;
    align-items: center;
    justify-content: center;
  }
}

.waitBox {
  width: 356px;
  height: 352px;
  background: #ffffff;
  box-shadow: 0px 4px 12px 0px rgba(14, 92, 133, 0.1);
  border-radius: 8px;
  padding: 24px 32px 0 32px;

  .title {
    font-size: 20px;
    font-family: PingFangSC-Medium, PingFang SC;
    font-weight: 500;
    color: #333333;
    line-height: 20px;
    text-align: center;
  }

  .waitImg {
    width: 156px;
    height: 154px;
    margin: auto;
    margin-top: 36px;

    img {
      width: 100%;
      height: 100%;
    }
  }

  .successImg {
    width: 108px;
    height: 108px;
    margin: auto;
    margin-top: 38px;

    img {
      width: 100%;
      height: 100%;
    }
  }

  .successText {
    font-size: 16px;
    font-family: PingFangSC-Regular, PingFang SC;
    font-weight: 400;
    color: #333333;
    line-height: 16px;
    margin-top: 20px;
    text-align: center;
  }

  .btn {
    width: 100%;
    height: 48px;
    background: #00bfff;
    border-radius: 4px;
    margin-top: 38px;
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 16px;
    font-family: PingFangSC-Medium, PingFang SC;
    font-weight: 500;
    color: #ffffff;
  }
}
</style>