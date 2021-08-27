# 高频JavaScript

#### 数据类型

1、JavaScript有哪些数据类型？区别？

JavaScript共有八种数据类型，分别是 Undefined、Null、Boolean、Number、String、Object、Symbol、BigInt。

Symbol 和 BigInt 是ES6 中新增的数据类型：

Symbol 代表创建后独一无二且不可变的数据类型，它主要是为了解决可能出现的全局变量冲突的问题。
BigInt 是一种数字类型的数据，它可以表示任意精度格式的整数，使用 BigInt 可以安全地存储和操作大整数，即使这个数已经超出了 Number 能够表示的安全整数范围。

这些数据可以分为原始数据类型和引用数据类型：

栈：原始数据类型（Undefined、Null、Boolean、Number、String）
堆：引用数据类型（对象、数组和函数）

两种类型的区别在于存储位置的不同：

原始数据类型直接存储在栈（stack）中的简单数据段，占据空间小、大小固定，属于被频繁使用数据，所以放入栈中存储；
引用数据类型存储在堆（heap）中的对象，占据空间大、大小不固定。如果存储在栈中，将会影响程序运行的性能；引用数据类型在栈中存储了指针，该指针指向堆中该实体的起始地址。当解释器寻找引用值时，会首先检索其在栈中的地址，取得地址后从堆中获得实体。

堆和栈的概念存在于数据结构和操作系统内存中，在数据结构中：

在数据结构中，栈中数据的存取方式为先进后出。
堆是一个优先队列，是按优先级来进行排序的，优先级可以按照大小来规定。

在操作系统中，内存被分为栈区和堆区：

栈区内存由编译器自动分配释放，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。
堆区内存一般由开发着分配释放，若开发者不释放，程序结束时可能由垃圾回收机制回收。

##### 2、数据类型检测方式有哪些？

typeof

console.log(typeof 2);               // number
console.log(typeof true);            // boolean
console.log(typeof 'str');           // string
**console.log(typeof []);              // object**    
console.log(typeof function(){});    // function
**console.log(typeof {});              // object**
console.log(typeof undefined);       // undefined
**console.log(typeof null);            // object**

instanceof

instanceof可以正确判断对象的类型，其内部运行机制是判断在其原型链中能否找到该类型的原型。

console.log(2 instanceof Number);                    // false
console.log(true instanceof Boolean);                // false 
console.log('str' instanceof String);                // false 

console.log([] instanceof Array);                    // true
console.log(function(){} instanceof Function);       // true
console.log({} instanceof Object);                   // true

instanceof只能正确判断引用数据类型，而不能判断基本数据类型。instanceof 运算符可以用来测试一个对象在其原型链中是否存在一个构造函数的 prototype 属性。

constructor

console.log((2).constructor === Number); // true
console.log((true).constructor === Boolean); // true
console.log(('str').constructor === String); // true
console.log(([]).constructor === Array); // true
console.log((function() {}).constructor === Function); // true
console.log(({}).constructor === Object); // true

constructor有两个作用，一是判断数据的类型，二是对象实例通过 constrcutor 对象访问它的构造函数。需要注意，如果创建一个对象来改变它的原型，constructor就不能用来判断数据类型了：

Object.prototype.toString.call()

Object.prototype.toString.call() 使用 Object 对象的原型方法 toString 来判断数据类型

##### 3、判断数组的方式有哪些？

通过Object.prototype.toString.call()做判断

Object.prototype.toString.call(obj).slice(8,-1) === 'Array';

通过原型链做判断

obj.__proto__ === Array.prototype;

通过ES6的Array.isArray()做判断

Array.isArrray(obj);

通过instanceof做判断

obj instanceof Array

通过Array.prototype.isPrototypeOf

Array.prototype.isPrototypeOf(obj)

##### 4、null和undefined区别

首先 Undefined 和 Null 都是基本数据类型，这两个基本数据类型分别都只有一个值，就是 undefined 和 null。
undefined 代表的含义是未定义，null 代表的含义是空对象。一般变量声明了但还没有定义的时候会返回 undefined，null主要用于赋值给一些可能会返回对象的变量，作为初始化。

undefined 在 JavaScript 中不是一个保留字

当对这两种类型使用 typeof 进行判断时，Null 类型化会返回 “object”，这是一个历史遗留的问题。当使用双等号对两种类型的值进行比较时会返回 true，使用三个等号时会返回 false。

