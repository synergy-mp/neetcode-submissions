// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board){
//         for(int row =0 ; row<9; row++){
//             unordered_set<char> seen;
//             for(int i=0;i<9;i++){
//                 if(board[row][i]== '.')continue;
//                 if(seen.count(board[row][i])) return false;
//                 seen.insert(board[row][i]);

//             }
//         }
//         for(int col=0;col<9;col++){
//             unordered_set<char>seen;
//             for(int i=0;i<9;i++){
//                 if(board[i][col]== '.')continue;
//                 if(seen.count(board[i][col])) return false;
//                 seen.insert(board[i][col]);
//             }

//         }

//         for(int square=0; square<9;square++){
//             unordered_set<char> seen;
//             for(int i=0; i<3;i++){
//                 for(int j=0;j<3;j++){
//                     int row =(square/3)*3+i;
//                     int col= (square%3)*3+j;
//                     if(board[row][col]=='.')continue;
//                     if(seen.count(board[row][col]))return false;
//                     seen.insert(board[row][col]);
//                 }
//             }
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board){
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int,int>, unordered_set<char>> squares;

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.')continue;
                pair<int,int> squarekey={r/3,c/3};
                if(rows[r].count(board[r][c]) || cols[c].count(board[r][c])|| squares[squarekey].count(board[r][c])){
                    return false;
                }
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squarekey].insert(board[r][c]);
            }
        }
        return true;
        
    }

};