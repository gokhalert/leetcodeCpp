class Solution {
    vector<vector<int>> memo;
public:
    
    bool DFS(vector<vector<int>>& matrix, unordered_set<int>& visited, int cell, bool pacific) {
        
        if(visited.find(cell) != visited.end()) return false;
        
        int r = cell / matrix[0].size();
        int c = cell - (r * matrix[0].size());
        
        if(pacific && memo[r][c] == 0x1) return true;
        if(!pacific && memo[r][c] == 0x2)  return true;
        
        if(pacific && (r == 0 || c == 0)) {
            memo[r][c] |= 0x1;
            return true;
        }
        if(!pacific && (r == matrix.size() - 1 || c == matrix[0].size() - 1)) {
            memo[r][c] |= 0x2;
            return true;
        }
        
        visited.insert(cell);   // mark cell as visited
        
        int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
        for(int k = 0; k < 4; k++) {
            int x = dx[k] + r, y = dy[k] + c;
            if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
                continue;
            if(matrix[x][y] > matrix[r][c]) continue;
            
            auto nbCellID = x * matrix[0].size() + y;
            auto res = DFS(matrix, visited, nbCellID, pacific);
            if(res) {
                if(pacific) memo[r][c] |= 0x1;
                else memo[r][c] |= 0x2;
                return true;
            }
        }
        return false;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.empty()) return res;
        
        memo.resize(matrix.size());
        for(auto& row : memo) row.resize(matrix[0].size());
        
        for(auto& row : memo) for(auto& cell : row) cell = 0;
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                unordered_set<int> visited;
                visited.clear();
                auto cell = i * matrix[0].size() + j;
                auto p = DFS(matrix, visited, cell, true);
                visited.clear();
                auto a = DFS(matrix, visited, cell, false);
                if(p && a) {
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
