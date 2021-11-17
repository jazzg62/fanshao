<template>
    <el-dialog width="656px" :visible.sync="show" center>
        <div class="form">
            <h3>请输入付款信息</h3>
            <div class="form-item">
                <label class="label" for="member_mobile">手机号码</label>
                <input
                    placeholder="请输入会员手机号"
                    name="member_mobile"
                    v-model="form.member_mobile"
                />
            </div>
            <h3 style="font-size: 24px">请输入付款金额</h3>
            <div class="form-item form-item-bigger">
                <label class="label" for="xfje">￥</label>
                <input name="xfje" v-model="form.xfje" />
            </div>
            <el-button class="submit-btn" type="primary" @click="pay()"
                >确认</el-button
            >
        </div>
    </el-dialog>
</template>

<script>
export default {
    name: "PayForm",
    props: {
        show: {
            type: Boolean,
        },
    },
    data: function(){
        return {
            form:{
                member_mobile:"",
                xfje:"",
            },
        }
    },
};
</script>

<style lang="scss" scoped>
.form {
    display: flex;
    flex-direction: column;
    margin-top: -30px;
    width: 477px;
    height: calc(472px - 55px);
    h3 {
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
        input {
            font-size: 32px;
            color: #ea4335;
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
