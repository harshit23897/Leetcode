class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddIndex = 1;
        for (int i = 0; i < nums.size(); i+=2) {
            if (i % 2 == 0 && nums[i] % 2 != 0) {
                for (int j = oddIndex; j < nums.size(); j+=2) {
                    if (nums[j] % 2 != 1) {
                        swap(nums[i], nums[j]);
                        oddIndex = j+2;
                        break;
                    }
                }
            }
        }
        return nums;
    }
};