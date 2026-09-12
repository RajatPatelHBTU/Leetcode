class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> st;

        for (auto &p : points) {
            st.insert({p[0], p[1]});
        }

        int ans = INT_MAX;

        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                
                if (x1 == x2 || y1 == y2)
                    continue;

                
                if (st.count({x1, y2}) &&
                    st.count({x2, y1})) {

                    int area = abs(x2 - x1) * abs(y2 - y1);

                    ans = min(ans, area);
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};