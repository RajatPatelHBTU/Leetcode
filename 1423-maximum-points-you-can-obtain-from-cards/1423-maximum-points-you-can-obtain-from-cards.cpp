class Solution {
public:
    // Function to return maximum score by picking k cards from either end
    int maxScore(vector<int>& cardPoints, int k) {
        // Get the total number of cards
        int n = cardPoints.size();

        // Calculate initial sum by picking first k cards from front
        int total = 0;
        for (int i = 0; i < k; ++i) {
            total += cardPoints[i];
        }

        // Store current max score
        int maxPoints = total;
        int right = n-1;

        // Move the window from front to back k times
        for (int i = k-1; i >= 0; i--) {
            // Subtract card from front
            total -= cardPoints[i];

            // Add card from back
            total += cardPoints[right];
            right--;

            // Update max score if needed
            maxPoints = max(maxPoints, total);
        }

        // Return the best score
        return maxPoints;
    }
};