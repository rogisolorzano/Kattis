#include <cmath>

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

/**
 * Recurses the BST keeping track of the closest value. Either goes w/
 * left or right depending on if we need a larger or smaller value.
 *
 * O(log(n)) time & space (On average w/ a reasonably balanced tree)
 */
int recurseBst(BST *tree, int target, int closest) {
  if (tree == NULL) {
    return closest;
  }
	
  int current = tree->value;
  int prevDiff = abs(target - closest);
  int diff = abs(target - current);

  if (diff == 0) {
    return current;
  }
	
  if (diff < prevDiff) {
    closest = current;
  }
	
  if (current < target) {
    return recurseBst(tree->right, target, closest);
  } else if (current > target) {
    return recurseBst(tree->left, target, closest);
  }

  return current;
}

int findClosestValueInBst(BST *tree, int target) {
  return recurseBst(tree, target, tree->value);
}
