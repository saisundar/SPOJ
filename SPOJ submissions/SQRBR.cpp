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

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i];cout<<"\n";}
int brut_ans(vector<vector<long int> > &mem,int size,vector<int> ka,int pos,int nextk,int diff)
{
  int tans;
  if(pos>=size||diff<0)
  {
    return 0;
  }
  if(pos==size-1)
  {
    diff--;
    if(diff==0)
    {
      return 1;
    }
    return 0;
  }
  if(mem[diff][pos]==-1)
  {
  if(((nextk<ka.size()) && (pos==ka[nextk]-1))||pos==0)
  {
    tans=brut_ans(mem,size,ka,pos+1,nextk+1,diff+1);
  }
  else
  {
    tans=brut_ans(mem,size,ka,pos+1,nextk,diff-1)+brut_ans(mem,size,ka,pos+1,nextk,diff+1);
  }
  mem[diff][pos]=tans;
  }
  else
    return mem[diff][pos];
  return tans;
}

void comp_ans(int n,int k,vector<int> ka)
{
  vector<vector<long int> > mem(n*2,vector<long int>(n*2));
  for(int i=0;i<n*2;i++)
    for(int j=0;j<n*2;j++)
      mem[i][j]=-1;
  cout<<brut_ans(mem,n*2,ka,0,-1,0)<<"\n";
}

void wrapper(int m)
{
  int i,temp,j,k,n;
  for(i=0;i<m;i++)
  {
    cin>>n>>k;
    vector<int> ka(k);
    for(j=0;j<k;j++)cin>>ka[j];
    if(ka[k-1]==2*n||k>n)
    {
      cout<<"0"<<"\n";
      continue;
    }
    comp_ans(n,k,ka); 
  }
}

int main()
{
  int n;
  cin >>n;
  wrapper(n);
  cin.get();
  return 0;
}
