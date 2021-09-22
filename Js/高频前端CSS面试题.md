# 高频前端CSS面试题

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/3f63fdc5979647e09bbde92d964a9656~tplv-k3u1fbpfcp-watermark.awebp)

#### CSS基础

##### 1、CSS选择器及其优先级

![image-20210826094027741](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210826094027741.png)

注意事项：

!important声明的样式的优先级最高；
如果优先级相同，则最后出现的样式生效；
继承得到的样式的优先级最低；
通用选择器（*）、子选择器（>）和相邻同胞选择器（+）并不在这四个等级中，所以它们的权值都为 0 ；
样式表的来源不同时，优先级顺序为：内联样式 > 内部样式 > 外部样式 > 浏览器用户自定义样式 > 浏览器默认样式。

##### 2、CSS中可继承与不可继承属性有哪些

无继承性的属性：

display：规定元素应该生成的框的类型
文本属性：


vertical-align：垂直文本对齐
text-decoration：规定添加到文本的装饰
text-shadow：文本阴影效果
white-space：空白符的处理
unicode-bidi：设置文本的方向

盒子模型的属性：width、height、margin、border、padding
背景属性：background、background-color、background-image、background-repeat、background-position、background-attachment
定位属性：float、clear、position、top、right、bottom、left、min-width、min-height、max-width、max-height、overflow、clip、z-index
生成内容属性：content、counter-reset、counter-increment
轮廓样式属性：outline-style、outline-width、outline-color、outline
页面样式属性：size、page-break-before、page-break-after
声音样式属性：pause-before、pause-after、pause、cue-before、cue-after、cue、play-during

有继承性的属性：

字体系列属性

font-family：字体系列
font-weight：字体的粗细
font-size：字体的大小
font-style：字体的风格


文本系列属性

text-indent：文本缩进
text-align：文本水平对齐
line-height：行高
word-spacing：单词之间的间距
letter-spacing：中文或者字母之间的间距
text-transform：控制文本大小写（就是uppercase、lowercase、capitalize这三个）
color：文本颜色


元素可见性


visibility：控制元素显示隐藏


列表布局属性


list-style：列表风格，包括list-style-type、list-style-image等


光标属性


cursor：光标显示为何种形态

##### 3、display的属性值及其作用

![image-20210826094527147](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210826094527147.png)

##### 4、display的block、inline和inline-block的区别

（1）block： 会独占一行，多个元素会另起一行，可以设置width、height、margin和padding属性；
（2）inline： 元素不会独占一行，设置width、height属性无效。但可以设置水平方向的margin和padding属性，不能设置垂直方向的padding和margin；
（3）inline-block： 将对象设置为inline对象，但对象的内容作为block对象呈现，之后的内联对象会被排列在同一行内。
对于行内元素和块级元素，其特点如下：
（1）行内元素

设置宽高无效；
可以设置水平方向的margin和padding属性，不能设置垂直方向的padding和margin；
不会自动换行；

（2）块级元素

可以设置宽高；
设置margin和padding都有效；
可以自动换行；
多个块状，默认排列从上到下

##### 5、隐藏元素的方法

display: none：渲染树不会包含该渲染对象，因此该元素不会在页面中占据位置，也不会响应绑定的监听事件。
visibility: hidden：元素在页面中仍占据空间，但是不会响应绑定的监听事件。
opacity: 0：将元素的透明度设置为 0，以此来实现元素的隐藏。元素在页面中仍然占据空间，并且能够响应元素绑定的监听事件。
position: absolute：通过使用绝对定位将元素移除可视区域内，以此来实现元素的隐藏。
z-index: 负值：来使其他元素遮盖住该元素，以此来实现隐藏。
clip/clip-path ：使用元素裁剪的方法来实现元素的隐藏，这种方法下，元素仍在页面中占据位置，但是不会响应绑定的监听事件。
transform: scale(0,0)：将元素缩放为 0，来实现元素的隐藏。这种方法下，元素仍在页面中占据位置，但是不会响应绑定的监听事件。

##### 6、link和@import的区别

两者都是外部引用CSS的方式，它们的区别如下：

link是XHTML标签，除了加载CSS外，还可以定义RSS等其他事务；@import属于CSS范畴，只能加载CSS。
link引用CSS时，在页面载入时同时加载；@import需要页面网页完全载入以后加载。
link是XHTML标签，无兼容问题；@import是在CSS2.1提出的，低版本的浏览器不支持。
link支持使用Javascript控制DOM去改变样式；而@import不支持。

