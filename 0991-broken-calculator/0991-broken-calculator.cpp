class Solution {
public:
    int brokenCalc(int startValue, int target) {
      int opr = 0 ;

      while(target > startValue){
        if(target % 2 == 1 ) {
            target++;
        }else{
            target = target/2;
        }

        opr++;
      }  
      opr += startValue - target;

      return opr;
    }
};