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
  unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  string reverseVowels(string s) {
    vector<string::size_type> toBeReplacedPosition;
    for (string::size_type i = 0; i != s.size(); ++i) {
      if (vowelSet.find(s[i]) != vowelSet.end()) {
        toBeReplacedPosition.push_back(i);
      }
    }

    if (toBeReplacedPosition.size() == 0) {
      return s;
    }

    string::size_type left = 0, right = toBeReplacedPosition.size() - 1;
    while (left < right) {
      char c = s[toBeReplacedPosition[left]];
      s[toBeReplacedPosition[left]] = s[toBeReplacedPosition[right]];
      s[toBeReplacedPosition[right]] = c;
      left++;
      right--;
    }
    return s;
  }
};

int main() {
  vector<string> testVector = {"", "a", "ab", "abc", "abab", "asdfrwq", "hello", "aeiou", "AaEabaBA", " "};
  Solution solution;
  for (string s : testVector) {
    cout << s << ": " << solution.reverseVowels(s) << endl;
  }
  return 0;
}