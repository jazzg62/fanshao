<template>
    <div>
        <Header></Header>
        <div class="row">
            <div class="sidebar">
                <StoreInfo></StoreInfo>
                <Menu name="明细"></Menu>
                
            </div>
            <div class="table">
                <div class="table-search">
                    <div class="member-mobile">
                        <input
                            type="text"
                            id="member-mobile"
                            name="member-mobile"
                            placeholder="请输入手机号"
                        />
                        <div class="icon icon-s icon-search"></div>
                    </div>
                    <div class="xflx">
                        <div class="type">红包支付</div>
                        <div class="type">支付宝支付</div>
                        <div class="type">微信支付</div>
                        <div class="type">充值余额支付</div>
                        <div class="type select">全部查询</div>
                    </div>
                </div>
                <el-table :data="tableData" stripe border >
                    <el-table-column prop="id" label="id" align="center">
                    </el-table-column>
                    <el-table-column
                        prop="member_name"
                        label="微信昵称"
                        align="center"
                    >
                    </el-table-column>
                    <el-table-column prop="member_mobile" label="手机号" align="center">
                    </el-table-column>
                    <el-table-column prop="xfje" label="支付金额" align="center">
                    </el-table-column>
                    <el-table-column prop="xfje" label="时间" align="center">
                    </el-table-column>
                    <el-table-column prop="xflx" label="消费类型" align="center">
                    </el-table-column>
                </el-table>

                <div class="table-navigation">
                    <span class="table-total">共1500条记录</span>
                    <div class="center">
                        <div class="table-navigation-list">
                            <div class="table-navigation-item arrow">◀</div>
                            <div class="table-navigation-item ">1</div>
                            <div class="table-navigation-dot">...</div>
                            <div class="table-navigation-item">7</div>
                            <div class="table-navigation-item select">8</div>
                            <div class="table-navigation-item">9</div>
                            <div class="table-navigation-dot">...</div>
                            <div class="table-navigation-item">15</div>
                            <div class="table-navigation-item arrow">▶</div>
                        </div>
                        <div class="page-total">
                            <span>到</span>
                            <input type="text" />
                            <span>页</span>
                        </div>
                    </div>
                    <select
                        class="table-size"
                        name="table-size"
                        id="table-size"
                    >
                        <option value="10">10/页</option>
                        <option value="20">20/页</option>
                        <option value="30">30/页</option>
                        <option value="40">40/页</option>
                    </select>
                </div>
            </div>
        </div>

        
    </div>
</template>

<script>
import Header from "../components/Header";
import StoreInfo from "../components/StoreInfo";
import Menu from "../components/Menu";
export default {
    name: "TradingRecord",
    beforeMount:function(){
    },
    components: {
        Header,
        StoreInfo,
        Menu
    },
    data: () => {
        return {
            payFrom:{
                member_mobile: "",
                xfje: "",
            },
            isShowPayForm:false,
            tableData:[],
            tableData1: [
                {
                    id: 1,
                    member_name: "张三",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "红包支付",
                },
                {
                    id: 2,
                    member_name: "李四",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "微信支付",
                },
                {
                    id: 3,
                    member_name: "阿斯蒂芬",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "支付宝支付",
                },
                {
                    id: 4,
                    member_name: "安斯",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "充值支付",
                },
                {
                    id: 1,
                    member_name: "张三",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "红包支付",
                },
                {
                    id: 2,
                    member_name: "李四",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "微信支付",
                },
                {
                    id: 3,
                    member_name: "阿斯蒂芬",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "支付宝支付",
                },
                {
                    id: 4,
                    member_name: "安斯",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "充值支付",
                },
                {
                    id: 3,
                    member_name: "阿斯蒂芬",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "支付宝支付",
                },
                {
                    id: 4,
                    member_name: "安斯",
                    member_mobile: "18955718231",
                    xfje: "100.00",
                    xflx: "充值支付",
                },
            ],
        };
    },
    methods:{
        showPayForm(){
            this.isShowPayForm = true;
        },
        pay(){

        }
    }
};
</script>

<style lang="scss" scoped>
.row {
    display: flex;
}
.column {
    display: flex;
    flex-direction: column;
}
.sidebar {
    // width: 300px;
    display: flex;
    flex-direction: column;
    align-items: center;
    padding-top: 35px;
    padding-left: 25px;
    padding-right: 40px;
}
</style>
