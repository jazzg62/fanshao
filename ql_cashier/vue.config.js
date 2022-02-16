module.exports = {
    lintOnSave: false, //关闭es-lint效验
    publicPath: '',
    devServer: {
        // open: true,
        // host: '192.168.3.58',
        // port: 8080,
        // https: false,
        // hotOnly: false,
        // http 代理配置
        disableHostCheck: true,
        proxy: {
            '/dev-api': {
                target: 'https://www.cnql888.com/',
                ws: false,
                changeOrigin: true,
                pathRewrite: {
                    '^/dev-api': '' //通过pathRewrite重写地址，将前缀/api转为/
                }
            }
        }

        // before: (app) => {}
    },
}