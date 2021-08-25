## 高频前端面试题

#### 一、HTML

![HTML面试题.png](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/a18f8caac72c44ccb29197298f65809e~tplv-k3u1fbpfcp-watermark.awebp)

1、src和href的区别；

src是对资源的引用，会将指定的资源下载并应用到文档内。

href是对超文本的引用，指向网络资源，建立和当前元素或文档的链接关系。

2、对HTML语义化的理解

语义化是指根据内容结构，选择合适的标签。

3、DOCTYPE(文档类型)的作用

4、script标签中的defer和async的区别；

<u>5、常用的meta标签；</u>

6、HTML5有哪些更新：

语义化标签、媒体标签、表单、进度条、度量器、DOM查询操作、web存储、拖放、画布、SVG、地理定位；

（1）新增语义化标签：nav、header、footer、aside、section、article
（2）音频、视频标签：audio、video
（3）数据存储：localStorage、sessionStorage
（4）canvas（画布）、Geolocation（地理定位）、websocket（通信协议）
（5）input标签新增属性：placeholder、autocomplete、autofocus、required
（6）history API：go、forward、back、pushstate

7、img的srcset属性的作用？

用于设置不同屏幕密度下，img会自动加载不同的图片。

8、行内元素有哪些？块级元素有哪些？空元素有哪些？

行内元素有：a b span img input select strong；
块级元素有：div ul ol li dl dt dd h1 h2 h3 h4 h5 h6 p；

空元素，即没有内容的HTML元素。空元素是在开始标签中关闭的，也就是空元素没有闭合标签：

常见的有：<br>、<hr>、<img>、<input>、<link>、<meta>；
鲜见的有：<area>、<base>、<col>、<colgroup>、<command>、<embed>、<keygen>、<param>、<source>、<track>、<wbr>。

9、web worker

web worker 是运行在后台的 js，独立于其他脚本，不会影响页面的性能。 并且通过 postMessage 将结果回传到主线程。这样在进行复杂操作的时候，就不会阻塞主线程了。

10、**HTML5的离线存储怎么使用**，它的工作原理是什么

11、**浏览器是如何对HTML5的离线存储资源进行管理和加**载？

12、title和h1的区别、b与strong的区别、i和em的区别？

13、iframe有哪些优点和缺点？

14、label的作用是什么？如何使用？

label标签来定义表单控件的关系：当用户选择label标签时，浏览器会自动将焦点转到和label标签相关的表单控件上。

15、canvas的svg的区别？

16、**head标签有什么作用**，其中什么标签必不可少？

17、**文档声明Doctype和<!Doctype html>有何作**用？严格模式与混杂模式如何区别？有何意义？

18、浏览器乱码的原因是什么？如何解决？

19、渐进增强和优雅降级之间的区别？

（1）渐进增强（progressive enhancement）：主要是针对低版本的浏览器进行页面重构，保证基本的功能情况下，再针对高级浏览器进行效果、交互等方面的改进和追加功能，以达到更好的用户体验。
（2）优雅降级 graceful degradation： 一开始就构建完整的功能，然后再针对低版本的浏览器进行兼容。

20、HTML5 drag API？



HTML超文本标签语言，用来描述网页。



标题h 段落 p 链接 a (href 属性指定链接的地址)

空的HTML元素：没有内容的HTML元素，空元素是在开始标签中关闭的。

HTML标题：h1 --- h6

浏览器自动的在标题前后添加空行。

请确保将 HTML heading 标签只用于标题。不要仅仅是为了产生粗体或大号的文本而使用标题。

搜索引擎使用标题为您的网页的结构和内容编制索引。因为用户可以通过标题来快速浏览您的网页，所以用标题来呈现文档结构是很重要的。

HTML水平线 <hr />

HTML 注释 

文本格式化标签

![image-20210825104428865](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825104428865.png)



计算机输出标签

![image-20210825104524347](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825104524347.png)

引用和术语定义

![image-20210825104555456](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825104555456.png)

引用

HTML<q> 用于短的引用，，通常包围引号。

HTML  <blockquote>长引用，元素缩进处理；

HTML <abbr> 定义缩写或首字母缩略语。

HTML<dfn>定义项目或缩写的定义；

