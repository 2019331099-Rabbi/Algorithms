#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

/*
Diameter = depth of left subtree + depth of right subtree
Any of the node can be the root of the diameter. So we have to calculate
the diameter for every node. 
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int d = 0;
    int findDiameter(TreeNode *root)
    {
        if (!root) return 0;

        int left = findDiameter(root->left);
        int right = findDiameter(root->right);
        d = max(d, left + right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {   
        findDiameter(root);
        return d;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node9 = new TreeNode(9);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node4->left = node6;
    node5->right = node7;

    node6->left = node8;
    node7->right = node9;

    cout << soln->diameterOfBinaryTree(node1) << endl;

    return 0;
}