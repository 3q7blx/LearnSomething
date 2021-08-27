# 高频Vue

![Vue面试题.png](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/2a44f18af182434d901b74df18491dea~tplv-k3u1fbpfcp-watermark.awebp)

#### vue基础

##### 1、vue的基本原理

当一个Vue实例创建时，Vue会遍历data中的属性，用 Object.defineProperty（vue3.0使用proxy ）将它们转为 getter/setter，并且在内部追踪相关依赖，在属性被访问和修改时通知变化。 每个组件实例都有相应的 watcher 程序实例，它会在组件渲染的过程中把属性记录为依赖，之后当依赖项的setter被调用时，会通知watcher重新计算，从而致使它关联的组件得以更新

![0_tB3MJCzh_cB6i3mS-1.png](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/b1b16025a35b4cd2b343a92e740621b7~tplv-k3u1fbpfcp-watermark.awebp)

##### 2、双向数据绑定的原理

Vue.js 是采用数据劫持结合发布者-订阅者模式的方式，通过Object.defineProperty()来劫持各个属性的setter，getter，在数据变动时发布消息给订阅者，触发相应的监听回调。

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/a286bdc076ae425fb9591bb8c4153240~tplv-k3u1fbpfcp-watermark.awebp)



##### 3、使用Object.defineProperty()来进行数据劫持有什么缺点？

在对一些属性进行操作时，使用这种方法无法拦截，比如通过下标方式修改数组数据或者给对象新增属性，这都不能触发组件的重新渲染，因为 Object.defineProperty 不能拦截到这些操作。更精确的来说，对于数组而言，大部分操作都是拦截不到的，只是 Vue 内部通过重写函数的方式解决了这个问题。
在 Vue3.0 中已经不使用这种方式了，而是通过使用 Proxy 对对象进行代理，从而实现数据劫持。使用Proxy 的好处是它可以完美的监听到任何方式的数据改变，唯一的缺点是兼容性的问题，因为 Proxy 是 ES6 的语法。

##### 4、MVVM、MVC、MVP的区别

MVC、MVP 和 MVVM 是三种常见的软件架构设计模式，主要通过分离关注点的方式来组织代码结构，优化开发效率。























































