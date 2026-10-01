class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // update last seen index
            lastSeen[s[i] - 'a'] = i;

            // if all a, b, c have appeared
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }

        return count;
    }
};