//You are given an n x n 2D matrix representing an image, 
//rotate the image by 90 degrees (clockwise).

//You have to rotate the image in-place, 
//which means you have to modify the input 2D matrix directly. 
//DO NOT allocate another 2D matrix and do the rotation.


//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [[7,4,1],[8,5,2],[9,6,3]]

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void rotate(vector<vector<int>> &v){
    int n = v.size();
    for(int i=0; i <= n-2; i++){
        for(int j = i+1; j <= n-1; j++){
            swap(v[i][j], v[j][i]);
        }
    }

    for(int i =0; i < n; i++){
        reverse(v[i].begin(), v[i].end());
    }

}


int main(){
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    rotate(v);

    for(auto i: v){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }


}