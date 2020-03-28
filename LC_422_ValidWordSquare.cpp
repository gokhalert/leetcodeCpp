class Solution {
    bool helper(vector<string>& words, int start) {
        if(start == words.size() - 1) return true;
        
        for(int i = start; i < words.size(); i++) {
            if(words[i][start] != words[start][i]) return false;
        }
        return helper(words, start + 1);
    }
public:
    bool validWordSquare(vector<string>& words) {
        if(words.empty()) return true;
        return helper(words, 0);
    }
};