##### 7、transition和animation的区别

transition是过度属性，强调过度，它的实现需要触发一个事件（比如鼠标移动上去，焦点，点击等）才执行动画。它类似于flash的补间动画，设置一个开始关键帧，一个结束关键帧。
animation是动画属性，它的实现不需要触发事件，设定好时间之后可以自己执行，且可以循环一个动画。它也类似于flash的补间动画，但是它可以设置多个关键帧（用@keyframe定义）完成动画。

##### 8、display:none与visibility:hidden的区别

（1）在渲染树中

display:none会让元素完全从渲染树中消失，渲染时不会占据任何空间；
visibility:hidden不会让元素从渲染树中消失，渲染的元素还会占据相应的空间，只是内容不可见。

（2）是否是继承属性

display:none是非继承属性，子孙节点会随着父节点从渲染树消失，通过修改子孙节点的属性也无法显示；
visibility:hidden是继承属性，子孙节点消失是由于继承了hidden，通过设置visibility:visible可以让子孙节点显示；

（3）修改常规文档流中元素的 display 通常会造成文档的重排，但是修改visibility属性只会造成本元素的重绘；
（4）如果使用读屏器，设置为display:none的内容不会被读取，设置为visibility:hidden的内容会被读取。

##### 9、伪元素与伪类的区别和作用？

伪元素：在内容元素的前后插入额外的元素或样式，但是这些元素实际上并不在文档中生成。它们只在外部显示可见，但不会在文档的源代码中找到它们，因此，称为“伪”元素。

伪类：将特殊的效果添加到特定选择器上。它是已有元素上添加类别的，不会产生新的元素。

伪类是通过在元素选择器上加⼊伪类改变元素状态，⽽伪元素通过对元素的操作进⾏对元素的改变。

##### 10、对requestAnimationframe的理解

window.requestAnimationFrame() 告诉浏览器——你希望执行一个动画，并且要求浏览器在下次重绘之前调用指定的回调函数更新动画。该方法需要传入一个回调函数作为参数，该回调函数会在浏览器下一次重绘之前执行。

取消动画： 使用cancelAnimationFrame()来取消执行动画，该方法接收一个参数——requestAnimationFrame默认返回的id，只需要传入这个id就可以取消动画了。

优势：

CPU节能：使用SetTinterval 实现的动画，当页面被隐藏或最小化时，SetTinterval 仍然在后台执行动画任务，由于此时页面处于不可见或不可用状态，刷新动画是没有意义的，完全是浪费CPU资源。而RequestAnimationFrame则完全不同，当页面处理未激活的状态下，该页面的屏幕刷新任务也会被系统暂停，因此跟着系统走的RequestAnimationFrame也会停止渲染，当页面被激活时，动画就从上次停留的地方继续执行，有效节省了CPU开销。
函数节流：在高频率事件( resize, scroll 等)中，为了防止在一个刷新间隔内发生多次函数执行，RequestAnimationFrame可保证每个刷新间隔内，函数只被执行一次，这样既能保证流畅性，也能更好的节省函数执行的开销，一个刷新间隔内函数执行多次时没有意义的，因为多数显示器每16.7ms刷新一次，多次绘制并不会在屏幕上体现出来。
减少DOM操作：requestAnimationFrame 会把每一帧中的所有DOM操作集中起来，在一次重绘或回流中就完成，并且重绘或回流的时间间隔紧紧跟随浏览器的刷新频率，一般来说，这个频率为每秒60帧。

setTimeout执行动画的缺点：它通过设定间隔时间来不断改变图像位置，达到动画效果。但是容易出现卡顿、抖动的现象；原因是：

settimeout任务被放入异步队列，只有当主线程任务执行完后才会执行队列中的任务，因此实际执行时间总是比设定时间要晚；
settimeout的固定时间间隔不一定与屏幕刷新间隔时间相同，会引起丢帧。

##### 11、对盒模型的理解

CSS3中的盒模型有以下两种：标准盒子模型、IE盒子模型 

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/4544d45b5a0c47a58c0c33a7d8fbac09~tplv-k3u1fbpfcp-watermark.awebp)



