#include<string>

using namespace std;

char shiftCharacterBy(int n, char c) {
  int newChar = c + n;
  return (newChar > 122) ? 96 + (newChar % 122) : newChar;
}

/**
 * Shifts each character by the key amount.
 *
 * O(n) time
 * O(1) space - mutates string in place
 */
string caesarCypher(string str, int key) {
  int newKey = key % 26;

  for (int i = 0; i < str.size(); i++) {
    str[i] = shiftCharacterBy(newKey, str[i]);
  }

  return str;
}
