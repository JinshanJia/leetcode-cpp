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
  int myAtoi(string str) {
    int currentPoint = 0;
    // ignore spaces on the left.
    while (currentPoint < str.size()) {
      if (str[currentPoint] != ' ') {
        break;
      }
      currentPoint++;
    }

    if (currentPoint == str.size()) {
      return 0;
    }

    int multiplier = 1;
    if (str[currentPoint] == '+') {
      currentPoint++;
    } else if (str[currentPoint] == '-') {
      multiplier = -1;
      currentPoint++;
    }

    bool overflow = false;
    int sum = 0;
    while (currentPoint < str.size() && (str[currentPoint] >= '0' && str[currentPoint]  <= '9')) {
      if ((numeric_limits<int>::max() - (str[currentPoint] - '0')) / 10 < sum) {
        overflow = true;
        break;
      } 
      sum = sum * 10 + (str[currentPoint] - '0');
      currentPoint++;
    }
    if (overflow || sum < 0) {
      return multiplier == 1 ? numeric_limits<int>::max() : numeric_limits<int>::min();
    }
    return multiplier * sum;
  }
};

int main() {
  vector<string> testVector = {"", "00000000000000000", "-", "-0", "+0", "-012", "21321230", "adf", "     -1230412jljfaeio", "    10522545459", "-111111111111111", "+111111111111111111", "2147483647", "-2147483648", "2147483648"};
  Solution s;
  for (string test : testVector) {
    cout << test << ": " << s.myAtoi(test) << endl;
  }
}