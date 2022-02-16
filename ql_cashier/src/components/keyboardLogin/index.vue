<template>
  <div>
    <van-popup v-model="show" class="login_prop">
      <div class="title">{{ titleText }}</div>
      <img src="@/assets/close.png" class="closeImg" @click.stop="handelClose" alt="" />
      <input v-if="titleText == '输入用户名'" type="text" v-model="value" disabled :placeholder="titleText" class="contentIpt" />
      <input v-if="titleText == '输入密码'" type="password" v-model="value" disabled :placeholder="titleText" class="contentIpt" />
      <div class="keyboard_box">
        <div class="leftBox">
          <div class="keyBox" v-for="(item, index) in keyList" :class="{ keyBoxselect: selectindex == index }" @click.stop="chooseKey(item, index)" :key="index">
            {{ item.key }}
          </div>
        </div>
        <div class="rightBox">
          <div class="del" @click.stop="delValue">
            <img src="@/assets/inputDel_icon.png" alt="" />
          </div>
          <div class="done" @click.stop="submit">确定</div>
        </div>
      </div>
    </van-popup>
  </div>
</template>
<script>
export default {
  data() {
    return {
      titleText: '',
      value: '',
      show: false,
      selectindex: null,
      keyList: [
        {
          key: '1',
          value: 1
        },
        {
          key: '2',
          value: 2
        },
        {
          key: '3',
          value: 3
        },
        {
          key: '4',
          value: 4
        },
        {
          key: '5',
          value: 5
        },
        {
          key: '6',
          value: 6
        },
        {
          key: '7',
          value: 7
        },
        {
          key: '8',
          value: 8
        },
        {
          key: '9',
          value: 9
        },
        {
          key: '.',
          value: '.'
        },
        {
          key: '0',
          value: 0
        },
        {
          key: '清空',
          value: null
        }
      ]
    }
  },
  props: {},
  created() {},
  mounted() {},
  methods: {
    handelClose() {
      this.show = false
    },
    delValue() {
      this.value = this.value.substring(0, this.value.length - 1)
    },
    returnKey() {
      setTimeout(function () {
        this.selectindex = null
      }, 500)
    },
    chooseKey(val, index) {
      this.selectindex = index
      
      console.log(val)
      console.log(this.selectindex)
      if (val.value != null) {
        this.value = this.value + val.value
      } else {
        this.value = ''
      }
      var that=this
      setTimeout(function () {
        that.selectindex = null
      }, 200)
    },
    submit() {
      this.$emit('inputSuccess', this.value)
      this.show = false
    }
  }
}
</script>
<style scoped  lang='scss'>
@import './index.scss';
</style>