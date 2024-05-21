// Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i =0; i < strs.size(); i++){
            ans += to_string(strs[i].size());
            ans += '*';
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string cnt = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                cnt += s[i];
            }else{
                int num = stoi(cnt);
                string val = "";
                for(int j = 1; j <= num; j++){
                    val += s[i+j];
                }
                ans.push_back(val);

                i = i+num;
                cnt = "";
            }
        }
        return ans;
    }
};
