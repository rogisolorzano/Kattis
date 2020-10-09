#include<vector>
using namespace std;

// array {7, 1, 99, 22, 3, 9, 41, 10}
// sequence {1, 3, 9, 10}

/**
 * Iterates backward, pops one off sequence if it runs into it
 *
 * O(n) time - iterative
 * O(1) space - iterative
 */
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  for (int i = array.size() - 1; i >= 0; i--) {
    if (array[i] == sequence.back()) {
      sequence.pop_back();
    }
    if (sequence.empty()) {
      return true;
    }
  }
	
  return false;
}
