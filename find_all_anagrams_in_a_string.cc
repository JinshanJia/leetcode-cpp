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
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int left = 0;
    int right = 0;
    initiatePMap(p);
    while (left < s.size()) {
      // If the character is not in p string, restart the sliding window after
      // the right pointer.
      if (pMap.find(s[right]) == pMap.end()) {
        left = right + 1;
        right = left;
        sMap.clear();
        continue;
      }
      // If current character is not in sliding window map, add it.
      if (sMap.find(s[right]) == sMap.end()) {
        sMap[s[right++]] = 1;
      } else if (sMap.find(s[right])->second < pMap.find(s[right])->second)  {
        // when current character count is ismaller than p string, add one more.
        sMap[s[right++]] += 1;
      } else {
        // When we already got enough count of current string, add left pointer until
        // find the first same character and erase all the count before that.
        while (s[left] != s[right]) {
          if (sMap.find(s[left])->second == 1) {
            sMap.erase(s[left]);
          } else {
            sMap[s[left]] -= 1;
          }
          left++;
        }
        // when s[left] == s[right], we can just presend we counted s[right] and removed
        // s[left], so no need to update sMap.
        left++;
        right++;
      }
      if (right - left == p.size()) {
        result.push_back(left);
      }
    }

    return result;
  }
private:
  // The map contains characters and count numbers of string p.
  unordered_map<char, int> pMap;
  // The map contains characters and count of current sliding window of string s.
  unordered_map<char, int> sMap;

  void initiatePMap(const string& p) {
    for (int i = 0; i < p.size(); ++i) {
      if (pMap.find(p[i]) == pMap.end()) {
        pMap[p[i]] = 1;
      } else {
        pMap[p[i]] += 1;
      }
    }
  }
};

string pintVector(const vector<int>& v) {
  string result = "[";
  for (int i : v) {
    result = result + to_string(i) + ", ";
  }
  result += "]";
  return result;
}

int main() {
  Solution s;
  cout << " for a: " << pintVector(s.findAnagrams("", "a")) << endl;
  s = Solution();
  cout << "a for a: " << pintVector(s.findAnagrams("a", "a")) << endl;
  s = Solution();
  cout << "aba for a: " << pintVector(s.findAnagrams("aba", "a")) << endl;
  s = Solution();
  cout << "\"cbaebabacd\" for \"abc\" result is : " << pintVector(s.findAnagrams("cbaebabacd", "abc")) << endl;
  s = Solution();
  cout << "\"abab\" for \"ab\" result is : " << pintVector(s.findAnagrams("abab", "ab")) << endl;
}