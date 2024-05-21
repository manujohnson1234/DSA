// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i =0; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        int longest = 0;

        for(auto it: st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    cnt++;
                    x = x+1;
                }
                longest = max(cnt, longest);
            }
        }
        return longest;
    }
};