![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/4040de9fef1a49f4ae0ae66039edcfe0~tplv-k3u1fbpfcp-watermark.awebp)



盒模型都是由四个部分组成的，分别是margin、border、padding和content

标准盒模型和IE盒模型的区别在于设置width和height时，所对应的范围不同：

标准盒模型的width和height属性的范围只包含了content，
IE盒模型的width和height属性的范围包含了border、padding和content。

可以通过修改元素的box-sizing属性来改变元素的盒模型：

box-sizeing: content-box表示标准盒模型（默认值）
box-sizeing: border-box表示IE盒模型（怪异盒模型）



##### 12、为什么有时候用translate来改变位置而不是定位？

translate 是 transform 属性的⼀个值。改变transform或opacity不会触发浏览器重新布局（reflow）或重绘（repaint），只会触发复合（compositions）。⽽改变绝对定位会触发重新布局，进⽽触发重绘和复合。transform使浏览器为元素创建⼀个 GPU 图层，但改变绝对定位会使⽤到 CPU。 因此translate()更⾼效，可以缩短平滑动画的绘制时间。 ⽽translate改变位置时，元素依然会占据其原始空间，绝对定位就不会发⽣这种情况。

##### 13、li和li之间有看不见的空白间隔是什么原因引起的？如何解决？

浏览器会把inline内联元素间的空白字符（空格、换行、Tab等）渲染成一个空格。为了美观，通常是一个<li>放在一行，这导致<li>换行后产生换行字符，它变成一个空格，占用了一个字符的宽度。
解决办法：
（1）为<li>设置float:left。不足：有些容器是不能设置浮动，如左右切换的焦点图等。
（2）将所有<li>写在同一行。不足：代码不美观。
（3）将<ul>内的字符尺寸直接设为0，即font-size:0。不足：<ul>中的其他字符尺寸也被设为0，需要额外重新设定其他字符尺寸，且在Safari浏览器依然会出现空白间隔。
（4）消除<ul>的字符间隔letter-spacing:-8px，不足：这也设置了<li>内的字符间隔，因此需要将<li>内的字符间隔设为默认letter-spacing:normal。

##### 14、CSS3中有哪些新特性？

新增各种CSS选择器 （: not(.input)：所有 class 不是“input”的节点）
圆角 （border-radius:8px）
多列布局 （multi-column layout）
阴影和反射 （Shadoweflect）
文字特效 （text-shadow）
文字渲染 （Text-decoration）
线性渐变 （gradient）
旋转 （transform）
增加了旋转,缩放,定位,倾斜,动画,多背景

##### 15、替换元素的概念及计算规则

通过修改某个属性值呈现的内容就可以被替换的元素就称为“替换元素”。

##### 16、常见的图片格式及使用场景

##### 17、对CSS Sprites的理解

CSSSprites（精灵图），将一个页面涉及到的所有图片都包含到一张大图中去，然后利用CSS的 background-image，background-repeat，background-position属性的组合进行背景定位。

优点：

利用CSS Sprites能很好地减少网页的http请求，从而大大提高了页面的性能，这是CSS Sprites最大的优点；
CSS Sprites能减少图片的字节，把3张图片合并成1张图片的字节总是小于这3张图片的字节总和。

缺点：

在图片合并时，要把多张图片有序的、合理的合并成一张图片，还要留好足够的空间，防止板块内出现不必要的背景。在宽屏及高分辨率下的自适应页面，如果背景不够宽，很容易出现背景断裂；
CSSSprites在开发的时候相对来说有点麻烦，需要借助photoshop或其他工具来对每个背景单元测量其准确的位置。
维护方面：CSS Sprites在维护的时候比较麻烦，页面背景有少许改动时，就要改这张合并的图片，无需改的地方尽量不要动，这样避免改动更多的CSS，如果在原来的地方放不下，又只能（最好）往下加图片，这样图片的字节就增加了，还要改动CSS

##### 18、什么是物理像素，逻辑像素和像素密度，为什么在移动端开发时需要用到@3x，@2x这种图片？

可以针对所有屏幕，都只提供最高清图片。虽然低密度屏幕用不到那么多图片像素，而且会因为下载多余的像素造成带宽浪费和下载延迟，但从结果上说能保证图片在所有屏幕上都不会失真。

