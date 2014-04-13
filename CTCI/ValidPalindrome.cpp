#include <iostream>
#include <cctype>
#include <string>
using namespace std;

# define debug 1
# ifdef debug
# define dbgn(str1,str2) cout<<str1<<": "<<str2<<endl;
# else
# define dbgn(str1,str2) (void)0;
#endif

class Solution {
public:
	bool isPalindrome(string s) {
	int len=s.size();
      	if(len==0||len==1)
      	return true;
		int left,right;
		dbgn("len",len);
		bool isPalin=true;
		for(left=0,right=len-1;left<=right;)
		{
			if(!isalnum(s[left]) || !isalnum(s[right]))
			{
			if(!isalnum(s[left]))
					left++;
			if(!isalnum(s[right]))
					right--;
				continue;
			}
			s[right]=tolower(s[right]);
			s[left]=tolower(s[left]);
			if(s[right]!=s[left])
			{
				isPalin=false;
				dbgn("right",right);
				dbgn("left",left);
				break;
			}
			right--;
			left++;
		}
		return isPalin;
	}
};

int main()
{
	Solution summa;
	string s="A man, a plan, a canal: Panama";
	string s1="a121a";
	if(summa.isPalindrome(s1))
		cout<<"its a palindorme"<<endl;
	else cout<<"its not a palindorme"<<endl;
}