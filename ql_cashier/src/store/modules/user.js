import {
    shopDetail,
    login,
    loginOut
} from "@/api/login"
import router from '@/router';
import {
    Message
} from 'element-ui';
import {
    getToken,
    setToken,
    removeToken
} from '@/utils/auth';
const user = {
    namespaced: true, // 开启命名空间
    state: {
        // 存储token
        token: getToken(),
        userInfo: null
    },

    mutations: {
        // 修改token，并将token存入localStorage
        SET_TOKEN: (state, token) => {
            state.token = token
        },
        SET_userInfo: (state, userInfo) => {
            state.userInfo = userInfo
        }
    },
    actions: {
        Login({
            commit
        }, user) {
            return new Promise((resolve, reject) => {
                console.log(4335)
                login(user).then(res => {
                    console.log(111, res)
                    if (res.code == 200) {
                        console.log(1)
                        commit('SET_TOKEN', res.datas.token)
                        setToken(res.datas.token)
                        resolve()
                    } else if (res.code == 400) {
                        console.log(11)
                        Message({
                            showClose: true,
                            message: "账号或密码错误"
                        });
                    }

                }).catch(err => {
                    reject(err)
                })
            })
        },
        LoginOut({
            state
        }, user) {
            return new Promise((resolve, reject) => {
                console.log(state, 'loginout')
                loginOut(user).then(res => {
                    if (res.code == 200) {
                        removeToken()
                        setTimeout(() => {
                            router.replace({
                                path: '/login',
                                query: {
                                    redirect: router.currentRoute.fullPath
                                }
                            })
                        }, 300)
                        resolve
                    }
                }).catch(err => {
                    reject(err)
                })
            })
        },
        GetUserInfo({
            commit,
            state,
        }, data) {
            console.log(state)
            return new Promise((resolve, reject) => {
                shopDetail(data).then(res => {
                    console.log(111, res)
                    if (res.code == 200) {
                        commit('SET_userInfo', res.datas.store_info)
                        resolve()
                    }else{
                        reject(res.datas.error)
                    }

                }).catch(() => {
                    reject()
                })
            })
        },
    }
}
export default user