还可以使用 CSS 媒体查询来判断不同的像素密度，从而选择不同的图片

my-image { background: (low.png); }
@media only screen and (min-device-pixel-ratio: 1.5) {
  #my-image { background: (high.png); }
}

##### 19、margin和padding的使用场景

需要在border外侧添加空白，且空白处不需要背景（色）时，使用 margin；
需要在border内测添加空白，且空白处需要背景（色）时，使用 padding。

##### 20、对line-height的理解及其赋值方式

line-height 指一行文本的高度，包含了字间距，实际上是下一行基线到上一行基线距离；

如果一个标签没有定义 height 属性，那么其最终表现的高度由 line-height 决定；

一个容器没有设置高度，那么撑开容器高度的是 line-height，而不是容器内的文本内容；

把 line-height 值设置为 height 一样大小的值可以实现单行文字的垂直居中；

line-height 和 height 都能撑开一个高度；

带单位：px 是固定值，而 em 会参考父元素 font-size 值计算自身的行高
纯数字：会把比例传递给后代。例如，父级行高为 1.5，子元素字体为 18px，则子元素行高为 1.5 * 18 = 27px
百分比：将计算后的值传递给后代

##### 21、CSS优化和提高性能的方法有哪些？

加载性能：
（1）css压缩：将写好的css进行打包压缩，可以减小文件体积。
（2）css单一样式：当需要下边距和左边距的时候，很多时候会选择使用 margin:top 0 bottom 0；但margin-bottom:bottom;margin-left:left;执行效率会更高。
（3）减少使用@import，建议使用link，因为后者在页面加载时一起加载，前者是等待页面加载完成之后再进行加载。

选择器性能：
（1）关键选择器（key selector）。选择器的最后面的部分为关键选择器（即用来匹配目标元素的部分）。CSS选择符是从右到左进行匹配的。当使用后代选择器的时候，浏览器会遍历所有子元素来确定是否是指定的元素等等；
（2）如果规则拥有ID选择器作为其关键选择器，则不要为规则增加标签。过滤掉无关的规则（这样样式系统就不会浪费时间去匹配它们了）。
（3）避免使用通配规则，如*{}计算次数惊人，只对需要用到的元素进行选择。
（4）尽量少的去对标签进行选择，而是用class。
（5）尽量少的去使用后代选择器，降低选择器的权重值。后代选择器的开销是最高的，尽量将选择器的深度降到最低，最高不要超过三层，更多的使用类来关联每一个标签元素。
（6）了解哪些属性是可以通过继承而来的，然后避免对这些属性重复指定规则。

渲染性能：
（1）慎重使用高性能属性：浮动、定位。
（2）尽量减少页面重排、重绘。
（3）去除空规则：｛｝。空规则的产生原因一般来说是为了预留样式。去除这些空规则无疑能减少css文档体积。
（4）属性值为0时，不加单位。
（5）属性值为浮动小数0.**，可以省略小数点之前的0。
（6）标准化各种浏览器前缀：带浏览器前缀的在前。标准属性在后。
（7）不使用@import前缀，它会影响css的加载速度。
（8）选择器优化嵌套，尽量避免层级过深。
（9）css雪碧图，同一页面相近部分的小图标，方便使用，减少页面的请求次数，但是同时图片本身会变大，使用时，优劣考虑清楚，再使用。
（10）正确使用display的属性，由于display的作用，某些样式组合会无效，徒增样式体积的同时也影响解析性能。
（11）不滥用web字体。对于中文网站来说WebFonts可能很陌生，国外却很流行。web fonts通常体积庞大，而且一些浏览器在下载web fonts时会阻塞页面渲染损伤性能。

可维护性、健壮性：

（1）将具有相同属性的样式抽离出来，整合并通过class在页面中进行使用，提高css的可维护性。

（2）样式与内容分离：将css代码定义到外部css中。

##### 22、CSS预处理器/后处理器是什么？为什么要使用它们？

预处理器， 如：less，sass，stylus，用来预编译sass或者less，增加了css代码的复用性。层级，mixin， 变量，循环， 函数等对编写以及开发UI组件都极为方便。
后处理器， 如： postCss，通常是在完成的样式表中根据css规范处理css，让其更加有效。目前最常做的是给css属性添加浏览器私有前缀，实现跨浏览器兼容性的问题。

