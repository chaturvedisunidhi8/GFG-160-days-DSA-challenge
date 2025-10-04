//You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. 
//You also have an integer k representing the number of students. The task is to allocate books to each student such that:
//Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student


class Solution {
  public:
  
  bool isPossible(vector<int> &arr,int k,int maxPages){
      
      int studentsRequired=1;
      int currentPages=0;
      
      for(int pages: arr){
          if(pages> maxPages){
              return false;
          }
          
          if(currentPages + pages > maxPages){
              
              studentsRequired++;
              currentPages=pages;
              if(studentsRequired >k){
                  return false;
              }
              
              }
              else{
                  currentPages+=pages;
              }
          
      }
      
      return true;
      
      
  }
  
    int findPages(vector<int> &arr, int k) {
        // code here
       int n=arr.size();
       if(k>n) return -1;
       
       
       int low=*max_element(arr.begin(),arr.end());
       int high=accumulate(arr.begin(),arr.end(),0);
       
       int result=high;
       while(low<=high){
       int mid=low+(high-low)/2;
       
       if(isPossible(arr,k,mid)){
           result=mid;
           high=mid-1;
           
       }
       else{
           low=mid+1;
       }
    }
    return result;
    }
};
