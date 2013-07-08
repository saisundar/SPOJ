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

#define md(val) ((val<0)?((val)*-1):((val)*1))
#define mn(m1,m2) (m1=((m1>m2)?m2:m1))
#define mx(m1,m2) (m1=((m1<m2)?m2:m1))
#define max(m1,m2) ((m1>m2)?m1:m2)
#define min(m1,m2) ((m1<m2)?m1:m2)

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

int tru[1000];
int fals[1000];
int maxper(vector<int> ln,vector<int> wd,int level,bool useln)
{

  int l=level;
  if(l==ln.size()-1)
  {
  if(useln)return ln[level];
    return wd[level];
  }
  if(useln)
  {
    if(tru[level]==0)
    return (tru[level]=(max(ln[l]+md(wd[l]-wd[l+1])+maxper(ln,wd,l+1,true),ln[l]+md(wd[l]-ln[l+1])+maxper(ln,wd,l+1,false))));
    return tru[level];
  }

  if(fals[level]==0)
  fals[level]=(max(wd[l]+md(ln[l]-wd[l+1])+maxper(ln,wd,l+1,true),wd[l]+md(ln[l]-ln[l+1])+maxper(ln,wd,l+1,false)));
  return fals[level];

}
void wrapper(int n)
{
  int i,a,b;
  vector<int> ln(n);
  vector<int> wd(n);
	for(i=0;i<n;i++)
  {
    cin>>a>>b;
    if(a>b){ln[i]=a;wd[i]=b;}
    else{ln[i]=b;wd[i]=a;}
  }
  cout<<max( maxper(ln,wd,0,true),maxper(ln,wd,0,false))<<"\n";

}

int main()
{
  int n;
  cin>>n;
	wrapper(n);
	cin.get();
	return 0;
}