##### 5、typeof null的结果是什么，为什么？

typeof null 的结果是Object。

##### 6、instanceof操作符的实现原理及实现

instanceof 运算符用于判断构造函数的 prototype 属性是否出现在对象的原型链中的任何位置。

##### 7、为什么0.1+0.2 ! == 0.3，如何让其相等？

计算机是通过二进制的方式存储数据的，所以计算机计算0.1+0.2的时候，实际上是计算的两个数的二进制的和。0.1的二进制是0.0001100110011001100...（1100循环），0.2的二进制是：0.00110011001100...（1100循环），这两个数的二进制都是无限循环的数。

那JavaScript是如何处理无限循环的二进制小数呢？

一般我们认为数字包括整数和小数，但是在 JavaScript 中只有一种数字类型：Number，它的实现遵循IEEE 754标准，使用64位固定长度来表示，也就是标准的double双精度浮点数。在二进制科学表示法中，双精度浮点数的小数部分最多只能保留52位，再加上前面的1，其实就是保留53位有效数字，剩余的需要舍去，遵从“0舍1入”的原则。
根据这个原则，0.1和0.2的二进制数相加，再转化为十进制数就是：0.30000000000000004。

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/0cb225cf71d748a8b2d6a5615e402711~tplv-k3u1fbpfcp-watermark.awebp)

第一部分（蓝色）：用来存储符号位（sign），用来区分正负数，0表示正数，占用1位
第二部分（绿色）：用来存储指数（exponent），占用11位
第三部分（红色）：用来存储小数（fraction），占用52位

##### 8、如何获取安全的undefined值？

void 0

##### 9、typeof NaN的结果是什么？

NaN 指“不是一个数字”（not a number），NaN 是一个“警戒值”（sentinel value，有特殊用途的常规值），用于指出数字类型中的错误情况，即“执行数学运算没有成功，这是失败后返回的结果”。

NaN 是一个特殊值，它和自身不相等，是唯一一个非自反（自反，reflexive，即 x === x 不成立）的值。而 NaN !== NaN 为 true。

typeof NaN; // "number"

##### 10、isNaN和Number.isNaN函数的区别？

函数 isNaN 接收参数后，会尝试将这个参数转换为数值，任何不能被转换为数值的的值都会返回 true，因此非数字值传入也会返回 true ，会影响 NaN 的判断。
函数 Number.isNaN 会首先判断传入参数是否为数字，如果是数字再继续判断是否为 NaN ，不会进行数据类型的转换，这种方法对于 NaN 的判断更为准确。

##### 11、== 操作符的强制类型转换规则？

对于 == 来说，如果对比双方的类型不一样，就会进行类型转换。假如对比 x 和 y 是否相同，就会进行如下判断流程：

首先会判断两者类型是否**相同，**相同的话就比较两者的大小；
类型不相同的话，就会进行类型转换；
会先判断是否在对比 null 和 undefined，是的话就会返回 true
判断两者类型是否为 string 和 number，是的话就会将字符串转换为 number

判断其中一方是否为 boolean，是的话就会把 boolean 转为 number 再进行判断

判断其中一方是否为 object 且另一方为 string、number 或者 symbol，是的话就会把 object 转为原始类型再进行判断

##### 12、其他值到字符串的转换规则？

Null 和 Undefined 类型 ，null 转换为 "null"，undefined 转换为 "undefined"，
Boolean 类型，true 转换为 "true"，false 转换为 "false"。
Number 类型的值直接转换，不过那些极小和极大的数字会使用指数形式。
Symbol 类型的值直接转换，但是只允许显式强制类型转换，使用隐式强制类型转换会产生错误。
对普通对象来说，除非自行定义 toString() 方法，否则会调用 toString()（Object.prototype.toString()）来返回内部属性 [[Class]] 的值，如"[object Object]"。如果对象有自己的 toString() 方法，字符串化时就会调用该方法并使用其返回值。

##### 13、其他值到数字值的转换规则？

Undefined 类型的值转换为 NaN。
Null 类型的值转换为 0。
Boolean 类型的值，true 转换为 1，false 转换为 0。
String 类型的值转换如同使用 Number() 函数进行转换，如果包含非数字值则转换为 NaN，空字符串为 0。
Symbol 类型的值不能转换为数字，会报错。
对象（包括数组）会首先被转换为相应的基本类型值，如果返回的是非数字的基本类型值，则再遵循以上规则将其强制转换为数字。

