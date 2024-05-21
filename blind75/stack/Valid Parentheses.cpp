class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty())return false;
                char t = st.top();
                st.pop();

                if(t == '[' && s[i] == ']') continue;
                if(t == '(' && s[i] == ')') continue;
                if(t == '{' && s[i] == '}') continue;

                return false;

            }
        }

        if(st.empty())
            return true;
        return false;
    }
};