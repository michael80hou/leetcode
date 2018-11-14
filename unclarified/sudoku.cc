#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0, 0);
    }

private:

    bool is_valid(vector<vector<char>>& board, int i, int j, char v) {
        bool res = true;
        
        for(int row = 0; row < 9; row++) {
            char c = board[row][j];
            if('.' != c) {
                if(v == c) {
                    return false;
                }
            }
        }
        
        for(int column = 0; column < 9; column++) {
            char c = board[i][column];
            if('.' != c) {
                if(v == c) {
                    return false;
                }
            }
        }
        
        int sub_row = i / 3 ;
        int sub_column = j / 3;
            
        for(int row = sub_row; row < sub_row + 3; row++) {
            for(int column = sub_column; column < sub_column + 3; column++) {
                char c = board[row][column];
                if('.' != c) {
                    if(v == c) {
                        return false;
                    }
                }                
            }
        }
        return res;
    }

    
    bool backtracking(vector<vector<char>>& board, int i, int j) {
        if(9 == i) {
            return true;
        } else if(9 == j) {
            return backtracking(board, i + 1, 0);
        }
        
        char c = board[i][j];
        if('.' != c) {
            return backtracking(board, i, j + 1);
        }
        
        for(char v = '1'; v <= '9'; v++) {
            if(is_valid(board, i, j, v)) {
                board[i][j] = v;
                if(backtracking(board, i, j + 1)) {
                    return true;
                } else {
                    board[i][j] = '.';
                }
            }
        }
        
        return false;
    }

};



int main() {
    vector<vector<char>> board = {{'5','3','4','6','7','8','9','1','2'},{'6','7','2','1','9','5','3','4','8'},{'1','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','2','4','8','5','6'},{'9','6','1','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}};

    class Solution* ptr = new Solution();
    ptr->solveSudoku(board);
    for(auto i : board) {
        for(auto j : i) {
            cout << j <<" ";
        }
        cout << endl;
    }
    return 0;
}
