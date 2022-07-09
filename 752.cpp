class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int answer = 1;
        queue<pair<string, int> > que;        
        set<string> invalid_elements;
        unordered_map<string, int> mp;        
        
        for (auto i = deadends.begin(); i != deadends.end(); i++) {
            invalid_elements.insert(*i);            
        }
        
        if (invalid_elements.find("0000") == invalid_elements.end()) {
            que.push({"0000", 0});
            mp["0000"] = 1;   
        }            
        
        while(que.empty() == false) {
            pair<string, int> top = que.front();
            que.pop();
            if (top.first == target) {
                return top.second;
            }
            for (int i = 1; i < 5; i++) {
                char firstElement = int(int(top.first[i-1] - '0') + 1) % 10 + '0';
                char secondElement = int(int(int(top.first[i-1] - '0') - 1) % 10 + 10) % 10 + '0'; 
                
                string nextString = top.first;
                nextString[i-1] = firstElement;
                string previousString = top.first;
                previousString[i-1] = secondElement;
                // cout << top.first << " " << nextString << " " << previousString << endl;
                if (invalid_elements.find(nextString) == invalid_elements.end() && mp[nextString] == 0) {
                    mp[nextString] = 1;
                    que.push({nextString, top.second + 1});
                }
                if (invalid_elements.find(previousString) == invalid_elements.end() && mp[previousString] == 0) { 
                    mp[previousString] = 1;
                    que.push({previousString, top.second + 1});
                }
            }
        }
        
        return -1;
    }
};
