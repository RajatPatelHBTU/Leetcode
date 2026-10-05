class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       int threshold = n/2;
       unordered_map<int,int> mpp;

       for(int num : nums){
        mpp[num]++;

        if(mpp[num] > threshold ) return num;
       }
     
     return -1;

    }
};