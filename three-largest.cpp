#include <vector>
#include <limits>
using namespace std;

// array [33, 1, 91, 12, 83, 23, 6, 8, 51]

/**
 * Stores 3 largest numbers and shifts values down as it finds larger ones.
 *
 * O(n) time - will traverse entire `array`
 * O(1) space - uses constant space - isn't relative to the size of the array
 */
vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> values = {
    numeric_limits<int>::min(),
    numeric_limits<int>::min(),
    numeric_limits<int>::min()
  };

  for (auto value : array) {
    if (value > values[2]) {
      values[0] = values[1];
      values[1] = values[2];
      values[2] = value;
    } else if (value > values[1]) {
      values[0] = values[1];
      values[1] = value;
    } else if (value > values[0]) {
      values[0] = value;
    }
  }

  return values;
}
