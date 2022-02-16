<template>
    <div class="home full-bg1">
        <Header></Header>
        <div class="menu">
          <div class="store-info">
            <div class="store-avatar"><img :src="avatar" alt="店铺头像"></div>
            <h2 class="store-name">{{name}}</h2>
          </div>
          <div class="block" style="left:830px;">
            <div class="container">
              <img src="../assets/index/f.png" alt="">
              <div class="text">
                <h3>收款</h3>
              </div>
            </div>
          </div>

          <div class="block" style="top:169px;">
            <div class="container">
              <img src="../assets/index/z.png" alt="">
              <div class="text">
                <h3>会员</h3>
                <h4 style="margin-top:28px;">本店会员</h4>
              </div>
            </div>
          </div>

          <div class="block" style="top:480px;">
            <div class="container">
              <img src="../assets/index/s.png" alt="">
              <div class="text">
                <h4>数据汇总</h4>
              </div>
            </div>
          </div>
          
          <div class="block" style="top:480px;left:410px;">
            <div class="container">
              <img src="../assets/index/l.png" alt="">
              <div class="text">
                <h4>流量变现</h4>
              </div>
            </div>
          </div>

          <div class="block" style="left:830px;top:330px;">
            <div class="container">
              <img src="../assets/index/m.png" alt="">
              <div class="text">
                <h3>消费记</h3>
                <h3>录明细</h3>
              </div>
            </div>
          </div>
        </div>
    </div>
</template>

<script>
import Header from "../components/Header";
import {getStoreInfo} from "../common";
export default {
    name: "Home",
    components: {
        Header
    },
    data:()=>{
      return {
        avatar: "",
        name:"",
        hys:"",
      }
    },
    beforeMount:function() {
        let store_info = getStoreInfo();
        this.avatar = store_info.avatar;
        this.name = store_info.name;
        this.hys = store_info.hys;
        let key = localStorage.getItem("key");
        if(!key){
            this.$router.push("/login");
        }
    },
};
</script>

<style lang="scss" scoped>
  .menu{
    display: block;
    // float: left;
    width: 1460px;
    min-height: 633px;
    margin: 80px auto;
    // background: red;
    position: relative;

    .store-info{
      display: flex;
      align-items: center;
      height: 136px;
      width: 796px;
      background: linear-gradient(to bottom, #3173EE, #2CC8FE);
      position: absolute;
      border-radius: 5px;
      box-sizing: border-box;
      padding-left: 137px;
      .store-avatar{
        width: 75px;
        height: 75px;
        border-radius: 50%;
        overflow: hidden;
        margin-right: 28px;
        img{
          width: 100%;
        }
      }
      .store-name{
        color: white;
        font-size: 50px;
        letter-spacing: 2px;
        font-weight: 400;
        overflow: hidden;
        text-overflow: ellipsis;
        white-space: nowrap;
      }
    }

    .block{
      position: absolute;
      border-radius: 5px;

      .container{
        position: relative;
        img{
          position: relative;
          left: 0;
          top: 0;
        }

        .text{
          position: absolute;
          left: 6%;
          top: 10%;
          h3{
            font-size: 50px;
            text-align: left;
            margin-top: 0;
            margin-bottom: 0;
          }
          h4{
            font-size: 28px;
            text-align: left;
            margin-top: 0;
            margin-bottom: 0;
          }
        }
      }
      
    }
  }
</style>
