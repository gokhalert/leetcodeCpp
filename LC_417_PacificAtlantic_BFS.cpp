class Solution {
    vector<vector<int>> memo;
public:
    int getCell(int r, int c, vector<vector<int>>& matrix) {
        return r * matrix[0].size() + c;
    }
    
    void BFS(vector<vector<int>>& matrix, bool pacific) {
        std::queue<int> q;
        unordered_set<int> visited;
        int rows = matrix.size(), cols = matrix[0].size();
        if(pacific) {
            for(int i = 0; i < cols; i++) {
                auto cell = getCell(0, i, matrix);
                visited.insert(cell);
                q.push(cell);
            }
            for(int i = 0; i < rows; i++) {
                auto cell = getCell(i, 0, matrix);
                visited.insert(cell);
                q.push(cell);
            }
        } else {
            for(int i = 0; i < rows; i++) {
                auto cell = getCell(i, cols - 1, matrix);
                visited.insert(cell);
                q.push(cell);
            }
            for(int i = 0; i < cols; i++) { 
                auto cell = getCell(rows - 1, i, matrix);
                visited.insert(cell);
                q.push(cell);
            }
        }
        
        while(!q.empty()) {
            auto cell = q.front(); q.pop();
            int r = cell / cols;
            int c = cell - r * cols;
            if(pacific) memo[r][c] |= 0x1;
            else memo[r][c] |= 0x2;
            
            int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
            for(int i = 0; i < 4; i++) {
                int x = dx[i] + r, y = dy[i] + c;
                if(x < 0 || x >= rows || y < 0 || y >= cols) continue;
                auto nbCell = getCell(x, y, matrix);
                if(visited.find(nbCell) != visited.end()) continue;
                if(matrix[x][y] < matrix[r][c]) continue;
                visited.insert(nbCell);
                q.push(nbCell);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.empty()) return res;
        
        memo.resize(matrix.size());
        for(auto& row : memo) row.resize(matrix[0].size());
        for(auto& row : memo) for(auto& cell : row) cell = 0;
        
        BFS(matrix, true);
        BFS(matrix, false);
        
        // the memo matrix is now populated
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(memo[i][j] == 0x3) {
                    vector<int> r;
                    r.push_back(i);
                    r.push_back(j);
                    res.push_back(std::move(r));
                }
            }
        }
        return res;
    }
};
