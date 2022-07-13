class Solution {
public:
    bool canTransform(string start, string end) {        
        for (int i = 0; i < start.length()-1; i++) {
            if (start[i] == end[i]) {
                continue;
            }
            if (start[i] == 'X') {
                int startIndex = i+1;
                while (startIndex < start.length()) {
                    if (start[startIndex] != 'X') {
                        break;
                    }
                    startIndex++;
                }
                if (start[startIndex] == 'L') {
                    swap(start[i], start[startIndex]);
                }                   
                // i = startIndex - 1;
            } else if (start[i] == 'R') {
                int startIndex = i+1;
                while (startIndex < start.length()) {
                    if (start[startIndex] != 'R') {
                        break;
                    }
                    startIndex++;
                }
                if (start[startIndex] == 'X') {
                    swap(start[i], start[startIndex]);
                }                   
                // i = startIndex - 1;
            }
            // cout << start << " " << end << endl;
        }
        
        // cout << start << " " << end << endl;
        
        return start == end;
    }
};