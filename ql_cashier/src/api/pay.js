import {
    post,
    get
} from '@/utils/request'
export const payLog = data => get('/mobile/index.php?act=seller_sm&op=skmx', data) //收款记录接口
export const tadayData = data => get('/mobile/index.php?act=seller_sm&op=twoDates', data) //昨日今日数据统计
export const chartData = data => get('/mobile/index.php?act=seller_sm&op=sevenData', data) //七日数据总汇
export const zhifuzhanbi = data => get('/mobile/index.php?act=seller_sm&op=pay_ratio', data) //商家消费占比
export const payForMoney = data => post('/mobile/index.php?act=seller_sm&op=jhfs', data) //收款接口
export const payStatusGet = data => post('/mobile/index.php?act=seller_sm&op=pay_query', data) //查询收款状态
