class Solution {
    unordered_map<int, unordered_set<int>> aList;
    
    bool DFS(int node, int dest, unordered_set<int>& gray) {
        // check for cycle
        if(gray.find(node) != gray.end()) 
            return false;
        
        if(node == dest && aList[node].size() == 0) return true;
        if(aList.find(node) == aList.end()) return false;
        
        // add node to the gray set to track for cycles
        gray.insert(node);
        
        for(auto nb : aList[node]) {
            auto res = DFS(nb, dest, gray);
            if(!res) return false;
        }
        
        gray.erase(node);
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        for(const auto& e : edges) aList[e[0]].insert(e[1]);
        unordered_set<int> gray;
        auto ans = DFS(source, destination, gray);
        return ans;
    }
};
