<template>
  <div class="page">
    <div class="payHeader">
      <div class="payType">
        <div class="payItem" :class="{ payItem_active: payType == 1 }" @click="changePayType(1)">
          支付宝
        </div>
        <div class="payItem" :class="{ payItem_active: payType == 2 }" @click="changePayType(2)">
          微信
        </div>
        <div class="payItem" :class="{ payItem_active: payType == 3 }" @click="changePayType(3)">
          红包
        </div>
      </div>
      <!-- <div class="payBtn">发起收款</div> -->
    </div>
    <div class="wrapBox">
      <div class="screeningBox">
        <div class="screeningLeft">
          <div class="leftItem">
            <span class="title">手机号：</span>
            <el-popover placement="bottom-start" width="360" trigger="click">
              <div class="inputBox" slot="reference">{{ phone }}</div>
              <div
                class="keyboard_box"
                style="display: flex; justify-content: center"
              >
                <keyboard
                  @keyClick="inputKeyClick"
                  @done="inputDone"
                  @del="inputDel"
                />
              </div>
            </el-popover>
          </div>
          <div class="leftItem">
            <span class="title">时间段：</span>
            <el-date-picker
              style="height: 36px"
              v-model="value1"
              type="daterange"
              range-separator="至"
              start-placeholder="开始日期"
              end-placeholder="结束日期"
              @change="dateChange"
            >
            </el-date-picker>
          </div>
        </div>
        <div class="screeningRight">
          <div class="searchBtn" @click="search">查询</div>
        </div>
      </div>
      <div class="listBox">
        <div class="listItem" v-for="(item, index) in list" :key="index">
          <div class="itemHeader">
            <div class="user">付款者：{{item.member_name}}（{{item.member_mobile}}）</div>
            <div class="right">
              <span class="_right">消费券抵扣：{{item.xjq}}元</span>
              <span class="_right">店内折扣：{{item.zkje}}元</span>
              <span class="_right">服务费：{{item.fwf}}元</span>
              <span class="_right">推广费：{{item.tgfz}}元</span>
            </div>
          </div>
          <div class="itemWrap">
            <div class="wrapCont payTime">
              <div class="name">支付时间</div>
              <div class="val">{{item.addtime}}</div>
            </div>
            <div class="wrapCont">
              <div class="name">订单金额(元)</div>
              <div class="val">{{item.xfze}}</div>
            </div>
            <div class="wrapCont">
              <div class="name">订单类型</div>
              <div class="val">{{item.xflx}}</div>
            </div>
            <div class="wrapCont">
              <div class="name">支付方式</div>
              <div class="val">{{item.xflx1}}</div>
            </div>
            <div class="wrapCont">
              <div class="name">实际支付(元)</div>
              <div class="val">{{item.xfje}}</div>
            </div>
            <div class="wrapCont">
              <div class="name">实际到账(元)</div>
              <div class="val blue">{{item.jsje}}</div>
            </div>
          </div>
        </div>
      </div>
      <div class="pageBox">
        <el-pagination
          background
          :current-page="currentPage"
          :page-size.sync="pageSize"
          layout="prev, pager, next"
          :total="total"
          @current-change="currentChange"
        >
        </el-pagination>
      </div>
    </div>
  </div>
</template>

<script>
import { payLog } from "@/api/pay";
import keyboard from "@/components/keyboard";
export default {
  data() {
    return {
      payType: 1,
      value1: "",

      phone: "",
      startTime: "",
      endTime: "",
      list: [],
      total: 0,
      pageSize: 4,
      currentPage: 1,
    };
  },
  components: {
    keyboard,
  },
  created() {
    this.getList();
  },
  methods: {
    getList() {
      let data = {
        lx: this.payType,
        curpage: this.currentPage,
        page: this.pageSize,
        member_mobile: this.phone,
        query_start_date: this.startTime,
        query_end_date: this.endTime,
      };
      payLog(data).then((res) => {
        if (res.code == 200) {
          this.list = res.datas.list;
          this.total = res.datas.total * 1;
        }
      });
    },
    search() {
      this.currentPage = 1;
      this.getList();
    },
    inputKeyClick(e) {
      console.log(e);
      if (e == null) {
        this.phone = "";
      } else {
        this.phone += e;
      }
    },
    inputDone() {},
    inputDel() {
      if (this.phone.length)
        this.phone = this.phone.substr(0, this.phone.length - 1);
    },
    dateChange(e) {
      console.log(e);
      this.startTime = e[0];
      this.endTime = e[1];
    },
    currentChange(e) {
      this.currentPage = e;
      this.getList();
      console.log(this.currentPage);
    },
    changePayType(e){
      this.payType=e
      this.getList()
    }
  },
};
</script>

