<template>
    <div class="login full-bg">
        <form
            class="login-form"
            method="POST"
            action="javascript:void(0);"
            @submit="login($event)"
        >
            <div class="ql-wrapper">
                <img src="../assets/login/QL-LOGO.png" alt="" />
            </div>
            <div class="input-group" :class="{'select':form.username.length!=0,'select1':highlight1}">
                <div class="icon icon-l " :class="{'icon-user-w':form.username.length==0,'icon-user':form.username.length!=0}"></div>
                <input
                    type="text"
                    id="username"
                    name="username"
                    v-model="form.username"
                    placeholder="请输入商家账号"
                    @focus="highlight1 = true"
                    @blur="highlight1 = false"
                />
            </div>
            <div class="input-group" :class="{'select':form.password.length!=0,'select1':highlight2}">
                <div class="icon icon-l " :class="{'icon-lock-w':form.password.length==0,'icon-lock':form.password.length!=0}"></div>
                <input
                    type="password"
                    id="password"
                    name="password"
                    v-model="form.password"
                    placeholder="请输入密码"
                    @focus="highlight2 = true"
                    @blur="highlight2 = false"
                />
            </div>
            <button class="login-btn pointer" :class="{'disabled':form.username.length ==0 || form.password.length == 0}">登录</button>
        </form>
    </div>
</template>

<script>
import {ApiUrl} from "../constant"
import {stringify} from "querystring";
export default {
    name: "Login",
    data: function () {
        return {
            form: {
                username: "",
                password: "",
            },
            highlight1: false,
            highlight2: false,
        };
    },
    methods: {
        login: function () {
            if (this.form.username == "" || this.form.password == "") {
                return ;
            }
            this.$http.post(ApiUrl+'?act=sm_login&op=login',stringify(this.form)).then(res => {
                console.log(res);
                if(res.data.code != 200){
                    this.$message.error(res.data.datas.error);
                    return ;
                }
                localStorage.setItem("key", res.data.datas.token);
                this.$http.get(ApiUrl+'?act=seller_sm&op=store_xx&'+stringify({key:res.data.datas.token})).then(res=>{
                    let {store_info} = res.data.datas;
                    let data = {
                        isLogin: true,
                        name: store_info.store_name,
                        avatar: store_info.store_avatar,
                        hys: store_info.hys
                    };
                    localStorage.setItem("store_info", JSON.stringify(data));
                    this.$router.push('/');
                });
            });
        },
    },
};
</script>

<style lang="scss" scoped>
.login {
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 20px;
    
    .login-form {
        width: 596px;
        height: 602px;
        padding-top: 80px;
        padding-left: 38px;
        padding-right: 38px;
        display: flex;
        flex-direction: column;
        background-color: white;
        border-radius: 15px;
        box-sizing: border-box;
        box-shadow: 1px 1px 10px rgba(0, 0, 0, 0.1);
    }

    .ql-wrapper {
        display: flex;
        align-items: center;
        justify-content: center;
    }
    .input-group {
        display: flex;
        align-items: center;
        border: 1px solid transparent;
        background: #f5f9fc;
        border-radius: 8px;
        overflow: hidden;
        height: 80px;
        box-sizing: border-box;
        margin-top: 50px;
        input {
            border: none;
            background: transparent;
            flex: 1;
            font-size: 22px;
            outline: none;
            height: 100%;
            color: #CFDDE8;
        }
        input::-webkit-input-placeholder{
            color: #CFDDE8;
        }
        input::-moz-placeholder{   /* Mozilla Firefox 19+ */
            color: #CFDDE8;
        }
        input:-moz-placeholder{    /* Mozilla Firefox 4 to 18 */
            color: #CFDDE8;
        }
        input:-ms-input-placeholder{  /* Internet Explorer 10-11 */ 
            color: #CFDDE8;
        }
        .icon {
            margin: 0 20px;
        }
        &:nth-child(n + 3) {
            margin-top: 14px;
        }
    }
    .select{  
        color: #333;
        input{
            color: #333;
        }
    }
    .select1{
        border:1px solid #4cb3e5; 
    }
    .login-btn {
        background-color: #4cb3e5;
        color: white;
        margin-top: 40px;
        height: 60px;
        border-radius: 8px;
        font-weight: bold;
        letter-spacing: 2px;
        font-size: 18px;
        border: none;
        box-shadow: 1px 1px 10px rgba(0, 0, 0, 0.1);
    }
    .disabled {
        background-color: gray;
        color: white;
    }
}
</style>
