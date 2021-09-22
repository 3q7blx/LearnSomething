const express = require('express');
const app = express();
const  wiki = require('./wiki.js')
const logger = require('morgan');


app.listen(3000,()=>{
    console.log('监听3000端口')
})
app.get('/',(req,res)=>{
    res.send('Heee');
})

app.use('/wiki',wiki);
app.use(logger('dev'));