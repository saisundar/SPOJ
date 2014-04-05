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
}