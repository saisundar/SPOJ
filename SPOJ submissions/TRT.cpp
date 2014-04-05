# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
#include <ctype.h>
#include <stdlib.h>
//# define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug 
# define dbgn(i,str)  cout<<"the value of"<<str<<" is "<<i<<"\n";
# else
# define dbgn(i,str)  (void)0;
#endif

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}
int mx[2000][2000];
int brut_ans(vector<int> &a,int low,int up)
{
int l,r;
short day=a.size()-up+low;
if(day==a.size())
{
mx[low][up]=a[up]*day;
return mx[low][up];
}
if(mx[low][up]==0)
{
l=a[low]*day+brut_ans(a,low+1,up);
r=a[up]*day+brut_ans(a,low,up-1);
if(r>l)
mx[low][up]=r;
else mx[low][up]=l;
}
return mx[low][up];
}

unsigned int compute_max(vector<int> &a)
{
int max=0;
short fl=0;
unsigned short days=1;
short l=0,r=a.size()-1;
return brut_ans(a,0,a.size()-1);
}

void wrapper(int n)
{
  vector<int> a(n);
	int i,temp;
	for(i=0;i<n;i++)
  cin>>a[i];
  cout<<compute_max(a)<<"\n";
}

int main()
{
int n;
  cin>>n;
	wrapper(n);;
	cin.get();
	return 0;
}