##### 14、其他值到布尔类型的值的转换规则？

以下这些是假值： • undefined • null • false • +0、-0 和 NaN • ""

假值的布尔强制类型转换结果为 false。从逻辑上说，假值列表以外的都应该是真值。

##### 15、||和 && 操作符的返回值？

|| 和 && 首先会对第一个操作数执行条件判断，如果其不是布尔值就先强制转换为布尔类型，然后再执行条件判断。

对于 || 来说，如果条件判断结果为 true 就返回第一个操作数的值，如果为 false 就返回第二个操作数的值。
&& 则相反，如果条件判断结果为 true 就返回第二个操作数的值，如果为 false 就返回第一个操作数的值。

|| 和 && 返回它们其中一个操作数的值，而非条件判断的结果

##### 16、Object.is()与比较操作符===、==的区别？

使用双等号（==）进行相等判断时，如果两边的类型不一致，则会进行强制类型转化后再进行比较。
使用三等号（===）进行相等判断时，如果两边的类型不一致时，不会做强制类型准换，直接返回 false。
使用 Object.is 来进行相等判断时，一般情况下和三等号的判断相同，它处理了一些特殊的情况，比如 -0 和 +0 不再相等，两个 NaN 是相等的。

##### 17、什么是JavaScript中的包装类型？

在 JavaScript 中，基本类型是没有属性和方法的，但是为了便于操作基本类型的值，在调用基本类型的属性或方法时 JavaScript 会在后台隐式地将基本类型的值转换为对象。

在访问'abc'.length时，JavaScript 将'abc'在后台转换成String('abc')，然后再访问其length属性。

##### 18、JavaScript 中如何进行隐式类型转换？

首先要介绍ToPrimitive方法，这是 JavaScript 中每个值隐含的自带的方法，用来将值 （无论是基本类型值还是对象）转换为基本类型值。如果值为基本类型，则直接返回值本身；如果值为对象，其看起来大概是这样：

/**
* @obj 需要转换的对象
* @type 期望的结果类型
*/
ToPrimitive(obj,type)

type的值为number或者string。
（1）当type为number时规则如下：

调用obj的valueOf方法，如果为原始值，则返回，否则下一步；
调用obj的toString方法，后续同上；
抛出TypeError 异常。

（2）当type为string时规则如下：

调用obj的toString方法，如果为原始值，则返回，否则下一步；
调用obj的valueOf方法，后续同上；
抛出TypeError 异常。

可以看出两者的主要区别在于调用toString和valueOf的先后顺序。默认情况下：

如果对象为 Date 对象，则type默认为string；
其他情况下，type默认为number。

以下是基本类型的值在不同操作符的情况下隐式转换的规则 （对于对象，其会被ToPrimitive转换成基本类型，所以最终还是要应用基本类型转换规则）：



+操作符的两边有至少一个string类型变量时，两边的变量都会被隐式转换为字符串；其他情况下两边的变量都会被转换为数字。

-、*、\操作符
NaN也是一个数字

对于==操作符
操作符两边的值都尽量转成number

对于<和>比较符
如果两边都是字符串，则比较字母表顺序

其他情况下，转换为数字再比较

##### 19、`+` 操作符什么时候用于字符串的拼接？

简单来说就是，如果 + 的其中一个操作数是字符串（或者通过以上步骤最终得到字符串），则执行字符串拼接，否则执行数字加法。

那么对于除了加法的运算符来说，只要其中一方是数字，那么另一方就会被转为数字。

##### 20、为什么会有BigInt的提案？

##### 21、object.assign和扩展运算法是深拷贝还是浅拷贝，两者区别？

两者都是浅拷贝。

Object.assign()方法接收的第一个参数作为目标对象，后面的所有参数作为源对象。然后把所有的源对象合并到目标对象中。它会修改了一个对象，因此会触发 ES6 setter。
扩展操作符（…）使用它时，数组或对象中的每一个值都会被拷贝到一个新的数组或对象中。它不复制继承的属性或类的属性，但是它会复制ES6的 symbols 属性。

#### ES6

1、let、const、var的区别

2、const对象的属性可以修改吗？

const保证的并不是变量的值不能改动，而是变量指向的那个内存地址不能改动。