HTML<address> 定义文档或文章的联系信息(作者/拥有者)。

HTML<cite> 定义著作的标题；斜体显示；

HTML<bdo> 定义双流向覆盖，覆盖当前文本的方向；rtl;



链接

HTML 使用超级链接与网络上的另一个文档相连。

几乎可以在所有的网页中找到链接。点击链接可以从一张页面跳转到另一张页面。

超链接可以是一个字，一个词，或者一组词，也可以是一幅图像，您可以点击这些内容来跳转到新的文档或者当前文档中的某个部分。

通过使用 <a> 标签在 HTML 中创建链接。

有两种使用 <a> 标签的方式：

1、通过使用 href 属性 - 创建指向另一个文档的链接；
2、通过使用 name 属性 - 创建文档内的书签；



HTML表格

表格由 <table> 标签来定义。每个表格均有若干行（由 <tr> 标签定义），每行被分割为若干单元格（由 <td> 标签定义）。字母 td 指表格数据（table data），即数据单元格的内容。数据单元格可以包含文本、图片、列表、段落、表单、水平线、表格等等。

![image-20210825112252197](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825112252197.png)



HTML列表

无序列表是一个项目的列表，此列项目使用粗体圆点（典型的小黑圆圈）进行标记。

无序列表始于 <ul> 标签。每个列表项始于 <li>。

有序列表也是一列项目，列表项目使用数字进行标记。

有序列表始于 <ol> 标签。每个列表项始于 <li> 标签。

自定义列表不仅仅是一列项目，而是项目及其注释的组合。

自定义列表以 <dl> 标签开始。每个自定义列表项以 <dt> 开始。每个自定义列表项的定义以 <dd> 开始。

![image-20210825112534398](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825112534398.png)

HTML块元素通常会以新行来开始（和结束）

例子：<h1>, <p>, <ul>, <table>

HTML内联元素，通常不会以新行开始。

例子：<b>, <td>, <a>, <img>

![image-20210825112927071](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825112927071.png)

HTML 类

分类块级元素

分类行内元素

HTML id属性

用于HTML元素指定唯一的id；一个 HTML文档中不能存在多个有相同 id 的元素。

通过 ID 和链接实现 HTML 书签   <a href="#C4">跳转到第四章</a>

在 JavaScript 中使用 id 属性  document.getElementById("myHeader")

HTML Iframe 

用于在网页内显示网页；<iframe src="URL"></iframe>

height 和 width 属性用于规定 iframe 的高度和宽度，属性值的默认单位是像素，但也可以用百分比来设定（比如 "80%"）。

frameborder 属性规定是否显示 iframe 周围的边框。

iframe 可用作链接的目标（target）。

链接的 target 属性必须引用 iframe 的 name 属性；



HTML JavaScript

JavaScript 使 HTML 页面更具动态性和交互性。

HTML文件路径

![image-20210825114633528](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825114633528.png)



绝对文件路径是指向一个因特网文件的完整 URL。

相对路径指向了相对于当前页面的文件。



HTML 头部元素

HTML <head> 元素  ；<head> 元素是所有头部元素的容器。<head> 内的元素可包含脚本，指示浏览器在何处可以找到样式表，提供元信息，等等。

以下标签都可以添加到 head 部分：<title>、<base>、<link>、<meta>、<script> 以及 <style>。

HTML<title>元素 定义文档的标题，是必需的；title 元素能够：定义浏览器工具栏中的标题；提供页面被添加到收藏夹时显示的标题；显示在搜索引擎结果中的页面标题。

HTML <base> 元素 标签为页面上的所有链接规定默认地址或默认目标（target）。

HTML <link> 元素 定义文档与外部资源之间的关系。最常用于连接样式表。

HTML <style> 元素 用于为 HTML 文档定义样式信息。

HTML <meta> 元素 关于数据的信息。元数据不会显示在页面上，但是对于机器是可读的。

HTML <script> 元素 用于定义客户端脚本，比如 JavaScript。

![image-20210825115453103](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825115453103.png)

HTML布局

![image-20210825115540240](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825115540240.png)



HTML响应式Web设计

