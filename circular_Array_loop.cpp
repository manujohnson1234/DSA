// you are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

// If nums[i] is positive, move nums[i] steps forward, and
// If nums[i] is negative, move nums[i] steps backward.
// Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

// A cycle in the array consists of a sequence of indices seq of length k where:

// Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
// Every nums[seq[j]] is either all positive or all negative.
// k > 1
// Return true if there is a cycle in nums, or false otherwise.

#include<iostream>
#include<vector>

using namespace std;



class Solution {
    bool dfs(vector<int> &nums, int v, vector<int> &vis, int prev){

        int next;
        int n = nums.size();
        
        if(nums[v] > 0){
            int steps = nums[v] % n;

            if(n-v-1 < steps){
                steps -= (n-v-1);
                next = steps - 1;
            }else{
                next = v + steps;
            }
        }else{
            int dup = nums[v] * -1;
            int steps = dup % n;
            if(v-steps < 0){
                steps -= v;
                next = n-steps;
            }else{
                next = v - steps;
            }
        }
        if(nums[prev] > 0 && nums[v] < 0 || nums[prev] < 0 && nums[v] > 0 || v == next) return false;
        if(vis[v]) return true;
        vis[v] = 1;

        // cout << next << endl;
        bool ch = dfs(nums, next, vis, v);
        vis[v] = 0;
        return ch;
    }





public:
    bool circularArrayLoop(vector<int>& nums) {           

        int n = nums.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for(int i =0; i < n; i++){
            if(!vis[i]){
                cnt++;
                cout << cnt << endl;
                if(dfs(nums, i, vis, i)) return true;
            }
        }

        return false;
    }
};


int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i =0; i < n; i++){
        cin >> v[i];
    }

    Solution sol;
    cout << sol.circularArrayLoop(v);
}