css预处理器为css增加一些编程特性，无需考虑浏览器的兼容问题，可以在CSS中使用变量，简单的逻辑程序，函数等在编程语言中的一些基本的性能，可以让css更加的简洁，增加适应性以及可读性，可维护性等。

使用原因：

结构清晰， 便于扩展
可以很方便的屏蔽浏览器私有语法的差异
可以轻松实现多重继承
完美的兼容了CSS代码，可以应用到老项目中

##### 23、::before和:after的双冒号和单冒号的区别？

冒号(:)用于CSS3伪类，双冒号(::)用于CSS3伪元素。 （2）::before就是以一个子元素的存在，定义在元素主体内容之前的一个伪元素。并不存在于dom之中，只存在在页面之中。

##### 24、display:inline-block什么时候会显示间隙？

有空格时会有间隙，可以删除空格解决；
margin正值时，可以让margin使用负值解决；
使用font-size时，可通过设置font-size:0、letter-spacing、word-spacing解决；

##### 25、单行、多行文本溢出隐藏

单行

overflow: hidden;            // 溢出隐藏
text-overflow: ellipsis;      // 溢出用省略号显示
white-space: nowrap;         // 规定段落中的文本不进行换行

多行

overflow: hidden;            // 溢出隐藏
text-overflow: ellipsis;     // 溢出用省略号显示
display:-webkit-box;         // 作为弹性伸缩盒子模型显示。
-webkit-box-orient:vertical; // 设置伸缩盒子的子元素排列方式：从上到下垂直排列
-webkit-line-clamp:3;        // 显示的行数

##### 26、Sass、Less是什么？

##### 27、对媒体查询的理解？

媒体查询由⼀个可选的媒体类型和零个或多个使⽤媒体功能的限制了样式表范围的表达式组成，例如宽度、⾼度和颜⾊。媒体查询，添加⾃CSS3，允许内容的呈现针对⼀个特定范围的输出设备⽽进⾏裁剪，⽽不必改变内容本身，适合web⽹⻚应对不同型号的设备⽽做出对应的响应适配。

简单来说，使用 @media 查询，可以针对不同的媒体类型定义不同的样式。@media 可以针对不同的屏幕尺寸设置不同的样式，特别是需要设置设计响应式的页面，@media 是非常有用的。当重置浏览器大小的过程中，页面也会根据浏览器的宽度和高度重新渲染页面。

##### 28、对CSS工程化的理解？

CSS 工程化是为了解决以下问题：

宏观设计：CSS 代码如何组织、如何拆分、模块结构怎样设计？
编码优化：怎样写出更好的 CSS？
构建：如何处理我的 CSS，才能让它的打包结果最优？
可维护性：代码写完了，如何最小化它后续的变更成本？如何确保任何一个同事都能轻松接手？

以下三个方向都是时下比较流行的、普适性非常好的 CSS 工程化实践：

预处理器：Less、 Sass 等；
重要的工程化插件： PostCss；
Webpack loader 等 。

##### 29、如何判断元素是否到达可视区域

window.innerHeight 是浏览器可视区的高度；
document.body.scrollTop || document.documentElement.scrollTop 是浏览器滚动的过的距离；
imgs.offsetTop 是元素顶部距离文档顶部的高度（包括滚动条的距离）；
内容达到显示区域的：img.offsetTop < window.innerHeight + document.body.scrollTop;

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/c57fc165a4ce4d5b9a2885867d4f1cab~tplv-k3u1fbpfcp-watermark.awebp)

##### 30、z-index属性在什么情况下会失效？

通常 z-index 的使用是在有两个重叠的标签，在一定的情况下控制其中一个在另一个的上方或者下方出现。z-index值越大就越是在上层。z-index元素的position属性需要是relative，absolute或是fixed。

z-index属性在下列情况下会失效：

父元素position为relative时，子元素的z-index失效。解决：父元素position改为absolute或static；
元素没有设置position属性为非static属性。解决：设置该元素的position属性为relative，absolute或是fixed中的一种；
元素在设置z-index的同时还设置了float浮动。解决：float去除，改为display：inline-block；

##### 31、CSS3中的transform有哪些属性？



#### 页面布局

##### 1、常见的CSS布局单位

常用的布局单位包括像素（px），百分比（%），em，rem，vw/vh。

##### 2、px、em和rem的区别与使用场景？

