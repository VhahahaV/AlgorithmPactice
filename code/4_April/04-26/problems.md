# 逆序对

## 题目描述

猫猫 TOM 和小老鼠 JERRY 最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。

最近，TOM 老猫查阅到一个人类称之为“逆序对”的东西，这东西是这样定义的：对于给定的一段正整数序列，逆序对就是序列中 $a_i>a_j$ 且 $i<j$ 的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。注意序列中可能有重复数字。

**Update:数据已加强。**

## 输入格式

第一行，一个数 $n$，表示序列中有 $n$个数。

第二行 $n$ 个数，表示给定的序列。序列中每个数字不超过 $10^9$。

## 输出格式

输出序列中逆序对的数目。

## 样例 #1

### 样例输入 #1

```
6
5 4 2 6 3 1
```

### 样例输出 #1

```
11
```

## 提示

对于 $25\%$ 的数据，$n \leq 2500$

对于 $50\%$ 的数据，$n \leq 4 \times 10^4$。

对于所有数据，$n \leq 5 \times 10^5$

请使用较快的输入输出

应该不会 $O(n^2)$ 过 50 万吧 by chen_zhe
# 【模板】并查集

## 题目描述

如题，现在有一个并查集，你需要完成合并和查询操作。

## 输入格式

第一行包含两个整数 $N,M$ ,表示共有 $N$ 个元素和 $M$ 个操作。

接下来 $M$ 行，每行包含三个整数 $Z_i,X_i,Y_i$ 。

当 $Z_i=1$ 时，将 $X_i$ 与 $Y_i$ 所在的集合合并。

当 $Z_i=2$ 时，输出 $X_i$ 与 $Y_i$ 是否在同一集合内，是的输出
`Y` ；否则输出 `N` 。

## 输出格式

对于每一个 $Z_i=2$ 的操作，都有一行输出，每行包含一个大写字母，为 `Y` 或者 `N` 。

## 样例 #1

### 样例输入 #1

```
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4
```

### 样例输出 #1

```
N
Y
N
Y
```

## 提示

对于 $30\%$ 的数据，$N \le 10$，$M \le 20$。

对于 $70\%$ 的数据，$N \le 100$，$M \le 10^3$。

对于 $100\%$ 的数据，$1\le N \le 10^4$，$1\le M \le 2\times 10^5$，$1 \le X_i, Y_i \le N$，$Z_i \in \{ 1, 2 \}$。
