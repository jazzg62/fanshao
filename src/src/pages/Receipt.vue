<template>
    <div>
        <Header></Header>
        <div class="row">
            <div class="sidebar">
                <StoreInfo></StoreInfo>
                <Menu name="收款"></Menu>
            </div>
            <div class="table">
                <div class="table-search">
                    <div class="member-mobile">
                        <input
                            type="text"
                            id="member-mobile"
                            name="member-mobile"
                            v-model="table.search.member_mobile"
                            placeholder="请输入手机号"
                            @keypress.enter="search()"
                        />
                        <div class="icon icon-m icon-search"></div>
                    </div>
                    <div class="xflx">
                        <div class="type type-btn" @click="showPayForm()">发起收款</div>
                        <div class="type" :class="{'select':table.search.lx==2}" @click="table.search.lx=2">待支付</div>
                        <div class="type" :class="{'select':table.search.lx==1}" @click="table.search.lx=1">已支付</div>
                        <div class="type" :class="{'select':table.search.lx==0}" @click="table.search.lx=0">全部查询</div>
                    </div>
                </div>
                <el-table :data="table.data.list" stripe border v-loading="table.loading">
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
                    <el-table-column prop="zt" label="支付状态" align="center">
                        <template slot-scope="scope">
                            <span :style="{color: scope.row.zt === '已支付'?null:'red'}">{{scope.row.zt}}</span>
                        </template>
                    </el-table-column>
                </el-table>

                <div class="table-navigation">
                    <span class="table-total">共{{table.data.total}}条记录</span>
                    <div class="center">
                        <div class="table-navigation-list">
                            <div class="table-navigation-item arrow" @click="last()">◀</div>
                            <div v-for="item in table.pages" :key="item.num" :class="{'select':item.s,'table-navigation-item':item.num>=0,'table-navigation-dot':item.num<0}" @click="navigateTo(item.num)">{{item.num>0?item.num:'...'}}</div>
                            <div class="table-navigation-item arrow" @click="next()">▶</div>
                        </div>
                        <div class="page-total">
                            <span>到</span>
                            <input type="text" v-model="table.targetPage" @keypress.enter="enter()" title="输入要跳转的页码并回车" />
                            <span>页</span>
                        </div>
                    </div>
                    <select
                        class="table-size"
                        name="table-size"
                        id="table-size"
                        v-model="table.search.page"
                    >
                        <option value="10">10/页</option>
                        <option value="20">20/页</option>
                        <option value="30">30/页</option>
                        <option value="40">40/页</option>
                    </select>
                </div>
            </div>
        </div>

        <el-dialog
            width="656px"
            :visible.sync="isShowPayForm"
            center
            @opened="opened()"
        >
            <div class="form">
                <h3>请输入付款信息</h3>
                <div class="form-item">
                    <label class="label" for="member_mobile">手机号码</label>
                    <input
                        placeholder="请输入会员手机号"
                        name="member_mobile"
                        ref="ref"
                        v-model="payFrom.member_mobile"
                    />
                </div>
                <h3 style="font-size:24px">请输入付款金额</h3>
                <div class="form-item form-item-bigger">
                    <label class="label" for="xfje">￥</label>
                    <input
                        name="xfje"
                        v-model="payFrom.xfje"
                        @keypress.enter="pay()"
                        @keypress.tab="pay()"
                    />
                </div>
                <el-button
                    class="submit-btn"
                    type="primary"
                    @click="pay()"
                    >确认</el-button
                >
            </div>
        </el-dialog>
    </div>
</template>