##### 3、两栏布局实现

一般两栏布局指的是左边一栏宽度固定，右边一栏宽度自适应。

##### 4、三栏布局的实现

三栏布局一般指的是页面中一共有三栏，左右两栏宽度固定，中间自适应的布局。

##### 5、水平垂直居中的实现

##### 6、如何根据设计稿进行移动端适配？

移动端适配主要有两个维度：

适配不同像素密度， 针对不同的像素密度，使用 CSS 媒体查询，选择不同精度的图片，以保证图片不会失真；
适配不同屏幕大小， 由于不同的屏幕有着不同的逻辑像素大小，所以如果直接使用 px 作为开发单位，会使得开发的页面在某一款手机上可以准确显示，但是在另一款手机上就会失真。为了适配不同屏幕的大小，应按照比例来还原设计稿的内容。

为了能让页面的尺寸自适应，可以使用 rem，em，vw，vh 等相对单位。

##### 7、对Flex布局的理解及其使用场景

弹性布局

采用Flex布局的元素，称为Flex容器（flex container），简称"容器"。它的所有子元素自动成为容器成员，称为Flex项目（flex item），简称"项目"。容器默认存在两根轴：水平的主轴（main axis）和垂直的交叉轴（cross axis），项目默认沿水平主轴排列。

以下6个属性设置在容器上：

flex-direction属性决定主轴的方向（即项目的排列方向）。
flex-wrap属性定义，如果一条轴线排不下，如何换行。
flex-flow属性是flex-direction属性和flex-wrap属性的简写形式，默认值为row nowrap。
justify-content属性定义了项目在主轴上的对齐方式。
align-items属性定义项目在交叉轴上如何对齐。
align-content属性定义了多根轴线的对齐方式。如果项目只有一根轴线，该属性不起作用。

以下6个属性设置在项目上：

order属性定义项目的排列顺序。数值越小，排列越靠前，默认为0。
flex-grow属性定义项目的放大比例，默认为0，即如果存在剩余空间，也不放大。
flex-shrink属性定义了项目的缩小比例，默认为1，即如果空间不足，该项目将缩小。
flex-basis属性定义了在分配多余空间之前，项目占据的主轴空间。浏览器根据这个属性，计算主轴是否有多余空间。它的默认值为auto，即项目的本来大小。
flex属性是flex-grow，flex-shrink和flex-basis的简写，默认值为0 1 auto。
align-self属性允许单个项目有与其他项目不一样的对齐方式，可覆盖align-items属性。默认值为auto，表示继承父元素的align-items属性，如果没有父元素，则等同于stretch。



##### 8、响应式设计的概念及基本原理

响应式网站设计（Responsive Web design）是一个网站能够兼容多个终端，而不是为每一个终端做一个特定的版本。
关于原理： 基本原理是通过媒体查询（@media）查询检测不同的设备屏幕尺寸做处理。
关于兼容： 页面头部必须有mate声明的viewport。

<meta name="’viewport’" content="”width=device-width," initial-scale="1." maximum-scale="1,user-scalable=no”"/>

#### 三、定位与浮动

##### 1、为什么需要清除浮动？清除浮动的方式。

浮动的定义： 非IE浏览器下，容器不设高度且子元素浮动时，容器高度不能被内容撑开。 此时，内容会溢出到容器外面而影响布局。这种现象被称为浮动（溢出）。

浮动的工作原理：

浮动元素脱离文档流，不占据空间（引起“高度塌陷”现象）
浮动元素碰到包含它的边框或者其他浮动元素的边框停留



清除浮动的方式如下：

给父级div定义height属性
最后一个浮动元素之后添加一个空的div标签，并添加clear:both样式
包含浮动元素的父级标签添加overflow:hidden或者overflow:auto
使用 :after 伪元素。由于IE6-7不支持 :after，使用 zoom:1 触发 hasLayout**

##### 2、使用clear属性清除浮动的原理？

官方对clear属性解释：“元素盒子的边不能和前面的浮动元素相邻”，对元素设置clear属性是为了避免浮动元素对该元素的影响，而不是清除掉浮动。

一般使用伪元素的方式清除浮动：

.clear::after{  content:'';  display: block;   clear:both;}

clear属性只有块级元素才有效的，而::after等伪元素默认都是内联水平，这就是借助伪元素清除浮动影响时需要设置display属性值的原因。

