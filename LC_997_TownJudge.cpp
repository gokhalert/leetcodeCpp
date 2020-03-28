class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, int> inDegree, outDegree;
        
        // corner case
        if(N == 1 && trust.empty()) return 1;
        
        for(const auto& t : trust) {
            auto a = t[0], b = t[1];
            // a trusts b
            outDegree[a]++;
            inDegree[b]++;
        }
        
        for(auto it = inDegree.begin(); it != inDegree.end(); it++) {
            auto a = it->second;
            auto b = it->first;
            if(a == N - 1 && outDegree[b] == 0) 
                    return it->first;
        }
        return -1;
    }
};
