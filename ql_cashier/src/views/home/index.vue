<template>
  <div class="">
    <headerTop></headerTop>
    <div class="containers">
      <div class="wrapBox">
        <div class="smallBox">
          <div class="small" @click="toZH">
            <img src="@/assets/sjzh.png" alt="" />
            <div class="text">商家账户</div>
          </div>
          <div class="small" @click="toJL">
            <img src="@/assets/skjl.png" alt="" />
            <div class="text">收款记录</div>
          </div>
          <div class="small" @click="toGL">
            <img src="@/assets/hygl.png" alt="" />
            <div class="text">会员管理</div>
          </div>
          <div class="small" @click="toHZ">
            <img src="@/assets/sjhz.png" alt="" />
            <div class="text">数据汇总</div>
          </div>
        </div>
        <div class="big" @click="pay">
          <img src="@/assets/sk.png" alt="" />
          <div class="text">收款</div>
        </div>
      </div>
    </div>
    <Pay ref="pay"/>
  </div>
</template>

<script>
import headerTop from "@/components/header";
import Pay from '@/components/pay'
export default {
  data() {
    return {
      
    };
  },
  watch: {
    
  },
  components: {
    headerTop,
    Pay
  },
  methods: {
    toZH() {
      this.$router.push({
        path: "/admin/merchants",
      });
    },
    toJL() {
      this.$router.push({
        path: "/admin/collection",
      });
    },
    toGL() {
      this.$router.push({
        path: "/admin/members",
      });
    },
    toHZ() {
      this.$router.push({
        path: "/admin/dataHZ",
      });
    },
    pay() {
      this.$refs.pay.show = true;
    },
  },
};
</script>

<style lang='scss' scoped>
.containers {
  width: 100%;
  height: calc(100vh - 48px);
  background: url("../../assets/homeBg.png") no-repeat;
  background-size: 100% 100%;
  display: flex;
  justify-content: center;

  .wrapBox {
    margin-top: 181px;
    display: flex;

    .smallBox {
      width: 336px;
      height: 296px;
      display: flex;
      flex-wrap: wrap;

      .small {
        width: 152px;
        height: 140px;
        background: #f1faff;
        box-shadow: 0px 4px 12px 0px rgba(14, 92, 133, 0.1);
        border-radius: 8px;
        margin-right: 16px;
        margin-bottom: 16px;
        text-align: center;

        img {
          width: 64px;
          height: 64px;
          margin-top: 25px;
        }

        .text {
          font-size: 16px;
          font-family: PingFangSC-Regular, PingFang SC;
          font-weight: 400;
          color: #333333;
          line-height: 16px;
          margin-top: 10px;
        }
      }
    }

    .big {
      width: 236px;
      height: 296px;
      background: #f1faff;
      box-shadow: 0px 4px 12px 0px rgba(14, 92, 133, 0.1);
      border-radius: 8px;
      text-align: center;

      img {
        width: 92px;
        height: 92px;
        margin-top: 86px;
      }

      .text {
        font-size: 20px;
        font-family: PingFangSC-Regular, PingFang SC;
        font-weight: 400;
        color: #333333;
        line-height: 20px;
        margin-top: 12px;
      }
    }
  }
}
</style>