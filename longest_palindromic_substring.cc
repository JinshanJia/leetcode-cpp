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
class Solution {
public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) {
      return s;
    }
    int size = 1;
    int leftIndex = 0;
    for (int center = 0; center != s.size(); ++center) {
      // string number is odd.
      int left = center - 1, right = center + 1;
      while (left >= 0 && right < s.size()) {
        if (tolower(s[left]) == tolower(s[right])) {
          if (size < right - left + 1) {
            size = right - left + 1;
            leftIndex = left;
          }
          left--;
          right++;
        } else {
          break;
        }
      }
      // string number is even.
      left = center -1;
      right = center;
      while (left >= 0 && right < s.size()) {
        if (tolower(s[left]) == tolower(s[right])) {
          if (size < right - left + 1) {
            size = right - left + 1;
            leftIndex = left;
          }
          left--;
          right++;
        } else {
          break;
        }
      }
    }
    return s.substr(leftIndex, size);
  }
};

int main() {
  Solution s;
  vector<string> test = {"Able was I ere I saw Elba afe", "AmanaplanacanalPanama", "", "aa", "aba"};
  for (string t : test) {
    cout << s.longestPalindrome(t) << endl;
  }
  return 0;
}