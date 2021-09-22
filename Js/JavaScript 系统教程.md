# JavaScript 系统教程



JavaScript是一种具有函数优先的轻量级，解释型或即时编译型的编程语言。

JavaScript是一种基于原型编程、多范式的动态脚本语言，并且支持面向对象、命令式和声明式风格。

###### 脚本调用策略

若JavaScript加载于欲操作的HTML之前，则代码将出错。

内部可以使用事件监听器，监听；

document.addEventListener("DOMContentLoaded", function() {
  . . .
});

外部的可使用async ，它告知浏览器在遇到script元素时不要中断后续HTML内容的加载；

解决此问题的旧方法是：把脚本元素放在文档体的底端（</body> 标签之前，与之相邻），这样脚本就可以在 HTML 解析完毕后加载了。此方案（以及上述的 DOMContentLoaded 方案）的问题是：只有在所有 HTML DOM 加载完成后才开始脚本的加载/解析过程。对于有大量 JavaScript 代码的大型网站，可能会带来显著的性能损耗。这也是 async 属性诞生的初衷。

###### async 和 defer

浏览器遇到 async 脚本时不会阻塞页面渲染，而是直接下载然后运行。这样脚本的运行次序就无法控制，只是脚本不会阻止剩余页面的显示。当页面的脚本之间彼此独立，且不依赖于本页面的其它任何脚本时，async 是最理想的选择。

脚本调用策略小结：

- 如果脚本无需等待页面解析，且无依赖独立运行，那么应使用 `async`。
- 如果脚本需要等待页面解析，且依赖于其它脚本，调用这些脚本时应使用 `defer`，将关联的脚本按所需顺序置于 HTML 中。



###### 转换大小写

字符串方法 toLowerCase()和 toUpperCase() 字符串并将所有字符串分别转换为小写或大写。

let radData = 'My NaMe Is MuD';
radData.toLowerCase();
radData.toUpperCase();

###### 替换字符串的某个部分

browserType.replace('moz','van');



##### 数组

一种将一组数据存储在单个变量名下的优雅方式。

数组是一个包含了多个值的对象。数组对象可以存储在变量中，并且能用和其他任何类型的值完全相同的方式处理，区别在于可以单独访问列表中的每个值，并使用列表执行一些有用和高效的操作。

创建数组：let sequence = [1, 1, 2, 3, 5, 8, 13];
let random = ['tree', 795, [0, 1, 2]];

访问和修改数组元素：

获取数组长度：length；

###### 一些有用的数组方法

字符串与数组之间的转换：

let myData = 'Manchester,London,Liverpool,Birmingham,Leeds,Carlisle';

let myArray = myData.split(',');
myArray;

let myNewString = myArray.join(',');
myNewString;

将数组转换为字符串的另一种方法是使用toString()方法；

let dogNames = ["Rocket","Flash","Bella","Slugger"];
dogNames.toString(); //Rocket,Flash,Bella,Slugger

添加和删除数组项

push() ;pop();

unshift()和shift();



使用break 退出循环；

使用continue跳过迭代；不是完全跳出循环，而是跳过当前循环而执行下一个循环；



##### 函数-可复用代码块

###### 浏览器内置函数

###### 函数与方法

严格来说，内置浏览器函数并不是函数--它们是方法；但很大程度上函数与方法是可以互换的；二者区别在于方法是在对象内定义的函数。浏览器内置函数(方法)和变量(属性)存储在结构化对象内，以使代码更加高效，易于处理；

###### 自定义函数

###### 调用函数

###### 匿名函数

通常将匿名函数与事件处理程序一起使用。

匿名函数也称为函数表达式。函数表达式与函数声明有一些区别。函数声明会进行声明提升，而函数表达式不会；

###### 函数参数

###### 函数作用域和冲突

当创建一个函数时，函数内定义的变量和其他东西都在它们自己的单独的范围内，意味着它们被锁定在自己独立的隔间中，不能被函数外的代码访问。

所有函数的最外层被称为全局作用域。全局作用域内定义的值可以在任意地方访问。

###### 函数内部的函数



##### 事件介绍

事件是在编程时系统内发生的动作或者发生的事情，系统响应后，如果需要，可以某种方式对事件做出回应。

系统会在事件出现时产生或触发某种信号，并且会提供一个自动加载某种动作（列如：运行一些代码）的机制。

###### 使用网页事件的方式

可以通过多种不同的方法将事件监听器代码添加到网页，以便在关联的事件被触发时运行它。

###### 事件处理器属性

onclick ； onfocus； onblur; ondbclick;  onkeypress;

###### 行内事件处理器

即使在单一文件中，内置事件处理器也不是一个好主意。一个按钮看起来还好，但是如果有一百个按钮呢？

###### addEventListener()和 removeEventListener()

onclick 不能注册多个处理器；

###### 其他事件概念

事件对象

event、evt、e;它被自动传递给事件处理函数，以提供额外的功能和信息；

阻止默认行为

preventDefault()函数

###### 事件冒泡及捕获

当一个事件发生在具有父元素的元素上时，现代浏览器运行两个不同的阶段--捕获阶段和冒泡阶段。

在捕获阶段：

浏览器检查元素的最外层HTML，是否在捕获阶段注册了一个事件处理程序，如果是，则运行它。

然后，它移动到HTML中单击元素的下一个元素，并执行相同的操作，然后是单击元素再下一个祖先元素，依次类推，直到到达实际点击的元素。

在冒泡阶段：

浏览器检查实际点击的元素是否在冒泡阶段中注册一个onclick事件处理程序，如果是，则运行它；

然后它移动到下一个直接的祖先元素，并做同样的事情，然后是下一个，等等，直到它到达HTML元素；

stopPropagation() 它只会让当前事件处理程序运行，但事件不会在冒泡链上进一步扩大。

默认情况下，所有事件处理程序都是在冒泡阶段注册的。addEventListener()第三个参数为true，捕获；

事件委托



##### JavaScript对象入门

对象是一个包含相关数据和方法的集合，通常由一些变量和函数组成。

###### 点表示法

###### 子命名空间 

可以用一个对象来做另一个对象成员的值；

###### 括号表示法

另一种访问属性的方式是使用括号表示法。

###### 设置对象成员

括号表示法一个有用的地方是它不仅可以动态的去设置对象成员的值，还可以动态的去设置成员的名字。

###### this的含义

关键字对象this指向当前代码运行时的对象；



##### 构建函数和对象

function Person(name) {
  this.name = name;
  this.greeting = function() {
    alert('Hi! I\'m ' + this.name + '.');
  };
}

构建函数时JavaScript版本的类。它只定义了对象的属性和方法，除了没有明确创建一个对象和返回任何值之外，它有函数的全部功能。

**注：** 一个构建函数通常是大写字母开头，这样便于区分构建函数和普通函数。

var person1 = new Person('Bob');
var person2 = new Person('Sarah');

###### 创建对象的其他方式

声明一个对象的语法；

使用构造函数；

Object()构造函数；

var person1 = new Object();

使用create()方法：它允许基于现有对象创建新的对象；属性在原型中；

var person2 = Object.create(person1);



##### 对象原型

JavaScript常被描述为一种基于原型的语言，每个对象拥有一个原型对象，对象以其原型为模板，从模板继承方法和属性。原型对象也可能拥有原型，并从中继承方法和属性，一层一层，依次类推。这种关系常被称为原型链，它解释了为何一个对象会拥有定义在其他对象中属性和方法。

准确的说，这些属性和方法定义在Object的构造器函数之上的prototype属性上，而不是对象实例本身。

正确使用new运算符的方法就是在正常调用函数时，在函数名的前面加上一个new前缀。通过这种方法，在调用函数前加一个new，它就会返回一个这个函数的实例化对象。然后就可以在这个对象上面添加一些属性。

function doSomething(){}
doSomething.prototype.foo = "bar"; // add a property onto the prototype
var doSomeInstancing = new doSomething();
doSomeInstancing.prop = "some value"; // add a property onto the object
console.log( doSomeInstancing );



调用 `person1` 的“实际定义在 `Object` 上”的方法时，会发生什么？比如：

person1.valueOf()

浏览器首先检查，person1对象是否具有可用的valueOf()方法。

如果没有，则浏览器检查person1对象的原型对象是否具有可用的方法；

如果也没有，则浏览器检查Person()构造函数的prototype属性所指向的对象的原型对象是否具有可用的方法。

**注意**：必须重申，原型链中的方法和属性**没有**被复制到其他对象——它们被访问需要通过前面所说的“原型链”的方式

