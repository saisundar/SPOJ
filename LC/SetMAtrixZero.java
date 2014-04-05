public class Solution {
    public void setZeroes(int[][] matrix) {
        int m=matrix.length,n=matrix[0].length,i,j;
        boolean row[]=new boolean[m];
        boolean col[]=new boolean[n];
        
        for(i=0;i<row.length;i++)row[i]=false;
        for(i=0;i<col.length;i++)col[i]=false;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            if(matrix[i][j]==0)
            {
                row[i]=true;
                col[j]=true;
            }
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            if(row[i] || col[j])
            {
                matrix[i][j]=0;
            }
        }
        
    }
}