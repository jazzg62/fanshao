<template>
    <div class="home full-bg1">
        <Header></Header>
        <div class="table">
            <div class="row">
                <div class="br">
                  <div class="item w9 h3 blue"><div class="store-avatar"><img :src="avatar" alt=""></div><h3>{{name}}</h3></div>
                </div>
                <div class="br">
                  <div class="item w6 h3 blue"><h3>本店会员（{{hys}}）</h3></div>
                </div>
            </div>

            <div class="row">
                <div class="br pointer">
                  <router-link to='/detail'>
                    <div class="column item w3 h6 blue blue-hover">
                        <div class="icon icon-xl3 icon-mingxi-w">
                        </div>
                        <span>明细</span>
                    </div>
                  </router-link>
                  <div class="column">
                      <router-link to="/detail?lx=1" class="item w3 h3 blue1 blue1-hover">微信</router-link>
                      <router-link to="/detail?lx=4" class="item w3 h3 blue2 blue2-hover">红包</router-link>
                  </div>
                  <div class="column">
                      <router-link to="/detail?lx=2" class="item w3 h3 blue2 blue2-hover">支付宝</router-link>
                      <router-link to="/detail?lx=3" class="item w3 h3 blue1 blue1-hover">余额支付</router-link>
                  </div>
                </div>
                
                <div class="br pointer">
                  <router-link to='/receipt?paypop=1'>
                    <div class="column item w3 h6 blue blue-hover">
                        <div class="icon icon-xl3 icon-shoukuan-w">
                        </div>
                        <span>收款</span>
                    </div>
                  </router-link>
                  <div class="column">
                      <router-link to="/receipt?lx=1" class="item w3 h2 blue1 blue1-hover">已支付</router-link>
                      <router-link to="/receipt?lx=2" class="item w3 h2 blue2 blue2-hover">待支付</router-link>
                      <router-link to="/receipt" class="item w3 h2 blue1 blue1-hover">全部查询</router-link>
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
.table {
    margin: auto;
    margin-top: 100px;
    display: inline-block;
    color: white;
    font-size: 36px;
    background: transparent;
    letter-spacing: 2px;
    .store-avatar{
      width: 90px;
      height: 90px;
      margin-right: 20px;
      img{
        width: 100%;
        height: 100%;
        object-fit: contain;
        border-radius: 50%;
      }
    }
    h3{
      font-size: 54px;
      font-weight: normal;
    }
    .item{
      display: flex;
      align-items: center;
      justify-content: center;
    }
    .blue {
        background: #28b3e0;
    }
    .blue1 {
        background: #5dc5e7;
    }
    .blue2 {
        background: #2eb6e1;
    }

    .row {
        display: flex;
    }
    .column {
        display: flex;
        flex-direction: column;
        span{
          font-size: 54px;
        }
    }
    .blue-hover:hover{
      background: #28b2e0b7;
      transition: all 0.3s;
    }
    .blue1-hover:hover{
      background: #5dc5e7b9;
      transition: all 0.3s;
    }
    .blue2-hover:hover{
      background: #2eb7e1c0;
      transition: all 0.3s;
    }
    .br{
      border-radius: 8px;
      overflow: hidden;
      display: flex;
      margin: 7px 11px;
    }
    .w2 {
        width: 130px;
    }
    .w3 {
        width: calc(850px / 3);
    }
    .w6 {
        width: calc(850px * 0.66666);
    }
    .w7 {
        width: 580px;
    }
    .w9 {
        width: 850px;
    }
    .h2 {
        height: 141.65px;
    }
    .h3 {
        height: 212.5px;
    }
    .h6 {
        height: 425px;
    }
    .icon{
      margin-bottom: 32px;
    }
}
</style>