<script>
import Header from "../components/Header";
import StoreInfo from "../components/StoreInfo";
import Menu from "../components/Menu";
import {ApiUrl} from "../constant"
import {stringify} from "querystring";
export default {
    name: "Receipt",
    beforeMount:function(){
        let {paypop} = this.$route.query;
        if(paypop == '1'){
            setTimeout(()=>{
                this.showPayForm();
            },500)
        }
        let {lx} = this.$route.query;
        if(lx){
            this.table.search.lx = lx;
        }

        this.loadForm();
    },
    components: {
        Header,
        StoreInfo,
        Menu
    },
    data: () => {
        return {
            table:{
                loading:false,
                data:{total:0,totalPage:0,list:[
                ]},
                search:{
                    curpage:1,
                    page:10,
                    member_mobile:'',
                    lx:0,
                },
                pages:[
                    {num:'1',s:'s'}
                ],
                targetPage:'',
            },
            payFrom:{
                member_mobile: "",
                xfje: "",
            },
            isShowPayForm:false,
        }
    },
    methods:{
        pay(){
            this.$prompt('请扫码', '提示', {
                    confirmButtonText: '确定',
                    cancelButtonText: '取消',
            }).then(({ value }) => {
                console.log(value);
                this.$message({
                    type: 'success',
                    message: '支付成功'
                });
            }).catch(() => {
                this.$message({
                    type: 'info',
                    message: '已取消'
                });       
            });
        },
        showPayForm(){
            this.isShowPayForm = true;
        },
        opened(){
            this.$refs.ref.focus();
        },
        hidePayForm(){
            this.isShowPayForm = false;
        },
        loadForm(){
            this.table.loading = true;
            this.$http.get(ApiUrl+"?act=seller_sm&op=skmx&"+stringify({...this.table.search,key:localStorage.getItem('key')})).then(res=>{
                this.table.data.total = res.data.datas.total;
                this.table.data.list = res.data.datas.list;
                this.table.data.totalPage = res.data.datas.totalPage;
                this.table.loading = false;

                this.reCalcautePage();
            })
        },
        reCalcautePage(){
            let list = [];            
            for(let i=1;i<=this.table.data.totalPage;i++){
                if(i<this.table.search.curpage-3){
                    list.push({num:1,s:''});
                    list.push({num:-1,s:''});
                    i=this.table.search.curpage-2;
                }
                if(i>this.table.search.curpage+2 && this.table.search.curpage+3 != this.table.data.totalPage){
                    list.push({num:-2,s:''});
                    list.push({num:this.table.data.totalPage,s:''});
                    break;
                }
                let status = i==this.table.search.curpage;
                list.push({num:i,s:status});
            }
            this.table.pages = list;
        },
        last(){
            if(this.table.search.curpage>1){
                this.table.search.curpage--;
                this.loadForm();
            }
        },
        next(){
            if(this.table.search.curpage<this.table.data.totalPage){
                this.table.search.curpage++;
                this.loadForm();
            }
        },
        navigateTo(num){
            if(num<1){
                return ;
            }
            this.table.search.curpage = num;
            this.loadForm();
        },
        enter(){
            let targetPage = parseInt(this.table.targetPage);
            if(targetPage<1 || targetPage>this.table.data.totalPage){
                this.$message.warning('请输入正确的页码');
                return 
            }
            this.table.search.curpage = targetPage;
            this.loadForm();
        },
        search(){
            this.loadForm();
        },
    },
    watch:{
        'table.search.lx':function(){
            this.table.search.curpage = 1;
            this.loadForm();
        },
        'table.search.page':function(){
            this.table.search.curpage = 1;
            this.loadForm();
        },
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

.form {
        display: flex;
        flex-direction: column;
        margin-top: -30px;
        width: 477px;
        height: calc(472px - 55px);
        h3{
            margin: 25px 0;
            font-size: 24px;
        }
        .form-item {
            display: flex;
            align-items: center;
            border: 1px solid #ccc;
            padding: 0 20px;
            border-radius: 3px;
            margin-bottom: 15px;
            box-sizing: border-box;
            overflow: hidden;
            height: 50px;
            label {
                flex: none;
                font-size: 16.5px;
            }
            input {
                flex: 1;
                border: none;
                outline: none;
                box-sizing: border-box;
                margin-left: 40px;
                position: relative;
                top: 1px;
                font-size: 16px;
                color: #333;
            }
        }
        .form-item-bigger {
            height: 80px;
            label {
                font-size: 34px;
            }
            input{
                font-size: 32px;
                color: #EA4335;
                overflow: hidden;
            }
        }
        .submit-btn {
            font-size: 24px;
            margin-top: 20px;
            background: rgb(40, 180, 225);
            border-color: rgb(40, 180, 225);
            height: 50px;
            display: flex;
            align-items: center;
            justify-content: center;
        }
    }
</style>
