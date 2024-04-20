#include<iostream>
#include<vector>
#include<string>

using namespace std;


bool search(vector<vector<char>>& board, string &word, int i, int j, int n, int m, int ind){
    if(ind == word.size()) return true;

    if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '0' || board[i][j] != word[ind]) return false;

    char temp = board[i][j];
    board[i][j] = '0';

    int dr[]{1,-1,0, 0};       
    int dc[]{0, 0,1,-1,};
    
    for(int r=0; r < 4; r++){
        if(search(board, word, i + dr[r], j + dc[r], n, m, ind+1))
            return true;
    }
    
    board[i][j] = temp;

    return false;
}



bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    
    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(search(board, word, i, j, n, m, 0)) return true;
        }
    }

    return false;
}




int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for(int i=0; i < n; i++){
        for(int j =0; j < m; j++){
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    cout << exist(board, word);


    return 0;
}