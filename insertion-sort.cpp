#include <vector>
using namespace std;

/**
 * Insertion sort implementation.
 *
 * O(n^2) time average
 * O(1) space
 */
vector<int> insertionSort(vector<int> array) {
  for (int i = 1; i < array.size(); i++) {
    int current = i;
    for (int j = i - 1; j >= 0; j--) {
      if (array[current] < array[j]) {
        swap(array[current], array[j]);
        current--;
      } else {
        break;
      }
    }
  }

  return array;
}