什么是响应式 Web 设计？
RWD 指的是响应式 Web 设计（Responsive Web Design）
RWD 能够以可变尺寸传递网页
RWD 对于平板和移动设备是必需的

创建您自己的响应式设计

使用 **Bootstrap** Bootstrap 是最流行的开发响应式 web 的 HTML, CSS, 和 JS 框架。

Bootstrap 帮助您开发在任何尺寸都外观出众的站点：显示器、笔记本电脑、平板电脑或手机。

HTML 计算机代码元素

![image-20210825134050753](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825134050753.png)

HTML5语义元素

HTML5 提供了定义页面不同部分的新语义元素：

![image-20210825134230962](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825134230962.png)

![image-20210825134647673](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825134647673.png)



HTML 字符实体

HTML 中的预留字符必须被替换为字符实体。

在 HTML 中，某些字符是预留的。

在 HTML 中不能使用小于号（<）和大于号（>），这是因为浏览器会误认为它们是标签。

如果希望正确地显示预留字符，我们必须在 HTML 源代码中使用字符实体（character entities）。

字符实体类似这样：&entity_name;   或者   &#entity_number;

不间断空格（non-breaking space）
HTML 中的常用字符实体是不间断空格(’&nbsp‘)。

![image-20210825135549054](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825135549054.png)



HTML符号

键盘上不存在的字符也可以由实体代替。

HTML 编码字符集 

表情符号（Emoji）是来自 UTF-8 字符集的字符：😄 😍 💗

HTML charset 属性
为了正确显示 HTML 页面，Web 浏览器必须知道页面中使用的字符集。

这是在 <meta> 标签中规定的：

<meta charset="UTF-8">

为了正确显示 HTML 页面，Web 浏览器必须知道要使用哪个字符集。

从 ASCII 到 UTF-8
ASCII 是第一个字符编码标准。ASCII 定义了 128 种可以在互联网上使用的字符：数字（0-9）、英文字母（A-Z）和一些特殊字符，比如：! $ + - ( ) @ < >。

ISO-8859-1 是 HTML 4 的默认字符集。此字符集支持 256 个不同的字符代码。HTML 4 同时支持 UTF-8。

ANSI（Windows-1252）是原始的 Windows 字符集。 ANSI 与 ISO-8859-1 相同，不同之处在于 ANSI 具有 32 个额外的字符。

HTML5 规范鼓励 Web 开发人员使用 UTF-8 字符集，该字符集涵盖了世界上几乎所有的字符和符号！



HTML 统一资源定位器

URL - Uniform Resource Locator  统一资源定位器（URL）用于定位万维网上的文档（或其他数据）。

![image-20210825140241653](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825140241653.png)



HTML URL 字符编码

URL 编码会将字符转换为可通过因特网传输的格式。

URL 只能使用 ASCII 字符集来通过因特网进行发送。

由于 URL 常常会包含 ASCII 集合之外的字符，URL 必须转换为有效的 ASCII 格式。

URL 编码使用 "%" 其后跟随两位的十六进制数来替换非 ASCII 字符。

URL 不能包含空格。URL 编码通常使用 + 来替换空格。



HTML Web Server

如果希望向世界发布您的网站，那么您必须把它存放在 web 服务器上。



HTML <!DOCTYPE>

html  <!DOCTYPE> 声明帮助浏览器正确地显示网页。

<!DOCTYPE> 声明
Web 世界中存在许多不同的文档。只有了解文档的类型，浏览器才能正确地显示文档。

HTML 也有多个不同的版本，只有完全明白页面中使用的确切 HTML 版本，浏览器才能完全正确地显示出 HTML 页面。这就是 <!DOCTYPE> 的用处。

html <!DOCTYPE> 不是 HTML 标签。它为浏览器提供一项信息（声明），即 HTML 是用什么版本编写的。



XHTML 简介

XHTML 是以 XML 格式编写的 HTML。

什么是 XHTML？
XHTML 指的是可扩展超文本标记语言
XHTML 与 HTML 4.01 几乎是相同的
XHTML 是更严格更纯净的 HTML 版本
XHTML 是以 XML 应用的方式定义的 HTML
XHTML 是 2001 年 1 月发布的 W3C 推荐标准
XHTML 得到所有主流浏览器的支持

