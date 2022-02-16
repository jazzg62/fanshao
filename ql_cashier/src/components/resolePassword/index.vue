<template>
  <div>
    <van-popup v-model="show" class="password_box">
      <div class="prop_left">
        <div class="title">修改密码</div>
        <div class="item_title">原密码</div>
        <div class="item_input" @click.stop="changeType('old_password')">
          {{ data.old_password }}
          <span class="inputLine" v-if="inputType == 'old_password'"></span>
        </div>

        <div class="item_title">新密码</div>
        <div class="item_input" @click.stop="changeType('new_password')">
          {{ data.new_password }}
          <span class="inputLine" v-if="inputType == 'new_password'"></span>
        </div>
        <div class="item_title">再次输入新密码</div>
        <div class="item_input" @click.stop="changeType('new_password2')">
          {{ data.new_password2 }}
          <span class="inputLine" v-if="inputType == 'new_password2'"></span>
        </div>
      </div>
      <div class="prop_right">
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
      </div>
    </van-popup>
  </div>
</template>
<script>
import { rejesPwd } from '@/api/member'
import { removeToken } from '@/utils/auth'
export default {
  data() {
    return {
      show: false,
      selectindex: null,
      inputType: '',
      data: {
        old_password: '',
        new_password: '',
        new_password2: ''
      },
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
  created() {},
  mounted() {},
  methods: {
    delValue() {
      if (this.inputType == 'old_password') {
        this.data.old_password = this.data.old_password.substring(0, this.data.old_password.length - 1)
      } else if (this.inputType == 'new_password') {
        this.data.new_password = this.data.new_password.substring(0, this.data.new_password.length - 1)
      } else if (this.inputType == 'new_password2') {
        this.data.new_password2 = this.data.new_password2.substring(0, this.data.new_password2.length - 1)
      }
    },
    chooseKey(val, index) {
      this.selectindex = index
      if (val.value == null) {
        if (this.inputType == 'old_password') {
          this.data.old_password = ''
        } else if (this.inputType == 'new_password') {
          this.data.new_password = ''
        } else if (this.inputType == 'new_password2') {
          this.data.new_password2 = ''
        }
      } else {
        if (this.inputType == 'old_password') {
          this.data.old_password = this.data.old_password + val.value
        } else if (this.inputType == 'new_password') {
          this.data.new_password = this.data.new_password + val.value
        } else if (this.inputType == 'new_password2') {
          this.data.new_password2 = this.data.new_password2 + val.value
        }
      }

      // this.value = this.value + val.value
      var that = this
      setTimeout(function () {
        that.selectindex = null
      }, 200)
    },
    changeType(e) {
      this.inputType = e
    },
    submit() {
      let data = this.data
      rejesPwd(data).then(res => {
        if (res.code == 200) {
          removeToken()
          this.show = false
          setTimeout(() => {
            this.$router.replace({
              path: '/login'
            })
          }, 1000)
        }
      })
    }
  }
}
</script>
<style scoped  lang='scss'>
@import './index.scss';
</style>