#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int count = 0;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if('.' == board[i][j]) {
                    count++;
                }
            }
        }

        backtracking(board, count);

    }

private:
    bool done = false;
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = false;
        vector<vector<int>> map_row(9, vector<int>(9, 1));
        vector<vector<int>> map_column(9, vector<int>(9, 1));
        vector<vector<int>> map_subbox(9, vector<int>(9, 1));

        for(int i = 0; i < 9; i++) {
            for(int j =0; j < 9; j++) {
                char c = board[i][j];
                int row = i;
                int column = j;
                int subbox = i / 3 * 3 + j / 3;
                if('.' == c) {
                    continue;
                } else {
                    int key = c - '1';

                    if( 0 == map_row[row][key] ||
                       0 == map_column[column][key] ||
                       0 == map_subbox[subbox][key] ) {
                        return res;
                    } else {
                        map_row[row][key] = 0;
                        map_column[column][key] = 0;
                        map_subbox[subbox][key] = 0;
                    }
                }

            }
        }

        res = true;
        return res;
    }

    void exclude_candidate(vector<vector<char>>& board, vector<int>& map, int i, int j) {
        int row = i;
        int column = j;
        int subbox_row = i / 3 * 3;
        int subbox_column = j / 3;

        //row
        for(int y = 0; y < 9; y++) {
            if('.' != board[row][y]) {
                int key = board[row][y] - '1';
                map[key] = 0;
            }
        }

        //column
        for(int x = 0; x < 9; x++) {
            if('.' != board[x][column]) {
                int key = board[x][column] - '1';
                map[key] = 0;
            }
        }

        //subbox
        for(int x = subbox_row; x < subbox_row + 3; x++) {
            for(int y = subbox_column; y < subbox_column + 3; y++) {
                if('.' != board[x][y]) {
                    int key = board[x][y] - '1';
                    map[key] = 0;
                }
            }
        }
    }
    
    void backtracking(vector<vector<char>>& board, int unsolved) {
        if(0 == unsolved) {
            done = true;
            return;
        }


        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if('.' == board[i][j]) {
                    vector<int> v(9,1);
                    exclude_candidate(board, v, i, j);
                    int stop = 1;
                    for(int k = 0; k < 9; k++) {
                        if(v[k]) {
                            stop = 0;
                            board[i][j] = k + '1';
                            backtracking(board, unsolved - 1);

                            if(done) {
                                return;
                            } else {
                                board[i][j] = '.'; //backtrack
                            }
                        }
                    }

                    if(stop) {
                        return;
                    }

                }
            }
        }
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
