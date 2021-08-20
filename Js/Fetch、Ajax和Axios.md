## Fetch、Ajax和Axios

### Ajax

Asynchronous JavaScript + XML：异步的JavaScript和XML；

### Axios

Axios是一个基于Promise网络请求库，作用于Node.js和浏览器中。

在服务器端它使用原生Node.js http模块，而在客户端则使用XMLHTTPRequest。

客户端 Axios 的主要特性有：

从浏览器创建 XMLHttpRequests
支持 Promise API
拦截请求和响应
转换请求和响应数据
取消请求
自动转换JSON数据
客户端支持防御XSRF

### Fetch

Fetch提供了一个获取资源的接口（包括跨域请求）。

Fetch 是一个现代的概念, 等同于 XMLHttpRequest。它提供了许多与 XMLHttpRequest 相同的功能，但被设计成更具可扩展性和高效性。

Fetch的核心在于对HTTP接口的抽象，包括Request、Response、Headers和Body，以及用于初始化异步请求的global fetch。

除此之外，Fetch 还利用到了请求的异步特性——它是基于 Promise 的。

fetch() 方法必须接受一个参数——资源的路径。无论请求成功与否，它都返回一个 Promise 对象，resolve 对应请求的 Response。

### Fetch和Axios/Ajax的关系

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/515d70fb207e49b79e9edaa8b2d871c5~tplv-k3u1fbpfcp-watermark.awebp)

1、Ajax 是一种代表异步 JavaScript + XML 的模型（技术合集），所以 Fetch 也是 Ajax 的一个子集
2、在之前，我们常说的 Ajax 默认是指以 XHR 为核心的技术合集，而在有了 Fetch 之后，Ajax 不再单单指 XHR 了，我们将以 XHR 为核心的 Ajax 技术称作传统 Ajax。
3、Axios 属于传统 Ajax（XHR）的子集，因为它是基于 XHR 进行的封装。



Fetch取代Ajax？

1、异步编程是 JavaScript 发展的大趋势，且绝大多数浏览器都已支持标准 Promise。
2、Fetch API 是浏览器自带的 API，且它是基于标准 Promise 的。
3、传统 Ajax 原生写法结构比较混乱，不符合关注分离的原则，写过远程 XHR 的同学应该深有体会。
4、Axios 是基于 XHR 封装的 Promise 请求库，用起来确实方便。



 



















