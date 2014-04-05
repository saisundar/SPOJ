public class Solution {
    public int minPathSum(int[][] grid) {
        
        if (grid==null)return 0;
        int i=0,j=0,m=0,n=0;
        
        m=grid.length;n=grid[0].length;
        
        for(i=1;i<n;i++)grid[0][i]+=grid[0][i-1];
        for(i=1;i<m;i++)grid[i][0]+=grid[i-1][0];
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                grid[i][j]+=(grid[i-1][j]<grid[i][j-1])?grid[i-1][j]:grid[i][j-1];
            }
        }
        
        return grid[m-1][n-1];
    }
}