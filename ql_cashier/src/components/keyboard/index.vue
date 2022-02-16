<template>
  <div>
    <div class="keyboard_box">
      <div class="leftBox">
        <div class="keyBox" @click="keyClick(item,index)" :class="item.key == '清空' ? 'clearBox' : selectindex == index ? 'keyBoxselect' : ''" v-for="(item, index) in keyList" :key="index">
          {{ item.key }}
        </div>
      </div>
      <div class="rightBox">
        <div class="del" @click="del">
          <img src="@/assets/inputDel_icon.png" alt="" />
        </div>
        <div class="done" @click="done">{{ doneText }}</div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    doneText: {
      type: String,
      default: '确定'
    }
  },
  data() {
    return {
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
  methods: {
    keyClick(item,index) {
      this.selectindex = index
      this.$emit('keyClick', item.value)
      var that = this
      setTimeout(function () {
        that.selectindex = null
      }, 200)
    },
    done() {
      this.$emit('done')
    },
    del() {
      this.$emit('del')
    }
  }
}
</script>

<style lang='scss' scoped>
.keyboard_box {
  display: flex;
  height: 256px;

  .leftBox {
    height: 100%;
    width: 225px;
    display: flex;
    flex-wrap: wrap;

    .keyBox {
      width: 67px;
      height: 58px;
      background: #ffffff;
      border-radius: 4px;
      border: 1px solid #dee5e7;
      margin-right: 8px;
      display: flex;
      align-items: center;
      justify-content: center;
      font-size: 24px;
      font-family: PingFangSC-Medium, PingFang SC;
      font-weight: 500;
      color: #333333;
      margin-top: 8px;

      &:nth-child(1) {
        margin-top: 0;
      }

      &:nth-child(2) {
        margin-top: 0;
      }

      &:nth-child(3) {
        margin-top: 0;
      }
    }
    .keyBoxselect {
      color: #fff;
      background-color: rgb(238, 238, 238);
    }

    .clearBox {
      font-size: 18px;
    }
  }

  .rightBox {
    width: 67px;
    height: 100%;
    display: flex;
    flex-direction: column;

    .del {
      width: 100%;
      height: 58px;
      margin-bottom: 8px;
      background: #ffffff;
      border-radius: 4px;
      border: 1px solid #dee5e7;
      display: flex;
      align-items: center;
      justify-content: center;

      img {
        width: 29px;
        height: 30px;
      }
    }

    .done {
      flex: 1;
      width: 100%;
      background: linear-gradient(180deg, #00dbff 0%, #00bfff 100%);
      border-radius: 4px;
      display: flex;
      align-items: center;
      justify-content: center;
      font-size: 18px;
      font-family: PingFangSC-Medium, PingFang SC;
      font-weight: 500;
      color: #ffffff;
    }
  }
}
</style>