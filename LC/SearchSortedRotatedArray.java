public class Solution {
    public int search(int[] A, int target) {
     
     int left=0,right=A.length-1,mid=0;
     
     while(right>=left)
     {
         mid=(right+left)/2;
        if(A[mid]==target)return mid;
        if(A[mid]>A[right])
        {
            
            if(target>A[mid])left=mid+1;
            else 
            {
                if(target>=A[left])right=mid-1;
                else left=mid+1;
            }
        }
        else
        {
            if(target>A[mid])
            {
                if(target>A[right])right=mid-1;
                else left=mid+1;
            }
            else
            right=mid-1;
            
        }
         
     }
     return -1;
     
        
    }
}