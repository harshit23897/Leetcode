class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_map<string, int> mp;
        
        vector<string> answer;        
        for (auto fold : folder) {
            int index = 0;
            int flag = 0;
            for(int x = 1; x < fold.length(); x++) {
                if (fold[x] == '/') {
                    string substr = fold.substr(0, x);
                    // cout << fold << " " << substr << endl;
                    if (mp[substr] != 0) {                        
                        flag++;
                        break;
                    }
                }
            }
            if (!flag) {
                answer.push_back(fold);
            }
            mp[fold]++;
        }
        
        return answer;
    }
};