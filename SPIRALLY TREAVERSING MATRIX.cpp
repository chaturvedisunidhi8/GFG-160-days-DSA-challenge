//You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.



class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int> result;
        
        int r=mat.size();
        int c=mat[0].size();
        
        
        int top=0,bottom=r-1;
        int left=0,right=c-1;
        
        
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                result.push_back(mat[top][i]);
            }
            top++;
            
            for(int i=top;i<=bottom;i++){
                result.push_back(mat[i][right]);
                
            }
            right--;
            
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    result.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    result.push_back(mat[i][left]);
                }
                left++;
            }
            
        }
        return result;
        
    }
};
