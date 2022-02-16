module.exports = {
    publicPath: '',
    chainWebpack: config => {
        config
            .plugin('html')
            .tap(args => {
                args[0].title = "企联收银台";
                return args;
            })
    }
}