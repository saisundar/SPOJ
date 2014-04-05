public class Solution {
	public int maxmum(int a,int b)
	{

		return (a>b?a:b);
	}

    public int lengthOfLongestSubstring(String s) {
        

       int len=s.length();
       int lenSeq=0,max=0;
       char temp=0;
       //oolean makeNew=true;
       HashSet<char> count=new HashSet<char>;
       for(int i=0;i<len;i++)
        {	
        	temp=s.charAt(i);

        	if(count.contains(temp)
        	{
        		max=mamum(max,lenSeq);
        		lenSeq=0;
				count=new HashSet<char>;
        	}
        	lenSeq++;
        	count.add(temp);

        }
        
        max=mamum(max,lenSeq);

        return max;
        
    }
}