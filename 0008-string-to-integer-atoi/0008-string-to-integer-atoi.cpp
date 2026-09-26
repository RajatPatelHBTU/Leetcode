class Solution {
public:
    const int INT_MIN_VAL = -2147483648;
    const int INT_MAX_VAL = 2147483647;

    int helper(const string & s , int i , long long num , int sign ){
        if(i > s.size() || ! isdigit(s[i]))
        return (int)num * sign;

         num = num * 10 + (s[i] - '0');
        if (sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
        if (sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

        return helper(s, i + 1, num, sign);


    }
    int myAtoi(string s) {
      int n = s.size();
      int sign  = 1;
      int i = 0;

      while( i < n && s[i] == ' ')i++;

      if(i < n && (s[i] == '+' || s[i] == '-')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
      }  
      return helper(s,i,0,sign);
    }
};