对于基本类型的数据（数值、字符串、布尔值），其值就保存在变量指向的那个内存地址，因此等同于常量。
但对于引用类型的数据（主要是对象和数组）来说，变量指向数据的内存地址，保存的只是一个指针，const只能保证这个指针是固定不变的，至于它指向的数据结构是不是可变的，就完全不能控制了。

##### 3、如果new一个箭头函数会怎样？

##### 4、箭头函数与普通函数的区别

##### 5、箭头函数的this指向哪里？

##### 6、扩展运算符的作用及其使用场景

对象的扩展运算符(...)用于取出参数对象中的所有可遍历属性，拷贝到当前对象之中。

let bar = { a: 1, b: 2 };
let baz = { ...bar }; // { a: 1, b: 2 }

同样，如果用户自定义的属性，放在扩展运算符后面，则扩展运算符内部的同名属性会被覆盖掉。

let bar = {a: 1, b: 2};
let baz = {...bar, ...{a:2, b: 4}};  // {a: 2, b: 4}

数组的扩展运算符可以将一个数组转为用逗号分隔的参数序列，且每次只能展开一层数组。

console.log(...[1, 2, 3])
// 1 2 3
console.log(...[1, [2, 3, 4], 5])
// 1 [2, 3, 4] 5

将数组转换为参数序列

复制数组

扩展运算符(…)用于取出参数对象中的所有可遍历属性，拷贝到当前对象之中，这里参数对象是个数组，数组里面的所有对象都是基础数据类型，将所有基础数据类型重新拷贝到新的数组中。

合并数组

扩展运算符与解构赋值结合起来，用于生成数组

如果将扩展运算符用于数组赋值，只能放在参数的最后一位，否则会报错。

将字符串转为真正的数组

<u>任何 Iterator 接口的对象，都可以用扩展运算符转为真正的数组</u>

使用Math函数获取数组中特定的值

const numbers = [9, 4, 7, 1];
Math.min(...numbers); // 1
Math.max(...numbers); // 9

##### 7、Proxy可以实现什么功能？

##### 8、对对象与数组的解构的理解？

解构是 ES6 提供的一种新的提取数据的模式，这种模式能够从对象或数组里有针对性地拿到想要的数值。 1）数组的解构 在解构数组时，以元素的位置为匹配条件来提取想要的数据的：

const [a, b, c] = [1, 2, 3]

对象的解构 对象解构比数组结构稍微复杂一些，也更显强大。在解构对象时，是以属性的名称为匹配条件，来提取想要的数据的。

注意，对象解构严格以属性名作为定位依据，所以就算调换了 name 和 age 的位置，结果也是一样的

##### 9、如何提取高度嵌套的对象里的指定属性？

可以在解构出来的变量名右侧，通过冒号+{目标属性名}这种形式，进一步解构它，一直解构到拿到目标数据为止。

##### 10、对 rest参数的理解？

扩展运算符被用在函数形参上时，它还可以把一个分离的参数序列整合成一个数组。

经常用于获取函数的多余参数，或者像上面这样处理函数参数个数不确定的情况。

##### 11、ES6中模板语法与字符串处理

板字符串的第一个优势——允许用${}的方式嵌入变量。

模板字符串的关键优势有两个：

在模板字符串中，空格、缩进、换行都会被保留
模板字符串完全支持“运算”式的表达式，可以在${}里完成一些计算

存在性判断：indexOf；includes；startsWith；endsWith；

自动重复：可以使用repeat方法来使同一个字符串输出多次；



#### JavaScript基础

##### 1、new操作符的实现原理

new操作符的执行过程：
（1）首先创建了一个新的空对象
（2）设置原型，将对象的原型设置为函数的 prototype 对象。
（3）让函数的 this 指向这个对象，执行构造函数的代码（为这个新对象添加属性）
（4）判断函数的返回值类型，如果是值类型，返回创建的对象。如果是引用类型，就返回这个引用类型的对象。

##### 2、map和Object的区别

##### 3、Map和WeakMap的区别

##### 4、JavaScript有哪些内置对象

全局的对象（ global objects ）或称标准内置对象，不要和 "全局对象（global object）" 混淆。这里说的全局的对象是说在 全局作用域里的对象。全局作用域中的其他对象可以由用户的脚本创建或由宿主程序提供。

标准内置对象的分类：

##### 5、常用的正则表达式有哪些？

##### 6、对JSON的理解？

