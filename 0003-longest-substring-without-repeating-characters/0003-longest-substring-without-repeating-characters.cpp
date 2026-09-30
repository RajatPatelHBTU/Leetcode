class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
            
            /* If current character s[r] 
            is already in the substring*/
            if (mp.find(s[r]) != mp.end()) {
                
                /* Move left pointer to the right
                of the last occurrence of s[r]*/
                l = max(mp[s[r]] + 1, l);
            }
            
            // Calculate the current substring length
            int len = r - l + 1;
            
            // Update maximum length found so far
            maxLen = max(len, maxLen);
            
            /* Store the index of the current
            character in the hash table*/
            mp[s[r]] = r;
            
            // Move right pointer to next position
            r++;
        }
       
        // Return the maximum length found
        return maxLen;
    }   
    
};