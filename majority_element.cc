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
  int majorityElement(vector<int>& nums) {
    int count = 1;
    int candidate = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (count == 0) {
        candidate = nums[i];
        count = 1;
      } else if (nums[i] == candidate) {
        count++;
      } else {
        count--;
      }
    }

    return candidate;
  }
};

int main() {
  vector<int> test = {1, 5, 5};
  Solution s;
  cout << s.majorityElement(test) << endl;
}