##### 3、对BFC的理解，如何创建BFC

块格式化上下文

通俗来讲：BFC是一个独立的布局环境，可以理解为一个容器，在这个容器中按照一定规则进行物品摆放，并且不会影响其它环境中的物品。如果一个元素符合触发BFC的条件，则BFC中的元素布局不受外部影响。

创建BFC的条件：

根元素：body；
元素设置浮动：float 除 none 以外的值；
元素设置绝对定位：position (absolute、fixed)；
display 值为：inline-block、table-cell、table-caption、flex等；
overflow 值为：hidden、auto、scroll

BFC的特点：

垂直方向上，自上而下排列，和文档流的排列方式一致。
在BFC中上下相邻的两个容器的margin会重叠
计算BFC的高度时，需要计算浮动元素的高度
BFC区域不会与浮动的容器发生重叠
BFC是独立的容器，容器内部元素不会影响外部元素
每个元素的左margin值和容器的左border相接触



BFC的作用：

解决margin的重叠问题：由于BFC是一个独立的区域，内部的元素和外部的元素互不影响，将两个元素变为两个BFC，就解决了margin重叠的问题。
解决高度塌陷的问题：在对子元素设置浮动后，父元素会发生高度塌陷，也就是父元素的高度变为0。解决这个问题，只需要把父元素变成一个BFC。常用的办法是给父元素设置overflow:hidden。
创建自适应两栏布局：可以用来创建自适应两栏布局：左边的宽度固定，右边的宽度自适应。



##### 4、什么是margin重叠问题？如何解决？

问题描述： 两个块级元素的上外边距和下外边距可能会合并（折叠）为一个外边距，其大小会取其中外边距值大的那个，这种行为就是外边距折叠。需要注意的是，浮动的元素和绝对定位这种脱离文档流的元素的外边距不会折叠。重叠只会出现在垂直方向。

计算原则： 折叠合并后外边距的计算原则如下：

如果两者都是正数，那么就去最大者
如果是一正一负，就会正值减去负值的绝对值
两个都是负值时，用0减去两个中绝对值大的那个

解决办法：
对于折叠的情况，主要有两种：兄弟之间重叠和父子之间重叠
（1）兄弟之间重叠

底部元素变为行内盒子：display: inline-block
底部元素设置浮动：float
底部元素的position的值为absolute/fixed

（2）父子之间重叠

父元素加入：overflow: hidden
父元素添加透明边框：border:1px solid transparent
子元素变为行内盒子：display: inline-block
子元素加入浮动属性或定位



##### 5、元素的层叠顺序

层叠顺序，英文称作 stacking order，表示元素发生层叠时有着特定的垂直显示顺序。下面是盒模型的层叠规则： 

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/fbc59ae1adb5454c8c7f60582df10ff9~tplv-k3u1fbpfcp-watermark.awebp)

上图，由上到下分别是：
（1）背景和边框：建立当前层叠上下文元素的背景和边框。
（2）负的z-index：当前层叠上下文中，z-index属性值为负的元素。
（3）块级盒：文档流内非行内级非定位后代元素。
（4）浮动盒：非定位浮动元素。
（5）行内盒：文档流内行内级非定位后代元素。
（6）z-index:0：层叠级数为0的定位元素。
（7）正z-index：z-index属性值为正的定位元素。
注意: 当定位元素z-index:auto，生成盒在当前层叠上下文中的层级为 0，不会建立新的层叠上下文，除非是根元素。

##### 6、position的属性有哪些，区别是什么

relative： 元素的定位永远是相对于元素自身位置的，和其他元素没关系，也不会影响其他元素。

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/6523548b65834c578202acc5e6388af4~tplv-k3u1fbpfcp-watermark.awebp)

fixed： 元素的定位是相对于 window （或者 iframe）边界的，和其他元素没有关系。但是它具有破坏性，会导致其他元素位置的变化。

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/4b35e646aa3c4d9cac803753d8b67c39~tplv-k3u1fbpfcp-watermark.awebp)

