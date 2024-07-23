#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode() :left(NULL), right(NULL) {}
    TreeNode(int value) :left(NULL), right(NULL), val(value) {}
};
class Solution {
public:
    TreeNode* pre = NULL;
    int minValue = 100;
    void traversal(TreeNode* root) {
        if (root == NULL)return;
        traversal(root->left);
        if (pre != NULL && minValue > abs(root->val - pre->val)) {
            minValue = abs(root->val - pre->val);
        }
        pre = root;
        traversal(root->right);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return minValue;
    }
};
//class Solution {
//public:
//        TreeNode* pre = NULL;
//        int minValue;
//    bool isValidBST(TreeNode* root) {
//        if (root == NULL)return true;
//        bool left=isValidBST(root->left);
//        if (pre != NULL && minValue > abs(root->val-pre->val)) {
//            minValue = root->val - pre->val;
//        }
//        pre = root;
//        bool right=isValidBST(root->right);
//        return left && right;
//    }
//};
//class Solution {
//public:
//    TreeNode* findTree(TreeNode* root, int val) {
//        if (root == NULL)return NULL;
//        if (root->val == val)return root;
//        TreeNode* root1;
//        TreeNode* leftTree = findTree(root->left, val);
//        TreeNode* rightTree = findTree(root->right, val);
//        if (leftTree != NULL)root1 = leftTree;
//        if (rightTree != NULL)root1 = rightTree;
//        return root1;
//    }
//    TreeNode* searchBST(TreeNode* root, int val) {
//        return findTree(root, val);
//    }
//};
//class Solution {
//public:
//    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//        if (root1 == NULL && root2 == NULL)return NULL;
//        if (root1 == NULL)return root2;
//        if (root2 == NULL)return root1;
//        root1->val += root2->val;
//        root1->left = mergeTrees(root1->left, root2->left);
//        root1->right = mergeTrees(root1->right, root2->right);
//        return root1;
//    }
//};
//class Solution {
//public:
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//        if (nums.size() == 1)return new TreeNode(nums[0]);
//        int maxVal, index;
//        for (int i=0; i < nums.size(); i++) {
//            if (nums[i] > maxVal) {
//                maxVal = nums[i];
//                index = i;
//            }
//        }
//        TreeNode* root = new TreeNode(maxVal);
//        if(index>0)
//        {
//            vector<int>leftTree(nums.begin(), nums.begin() + index);
//            root->left = constructMaximumBinaryTree(leftTree);
//        }
//        if (nums.size() - index - 1 > 0) {
//            vector<int>rightTree(nums.begin() + index + 1, nums.end());
//            root->right = constructMaximumBinaryTree(rightTree);
//        }
//        return root;
//    }
//};
//class Solution {
//public:
//    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
//        if (postorder.size() == 0)return NULL;
//        int rootValue = postorder[postorder.size() - 1];
//        TreeNode* root = new TreeNode(rootValue);
//        if (postorder.size() == 1)return root;
//        int index = 0;
//        for (index; index < inorder.size(); index++) {
//            if (inorder[index] == rootValue) {
//                break;
//            }
//        }
//        vector<int>left1(inorder.begin(), inorder.begin() + index);
//        vector<int>right1(inorder.begin() + index + 1, inorder.end());
//        vector<int>left2(postorder.begin(), postorder.begin()+left1.size());
//        vector<int>right2(postorder.begin() + left1.size(), postorder.end() - 1);
//        root->left = traversal(left1, left2);
//        root->right = traversal(right1, right2);
//        return root;
//    }
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        return traversal(inorder, postorder);
//    }
//};