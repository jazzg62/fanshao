<template>
    <div class="header">
        <router-link to="/">
            <div class="icon icon-l icon-menu pointer"></div>
        </router-link>
        <div class="icon icon-xl icon-ql"></div>
        <h2>欢迎使用企联收银台!</h2>

        <div class="btn mla pointer" @click="dialogFormVisible = true">
            <div class="icon icon-m icon-edit"></div>
            <span>修改密码</span>
        </div>
        <div class="btn pointer" @click="logout()">
            <div class="icon icon-m icon-logout"></div>
            <span>退出登录</span>
        </div>

        <div class="btn">
            <div class="icon icon-m icon-clock"></div>
            <Timer></Timer>
        </div>
        <el-dialog
            width="547px"
            :visible.sync="dialogFormVisible"
            center
        >
            <h2 class="form-header">修改密码</h2>
            <div class="form">
                <div class="form-item">
                    <label class="label" for="old_password">旧密码</label>
                    <input
                        placeholder="请输入旧密码"
                        name="old_password"
                        v-model="form.old_password"
                    />
                </div>
                <div class="form-item">
                    <label class="label" for="new_password">新密码</label>
                    <input
                        placeholder="请输入新密码"
                        name="new_password"
                        v-model="form.new_password"
                    />
                </div>
                <el-button
                    class="submit-btn"
                    type="primary"
                    @click="modifyPassword()"
                    >提 交</el-button
                >
            </div>
        </el-dialog>
    </div>
</template>

<script>
import Timer from "../components/Timer.vue";
import {ApiUrl} from "../constant";
import {stringify} from "querystring";
export default {
    name: "Header",
    data: () => {
        return {
            dialogFormVisible: false,
            form: {
                old_password: "",
                new_password: "",
            },
        };
    },
    components: {
        Timer,
    },
    methods: {
        logout() {
            localStorage.removeItem("key");
            this.$router.push("/login");
        },
        home() {
            this.$router.push("/");
        },
        modifyPassword() {
            this.$http.post(ApiUrl+'?act=seller_sm&op=xgmm',stringify(Object.assign(this.form, {key:localStorage.getItem('key')}))).then(res=>{
                console.log(res);
                if(res.data.code != 200){
                    this.$message.error(res.data.datas.error);
                    return ;
                }
                this.$message.success("修改成功");
                this.dialogFormVisible = false;
                this.form.old_password = "";
                this.form.new_password = "";
            })
        },
    },
};
</script>

<style lang="scss" scoped>
.header {
    background: #28b3e0;
    display: flex;
    align-items: center;
    color: white;
    padding: 0 25px;
    height: 85px;

    .icon-ql {
        margin-left: 30px;
    }
    h2 {
        margin-left: 10px;
        font-weight: normal;
    }
    .mla {
        margin-left: auto;
    }
    .btn {
        display: flex;
        align-items: center;
        padding-right: 24px;

        span {
            margin-left: 10px;
        }
    }
    .form {
        display: flex;
        flex-direction: column;
        width: 417px;
        color: #333;
        &-header{
            font-size: 21px;
            padding: 0;
            margin: 0;
            margin-top: -30px;
        }
        .form-item {
            display: flex;
            align-items: center;
            border: 1px solid #ccc;
            padding: 0 15px;
            border-radius: 3px;
            margin-bottom: 20px;
            height: 50px;
            box-sizing: border-box;
            label {
                flex: none;
                font-size: 16.5px;
            }
            input {
                flex: 1;
                border: none;
                outline: none;
                height: 40px;
                box-sizing: border-box;
                padding: 0;
                margin-left: 30px;
                font-size: 16.5px;
            }
            &:first-child{
                margin-top: 50px;
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
}
</style>