<style lang='scss' scoped>
.page {
  width: 100%;
  height: 100%;
  background: #ffffff;
  border-radius: 4px;
}

.payHeader {
  width: 100%;
  height: 68px;
  padding: 0 16px;
  border-bottom: 1px solid #eeeeee;
  display: flex;
  align-items: center;
  justify-content: space-between;

  .payType {
    display: flex;
    align-items: center;

    .payItem {
      width: 80px;
      height: 36px;
      background: #ffffff;
      border-radius: 4px;
      border: 1px solid #e5e5e5;
      display: flex;
      align-items: center;
      justify-content: center;
      font-size: 14px;
      font-family: PingFangSC-Regular, PingFang SC;
      font-weight: 400;
      color: #333333;
      margin-right: 8px;
    }

    .payItem_active {
      background: #00bfff;
      color: #ffffff;
    }
  }

  .payBtn {
    width: 88px;
    height: 36px;
    background: #00bfff;
    border-radius: 4px;
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 14px;
    font-family: PingFangSC-Regular, PingFang SC;
    font-weight: 400;
    color: #ffffff;
  }
}

.wrapBox {
  width: 100%;
  padding: 0 16px;

  .screeningBox {
    width: 100%;
    height: 68px;
    display: flex;
    align-items: center;
    justify-content: space-between;

    .screeningLeft {
      display: flex;
      align-items: center;

      .leftItem {
        display: flex;
        align-items: center;
        margin-left: 32px;

        &:first-child {
          margin-left: 0;
        }

        .title {
          font-size: 14px;
          font-family: PingFangSC-Regular, PingFang SC;
          font-weight: 400;
          color: #333333;
        }

        .inputBox {
          width: 185px;
          height: 36px;
          background: #ffffff;
          border-radius: 4px;
          border: 1px solid #e5e5e5;
          padding-left: 16px;
          display: flex;
          align-items: center;
          font-size: 14px;
          font-family: PingFangSC-Regular, PingFang SC;
          font-weight: 400;
          color: #bbbbbb;
        }
      }
    }

    .screeningRight {
      .searchBtn {
        width: 60px;
        height: 36px;
        background: #00bfff;
        border-radius: 4px;
        display: flex;
        align-items: center;
        justify-content: center;
        font-size: 14px;
        font-family: PingFangSC-Regular, PingFang SC;
        font-weight: 400;
        color: #ffffff;
      }
    }
  }

  .listBox {
    width: 100%;

    .listItem {
      margin-top: 8px;
      width: 100%;
      border: 1px solid #eceef3;
      border-radius: 4px;

      &:first-child {
        margin-top: 0;
      }

      .itemHeader {
        width: 100%;
        background: #f5f7fa;
        height: 40px;
        padding: 0 16px;
        display: flex;
        align-items: center;
        justify-content: space-between;

        .user {
          font-size: 14px;
          font-family: PingFangSC-Regular, PingFang SC;
          font-weight: 400;
          color: #333333;
        }

        .right {
          ._right {
            font-size: 12px;
            font-family: PingFangSC-Regular, PingFang SC;
            font-weight: 400;
            color: #666666;
            margin-left: 24px;
          }
        }
      }

      .itemWrap {
        width: 100%;
        height: 62px;
        display: flex;

        .wrapCont {
          width: 140px;
          height: 100%;
          border-right: 1px solid #eceef3;
          padding-top: 12px;

          &:last-child {
            border-right: none;
          }

          .name {
            text-align: center;
            font-size: 12px;
            font-family: PingFangSC-Regular, PingFang SC;
            font-weight: 400;
            color: #666666;
            line-height: 12px;
          }

          .val {
            text-align: center;
            font-size: 16px;
            font-family: PingFangSC-Semibold, PingFang SC;
            font-weight: 600;
            color: #333333;
            line-height: 16px;
            margin-top: 10px;
          }

          .blue {
            color: #00bfff;
          }
        }

        .payTime {
          flex: 1;
        }
      }
    }
  }
}

.pageBox {
  width: 100%;
  display: flex;
  justify-content: flex-end;
  margin-top: 16px;
}
</style>
<style lang="scss">
.el-pagination {
  li {
    height: 30px;
    line-height: 30px;
  }

  button {
    height: 30px;
    line-height: 30px;
  }
}
</style>