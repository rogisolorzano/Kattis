#include <vector>
using namespace std;

/**
 * Selection sort implementation.
 *
 * O(n^2) time
 * O(1) space
 */
vector<int> selectionSort(vector<int> array) {
  int smallestPointer = 0;
	
  for (int i = 0; i < array.size(); i++) {
    smallestPointer = i;

    for (int j = smallestPointer; j < array.size(); j++) {
      if (array[j] < array[smallestPointer]) {
        smallestPointer = j;
      }
    }

    swap(array[i], array[smallestPointer]);
  }

  return array;
}
