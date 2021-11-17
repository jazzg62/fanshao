<template>
    <div class="store-info">
        <div class="store-avatar">
            <img
                :src="avatar"
                alt=""
            />
        </div>
        <div class="column">
            <div class="store-name">{{name}}</div>
            <div class="store-vip">本店会员（{{hys}}个）</div>
        </div>
    </div>
</template>

<script>
import {getStoreInfo} from "../common";
export default {
    data:()=>{
        return {
            name:"",
            avatar:"",
            hys:"",
        }
    },
    beforeMount:function(){
        let store_info = getStoreInfo();
        this.name = store_info.name;
        this.avatar = store_info.avatar;
        this.hys = store_info.hys;
    }
}
</script>

<style lang="scss" scoped>
.store-info {
    display: flex;
    align-items: center;
    .store-avatar {
        width: 50px;
        height: 50px;
        border-radius: 50%;
        overflow: hidden;
        margin-right: 10px;
        img {
            width: 100%;
            height: 100%;
        }
    }
    .store-name {
        width: 120px;
        overflow: hidden;
        white-space: nowrap;
        text-overflow: ellipsis;
        text-align: left;
        color: #333;
    }
    .store-vip {
        font-size: 12px;
        width: 120px;
        overflow: hidden;
        white-space: nowrap;
        text-overflow: ellipsis;
        text-align: left;
        color: #9e9e9e;
    }
}
</style>