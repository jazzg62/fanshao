<template>
  <div class="page">
    <headerTop :isShowBack="false" :isShowOut='false' :isShowPwd='false'></headerTop>
    <div class="contaires">
      <div class="login_box">
        <div class="logoimg"></div>
        <div class="login_item" @click.stop="showUserPhone">
          <img src="@/assets/loginUser.png" alt="" />
          <input type="text" v-model="form.username" disabled placeholder="请输入用户名" />
        </div>
        <div class="login_item" @click.stop="showUserPwd">
          <img src="@/assets/loginPwd.png" alt="" />
          <input type="password" v-model="form.password" disabled placeholder="请输入密码" />
        </div>
        <div class="submit" @click.stop="commitLogin">登陆</div>
      </div>
    </div>
    <keyboard ref="keyboard" @inputSuccess="inputSuccess"></keyboard>
  </div>
</template>
<script>
import headerTop from '../../components/header'
import keyboard from '../../components/keyboardLogin'
export default {
  data() {
    return {
      form: {
        username: '',
        password: ''
      },
      type: 'username'
    }
  },
  components: {
    headerTop,
    keyboard
  },
  created() {},
  mounted() {},
  methods: {
    commitLogin() {
      this.$store
        .dispatch('user/Login', this.form)
        .then(() => {
          this.$store.dispatch('user/GetUserInfo', {}).then(() => {
            console.log('我被执行了099')
            this.$router.push({ path: '/' })
          })
        })
        .catch(err => {
          console.log(err)
        })
      // login(this.form).then(res => {
      //   console.log(res)
      //   if (res.code == 200) {
      //   }
      // })
    },
    inputSuccess(e) {
      if (this.type == 'username') {
        this.form.username = e
      }
      if (this.type == 'userpassword') {
        this.form.password = e
      }
    },
    showUserPhone() {
      this.type = 'username'
      this.$refs.keyboard.show = true
      this.$refs.keyboard.titleText = '输入用户名'
      this.$refs.keyboard.value = this.form.username
    },
    showUserPwd() {
      this.type = 'userpassword'
      this.$refs.keyboard.show = true
      this.$refs.keyboard.titleText = '输入密码'
      this.$refs.keyboard.value = this.form.password
    }
  }
}
</script>
<style scoped  lang='scss'>
.page {
  display: flex;
  flex-direction: column;
  width: 100vw;
  height: 100vh;

  .contaires {
    flex: 1;
    width: 100%;
    background: url(../../assets/loginBgimg.png) no-repeat;
    background-size: 100% 100%;

    .login_box {
      margin: 0 auto;
      margin-top: 145px;
      width: 356px;
      height: 314px;
      background: #ffffff;
      box-shadow: 0px 4px 12px 0px rgba(14, 92, 133, 0.1);
      border-radius: 8px;
      padding: 0 32px;
      padding-top: 24px;
      .logoimg {
        width: 80px;
        height: 48px;
        margin: 0 auto;
        background: url(../../assets/login_login.png) no-repeat;
        background-size: 100% 100%;
        margin-bottom: 4px;
      }
      .login_item {
        width: 100%;
        height: 48px;
        background: #f1f7f9;
        border-radius: 4px;
        border: 1px solid #dddddd;
        display: flex;
        padding: 0 12px;
        align-items: center;
        margin-top: 16px;
        img {
          width: 24px;
          height: 24px;
        }
        input {
          flex: 1;
          outline: none;
          background-color: transparent;
          font-size: 16px;
          font-family: PingFangSC-Regular, PingFang SC;
          font-weight: 400;
          color: #333;
          border: none;
          margin-left: 7px;
        }
      }
      .submit {
        width: 100%;
        height: 48px;
        background: #00bfff;
        border-radius: 4px;
        text-align: center;
        line-height: 48px;
        font-size: 16px;
        font-family: PingFangSC-Medium, PingFang SC;
        font-weight: 500;
        color: #ffffff;
        margin-top: 30px;
      }
    }
  }
}
</style>