//You are given a 2D matrix mat[][] of size n×m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0 
//and do it in constant space complexity.
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
int rows=mat.size();
int cols=mat[0].size();

bool firstRowZero=false, firstColZero=false;

for(int j=0; j<cols;j++){
    if(mat[0][j]==0){
        firstRowZero=true;
        break;
        
    }
}

for(int i=0;i<rows;i++){
    if(mat[i][0]==0){
        firstColZero=true;
        break;
    }
}

for(int i=1;i<rows;i++){
    for(int j=1;j<cols;j++){
        if(mat[i][j]==0){
            mat[i][0]=0;
            mat[0][j]=0;
        }
    }
} 

for(int i=1;i<rows;i++){
    for(int j=1;j<cols;j++){
        if(mat[i][0]==0 || mat[0][j]==0){
            mat[i][j]=0;
        }
    }
}


if(firstRowZero){
    for(int j=0;j<cols;j++){
        mat[0][j]=0;
    }
}

if(firstColZero){
    for(int i=0;i<rows;i++){
        mat[i][0]=0;
    }
}

    }
};
