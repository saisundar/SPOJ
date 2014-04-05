# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
#include <algorithm>
using namespace std;
# define debug 1
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
#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\t";cout<<"\n";}

int ans[2000001][2];

struct item
{
    int v;
    int w;
};
void wrapper(int k,int n)
{
  item *it=new item[n];
  int i,rem_wt=0,j,max_ind=0,z,wt;
    for(z=0,j=0;z<n;z++,j=1-j)
    {
      scanf("%d %d\n",&it[z].v,&it[z].w);
      wt=it[z].w;
      for(i=it[0].w;i<wt;i++)
      *(*(ans+i)+j)=*(*(ans+i)+(1-j));
      for(i=wt;i<=k;i++)
      *(*(ans+i)+j)=max(ans[i-wt][1-j]+it[z].v,ans[i][1-j]);
    }

  free(it);
  cout<<*(*(ans+k)+(n-1)%2)<<"\n";
}

int main()
{
  int k,n;
  scanf("%d",&k);
  scanf(" %d",&n);
  wrapper(k,n);
	cin.get();
	return 0;
}
