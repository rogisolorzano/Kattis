#include <vector>
using namespace std;

/**
 * Bubble sort implementation.
 *
 * O(n^2) time on average
 * O(1) space
 */
vector<int> bubbleSort(vector<int> array) {
  int swapped = true;
  int rightPointer = array.size() - 1;

  while (swapped) {
    swapped = false;

    for (int i = 0; i < rightPointer; i++) {
      if (array[i] > array[i + 1]) {
        swap(array[i], array[i + 1]);
        swapped = true;
      }
    }

    rightPointer--;
  }

  return array;
}