JSON 是一种基于文本的轻量级的数据交换格式。它可以被任何的编程语言读取和作为数据格式来传递。

应该注意的是 JSON 和 js 中的对象不是一回事，JSON 中对象格式更加严格，比如说在 JSON 中属性值不能为函数，不能出现 NaN 这样的属性值等，因此大多数的 js 对象是不符合 JSON 对象的格式的。

在 js 中提供了两个函数来实现 js 数据结构和 JSON 格式的转换处理，

JSON.stringify 函数，通过传入一个符合 JSON 格式的数据结构，将其转换为一个 JSON 字符串。如果传入的数据结构不符合 JSON 格式，那么在序列化的时候会对这些值进行对应的特殊处理，使其符合规范。在前端向后端发送数据时，可以调用这个函数将数据对象转化为 JSON 格式的字符串。
JSON.parse() 函数，这个函数用来将 JSON 格式的字符串转换为一个 js 数据结构，如果传入的字符串不是标准的 JSON 格式的字符串的话，将会抛出错误。当从后端接收到 JSON 格式的字符串时，可以通过这个方法来将其解析为一个 js 数据结构，以此来进行数据的访问。

##### 7、JavaScript脚本延迟加载的方式有哪些？

延迟加载就是等页面加载完成之后再加载 JavaScript 文件。 js 延迟加载有助于提高页面加载速度。

一般有以下几种方式：

defer 属性： 给 js 脚本添加 defer 属性，这个属性会让脚本的加载与文档的解析同步解析，然后在文档解析完成后再执行这个脚本文件，这样的话就能使页面的渲染不被阻塞。多个设置了 defer 属性的脚本按规范来说最后是顺序执行的，但是在一些浏览器中可能不是这样。
async 属性： 给 js 脚本添加 async 属性，这个属性会使脚本异步加载，不会阻塞页面的解析过程，但是当脚本加载完成后立即执行 js 脚本，这个时候如果文档没有解析完成的话同样会阻塞。多个 async 属性的脚本的执行顺序是不可预测的，一般不会按照代码的顺序依次执行。
动态创建 DOM 方式： 动态创建 DOM 标签的方式，可以对文档的加载事件进行监听，当文档加载完成后再动态的创建 script 标签来引入 js 脚本。
使用 setTimeout 延迟方法： 设置一个定时器来延迟加载js脚本文件
让 JS 最后加载： 将 js 脚本放在文档的底部，来使 js 脚本尽可能的在最后来加载执行。

##### 8、JavaScript类数组对象的定义？

一个拥有 length 属性和若干索引属性的对象就可以被称为类数组对象，类数组对象和数组类似，但是不能调用数组的方法。常见的类数组对象有 arguments 和 DOM 方法的返回结果，还有一个函数也可以被看作是类数组对象，因为它含有 length 属性值，代表可接收的参数个数。

##### 9、数组有哪些原生方法？

数组和字符串的转换方法：toString()、toLocalString()、join() 其中 join() 方法可以指定转换为字符串时的分隔符。

数组尾部操作的方法 pop() 和 push()，push 方法可以传入多个参数。

数组首部操作的方法 shift() 和 unshift() 重排序的方法 reverse() 和 sort()，sort() 方法可以传入一个函数来进行比较，传入前后两个值，如果返回值为正数，则交换两个参数的位置。

数组连接的方法 concat() ，返回的是拼接好的数组，不影响原数组。

数组截取办法 slice()，用于截取数组中的一部分返回，不影响原数组。

数组插入方法 splice()，影响原数组查找特定项的索引的方法，indexOf() 和 lastIndexOf() 迭代方法 every()、some()、filter()、map() 和 forEach() 方法

数组归并方法 reduce() 和 reduceRight() 方法

##### 10、Unicode、UTF-8、UTF-16、UTF-32的区别？

##### 11、常见的位运算符有哪些？计算规则？

##### 12、为什么函数的arguments参数是类数组而不是数组？如何遍历类数组？

arguments是一个对象，它的属性是从 0 开始依次递增的数字，还有callee和length等属性，与数组相似；但是它却没有数组常见的方法属性，如forEach, reduce等，所以叫它们类数组。

要遍历类数组，有三个方法：

将数组的方法应用到类数组上，这时候就可以使用call和apply方法，如：

function foo(){ 
  Array.prototype.forEach.call(arguments, a => console.log(a))
}

使用Array.from方法将类数组转化成数组：‌

