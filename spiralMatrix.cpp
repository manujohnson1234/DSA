#include <iostream>
#include<vector>

using namespace std;


vector<int> spiralMatrix(vector<vector<int>> &matrix, int n, int m){
    vector<int> ans;

    int top = 0;
    int bottom = n-1;
    int right = m-1;
    int left = 0;

    while(top <= bottom && left <= right){

        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[right][i]);
        }
        right--;

        if(top <= bottom){
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left--;
        }


    }

    return ans;

}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> spiral = spiralMatrix(matrix, n, m);

    return 0;
}