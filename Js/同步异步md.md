# 同步异步，宏任务微任务，事件循环机制

event loop过程

同步代码，一行一行放在Call Stack执行
遇到异步，会先‘记录’下，等待时机（定时、网络请求等）
时机到了，就移动到Callback Queue
如 Call Stack为空（即同步代码执行完），Event Loop开始工作
轮询查找Callback Queue，如有则移动到Call Stack执行
然后继续轮询查找（永动机一样）

##### 什么是宏任务？什么是微任务？

宏任务：setTimeout, setInterval, Ajax , Dom事件
微任务：Promise, async/await
微任务执行时机比宏任务要早。

执行顺序

Call Stack空闲
执行当前的微任务
尝试DOM渲染
触发Event loop

##### 微任务为什么比宏任务执行更早

每次Call Stack清空（即每次轮询结束），即同步任务执行完，都是DOM重新渲染的机会，DOM结构如有改变则重新渲染，然后再去触发下一次Event loop。

##### 微任务和宏任务的区别

宏任务： DOM渲染后触发， 如setTimeout; 是由浏览器规定的。

微任务： DOM渲染前触发，如Promise；是ES6规定的。

























