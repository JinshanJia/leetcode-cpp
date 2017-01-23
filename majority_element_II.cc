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
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> result;
    if (nums.size() == 0) {
      return result; 
    }
    // At most has two results
    int count1 = 0, candidate1 = nums[0];
    int count2 = 0, candidate2 = nums[0];
    int index = 0;
    for (; index < nums.size(); ++index) {
      if (nums[index] != candidate1) {
        candidate2 = nums[index++];
        count2 = 1;
        break;
      } else {
        count1++;
      }
    }

    if (candidate1 == candidate2) {
      result.push_back(candidate1);
      return result;
    }

    for (; index < nums.size(); ++index) {
      if (candidate2 == nums[index]) {
        count2++;
      } else if (candidate1 == nums[index]) {
        count1++;
      } else if (count1 == 0) {
        candidate1 = nums[index];
        count1 = 1;
      } else if (count2 == 0) {
        candidate2 = nums[index];
        count2 = 1;
      } else {
        count1--;
        count2--;
      }
    }
    if (count1 < count2) {
      int tmp = candidate1;
      candidate1 = candidate2;
      candidate2 = tmp;
    }

    count1 = 0;
    count2 = 0;
    for (int num : nums) {
      if (num == candidate1) {
        count1++;
      } else if (num == candidate2) {
        count2++;
      }
    }
 
    if (count1 > nums.size() / 3) {
      result.push_back(candidate1);
    }

    if (count2 > nums.size() / 3) {
      result.push_back(candidate2);
    }
    return result;
  }
};

int main() {
  vector<int> test = {1, 2};
  Solution s;
  for (int r : s.majorityElement(test)) {
    cout << " " << r;
  }
  cout << endl;
  return 0;
}