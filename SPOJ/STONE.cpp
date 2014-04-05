# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
#include<iomanip>
using namespace std;
//# define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug 
# define dbgn(i,str)  cout<<"the value of"<<str<<" is "<<i<<"\n";
# else
# define dbgn(i,str)  (void)0;
#endif

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

void wrapper(int n)
{
  vector<int> a;
	int i,j,temp;
	for(i=0;i<n;i++)
  {
	cin>>temp;
  vector<int> x(temp+1);
  vector<int> y(temp+1);
  float cx=0,cy=0,area=0,t;
	for(j=0;j<temp;j++)
    cin>>x[j]>>y[j];
  x[temp]=x[0];y[temp]=y[0];

   for(j=0;j<temp;j++)
   {
   t=(x[j]*y[j+1]-x[j+1]*y[j]);
   cx=cx+((x[j]+x[j+1])*t);
   cy=cy+((y[j]+y[j+1])*t);
   area=area+t;
   }
   cx=cx/(3*area);
   cy=cy/(3*area);
   
   cout<<setprecision(2)<<fixed<<cx <<" "<<cy<<"\n";
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
