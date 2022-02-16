<template>
  <div>
    <div class="topBox">
      <div class="topItem">
        <div class="itemTitle">今日消费金额</div>
        <div class="itemMsg">
          <span class="moneyIcon">¥</span>
          <span class="val">{{ topData.jr_xfje }}</span>
          <span class="green" v-if="topData.jr_xfje > topData.zr_xfje"
            >+{{ topData.jr_xfje - topData.zr_xfje }}</span
          >
          <span class="red" v-if="topData.zr_xfje > topData.jr_xfje"
            >-{{ (topData.zr_xfje - topData.jr_xfje).toFixed(2) }}</span
          >
        </div>
        <div class="itemBottom">总消费金额 ¥{{ topData.z_xfje }}</div>
      </div>
      <div class="topItem">
        <div class="itemTitle">今日结算金额</div>
        <div class="itemMsg">
          <span class="moneyIcon">¥</span>
          <span class="val">{{ topData.jr_jsje }}</span>
          <span class="green" v-if="topData.jr_jsje > topData.zr_jsje"
            >+{{ (topData.jr_jsje - topData.zr_jsje).toFixed(2) }}</span
          >
          <span class="red" v-if="topData.zr_jsje > topData.jr_jsje"
            >-{{ topData.zr_jsje - topData.jr_jsje }}</span
          >
        </div>
        <div class="itemBottom">总结算金额 ¥{{ topData.z_jsje }}</div>
      </div>
      <div class="topItem">
        <div class="itemTitle">今日新增会员</div>
        <div class="itemMsg">
          <span class="val">{{ topData.jr_hys }}</span>
          <span class="unit">人</span>
          <span class="green" v-if="topData.jr_hys > topData.zr_hys"
            >+{{ topData.jr_hys - topData.zr_hys }}</span
          >
          <span class="red" v-if="topData.zr_hys > topData.jr_hys"
            >-{{ topData.zr_hys - topData.jr_hys }}</span
          >
        </div>
        <div class="itemBottom">会员总人数 {{ topData.z_hys }}</div>
      </div>
      <div class="topItem">
        <div class="itemTitle">今日订单数</div>
        <div class="itemMsg">
          <span class="val">{{ topData.jr_xfbs }}</span>
          <span class="unit">单</span>
          <span class="green" v-if="topData.jr_xfbs > topData.zr_xfbs"
            >+{{ topData.jr_xfbs - topData.zr_xfbs }}</span
          >
          <span class="red" v-if="topData.zr_xfbs > topData.jr_xfbs"
            >-{{ topData.zr_xfbs - topData.jr_xfbs }}</span
          >
        </div>
        <div class="itemBottom">总订单数 {{ topData.z_xfbs }}单</div>
      </div>
    </div>
    <div class="centerBox">
      <div class="left">
        <div class="chartTitle">近七日新增会员</div>
        <div class="chartWrap">
          <Charts
            type="line"
            lineColor="#27D148"
            :lineAreaColor="lineAreaColor"
            linePointColor="#27D148"
            :Opinion="addMemberOpinion"
            :OpinionData="addMemberOpinionData"
          />
        </div>
      </div>
      <div class="right">
        <div class="chartTitle">支付占比</div>
        <div class="chartWrap">
          <Charts
            type="pie"
            :pieColor="['#28B3E0', '#27D148', '#FFA549']"
            :Opinion="['支付宝', '微信', '红包']"
            :OpinionData="zfzbOpinionData"
          />
        </div>
      </div>
    </div>
    <div class="bottomBox">
      <div class="left">
        <div class="chartTitle">近七日消费金额</div>
        <div class="chartWrap">
          <Charts
            barColor="#28B3E0"
            :Opinion="xfjeOpinion"
            :OpinionData="xfjeOpinionData"
          />
        </div>
      </div>
      <div class="right">
        <div class="chartTitle">近七日结算金额</div>
        <div class="chartWrap">
          <Charts
            barColor="#FFA549"
            :Opinion="jsjeOpinion"
            :OpinionData="jsjeOpinionData"
          />
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import { tadayData, chartData, zhifuzhanbi } from "@/api/pay";
import Charts from "@/components/charts";
export default {
  data() {
    return {
      topData: {},
      addMemberOpinion: [],
      addMemberOpinionData: [],
      xfjeOpinion: [],
      xfjeOpinionData: [],
      jsjeOpinion: [],
      jsjeOpinionData: [],
      zfzbOpinionData: [],
      lineAreaColor: {
        type: "linear",
        x: 0,
        y: 0,
        x2: 0,
        y2: 1,
        colorStops: [
          {
            offset: 0,
            color: "rgba(39, 209, 72, 0.26)", // 0% 处的颜色
          },
          {
            offset: 1,
            color: "rgba(255, 255, 255, 0.14)", // 100% 处的颜色
          },
        ],
        global: false, // 缺省为 false
      },
    };
  },
  components: {
    Charts,
  },
  created() {
    this.getTopData();
    this.getChartData();
    this.getZhifuzhanbi();
  },
  methods: {
    getTopData() {
      tadayData({}).then((res) => {
        if (res.code == 200) {
          this.topData = res.datas.list;
        } else {
          this.$message({
            message: res.datas.error,
            type: "error",
          });
        }
      });
    },
    getChartData() {
      chartData({}).then((res) => {
        if (res.code == 200) {
          this.addMemberOpinion = res.datas.hytj.map((item) => item.rq);
          this.addMemberOpinionData = res.datas.hytj.map((item) => item.zj);
          this.xfjeOpinion = res.datas.xftj.map((item) => item.rq);
          this.xfjeOpinionData = res.datas.xftj.map((item) => item.zj);
          this.jsjeOpinion = res.datas.jstj.map((item) => item.rq);
          this.jsjeOpinionData = res.datas.jstj.map((item) => item.zj);
        } else {
          this.$message({
            message: res.datas.error,
            type: "error",
          });
        }
      });
    },
    getZhifuzhanbi() {
      zhifuzhanbi({}).then((res) => {
        if (res.code == 200) {
          if (res.datas.list.length > 0) {
            this.zfzbOpinionData = [
              { value: res.datas.list[0].zfb, name: "支付宝" },
              { value: res.datas.list[0].wx, name: "微信" },
              { value: res.datas.list[0].hb, name: "红包" },
            ];
          }
        }
      });
    },
  },
};
</script>

