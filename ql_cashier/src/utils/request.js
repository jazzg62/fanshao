import axios from 'axios';
import qs from 'qs'

import {
    getToken,
    removeToken
} from '@/utils/auth';
import { Message } from 'element-ui';
// removeToken
import router from '@/router';
// 请求超时时间
axios.defaults.timeout = 100000;
axios.defaults.baseURL = process.env.VUE_APP_BASE_API;
// post请求头
// axios.defaults.headers.post['Content-Type'] = 'application/x-www-form-urlencoded;charset=UTF-8';
// 请求拦截器
axios.interceptors.request.use(
    config => {
        // console.log(config)
        // if (getToken()) {
        //     config.headers.accessToken = getToken();
        // }
        return config;
    },
    error => {
        return Promise.reject(error);
    });
// 响应拦截器
axios.interceptors.response.use(
    response => {
        console.log(response,'response')
        // const res = response.data
        if(response.data.code==400){
            Message({
                showClose: true,
                message: response.data.datas.error,
                type: "error"
            });
            if(response.data.login=='0'){
                removeToken()
                setTimeout(() => {
                    router.replace({
                        path: '/login'
                    });
                }, 1000);
            }
        }
        return response
    },
    // 服务器状态码不是200的情况    
    error => {
        return Promise.reject(error.response);
    }
);
/** 
 * get方法，对应get请求 
 * @param {String} url [请求的url地址] 
 * @param {Object} params [请求时携带的参数] 
 */
export function get(url, params, spell) {
    return new Promise((resolve, reject) => {
        if (spell) {
            let i = 0
            for (let key in params) {

                if (i == 0) {
                    url += '?' + key + '=' + params[key]
                } else {
                    url += '&' + key + '=' + params[key]
                }
                i++
            }
        }
        // console.log(url)
        params.key=getToken()
        axios.get(url, {
                params:params
            })
            .then(res => {
                resolve(res.data);
            })
            .catch(err => {
                reject(err)
            })
    });
}
/** 
 * post方法，对应post请求 
 * @param {String} url [请求的url地址] 
 * @param {Object} params [请求时携带的参数] 
 */
export function post(url, params, spell) {
    return new Promise((resolve, reject) => {
        if (spell) {
            let i = 0
            for (let key in params) {

                if (i == 0) {
                    url += '?' + key + '=' + params[key]
                } else {
                    url += '&' + key + '=' + params[key]
                }
                i++
            }
        }
        params.key=getToken()
        axios.post(url, qs.stringify(params))
            .then(res => {
                resolve(res.data);
            })
            .catch(err => {
                reject(err)
            })
    });
}