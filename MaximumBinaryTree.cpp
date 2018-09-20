/*
LeetCode 654(2018/9/20(Th-3))
 Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

Note:The size of the given array will be in the range [1,1000].


*/
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include<queue>
using namespace std;
class TreeNode
{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
class Solution {
public:
	TreeNode * constructMaximumBinaryTree(vector<int>& nums)
	{
		if (!nums.size())return nullptr;
		int biggest = max(nums);
		TreeNode *now = new TreeNode(nums[biggest]);
		vector<int> left, right;
		for (int i = 0; i < biggest; i++)
		{
			left.push_back(nums[i]);
		}
		for (int i = biggest + 1; i < nums.size(); i++)
		{
			right.push_back(nums[i]);
		}
		now->left = constructMaximumBinaryTree(left);
		now->right = constructMaximumBinaryTree(right);
		return now;
	}
	int max(vector<int> &nums)
	{
		int biggest = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[biggest] < nums[i])biggest = i;
		}
		return biggest;
	}
};
void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

string treeNodeToString(TreeNode* root) {
	if (root == nullptr) {
		return "[]";
	}

	string output = "";
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* node = q.front();
		q.pop();

		if (node == nullptr) {
			output += "null, ";
			continue;
		}

		output += to_string(node->val) + ", ";
		q.push(node->left);
		q.push(node->right);
	}
	return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		TreeNode* ret = Solution().constructMaximumBinaryTree(nums);

		string out = treeNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}