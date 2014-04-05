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

#define md(val) ((val<0)?(val*-1):(val*1))
#define mn(m1,m2) (m1=((m1>m2)?m2:m1))
#define mx(m1,m2) (m1=((m1<m2)?m2:m1))
#define min(m1,m2) ((m1>m2)?m2:m1)
#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

void wrapper(int n,int m)
{
  int i,temp,j;
  vector<vector<int> > k(n,vector<int>(m));
	for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    cin>>k[i][j];
  for(i=n-2;i>=0;i--)
  {
    k[i][0]+=min(k[i+1][0],k[i+1][1]);
    k[i][m-1]+=min(k[i+1][m-1],k[i+1][m-2]);
    if(i==0)
    {
      temp=min(k[0][0],k[0][m-1]);
    }
    for(j=1;j<m-1;j++)
    {
      k[i][j]+=min(min(k[i+1][j-1],k[i+1][j]),k[i+1][j+1]);
      if(i==0)
      {
        mn(temp,k[i][j]);
      }
    }
  }
  cout<<temp<<"\n";
}
int main()
{
  int n,m;
  cin>>n>>m;
	wrapper(n,m);
	cin.get();
	return 0;
}