absolute： 元素的定位相对于前两者要复杂许多。如果为 absolute 设置了 top、left，浏览器会根据什么去确定它的纵向和横向的偏移量呢？答案是浏览器会递归查找该元素的所有父元素，如果找到一个设置了position:relative/absolute/fixed的元素，就以该元素为基准定位，如果没找到，就以浏览器边界定位。如下两个图所示：

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/d6d4f199b3f842f090890eea32318e11~tplv-k3u1fbpfcp-watermark.awebp)

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/d2c7150bd7614a548f04a2919f1ea12a~tplv-k3u1fbpfcp-watermark.awebp)



##### 7、display、float、position的关系



##### 8、absolute与fixed共同点与不同点

共同点：

改变行内元素的呈现方式，将display置为inline-block  
使元素脱离普通文档流，不再占据文档物理空间
覆盖非定位文档元素

不同点：

abuselute与fixed的根元素不同，abuselute的根元素可以设置，fixed根元素是浏览器。
在有滚动条的页面中，absolute会跟着父元素进行移动，fixed固定在页面的具体位置。

##### 9、对sticky定位的理解

粘性定位，基于用户的滚动位置来定位；

粘性定位的元素是依赖于用户的滚动，在 position:relative 与 position:fixed 定位之间切换。它的行为就像 position:relative; 而当页面滚动超出目标区域时，它的表现就像 position:fixed;，它会固定在目标位置。元素定位表现为在跨越特定阈值前为相对定位，之后为固定定位。这个特定阈值指的是 top, right, bottom 或 left 之一，换言之，指定 top, right, bottom 或 left 四个阈值其中之一，才可使粘性定位生效。否则其行为与相对定位相同。

#### 场景应用

##### 1、实现一个三角形

border属性；

border-right: 50px solid red;

border-top: 50px solid transparent;

##### 2、实现一个扇形

div{
    border: 100px solid transparent;
    width: 0;
    heigt: 0;
    border-radius: 100px;
    border-top-color: red;
}

##### 3、实现一个宽高自适应的正方形



##### 4、画一条0.5px的线

采用transform: scale()的方式，该方法用来定义元素的2D 缩放转换：

transform: scale(0.5,0.5);

采用meta viewport的方式

<meta name="viewport" content="width=device-width, initial-scale=0.5, minimum-scale=0.5, maximum-scale=0.5"/>

这样就能缩放到原来的0.5倍，如果是1px那么就会变成0.5px。viewport只针对于移动端，只在移动端上才能看到效果。

##### 5、设置小于12px的字体

在谷歌下css设置字体大小为12px及以下时，显示都是一样大小，都是默认12px。

解决办法：

使用Webkit的内核的-webkit-text-size-adjust的私有CSS属性来解决，只要加了-webkit-text-size-adjust:none;字体大小就不受限制了。但是chrome更新到27版本之后就不可以用了。所以高版本chrome谷歌浏览器已经不再支持-webkit-text-size-adjust样式，所以要使用时候慎用。
使用css3的transform缩放属性-webkit-transform:scale(0.5); 注意-webkit-transform:scale(0.75);收缩的是整个元素的大小，这时候，如果是内联元素，必须要将内联元素转换成块元素，可以使用display：block/inline-block/...；
使用图片：如果是内容固定不变情况下，使用将小于12px文字内容切出做图片，这样不影响兼容也不影响美观。

##### 6、如何解决1px的问题？

1px 问题指的是：在一些 Retina屏幕 的机型上，移动端页面的 1px 会变得很粗，呈现出不止 1px 的效果。原因很简单——CSS 中的 1px 并不能和移动设备上的 1px 划等号。它们之间的比例关系有一个专门的属性来描述：
window.devicePixelRatio = 设备的物理像素 / CSS像素。

这就意味着设置的 1px CSS 像素，在这个设备上实际会用 2 个物理像素单元来进行渲染，所以实际看到的一定会比 1px 粗一些。

解决1px 问题的三种思路：

思路一：直接写 0.5px

思路二：伪元素先放大后缩小
这个方法的可行性会更高，兼容性也更好。唯一的缺点是代码会变多。

思路三：viewport 缩放来解决

<meta name="viewport" content="initial-scale=0.5, maximum-scale=0.5, minimum-scale=0.5, user-scalable=no">

这样解决了，但这样做的副作用也很大，整个页面被缩放了。这时 1px 已经被处理成物理像素大小，这样的大小在手机上显示边框很合适。但是，一些原本不需要被缩小的内容，比如文字、图片等，也被无差别缩小掉了。























