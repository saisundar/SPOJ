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
#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i];cout<<"\n";}
#define iseq(a,b) ((a==b)?(true):(false))

void comp_lp(string pat)
{
  vector<int> lp(pat.size());
  lp[0]=0;

  int i,prev_len=0;
  i=1;
  while(i<lp.size())
  {
    if(iseq(pat[i],pat[prev_len]))
    {
      prev_len++;  lp[i]=prev_len;i++;
    }
    else
    {
      if(prev_len)prev_len=lp[prev_len-1];
      else
        lp[i++]=0;
    }
  }
  dispout(lp);
  int rem=lp.size()%(lp.size()-lp[lp.size()-1]);
  if(!rem)cout<<lp.size()/(lp.size()-lp[lp.size()-1])<<"\n";
  else cout<<"1\n";
}

void wrapper(int n)
{
  while(1)
  {
  string pat;
  cin.clear();
  getline(cin,pat);
  if(pat[0]=='*')
    break;
  comp_lp(pat);
  }
}

int main()
{
  int n;
  cin>>n;
  wrapper(n);
	cin.get();
	return 0;
}
