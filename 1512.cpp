class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int answer = 0;
        for (auto i : nums) {
            answer += mp[i];
            mp[i]++;
        }
        return answer;
    }
};