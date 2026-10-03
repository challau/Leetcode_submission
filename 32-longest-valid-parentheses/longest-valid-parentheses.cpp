class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int current = 0;
        int length = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                st.pop();
                if(!st.empty()){
                    current = i - st.top();
                    length = max(length, current);
                }else{
                    st.push(i);
                }
            }
        }
        return length;
    }
};