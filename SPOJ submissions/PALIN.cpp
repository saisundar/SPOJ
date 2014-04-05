# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
#include<cstdlib>
using namespace std;

//#define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug
# define dbgn(i,str)  cout<<str<<" = "<<i<<"\n";
# define dbgp(str)    cout<<str<<"\n";
# else
# define dbgn(i,str)  (void)0;
# define dbgp(str)    (void)0;
#endif

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\t";}

void inc_carry(string &str,int loc)
{
  if(loc<0)return;
  int carry=1,i;
  for(i=loc;i>=0 && carry==1;i--)
  {
    if(str[i]=='9')
    {carry=1;
      str[i]='0';
    }
    else
    {str[i]++;
      carry=0;
    }
  }
}

void palindromize(string &str)
{
int i,ss=0,se=str.size()-1,max=(ss+se)/2;

for(i=0;i<=max;i++)
{
 if(str[ss+i]==str[se-i])
   continue;
 else if(str[ss+i]>str[se-i])
 {
   str[se-i]=str[ss+i];
   continue;
 }
 else
 {
   inc_carry(str,se-i-1);
   str[se-i]=str[ss+i];
 }
}

cout<<str<<"\n";

}


void wrapper(int n)
{
  int j=0,i=0;
  for(j=0;j<n;j++)
  {
  string str;
  int num_nine=0;
  cin>>str;
  
  for(i=0;i<str.size() && i<1000000;i++)
  {
    if(str[i]=='9')num_nine++;
  }
  if(num_nine==str.size())
  {  cout<<"1";
    for(i=0;i<str.size()-1;i++)
    cout<<"0";
    cout<<"1\n";
    continue;
  }

  inc_carry(str,str.size()-1);
  
  palindromize(str);
  cin.clear();
  cin.ignore(1000000,'\n');
  }
}


int main()
{
  int n;
  cin >>n;
  cin.ignore();
  wrapper(n);
  getchar();
  return 0;
}

