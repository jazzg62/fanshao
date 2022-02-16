<template>
  <div>
    <Header showType="white" />
    <div class="main">
      <div class="leftNav">
        <div class="navHeader" @click="back">
          <div class="logo">
            <img :src="userInfo.store_avatar" alt="" />
          </div>
          <div class="name">{{userInfo.store_name}}</div>
          <div class="num">会员({{userInfo.hys}})</div>
        </div>
        <div class="navWrap">
          <template    v-for="(item, index) in routes.children">
          <router-link
            :to="routes.path + '/' + item.path"
            class="navItem"
            :class="{ navItem_active: item.name == routePage.name }"
            v-if="item.meta.show"
            :key="index"
          >
            <img
              :src="
                item.name == routePage.name
                  ? require(`@/assets/${item.meta.icon}_active.png`)
                  : require(`@/assets/${item.meta.icon}.png`)
              "
              alt=""
            />
            <div class="title">{{ item.meta.title }}</div>
          </router-link>
          </template>
        </div>
      </div>
      <div class="rightMain">
        <div class="mainWrap">
          <router-view />
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import { mapState } from "vuex";
import Header from "@/components/header";
export default {
  components: {
    Header,
  },
  computed: {
    ...mapState({
      userInfo: (state) => state.user.userInfo,
    }),
    routes() {
      return this.$router.options.routes.find((item) => item.name == "admin");
    },
    routePage() {
      return this.$route;
    },
  },
  created() {
    console.log(this.$route);
  },
  methods:{
    back(){
         this.$router.replace({
        path:'/home'
      })
    }
  },
};
</script>

<style lang='scss' scoped>
.main {
  width: 100%;
  height: calc(100vh - 48px);
  display: flex;

  .leftNav {
    width: 80px;
    height: 100%;
    padding-top: 16px;

    .navHeader {
      .logo {
        width: 40px;
        height: 40px;
        margin: auto;

        img {
          width: 100%;
          height: 100%;
        }
      }

      .name {
        text-align: center;
        font-size: 14px;
        font-family: PingFangSC-Regular, PingFang SC;
        font-weight: 400;
        color: #333333;
        line-height: 14px;
        margin-top: 10px;
        overflow: hidden;
        text-overflow: ellipsis;
        white-space: nowrap;
      }

      .num {
        text-align: center;
        font-size: 14px;
        font-family: PingFangSC-Regular, PingFang SC;
        font-weight: 400;
        color: #999999;
        line-height: 14px;
        margin-top: 8px;
      }
    }

    .navWrap {
      width: 100%;

      .navItem {
        width: 100%;
        height: 62px;
        display: block;
        padding-top: 10px;
        text-align: center;
        margin-top: 16px;
        box-sizing: border-box;

        img {
          width: 22px;
          height: 22px;
        }

        .title {
          font-size: 14px;
          font-family: PingFangSC-Regular, PingFang SC;
          font-weight: 400;
          color: #666666;
          line-height: 14px;
          margin-top: 6px;
          text-align: center;
        }
      }

      .navItem_active {
        background: #00bfff;

        .title {
          color: #ffffff;
        }
      }
    }
  }

  .rightMain {
    flex: 1;
    height: 100%;
    background: #f3f4f5;
    padding: 16px;

    .mainWrap {
      width: 100%;
      height: 100%;
      overflow-y: auto;
    }
  }
}
</style>