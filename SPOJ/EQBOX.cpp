# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
#include <math.h>

//# define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug 
# define dbgn(i,str)  cout<<"the value of"<<str<<" is "<<i<<"\n";
# else
# define dbgn(i,str)  (void)0;
#endif

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}
#define PI 3.14159265

void wrapper(int n)
{
  int a,b;
  double arg=0.0,cosv,sinv,diff,x1,y1,x,y,mina,maxa,minx,maxx;
  bool ess=false;
  while(n)
  {
   ess=false;
   cin>>a>>b>>x>>y;
    if(a>b){mina=b;maxa=a;}
    else{maxa=b;mina=a;}
    
    if(x>y){minx=y;maxx=x;}
    else{maxx=y;minx=x;}
    
    if(minx<=mina && maxx<=maxa)
    {
        cout<<"Escape is possible.\n"; 
        n--;
        continue;
    }
    y1=minx;      
  for(arg=0.0;arg<=45;arg=arg+0.05)
  {
    cosv=cos(arg*PI/180);
    sinv=sin(arg*PI/180);
    x1=((maxa-(minx*sinv))/cosv);
    
    if(maxx<=x1+0.0001 && ((maxx*sinv)+(minx*cosv)<=mina))
    {
      cout<<"Escape is possible.\n"; 
      ess=true; 
      break;
    }
  }
  if(!ess)cout<<"Box cannot be dropped.\n";
   n--;
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

