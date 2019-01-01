/*
Implement an iterator over a binary search tree (BST). Your iterator will be
initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory,
where h is the height of the tree.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    //对二叉搜索树进行中序遍历，结果存入到队列中
    stack<TreeNode *> node_stack;
    TreeNode *pNode = root;
    while (pNode || !node_stack.empty()) {
      if (pNode != NULL) {
        node_stack.push(pNode);
        pNode = pNode->left;
      } else {
        pNode = node_stack.top();
        node_stack.pop();
        int_queue.push(pNode->val);
        pNode = pNode->right;
      }
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !int_queue.empty(); }

  /** @return the next smallest number */
  int next() {
    //队列首元素出列
    if (!int_queue.empty()) {
      int result = int_queue.front();
      int_queue.pop();
      return result;
    } else {
      return -1;
    }
  }

private:
  queue<int> int_queue;
};
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
