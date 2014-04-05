#include <iostream>
#include <cctype>
using namespace std;

# define debug
# ifdef debug
# define dbgn(str1,str2) cout<<(str1)<<": "<<(str2)<<"\n";
# else
# define dbgn(str1,str2) (void)0;
#endif

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	dbgn("================\n"," ");
        dbgn("s",s[0]);
        dbgn("p",p[0]);
        if(s[0]==0 && p[0]==0)return true;
        if(s[0]==0 || p[0]==0)return false;
        int i,j;char alpha='-';bool ismatch=false;
        
        if(p[0]=='.')return isMatch(s+1,p+1);
        

        if(p[0]=='*')
        {
            alpha='-';
            for(i=1;p[i]!=0;i++)
            {
                if(p[i]!='*' && p[i]!='.')
                {
                    alpha=p[i];break;
                }
            }

            dbgn("alpha",alpha);

            if( p[i]!=0 && (alpha!='*' && alpha!='.'))
            {
                ismatch=false;
                for(j=0;s[j]!=0;j++)
                {
                	dbgn("s[j]",s[j]);
                    if(s[j]==alpha)
                    {   ismatch=true;
                    	dbgn("match",s[j]);
                        break;
                    }
                }

            dbgn("j",j);
            if(ismatch)
            {
            	dbgn("maytch","");
            	return isMatch(s+j+1,p+i+1);
            }
            dbgn("no maytch","");
        	return false;                
                
            }
            
            return true;
         
        }
        
        if(p[0]==s[0])return isMatch(s+1,p+1);

        return false;
 }
};

int main()
{
	char *s="ab",*p=".*c";
	Solution summa;

	if(summa.isMatch(s,p))
		cout<<"matchhhhhh";
	else cout<<"not a match";
	return 0;
}