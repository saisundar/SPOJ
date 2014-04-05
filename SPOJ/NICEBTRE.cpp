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
#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}
#define disparr(a,n) {int z;for(z=0;z<n;z++)cout<<a[z];cout<<"\n";}

int a[10000];
void wrapper(int n)
{
  int i,temp;
	for(i=0;i<n;i++)
  {
    int j=-1,k;
    char c;
    int max=-1;
    for(k=0;k<10000;k++)a[k]=0;
    scanf("%c",&c);
    while(c!='\n')
    {
      j++;
      mx(max,j);
      if(c=='n')a[j]+=2;
      else if(c=='l')
      {
       j--;
       a[j]--;
       while(j>=0 && a[j]==0)
         { j--;a[j]--;
         }
      }
     scanf("%c",&c);
	  }
    printf("%d\n",max);
  }
}

int main()
{
  int n;
  scanf("%d\n",&n);
	wrapper(n);
	cin.get();
	return 0;
}
