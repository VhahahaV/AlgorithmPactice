# [NOIP2001 提高组] 一元三次方程求解

## 题目描述

有形如：$a x^3 + b x^2 + c x + d = 0$  这样的一个一元三次方程。给出该方程中各项的系数（$a,b,c,d$ 均为实数），并约定该方程存在三个不同实根（根的范围在 $-100$ 至 $100$ 之间），且根与根之差的绝对值 $\ge 1$。要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后 $2$ 位。

提示：记方程 $f(x) = 0$，若存在 $2$ 个数 $x_1$ 和 $x_2$，且 $x_1 < x_2$，$f(x_1) \times f(x_2) < 0$，则在 $(x_1, x_2)$ 之间一定有一个根。

## 输入格式

一行，$4$ 个实数 $a, b, c, d$。

## 输出格式

一行，$3$ 个实根，从小到大输出，并精确到小数点后 $2$ 位。

## 样例 #1

### 样例输入 #1

```
1 -5 -4 20
```

### 样例输出 #1

```
-2.00 2.00 5.00
```

## 提示

**【题目来源】**

NOIP 2001 提高组第一题
# [NOIP2004 提高组] 合并果子 / [USACO06NOV] Fence Repair G

## 题目描述

在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。

每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过 $n-1$ 次合并之后， 就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。

因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。假定每个果子重量都为 $1$ ，并且已知果子的种类 数和每种果子的数目，你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。

例如有 $3$ 种果子，数目依次为 $1$ ， $2$ ， $9$ 。可以先将 $1$ 、 $2$ 堆合并，新堆数目为 $3$ ，耗费体力为 $3$ 。接着，将新堆与原先的第三堆合并，又得到新的堆，数目为 $12$ ，耗费体力为 $12$ 。所以多多总共耗费体力 $=3+12=15$ 。可以证明 $15$ 为最小的体力耗费值。

## 输入格式

共两行。  
第一行是一个整数 $n(1\leq n\leq 10000)$ ，表示果子的种类数。

第二行包含 $n$ 个整数，用空格分隔，第 $i$ 个整数 $a_i(1\leq a_i\leq 20000)$ 是第 $i$ 种果子的数目。

## 输出格式

一个整数，也就是最小的体力耗费值。输入数据保证这个值小于 $2^{31}$ 。

## 样例 #1

### 样例输入 #1

```
3 
1 2 9
```

### 样例输出 #1

```
15
```

## 提示

对于 $30\%$ 的数据，保证有 $n \le 1000$：

对于 $50\%$ 的数据，保证有 $n \le 5000$；

对于全部的数据，保证有 $n \le 10000$。