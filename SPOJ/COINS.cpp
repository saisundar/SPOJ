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
#define SIZE 1000000
int g[SIZE];
unsigned int dollarify(int val)
{
if(val<12)return val;

int val1,val2,val3;

val1=val/2;
if(val1>SIZE)
  val1=dollarify(val1);
else
 {
   if(g[val/2])val1=g[val/2];
   else g[val/2]=val1=dollarify(val1);
 }

val2=val/3;
if(val2>SIZE)
  val2=dollarify(val2);
else
 {
   if(g[val/3])val2=g[val/3];
   else g[val/3]=val2=dollarify(val2);
 }

val3=val/4;
if(val3>SIZE)
  val3=dollarify(val3);
else
 {
   if(g[val/4])val3=g[val/4];
   else g[val/4]=val3=dollarify(val3);
 }

return(val1+val2+val3);
}

void wrapper(int n)
{
  vector<int> a;
	int i,temp;
	for(i=0;i<10;i++)
  {
  string str;
  unsigned int val;
  getline(cin,str);
  if (!isdigit(str[0]))
		break;
  val=atoi(str.c_str());
  cout<<dollarify(val)<<"\n";
  }
}

int main()
{
	wrapper(10);;
	cin.get();
	return 0;
}
