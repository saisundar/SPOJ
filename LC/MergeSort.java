public class Solution {
    public void merge(int A[], int m, int B[], int n) {
        int a=0,b=0,i;
        int C[]=new int[m+n];
        for(a=0,b=0,i=0;a<m && b<n;i++)
        {
            if(A[a]>B[b])
            {
                C[i]=B[b++];
            }
            else
                C[i]=A[a++];
        }
        
        for(;a<m;a++)C[i++]=A[a];
        for(;b<n;b++)C[i++]=B[b];
        
        for(i=0;i<m+n;i++)A[i]=C[i];
        
    }
}