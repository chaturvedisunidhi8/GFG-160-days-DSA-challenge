//Given an array arr[] of positive integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target.

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_set<int>s;
        
        for(int num : arr){
            int complement=target-num;
            
            
            if(s.find(complement)!=s.end()){
                return true;
            }
            
            s.insert (num);
        }
        
        
        
        return false;
        
        
        
        
        
    }
};
