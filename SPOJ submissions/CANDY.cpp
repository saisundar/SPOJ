# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
# define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug 
# define dbgn(i,str)  cout<<"the value of"<<str<<" is "<<i<<"\n";
# else
# define dbgn(i,str)  (void)0;
#endif

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

void wrapper(int n)
{
  vector<int> a(n);
	int i=0,avg=0,pos=0,neg=0;
    for(i=0;i<n;i++)		
	{cin>>a[i];
	 avg=avg+a[i];
	}
	if(avg%n!=0)
	{
		cout<<"-1\n";
		return;
	}

	avg=avg/n;

	for(i=0;i<n;i++)
	{	a[i]=a[i]-avg;
	    if(a[i]>0)pos=pos+a[i];
		else if(a[i]<0)neg=neg+a[i];
	}

	if(neg==0)
		cout<<"0\n";
	else if(pos>=neg)
		cout<<(neg*-1)<<"\n";
	else
		cout<<pos<<"\n";
	return;
	
}

int main()
{int n;
	while(1)
	{
    cin>>n;
	if(n==-1)
		break;
	wrapper(n);
	}
	cin.get();
	return 0;
}
