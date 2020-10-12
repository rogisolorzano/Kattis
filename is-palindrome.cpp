#include <math.h>
#include <stack>
using namespace std;

/**
 * Pushes the chars of the first half of the string onto a stack.
 * While traversing the second of the string, pops the chars off the stack
 * and compares w/ the current letter.
 *
 * O(n) time - traverses the array once.
 * O(n) space - stack size depends on the size of the array.
 */
bool isPalindrome(string str) {
  int isEven = (str.size() % 2) == 0;
  int halfIndex = floor(str.size() / 2);
  stack<int> charStack;

  for (int i = 0; i < str.size(); i++) {
    if (i < halfIndex) {
      charStack.push(str[i]);
    } else if ((!isEven && i > halfIndex) || (isEven && i >= halfIndex)) {
      if (charStack.top() != str[i]) {
        return false;
      }
      charStack.pop();
    }
  }

  return true;
}

/**
 * Uses two pointers to compare the left and right ends of the string.
 *
 * O(n) time - traverses the array once.
 * O(1) space - traverses array in place. Uses no additional space.
 */
bool isPalindromePointers(string str) {
  int leftPointer = 0;
  int rightPointer = str.size() - 1;

  while (leftPointer <= rightPointer) {
    if (str[leftPointer] != str[rightPointer]) {
      return false;
    }
    leftPointer++;
    rightPointer--;
  }

  return true;
}
