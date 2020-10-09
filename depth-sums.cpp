using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

/**
 * DFS - keeps running sum of depths
 *
 * O(n) time - touches every node in the tree
 * O(h) space - h is height of tree. h functions calls will be added to the call stack.
 */
void calculateDepth(BinaryTree *node, int currentDepth, int &depthSum) {
  if (node == NULL) {
    return;
  }

  depthSum += currentDepth;

  calculateDepth(node->left, currentDepth + 1, depthSum);
  calculateDepth(node->right, currentDepth + 1, depthSum);
}

int nodeDepths(BinaryTree *root) {
  int sum = 0;

  calculateDepth(root, 0, sum);

  return sum;
}
