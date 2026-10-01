class Solution {
public:  
    static bool comp(vector<int>&first, vector<int>&second){
        return first[1] < second[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       int n = intervals.size();
       sort(intervals.begin(),intervals.end(),comp);
       int remove = 0 ;

       int last_time = intervals[0][1];

       for(int i = 1 ; i<n ; i++){
          if(intervals[i][0] < last_time ) {
            remove++;
          }
          else{
            last_time = intervals[i][1];
          }
       } 
       return remove;
    }
};