与 HTML 相比最重要的区别：

### 文档结构

- XHTML DOCTYPE 是强制性的
- <html> 中的 XML namespace 属性是强制性的
- <html>、<head>、<title> 以及 <body> 也是强制性的

### 元素语法

- XHTML 元素必须正确嵌套
- XHTML 元素必须始终关闭
- XHTML 元素必须小写
- XHTML 文档必须有一个根元素

### 属性语法

- XHTML 属性必须使用小写
- XHTML 属性值必须用引号包围
- XHTML 属性最小化也是禁止的

如何从 HTML 转换到 XHTML
向每张页面的第一行添加 XHTML <!DOCTYPE>
向每张页面的 html 元素添加 xmlns 属性
把所有元素名改为小写
关闭所有空元素
把所有属性名改为小写
为所有属性值加引号



XHTML - 元素

XHTML 元素是以 XML 格式编写的 HTML 元素。

XHTML - 属性

XHTML 属性是以 XML 格式编写的 HTML 属性。



HTML 表单

HTML 表单用于搜集不同类型的用户输入。

HTML <form> 元素 HTML表单用于收集用户输入。

HTML 表单包含表单元素。
表单元素指的是不同类型的 input 元素、复选框、单选按钮、提交按钮等等。

1、input 元素

根据不同type属性 ，有很多形态；

![image-20210825141856440](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825141856440.png)

Action属性定义在提交表单时执行的动作。

method 属性规定在提交表单时所用的 HTTP 方法（GET 或 POST）

能够使用 GET（默认方法）：如果表单提交是被动的（比如搜索引擎查询），并且没有敏感信息。

GET 最适合少量数据的提交。浏览器会设定容量限制。

如果表单正在更新数据，或者包含敏感信息（例如密码）。POST 的安全性更好，因为在页面地址栏中被提交的数据是不可见的。

Name 属性，如果要正确地被提交，每个输入字段必须设置一个 name 属性。

用 <fieldset> 组合表单数据
<fieldset> 元素组合表单中的相关数据

<legend> 元素为 <fieldset> 元素定义标题。

HTML Form 属性

![image-20210825142723298](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825142723298.png)

![image-20210825142840217](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825142840217.png)

HTML 表单元素

input> 元素

select> 元素（下拉列表）select> 元素定义下拉列表 ；option> 元素定义待选择的选项。

textarea> 元素  定义多行输入字段（文本域）

button> 元素定义可点击的按钮

HTML5 增加了如下表单元素：

1 、datalist>  为 <input> 元素规定预定义选项列表
2、keygen>
3、output>

HTML5 增加了多个新的输入类型：

color
date
datetime
datetime-local
email
month
number
range
search
tel
time
url
week

HTML Input 属性

value 属性规定输入字段的初始值；

readonly 属性规定输入字段为只读（不能修改）；

disabled 属性规定输入字段是禁用的。

size 属性规定输入字段的尺寸（以字符计）

maxlength 属性规定输入字段允许的最大长度



HTML5 为 <input> 增加了如下属性：

autocomplete
autofocus
form
formaction
formenctype
formmethod
formnovalidate
formtarget
height 和 width
list
min 和 max
multiple
pattern (regexp)
placeholder
required
step



HTML5 Canvas

canvas 元素用于在网页上绘制图形。画布是一个矩形区域，您可以控制其每一像素。

canvas 拥有多种绘制路径、矩形、圆形、字符以及添加图像的方法

canvas 元素本身是没有绘图能力的。所有的绘制工作必须在 JavaScript 内部完成。



HTML5 内联 SVG

SVG 指可伸缩矢量图形 (Scalable Vector Graphics)
SVG 用于定义用于网络的基于矢量的图形
SVG 使用 XML 格式定义图形
SVG 图像在放大或改变尺寸的情况下其图形质量不会有损失
SVG 是万维网联盟的标准

与其他图像格式相比（比如 JPEG 和 GIF），使用 SVG 的优势在于：

SVG 图像可通过文本编辑器来创建和修改
SVG 图像可被搜索、索引、脚本化或压缩
SVG 是可伸缩的
SVG 图像可在任何的分辨率下被高质量地打印
SVG 可在图像质量不下降的情况下被放大

