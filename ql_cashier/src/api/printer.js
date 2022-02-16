import {
    post
} from '@/utils/request'

// 打印收款信息
export const printPayInfo = data => post('http://localhost:5826/printer/print', data) 
