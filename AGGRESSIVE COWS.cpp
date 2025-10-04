//You are given an array with unique elements of stalls[], which denote the position of a stall. 
//You are also given an integer k which denotes the number of aggressive cows. 
//Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.



class Solution {
  public:

   bool canPlaceCows(vector<int> &stalls,int k,int minDist){

    int cowsPlaced=1;
    int lastPos=stalls[0];
    
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-lastPos>=minDist){
            cowsPlaced++;
            lastPos=stalls[i];
            if(cowsPlaced==k) 
            return true;
        }
        
    }

   return false;
    
}

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls.back()-stalls.front();
        int result=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(canPlaceCows(stalls,k,mid)){
                result=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        
        
        return result;
        
        
        
    }
};
