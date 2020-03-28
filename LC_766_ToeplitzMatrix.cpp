class Solution {
    bool validDiagonal(vector<vector<int>>& matrix, int r, int c) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int base = matrix[r][c];
        for(int i = r + 1, j = c + 1; i < ROWS && j < COLS; i++, j++) {
            if(matrix[i][j] != base) return false;
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return true;
        
        for(int r = 0; r < matrix.size(); r++) {
            if(!validDiagonal(matrix, r, 0)) return false;
        }
        for(int c = 0; c < matrix[0].size(); c++) {
            if(!validDiagonal(matrix, 0, c)) return false;
        }
        return true;
    }
};