**注意**：没有官方的方法用于直接访问一个对象的原型对象——原型链中的“连接”被定义在一个内部属性中，在 JavaScript 语言标准中用 `[[prototype]]` 表示（参见 [ECMAScript](https://developer.mozilla.org/zh-CN/docs/Glossary/ECMAScript)）。然而，大多数现代浏览器还是提供了一个名为 `__proto__` （前后各有2个下划线）的属性，其包含了对象的原型。

###### prototype属性：继承成员被定义的地方

原因在于，继承的属性和方法是定义在 prototype 属性之上的（你可以称之为子命名空间 (sub namespace) ）——那些以 Object.prototype. 开头的属性，而非仅仅以 Object. 开头的属性。prototype 属性的值是一个对象，我们希望被原型链下游的对象继承的属性和方法，都被储存在其中。

于是 Object.prototype.watch()、Object.prototype.valueOf() 等等成员，适用于任何继承自 Object() 的对象类型，包括使用构造器创建的新的对象实例。

`Object.is()`、`Object.keys()`，以及其他不在 `prototype` 对象内的成员，不会被“对象实例”或“继承自 `Object()` 的对象类型”所继承。这些方法/属性仅能被 `Object()` 构造器自身使用。

JavaScript 中到处都是通过原型链继承的例子。比如，你可以尝试从 `String`、`Date`、`Number` 和 `Array`全局对象的原型中寻找方法和属性。它们都在原型上定义了一些方法，因此当你创建一个字符串时：

```
var myString = 'This is my string.';
```

Copy to Clipboard

`myString` 立即具有了一些有用的方法，如 `split()`、`indexOf()`、`replace()` 等。

###### create（）

Object.create()方法创建新的对象实例，实际做的是从指定原型对象创建一个新的对象。

###### constructor属性

每个实例对象都从原型中继承一个constructor属性，该属性指向了用于构造此实例对象的构造函数。

person1.constructor
person2.constructor

都将返回 `Person()` 构造器，因为该构造器包含这些实例的原始定义。

一个小技巧是，你可以在 `constructor` 属性的末尾添加一对圆括号（括号中包含所需的参数），从而用这个构造器创建另一个对象实例。毕竟构造器是一个函数，故可以通过圆括号调用；只需在前面添加 `new` 关键字，便能将此函数作为构造器使用。

var person3 = new person1.constructor('Karen', 'Stephenson', 26, 'female', ['playing drums', 'mountain climbing']);

###### 修改原型

事实上，一种极其常见的对象定义模式是，在构造器（函数体）中定义属性、在 `prototype` 属性上定义方法。如此，构造器只包含属性定义，而方法则分装在不同的代码块，代码更具可读性。



##### JavaScript中的继承

###### 原型式的继承

继承的对象函数并不是通过复制而来，而是通过原型链继承。原型式继承；

###### 从无参构造函数继承

如果继承的构造函数从不传入的参数中获取其属性值，则不需要在call()中为其指

```
function Brick() {
  this.width = 10;
  this.height = 20;
}
```

Copy to Clipboard

您可以这样继承`width`和`height`属性（以及下面描述的其他步骤）：

```
function BlueGlassBrick() {
  Brick.call(this);

  this.opacity = 0.5;
  this.color = 'blue';
}
```

Copy to Clipboard

请注意，我们仅传入了`this`到`call()`中 - 不需要其他参数，因为我们不会继承通过参数设置的父级的任何属性。定其他参数。

##### 使用JSON

JavaScript对象表示法JSON是用于将结构化数据表示为JavaScript对象的标准格式，通常用于在网站上表示和传输数据。

- JSON 是一种纯数据格式，它只包含属性，没有方法。
- JSON要求在字符串和属性名称周围使用双引号。 单引号无效。
- 甚至一个错位的逗号或分号就可以导致  JSON 文件出错。您应该小心的检查您想使用的数据(虽然计算机生成的 JSON 很少出错，只要生成程序正常工作)。您可以通过像 [JSONLint](http://jsonlint.com/) 的应用程序来检验 JSON。
- JSON 可以将任何标准合法的 JSON 数据格式化保存，不只是数组和对象。比如，一个单一的字符串或者数字可以是合法的 JSON 对象。虽然不是特别有用处……
- 与 JavaScript 代码中对象属性可以不加引号不同，JSON 中只有带引号的字符串可以用作属性。



###### 对象和文本之间的转换

- `parse()`: 以文本字符串形式接受JSON对象作为参数，并返回相应的对象。
- `stringify()`: 接收一个对象作为参数，返回一个对应的JSON字符串。



##### 异步JavaScript

阻塞

JavaScript一般是单线程的。

###### 线程

一个线程是一个基本的处理过程，程序用它来完成任务。每一个线程一次只能执行一个任务；

###### JavaScript是单线程的

JavaScript传统上是单线程的，即使有多个核，也只能在单一线程上运行多个任务，此线程称为主线程。

Webworkers解决单线程；

###### 异步代码

webworker局限，不能访问DOM，不能直接更新UI。



###### 异步JavaScript

老派 callbacks 新派promise；

###### 异步callbacks

y异步callbacks其实就是 函数，只不过作为参数传递给那些后台执行的其他函数。

###### Promises

`fetch()` API就是一个很好的例子, 它基本上就是一个现代版的，更高效的 [`XMLHttpRequest`](https://developer.mozilla.org/zh-CN/docs/Web/API/XMLHttpRequest)

```
fetch('products.json').then(function(response) {
  return response.json();
}).then(function(json) {
  products = json;
  initialize();
}).catch(function(err) {
  console.log('Fetch problem: ' + err.message);
});
```



###### 事件队列

像promise这样的异步操作被放入事件队列中，事件队列在主线程完成处理后运行，这样它们就不会阻止后续JavaScript代码的运行。排队操作将尽快完成，然后将结果返回到JavaScript环境。

###### 异步代码的本质



##### 合作异步JavaScript：超时和间隔

- `setTimeout()`

  在指定的时间后执行一段代码.

- `setInterval()`

  以固定的时间间隔，重复运行一段代码.

- `requestAnimationFrame()`

  setInterval()的现代版本;在浏览器下一次重新绘制显示之前执行指定的代码块，从而允许动画在适当的帧率下运行，而不管它在什么环境中运行.

这些函数设置的异步代码实际上在主线程上运行（在其指定的计时器过去之后）。

在 `setTimeout()` 调用执行之前或 `setInterval()` 迭代之间可以（并且经常会）运行其他代码。根据这些操作的处理器密集程度，它们可以进一步延迟异步代码，因为任何异步代码仅在主线程可用后才执行（换句话说，当调用栈为空时）。

###### setTimeout()

指定的时间（或延迟）不能保证在指定的确切时间之后执行，而是最短的延迟执行时间。在主线程上的堆栈为空之前，传递给这些函数的回调将无法运行。

最后，如果创建了 timeout，您可以通过调用`clearTimeout()`，将`setTimeout()`调用的标识符作为参数传递给它，从而在超时运行之前取消。要取消上面的超时，你需要这样做：

```
clearTimeout(myGreeting);
```



###### setInterval()

清除intervals

const myInterval = setInterval(myFunction, 2000);

clearInterval(myInterval);



###### 关于setTimeout()和setInterval()需要注意的几点

递归的timeouts

还有另一种方法可以使用`setTimeout()`：我们可以递归调用它来重复运行相同的代码，而不是使用`setInterval()`

let i = 1;

setTimeout(function run() {
  console.log(i);
  i++;
  setTimeout(run, 100);
}, 100);

#### 递归setTimeout()和setInterval()有何不同？

上述代码的两个版本之间的差异是微妙的。

- 递归 `setTimeout()` 保证执行之间的延迟相同，例如在上述情况下为100ms。 代码将运行，然后在它再次运行之前等待100ms，因此无论代码运行多长时间，间隔都是相同的。
- 使用 `setInterval()` 的示例有些不同。 我们选择的间隔包括执行我们想要运行的代码所花费的时间。假设代码需要40毫秒才能运行 - 然后间隔最终只有60毫秒。
- 当递归使用 `setTimeout()` 时，每次迭代都可以在运行下一次迭代之前计算不同的延迟。 换句话说，第二个参数的值可以指定在再次运行代码之前等待的不同时间（以毫秒为单位）。



当你的代码有可能比你分配的时间间隔，花费更长时间运行时，最好使用递归的 `setTimeout()` - 这将使执行之间的时间间隔保持不变，无论代码执行多长时间，你不会得到错误。



##### 立即超时

使用0用作setTimeout()的回调函数会立刻执行，但是在主线程代码运行之后执行。

### [使用 clearTimeout() or clearInterval()清除](https://developer.mozilla.org/zh-CN/docs/Learn/JavaScript/Asynchronous/Timeouts_and_intervals#使用_cleartimeout_or_clearinterval清除)

```
clearTimeout()` 和`clearInterval()` 都使用相同的条目列表进行清除。有趣的是，这意味着你可以使用任一一种方法来清除 `setTimeout()` 和 `setInterval()。
```

但为了保持一致性，你应该使用 `clearTimeout()` 来清除 `setTimeout()` 条目，使用 `clearInterval()`来清除 `setInterval()` 条目。 这样有助于避免混乱。

##### requestAnimationFrame()

`requestAnimationFrame()` 是一个专门的循环函数，旨在浏览器中高效运行动画。它基本上是现代版本的`setInterval()` —— 它在浏览器重新加载显示内容之前执行指定的代码块，从而允许动画以适当的帧速率运行，不管其运行的环境如何。

指示浏览器在下一次显示重新绘制时再次调用该函数。然后这个操作连续运行， 因为`requestAnimationFrame()`是递归调用的。

如果要执行某种简单的常规DOM动画, [CSS 动画](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Animations) 可能更快，因为它们是由浏览器的内部代码计算而不是JavaScript直接计算的。但是，如果您正在做一些更复杂的事情，并且涉及到在DOM中不能直接访问的对象(such as [2D Canvas API](https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API) or [WebGL](https://developer.mozilla.org/en-US/docs/Web/API/WebGL_API) objects), `requestAnimationFrame()` 在大多数情况下是更好的选择。

######  requestAnimationFrame() 与 setInterval() 和 setTimeout()有什么不同?

如前所述，我们没有为`requestAnimationFrame()`;指定时间间隔；它只是在当前条件下尽可能快速平稳地运行它。如果动画由于某些原因而处于屏幕外浏览器也不会浪费时间运行它。

另一方面`setInterval()`需要指定间隔。我们通过公式1000毫秒/60Hz得出17的最终值，然后将其四舍五入。四舍五入是一个好主意，浏览器可能会尝试运行动画的速度超过60fps，它不会对动画的平滑度有任何影响。如前所述，60Hz是标准刷新率。

### [撤销requestAnimationFrame()](https://developer.mozilla.org/zh-CN/docs/Learn/JavaScript/Asynchronous/Timeouts_and_intervals#撤销requestanimationframe)

`requestAnimationFrame()`可用与之对应的`cancelAnimationFrame()`方法“撤销”（不同于“set…”类方法的“清除”，此处更接近“撤销”之意）。

该方法以`requestAnimationFrame()`的返回值为参数，此处我们将该返回值存在变量 `rAF` 中：

```
cancelAnimationFrame(rAF);
```



##### Promise 

本质上，Promise是一个对象，代表操作的中间状态，它保证在未来可能返回某种结果。虽然Promise并不保证操作在何时完成并返回结果，但是它保证当结果可用时，代码能正确处理结果，当结果不可用时，代码同样会被执行，来优雅的处理错误。

## [Promise术语回顾](https://developer.mozilla.org/zh-CN/docs/Learn/JavaScript/Asynchronous/Promises#promise术语回顾)

在上面的部分中有很多要介绍的内容，所以让我们快速回过头来给你[一个简短的指南](https://developer.mozilla.org/zh-CN/docs/Learn/JavaScript/Asynchronous/Promises#Promise_terminology_recap)，你可以将它添加到书签中，以便将来更新你的记忆。你还应该再次阅读上述部分，以确保这些概念坚持下去。

1. 创建promise时，它既不是成功也不是失败状态。这个状态叫作**pending**（待定）。

2. 当promise返回时，称为 

   resolved

   （已解决）.

   1. 一个成功**resolved**的promise称为**fullfilled**（**实现**）。它返回一个值，可以通过将`.then()`块链接到promise链的末尾来访问该值。` .then()`块中的执行程序函数将包含promise的返回值。
   2. 一个不成功**resolved**的promise被称为**rejected**（**拒绝**）了。它返回一个原因（**reason**），一条错误消息，说明为什么拒绝promise。可以通过将`.catch()`块链接到promise链的末尾来访问此原因。



##### async和await：让异步编程更加简单

简单来说，它们是基于promises的语法糖，使异步代码更易于编写和阅读。通过使用它们，异步代码看起来更像是老式同步代码，因此它们非常值得学习。

###### async 关键字

将 async 关键字加到函数申明中，可以告诉它们返回的是 promise，而不是直接返回值。此外，它避免了同步函数为支持使用 await 带来的任何潜在开销。在函数声明为 async 时，JavaScript引擎会添加必要的处理，以优化你的程序。爽！

###### await关键字

 await 只在异步函数里面才起作用。它可以放在任何异步的，基于 promise 的函数之前。它会暂停代码在该行上，直到 promise 完成，然后返回结果值。在暂停的同时，其他正在等待执行的代码就有机会执行了。

它使代码简单多了，更容易理解 —— 去除了到处都是 `.then()` 代码块！



###### 添加错误处理

可以将同步的 `try...catch` 结构和 `async/await` 一起使用 

`catch() {}` 代码块会接收一个错误对象 `e` ; 我们现在可以将其记录到控制台，它将向我们提供详细的错误消息，显示错误被抛出的代码中的位置。

###### async/await 的缺陷

Async/await 让你的代码看起来是同步的，在某种程度上，也使得它的行为更加地同步。 await 关键字会阻塞其后的代码，直到promise完成，就像执行同步操作一样。它确实可以允许其他任务在此期间继续运行，但您自己的代码被阻塞。

意味着您的代码可能会因为大量await的promises相继发生而变慢。每个await都会等待前一个完成，而你实际想要的是所有的这些promises同时开始处理（就像我们没有使用async/await时那样）。



###### Async/await 的类方法

可以在类/对象方法前面添加`async`，以使它们返回promises，并`await`它们内部的promises。



#### 客户端API

当你给网页或者网页应用编写客户端的JavaScript时， 你很快会遇上应用程序接口（API ）—— 这些编程特性可用来操控网站所基于的浏览器与操作系统的不同方面，或是操控由其他网站或服务端传来的数据。

###### WebAPI 简介

首先，我们将从一个高层次看看API - 它们是什么；他们如何工作；如何在代码中使用它们，以及它们是如何组织的。我们也将看看不同主要类别的API以及它们的用途。

什么是API？

应用程序接口API是基于编程语言构建的结构，使开发人员更容易的创建复杂的功能。它们抽象了复杂的代码，并提供了一些简单的接口规则直接使用。

客户端JavaScript的API

客户端JavaScript中有很多可用的API — 他们本身并不是JavaScript语言的一部分，却建立在JavaScript语言核心的顶部，为使用JavaScript代码提供额外的超强能力。他们通常分为两类：

- **浏览器API**内置于Web浏览器中，能从浏览器和电脑周边环境中提取数据，并用来做有用的复杂的事情 。例如[Geolocation API](https://developer.mozilla.org/en-US/docs/Web/API/Geolocation_API)提供了一些简单的JavaScript结构以获得位置数据，因此您可以在Google地图上标示您的位置。在后台，浏览器确实使用一些复杂的低级代码（例如C++）与设备的GPS硬件（或可以决定位置数据的任何设施）通信来获取位置数据并把这些数据返回给您的代码中使用浏览器环境；但是，这种复杂性通过API抽象出来，因而与您无关。
- **第三方API**缺省情况下不会内置于浏览器中，通常必须在Web中的某个地方获取代码和信息。例如[Twitter API](https://dev.twitter.com/overview/documentation) 使您能做一些显示最新推文这样的事情，它提供一系列特殊的结构，可以用来请求Twitter服务并返回特殊的信息。

###### JavaScript，API和其他JavaScript工具之间的关系

- JavaScript — 一种内置于浏览器的高级脚本语言，您可以用来实现Web页面/应用中的功能。注意JavaScript也可用于其他象[Node](https://developer.mozilla.org/en-US/docs/Learn/Server-side/Express_Nodejs/Introduction)这样的的编程环境。但现在您不必考虑这些。
- 客户端API — 内置于浏览器的结构程序，位于JavaScript语言顶部，使您可以更容易的实现功能。
- 第三方API — 置于第三方普通的结构程序（例如Twitter，Facebook），使您可以在自己的Web页面中使用那些平台的某些功能（例如在您的Web页面显示最新的Tweets）。
- JavaScript库 — 通常是包含具有[特定功能](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Building_blocks/Functions#custom_functions)的一个或多个JavaScript文件，把这些文件关联到您的Web页以快速或授权编写常见的功能。例如包含jQuery和Mootools
- JavaScript框架 — 从库开始的下一步，JavaScript框架视图把HTML、CSS、JavaScript和其他安装的技术打包在一起，然后用来从头编写一个完整的Web应用。

##### API如何工作？

不同的JavaScriptAPI以稍微不同的方式工作，但通常它们具有共同的特征和相似的主题。

它们是基于对象的

API使用一个或多个 [JavaScript objects](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects) 在您的代码中进行交互，这些对象用作API使用的数据（包含在对象属性中）的容器以及API提供的功能（包含在对象方法中）。

###### 操作文档

通常使用一套大量使用Document对象来控制HTML和样式信息的文档对象模型（DOM）来实现。

![img](https://mdn.mozillademos.org/files/14557/document-window-navigator.png)

- window是载入浏览器的标签，在JavaScript中用[`Window`](https://developer.mozilla.org/zh-CN/docs/Web/API/Window)对象来表示，使用这个对象的可用方法，你可以返回窗口的大小（参见[`Window.innerWidth`](https://developer.mozilla.org/zh-CN/docs/Web/API/Window/innerWidth)和[`Window.innerHeight`](https://developer.mozilla.org/zh-CN/docs/Web/API/Window/innerHeight)），操作载入窗口的文档，存储客户端上文档的特殊数据（例如使用本地数据库或其他存储设备），为当前窗口绑定[event handler](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Building_blocks/Events#a_series_of_fortunate_events)，等等。
- navigator表示浏览器存在于web上的状态和标识（即用户代理）。在JavaScript中，用[`Navigator`](https://developer.mozilla.org/zh-CN/docs/Web/API/Navigator)来表示。你可以用这个对象获取一些信息，比如来自用户摄像头的地理信息、用户偏爱的语言、多媒体流等等。
- document（在浏览器中用DOM表示）是载入窗口的实际页面，在JavaScript中用[`Document`](https://developer.mozilla.org/zh-CN/docs/Web/API/Document) 对象表示，你可以用这个对象来返回和操作文档中HTML和CSS上的信息。例如获取DOM中一个元素的引用，修改其文本内容，并应用新的样式，创建新的元素并添加为当前元素的子元素，甚至把他们一起删除。

###### 文档对象模型

在浏览器标签中当前载入的文档用文档对象模型来表示。这是一个由浏览器生成的“树结构”，使编程语言可以很容易的访问HTML结构。

###### 基本的DOM操作

[`Document.querySelector()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Document/querySelector)是推荐的主流方法，它允许你使用CSS选择器选择元素，使用很方便。

- [`Document.getElementById()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Document/getElementById)，选择一个`id`属性值已知的元素，例如`<p id="myId">My paragraph</p>`。ID作为参数传递给函数，即 `var elementRef = document.getElementById('myId')`。
- [`Document.getElementsByTagName()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Document/getElementsByTagName)，返回页面中包含的所有已知类型元素的数组。如`<p>`s, `<a>`。元素类型作为参数传递给函数，即`var elementRefArray = document.getElementsByTagName('p')`.

###### 创建并放置新的节点

[`Document.createElement()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Document/createElement)创建一个新的段落

[`Node.appendChild()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Node/appendChild)方法在后面追加新的段落

[`Document.createTextNode()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Document/createTextNode)创建一个文本节点

###### 移动和删除元素

如果你想把具有内部链接的段落移到sectioin的底部，简单的做法是：

```
sect.appendChild(linkPara);
```

这样可以把段落下移到section的底部。

删除节点也非常的简单，至少，你拥有要删除的节点和其父节点的引用。在当前情况下，我们只要使用[`Node.removeChild()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Node/removeChild)即可，如下：

```
sect.removeChild(linkPara);
```

要删除一个仅基于自身引用的节点可能稍微有点复杂，这也是很常见的。没有方法会告诉节点删除自己，所以你必须像下面这样操作。

```
linkPara.parentNode.removeChild(linkPara);
```

###### 操作样式

通过JavaScript以不同的方式来操作CSS样式是可能的。

首先，使用 [`Document.stylesheets`](https://developer.mozilla.org/zh-CN/docs/Web/API/Document/styleSheets)返回[`CSSStyleSheet`](https://developer.mozilla.org/zh-CN/docs/Web/API/CSSStyleSheet)数组，获取绑定到文档的所有样式表的序列。然后添加/删除想要的样式。

然而，我们并不想扩展这些特性，因此它们在操作样式方面有点陈旧和困难，而现在有了更容易的方法。

第一种方法是直接在想要动态设置样式的元素内部添加内联样式。这是用[`HTMLElement.style` (en-US)](https://developer.mozilla.org/en-US/docs/Web/API/HTMLElement/style)属性来实现。这个属性包含了文档中每个元素的内联样式信息。你可以设置这个对象的属性直接修改元素样式。

**注意**: CSS样式的JavaSript属性版本以小驼峰式命名法书写，而CSS版本带连接符号（`backgroundColor`对 `background-color`）。确保你不会混淆，否则就不能工作。

另一个操作文档样式的常用方法

1. 删除之前添加到JavaScript中的五行代码。

2. 在HTML的

   `<head>`

   中添加下列代码 :

   ```
   <style>
   .highlight {
     color: white;
     background-color: black;
     padding: 10px;
     width: 250px;
     text-align: center;
   }
   </style>
   ```

3. 现在我们改为使用HTML操作的常用方法 —

    

   `Element.setAttribute()`

    

   — 这里有两个参数，你想在元素上设置的属性，你要为它设置的值。在这种情况下，我们在段落中设置类名为highlight：

   ```
   para.setAttribute('class', 'highlight');
   ```

   Copy to Clipboard

4. 刷新页面，看不到改变 — CSS仍然应用到段落，但是这次给出CSS规则选择的类不是内联CSS样式。

两种方式各有优缺点，选择哪种取决于你自己。第一种方式无需安装，适合简单应用，第二种方式更加正统（没有CSS和JavaScript的混合，没有内联样式，而这些被认为是不好的体验）。当你开始构建更大更具吸引力的应用时，你可能会更多地使用第二种方法，但这完全取决于你自己。



###### 从Window对象中获取有用的信息



##### 从服务器获取数据

在现代网站和应用中另一个常见的任务是从服务端获取个别数据来更新部分网页而不用加载整个页面。 这看起来是小细节却对网站性能和行为产生巨大的影响。

![A basic representation of a web site architecture](https://mdn.mozillademos.org/files/6475/web-site-architechture@2x.png)

这个模型的问题是当你想更新网页的任何部分，例如显示一套新的产品或者加载一个新的页面，你需要再一次加载整个页面。这是非常浪费的并且导致了差的用户体验尤其是现在的页面越来越大且越来越复杂。

###### Ajax开始

这导致了创建允许网页请求小块数据（例如 [HTML](https://developer.mozilla.org/en-US/docs/Web/HTML), [XML](https://developer.mozilla.org/zh-CN/docs/Glossary/XML), [JSON](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects/JSON), 或纯文本) 和 仅在需要时显示它们的技术，从而帮助解决上述问题。

这是通过使用诸如 [`XMLHttpRequest`](https://developer.mozilla.org/zh-CN/docs/Web/API/XMLHttpRequest) 之类的API或者 — 最近以来的 [Fetch API](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API) 来实现. 这些技术允许网页直接处理对服务器上可用的特定资源的 [HTTP](https://developer.mozilla.org/en-US/docs/Web/HTTP) 请求，并在显示之前根据需要对结果数据进行格式化。

![A simple modern architecture for web sites](https://mdn.mozillademos.org/files/6477/moderne-web-site-architechture@2x.png)

Ajax模型包括使用Web API作为代理来更智能地请求数据，而不仅仅是让浏览器重新加载整个页面。

- 页面更新速度更快，您不必等待页面刷新，这意味着该网站体验感觉更快，响应更快。
- 每次更新都会下载更少的数据，这意味着更少地浪费带宽。在宽带连接的桌面上这可能不是一个大问题，但是在移动设备和发展中国家没有无处不在的快速互联网服务是一个大问题。

为了进一步提高速度，有些网站还会在首次请求时将资产和数据存储在用户的计算机上，这意味着在后续访问中，他们将使用本地版本，而不是在首次加载页面时下载新副本。 内容仅在更新后从服务器重新加载。

###### 基本的AJAX请求

XMLHttpRequest

```
let request = new XMLHttpRequest();
request.open('GET', url);
request.responseType = 'text';

request.onload = function() {
  poemDisplay.textContent = request.response;
};

request.send();
```

Fetch

```
fetch(url).then(function(response) {
  response.text().then(function(text) {
    poemDisplay.textContent = text;
  });
});
```



##### 绘图

浏览器包含一些非常强大的图形编程工具，从可缩放矢量图形（Scalable Vector Graphics，简称 [SVG](https://developer.mozilla.org/zh-CN/docs/Web/SVG)）语言到用于在 HTML [``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/canvas) 元素上绘制图形的API。

开始使用<canvas>

要在网页中创建 2D 或者 3D 场景，必须在 HTML 文件中插入一个 [``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/canvas) 元素，以界定网页中的绘图区域。

```
<canvas width="320" height="240"></canvas>
```

获取画布上下文并完成设置

```
var ctx = canvas.getContext('2d');
```

一些通用的方法和属性将贯穿以下全部内容：

- [`beginPath()`](https://developer.mozilla.org/zh-CN/docs/Web/API/CanvasRenderingContext2D/beginPath)：在钢笔当前所在位置开始绘制一条路径。在新的画布中，钢笔起始位置为 (0, 0)。
- [`moveTo()`](https://developer.mozilla.org/zh-CN/docs/Web/API/CanvasRenderingContext2D/moveTo)：将钢笔移动至另一个坐标点，不记录、不留痕迹，只将钢笔“跳”至新位置。
- [`fill()`](https://developer.mozilla.org/zh-CN/docs/Web/API/CanvasRenderingContext2D/fill)：通过为当前所绘制路径的区域填充颜色来绘制一个新的填充形状。
- [`stroke()`](https://developer.mozilla.org/zh-CN/docs/Web/API/CanvasRenderingContext2D/stroke)：通过为当前绘制路径的区域描边，来绘制一个只有边框的形状。
- 路径也可和矩形一样使用 `lineWidth` 和 `fillStyle` / `strokeStyle` 等功能。



##### 视频和音频API

HTML5提供了用于在文档中嵌入富媒体的元素 — [``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/video)和[``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/audio)和[``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/audio)和[``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/audio) — 这些元素通过自带的API来控制视频或音频的播放，定位进度等。

###### HTMLMediaElement API

作为HTML5规范的一部分，[`HTMLMediaElement`](https://developer.mozilla.org/zh-CN/docs/Web/API/HTMLMediaElement) API提供允许你以编程方式来控制视频和音频播放的功能—例如 [`HTMLMediaElement.play()`](https://developer.mozilla.org/zh-CN/docs/Web/API/HTMLMediaElement/play), [`HTMLMediaElement.pause()`](https://developer.mozilla.org/zh-CN/docs/Web/API/HTMLMediaElement/pause),等。该接口对[``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/audio)和[``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/video)和[``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/video)和[``](https://developer.mozilla.org/zh-CN/docs/Web/HTML/Element/video)两个元素都是可用的，因为在这两个元素中要实现的功能几乎是相同的。让我们通过一个例子来一步步演示一些功能。



##### 客户端存储

现代web浏览器提供了很多在用户电脑web客户端存放数据的方法 — 只要用户的允许 — 可以在它需要的时候被重新获得。这样能让你存留的数据长时间保存, 保存站点和文档在离线情况下使用, 保留你对其站点的个性化配置等等。

通常客户端和服务端存储是结合在一起使用的。例如，你可以从数据库中下载一个由网络游戏或音乐播放器应用程序使用的音乐文件，将它们存储在客户端数据库中，并按需要播放它们。用户只需下载音乐文件一次——在随后的访问中，它们将从数据库中检索。

**注意：**使用客户端存储 API 可以存储的数据量是有限的（可能是每个API单独的和累积的总量）;具体的数量限制取决于浏览器，也可能基于用户设置。

传统方法：cookies

cookie的唯一优势是它们得到了非常旧的浏览器的支持

###### 新流派：web storage 和IndexedDB

- [Web Storage API](https://developer.mozilla.org/en-US/docs/Web/API/Web_Storage_API) 提供了一种非常简单的语法，用于存储和检索较小的、由名称和相应值组成的数据项。当您只需要存储一些简单的数据时，比如用户的名字，用户是否登录，屏幕背景使用了什么颜色等等，这是非常有用的。
- [IndexedDB API](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API) 为浏览器提供了一个完整的数据库系统来存储复杂的数据。这可以用于存储从完整的用户记录到甚至是复杂的数据类型，如音频或视频文件。

###### 未来：Cache API

一些现代浏览器支持新的 [`Cache`](https://developer.mozilla.org/zh-CN/docs/Web/API/Cache) API。这个API是为存储特定HTTP请求的响应文件而设计的，它对于像存储离线网站文件这样的事情非常有用，这样网站就可以在没有网络连接的情况下使用。缓存通常与 [Service Worker API](https://developer.mozilla.org/en-US/docs/Web/API/Service_Worker_API) 组合使用，尽管不一定非要这么做。

###### 存储简单数据-web storage

[Web Storage API](https://developer.mozilla.org/en-US/docs/Web/API/Web_Storage_API) 非常容易使用 — 你只需存储简单的 键名/键值 对数据 (限制为字符串、数字等类型) 并在需要的时候检索其值。

你所有的 web storage 数据都包含在浏览器内两个类似于对象的结构中： [`sessionStorage`](https://developer.mozilla.org/zh-CN/docs/Web/API/Window/sessionStorage) 和 [`localStorage`](https://developer.mozilla.org/zh-CN/docs/Web/API/Window/localStorage)。 第一种方法，只要浏览器开着，数据就会一直保存 (关闭浏览器时数据会丢失) ，而第二种会一直保存数据，甚至到浏览器关闭又开启后也是这样。

[`Storage.setItem()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Storage/setItem) 方法允许您在存储中保存一个数据项——它接受两个参数：数据项的名字及其值。

[`Storage.getItem()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Storage/getItem) 方法接受一个参数——你想要检索的数据项的名称——并返回数据项的值。

[`Storage.removeItem()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Storage/removeItem) 方法接受一个参数——你想要删除的数据项的名称——并从 web storage 中删除该数据项。

###### 为每个域名分离储存



###### 存储复杂数据--IndexedDB

[IndexedDB API](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API)（有时简称 IDB ）是可以在浏览器中访问的一个完整的数据库系统，在这里，你可以存储复杂的关系数据。

但是，这确实是有代价的：使用IndexedDB要比Web Storage API复杂得多。



```
// Create an instance of a db object for us to store the open database in
let db;
```

```
window.onload = function() {
// Open our database; it is created if it doesn't already exist
// (see onupgradeneeded below)
	let request = window.indexedDB.open('notes', 1);
// onerror handler signifies that the database didn't open successfully
    request.onerror = function() {
      console.log('Database failed to open');
    };
// onsuccess handler signifies that the database opened successfully
    request.onsuccess = function() {
    console.log('Database opened successfully');
// Store the opened database object in the db variable. This is used a lot below
    db = request.result;
// Run the displayData() function to display the notes already in the IDB
    displayData();
    };
    
    // Setup the database tables if this has not already been done
request.onupgradeneeded = function(e) {
  // Grab a reference to the opened database
  let db = e.target.result;

  // Create an objectStore to store our notes in (basically like a single table)
  // including a auto-incrementing key
  let objectStore = db.createObjectStore('notes', { keyPath: 'id', autoIncrement:true });

  // Define what data items the objectStore will contain
  objectStore.createIndex('title', 'title', { unique: false });
  objectStore.createIndex('body', 'body', { unique: false });

  console.log('Database setup complete');
};
	

};
```



##### 离线文件存储

每次访问网站时仍然需要下载主要的HTML，CSS和JavaScript文件，这意味着当没有网络连接时，它将无法工作。

# Service Worker

服务工作者是一个JavaScript文件，简单地说，它是在浏览器访问时针对特定来源（网站或某个域的网站的一部分）进行注册的。注册后，它可以控制该来源的可用页面。它通过坐在加载的页面和网络之间以及拦截针对该来源的网络请求来实现这一点。

当它拦截一个请求时，它可以做任何你想做的事情（参见[用例思路](https://developer.mozilla.org/en-US/docs/Web/API/Service_Worker_API#Other_use_case_ideas)），但经典的例子是离线保存网络响应，然后提供响应请求而不是来自网络的响应。实际上，它允许您使网站完全脱机工作。

Cache API是另一种客户端存储机制，略有不同 - 它旨在保存HTTP响应，因此与服务工作者一起工作得非常好。

###### 一个service worker例子

###### 注册服务工作者

首先要注意的是，在主JavaScript文件中放置了一些额外的代码（请参阅[index.js](https://github.com/mdn/learning-area/blob/master/javascript/apis/client-side-storage/cache-sw/video-store-offline/index.js)）。首先，我们进行特征检测测试，以查看`serviceWorker`该[`Navigator`](https://developer.mozilla.org/zh-CN/docs/Web/API/Navigator)对象中是否有该成员。如果返回true，那么我们知道至少支持服务工作者的基础知识。在这里，我们使用该[`ServiceWorkerContainer.register()`](https://developer.mozilla.org/zh-CN/docs/Web/API/ServiceWorkerContainer/register)方法将`sw.js`文件中包含的服务工作者注册到它所驻留的源，因此它可以控制与它或子目录相同的目录中的页面。当其承诺履行时，服务人员被视为已注册。

```
  // Register service worker to control making site work offline

  if('serviceWorker' in navigator) {
    navigator.serviceWorker
             .register('/learning-area/javascript/apis/client-side-storage/cache-sw/video-store-offline/sw.js')
             .then(function() { console.log('Service Worker Registered'); });
  }
```

###### 安装service worker

下次访问服务工作者控制下的任何页面时（例如，重新加载示例时），将针对该页面安装服务工作者，这意味着它将开始控制它。发生这种情况时，`install`会向服务工作人员发起一个事件; 您可以在服务工作者本身内编写代码来响应安装。

您将看到安装侦听器已注册`self`。此`self`关键字是一种从服务工作文件内部引用服务工作者的全局范围的方法。

在`install` 处理程序内部， 我们使用[`ExtendableEvent.waitUntil()`](https://developer.mozilla.org/zh-CN/docs/Web/API/ExtendableEvent/waitUntil)事件对象上可用的方法来表示浏览器不应该完成服务工作者的安装，直到其中的promise成功完成。

我们使用该[`CacheStorage.open()`](https://developer.mozilla.org/zh-CN/docs/Web/API/CacheStorage/open)方法打开一个可以存储响应的新缓存对象（类似于IndexedDB对象存储）。此承诺通过[`Cache`](https://developer.mozilla.org/zh-CN/docs/Web/API/Cache)表示`video-store`缓存的对象来实现。然后，我们使用该[`Cache.addAll()`](https://developer.mozilla.org/zh-CN/docs/Web/API/Cache/addAll)方法获取一系列资产并将其响应添加到缓存中。

```
self.addEventListener('install', function(e) {
 e.waitUntil(
   caches.open('video-store').then(function(cache) {
     return cache.addAll([
       '/learning-area/javascript/apis/client-side-storage/cache-sw/video-store-offline/',
       '/learning-area/javascript/apis/client-side-storage/cache-sw/video-store-offline/index.html',
       '/learning-area/javascript/apis/client-side-storage/cache-sw/video-store-offline/index.js',
       '/learning-area/javascript/apis/client-side-storage/cache-sw/video-store-offline/style.css'
     ]);
   })
 );
});
```

###### 响应未来的请求

在我们的HTML页面上注册并安装了服务工作者，并且所有相关资产都添加到我们的缓存中，我们几乎准备好了。还有一件事要做，写一些代码来响应进一步的网络请求。

我们向服务工作者全局范围添加另一个侦听器，该范围在`fetch`引发事件时运行处理函数。只要浏览器在服务工作者注册的目录中请求资产，就会发生这种情况。

在处理程序内部，我们首先记录所请求资产的URL。然后，我们使用该[`FetchEvent.respondWith()`](https://developer.mozilla.org/zh-CN/docs/Web/API/FetchEvent/respondWith)方法为请求提供自定义响应。

在这个块中，我们[`CacheStorage.match()`](https://developer.mozilla.org/zh-CN/docs/Web/API/CacheStorage/match)用来检查是否可以在任何缓存中找到匹配的请求（即匹配URL）。如果未找到匹配，或者`undefined`如果未找到匹配，则此承诺将满足匹配的响应。

如果找到匹配项，我们只需将其作为自定义响应返回。如果没有，我们从网络中[获取（）](https://developer.mozilla.org/en-US/docs/Web/API/WindowOrWorkerGlobalScope/fetch)响应并返回该响应。

```
self.addEventListener('fetch', function(e) {
  console.log(e.request.url);
  e.respondWith(
    caches.match(e.request).then(function(response) {
      return response || fetch(e.request);
    })
  );
});
```



##### 查找并解决JavaScript代码的错误

###### 错误类型

一般来说，代码错误主要分为两种：

- **语法错误**：代码中存在拼写错误，将导致程序完全或部分不能运行，通常你会收到一些出错信息。只要熟悉语言并了解出错信息的含义，你就能够顺利修复它们。
- **逻辑错误**：有些代码语法虽正确，但执行结果和预期相悖，这里便存在着逻辑错误。这意味着程序虽能运行，但会给出错误的结果。由于一般你不会收到来自这些错误的提示，它们通常比语法错误更难修复。

###### 开发工具JavaScript控制台



#### 可访问性

如果你想成为一个web开发者，学习一些HTML,CSS和JavaScript是很有用的, 但是仅仅使用这些技术是不够的, 你应该更进一步拓展你的知识 — 你需要响应式地使用它们来最大程度地发展你的用户, 并且使用这些技术时不能把任何一门排斥出去。 为了达到这个目的, 要遵循一般最佳实践（这些最佳实践已经被 [HTML](https://developer.mozilla.org/en-US/docs/Learn/HTML), [CSS](https://developer.mozilla.org/en-US/docs/Learn/CSS), 和 [JavaScript](https://developer.mozilla.org/en-US/docs/Learn/JavaScript) 相关的话题所证明）,进行跨浏览器测试, 并且从项目最初阶段就把易使用性考虑在内。在这个模块中我们将会详细讨论后者。

可访问性是一种让尽可能多的用户可以使用你的网站的做法。传统上我们认为这只与残疾人士有关，但提升网站的可访问性也可以让其他用户群体受益。比如使用移动设备的人群，那些使用低速网络连接的人群。

，W3C发布了一个庞大而详细的文档，其中包含了非常精确的、与技术无关的可访问性一致性标准。这些被称为Web内容可访问性指南(WCAG)，它们绝不是短读的。这些标准分为四大类，它们指定如何使实现具有可感知性、可操作性、可理解性和鲁棒性。



##### 服务器端网页编程

大多数的主流网页使用一类服务器端的技术去动态地显示所要求的不同数据。

开始服务器端编程通常比客户端编程要简单，因为动态的页面倾向于执行非常类似的操作（从数据库中获取数据然后显示到一个页面中，确认用户输入的数据以及保存到一个数据库中，检查用户的权限和登陆用户，以及更多），并且它是用能使这些和其他的常见网页服务端操作变简单的网页框架来构建的。



##### 服务器网站编程的第一步

##### 服务端编程介绍

大多数的大型网站采用服务器端编程来在需要的时候动态展示不同的信息，这些信息通常会从服务器上的数据库中取出，然后发送给客户端，并通过一些代码（比如HTML和Javascript）展示在客户端。

或许服务器端编程的最大益处在于它允许你对不同的用户个体展示不同的网站信息。

它允许在页面中与用户进行交互，比如通过邮件或者其他渠道发送通知和更新信息。服务器端的所有的这些能力使得网站可以与用户有更深的联系。

##### 服务器端编程是什么？

网络浏览器通过**超文本传输协议** ([HTTP](https://developer.mozilla.org/zh-CN/docs/Glossary/HTTP))来和[网络服务器](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/What_is_a_web_server) 进行通信。当你在网页上点击一个链接，或提交一个表单，再或进行一次搜索时，一个**HTTP请求**就从你的浏览器发送到了目标服务器。

这个请求包括一个标识所请求资源的URL，一个定义所需操作的方法(比如获取，删除或者发布资源)，还可以包括编码在URL参数中的附加信息。附加信息以键值对（参数和它的值）的形式，通过一个[查询字符串](https://en.wikipedia.org/wiki/Query_string)，作为POST数据（由[HTTP POST方法](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Methods/POST)发送）或存放在与之相关联的[Cookie](https://developer.mozilla.org/zh-CN/docs/Glossary/Cookie)中。

网络服务器等待客户端的请求信息，在它们到达的时候处理它们，并且回复网络浏览器一个**HTTP响应**信息。这个响应包含一个表明该请求是否成功的状态行（比如“HTTP/1.1 200 OK”代表请求成功）。

相应一个请求的成功回应包含被请求的资源（比如一个新的HTML页面，或者图片等），然后这些会被展示在客户端的网络浏览器上。

静态网站是指无论何时当一个特定资源被请求的时候都返回相同的被硬编码的内容）

动态网站是指，一些响应内容只有在被需要的时候才会生发的网站。在一个动态网站上，页面通常是通过将数据库的数据植入到HTML模板中的占位符中而产生的（这是一种比使用静态网站有效得多的存储大量内容的方式）。

动态网站可以基于用户提供的个人信息或者偏好设置来返回不同的数据，并且可以展示作为返回一个回应的内容的一部分的其他操作（比如发送通知）。

大多数支持动态网站的代码必须运行在服务器上。编写这些代码就是所谓的“**服务器端编程**”（有些时候也称“后端脚本编写”）。

动态网站对于静态资源的请求的处理方式和静态网站是一样的（静态资源是指那些不会改变的文件——最典型的就是：CSS，Javascript，图片，预先生成的PDF文件等）。

对于动态资源的请求则会指向（2）服务器端代码(在图中显示为*Web Application*（网络应用））。在处理“动态请求”时，服务器会首先解释请求，从数据库中读取被请求的信息，然后将这些被检索的信息组合到HTML模板中（4）,最后返回一个包含所生成的HTML页面的回应（5,6）。

在浏览器端运行的代码被称为**客户端代码**，并且主要涉及所呈现的网页的外观和行为的改进。这就包括选择和设计UI元素、布局、导航、表单验证等。相反的，服务器端网站编程主要涉及，对于相应的请求，选择所要返回给浏览器的内容。服务器端代码解决这样一些问题，比如验证提交的数据和请求、使用数据库来存储和检索信息及发送给用户正如他们所请求的的正确内容。



##### 客户端服务端交互概述

##### 网络服务器和HTTP（入门）

网络浏览器通过超文本标记语言传输协议（[HTTP](https://developer.mozilla.org/en-US/docs/Web/HTTP)）与网络服务器（[web servers](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_web_server)）。 当你在网页上点击一个链接、提交一个表单、或者进行一次搜索的时候，浏览器发送一个HTTP请求给服务器。

### [GET请求/响应举例](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Client-Server_overview#get请求响应举例)

### [POST 请求/响应举例](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Client-Server_overview#post_请求响应举例)

## [web框架简化服务器端的web编程](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Client-Server_overview#web框架简化服务器端的web编程)

服务器端web框架使得编写解决我们上面描述的操作的代码变得简单得多。

web 框架可以提供的一个最重要的功能就是，提供简单的机制，以将不同的资源和页面定位到具体的处理函数。这使得保持代码和各个不同形式的资源的联系变得简单。它也非常利于代码的维护，因为你可以直接改变在一个地方用来传输特定功能的URL，而不用改变处理函数。

Web 框架还可以轻松地使用查看函数，从数据库获取信息。我们的数据结构是在模型中定义的，模型是定义要存储在底层数据库中的字段的Python类。如果我们有一个名为Team的模型，其中有一个“*team_type*”字段，那么我们可以使用一个简单的查询语法来取回所有具有特定类型的球队。

### [直接处理 HTTP 请求和响应](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Web_frameworks#直接处理_http_请求和响应)

web服务器和浏览器通过HTTP协议进行通信——服务器等待来自浏览器的HTTP请求然后在HTTP回应中返回相关信息。web框架允许你编写简单语法的代码，即可生成处理这些请求和回应的代码。这意味着你的工作变得简单、交互变得简单、并且使用抽象程度高的代码而不是底层代码。

### [将请求路由到相关的handler中](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Web_frameworks#将请求路由到相关的handler中)

大多数的站点会提供一系列不同资源，通过特定的URL来访问。如果都放在一个函数里面，网站会变得很难维护。所以web框架提供一个简单机制来匹配URL和特定处理函数。这种方式对网站维护也有好处，因为你只需要改变用来传输特定功能的URL而不用改变任何底层代码。

### [使从请求中获得数据变得简单](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Web_frameworks#使从请求中获得数据变得简单)

### [抽象和简化数据库接口](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Web_frameworks#抽象和简化数据库接口)

web框架通常会提供一个数据库层来抽象数据库的读、写、查询和删除操作。这一个抽象层被称作对象关系映射器（ORM）。

### [渲染数据](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Web_frameworks#渲染数据)

web框架经常提供模板系统。这些允许你制定输出文档的结构，使用为那些数据准备的将在页面生成时添加进去的占位符。模板经常是用来生成HTML的，但是也可以用来生成一些其他的文档。

框架提供一个机制，使得从存储的数据中生成其他格式数据变得简单，包括[JSON](https://developer.mozilla.org/zh-CN/docs/Glossary/JSON)和[XML](https://developer.mozilla.org/zh-CN/docs/Glossary/XML)。



##### 站点安全

站点安全需要在网站设计和使用的各个方面保持警惕。

站点安全的目的就是为了防范这些（或者说所有）形式的攻击。更正式点说，站点安全就是为保护站点不受未授权的访问、使用、修改和破坏而采取的行为或实践。

## [站点安全威胁](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Website_security#站点安全威胁)

### [跨站脚本 (XSS)](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Website_security#跨站脚本_xss)

XSS是一个术语，用来描述一类允许攻击者通过网站将客户端脚本代码注入到其他用户的浏览器中的攻击手段。由于注入到浏览器的代码来自站点，其是可信赖的，因此可以做类似将该用户用于站点认证的cookie发送给攻击者的事情。一旦攻击者拿到了这个cookie，他们就可以登陆到站点，就好像他们就是那个用户，可以做任何那个用户能做的事情。根据站点的不同，这些可能包括访问他们的信用卡信息、查看联系人、更改密码等。

### [SQL 注入](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Website_security#sql_注入)

SQL 注入漏洞使得恶意用户能够通过在数据库上执行任意SQL代码，从而允许访问、修改或删除数据，而不管该用户的权限如何。成功的注入攻击可能会伪造身份信息、创建拥有管理员权限的身份、访问服务器上的任意数据甚至破坏/修改数据使其变得无法使用。

### [跨站请求伪造 (CSRF)](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/First_steps/Website_security#跨站请求伪造_csrf)

CSRF 攻击允许恶意用户在另一个用户不知情的情况下利用其身份信息执行操作。

这种形式的攻击用实例来解释最好。John是一个恶意用户，他知道某个网站允许已登陆用户使用包含了账户名和数额的HTTP `POST`请求来转帐给指定的账户。John 构造了包含他的银行卡信息和某个数额做为隐藏表单项的表单，然后通过Email发送给了其它的站点用户（还有一个伪装成到 “快速致富”网站的链接的提交按钮）.

如果某个用户点击了提交按钮，一个 HTTP `POST` 请求就会发送给服务器，该请求中包含了交易信息以及浏览器中与该站点关联的所有客户端cookie（将相关联的站点cookie信息附加发送是正常的浏览器行为) 。服务器会检查这些cookie，以判断对应的用户是否已登陆且有权限进行上述交易。

最终的结果就是任何已登陆到站点的用户在点击了提交按钮后都会进行这个交易。



# Express Web Framework (Node.js/JavaScript)

## [什么是 Node?](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#什么是_node)

[Node](https://nodejs.org/zh-cn/)（正式名称 Node.js）是一个开源的、跨平台的运行时环境，有了它，开发人员可以使用 [JavaScript](https://developer.mozilla.org/zh-CN/docs/Glossary/JavaScript)创建各种服务器端工具和应用程序。

该环境省略了一些浏览器专用的 JavaScript API，同时添加了对更传统的 OS API（比如 HTTP 库和文件系统库）的支持。



## [Web 框架](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#web_框架)

Node 本身并不支持其它常见的 web 开发任务。如果需要进行一些具体的处理，比如运行其它 HTTP 动词（比如 `GET`、`POST`、`DELETE` 等）、分别处理不同 URL 路径的请求（“路由”）、托管静态文件，或用模板来动态创建响应，那么可能就要自己编写代码了，亦或使用 web 框架，以避免重新发明轮子。

## [什么是 Express?](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#什么是_express)

[Express](http://www.expressjs.com.cn/) 是最流行的 Node 框架，是许多其它流行 [Node 框架](http://www.expressjs.com.cn/resources/frameworks.html) 的底层库。它提供了以下机制：

- 为不同 URL 路径中使用不同 HTTP 动词的请求（路由）编写处理程序。
- 集成了“视图”渲染引擎，以便通过将数据插入模板来生成响应。
- 设置常见 web 应用设置，比如用于连接的端口，以及渲染响应模板的位置。
- 在请求处理管道的任何位置添加额外的请求处理“中间件”。

虽然 Express 本身是极简风格的，但是开发人员通过创建各类兼容的中间件包解决了几乎所有的 web 开发问题。这些库可以实现 cookie、会话、用户登录、URL 参数、`POST` 数据、安全头等功能。可在 [Express 中间件](http://www.expressjs.com.cn/resources/middleware.html) 网页中找到由 Express 团队维护的中间件软件包列表（还有一张流行的第三方软件包列表）。



```
const express = require('express');
const app = express();

app.get('/', (req, res) => {
  res.send('Hello World!');
});

app.listen(3000, () => {
  console.log('示例应用正在监听 3000 端口!');
});
```

传统上把这个对象命名为 `app`，它可以进行路由 HTTP 请求、配置中间件、渲染 HTML 视图、注册模板引擎以及修改 [应用程序设置](http://www.expressjs.com.cn/4x/api.html#app.settings.table) 等操作，从而控制应用的行为（例如，环境模式，路由定义是否为区分大小写等）

### [导入和创建模块](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#导入和创建模块)

模块是 JavaScript 库或文件，可以用 Node 的 `require()` 函数将它们导入其它代码。Express 本身就是一个模块，Express 应用中使用的中间件和数据库也是。

还可以创建自定义模块，并用相同的方法导入。

**提示：**你一定会有自建模块的**需求**，因为这可以让代码管理更有序。单文件应用是很难理解和维护的。使用模块还有助于管理名字空间，因为在使用模块时只会导入模块中显式导出的变量。

为了让对象暴露于模块之外，只需把它们设置为 `exports` 对象的附加属性即可。例如，下面的 **square.js** 模块就是一个导出了 `area()` 和 `perimeter()` 方法的文件：

```
exports.area = width => { return width * width; };
exports.perimeter = width => { return 4 * width; };
```

Copy to Clipboard

可以用 `require()` 导入这个模块，然后调用导出的方法，用法如下：

```
const square = require('./square');
// 这里 require() 了文件名，省略了 .js 扩展名（可选）
console.log('边长为 4 的正方形面积为 ' + square.area(4));
```

Copy to Clipboard

**注：**为模块指定绝对路径（或模块的名字，见最初的示例）也是可行的。

一次赋值不仅能构建一个单一的属性，还能构建一个完整的对象，可以像下面这样把对象赋值给 `module.exports`（也可以让 `exports` 对象直接作为一个构造器或另一个函数）：

```
module.exports = {
  area: width => { return width * width; },
  perimeter: width => { return 4 * width; }
};
```

**注：**在一个既定的模块内，可以把 `exports` 想象成 `module.exports` 的 [快捷方式](http://nodejs.cn/api/modules.html#modules_exports_shortcut)。`exports` 本质上就是在模块初始化前为 `module.exports` 的值进行初始化的一个变量。这个值是对一个对象（这里是空对象）的引用。这意味着 `exports` 与 `module.exports` 引用了同一个对象，也意味着如果为 `exports` 赋其它值不会影响到 `module.exports`。

### [使用异步 APIs](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#使用异步_apis)

在 Node 中使用无阻塞异步 API 甚至比在浏览器中更为重要，这是因为 Node 是一个单线程事件驱动的执行环境。“单线程”意味着对服务器的所有请求运行在同一个线程上，而不是分布在不同的进程上。这个模式在速度和管理服务器资源方面效率很高，但也意味着如果以同步方式调用的函数占用了很长时间，不仅会阻塞当前请求，还会阻塞当前 web 应用其它所有请求。

有多种方法可以让一个异步 API 通知当前应用它已执行完毕。最常用的是在调用异步 API 时注册一个回调函数，在 API 操作结束后将“回调”之。这也是上面的代码所使用的方法。

### [创建路由处理器（Route handler）](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#创建路由处理器（route_handler）)

```
app.get('/', (req, res) => {
  res.send('Hello World!');
});
```

定义了一个（回调）路由处理函数来处理对站点根目录（`'/'`）的 HTTP `GET` 请求。

该函数直接调用响应的 send() 以返回字符串“Hello World!”。有 许多其它响应方法 可以结束请求/响应周期，例如，通过调用 res.json() 来发送JSON 响应、调用 res.sendFile() 来发送文件。

**Express 应用** 对象还提供了为其它所有 HTTP 动词定义路由处理器的方法，大多数处理器的使用方式完全一致：

`checkout()`, `copy()`, **`delete()`**, **`get()`**, `head()`, `lock()`, `merge()`, `mkactivity()`, `mkcol()`, `move()`, `m-search()`, `notify()`, `options()`, `patch()`, **`post()`**, `purge()`, **`put()`**, `report()`, `search()`, `subscribe()`, `trace()`, `unlock()`, `unsubscribe()`.

有一个特殊的路由方法 `app.all()`，它可以在响应任意 HTTP 方法时调用。用于在特定路径上为所有请求方法加载中间件函数。

路由器可以匹配 URL 中特定的字符串模式，并从 URL 中提取一些值作为参数传递给路由处理程序（作为请求对象的属性）。

可以为站点的特定部分提供一组路由处理器（使用公共路由前缀进行组合）。（比如对于一个有 维基（Wiki）内容的站点，可以把所有 Wiki 相关的路由放在同一个文件里，使用路由前缀 *`'/wiki/'`* 访问它们）。在 Express 中可以使用 [express.Router](http://www.expressjs.com.cn/guide/routing.html#express.Router) 对象实现。例如，可以把所有维基相关的路由都放在一个 **wiki.js** 模块中，然后导出 `Router` 对象，如下：

```
// wiki.js - 维基路由模块

const express = require('express');
const router = express.Router();

// 首页路由
router.get('/', (req, res) => {
  res.send('维基首页');
});

// “关于”页面路由
router.get('/about', (req, res) => {
  res.send('关于此维基');
});

module.exports = router;
```

**注意：**向 `Router` 对象添加路由就像向之前为 `app` 对象添加路由一样。



首先 `require()` 路由模块（**wiki.js**），然后在 Express 应用中调用 `use()` 把 `Router` 添加到中间件处理路径中，就可以在主应用中使用这个模块中的路由处理器了。路由路径有两条：`/wiki` 和 `/wiki/about/`。

```
const wiki = require('./wiki.js');
// ...
app.use('/wiki', wiki);
```

### [使用中间件（Middleware）](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#使用中间件（middleware）)

中间件在 Express 应用中得到了广泛使用，从提供错误处理静态文件、到压缩 HTTP 响应等等。路由函数可以通过向 HTTP 客户端返回一些响应来结束 HTTP “请求 - 响应”周期，而中间件函数*通常是*对请求或响应执行某些操作，然后调用“栈”里的下一个函数，可能是其它中间件或路由处理器。中间件的调用顺序由应用开发者决定。

**注：**中间件可以执行任何操作，运行任何代码，更改请求和响应对象，也可以**结束“请求 - 响应”周期**。如果它没有结束循环，则必须调用 `next()` 将控制传递给下一个中间件函数（否则请求将成为悬挂请求）。

大多数应用会使用**第三方**中间件来简化常见的 web 开发任务，比如 cookie、会话、用户身份验证、访问请求 `POST` 和 JSON 数据，日志记录等。参见 [Express 团队维护的中间件包列表](http://www.expressjs.com.cn/resources/middleware.html)（包含受欢迎的第三方包）。NPM 有提供其它 Express 包。

可以对 *Express 应用对象*调用 `use()` 将该中间件添加到栈；

中间件和路由函数是按声明顺序调用的。一些中间件的引入顺序很重要（例如，如果会话中间件依赖于 cookie 中间件，则必须先添加 cookie 处理器）。绝大多数情况下要先调用中间件后设置路由，否则路由处理器将无法访问中间件的功能。

可以自己编写中间件函数，这是基本技能（仅仅为了创建错误处理代码也需要）。中间件函数和路由处理回调之间的**唯一**区别是：中间件函数有第三个参数 `next`，在中间件不会结束请求周期时应调用这个 `next`（它包含中间件函数调用后应调用的**下一个**函数）。

可以使用 `app.use()` 或 `app.add()` 将一个中间件函数添加至处理链中，这取决于中间件是应用于所有响应的，还是应用于特定 HTTP 动词（`GET`，`POST`等）响应的。可以为两种情况指定相同的路由，但在调用 `app.use()` 时路由可以省略。

下面的示例显示了如何使用这两种方法添加中间件功能，以及是否使用路由。

```
const express = require('express');
const app = express();

// 示例中间件函数
const a_middleware_function = (req, res, next) => {
  // ... 进行一些操作
  next(); // 调用 next() ，Express 将调用处理链中下一个中间件函数。
};

// 用 use() 为所有的路由和动词添加该函数
app.use(a_middleware_function);

// 用 use() 为一个特定的路由添加该函数
app.use('/someroute', a_middleware_function);

// 为一个特定的 HTTP 动词和路由添加该函数
app.get('/', a_middleware_function);

app.listen(3000);
```

**JavaScript提示：**上面代码中单独声明了中间件函数，并把它设置为回调。之前是把路由处理函数在使用时声明为回调。在 JavaScript 中，两种方法都可行。



### [托管静态文件](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#托管静态文件)

可以使用 [express.static](http://www.expressjs.com.cn/4x/api.html#express.static) 中间件来托管静态文件，包括图片、CSS 以及 JavaScript 文件（其实 `static()` 是 Express 提供的**原生**中间件函数之一）。

例如，可以通过下面一行来托管 'public' 文件夹（应位于 Node 调用的同一级）中的文件：

```
app.use(express.static('public'));
```

Copy to Clipboard

现在 'public' 文件夹下的所有文件均可通过在根 URL 后直接添加文件名来访问了，比如：

```
http://localhost:3000/images/dog.jpg
http://localhost:3000/css/style.css
http://localhost:3000/js/app.js
http://localhost:3000/about.html
```

可以通过多次调用 `static()` 来托管多个文件夹。如果一个中间件函数找不到某个文件，将直接传递给下一个中间件（中间件的调用顺序取决于声明顺序）。

```
app.use(express.static('public'));
app.use(express.static('media'));
```

还可以为静态 URL 创建一个虚拟的前缀，而不是直接把文件添加到根 URL 里。比如，这里 [指定了一个装载路径](http://www.expressjs.com.cn/4x/api.html#app.use)，于是这些文件将通过 '/media' 前缀调用：

```
app.use('/media', express.static('public'));
```

Copy to Clipboard

现在可以通过 '/media' 路径前缀来访问 'public' 文件夹中的文件。

```
http://localhost:3000/media/images/dog.jpg
http://localhost:3000/media/video/cat.mp4
http://localhost:3000/media/cry.mp3
```



### [错误处理](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#错误处理)

用来处理错误的特殊中间件函数有四个参数`(err, req, res, next)`，而不是之前的三个。例如：

```
app.use((err, req, res, next) => {
  console.error(err.stack);
  res.status(500).send('出错了！');
});
```

Copy to Clipboard

错误处理中间件可以任何所需内容，但是必须在所有其它 `app.use()` 和路由调用后才能调用，因此它们是需求处理过程中最后的中间件。

Express 内建了错误处理机制，可以协助处理 app 中没有被处理的错误。默认的错误处理中间件函数在中间件函数栈的末尾。如果一个错误传递给 `next()` 而没有用错误处理器来处理它，内建处理机制将启动，栈跟踪的错误将回写给客户端。

**注：** 生产环境中不保留栈跟踪轨迹。可将环境变量 `NODE_ENV` 设置为 `'production'` 来运行所需的生产环境。

**注：**HTTP404 和其它“错误”状态码不作为错误处理。可使用中间件来自行处理这些状态。

### [使用数据库](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#使用数据库)

*Express* 应用可以使用 Node 支持的所有数据库（Express 本身并没有定义任何数据库管理的附加行为或需求）。其中包括：PostgreSQL、MySQL、Redis、SQLite、MongoDB，等等。

使用数据库前先要用 NPM 来安装驱动程序。

数据库可以安装在本地或云端。在 Express 代码中 `require()` 驱动程序，连接，然后就可以执行增加、读取、更新、删除四种操作（CRUD）。

还有一种通过“对象关系映射（Object Relational Mapper，简称 ORM）”间接访问数据库的方法。可以把数据定义为“对象”或“模型”，然后由 ORM 根据给定的数据库格式搞定所有映射关系。这种方法对于开发者有一个好处：可以用 JavaScript 对象的思维而无需直接使用数据库语法，同时传进的数据也有现成的检查工具。

### [渲染数据（视图，view）](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#渲染数据（视图，view）)

模板引擎可为输出文档的结构指定一个模板，在数据处先放置占位符，并于页面生成时填充。模板通常用于生成 HTML，也可以生成其它类型的文档。Express 支持 [多个版本的模板引擎](https://github.com/expressjs/express/wiki#template-engines)。

在应用设置代码中声明了模板引擎的名称和位置后，Express 可以使用 `'views'` 和 `'view engines'` 设置来寻找模板

```
const express = require('express');
const app = express();

// 设置包含模板的文件夹（'views'）
app.set('views', path.join(__dirname, 'views'));

// 设置视图引擎，比如'some_template_engine_name'
app.set('view engine', 'some_template_engine_name');
```

Copy to Clipboard

模板的外观取决于所使用的引擎。假设一个模板文件名为 "index.<template_extension>"，其中包括数据变量 `'title'` 和 `'message'` 的两个占位符，可以在路由处理器函数中调用 `Response.render()` 来创建并发送 HTML 响应：

```
app.get('/', (req, res) => {
  res.render('index', { title: '关于狗狗', message: '狗狗很牛！' });
});
```

### [文件结构](https://developer.mozilla.org/zh-CN/docs/Learn/Server-side/Express_Nodejs/Introduction#文件结构)

Express 不对文件结构和组件的选用做任何约定。路由、视图、静态文件，以及其它应用具体逻辑均可按任意文件结构保存在任意数量的文件中。当然可以让整个 Express 应用保存在单一文件中，但是一般情况下，把应用按功能（比如账户管理、博客、论坛）和架构问题域（比如 [MVC 架构](https://developer.mozilla.org/zh-CN/docs/Web/Apps/Fundamentals/Modern_web_app_architecture/MVC_architecture) 中的模型、视图、控制器）进行拆分是有意义的。



#### 设置Node 开发环境

## [Express 开发环境概述](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/development_environment#express_开发环境概述)

### [什么是 Express 开发环境？](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/development_environment#什么是_express_开发环境？)

完整的 Express 本地开发环境包括 Nodejs、NPM 包管理器和 **Express 应用生成器**（可选）。

### [开发依赖（Development dependencies）](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/development_environment#开发依赖（development_dependencies）)

如果一个依赖只在开发过程中用到，应该将其保存为“开发依赖”（这样，包的用户便无需在生产环境中安装它们）。

比如，如果要使用 [eslint](http://eslint.org/)（一款流行的 JavaScript lint 工具）可以这样调用 NPM：

```
$ npm install eslint --save-dev
```

Copy to Clipboard

当前应用的 **package.json** 文件中将自动添加以下项目：

```
  "devDependencies": {
    "eslint": "^5.12.0"
  }
```

### [运行任务](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/development_environment#运行任务)

在 **package.json** 中，除了定义和获取依赖，还可以定义脚本，然后通过 NPM 的 [run-script](https://docs.npmjs.com/cli/run-script) 命令来运行。这个用法普遍用于自动运行测试单元或部分应用，也可用于构建工具链（比如运行工具来压缩 JavaScript 文件或图片，lint 或分析代码，等等）。

比如，可以在 **package.json** 文件中添加以下内容来定义一个脚本，从而对上文的代码运行 eslint（假设应用代码在 /src/js 文件夹下）：

```
"scripts": {
  ...
  "lint": "eslint src/js"
  ...
}
```

Copy to Clipboard

深入解释一下，eslint src/js 命令可以在终端/命令行对应用目录下的 src/js 目录中的 JavaScript 文件运行 eslint。把上面一段脚本添加进应用的 package.json 中还可以为此命令提供一个快捷方式—— lint。

然后就可以用 NPM 这样运行 eslint 了：

```
$ npm run-script lint
```

Copy to Clipboard

或使用别名：

```
$ npm run lint
```

## [安装 Express 应用生成器](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/development_environment#安装_express_应用生成器)

[Express 应用生成器](https://expressjs.com/en/starter/generator.html) 工具可以生成一个 Express 应用的“框架”。可以用 NPM 这样安装它（-g 参数可以把该工具全局安装，那样就可以在任意应用中使用了）：

```
$ npm install express-generator -g
```

Copy to Clipboard

进入应用目录，运行以下命令，即可创建一个名为 "helloworld" 的 Express 应用：

```
$ express helloworld
```



# Express 教程: 本地图书馆网站

本系列教程中，你将：

- 使用 *Express* 应用生成器创建一个应用骨架。
- 启动和停止 Node web 服务器。
- 使用数据库存放应用数据。
- 创建路由来处理不同信息的请求，创建模板（"视图"）来渲染 HTML 数据以在浏览器中显示。
- 使用表单。
- 部署应用到生产环境。



### [我应该用哪个视图引擎？](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/skeleton_website#我应该用哪个视图引擎？)

Express 应用生成器支持多款流行的视图/模板引擎，包括 [EJS](https://www.npmjs.com/package/ejs)、[Hbs](http://github.com/donpark/hbs)、[Pug](https://pugjs.org/api/getting-started.html) (Jade)、[Twig](https://www.npmjs.com/package/twig) 和 [Vash](https://www.npmjs.com/package/vash)，缺省选项是 Jade。Express 本身也支持大量其他模板语言，[开箱即用](https://github.com/expressjs/express/wiki#template-engines)。

### [我应该用哪个 CSS 引擎？](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/skeleton_website#我应该用哪个_css_引擎？)

Express 应用生成器支持最常见的 CSS 引擎：[LESS](https://lesscss.org/), [SASS](https://sass-lang.com/), [Compass](http://compass-style.org/), [Stylus](http://stylus-lang.com/)。

### [我应该用哪个数据库？](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/skeleton_website#我应该用哪个数据库？)

生成器生成的代码不使用、也不包含任何数据库。 Express 应用可以使用 Node 支持的所有 [数据库](https://expressjs.com/en/guide/database-integration.html)（Express 本身不提供数据库管理机制）。

## [文件改动时重启服务器](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/skeleton_website#文件改动时重启服务器)

只有重启服务器才能看到 Express 网站所做的改动。每次改动后手动启停服务器实在太烦人了，有必要花点时间让这项工作自动化。

[nodemon](https://github.com/remy/nodemon) 是最简便的自动化工具之一。通常将其全局安装（因为它是一个“工具”）：

在 `"start"` 一行的末尾添加逗号，并在新的一行中添加 `"devstart"`，如下所示：

```
  "scripts": {
    "start": "node ./bin/www",
    "devstart": "nodemon ./bin/www"
  },
```

### [目录结构](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/skeleton_website#目录结构)

安装好依赖项的生成项目具有如下文件结构（**不**带 “/” 前缀的是文件）：

```
/express-locallibrary-tutorial
    app.js
    /bin
        www
    package.json
    /node_modules
        [约 4,500 个子文件夹和文件]
    /public
        /images
        /javascripts
        /stylesheets
            style.css
    /routes
        index.js
        users.js
    /views
        error.pug
        index.pug
        layout.pug
```

**package.json** 文件定义依赖项和其他信息，以及一个调用应用入口（**/bin/www**，一个 JavaScript 文件）的启动脚本，脚本中还设置了一些应用的错误处理，加载 **app.js** 来完成其余工作。**/routes** 目录中用不同模块保存应用路由。/**views** 目录保存模板。

### [www 文件](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/skeleton_website#www_文件)

文件 **/bin/www** 是应用入口！它做的第一件事是 `require()` “真实” 的应用入口（即项目根目录中的 **app.js**），**app.js** 会设置并返回 `express()`应用对象。

文件的其余部分先为 `app` 设置端口（环境变量中的预定义值或默认值 3000），再创建一个 HTTP 服务器，然后开始监听请求，报告服务器错误和连接信息。

### [app.js](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/skeleton_website#app.js)

此文件创建一个 `express` 应用对象（依照惯例命名为 `app`），通过各种设置选项和中间件来设置这个应用，然后从该模块中导出。



# 使用数据库 (Mongoose)

Express 应用支持多款数据库，执行新建（**C**reate）、读取（**R**ead）、更新（**U**pdate）和删除（**D**elete）操作 (CRUD) 操作也有诸多途径。

### [我可以使用什么数据库?](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#我可以使用什么数据库)

Express 应用可以使用 Node 支持的所有数据库（Express 本身不支持数据库管理的任何具体行为/需求）。有许多 [流行的选择](https://expressjs.com/en/guide/database-integration.html)，包括 PostgreSQL、MySQL、Redis、SQLite 和 MongoDB。

### [与数据库交互的最佳方式是什么?](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#与数据库交互的最佳方式是什么)

与数据库交互有两种方法：

- 使用数据库的原生查询语言（例如SQL）
- 使用对象数据模型（Object Data Model，简称 ODM）或对象关系模型（Object Relational Model，简称 ORM）。 ODM / ORM 能将网站中的数据表示为 JavaScript 对象，然后将它们映射到底层数据库。一些 ORM 只适用某些特定数据库，还有一些是普遍适用的。

使用 SQL 或其它受到支持的查询语言才能达到最佳性能。ODM 通常慢一些，因为在对象和数据库格式之间存在一层用于映射的翻译代码，使它不一定会选用最高性能的数据库查询（尤其是普遍使用级别的 ODM，它必须在各类数据库功能方面做出更大的折衷）。

使用 ORM 的好处是：程序员可以继续用 JavaScript 对象的思维而不用转向数据库语义的思维。 在（同一个或不同网站）使用不同数据库时尤为明显。使用 ORM 还可以更方便地对数据进行验证和检查。

**提示：**使用 ODM / ORM 通常可以降低开发和维护成本！除非你非常熟悉本地查询语言，或者项目对性能要求很高，否则强烈推荐使用 ODM。

### [我应该使用哪种 ORM/ODM ?](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#我应该使用哪种_ormodm)

NPM 站点上有许多 ODM / ORM 解决方案

一般来说，选择解决方案应该考虑功能和“社区活跃度”（下载量、贡献数、bug 报告、文档质量，等）。在撰写本文时，Mongoose 是最受欢迎的 ODM，选用 MongoDB 数据库时，它是一个合理的选择。

### [在 LocalLibrary 中使用 Mongoose 和 MongoDb](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#在_locallibrary_中使用_mongoose_和_mongodb)

我们将在本地图书馆示例（以及本主题的其余部分）中使用 [Mongoose ODM ](https://www.npmjs.com/package/mongoose)来访问图书馆数据。Mongoose 作为 [MongoDB](https://www.mongodb.com/what-is-mongodb)（面向文档数据模型的开源 [NoSQL](https://en.wikipedia.org/wiki/NoSQL) 数据库）的前端。MongoDB 数据库里，“集合”中的“文档” [类似于](https://docs.mongodb.com/manual/core/databases-and-collections/#collections) 关系数据库里“表”中的“行”。

## [Mongoose 入门](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#mongoose_入门)

这一段将简要介绍如何将 Mongoose 连接到 MongoDB 数据库，如何定义模式和模型，以及如何进行基本查询

```
npm install mongoose
```

Copy to Clipboard

安装 Mongoose 会添加所有依赖项，包括 MongoDB 数据库驱动程序，但不会安装 MongoDB 本身。要安装 MongoDB 服务器，可以 [点击下载](https://www.mongodb.com/download-center) 各操作系统的安装程序在本地安装。也可以使用云端 MongoDB 实例。

### [连接到 MongoDB](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#连接到_mongodb)

Mongoose 需要连接到 MongoDB 数据库。可以 `require()` 之，并通过 `mongoose.connect()` 连接到本地数据库，如下。

```
// 导入 mongoose 模块
const mongoose = require('mongoose');

// 设置默认 mongoose 连接
const mongoDB = 'mongodb://127.0.0.1/my_database';
mongoose.connect(mongoDB);
// 让 mongoose 使用全局 Promise 库
mongoose.Promise = global.Promise;
// 取得默认连接
const db = mongoose.connection;

// 将连接与错误事件绑定（以获得连接错误的提示）
db.on('error', console.error.bind(console, 'MongoDB 连接错误：'));
```

可以用 `mongoose.connection` 取得默认的 `Connection` 对象。一旦连接，`Connection` 实例将触发打开事件。

**提示：**可以使用 `mongoose.createConnection()` 创建其它连接。该函数与 `connect()` 的参数（数据库 URI，包括主机地址、数据库名、端口、选项等）一致，并返回一个 `Connection` 对象。

### [定义和添加模型](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#定义和添加模型)

模型使用 `Schema` 接口进行定义。 `Schema` 可以定义每个文档中存储的字段，及字段的验证要求和默认值。还可以通过定义静态和实例辅助方法来更轻松地处理各种类型的数据，还可以像使用普通字段一样使用数据库中并不存在的虚拟属性（稍后讨论）。

`mongoose.model()` 方法将模式“编译”为模型。模型就可以用来查找、创建、更新和删除特定类型的对象。

**注：**MongoDB 数据库中，每个模型都映射至一组文档。这些文档包含 `Schema` 模型定义的字段名/模式类型。

#### 定义模式

下面的代码片段中定义了一个简单的模式。首先 `require()` mongoose，然后使用 `Schema` 构造器创建一个新的模式实例，使用构造器的对象参数定义各个字段。

```
// 获取 Mongoose
const mongoose = require('mongoose');

// 定义一个模式
var Schema = mongoose.Schema;

var SomeModelSchema = new Schema({
    a_string: String,
    a_date: Date
});
```

#### 创建模型

使用 `mongoose.model()` 方法从模式创建模型：

```
// 定义模式
const Schema = mongoose.Schema;

const SomeModelSchema = new Schema({
    a_string: String,
    a_date: Date
});

// 使用模式“编译”模型
const SomeModel = mongoose.model('SomeModel', SomeModelSchema);
```



第一个参数是为模型所创建集合的别名（Mongoose 将为 SomeModel 模型创建数据库集合），第二个参数是创建模型时使用的模式。

**注：**定义模型类后，可以使用它们来创建、更新或删除记录，以及通过查询来获取所有记录或特定子集。我们将在以下“[使用模型](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#)”部分展示，包括创建视图的情况。

#### 模式类型（字段）

模式可以包含任意数量的字段，每个字段代表 MongoDB 文档中的一段存储区域。下面是一个模式的示例，其中有许多常见字段类型和声明方式：

```
const schema = new Schema(
{
  name: String,
  binary: Buffer,
  living: Boolean,
  updated: { type: Date, default: Date.now },
  age: { type: Number, min: 18, max: 65, required: true },
  mixed: Schema.Types.Mixed,
  _someId: Schema.Types.ObjectId,
  array: [],
  ofString: [String], // 其他类型也可使用数组
  nested: { stuff: { type: String, lowercase: true, trim: true } }
})
```

#### 验证

Mongoose 提供内置的和自定义的验证器，以及同步的和异步的验证器。你可以在所有情况下，指定可接受的范围或值，以及验证失败的错误消息。

```
const breakfastSchema = new Schema({
  eggs: {
    type: Number,
    min: [6, '鸡蛋太少'],
    max: 12
  },
  drink: {
    type: String,
    enum: ['咖啡', '茶']
  }
});
```

#### 虚拟属性

虚拟属性是可以获取和设置、但不会保存到 MongoDB 的文档属性。getter 可用于格式化或组合字段，而 setter 可用于将单个值分解为多个值从而便于存储。文档中的示例，从名字和姓氏字段构造（并解构）一个全名虚拟属性，这比每次在模板中使用全名更简单，更清晰。

#### 方法和查询助手

模式支持 [实例方法](http://mongoosejs.com/docs/guide.html#methods)、[静态方法](http://mongoosejs.com/docs/guide.html#statics) 和 [查询助手](http://mongoosejs.com/docs/guide.html#query-helpers)。实例方法和静态方法外表很相似，但有本质区别，实例方法针对特定记录，且可以访问当前对象。查询助手可用于扩展 Mongoose 的 [链式查询 API](http://mongoosejs.com/docs/queries.html)（例如，在 `find()`、`findOne()` 和 `findById()` 方法外还可以添加一个 “`byName`” 查询）。

### [使用模型](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#使用模型)

就可以使用创建好的模式来创建模型。模型即数据库中可以搜索的一类文档，模型的实例即可以存取的单个文档。

#### 创建和修改文档

可以通过定义模型的实例并调用 `save()` 来创建记录。以下示例假定 `SomeModel` 是用现有模式创建的模型（只有一个字段 "`name`" ）：

```
// 创建一个 SomeModel 模型的实例
const awesome_instance = new SomeModel({ name: '牛人' });

// 传递回调以保存这个新建的模型实例
awesome_instance.save( function (err) {
  if (err) {
    return handleError(err);
  } // 已保存
});
```

记录的创建（以及更新、删除和查询）操作是异步的，可以提供一个回调函数在操作完成时调用。由于 API 遵循错误参数优先的惯例，因此回调的第一个参数必为错误值（或 `null`）。如果 API 需要返回一些结果，则将结果作为第二个参数。

还可以使用 `create()`，在定义模型实例的同时将其保存。回调的第一个参数返回错误，第二个参数返回新建的模型实例。

```
SomeModel.create(
  { name: '也是牛人' },
  function(err, awesome_instance) {
    if (err) {
      return handleError(err);
    } // 已保存
  }
);
```

每个模型都有一个相关的连接（使用 `mongoose.model()` 时将做为默认连接）。可以通过创建新连接并对其调用 `.model()`，从而在另一个数据库上创建文档。

可以使用“圆点”加字段名来访问、修改新记录中的字段。操作后必须调用 `save()` 或 `update()` 以将改动保存回数据库。

```
// 使用圆点来访问模型的字段值
console.log(awesome_instance.name); // 控制台将显示 '也是牛人'

// 修改字段内容并调用 save() 以修改记录
awesome_instance.name = "酷毙了的牛人";
awesome_instance.save( function(err) {
   if (err) {
     return handleError(err);
   } // 已保存
});
```

#### 搜索纪录

可以使用查询方法搜索记录，查询条件可列在 JSON 文档中。以下代码展示了如何在数据库中找到所有网球运动员，并返回运动员姓名和年龄字段。这里只指定了一个匹配字段（运动项目，`sport`），也可以添加更多条件，指定正则表达式，或去除所有条件以返回所有运动员。

```
const Athlete = mongoose.model('Athlete', yourSchema);

// SELECT name, age FROM Athlete WHERE sport='Tennis'
Athlete.find(
  { 'sport': 'Tennis' },
  'name age',
  function (err, athletes) {
    if (err) {
      return handleError(err);
    } // 'athletes' 中保存一个符合条件的运动员的列表
  }
);
```

若未指定回调，则 API 将返回 [Query](http://mongoosejs.com/docs/api.html#query-js) 类型的变量。可以使用该查询对象来构建查询，随后使用 `exec()`方法执行（使用回调）。

```
// 寻找所有网球运动员
const query = Athlete.find({ 'sport': 'Tennis' });

// 查找 name, age 两个字段
query.select('name age');

// 只查找前 5 条记录
query.limit(5);

// 按年龄排序
query.sort({ age: -1 });

// 以后某个时间运行该查询
query.exec(function (err, athletes) {
  if (err) {
    return handleError(err);
  } // athletes 中保存网球运动员列表，按年龄排序，共 5 条记录
})
```



#### 文档间协同 —— population

可以使用 `ObjectId` 模式字段来创建两个文档/模型实例间一对一的引用，（一组 `ObjectIds` 可创建一对多的引用）。该字段存储相关模型的 id。如果需要相关文档的实际内容，可以在查询中使用 `populate()`方法，将 id 替换为实际数据。

### [一模式（模型）一文件](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/mongoose#一模式（模型）一文件)

虽然创建模式和模型没有文件结构的限制，但强烈建议将单一模式定义在单一模块（文件）中，并通过导出方法来创建模型。



# 路由和控制器

下图展示了 HTTP 请求/响应处理的主数据流和需要实现的行为。图中除视图（View）和路由（Route）外，还展示了控制器（Controller），它们是实际的请求处理函数，与路由请求代码是分开的。

- 路由：把需要支持的请求（以及请求 URL 中包含的任何信息）转发到适当的控制器函数。
- 控制器：从模型中获取请求的数据，创建一个 HTML 页面显示出数据，并将页面返回给用户，以便在浏览器中查看。
- 视图（模板）：供控制器用来渲染数据。

![Express HTTP 请求/响应 路径](https://mdn.mozillademos.org/files/16453/Express_MVC.png)

创建路由有几种方法。本教程将使 `express.Router` 中间件，因为使用它可以将站点特定部分的路由处理程序打包，并使用通用路由前缀访问它们。

### [定义和使用单独的路由模块](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#定义和使用单独的路由模块)



### [路由函数](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#路由函数)

`Router.get()` 方法定义的 “about” 路由（下方重现的）仅响应 HTTP GET 请求。第一个参数是 URL 路径，第二个参数是一个回调，在收到带有路径的HTTP GET 请求将调用之。

```
router.get('/about', (req, res) => {
  res.send('关于此维基');
});
```

该回调有三个参数（通常命名为：`req`、`res`、`next`），分别是：HTTP 请求对象、HTTP 响应、中间件链中的下一个函数。

**注：**路由函数就是 [Express 中间件](https://developer.mozilla.org/en-US/docs/Learn/Server-side/Express_Nodejs/Introduction#Using_middleware)，这意味着它们必须（通过响应）结束请求，否则必须调用链中的 `next`函数。上述示例使用`send()` 完成了请求，所以没有使用 `next` 参数（参数表中将其省略）。

上述路由函数只需要一个回调，可以根据需要指定任意数量的回调参数，或一个回调函数数组。每个函数都将加入中间件链，并且将按添加顺序调用（若有回调完成请求则中止当前周期）。

### [HTTP 动词](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#http_动词)

上面的示例使用 `Router.get()` 方法来响应特定路径的 HTTP GET 请求。

`Router` 还为所有其他 HTTP 动词提供路由方法，大都用法相同：`post()`, `put()`, `delete()`, `options()`, `trace()`, `copy()`, `lock()`, `mkcol()`, `move()`, `purge()`, `propfind()`, `proppatch()`, `unlock()`, `report()`,  `mkactivity()`, `checkout()`, `merge()`, `m-``search()`, `notify()`, `subscribe()`, `unsubscribe()`, `patch()`, `search()`, 和 `connect()`。

### [路由路径](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#路由路径)

路由路径用于定义可请求的端点。之前示例中路径都是字符串，并且必须精确写为：'/'、'/ about'、'/ book'，等等。

路由路径也可以是字符串模式（String Pattern）。可用部分正则表达式语法来定义端点的模式。以下是所涉及的正则表达式（注意，连字符（ `-`）和点（`.`）在字符串路径中解释为字面量，不能做为正则表达式）：

- `?`：问号之前的一个字符只能出现零次或一次。例如，路由路径 `'/ab?cd'` 路径匹配端点 `acd` 或 `abcd`。
- `+`：加号之前的一个字符至少出现一次。例如，路径路径 `'/ab+cd'` 匹配端点 `abcd`、`abbcd`、`abbbcd`，等。
- `*`：星号可以替换为任意字符串。例如，路由路径 `'ab\*cd'` 匹配端点 `abcd`、`abXcd`、`abSOMErandomTEXTcd`，等。
- `()`：将一个字符串视为一体以执行 `?`、`+`、`*` 操作。例如。 `'/ab(cd)?e'` 将对 `(cd)` 进行匹配，将匹配到 `abe` 和 `abcde`。

路由路径也可以是 JavaScript [正则表达式](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Regular_Expressions)。例如，下面的路由路径将匹配 `catfish` 和 `dogfish`，但不会匹配 `catflap`、`catfishhead` 等。注意，正则表达式路径不再用引号 `"..."` 括起来，而是正则表达式语法 `/.../`。

```
app.get(/.*fish$/, (req, res) => {
  ...
});
```

### [路由参数](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#路由参数)

路径参数是命名的 URL 段，用于捕获在 URL 中的位置指定的值。命名段以冒号为前缀，然后是名称（例如 `/**:**your_parameter_name/`。捕获的值保存在 `req.params` 对象中，键即参数名（例如 `req.params.your_parameter_name`）。



## [创建路由处理器回调函数](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#创建路由处理器回调函数)

定义路由之前应先使用单独的“控制器”模块创建回调的结构骨架。（文件/模块结构没有限制，但以下结构很适合当前项目的规模）。

首先在项目根目录新建一个存放控制器的文件夹（**/controllers**），然后为每个模型创建单独的控制器文件（模块）：

### [`Author` 控制器](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#author_控制器)

以下是 **/controllers/authorController.js** 文件的内容：

```
const Author = require('../models/author');

// 显示完整的作者列表
exports.author_list = (req, res) => { res.send('未实现：作者列表'); };

// 为每位作者显示详细信息的页面
exports.author_detail = (req, res) => { res.send('未实现：作者详细信息：' + req.params.id); };

// 由 GET 显示创建作者的表单
exports.author_create_get = (req, res) => { res.send('未实现：作者创建表单的 GET'); };

// 由 POST 处理作者创建操作
exports.author_create_post = (req, res) => { res.send('未实现：创建作者的 POST'); };

// 由 GET 显示删除作者的表单
exports.author_delete_get = (req, res) => { res.send('未实现：作者删除表单的 GET'); };

// 由 POST 处理作者删除操作
exports.author_delete_post = (req, res) => { res.send('未实现：删除作者的 POST'); };

// 由 GET 显示更新作者的表单
exports.author_update_get = (req, res) => { res.send('未实现：作者更新表单的 GET'); };

// 由 POST 处理作者更新操作
exports.author_update_post = (req, res) => { res.send('未实现：更新作者的 POST'); };
```

该模块首先导入了用于访问和更新数据的模型，然后为每个需要处理（添加、更新和删除表单，以及相应的 POST 请求，稍后在 [使用表单](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/forms) 一节中讲解）的 URL 导出一个函数。

所有函数都遵循 Express 中间件函数的标准形式，三个参数依次为：请求 `req`、响应 `res`、当前方法无法完成请求循环时（这里不存在这种情况）调用的 `next` 函数。上述方法只返回一个字符串，显示相关页面尚未创建。接收路径参数的控制器函数可将参数输出到消息字符串中（代码中出现的 `req.params.id` ）。

## [创建藏书编目 `catalog` 路由模组](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#创建藏书编目_catalog_路由模组)

定义好控制器后，我们来为 LocalLibrary 网站创建完整的 URL 路由。

站点骨架中有一个 **./routes** 文件夹，其中包含两个路由文件：index 和 user，在这里新建一个 **catalog.js** 路由文件；

**/routes/****catalog.js** 中有以下代码：

```
const express = require('express');
const router = express.Router();

// 导入控制器模块
const book_controller = require('../controllers/bookController');
const author_controller = require('../controllers/authorController');
const genre_controller = require('../controllers/genreController');
const book_instance_controller = require('../controllers/bookinstanceController');

/// 藏书路由 ///

// GET 获取藏书编目主页
router.get('/', book_controller.index);

// GET 请求添加新的藏书。注意此项必须位于显示藏书的路由（使用了 id）之前。
router.get('/book/create', book_controller.book_create_get);

// POST 请求添加新的藏书
router.post('/book/create', book_controller.book_create_post);

// GET 请求删除藏书
router.get('/book/:id/delete', book_controller.book_delete_get);

// POST 请求删除藏书
router.post('/book/:id/delete', book_controller.book_delete_post);

// GET 请求更新藏书
router.get('/book/:id/update', book_controller.book_update_get);

// POST 请求更新藏书
router.post('/book/:id/update', book_controller.book_update_post);

// GET 请求藏书
router.get('/book/:id', book_controller.book_detail);

// GET 请求完整藏书列表
router.get('/books', book_controller.book_list);

/// 藏书副本、藏书种类、作者的路由与藏书路由结构基本一致，只是无需获取主页 ///

module.exports = router;
```

Copy to Clipboard

该模块导入了 `express` 并创建了一个 `Router` 对象 `router`。所有路由都设置在 `router` 上，最后将其导出。

对 `router` 对象调用 `.get()` 或`.post()` 函数即可定义路由。这里所有路径都使用字符串定义（而不用字符串模式或正则表达式）。某些特定资源（如藏书）的路由使用路径参数从 URL 中获取对象标识。

处理函数均导入自上文的控制器模块。

### [更新 index 路由模块](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#更新_index_路由模块)

新路由已经设置完毕，还需要设置一下 `index` 模块。我们将网站的首页重定向（`redirect`）至刚创建的地址 '`/catalog`'。

将 **/routes/index.js** 中的中间件修改一下：

```
// GET 请求主页
router.get('/', (req, res) => {
  res.redirect('/catalog');
});
```

**注：**这是我们第一次使用 [redirect()](https://expressjs.com/en/4x/api.html#res.redirect) 响应方法。它会使路由重定向到指定的页面，默认发送 HTTP 状态代码“302 Found”。可以根据需要更改返回的状态代码、设置绝对或相对路径。

### [更新 app.js](https://developer.mozilla.org/zh-CN/docs/learn/Server-side/Express_Nodejs/routes#更新_app.js)

最后一步是在 `app.js` 中将路由添加到中间件链。

打开 **app.js**，在 `index` 和 `users` 路由下方添加 `catalog` 路由：

```
const indexRouter = require('./routes/index');
const usersRouter = require('./routes/users');
const catalogRouter = require('./routes/catalog');  // 导入 catalog 路由
```

Copy to Clipboard

然后在已定义的路由下方将目录路由添加进中间件栈：

```
app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/catalog', catalogRouter);  // 将 catalog 路由添加进中间件链
```

# 呈现图书馆数据

# 使用表单





### 重新介绍JavaScript

##### 概览

JavaScript 是一种多范式的动态语言，它包含类型、运算符、标准内置（ built-in）对象和方法。

avaScript 通过原型链而不是类来支持面向对象编程

##### 数字

JavaScript采用IEEE754标准的双精度64位格式表示数字。除了BigInt外，并不存在整数/整型。

JavaScript支持标准的算符运算符，包括加减乘除，取模等；

内置对象Math，用以处理更多高级数学函数和常数；

可使用内置函数parseInt将字符串转换为整型，该函数的第二个可选参数表示字符串所代表的数字的基（进制）；

```
parseInt("123", 10); // 123
parseInt("010", 10); // 10
```

一元运算符+也可以把数字字符串转换成数值：

```js
+ "42";   // 42
+ "010";  // 10
+ "0x10"; // 16
```

如果给定的字符串不存在数值形式，函数会返回一个特殊的值 [`NaN`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/NaN)（Not a Number 的缩写）：

```
parseInt("hello", 10); // NaN
```

要小心NaN：如果把 `NaN` 作为参数进行任何数学运算，结果也会是 `NaN`：

```
NaN + 5; //NaN
```



##### 字符串

JavaScript中的字符串是一串Unicode字符序列。它们是一串UTF-16编码单元的序列，每个编码单元由一个16位二进制数表示。每一个Unicode字符由一个或两个编码单元来表示。

JavaScript 允许声明变量但不对其赋值，一个未被赋值的变量就是 `undefined` 类型。还有一点需要说明的是，`undefined` 实际上是一个不允许修改的常量。



##### 变量

let 、const、var；

let 语句声明一个块级作用域的本地变量；

const 允许声明一个不可变的常量；

var 声明的变量在它声明的整个函数都是可见的；

如果声明了一个变量却没有对其赋值，那么这个变量的类型就是 `undefined`。

JavaScript 与其他语言的（如 Java）的重要区别是在 JavaScript 中语句块（blocks）是没有作用域的，只有函数有作用域。因此如果在一个复合语句中（如 if 控制结构中）使用 var 声明一个变量，那么它的作用域是整个函数（复合语句在函数中）。 但是从 ECMAScript Edition 6 开始将有所不同的， `let` 和 `const` 关键字允许你创建块作用域的变量。

##### 运算符

JavaScript的算术操作符包括 `+`、`-`、`*`、`/` 和 `%` ——求余（[与模运算相同](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Arithmetic_Operators#求余_())）。赋值使用 `=` 运算符，此外还有一些复合运算符，如 `+=` 和 `-=`，它们等价于 `x = x *operator* y`。

[`+` 操作符](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Arithmetic_Operators#.E5.8A.A0.E6.B3.95_(.2B))还可以用来连接字符串：

##### 控制结构

在 `switch` 的表达式和 `case` 的表达式是使用 `===` 严格相等运算符进行比较的。

##### 对象

new Object（）

对象字面量法；直接定义对象；

##### 数组

JavaScript中的数组是一种特殊的对象。

for 。。。of 遍历可迭代对象；

for...in 数组的索引；

| 方法名称                                             | 描述                                                         |
| :--------------------------------------------------- | :----------------------------------------------------------- |
| `a.toString()`                                       | 返回一个包含数组中所有元素的字符串，每个元素通过逗号分隔。   |
| `a.toLocaleString()`                                 | 根据宿主环境的区域设置，返回一个包含数组中所有元素的字符串，每个元素通过逗号分隔。 |
| `a.concat(item1[, item2[, ...[, itemN]]])`           | 返回一个数组，这个数组包含原先 `a` 和 `item1、item2、……、itemN` 中的所有元素。 |
| `a.join(sep)`                                        | 返回一个包含数组中所有元素的字符串，每个元素通过指定的 `sep` 分隔。 |
| `a.pop()`                                            | 删除并返回数组中的最后一个元素。                             |
| `a.push(item1, ..., itemN)`                          | 将 `item1、item2、……、itemN` 追加至数组 `a`。                |
| `a.reverse()`                                        | 数组逆序（会更改原数组 `a`）。                               |
| `a.shift()`                                          | 删除并返回数组中第一个元素。                                 |
| `a.slice(start, end)`                                | 返回子数组，以 `a[start]` 开头，以 `a[end]` 前一个元素结尾。 |
| `a.sort([cmpfn])`                                    | 依据可选的比较函数 `cmpfn` 进行排序，如果未指定比较函数，则按字符顺序比较（即使被比较元素是数字）。 |
| `a.splice(start, delcount[, item1[, ...[, itemN]]])` | 从 `start` 开始，删除 `delcount` 个元素，然后插入所有的 `item`。 |
| `a.unshift(item1[, item2[, ...[, itemN]]])`          | 将 `item` 插入数组头部，返回数组新长度（考虑 `undefined`）。 |



##### 函数

函数内部的arguments的内部对象；

```
function add() {
    var sum = 0;
    for (var i = 0, j = arguments.length; i < j; i++) {
        sum += arguments[i];
    }
    return sum;
}

add(2, 3, 4, 5); // 14
```



可以使用剩余参数来替换arguments的使用。

**剩余参数操作符**在函数中以：**...variable** 的形式被使用，它将包含在调用函数时使用的未捕获整个参数列表到这个变量中。

```
function avg(...args) {
  var sum = 0;
  for (let value of args) {
    sum += value;
  }
  return sum / args.length;
}

avg(2, 3, 4, 5); // 3.5
```



##### 自定义对象

###### 闭包

每当JavaScript执行一个函数时，都会创建一个作用域对象，用来保存这个函数中创建的局部变量。它使用一切被传入函数的变量进行初始化。这与那些保存所有全局变量和函数的全局对象相类似，但仍有一些区别：第一，每次函数被执行的时候，就会创建一个新的特定的作用域对象，第二，与全局对象不同的是，不能从JavaScript代码中直接访问作用域对象，也没有可以遍历当前作用域对象中的属性的方法。

所以，当调用 `makeAdder` 时，解释器创建了一个作用域对象，它带有一个属性：`a`，这个属性被当作参数传入 `makeAdder` 函数。然后 `makeAdder` 返回一个新创建的函数（暂记为 `adder`）。通常，JavaScript 的垃圾回收器会在这时回收 `makeAdder` 创建的作用域对象（暂记为 `b`），但是，`makeAdder` 的返回值，新函数 `adder`，拥有一个指向作用域对象 `b` 的引用。最终，作用域对象 `b` 不会被垃圾回收器回收，直到没有任何引用指向新函数 `adder`。

作用域对象组成了一个名为作用域链（scope chain）的（调用）链。它和 JavaScript 的对象系统使用的原型（prototype）链相类似。



一个**闭包**，就是 一个函数 与其 被创建时所带有的作用域对象 的组合。闭包允许你保存状态——所以，它们可以用来代替对象。



# JavaScript 数据类型和数据结构

记住 `typeof` 操作符的唯一目的就是检查数据类型，如果我们希望检查任何从 Object 派生出来的结构类型，使用 `typeof` 是不起作用的，因为总是会得到 `"object"`。检查 Object 种类的合适方式是使用 instanceof 关键字。但即使这样也存在误差。

[`BigInt`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/BigInt)类型是 JavaScript 中的一个基础的数值类型，可以用任意精度表示整数。使用 BigInt，您可以安全地存储和操作大整数，甚至可以超过数字的安全整数限制。BigInt 是通过在整数末尾附加 `n `或调用构造函数来创建的。



### [键控集: Maps, Sets, WeakMaps, WeakSets](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#键控集_maps_sets_weakmaps_weaksets)



# 内存管理

JavaScript是在创建变量（对象，字符串等）时自动进行了分配内存，并且在不使用它们时“自动”释放。 释放的过程称为垃圾回收。

## [内存生命周期](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Memory_Management#内存生命周期)

不管什么程序语言，内存生命周期基本是一致的：  

1. 分配你所需要的内存
2. 使用分配到的内存（读、写）
3. 不需要时将其释放\归还



# 继承与原型链

当谈到继承时，JavaScript 只有一种结构：对象。每个实例对象（object）都有一个私有属性（称之为 __proto__ ）指向它的构造函数的原型对象（**prototype**）。该原型对象也有一个自己的原型对象（__proto__），层层向上直到一个对象的原型对象为 `null`。根据定义，`null` 没有原型，并作为这个**原型链**中的最后一个环节。

几乎所有 JavaScript 中的对象都是位于原型链顶端的 [`Object`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Object) 的实例。



## [基于原型链的继承](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Inheritance_and_the_prototype_chain#基于原型链的继承)

### [继承属性](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Inheritance_and_the_prototype_chain#继承属性)

### [继承方法](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Inheritance_and_the_prototype_chain#继承方法)

在 JavaScript 里，任何函数都可以添加到对象上作为对象的属性。函数的继承与其他的属性继承没有差别，包括上面的“属性遮蔽”（这种情况相当于其他语言的方法重写）。



## [使用不同的方法来创建对象和生成原型链](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Inheritance_and_the_prototype_chain#使用不同的方法来创建对象和生成原型链)

###### 使用语法结构创建的对象

```
var o = {a: 1};

// o 这个对象继承了 Object.prototype 上面的所有属性
// o 自身没有名为 hasOwnProperty 的属性
// hasOwnProperty 是 Object.prototype 的属性
// 因此 o 继承了 Object.prototype 的 hasOwnProperty
// Object.prototype 的原型为 null
// 原型链如下:
// o ---> Object.prototype ---> null

var a = ["yo", "whadup", "?"];

// 数组都继承于 Array.prototype
// (Array.prototype 中包含 indexOf, forEach 等方法)
// 原型链如下:
// a ---> Array.prototype ---> Object.prototype ---> null

function f(){
  return 2;
}

// 函数都继承于 Function.prototype
// (Function.prototype 中包含 call, bind等方法)
// 原型链如下:
// f ---> Function.prototype ---> Object.prototype ---> null
```

###### 使用构造器创建的对象

在 JavaScript 中，构造器其实就是一个普通的函数。当使用 [new 操作符](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/new) 来作用这个函数时，它就可以被称为构造方法（构造函数）。

###### 使用Object.create创建的对象

ECMAScript 5 中引入了一个新方法：[`Object.create()`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Object/create)。可以调用这个方法来创建一个新对象。新对象的原型就是调用 create 方法时传入的第一个参数。

###### 使用class关键字创建的对象

ECMAScript6 引入了一套新的关键字用来实现 [class](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Classes)。使用基于类语言的开发人员会对这些结构感到熟悉，但它们是不同的。JavaScript 仍然基于原型。这些新的关键字包括 [`class`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/class), [`constructor`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Classes/constructor)，[`static`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Classes/static)，[`extends`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Classes/extends) 和 [`super`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/super)。

###### 性能

在原型链上查找属性比较耗时，对性能有副作用。另外，试图访问不存在的属性时会遍历整个原型链。

遍历对象的属性时，原型链上的每个可枚举属性都会被枚举出来。

要检查对象是否具有自己定义的属性，而不是其原型链上的某个属性，则必须使用所有对象从Object.prototype继承的hasOwnProperty方法。

`hasOwnProperty (en-US)` 是 JavaScript 中唯一一个处理属性并且**不会**遍历原型链的方法。（译者注：原文如此。另一种这样的方法：`Object.keys()`）

注意：检查属性是否为 `undefined` 是**不能够**检查其是否存在的。该属性可能已存在，但其值恰好被设置成了 `undefined`。















































