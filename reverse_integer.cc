#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <limits>
#include <cmath>

using namespace std;
class Solution {
public:
  int reverse(int x) {
    int result = 0;
    bool isNegative = x < 0;
    x = x < 0 ? x : -1 * x;
    while (x != 0) {
      if (isOverFlow(result, x % 10)) {
        return 0;
      }
      result = result * 10 + x % 10;
      x /= 10;
    }
    return isNegative ? result : result == numeric_limits<int>::min() ? 0 : result * -1;
  }

  /*2147483647 -2147483648*/

private:
  bool isOverFlow(int a, int b) {
    if ((numeric_limits<int>::min() - b) / 10 > a) {
      return true;
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> test = {0, -100, 1, numeric_limits<int>::min(), numeric_limits<int>::max(), 1000000003, -1000000003, 123, -321} ;
  for (int t : test) {
    cout << t << ": " << s.reverse(t) << endl;
  }
  return 0;
}