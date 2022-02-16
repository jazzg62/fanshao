import {
    post,
    get
} from '@/utils/request'
export const login = data => post('/mobile/index.php?act=sm_login', data)//账号密码登陆
export const loginOut = data => post('/mobile/index.php?act=seller_sm&op=logout', data)//账号密码登陆
export const resolvePassword=data=>post('/mobile/index.php?act=seller_sm&op=xgmm',data)//修改密码
export const shopDetail=data=>get('/mobile/index.php?act=seller_sm&op=store_xx',data)//获取店铺信息
