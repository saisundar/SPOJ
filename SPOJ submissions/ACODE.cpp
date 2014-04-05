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

vector<int> ones(5000);

void wrapper(int n)
{
  int i;
  string str;
  long long int prev;
  int length=0;
  while(1)
  {
    prev=1; 
    length=0;
    cin>>str;
    vector<bool> arr(str.size()-1);
    if (str[0]=='0')
      break;
    for(i=0;i<str.size()-1;i++)
    {
      if((str[i]>='1' && str[i]<='2')&& str[i+1]!='0')
      {
        arr[i]=true;
      }
      else
      {
        arr[i]=false;
        if(str[i+1]=='0' && i>=1)arr[i-1]=false;
      }
    }
    for(i=0;i<arr.size();i++)
    {
      if(arr[i])length++;
      else
      {
        prev=prev*ones[length];
        length=0;
      }
    }
    
    if(length)prev=prev*ones[length];
    cout<<prev<<"\n";
  }

}

int main()
{
  int i;

  ones[0]=1;
  ones[1]=2;
  ones[2]=3;
  for(i=3;i<5000;i++)
     ones[i]=ones[i-1]+ones[i-2];
	wrapper(0);
	cin.get();
	return 0;
}
