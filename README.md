## 年轻人的第一个编译器

此简单编译器是一个C语言编译器，实现环境visual studio 2015。主要由语法分析和词法分析两部分组成。为简化处理，跳过了中间代码生成，直接生成汇编语言，汇编语言类型为windows下32位汇编，可使用masm运行。实现的功能如下：

### 1 statement：
```
for（含除了第二个结点之外的缺省）
while
if
```
以上三个语句的任意嵌套、并列

### 2 operator：
```
+ - * / % && || ! | & ^ >> << 
> >= < <= != == 
++(包括前++和后++)
--（包括前--和后--）
```

### 3 declear：
```
int/char a,b,c…
int/char a=1
int/char a[3][3]…
```
可随时声明

转义字符$n(回车换行),$t(制表符)

### 4 符号表
采用单符号表，可以改进

---
### 实现错误：
在检查作业时发现赋值语句的类型检查，未检查是否为可修改的左值

### 实现缺点与不足之处：
未实现对char型变量的临时变量,所以对char变量只能做赋值、打印（在移位运算中有用char临时变量的测试ctemp）
采用直接遍历符号表生成声明，对语法分析的要求较高（添加类型等）

可以增加struct，宏汇编中可以直接定义结构

对于作用域中变量的声明，例如for语句，在C99之前的标准中也没有，如果要实现的话，
一个思路是用函数栈（当然这个也很难实现），简单的方法或许可以用临时变量local

---
by the way, input.txt中有三个小程序，可尝试运行
