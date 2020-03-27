class Solution {
    bool endsWith(string w, string match) {
        for(int i = w.length() - 1, j = match.length() - 1; i >= 0 && j >= 0; i--, j--) {
            if(w[i] != match[j]) return false;
        }
        return true;
    }
    vector<string> getMatchingCandidates(string match, vector<string>& words) {
        vector<string> res;
        for(auto w : words) {
            // auto pos = w.find(match);
            // // cout << match << " " << w << " " << pos << "\n";
            // if(pos == string::npos) continue;
            // if(w.length() - pos != match.length()) continue;
            if(!endsWith(w, match)) continue;
            res.push_back(w);
        }
        return res;
    }
public:
    void spaces(int level) {
        for(int i = 0; i < level; i++) cout << ".";
    }
    vector<vector<string>> gRes;
    void helper(vector<string>& chosen, vector<string>& words, int level) {
        if(!chosen.empty() && chosen.size() == chosen[0].length()) {
            vector<string> temp = chosen;
            std::reverse(temp.begin(), temp.end());
            gRes.insert(gRes.begin(), temp);
            return;
        }
        
        vector<string> candidates;
        if(chosen.empty()) {
            std::copy(words.begin(), words.end(), std::back_inserter(candidates));
        } else {
            auto m = chosen.size();
            string match = "";
            auto wordLen = chosen[0].length();
            for(int i = m - 1; i >= 0; i--) match += chosen[i][wordLen - m - 1];
            candidates = getMatchingCandidates(match, words);
            if(candidates.empty()) {
                // cout << "No matching candidates for Match " << match << "\n";
                return;
            }
        }
        
        for(auto c : candidates) {
            // chosen.insert(chosen.begin(), c);    // choose
            chosen.push_back(c);
            // cout << "Choosing " << c << "\n";
            helper(chosen, words, level + 1);
            // chosen.erase(chosen.begin());      // Unchoose / backtrack
            // chosen.pop_front();
            chosen.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<string> chosen;
        helper(chosen, words, 0);
        return gRes;
    }
};
