public class Solution {
    public boolean isValid(String s) {
        
        int curv=0, curl=0,square=0,len=s.length();
        
        int stack[]=new int[len];int i=0,top=0;for(i=0;i<stack.length;i++)stack[i]=-1;
        
        for(i=0;i<len;i++)
        {
                if(s.charAt(i)=='(')
                {
                curv++;stack[top++]=0;
                }
                else if(s.charAt(i)=='{')
                {curl++;stack[top++]=1;
                
                }
                else if(s.charAt(i)=='[')
                {
                    square++;stack[top++]=2;
                }
                else if(s.charAt(i)==')')
                {   
                    curv--;
                    if(top<=0||stack[top-1]!=0||curv<0)return false;
                    top--;
                }
                else if(s.charAt(i)=='}')
                {   curl--;
                    if(top<=0||stack[top-1]!=1||curl<0)return false;top--;
                }
                else if(s.charAt(i)==']')
                {square--;
                    if(top<=0||stack[top-1]!=2||square<0)return false;top--;
                }
                    
        }
        
        if(curv!=0||curl!=0||square!=0)return false;
        return true;
        
        
        
    }
}