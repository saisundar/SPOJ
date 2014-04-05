class Solution {
public:


    int maxmum(int a,int b)
    {
        
        return (a>b?a:b);
    }

    int maxSubArray(int A[], int n) {
     
     int i,sum,maxSum;
     
     if(n==0)return 0;
     
     sum=maxSum=A[0];
     
     for(i=1;i<n;i++)
     {
        if(A[i]<0) 
        {
           if(sum<A[i])
           {
               sum=A[i];
               maxSum=maxmum(maxSum,sum);
           }
           else if(sum>A[i])
           {
               sum+=A[i];
           }
        }
        else
        {
         if(sum<0)
         {
             
             sum=A[i];
             maxSum=maxmum(sum,maxSum);
         }
         else
         {
             sum=sum+A[i];
             maxSum=maxmum(maxSum,sum);
             
         }
        }
     }
     return maxSum;
    }
};