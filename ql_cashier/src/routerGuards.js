import router from './router';
import store from './store'
import {
    getToken,
    removeToken
} from '@/utils/auth';
const whiteList = ['/login']
router.beforeEach(async (to, from, next) => {
    // debugger
    if (getToken()) {
        if (to.path === '/login') {
            next({
                path: '/'
            })
        } else {
            if (!store.state.user.userInfo) {
                try {
                    await store.dispatch('user/GetUserInfo',{})
                    next()
                } catch {
                    removeToken()
                    next('/login')
                }
            }else{
                next()
            }
        }
    } else {
        if (whiteList.indexOf(to.path) !== -1) {
            next()
        } else {
            next('/login')
        }
    }
})