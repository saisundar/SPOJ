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

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

void wrapper(int n)
{
  int i,j,temp,ev=0,od=0;
  bool flag=false;
	while(1)
	{
	cin>>temp;
	if (temp==0)
		break;
  string str;
  
  cin>>str;

  for(i=0;i<temp;i++)
  {
    ev=2*i+1;
    od=2*temp-ev;
    flag=false;
    for(j=i;j<str.size();j+=(flag?od:ev))
        {
        cout<<str[j];
        flag=!flag;
        }

	} 
  cout<<"\n";
  cin.clear();
  cin.ignore(200,'\n');
      
  }

}

int main()
{
	wrapper(0);
	cin.get();
	return 0;
}
