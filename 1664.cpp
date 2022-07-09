class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> evenSumLeft(nums.size(), 0);
        vector<int> evenSumRight(nums.size(), 0);
        vector<int> oddSumLeft(nums.size(), 0);
        vector<int> oddSumRight(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); i++) {            
            evenSumLeft[i] = ((i > 0) ? evenSumLeft[i-1] : 0) + ((i % 2 == 0) ? nums[i] : 0);            
            oddSumLeft[i] = ((i > 0) ? oddSumLeft[i-1] : 0) + ((i % 2 == 1) ? nums[i] : 0);            
        }
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            evenSumRight[i] = ((i < nums.size() - 1) ? evenSumRight[i + 1] : 0) + ((i % 2 == 0) ? nums[i] : 0);
            oddSumRight[i] = ((i < nums.size() - 1) ? oddSumRight[i + 1] : 0) + ((i % 2 == 1) ? nums[i] : 0);
        }
        
        int answer = 0;
        for (int i = 0; i < nums.size(); i++) {
            int evenSumAtPosition = ((i > 0) ? evenSumLeft[i-1] : 0) + ((i < nums.size() - 1) ? oddSumRight[i+1] : 0);
            int oddSumAtPosition = ((i > 0) ? oddSumLeft[i-1] : 0) + ((i < nums.size() - 1) ? evenSumRight[i+1] : 0);
            
            if (evenSumAtPosition == oddSumAtPosition) {
                answer++;
            }
        }
        
        return answer;
    }
};