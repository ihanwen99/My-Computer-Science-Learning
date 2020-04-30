# OJ Contest 7

训练题目内容对应书上第八章。

---

### 1. 复数相加

> 用结构体表示一个复数，编写实现复数的加法，输入和输出的三个函数。

复数类是结构体的基本考察题型。

在函数中创建一个新的类的时候，直接使用 new

因为输出输出的实部和虚部都是正整数，所以我们最后输出的时候不用判断虚部的符号。

```cpp
// Define your struct here. Its name *must* be my_complex.
struct my_complex {
	long long real;
	long long viru;
};
/**
 * Read a complex number.
 * @return pointer to the complex number just read, allocated on heap
 */
my_complex* read_complex() {
	my_complex* tmp = new my_complex;
	cin >> tmp->real >> tmp->viru;
	return tmp;
}

/**
 * Add two complex numbers.
 * @return pointer to the result, allocated on heap
 */
my_complex* add_complex(const my_complex* a, const my_complex* b) {
	my_complex* tmp = new my_complex;
	tmp->real = a->real + b->real;
	tmp->viru = a->viru + b->viru;
	return tmp;
}

/**
 * Print a complex number.
 */
void print_complex(const my_complex* a) {
	cout << a->real << '+' << a->viru << 'i';
}

```

### 2. 学生成绩排序

> 编写一个程序，读入 N*N* 个同学的姓名和语数外三门功课的单科成绩，对其按照一定的排序规则排序形成一张成绩表
>
> - 先按总分从高到低排序
> - 总分相同则按语文成绩由高到低排序
> - 仍然相同则按数学成绩由高到低排序
> - 若总分和单科成绩均相同则最后按姓名的字典序排序）
>
> 最后给定一个数字 K*(*K*≤*N*) ，输出在这张排好序的成绩表中位置在第 K*K* 位的同学的姓名和总分。

整体来说这道题考察了我对于 `compare` 函数的理解。

`bool compare(a,b)`如果不用修改顺序，就输出 `true`，如果需要修改就输出 `false`，这样好理解。

字符串字典序比较大小的时候，直接使用大于小于号比较就可以。

```cpp
bool compare(student a, student b) {
	int totalA = a.chiScore + a.mathScore + a.engScore;
	int totalB = b.chiScore + b.mathScore + b.engScore;
	if (totalA > totalB) { return true; }
	if (totalA < totalB) { return false; }
	//totalA==totalB
	if (a.chiScore > b.chiScore) { return true; }
	if (a.chiScore < b.chiScore) { return false; }
	//a.chiScore==b.chiScore
	if (a.mathScore > b.mathScore) { return true; }
	if (a.mathScore < b.mathScore) { return false; }
	//a.mathScore==b.mathScore
	if (a.engScore > b.engScore) { return true; }
	if (a.engScore < b.engScore) { return false; }
	//a.engScore==b.engScore
	return a.name < b.name;
}
```

排序的时候锻炼了一下冒泡排序：`n-1` 次起泡，内部循环的时候 `times-i-1`

```cpp
//sort
for (int i = 0; i < times - 1; i++) {
    bool flag = true;
    for (int j = 0; j < times - i - 1; j++) {
        if (!compare(arr[j], arr[j + 1])) {
            student tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            flag = false;
        }
    }
    if (flag) { break; }
}
```

### 3. 多项式加法

> 利用链表实现整系数多项式的加法`Node* add_poly(Node* a, Node* b)`

需要注意自身 a / b 中携带 0 的时候。

整体实现就是使用链表实现，注意移动就可以了。

实现过程中，我使用了`head`的想法，这样可以使我专注连接后面的节点；需要 `return head->next`

```cpp
// IN: Node* a, Node* b, polynomials represented as linked lists
// RETURN: polynomial a+b represented as a linked list
Node* add_poly(Node* a, Node* b) {
	bool exist = false;
	Node* head = new Node;
	Node* curr = head;
	while (a && b) {
		if (a->order == b->order) {
			if (a->coeff + b->coeff != 0) {
				exist = true;
				Node* tmp = new Node;
				tmp->order = a->order;
				tmp->coeff = a->coeff + b->coeff;
				curr->nxt = tmp;
				curr = curr->nxt;
			}
			a = a->nxt;
			b = b->nxt;
		}
		else {
			if (a->order > b->order) {
				if (a->coeff != 0) {
					curr->nxt = a;
					curr = curr->nxt;
				}
				a = a->nxt;
			}
			else {
				if (b->coeff != 0) {
					curr->nxt = b;
					curr = curr->nxt;
				}
				b = b->nxt;
			}
		}
	}
	while (a) {
		if (a->coeff != 0) {
			curr->nxt = a;
			curr = curr->nxt;
		}
		a = a->nxt;
	}
	while (b) {
		if (b->coeff != 0) {
			curr->nxt = b;
			curr = curr->nxt;
		}
		b = b->nxt;
	}
	curr->nxt = NULL;

	if (exist) { return head->nxt; }
	head->order = 0;
	head->coeff = 0;
	head->nxt = NULL;
	return head;

}
```

### 4. 删除有序链表中的重复元素

> 定义`deleteDuplicates`函数，实现对于元素为升序的链表，删除其中重复的元素。

力扣中的题目，复习了链表遍历过程中需要 `while(curr && curr->next)`

```cpp
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* curr = head;
	while (curr && curr->next) {
		if (curr->next->val == curr->val) {
			curr->next = curr->next->next;
		}
		else { curr = curr->next; }
	}
	return head;
}
```

### 5. 二叉树的直径

> 给定一棵二叉树，你需要计算它的直径长度。
>
> 一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

二叉树的直径可以基于二叉树的深度来进行计算。

递归计算二叉树深度的同时，我们要的直径就是 `ans=max(ans,L+R)`

在第一次提交的代码中我是使用 `L+R+1` 这个是整体的路径长度，减去1就是我们的直径。

```cpp
#include<vector>
#include <algorithm>
int ans;
int depth(TreeNode* head) {
	if (head == NULL) { return 0; }
	int L = depth(head->left);
	int R = depth(head->right);
	ans = max(ans, L + R);
	return max(L, R) + 1;
}
```

```cpp
int main() {
	int n; cin >> n;
	vector<TreeNode> arr;
	for (int i = 1; i <= n; i++) {
		arr.push_back(TreeNode(i));
	}
	for (int i = 0; i < n; i++) {
		int left, right;
		cin >> left >> right;
		if(left>0){ arr[i].left = &arr[left - 1]; }
		if(right>0){ arr[i].right = &arr[right - 1]; }
	}

	ans = 0;
	TreeNode* head = &arr[0];
	int dep = depth(head);
	cout << ans << endl;
	return 0;
}
```

