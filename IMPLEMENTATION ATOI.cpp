//Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int i =0 , n = strlen(s);
        while (i<n&&s[i]==' '){
            i++;
        }
        int sign =1;
        if(i<n&& (s[i]=='-'|| s[i] =='+')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        int result =0;
        while(i<n&& isdigit(s[i])){
            int digit = s[i]-'0';
            if(result > (INT_MAX - digit )/100){
                return(sign==1)? INT_MAX:INT_MIN;
            }
            result= result *10+digit;
            i++;
        }
        return sign *result;
    }
};
