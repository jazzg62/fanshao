import Vue from 'vue'
import VueRouter from 'vue-router'

Vue.use(VueRouter)

const routes = [
    {
        path:'/',
        redirect:'/home'
    },
    {
        path:'/login',
        name:'login',
        component:()=>import('@/views/login')
    },{
        path:'/home',
        name:'home',
        component:()=>import('@/views/home')
    },
    {
        path:'/admin',
        name:'admin',
        redirect:'/admin/collection',
        component:()=>import('@/views/admin/home'),
        children:[
            {
                path:'collection',
                name:'collection',
                component:()=>import('@/views/admin/collection'),
                meta:{
                    title:'收款记录',
                    icon:'admin_skjl',
                    show:true
                }
            },
            {
                path:'members',
                name:'members',
                component:()=>import('@/views/admin/members'),
                meta:{
                    title:'会员管理',
                    icon:'admin_hygl',
                    show:true
                }
            },
            {
                path:'dataHZ',
                name:'dataHZ',
                component:()=>import('@/views/admin/dataHZ'),
                meta:{
                    title:'数据汇总',
                    icon:'admin_sjhz',
                    show:true
                }
            },
            {
                path:'merchants',
                name:'merchants',
                component:()=>import('@/views/admin/merchants'),
                meta:{
                    title:'商家账户',
                    icon:'admin_sjzh',
                    show:true
                }
            },
            {
                path:'memberInfo',
                name:'memberInfo',
                component:()=>import('@/views/admin/memberInfo'),
                meta:{
                    title:'商家账户',
                    icon:'admin_sjzh',
                    show:false
                }
            }
        ]
    }
]

const router = new VueRouter({
    mode: 'hash',
    base: '/dist/',
    routes
})

export default router