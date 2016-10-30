#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
  string reverseString(string s) {
    if (s.size() == 0) {
      return s;
    }
    string::size_type left = 0, right = s.size() - 1;
    while (left < right) {
      char c = s[left];
      s[left] = s[right];
      s[right] = c;
      left++;
      right--;
    }
    return s;
  }
};

int main() {
  vector<string> testVector = {"", "a", "ab", "abc", "abab", "asdfrwq", "hello"};
  Solution solution;
  for (string s : testVector) {
    cout << s << ": " << solution.reverseString(s) << endl;
  }
  return 0;
}