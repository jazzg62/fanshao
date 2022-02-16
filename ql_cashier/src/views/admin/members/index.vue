<template>
  <div class="page">
    <div class="contaires">
      <div class="screeningBox">
        <div class="screeningLeft">
          <div class="leftItem">
            <span class="title">手机号：</span>
            <el-popover placement="bottom-start" v-model="visible" width="360" trigger="click">
              <div class="inputBox" slot="reference">{{filter.phone}}</div>
              <div class="keyboard_box" style="display: flex; justify-content: center">
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
            <el-date-picker style="height: 36px"  @change="dateChange" v-model="value1" type="daterange" range-separator="至" start-placeholder="开始日期" end-placeholder="结束日期"> </el-date-picker>
          </div>
        </div>
        <div class="screeningRight">
          <div class="searchBtn" @click="search">查询</div>
        </div>
      </div>
      <div class="content_all">
        <table class="table" cellpadding="0" cellspacing="0">
          <tr class="headerTr">
            <td class="img">头像</td>
            <td class="name">昵称</td>
            <td class="phone">手机号</td>
            <td class="time">锁定时间</td>
            <td class="money">累计消费金额</td>
            <td class="look">查看消费记录</td>
          </tr>
          <tr class="li_item" v-for="(item, index) in list" :key="index">
            <td class="img"><img :src="item.member_avatar" alt="" /></td>
            <td class="name">{{ item.member_name }}</td>
            <td class="phone">{{ item.member_mobile }}</td>
            <td class="time">{{ item.addtime }}</td>
            <td class="money">{{ item.ze }}</td>
            <td class="look" @click.stop="toDetail(item)">查看</td>
          </tr>
        </table>
      </div>
      <div class="pageBox">
        <el-pagination background :current-page="filter.curpage" :page-size.sync="filter.page" layout="prev, pager, next" :total="total" @current-change="currentChange"> </el-pagination>
      </div>
    </div>
  </div>
</template>
<script>
import { memberList } from '@/api/member'
import keyboard from '@/components/keyboard'
export default {
  data() {
    return {
      total: 0,
      visible:false,
      value1: [],
      filter: {
        curpage: 1,
        page: 10,
        query_start_date:'',
        query_end_date:'',
        phone:''
      },

      list: []
    }
  },
  components: {
    keyboard
  },
  created() {
    this.getlist()
  },
  mounted() {},
  methods: {
    toDetail(e){
      console.log(e)
      this.$router.push({
        path:'/admin/memberInfo',
        query:{
          item:JSON.parse(JSON.stringify(e))
        }
      })
    },
     search() {
      this.filter.curpage = 1;
      this.getlist();
    },
     inputKeyClick(e) {
      console.log(e);
      if (e == null) {
        this.filter.phone = "";
      } else {
        this.filter.phone += e;
      }
    },
    inputDone() {
      this.visible=false
    },
    dateChange(e) {
      console.log(e);
      this.filter.query_start_date = e[0];
      this.filter.query_end_date = e[1];
    },
    inputDel() {
      if (this.filter.phone.length)
        this.filter.phone = this.filter.phone.substr(0, this.filter.phone.length - 1);
    },
    currentChange(e) {
      this.filter.curpage = e;
      this.getlist();
      console.log(this.currentPage);
    },
    getlist() {
      memberList(this.filter).then(res => {
        if (res.code == 200) {
          console.log(res)
          this.list = res.datas.list
          this.total = res.datas.total * 1
        }
      })
    }
  }
}
</script>
<style scoped  lang='scss'>
@import './index.scss';
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