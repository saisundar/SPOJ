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

unsigned int dp(unsigned int diff,vector<unsigned int> p,vector<unsigned int> w)
{
vector<unsigned int> ans(diff+1);
int i,j,tempwt;

 for(i=0;i<=diff;i++)
 ans[i]=0-1;
 ans[0]=0;
 for(i=1;i<=diff;i++)
 {
   for(j=0;j<p.size();j++)
   {
     if(w[j]>i)continue;
     tempwt=i-w[j];
     if((ans[tempwt]!=-1) && ans[tempwt]+p[j]<ans[i])
       ans[i]=ans[tempwt]+p[j];
   }

 }
 return ans[diff];

}
void wrapper(int t)
{
  vector<int> a;
	unsigned int i,temp,e,f,n,j,ans;
	for(i=0;i<t;i++)
  {
	cin>>e>>f;
	cin>>n;
  vector<unsigned int> p(n),w(n);

  for(j=0;j<n;j++)
    cin>>p[j]>>w[j];
  ans=dp(f-e,p,w);
  if(ans==-1)
    cout<<"This is impossible.\n";
  else
    cout<<"The minimum amount of money in the piggy-bank is "<<ans<<".\n";
  }
}

int main()
{
  int t;
  cin>>t;
  wrapper(t);
	cin.get();
	return 0;
}
