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
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charMap;
    int length = 0;
    for (int windowRight = 0, windowLeft = 0; windowRight < s.size(); ++windowRight) {
      if (charMap.find(s[windowRight]) != charMap.end()) {
        windowLeft = windowLeft <= charMap.find(s[windowRight])->second ? charMap.find(s[windowRight])->second + 1 : windowLeft;
      }
      charMap[s[windowRight]] = windowRight;
      length = max(windowRight - windowLeft + 1, length);
    }
    return length;
  }   
};

int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << s.lengthOfLongestSubstring("bbbbbb") << endl;
  cout << s.lengthOfLongestSubstring("pwwkew") << endl;
  cout << s.lengthOfLongestSubstring("cdd") << endl;
  cout << s.lengthOfLongestSubstring("asdfa") << endl;
  cout << s.lengthOfLongestSubstring("tmmzuxt") << endl;


  return 0;
}