//Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
//Note: The input strings may contain leading zeros but the output string should not have any leading zeros.
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int i=s1.size()-1,j=s2.size()-1,carry=0;
        
        string result="";
        
        while(i>=0 || j>=0 || carry){
            int sum=carry;
            
            if(i>=0) sum+=s1[i--]-'0';
            if(j>=0) sum+=s2[j--]-'0';
            
            result=char((sum%2)+'0')+result;
            
            carry=sum/2;
            
        }
        
        
        int pos=0;
        while(pos<=result.size()-1 && result[pos]=='0'){
        pos++;
        
        }
        return result.substr(pos);
    }
};
