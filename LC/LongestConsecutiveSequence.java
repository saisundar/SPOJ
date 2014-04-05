public class Solution {
    public int longestConsecutive(int[] num) {
        
        java.util.Hashtable h= new java.util.Hashtable();
        int i,j,g,l,length=0,longest=0;
        for(i=0;i<num.length;i++)
        {
            h.put(new java.lang.Integer(num[i]),'f');
        }
        
        for(i=0;i<num.length;i++)
        {
            if((h.get(num[i])).toString().charAt(0)=='f')
            {
            length=0;
            for(g=0,j=num[i]+1;h.containsKey(j);j++,g++){h.put(new java.lang.Integer(j),'t');}
            for(l=0,j=num[i]-1;h.containsKey(j);j--,l++){h.put(new java.lang.Integer(j),'t');};
            length=g+l+1;
            if(length>longest)longest=length;
            }
            
        }
        return longest;
    }
}