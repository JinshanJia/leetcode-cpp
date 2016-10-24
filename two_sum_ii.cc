#include <unordered_map>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum < target) {
        left++;
      } else if (sum > target) {
        right--;
      } else {
        // result index start from 1
        return vector<int>({left + 1, right + 1});
      }
    }
    throw runtime_error("no result");
  }
};

int main() {
  Solution s;
  vector<int> test({0, 0, 3, 4});
  vector<int> result = s.twoSum(test, 0);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}

