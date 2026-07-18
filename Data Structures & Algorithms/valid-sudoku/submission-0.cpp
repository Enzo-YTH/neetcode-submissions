class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> blocks[9];
        
        for(int r = 0; r < 9; r++)
            for(int c = 0; c < 9; c++) {
                char val = board[r][c];
                if(val == '.')
                    continue;

                // #1. row comparison
                if(rows[r].find(val) != rows[r].end())
                    return false;
                rows[r].insert(val);

                // #2. col comparison
                if(cols[c].find(val) != cols[c].end())
                    return false;
                cols[c].insert(val);

                // #3. blocks comparison
                if(blocks[(r/3) * 3 + (c/3)].find(val) != blocks[(r/3) * 3 + (c/3)].end())
                    return false;
                blocks[(r/3) * 3 + (c/3)].insert(val);
            }
        return true;
    }
};
