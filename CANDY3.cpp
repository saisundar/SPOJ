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
  int i=0;
	long long int inp,avg=0;
    for(i=0;i<n;i++)		
	{cin>>inp;
	 avg=(avg+inp)%n;
	}
	if(avg%n!=0)
		cout<<"NO\n";
	else
	    cout<<"YES\n";
	return;
}

int main()
{int t,n;
    cin>>t;
	cout<<"\n";
	while(t--)
	{
    cin>>n;
	wrapper(n);
	cout<<"\n";
	}
	
	return 0;
}
