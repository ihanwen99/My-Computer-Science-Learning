# OJ Contest 4

训练题目内容对应书上第五章。

---

### 1. 13号是周几

> 计算1900年1月1日（星期一）至 1900+n-1 年12月31日中所有13号落在周一到周日的次数。

[My Code](https://github.com/david990917/CPP-Programming-Course/blob/master/OJ%20Contest%204/13号是周几.cpp)

周几其实就是一个 `相对变化` 然后 `取模` 的计算过程。

我们计算出相对于 `前一年(base)` 的日期差，然后更新 `(base)` 这样的话，我们也不用存储大量的累积日期数据。

计算年份日期的问题，我们需要注意 `闰年` 的判断。

### 2. 找出素数

> 使用 `埃拉托色尼筛选法` 找出小于等于 `n`的所有素数。

[My Code](https://github.com/david990917/CPP-Programming-Course/blob/master/OJ%20Contest%204/找出素数.cpp)

算法复杂度的优化，对于我们每次找的新的一个数 `n`，我们不是从容易想到的 `2n` 开始找，我们是从 `n^2` 开始。这样的话可以减少很多重复的数。

原因：因为我们找 `n-1` 的时候，已经找了 `(n-1)*n`。所以对于 `n` 来说，我们之前的 `n*(n-1)` 或者 `n*k (k<n)` 都已经被查找过了。

### 3. 出现的位置

> 升序正整数数组，找出 x 出现的第一次和最后一次的位置

[My Code](https://github.com/david990917/CPP-Programming-Course/blob/master/OJ%20Contest%204/%E5%87%BA%E7%8E%B0%E7%9A%84%E4%BD%8D%E7%BD%AE.cpp)

最开始进行特判，然后正常顺序遍历数组就可以。

### 4. 插入排序

> 插入排序

[My Code](https://github.com/david990917/CPP-Programming-Course/blob/master/OJ%20Contest%204/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F.cpp)

简单直白实现算法即可。

### 5. 矩阵鞍点

> `R*C` 的矩阵，找到鞍点。

[My Code](https://github.com/david990917/CPP-Programming-Course/blob/master/OJ%20Contest%204/%E7%9F%A9%E9%98%B5%E9%9E%8D%E7%82%B9.cpp)

最直接的想法：鞍点的寻找可以通过暴力方法进行比较。

这道题目中的特色是元素可以重复。所以对于同一行中元素来说，可能有多个相等的最大值；对于同一列来说，可能有多个相等的最小值。

我的实现方法是：

1. 首次遍历：找到每一行中的最大值所在的列数（其中使用严格的`>`来进行判断，这样我们找到的会使第一个最大值）
2. 再次遍历：对于每一行来说：
   1. 从第一次出现的最大值位置开始找起，遍历来判断是不是当列的最小值。
   2. 重复这个过程，对该行相等的最大值进行同样的检查过程。
3. 如果最后也没有找到，输出`NONE`

**额外的方法：**`max_row[]` & `min_col[]` 里面存储最大最小的值！

### 6. 小球碰撞

> 极大数量的小球弹性碰撞，寻找最先和最后掉下木板的时间。

[My Code](https://github.com/david990917/CPP-Programming-Course/blob/master/OJ%20Contest%204/%E5%B0%8F%E7%90%83%E7%A2%B0%E6%92%9E.cpp)

这个题目主要是物理的思想。

弹性碰撞后，两个小球反向运动。这个过程实际上就相当于互相穿过去了，没有碰撞。

所以就很好想到最后只需要关注四个球的点位就可以了。

- 向左运动的球中
  - 最左边的 - leftMin
  - 最右边的 - leftMax

- 向右运动的球中
  - 最左边的 - rightMin
  - 最右边的 - rightMax

### 7. 



### 8. 四则运算

> 解析单字符串，实现四则运算。

[My Code](https://github.com/david990917/CPP-Programming-Course/blob/master/OJ%20Contest%204/%E5%9B%9B%E5%88%99%E8%BF%90%E7%AE%97.cpp)

使用数字记录的方式，不用另开数组了。

### 9. 字符串排序去重

> 删除字符串中的重复元素，并且按照ASCII码从大到小输出。

[My Code](https://github.com/david990917/CPP-Programming-Course/blob/master/OJ%20Contest%204/%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%8E%92%E5%BA%8F%E5%8E%BB%E9%87%8D.cpp)

简单易懂的暴力搜索实现。

需要注意输入的末尾是`cin.eof()`（这个需要注意）

`cin.getline(input, 80, cin.eof());` 我使用的这句话有点问题。

### 10. 数一

> 输出每行中一的最大出现次数。

[My Code](https://github.com/david990917/CPP-Programming-Course/blob/master/OJ%20Contest%204/%E6%95%B0%E4%B8%80.cpp)

随着输入过程的判断，就能不使用额外操作实现计数。