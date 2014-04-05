public class Solution {
    public int numDecodings(String s) {
        
        int len=s.length();
        if (len==0)return 0;
        
        int len1=len+1,i=0,j=0;
        int[] ans=new int[len1];
        char[] s1=s.toCharArray();
        ans[0]=1;
        if(s1[0]!='0')ans[1]=1;
        
        for(i=2;i<=s.length();i++)
        {
            j=i-1;
            ans[i]=0;
            
            if(s1[j]!='0')
            ans[i]+=ans[i-1];
            
            if(s1[j-1]=='1' ||(s1[j-1]=='2' && (s1[j]>='0' && s1[j]<='6')))
            ans[i]+=ans[i-2];
            
            
        }
        
        return ans[s.length()];
        
    }
}