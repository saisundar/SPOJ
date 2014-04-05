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

int fib[1600000];
void wrapper(short u)
{
  int n,i,j;
  short m;
  int rem,per;
  for(i=0;i<u;i++)
  {
 	cin>>n>>m;
  per=int(3*pow(2.0,m-1));
  n=(n-1)%per;
  rem=int(pow(2.0,m));
  cout<<fib[n]%rem<<"\n";
 
  }
}

int main()
{
  short n;
  int j;
  cin>>n;
  fib[0]=1;  fib[1]=2;fib[2]=3;
  for(j=3;j<=1572890;j++)
    fib[j]=(fib[j-1]+fib[j-2])%1048576;
	wrapper(n);
	cin.get();
	return 0;
}
