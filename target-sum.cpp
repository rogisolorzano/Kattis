#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// array {5, 1, 22, -1, 25, 6, 11}
// targetSum 10

/**
 * Iterative solution
 *
 * targetSum - array[n] = x
 *
 * O(n) time - iterative
 * O(n) space - set grows along with size of `array`
 */
vector<int> targetSumSolutionOne(vector<int> array, int targetSum) {
  unordered_set<int> set;

  for (int i = 0; i < array.size(); i++) {
    int x = targetSum - array[i];

    if (set.find(x) != set.end()) {
      return {array[i], x};
    }

    set.insert(array[i]);
  }

  return {};
}

/**
 * Uses 2 pointers.
 *
 * O(nlog(n)) time - due to `sort`
 * O(1) space - iterative
 */
vector<int> targetSumSolutionTwo(vector<int> array, int targetSum) {
  sort(array.begin(), array.end());
	
  int left = 0;
  int right = array.size() - 1;
	
  while (left < right) {
    int sum = array[left] + array[right];

    if (sum < targetSum) {
      left += 1;
    } else if (sum > targetSum) {
      right -= 1;
    } else {
      return {array[left], array[right]};
    }
  }
	
  return {};
}
