import {
    get,
    post
} from '@/utils/request'
export const memberList = data => get('/mobile/index.php?act=seller_sm&op=hylb', data) //账号密码登陆
export const memberDetail = data => get('/mobile/index.php?act=seller_sm&op=hyxf', data) //会员消费记录查询
export const shopMoney = data => get('/mobile/index.php?act=seller_sm&op=shop_account', data)
export const shopAll = data => get('/mobile/index.php?act=seller_sm&op=xfsj', data)
export const rejesPwd = data => post('/mobile/index.php?act=seller_sm&op=xgmm', data) //修改密码