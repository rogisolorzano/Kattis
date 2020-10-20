#include <vector>
#include <algorithm>
using namespace std;

/**
 * O(n^2) time
 * O(n) space
 */
vector<vector<int>> tripletSum(vector<int> array, int target) {
  sort(array.begin(), array.end());
  vector<vector<int>> solution = {};

  for (int cP = 0; cP < array.size() - 2; cP++) {
    int lP = cP + 1;
    int rP = array.size() - 1;

    while (lP < rP) {
      int currentSum = array[cP] + array[lP] + array[rP];
			
      if (currentSum == target) {
        solution.push_back({array[cP], array[lP], array[rP]});
        lP++;
        rP--;
      } else if (currentSum > target) {
        rP--;
      } else {
        lP++;
      }
    }
  }
	
  return solution;
}
