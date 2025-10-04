class Solution {
public:
    void backtrack(string &s, vector<bool> &used, string &current, set<string> &result) {
        if (current.size() == s.size()) {
            result.insert(current);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (used[i]) continue;

            used[i] = true;
            current.push_back(s[i]);
            backtrack(s, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }

    vector<string> findPermutation(string S) {  
        set<string> result;
        string current = "";
        vector<bool> used(S.size(), false);
        sort(S.begin(), S.end());

        backtrack(S, used, current, result);

        return vector<string>(result.begin(), result.end());
    }
};