<style lang='scss' scoped>
.topBox {
  width: 100%;
  height: 112px;
  display: flex;

  .topItem {
    flex: 1;
    height: 100%;
    background: #ffffff;
    border-radius: 4px;
    margin-left: 16px;
    padding: 22px 0;
    padding-left: 16px;
    display: flex;
    flex-direction: column;
    justify-content: space-between;

    &:first-child {
      margin-left: 0;
    }

    .itemTitle {
      font-size: 12px;
      font-family: PingFangSC-Regular, PingFang SC;
      font-weight: 400;
      color: #999999;
      line-height: 12px;
    }

    .itemMsg {
      .moneyIcon {
        font-size: 14px;
        font-family: PingFangSC-Semibold, PingFang SC;
        font-weight: 600;
        color: #333333;
      }

      .val {
        font-size: 24px;
        font-family: DINAlternate-Bold, DINAlternate;
        font-weight: bold;
        color: #333333;
      }

      .green {
        font-size: 14px;
        font-family: DINAlternate-Bold, DINAlternate;
        font-weight: bold;
        color: #34dc1c;
        margin-left: 4px;
      }

      .red {
        font-size: 14px;
        font-family: DINAlternate-Bold, DINAlternate;
        font-weight: bold;
        color: #f86464;
        margin-left: 4px;
      }

      .unit {
        font-size: 12px;
        font-family: PingFangSC-Regular, PingFang SC;
        font-weight: 400;
        color: #333333;
        margin-left: 4px;
      }
    }

    .itemBottom {
      font-size: 14px;
      font-family: PingFangSC-Regular, PingFang SC;
      font-weight: 400;
      color: #666666;
      line-height: 14px;
    }
  }
}

.chartTitle {
  padding-left: 16px;
  font-size: 16px;
  font-family: PingFangSC-Medium, PingFang SC;
  font-weight: 500;
  color: #333333;
  line-height: 16px;
}

.centerBox {
  width: 100%;
  height: 272px;
  display: flex;
  margin-top: 16px;

  .left {
    width: 601px;
    height: 100%;
    background: #ffffff;
    border-radius: 4px;
    padding-top: 16px;
    display: flex;
    flex-direction: column;
  }

  .right {
    flex: 1;
    height: 100%;
    margin-left: 16px;
    background: #ffffff;
    border-radius: 4px;
    padding-top: 16px;
    display: flex;
    flex-direction: column;
  }
}

.bottomBox {
  width: 100%;
  height: 272px;
  display: flex;
  margin-top: 16px;

  .left {
    flex: 1;
    height: 100%;
    background: #ffffff;
    border-radius: 4px;
    padding-top: 16px;
    display: flex;
    flex-direction: column;
  }

  .right {
    flex: 1;
    height: 100%;
    margin-left: 16px;
    background: #ffffff;
    border-radius: 4px;
    padding-top: 16px;
    display: flex;
    flex-direction: column;
  }
}

.chartWrap {
  width: 100%;
  flex: 1;
  overflow: hidden;
}
</style>