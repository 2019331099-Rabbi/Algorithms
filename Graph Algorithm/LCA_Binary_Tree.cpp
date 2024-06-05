#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == NULL || root == p || root == q) return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL) return right;
    if (right == NULL) return left;
    return root;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    // Create leaf nodes
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(9);

    // Create internal nodes and attach leaf nodes
    TreeNode* node4 = new TreeNode(4);
    node4->left = node3;
    node4->right = node5;

    TreeNode* node2 = new TreeNode(2);
    node2->left = node0;
    node2->right = node4;

    TreeNode* node8 = new TreeNode(8);
    node8->left = node7;
    node8->right = node9;

    // Create the root node and attach internal nodes
    TreeNode* root = new TreeNode(6);
    root->left = node2;
    root->right = node8;

    auto node = lowestCommonAncestor(root, node2, node4);
    cout << node->val << endl;

    return 0;
}