Canvas 和 SVG 都允许您在浏览器中创建图形，但是它们在根本上是不同的。

SVG
SVG 是一种使用 XML 描述 2D 图形的语言。

SVG 基于 XML，这意味着 SVG DOM 中的每个元素都是可用的。您可以为某个元素附加 JavaScript 事件处理器。

在 SVG 中，每个被绘制的图形均被视为对象。如果 SVG 对象的属性发生变化，那么浏览器能够自动重现图形。

Canvas
Canvas 通过 JavaScript 来绘制 2D 图形。

Canvas 是逐像素进行渲染的。

在 canvas 中，一旦图形被绘制完成，它就不会继续得到浏览器的关注。如果其位置发生变化，那么整个场景也需要重新绘制，包括任何或许已被图形覆盖的对象。

Canvas
依赖分辨率
不支持事件处理器
弱的文本渲染能力
能够以 .png 或 .jpg 格式保存结果图像
最适合图像密集型的游戏，其中的许多对象会被频繁重绘
SVG
不依赖分辨率
支持事件处理器
最适合带有大型渲染区域的应用程序（比如谷歌地图）
复杂度高会减慢渲染速度（任何过度使用 DOM 的应用都不快）
不适合游戏应用

HTML 多媒体

Web 上的多媒体指的是音效、音乐、视频和动画。



HTML 插件

插件（Plug-in）是扩展浏览器标准功能的计算机程序。

<object> 元素
所有浏览器均支持 <object> 元素。

<object> 元素定义 HTML 文档中的嵌入式对象。
它旨在将插件（例如 Java applet、PDF 阅读器和 Flash 播放器）嵌入网页中，但也可以用于将 HTML 包含在 HTML 中。



<embed> 元素
所有主要浏览器均支持 <embed> 元素。
HTML <embed> 元素也可定义了 HTML 文档中的嵌入式对象。



内联的声音
当您在网页中包含声音，或者作为网页的组成部分时，它被称为内联声音。

![image-20210825150106262](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825150106262.png)

HTML 视频



HTML5 地理定位

用于定位用户的位置。HTML5 Geolocation API 用于获得用户的地理位置。

鉴于该特性可能侵犯用户的隐私，除非用户同意，否则用户位置信息是不可用的。

使用 getCurrentPosition() 方法来获得用户的位置。



HTML5 拖放

拖放（Drag 和 Drop）是很常见的特性。它指的是您抓取某物并拖入不同的位置。

拖放是 HTML5 标准的组成部分：任何元素都是可拖放的。

拖放的内容 - ondragstart 和 setData()

dataTransfer.setData() 方法设置被拖动数据的数据类型和值

ondragover 事件规定被拖动的数据能够被放置到何处

默认地，数据/元素无法被放置到其他元素中。为了实现拖放，我们必须阻止元素的这种默认的处理方式。

这个任务由 ondragover 事件的 event.preventDefault() 方法完成

当放开被拖数据时，会发生 drop 事件。



HTML 本地存储

通过本地存储（Local Storage），web 应用程序能够在用户浏览器中对数据进行本地的存储。

在 HTML5 之前，应用程序数据只能存储在 cookie 中，包括每个服务器请求。本地存储则更安全，并且可在不影响网站性能的前提下将大量数据存储于本地。

与 cookie 不同，存储限制要大得多（至少5MB），并且信息不会被传输到服务器。

HTML 本地存储提供了两个在客户端存储数据的对象：

window.localStorage - 存储没有截止日期的数据
window.sessionStorage - 针对一个 session 来存储数据（当关闭浏览器标签页时数据会丢失）

localStorage 对象
localStorage 对象存储的是没有截止日期的数据。当浏览器被关闭时数据不会被删除，在下一天、周或年中，都是可用的。

/ /存储
localStorage.setItem("lastname", "Gates");
// 取回
document.getElementById("result").innerHTML = localStorage.getItem("lastname");

注释：名称/值对始终存储为字符串。如果需要请记得把它们转换为其他格式！



sessionStorage 对象
sessionStorage 对象等同 localStorage 对象，不同之处在于只对一个 session 存储数据。如果用户关闭具体的浏览器标签页，数据也会被删除。



