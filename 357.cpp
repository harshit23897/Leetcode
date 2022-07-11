class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count[n+1];
        count[0] = 1;
        int answer = 1;
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                answer = 9;
            } else {
                answer  = answer * (9 - i + 2);
            }
            count[i] = count[i-1] + answer;
        }
        
        return count[n];
    }
};