function foo(){ 
  const arrArgs = Array.from(arguments) 
  arrArgs.forEach(a => console.log(a))
}

使用展开运算符将类数组转化成数组

function foo(){ 
    const arrArgs = [...arguments] 
    arrArgs.forEach(a => console.log(a)) 
}

##### 13、什么是DOM和BOM？

DOM 指的是文档对象模型，它指的是把文档当做一个对象，这个对象主要定义了处理网页内容的方法和接口。
BOM 指的是浏览器对象模型，它指的是把浏览器当做一个对象来对待，这个对象主要定义了与浏览器进行交互的法和接口。BOM的核心是 window，而 window 对象具有双重角色，它既是通过 js 访问浏览器窗口的一个接口，又是一个 Global（全局）对象。这意味着在网页中定义的任何对象，变量和函数，都作为全局对象的一个属性或者方法存在。window 对象含有 location 对象、navigator 对象、screen 对象等子对象，并且 DOM 的最根本的对象 document 对象也是 BOM 的 window 对象的子对象。

##### 14、对类数组对象的理解，如何转化为数组？

一个拥有 length 属性和若干索引属性的对象就可以被称为类数组对象，类数组对象和数组类似，但是不能调用数组的方法。常见的类数组对象有 arguments 和 DOM 方法的返回结果，函数参数也可以被看作是类数组对象，因为它含有 length属性值，代表可接收的参数个数。

常见的类数组转换为数组的方法有这样几种：

通过 call 调用数组的 slice 方法来实现转换：Array.prototype.slice.call(arrayLike);

。

。

。

。

##### 16、对AJAX的理解，实现一个AJAX 请求

AJAX是 Asynchronous JavaScript and XML 的缩写，指的是通过 JavaScript 的 异步通信，从服务器获取 XML 文档从中提取数据，再更新当前网页的对应部分，而不用刷新整个网页。

创建AJAX请求的步骤：

创建一个 XMLHttpRequest 对象。
在这个对象上使用 open 方法创建一个 HTTP 请求，open 方法所需要的参数是请求的方法、请求的地址、是否异步和用户的认证信息。
在发起请求前，可以为这个对象添加一些信息和监听函数。比如说可以通过 setRequestHeader 方法来为请求添加头信息。还可以为这个对象添加一个状态监听函数。一个 XMLHttpRequest 对象一共有 5 个状态，当它的状态变化时会触发onreadystatechange 事件，可以通过设置监听函数，来处理请求成功后的结果。当对象的 readyState 变为 4 的时候，代表服务器返回的数据接收完成，这个时候可以通过判断请求的状态，如果状态是 2xx 或者 304 的话则代表返回正常。这个时候就可以通过 response 中的数据来对页面进行更新了。
当对象的属性和监听函数设置完成后，最后调用 sent 方法来向服务器发起请求，可以传入参数作为发送的数据体。

##### 17、JavaScript为什么要进行变量提升，它导致了什么问题？

变量提升的表现是，无论在函数中何处位置声明的变量，好像都被提升到了函数的首部，可以在变量声明前访问到而不会报错。



造成变量声明提升的本质原因是 js 引擎在代码执行前有一个解析的过程，创建了执行上下文，初始化了一些代码执行时需要用到的对象。当访问一个变量时，会到当前执行上下文中的作用域链中去查找，而作用域链的首端指向的是当前执行上下文的变量对象，这个变量对象是执行上下文的一个属性，它包含了函数的形参、所有的函数和变量声明，这个对象的是在代码解析的时候创建的。

##### 18、什么是尾调用，使用尾调用有什么好处？

尾调用指的是函数的最后一步调用另一个函数。代码执行是基于执行栈的，所以当在一个函数里调用另一个函数时，会保留当前的执行上下文，然后再新建另外一个执行上下文加入栈中。使用尾调用的话，因为已经是函数的最后一步，所以这时可以不必再保留当前的执行上下文，从而节省了内存，这就是尾调用优化。但是 ES6 的尾调用优化只在严格模式下开启，正常模式是无效的。

##### 19、ES6模块与CommonJS模块有什么异同？

ES6 Module和CommonJS模块的区别：

CommonJS是对模块的浅拷⻉，ES6 Module是对模块的引⽤，即ES6 Module只存只读，不能改变其值，也就是指针指向不能变，类似const；
import的接⼝是read-only（只读状态），不能修改其变量值。 即不能修改其变量的指针指向，但可以改变变量内部指针指向，可以对commonJS对重新赋值（改变指针指向），但是对ES6 Module赋值会编译报错。

