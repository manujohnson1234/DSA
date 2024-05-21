class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        int pow = 1;
        for(int i = 1; i <= n; i++){
            if(i&(i-1)){
                ans[i] = ans[pow] + ans[i-pow];
            }else{
                pow = i;
                ans[i] = 1;
            }
        }

        return ans;
    }
};