HTML5 应用程序缓存

使用应用程序缓存，通过创建 cache manifest 文件，可轻松创建 web 应用的离线版本。

HTML5 引入了应用程序缓存（Application Cache），这意味着可对 web 应用进行缓存，并可在没有因特网连接时进行访问。

应用程序缓存为应用带来三个优势：

离线浏览 - 用户可在应用离线时使用它们
速度 - 已缓存资源加载得更快
减少服务器负载 - 浏览器将只从服务器下载更新过或更改过的资源

<html manifest="demo.appcache">

如需启用应用程序缓存，请在文档的 <html> 标签中包含 manifest 属性。

每个指定了 manifest 的页面在用户对其访问时都会被缓存。如果未指定 manifest 属性，则页面不会被缓存（除非在 manifest 文件中直接指定了该页面）。

注意：manifest 文件需要设置正确的 MIME-type，即 "text/cache-manifest"。必须在 web 服务器上进行配置。

Manifest 文件
manifest 文件是简单的文本文件，它告知浏览器被缓存的内容（以及不缓存的内容）。

manifest 文件有三个部分：

CACHE MANIFEST - 在此标题下列出的文件将在首次下载后进行缓存
NETWORK - 在此标题下列出的文件需要与服务器的连接，且不会被缓存
FALLBACK - 在此标题下列出的文件规定当页面无法访问时的回退页面（比如 404 页面）

CACHE MANIFEST，是必需的；无论用户何时与因特网断开连接，这些资源依然可用

NETWORK 部分规定文件 "login.php" 永远不会被缓存，且离线时是不可用的

FALLBACK 部分规定如果无法建立因特网连接，则用 "offline.html" 替代 /html/ 目录中的所有文件



更新缓存
一旦应用被缓存，它就会保持缓存直到发生下列情况：

用户清空浏览器缓存
manifest 文件被修改（参阅下面的提示）
由程序来更新应用缓存



应用的缓存只会在其 manifest 文件改变时被更新。如果您编辑了一幅图像，或者修改了一个 JavaScript 函数，这些改变都不会被重新缓存。更新注释行中的日期和版本号是一种使浏览器重新缓存文件的办法。



HTML Web Workers

Web worker 是运行在后台的 JavaScript，不会影响页面的性能。

当在 HTML 页面中执行脚本时，页面是不可响应的，直到脚本已完成。

Web worker 是运行在后台的 JavaScript，独立于其他脚本，不会影响页面的性能。您可以继续做任何愿意做的事情：点击、选取内容等等，而此时 web worker 运行在后台。

创建 Web Worker 文件

postMessage() 方法 - 它用于向 HTML 页面传回一段消息

创建 Web Worker 对象

w = new Worker("demo_workers.js");

w.onmessage = function(event){
    document.getElementById("result").innerHTML = event.data;
};

当 web worker 传送消息时，会执行事件监听器中的代码。来自 web worker 的数据会存储于 event.data 中。

终止 Web Worker

当创建 web worker 后，它会继续监听消息（即使在外部脚本完成后）直到其被终止为止。

如需终止 web worker，并释放浏览器/计算机资源，请使用 terminate() 方法：

w.terminate();

复用 Web Worker

如果您把 worker 变量设置为 undefined，在其被终止后，可以重复使用该代码

w = undefined;

Web Worker 和 DOM
由于 web worker 位于外部文件中，它们无法访问下例 JavaScript 对象：

window 对象
document 对象
parent 对象



HTML Server-Sent 事件

Server-Sent 事件允许网页从服务器获得更新。指的是网页自动从服务器获得更新。

接收 Server-Sent 事件通知

EventSource 对象用于接收服务器发送事件通知：

var source = new EventSource("demo_sse.php");
source.onmessage = function(event) {
    document.getElementById("result").innerHTML += event.data + "<br>";
};

创建一个新的 EventSource 对象，然后规定发送更新的页面的 URL（本例中是 "demo_sse.php"）
每当接收到一次更新，就会发生 onmessage 事件
当 onmessage 事件发生时，把已接收的数据推入 id 为 "result" 的元素中。

![image-20210825160540746](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210825160540746.png)



















