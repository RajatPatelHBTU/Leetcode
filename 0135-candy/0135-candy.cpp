class Solution {
public:
    int candy(vector<int>& ratings) {
                int n = ratings.size();
 
        // Each child must receive at least one candy.
        vector<int> candies(n, 1);
 
        for (int i = 1; i < n; i++) {
            // If the current child has a higher rating
            // than the left child, they need more candies.
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
 
        for (int i = n - 2; i >= 0; i--) {
            // If the current child has a higher rating
            // than the right child, the right-side rule
            // must also be satisfied.
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
 
        // This stores the minimum total candies required.
        int totalCandies = 0;
 
        for (int candyCount : candies) {
            totalCandies += candyCount;
        }
 
        return totalCandies;
    }
};