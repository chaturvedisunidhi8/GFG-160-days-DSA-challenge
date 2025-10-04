// You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 
//   Note: The answer should be returned in an increasing format.

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n = arr.size();
        if(n==0) return{};
        if(n==1) return {arr[0]};
        
        int first = INT_MIN , second = INT_MIN;
        int fc =0,sc=0;
        for (int num:arr){
            if(num == first){
                fc++;
            } else if (num == second){
                sc++;
            } else if (fc == 0){
                first = num;
                fc = 1;
            } else if (sc == 0){
                second = num;
                sc = 1;
            } else {
                fc--;
                sc--;
            }
        }
        fc = 0; sc = 0;
        for(int num:arr){
            if(num == first) fc++;
            else if(num== second) sc++;
        }
        vector<int> res;
        if(fc>n/3) res.push_back(first);
        if(sc>n/3 && first != second) res.push_back(second);
        sort(res.begin(), res.end());
        return res;
    }
};
