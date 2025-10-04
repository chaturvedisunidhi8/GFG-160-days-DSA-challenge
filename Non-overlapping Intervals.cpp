// Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping



class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end(),[](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int count =0;
        int end = INT_MIN;
        for (auto& interval:intervals){
            if(interval[0] >= end){
                end= interval[1];
            } else {
                count++;
            }
        }
        return count;
    }
};
