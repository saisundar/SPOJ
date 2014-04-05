public class Solution {
    public int largestRectangleArea(int[] height) {
     
     int[] stack= new int[height.length];
     int top=-1,area,maxArea=0,histBase,prevSmall,i=0;
     for(i=0;i<height.length;i++)
     {
         
         if(top==-1||height[stack[top]]<=height[i])
         {
             stack[top+1]=i;
             top++;
         }
         else
         {
             histBase=stack[top--];
             if(top>=0)
             prevSmall=stack[top];
             else prevSmall=-1;
             
             area= height[histBase]*(i-1-prevSmall);
             maxArea=(area>maxArea)?area:maxArea;
             i--;
         }
     }
     
     while(top!=-1)
     {
         
             histBase=stack[top--];
             if(top>=0)
             prevSmall=stack[top];
             else prevSmall=-1;
             
             area= height[histBase]*(i-1-prevSmall);
             maxArea=(area>maxArea)?area:maxArea; 
     }
       return maxArea; 
    }
    
    
    public int maximalRectangle(char[][] matrix) {
        int n=matrix.length,maxArea=0,area;
        
        if(n==0)return 0;
        
        int m=matrix[0].length,i,j;
        
        int[][] hist=new int[n][m];
        
        for(i=0;i<m;i++)
        if(matrix[0][i]=='1')hist[0][i]=1;
        
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                hist[i][j]=hist[i-1][j]+1;
                else
                hist[i][j]=0;
                
            }
        }
        
        for(i=0;i<n;i++)
        {
            area=largestRectangleArea(hist[i]);
            maxArea=(area>maxArea)?area:maxArea;
            
        }
        
        return maxArea;
        
        
    }
}