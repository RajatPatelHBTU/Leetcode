class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[n-1];

        int minL = min(first.size(),last.size());
        string ans = "";
        for(int i = 0 ; i < minL ; i++){
            if(first[i] != last[i]) break;

            ans += first[i];
        }
        return ans;
    }
};