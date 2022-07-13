class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> answer;
        for (int i = 1; i <= nums.size(); i+=2) {
            answer.insert(answer.end(), nums[i-1], nums[i]);
        }
        return answer;
    }
};