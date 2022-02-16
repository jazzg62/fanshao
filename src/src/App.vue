<template>
  <div id="app">
    <transition :name="transitionName">
    <router-view class="rv" />
    </transition>
  </div>
</template>
<script>
import './common.scss';
export default {
  name: 'App',
  data: ()=>{
    return {
      transitionName: 'fade'
    }
  },
  watch:{
    // 根据$route来决定使用哪种过渡动画
    '$route' (to, from) {
      if(to.path == '/' || to.path == '/login' || from.path == '/' || from.path == '/login'){
        this.transitionName = 'el-zoom-in-center'
        return ;
      }
      this.transitionName = 'fade';
    }
  }
}
</script>

<style scoped>
.fade-enter-active, .fade-leave-active {
  transition: opacity .6s;
}
.fade-enter, .fade-leave-to /* .fade-leave-active below version 2.1.8 */ {
  opacity: 0;
}
#app{
  position: relative;
  left: 0;
  top: 0;
}
.rv{
  position: absolute;
  top: 0;
  left: 0;
  right: 0;
}
</style>