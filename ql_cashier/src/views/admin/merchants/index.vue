<template>
  <div class="page">
    <div class="contaires_header">
      <!-- <div class="chooseBox">
        <div class="choose_item choose_item_slelct">最近七天</div>
        <div class="choose_item">最近30天</div>
        <div class="choose_item">最近90天</div>
      </div> -->
      <div class="lineBox">
        <Charts type="line" lineColor="#27D148" :lineAreaColor="lineAreaColor" linePointColor="#27D148" :Opinion="Opinion" :OpinionData="OpinionData" />
      </div>
      <div class="settlementBox">
        <div class="settlementTitle">结算总额</div>
        <div class="settlementContentBox">
          <div class="settlementContent">
            <span class="money">¥</span>
            <span>{{dataAll.jssum}}</span>
          </div>
        </div>
      </div>
      <div class="settlementBox settlementBox2">
        <div class="settlementTitle">提成总额</div>
        <div class="settlementContentBox">
          <div class="settlementContent1">
            <span class="money">¥</span>
            <span>{{dataAll.sysum}}</span>
          </div>
        </div>
      </div>
    </div>
    <div class="contaires_content">
      <div class="content_nav">
        <div class="item" :class="{ item_choose: filter.lx == 1 }" @click.stop="chooseNav(1)">结算账户</div>
        <div class="item" :class="{ item_choose: filter.lx == 2 }" @click.stop="chooseNav(2)">提成账户</div>
      </div>
      <div class="screeningBox">
        <div class="screeningLeft">
          <div class="leftItem">
            <span class="title">时间段：</span>
            <el-date-picker style="height: 36px" @change="dateChange" v-model="value1" type="daterange" range-separator="至" start-placeholder="开始日期" end-placeholder="结束日期"> </el-date-picker>
          </div>
        </div>
        <div class="screeningRight">
          <div class="searchBtn" @click.stop="search">查询</div>
        </div>
      </div>
      <table class="table" cellpadding="0" cellspacing="0" v-if="filter.lx == 1">
        <tr class="headerTr">
          <td class="time1">
            <span>消费时间</span>
            <img class="screenImg" src="@/assets/screenT.png" alt="" />
          </td>
          <td class="time1">
            <span>结算时间</span>
            <img class="screenImg" src="@/assets/screenT.png" alt="" />
          </td>
          <td class="time1">
            <span>消费金额</span>
            <img class="screenImg" src="@/assets/screenT.png" alt="" />
          </td>
          <td class="time1">
            <span>结算金额</span>
            <img class="screenImg" src="@/assets/screenT.png" alt="" />
          </td>
        </tr>
        <tr class="li_item" v-for="(item, index) in list" :key="index">
          <td class="time1">{{ item.addtime }}</td>
          <td class="time1">{{ item.jstime }}</td>
          <td class="time1">{{ item.xfje }}</td>
          <td class="time1">{{ item.jsje }}</td>
        </tr>
      </table>
      <table class="table" cellpadding="0" cellspacing="0" v-if="filter.lx == 2">
        <tr class="headerTr">
          <td class="time1">
            <span>会员昵称</span>
          </td>
          <td class="time1">
            <span>手机号</span>
          </td>
          <td class="time1">
            <span>消费时间</span>
            <img class="screenImg" src="@/assets/screenT.png" alt="" />
          </td>
          <td class="time1">
            <span>消费金额</span>
            <img class="screenImg" src="@/assets/screenT.png" alt="" />
          </td>
          <td class="time1">
            <span>消费商家名称</span>
          </td>
          <td class="time1">
            <span>提成金额</span>
          </td>
        </tr>
        <tr class="li_item" v-for="(item, index) in list" :key="index">
          <td class="time1">{{ item.member_name }}</td>
          <td class="time1">{{ item.member_mobile }}</td>
          <td class="time1">{{ item.addtime }}</td>
          <td class="time1">{{ item.xfje }}</td>
          <td class="time1">{{ item.store_name }}</td>
          <td class="time1">{{ item.syje }}</td>
        </tr>
      </table>
      <div class="pageBox">
        <el-pagination background :current-page="filter.curpage" :page-size.sync="filter.page" layout="prev, pager, next" :total="total" @current-change="currentChange"> </el-pagination>
      </div>
    </div>
  </div>
</template>
<script>
import Charts from '@/components/charts'
import { shopMoney, shopAll } from '@/api/member'
export default {
  data() {
    return {
      value1: [],
      list: [],
      total: 0,
      filter: {
        curpage: 1,
        page: 6,
        lx: 1,
        query_start_date: '',
        query_end_date: ''
      },
      dataAll: {},
      lineAreaColor: {
        type: 'linear',
        x: 0,
        y: 0,
        x2: 0,
        y2: 1,
        colorStops: [
          {
            offset: 0,
            color: 'rgba(39, 209, 72, 0.26)' // 0% 处的颜色
          },
          {
            offset: 1,
            color: 'rgba(255, 255, 255, 0.14)' // 100% 处的颜色
          }
        ],
        global: false // 缺省为 false
      },
      Opinion:[],
      OpinionData:[]
    }
  },
  components: { Charts },
  created() {
    this.getList()
    this.getdata()
  },
  mounted() {},
  methods: {
    getdata() {
      let data = {}
      shopAll(data).then(res => {
        if (res.code == 200) {
          this.dataAll = res.datas
          this.Opinion=res.datas.list.map(item=>item.rq)
          this.OpinionData=res.datas.list.map(item=>item.zj)
        }
      })
    },
    chooseNav(e) {
      this.filter.lx = e
      this.filter.curpage = 1
      this.getList()
    },
    currentChange(e) {
      this.filter.curpage = e
      this.getList()
      console.log(this.currentPage)
    },
    dateChange(e) {
      console.log(e)
      this.filter.query_start_date = e[0]
      this.filter.query_end_date = e[1]
    },
    getList() {
      shopMoney(this.filter).then(res => {
        if (res.code == 200) {
          this.list = res.datas.list
          this.total = res.datas.total * 1
        }
      })
    },
    search() {
      this.filter.curpage = 1
      this.getList()
    }
  }
}
</script>
<style scoped  lang='scss'>
@import './index.scss';
</style>