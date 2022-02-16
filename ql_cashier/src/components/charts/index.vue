<template>
  <div class="chartBox">
    <template v-if="type == 'bar'">
      <div class="chart_box" ref="barCharts"></div>
    </template>
    <template v-if="type == 'pie'">
      <div class="chart_box" ref="pieCharts"></div>
    </template>
    <template v-if="type == 'line'">
      <div class="chart_box" ref="lineCharts"></div>
    </template>
  </div>
</template>

<script>
import * as echarts from "echarts";
export default {
  props: {
    type: {
      type: String,
      default: "bar",
    },
    Opinion: {
      type: Array,
      default: () => {
        return [];
      },
    },
    OpinionData: {
      type: Array,
      default: () => {
        return [];
      },
    },
    barColor: {
      type: String,
    },
    pieColor: {
      type: Array,
      default: () => {
        return [];
      },
    },
    lineColor: {
      type: String,
    },
    lineAreaColor: {
      type: [String, Object],
    },
    linePointColor: {
      type: String,
    },
  },
  data() {
    return {
      charts: "",
      pieOptions: {
        //环形图配置
        tooltip: {
          trigger: "item",
          position: "right",
          formatter: "{b}<br />{c}",
        },
        color: [],
        legend: {
          show: true,
          orient: "horizontal",
          bottom: 0,
          left: "center",
          // data: [],
          // formatter: function (name) {
          //   return name;
          // },
          // textStyle: {
          //   color: "#FFFFFF",
          // },
        },
        series: [
          {
            name: "",
            type: "pie",
            radius: ["30%", "60%"],
            avoidLabelOverlap: false,
            label: {
              normal: {
                formatter: "{b}：\n{d}%",
              },
            },
            labelLine: {
              normal: {
                show: true,
                length2: 10,
                lineStyle: {
                  color: "#24B8CE",
                },
              },
            },
            data: [],
          },
        ],
      },
      barOptions: {
        //柱状图配置
        grid: {
          left: 35,
          right: 15,
          top: 30,
          bottom: 30,
          containLabel: false,
          backgroundColor: "#ffffff",
        },
        title: {
          show: false,
        },
        tooltip: {
          trigger: "item",
          formatter: "{b}<br />{c}",
        },
        dataZoom: [
          {
            type: "inside", // 横向滑动设置
            filterMode: "empty",
            xAxisIndex: [0],
            start: 0, // 初始化开始位置
            end: 100, // 初始化结束为止
            zoomLock: true,
          },
        ],
        xAxis: {
          nameTextStyle: {
            color: "#666666",
            fontSize: 12,
          },
          axisLine: {
            lineStyle: {
              color: "#EEEEEE",
            },
          },
          axisTick: {
            show: false,
          },
          axisLabel: {
            interval: 0,
            color: "#666666",
            // formatter: function (value) {
            //   // debugger;
            //   var ret = ""; //拼接加\n返回的类目项
            //   var maxLength = 4; //每项显示文字个数
            //   var valLength = value.length; //X轴类目项的文字个数
            //   var rowN = Math.ceil(valLength / maxLength); //类目项需要换行的行数
            //   if (rowN > 1) {
            //     //如果类目项的文字大于3,
            //     for (var i = 0; i < rowN; i++) {
            //       var temp = ""; //每次截取的字符串
            //       var start = i * maxLength; //开始截取的位置
            //       var end = start + maxLength; //结束截取的位置
            //       //这里也可以加一个是否是最后一行的判断，但是不加也没有影响，那就不加吧
            //       temp = value.substring(start, end) + "\n";
            //       ret += temp; //凭借最终的字符串
            //     }
            //     return ret;
            //   } else {
            //     return value;
            //   }
            // },
          },
          data: [],
        },
        yAxis: {
          name: "",
          splitLine: {
            show: true,
          },
          nameTextStyle: {
            color: "#999999",
            fontSize: 12,
          },
          axisLine: {
            lineStyle: {
              color: "#666666",
            },
          },
          axisTick: {
            show: false,
          },
        },
        series: [
          {
            type: "bar",
            name: "",
            barWidth: 20,
            data: [],
            itemStyle: {
              normal: {
                color: this.barColor,
                label: {
                  show: false, //开启显示
                  position: "top", //在上方显示
                  textStyle: {
                    //数值样式
                    color: "#333333",
                    fontSize: 12,
                  },
                  formatter: "{c}",
                },
              },
            },
          },
        ],
      },
      lineOptions: {
        grid: {
          left: 35,
          right: 15,
          top: 30,
          bottom: 30,
          containLabel: false,
          backgroundColor: "#ffffff",
        },
        xAxis: {
          type: "category",
          data: [],
          axisLine: {
            lineStyle: {
              color: "#EEEEEE",
            },
          },
          axisTick: {
            show: false,
          },
          axisLabel: {
            interval: 0,
            color: "#666666",
          },
        },
        yAxis: {
          type: "value",
        },
        series: [
          {
            data: [],
            type: "line",
            symbolSize: 6,
            lineStyle: {
              color: this.lineColor,
            },
            itemStyle: {
              normal: {
                color: this.linePointColor,
              },
            },
            areaStyle: {
              color: this.lineAreaColor,
            },
          },
        ],
      },
    };
  },
  watch: {
    Opinion: {
      handler(newVal) {
        if (newVal) {
          switch (this.type) {
            case "line":
              this.charts.setOption({
                xAxis: {
                  data: newVal,
                },
              });
              break;
            case "bar":
              this.charts.setOption({
                xAxis: {
                  data: newVal,
                },
              });
              break;
          }
        }
      },
      deep: true,
    },
    OpinionData: {
      handler(newVal) {
        if (newVal) {
          switch (this.type) {
            case "line":
              this.charts.setOption({
                series: [
                  {
                    data: newVal,
                  },
                ],
              });
              break;
            case "bar":
              this.charts.setOption({
                series: [
                  {
                    data: newVal,
                  },
                ],
              });
              break;
            case "pie":
              this.charts.setOption({
                series: [
                  {
                    data: newVal,
                  },
                ],
              });
              break;
          }
        }
      },
      deep: true,
    },
  },
  mounted() {
    switch (this.type) {
      case "bar":
        this.barInit();
        break;
      case "pie":
        this.pieInit();
        break;
      case "line":
        this.lineInit();
        break;
    }
  },
  methods: {
    barInit() {
      this.charts = echarts.init(this.$refs.barCharts);
      this.barOptions.xAxis.data = this.Opinion;
      this.barOptions.series[0].data = this.OpinionData;
      this.charts.setOption(this.barOptions);
      let _this = this;
      window.addEventListener("resize", function () {
        _this.charts.resize();
      });
    },
    pieInit() {
      console.log(this.Opinion);
      this.charts = echarts.init(this.$refs.pieCharts);
      this.pieOptions.color = this.pieColor;
      // this.pieOptions.legend.data = this.Opinion;
      this.pieOptions.series[0].data = this.OpinionData;
      console.log(this.pieOptions);
      this.charts.setOption(this.pieOptions);
      let _this = this;
      window.addEventListener("resize", function () {
        _this.charts.resize();
      });
    },
    lineInit() {
      this.charts = echarts.init(this.$refs.lineCharts);
      this.lineOptions.xAxis.data = this.Opinion;
      this.lineOptions.series[0].data = this.OpinionData;
      this.charts.setOption(this.lineOptions);
      let _this = this;
      window.addEventListener("resize", function () {
        _this.charts.resize();
      });
    },
  },
};
</script>

<style lang='scss' scoped>
.chartBox,
.chart_box {
  width: 100%;
  height: 100%;
}
</style>