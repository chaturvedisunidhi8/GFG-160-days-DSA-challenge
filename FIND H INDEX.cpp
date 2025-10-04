//Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.
//H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.rbegin(),citations.rend());
        int h=0;
        while(h<citations.size() && citations[h]>h)
        {
            h++;
        }
        
        return h;
    }
};
