// Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not have duplicate elements and the result should contain items in any order.

// Note: The driver code will sort the resulting array in increasing order before printing.


class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> setA;
        unordered_set<int> result;
        
        for(int i =0; i< a.size(); ++i){
            setA.insert(a[i]);
        }
        for(int i = 0; i<b.size(); ++i){
            if(setA.find(b[i]) != setA.end()){
                result.insert(b[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
