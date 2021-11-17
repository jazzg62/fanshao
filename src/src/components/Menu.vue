<template>
    <div class="menus">
        <div :class="'item pointer '+ (item.name==name?'select':'')" v-for="item in menus" :key="item.name" @click="handleClick(item)">
            <div class="" :class="'icon icon-s '+item.icon+(item.name==name?'-w':'')"></div>
            <div class="name">{{item.name}}</div>
        </div>
    </div>
</template>
<script>
export default {
    name: 'Menu',
    props:{
        name: {
            type: String,
            default: '收款'
        }
    },
    data() {
        return {
            menus: [
                {
                    name: '收款',
                    icon: 'icon-shoukuan',
                    path: '/receipt'
                },
                {
                    name: '明细',
                    icon: 'icon-mingxi',
                    path: '/detail'
                }
            ]
        }
    },
    methods: {
        handleClick(item) {
            if(this.name !== item.name){
                this.$router.push(item.path)
            }
        }
    }
}
</script>

<style lang="scss" scoped>
.menus {
    display: flex;
    flex-direction: column;
    margin-top: 20px;

    .item {
        width: 165px;
        height: 38px;
        display: flex;
        align-items: center;
        border-radius: 50px;
        font-size: 15px;
        color: #28b3e0;
        padding: 0 20px;
        box-sizing: border-box;
        &:nth-child(n + 2) {
            margin-top: 10px;
        }
        .icon {
            margin-left: 5px;
            margin-right: 8px;
        }
    }
    .select {
        background: #28b3e0;
        color: #fff;
    }
}
</style>