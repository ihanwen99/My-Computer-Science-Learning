# OJ Contest 6

训练题目内容对应书上第七章。

---

### 1. 何月何日

> 编写函数`bool getdate(int x, int& month, int& day)`使之能够算出 2020 年的第`x`天是几月几日。

[My Code](https://github.com/david990917/My-Computer-Science-Learning/blob/master/Courses/CPP-Programming-Course/OJ%20Contest%206/%E4%BD%95%E6%9C%88%E4%BD%95%E6%97%A5.cpp)

1. 首先进行 `bool` 判断。

2. 使用数组进行日期递减判断

   `for(expression 1;expression 2;expression 3)`

   1. 执行表达式1
   2. 执行表达式2
   3. 如果表达式2的结果为 `true`，执行函数体和表达式3，然后回到表达式2；如果结果为 `false`，结束循环

**本题目需要注意366天的输入情况：**在最后一个月的时候直接跳出。

```cpp
bool getdate(int x, int& month, int& day) {
	if (x > 366) { return false; }
	int monthDay[] = { 31,29,31,30,31,30,31,31,30,31,30,30,31 };
	for (month = 0; month < 12; ++month) {
		if (month == 11) { break; }
		if (x <= monthDay[month]) { break; }
		x -= monthDay[month];
	}
	month++; day = x;
	return true;
}
```

### 2.  寻找最大两个数

> 分治法找出最大和第二大的值。

[My Code](https://github.com/david990917/My-Computer-Science-Learning/blob/master/Courses/CPP-Programming-Course/OJ%20Contest%206/%E5%AF%BB%E6%89%BE%E6%9C%80%E5%A4%A7%E4%B8%A4%E4%B8%AA%E6%95%B0.cpp)

需要注意找的是**值**。所以如果两个相等的情况，需要将 `second` 空着。

**Tip：**最好还是特殊情况的时候，second设置为最小值(INT_MIN)；

```cpp
void max2(int a[], int n, int* first, int* second) {
	switch (n) {
	case 1:*first= a[0]; return;
	case 2:
		if (a[0] == a[1]) { *first = a[0]; return; }
		*first = max(a[0], a[1]); *second = min(a[0], a[1]); return;
	default:
		int max0, second0, max1, second1;
		max2(a, n / 2, &max0, &second0);
		max2(a + n / 2, n - n / 2, &max1, &second1);
		if (max0 > max1) { *first = max0; *second = max(second0, max1); }
		if (max1 > max0) { *first = max1; *second = max(second1, max0); }
		if (max1 == max0) { *first = *second = max0; }
		return;
	}
}
```

