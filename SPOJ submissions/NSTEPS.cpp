# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
//# define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug 
# define dbgn(i,str)  cout<<"the value of"<<str<<" is "<<i<<"\n";
# else
# define dbgn(i,str)  (void)0;
#endif

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

void wrapper(int n)
{
  int i,x,y;
  cin>>i;

	while(i)
	{
	cin>>x>>y;
	if ((x!=y)&&(x!=y+2))
  {cout<<"No Number\n";
    i--;
    continue;
  }

  if(x%2==0)
  {
    cout<<x+y<<"\n";
  }
  else
    cout<<x+y-1;

  i--;
	}
}

int main()
{
	wrapper(0);
	cin.get();
	return 0;
}
