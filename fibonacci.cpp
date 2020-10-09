using namespace std;

// n 8

/**
 * Recursive solution.
 *
 * O(2^n) time - The first n calls two getFibonacci, and each of those getFibonacci call two more,
 *   and so on. The function calls go from 1 -> 2 -> 4 -> 8.. increasing exponentially to 2 to
 *   the nth power. Utilizing memoization will reduce the time complexity of computations
 *   to O(n) time and O(n) space. The iterative solution below is better though, since it uses
 *   O(n) time and O(1) space.
 * O(n) space - We'll always have n functions on the call stack at a time.
 */
int getFibonacci(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  }

  return getFibonacci(n - 1) + getFibonacci(n - 2);
}

/**
 * Iterative solution.
 *
 * O(n) time
 * O(1) space
 */
int getFibonacciIterative(int n) {
  if (n == 1) {
    return 0;
  }

  int temp;
  array<int, 2> values = {0, 1};

  for (int i = 2; i < n; i++) {
    temp = values[1];
    values[1] = values[0] + values[1];
    values[0] = temp;
  }

  return values[1];
}
