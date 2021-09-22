const express = require('express');
const app = express();

const mdfn = (req,res,next)=>{
    next();
}

// 用 use() 为所有的路由和动词添加该函数
app.use(mdfn);

// 用 use() 为一个特定的路由添加该函数
app.use('/ss',mdfn);

// 为一个特定的 HTTP 动词和路由添加该函数
app.get('/',mdfn);

app.listen(3000);