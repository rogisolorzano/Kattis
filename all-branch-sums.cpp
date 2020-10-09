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
 * DFS - keeping a running tally of all sums
 *
 * O(n) time - will touch every node
 * O(n) space - each recursive call will add n memory to the call stack
 */
void calculateSumsForBranch(BinaryTree *node, int runningSum, vector<int> &sums) {
  if (node == NULL) {
    return;
  }

  runningSum += node->value;

  if (node->left == NULL && node->right == NULL) {
    sums.push_back(runningSum);
    return;
  }

  calculateSumsForBranch(node->left, runningSum, sums);
  calculateSumsForBranch(node->right, runningSum, sums);
}

vector<int> allBranchSums(BinaryTree *root) {
  vector<int> sums;

  calculateSumsForBranch(root, 0, sums);

  return sums;
}
