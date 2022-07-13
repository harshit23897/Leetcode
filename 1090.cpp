class Solution {
public:
    static bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
    {
        return (a.first > b.first);
    }
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int> > comb;
        for (int i = 0; i < values.size(); i++) {
            comb.push_back({values[i], labels[i]});
        }
        
        sort(comb.begin(), comb.end(), sortbysec);
        
        unordered_map<int, int> mp;
        int answer = 0;
        int totalNumbers = 0;
        for (auto val : comb) {
            if (totalNumbers >= numWanted) {
                break;
            }
            // cout << val.first << " " << val.second << " " << mp[val.second] << endl;
            if (mp[val.second] < useLimit) {
                mp[val.second]++;
                totalNumbers++;
                answer += val.first;
            }
        }
        
        return answer;
    }
};