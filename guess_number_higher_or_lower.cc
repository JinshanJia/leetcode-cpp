#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <limits>
#include <ctype.h>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num) {
  return num == 1 ? 0 : num > 1 ? -1 : 1;
}
class Solution {
public:
  int guessNumber(int n) {
    int left = 1, right = n;
    while(right >= left) {
      int mean = (right - left) / 2 + left;
      int g = guess(mean);
      if (g == 0) {
        return mean;
      } else if (g == -1) {
        right = mean - 1;
      } else {
        left = mean  + 1;
      }
    }
    return -1;
  }
};


int main() {
  Solution s;
  cout << s.guessNumber(1) << endl;
}