#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include<vector>
#include <algorithm>
int ans;
int depth(TreeNode* head) {
	if (head == NULL) { return 0; }
	int L = depth(head->left);
	int R = depth(head->right);
	ans = max(ans, L + R + 1);
	return max(L, R) + 1;
}

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

	ans = 1;
	TreeNode* head = &arr[0];
	int dep = depth(head);
	cout << ans - 1 << endl;
	return 0;
}