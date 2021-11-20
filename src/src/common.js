import Vue from 'vue';
import {ApiUrl} from './constant';
import {stringify} from 'querystring';
import router from './router';
export function formatDate(date, fmt) {
    var o = {
        "M+": date.getMonth() + 1, //月份
        "d+": date.getDate(), //日
        "h+": date.getHours(), //小时
        "m+": date.getMinutes(), //分
        "s+": date.getSeconds(), //秒
        "q+": Math.floor((date.getMonth() + 3) / 3), //季度
        "S": date.getMilliseconds() //毫秒
      };
      if (/(y+)/.test(fmt)) fmt = fmt.replace(RegExp.$1, (date.getFullYear() + "").substr(4 - RegExp.$1.length));
      for (var k in o)
        if (new RegExp("(" + k + ")").test(fmt)) fmt = fmt.replace(RegExp.$1, (RegExp.$1.length == 1) ? (o[k]) : (("00" + o[k]).substr(("" + o[k]).length)));
      return fmt;
}

export function getStoreInfo(){
  return JSON.parse(localStorage.getItem('store_info'));
}

export function checkLogin(login){
  if(login == 0){
    router.push('/login');
    return false;
  }
  return true;
}

export function generateUnionID() {
    var time = new Date().getTime();
    var res = (time + "").split("");
    const RAND_S = "1234567890";
    const LENGTH = 18;
    for (var i = res.length; i < LENGTH; i++) {
        res.push(RAND_S[parseInt(Math.random() * RAND_S.length)]);
    }
    return res.join("");
}

export function payNotification(ddh, callback=()=>{}){
  let delayArr = [1000, 1000, 1000, 1000, 1000, 2000, 3000, 5000, 5000, 100000, 300000];
  let now = 0;
  let delayArrLength = delayArr.length;
  let requestNotification = ()=>{
    Vue.axios.get(ApiUrl + '?act=seller_sm&op=ddh&'+stringify({key:localStorage.getItem('key'), ddh:ddh})).then((res)=> {
      var order_info = res.data.datas.list;
      if(order_info.zt == 1){
        callback(order_info);
        return ;
      }
      if(now<delayArrLength){
        setTimeout(requestNotification, delayArr[now++]);
      }
    });
  }
  requestNotification();
}

export function xflx(val){
  switch(val){
    case 'FS':
      return '反扫支付';
    case 'FS_ALIPAY':
      return '支付宝反扫';
    case 'FS_WXPAY':
      return '微信反扫';
    default:
      return val;
  }
}
