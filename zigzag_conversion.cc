#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows <= 1 || s.size() == 0) {
      return s;
    }
    string result;
    for (int row = 0; row != numRows; ++row) {
      int index = row;
      while (index < s.size()) {
        result += s[index];
        if (row > 0 && row < numRows - 1) {
          int temp = index + (numRows - row - 1) * 2;
          if (temp < s.size()) {
            result += s[temp];
          }
        }
        index += (numRows - 1) * 2;
      }
    }
    return result;
  }
};

int main() {
  vector<string> testVector = {"", "PAYPALISHIRING", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  Solution s;
  for (string test : testVector) {
    cout << test << " with 1: " << s.convert(test, 1) << endl;
    cout << test << " with 2: " << s.convert(test, 2) << endl;
    cout << test << " with 3: " << s.convert(test, 3) << endl;
    cout << test << " with 4: " << s.convert(test, 4) << endl;
    cout << "==========" << endl;
  }
}