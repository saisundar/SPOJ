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
#define max(m1,m2) ((m1>m2)?m1:m2)
#define min(m1,m2) ((m1<m2)?m1:m2)
#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}
#define INF 3000000000
int *c=NULL;
int *a=NULL;
unsigned int *mem[2];
void wrapper(int n)
{
  int i,temp,j,z;
  c=new int[n];
  a=new int[n];
  mem[0]=int[n/2];
  mem[1]=int[n/2];
  for(i=0;i<n;i++)
  {
    scanf("%d %d\n",c+i,a+i);
  }

  for(i=0,z=0;i<=n/2;i++)
    mem[0][i]=a[0];

  for(i=1,z=!z;i<n;i++,z=!z)
  {
    mem[z][0]=a[i]+mem[!z][0];
    for(j=1;(2*j)<(i+1);j++)
      mem[z][j]=min(a[i]+mem[!z][j],c[i]+mem[!z][j-1]);
    for(;j<=n/2;j++)
      mem[z][j]=c[i]+mem[!z][j-1];
  }

  printf("%u\n",mem[!z][n/2]);
}

int main()
{
  int n,i,j;
  cin>>n;
  wrapper(n);
  cin.get();
	return 0;
}
