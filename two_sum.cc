#include <unordered_map>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> nums_map;
    for (int i = 0; i != nums.size(); ++i) {
      auto find = nums_map.find(target - nums[i]);
      if (find != nums_map.end()) {
        return vector<int>({find->second, i});
      } else {
        nums_map[nums[i]] = i;
      }
    }
    throw runtime_error("Cannot find result");
  }
};

int main() {
  Solution s;
  vector<int> test({0, 4, 3, 0});
  vector<int> result = s.twoSum(test, 0);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}
