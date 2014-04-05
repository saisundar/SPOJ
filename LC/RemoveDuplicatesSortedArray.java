public class Solution {
    public int removeDuplicates(int[] A) {
        
        int next_loc,i,prev;
        if (A.length==0)return 0;
        prev=A[0];
        for(i=1,next_loc=1;i<A.length;i++)
        {
            if(prev==A[i])continue;
            
            A[next_loc++]=A[i];
            prev=A[i];
            
        }
        
        return next_loc;
    }
}