ES6 Module和CommonJS模块的共同点：

CommonJS和ES6 Module都可以对引⼊的对象进⾏赋值，即对对象内部属性的值进⾏改变。

##### 20、常见的DOM操作有哪些？

1、DOM节点的获取

getElementById // 按照 id 查询
getElementsByTagName // 按照标签名查询
getElementsByClassName // 按照类名查询
querySelectorAll // 按照 css 选择器查询

2、DOM节点的创建  appendChild

3、DOM节点的删除 

// 获取目标元素的父元素
var container = document.getElementById('container')
// 获取目标元素
var targetNode = document.getElementById('title')
// 删除目标元素
container.removeChild(targetNode)

// 获取目标元素的父元素var container = document.getElementById('container')// 获取目标元素var targetNode = container.childNodes[1]// 删除目标元素container.removeChild(targetNode)

4、修改DOM元素  调换位置 insertBefore 或 appendChild

// 获取父元素
var container = document.getElementById('container')   

// 获取两个需要被交换的元素
var title = document.getElementById('title')
var content = document.getElementById('content')
// 交换两个元素，把 content 置于 title 前面
container.insertBefore(content, title)

##### 21、use strict是什么意思？使用它的区别？

use strict 是一种 ECMAscript5 添加的（严格模式）运行模式，这种模式使得 Javascript 在更严格的条件下运行。设立严格模式的目的如下：

消除 Javascript 语法的不合理、不严谨之处，减少怪异行为;
消除代码运行的不安全之处，保证代码运行的安全；
提高编译器效率，增加运行速度；
为未来新版本的 Javascript 做好铺垫。

区别：

禁止使用 with 语句。
禁止 this 关键字指向全局对象。
对象不能有重名的属性。

##### 22、如何判断一个对象是否属于一个类？

##### 23、强类型语言和弱类型语言的区别

强类型语言：强类型语言也称为强类型定义语言，是一种总是强制类型定义的语言，要求变量的使用要严格符合定义，所有变量都必须先定义后使用。Java和C++等语言都是强制类型定义的，也就是说，一旦一个变量被指定了某个数据类型，如果不经过强制转换，那么它就永远是这个数据类型了。例如你有一个整数，如果不显式地进行转换，你不能将其视为一个字符串。
弱类型语言：弱类型语言也称为弱类型定义语言，与强类型定义相反。JavaScript语言就属于弱类型语言。简单理解就是一种变量类型可以被忽略的语言。比如JavaScript是弱类型定义的，在JavaScript中就可以将字符串'12'和整数3进行连接得到字符串'123'，在相加的时候会进行强制类型转换。

两者对比：强类型语言在速度上可能略逊色于弱类型语言，但是强类型语言带来的严谨性可以有效地帮助避免许多错误。

##### 24、解释性语言和编译型语言的区别？

##### 25、for ...in 和 for...of的区别

for…of 遍历获取的是对象的键值，for…in 获取的是对象的键名；
for… in 会遍历对象的整个原型链，性能非常差不推荐使用，而 for … of 只遍历当前对象不会遍历原型链；
对于数组的遍历，for…in 会返回数组中所有可枚举的属性(包括原型链上可枚举的属性)，for…of 只返回数组的下标对应的属性值；

##### 26、如何使用for...of遍历对象

for…of是作为ES6新增的遍历方式，允许遍历一个含有iterator接口的数据结构（数组、对象等）并且返回各项的值，普通的对象用for..of遍历是会报错的。

如果需要遍历的对象是类数组对象，用Array.from转成数组即可。

如果不是类数组对象，就给对象添加一个[Symbol.iterator]属性，并指向一个迭代器即可。

##### 27、Ajax、axios、fetch的区别

##### 28、数组的遍历方法有哪些？

foreach、map、filter、for...of 、every、some、find、findIndex、reduce、reduceRight;

##### 29、forEach和map的区别？

forEach()方法会针对每一个元素执行提供的函数，对数据的操作会改变原数组，该方法没有返回值；
map()方法不会改变原数组的值，返回一个新数组，新数组中的值为原数组调用函数处理之后的值；

#### 原型与原型链



#### 执行上下文/作用域链/闭包

































