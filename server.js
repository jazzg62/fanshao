const exec = require('child_process').execFile;
const axios = require('axios');

let startServer = (function(){
    const exec_path = "./Cserver/Release/Cserver.exe";
    return function(){
        let child = exec(exec_path, function (error, stdout, stderr) {
            if(error) return console.error(error);
            // 返回结果封装在 stdout 中，字符串格式
            console.log(stdout);
        });
    }
})();

let reqStart =  function(){
    return axios.get('http://localhost:5876/start')
}

let printFile = function(data){
    return axios.post('http://localhost:5876/print/file', data);
}

module.exports = {
    startServer,
    reqStart,
    printFile
}
