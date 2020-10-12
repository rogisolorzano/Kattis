#include <vector>
#include <math.h>
using namespace std;

// array {2, 4, 5, 8, 24, 33, 43, 56, 61, 82}
// target 24

/**
 * Moves left and right pointers to cut down possible values by 1/2 on every iteration.
 *
 * O(log(n)) time - half of array is excluded on every iteration
 * O(1) space - iterative w/ no additional space used
 */
int binarySearch(vector<int> array, int target) {
  int leftPointer = 0;
  int rightPointer = array.size() - 1;

  while (leftPointer <= rightPointer) {
    int centerPointer = floor((rightPointer + leftPointer) / 2);
    int centerValue = array[centerPointer];

    if (centerValue == target) {
      return centerPointer;
    }

    if (centerValue > target) {
      rightPointer = centerPointer - 1;
    } else {
      leftPointer = centerPointer + 1;
    }
  }

  return -1;
}
