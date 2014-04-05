# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
# define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug 
# define dbgn(i,str)  cout<<str<<" = "<<i<<"\n";
# else
# define dbgn(i,str)  (void)0;
#endif

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

void wrapper(int n)
{
  int i,nop;
	for(i=0;i<n;i++)
  {
  string str;  
	cin>>nop>>str;
  cout<<str[str.size()-1]<<"\n";
  }
}

int main()
{
  int n;
  cin >>n;
  wrapper(n);
	cin.get();
	return 0;
}
