class Solution {
public:
    

    void solve(vector<string> &result,string s, int open, int close, int n) {

        // Base case
        if (open == n && close == n) {
            result.push_back(s);
            return;
        }

        // Add opening bracket
        if (open < n) {
            solve(result,s + '(', open + 1, close, n);
        }

        // Add closing bracket
        if (close < open) {
            solve(result,s + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;

        solve( result,"", 0, 0, n);

        return result;
    }
};