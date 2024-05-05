# 【模板】高斯消元法

## 题目背景

如果想要更好地测试高斯消元算法模板请在通过此题后尝试通过 [SDOI2006 线性方程组](https://www.luogu.com.cn/problem/P2455) 这一题。

## 题目描述

给定一个线性方程组，对其求解。

$$ \begin{cases} a_{1, 1} x_1 + a_{1, 2} x_2 + \cdots + a_{1, n} x_n = b_1 \\ a_{2, 1} x_1 + a_{2, 2} x_2 + \cdots + a_{2, n} x_n = b_2 \\ \cdots \\ a_{n,1} x_1 + a_{n, 2} x_2 + \cdots + a_{n, n} x_n = b_n \end{cases}$$

## 输入格式

第一行，一个正整数 $n$。

第二至 $n+1$ 行，每行 $n+1$ 个整数，为 $ a_1, a_2, \dots ,a_n$ 和 $b$，代表一组方程。

## 输出格式

共 $n$ 行，每行一个数，第 $i$ 行为 $x_i$（四舍五入保留 $2$ 位小数）。

如果不存在唯一解或无解，在第一行输出 `No Solution`.

## 样例 #1

### 样例输入 #1

```
3
1 3 4 5
1 4 7 3
9 3 2 2
```

### 样例输出 #1

```
-0.97
5.18
-2.39
```

## 提示

本题 special judge 用于处理可能由于浮点数问题输出 `-0.00` 的情况。若某个 $x_i$ 的解四舍五入后是 `0.00`，那么你的程序输出 `-0.00` 和输出 `0.00` 都是正确的。

数据范围：$1 \leq n \leq 100, \left | a_i \right| \leq {10}^4 , \left |b \right| \leq {10}^4 $。保证数据若有解则所有解均满足 $|x_i|\le 10^3$，且 $x_i\pm 10^{-6}$ 和 $x_i$ 四舍五入后的结果相同（即不会因为较小的精度误差导致四舍五入后的结果不同）。
# 【模板】矩阵求逆

## 题目描述

求一个 $N\times N$ 的矩阵的逆矩阵。答案对 ${10}^9+7$ 取模。

## 输入格式

第一行有一个整数 $N$，代表矩阵的大小；

接下来 $N$ 行，每行 $N$ 个整数，其中第 $i$ 行第 $j$ 列的数代表矩阵中的元素 $a_{i j}$。

## 输出格式

若矩阵可逆，则输出 $N$ 行，每行 $N$ 个整数，其中第 $i$ 行第 $j$ 列的数代表逆矩阵中的元素 $b_{i j}$，答案对 ${10}^9+7$ 取模；

否则只输出一行 `No Solution`。

## 样例 #1

### 样例输入 #1

```
3
1 2 8  
2 5 6
5 1 2
```

### 样例输出 #1

```
718750005 718750005 968750007
171875001 671875005 296875002
117187501 867187506 429687503
```

## 样例 #2

### 样例输入 #2

```
3
3 2 4
7 2 9
2 4 3
```

### 样例输出 #2

```
No Solution
```

## 提示

对 $30 \%$ 的数据有 $N\le 100$；  
对 $100 \%$ 的数据有 $N\le 400$，所有 $0 \le a_{i j} < {10}^9 + 7$。
# 【模板】快速幂

## 题目描述

给你三个整数 $a,b,p$，求 $a^b \bmod p$。

## 输入格式

输入只有一行三个整数，分别代表 $a,b,p$。

## 输出格式

输出一行一个字符串 `a^b mod p=s`，其中 $a,b,p$ 分别为题目给定的值， $s$ 为运算结果。

## 样例 #1

### 样例输入 #1

```
2 10 9
```

### 样例输出 #1

```
2^10 mod 9=7
```

## 提示

**样例解释**

$2^{10} = 1024$，$1024 \bmod 9 = 7$。

**数据规模与约定**

对于 $100\%$ 的数据，保证 $0\le a,b < 2^{31}$，$a+b>0$，$2 \leq p \lt 2^{31}$。