#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class DSU{

public:

    vector<int> parent;
    vector<int> size;

    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i =0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; 
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }

};


int LCS(vector<int> &v){
    unordered_map<int, int> mp;

    for(int i =0; i < v.size(); i++){
        mp[v[i]] = i;
    }

    DSU ds(v.size());

    for(auto it: mp){
        if(mp.find(it.first - 1) != mp.end()){
        int u = mp[it.first-1];
            if(ds.findParent(u) != ds.findParent(it.second)){
                ds.unionBySize(it.second,u);
            }
        }
    }

    int ans = 0;

    for(int i=0; i < v.size(); i++){
        ans = max(ans, ds.size[i]);
    }

    return ans;


}

int main(){

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i =0; i < n; i++){
        cin >> v[i];
    }

    cout << LCS(v);

    return 0;
}