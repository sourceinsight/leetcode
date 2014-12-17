/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution 
{
public:
    bool isValidSudoku(vector<vector<char> > &board) 
    {
        const int cnt = 9;
        bool row_used[cnt][cnt] = {false};
        bool col_used[cnt][cnt] = {false};
        bool area_used[cnt][cnt] = {false};
        
        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[r].size(); c++)
            {
                if (board[r][c] == '.')
                    continue;
                int idx = board[r][c] - '0' - 1;
                
                // 检查 行
                if (row_used[r][idx] == true)
                {
                    return false;
                }
                row_used[r][idx] = true;
                
                // 检查 列
                if (col_used[c][idx] == true)
                {
                    return false;
                }
                col_used[c][idx] = true;
                
                // 检查sub-boxes area的取值来区分这个9个sub-boxes
                int area = (r / 3) * 3 + (c / 3);
                if (area_used[area][idx] == true)
                {
                    return false;
                }
                area_used[area][idx] = true;
            }
        }
        
        return true;
    }
};
