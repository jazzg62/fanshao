# shaoma

**收银台客户端，基于electron。**

## 快速开始

克隆和运行这个项目你需要安装[Git](https://git-scm.com) 和 [Node.js](https://nodejs.org/en/download/) (带有 [npm](http://npmjs.com)的版本)，然后在命令行运行

```bash
# 克隆项目
git clone git@github.com:jazzg62/fanshao.git
# 安装依赖
npm install
# 运行项目
npm start
```

## 发布
0. 修改package.json的版本号
1. 使用npm run win64打包windows 64版本，或使用npm run win32来打包windows 32版本
2. 将打包好的.exe文件和latest.yml放置到项目服务器fanshao目录下

## 修改
1. 文件前端位于src目录下，是一个vue单页面项目
2. 可使用cd进入src目录下，使用npm run serve来调试项目
3. 配置代理来解决跨域问题

### electron
1. 通知 https://www.electronjs.org/zh/docs/latest/tutorial/notifications
2. xxxx
## License

MIT
