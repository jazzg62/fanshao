<template>
  <div>
    <div class="contaires" :class="{ whiteType: showType == 'white' }">
      <div class="contaires_itemLogo">
        <img class="logo" @click.stop="back" :src="showType == 'black' ? require('@/assets/header_logo.png') : require('@/assets/header_logo_white.png')" alt="" />
        <div class="wel">欢迎使用企联收银台</div>
        <div class="time">{{ nowDate }}</div>
      </div>
      <div class="contaires_item_other">
        <div class="pwd" v-if="isShowPwd" @click="showResPwd">
          <img :src="showType == 'black' ? require('@/assets/login_pwd.png') : require('@/assets/login_pwd_white.png')" alt="" />
          <div>密码设置</div>
        </div>
        <div class="login_out" v-if="isShowOut" @click.stop="tologinOut">
          <img :src="showType == 'black' ? require('@/assets/login_out.png') : require('@/assets/login_out_white.png')" alt="" />
          <div>退出登录</div>
        </div>
      </div>
    </div>
    <resolePassword ref="resolePassword"></resolePassword>
  </div>
</template>
<script>
import { Dialog } from 'vant'
import resolePassword from "@/components/resolePassword"
export default {
  props: {
    showType: {
      type: String,
      default: 'black'
    },
    isShowOut: {
      type: Boolean,
      default: true
    },
    isShowBack:{
      type: Boolean,
      default: true
    },
    isShowPwd:{
        type: Boolean,
      default: true
    }
  },
  components:{
    resolePassword
  },
  data() {
    return {
      nowDate: '' // 当前日期
    }
  },
  methods: {
    showResPwd(){
      this.$refs.resolePassword.show=true
    },
    back(){
      if(this.isShowBack==false){
        return
      }
      this.$router.replace({
        path:'/home'
      })
    },
    tologinOut() {
      Dialog.confirm({
        title: '提示',
        message: '是否确认退出？'
      })
        .then(() => {
          this.$store
            .dispatch('user/LoginOut', {})
            .then(() => {
            
            })
            .catch(err => {
              console.log(err)
            })
        })
        .catch(() => {
          // on cancel
        })
    },
    currentTime() {
      setInterval(this.formatDate, 500)
    },
    formatDate() {
      let date = new Date()
      let year = date.getFullYear() // 年
      let month = date.getMonth() + 1 // 月
      let day = date.getDate() // 日
      //   let week = date.getDay() // 星期
      //   let weekArr = ['星期日', '星期一', '星期二', '星期三', '星期四', '星期五', '星期六']
      let hour = date.getHours() // 时
      hour = hour < 10 ? '0' + hour : hour // 如果只有一位，则前面补零
      let minute = date.getMinutes() // 分
      minute = minute < 10 ? '0' + minute : minute // 如果只有一位，则前面补零
      let second = date.getSeconds() // 秒
      second = second < 10 ? '0' + second : second // 如果只有一位，则前面补零
      this.nowDate = `${year}/${month}/${day} ${hour}:${minute}:${second}` //${weekArr[week]}
    }
  },
  mounted() {
    this.currentTime()
  },
  // 销毁定时器
  beforeDestroy() {
    if (this.formatDate) {
      clearInterval(this.formatDate) // 在Vue实例销毁前，清除时间定时器
    }
  }
}
</script>
<style scoped  lang='scss'>
@import './index.scss';
</style>