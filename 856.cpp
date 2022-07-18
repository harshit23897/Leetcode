class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        int index = 0;
        
        while(index < s.size()) {
            char letter = s[index];
            if (letter == '(') {
                st.push("(");
            } else {
                if (st.top() == "(") {
                    st.pop();
                    st.push("1");
                } else {
                    int count = 0;
                    
                    while (st.top() != "(") {
                        count += stoi(st.top());
                        st.pop();
                    }
                    
                    st.pop();
                    st.push(to_string(2 * count));
                }                            
            }
            index++;
        }
        
        int answer = 0;
        while (st.empty() == false) {
            answer += stoi(st.top());
            st.pop();
        }
                
        return answer;
    }
};