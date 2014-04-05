# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
#include <stack>
using namespace std;
//# define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug 
# define dbgn(i,str)  cout<<"the value of"<<str<<" is "<<i<<"\n";
# else
# define dbgn(i,str)  (void)0;
#endif


void wrapper(int n)
{
  vector<long long int> a(n);
  stack<int> st;
  int i=0,temp;
  long long int area=0,max=0;
	while(i<n)
	{
	cin>>a[i];

  if(st.empty()||a[i]>=a[st.top()])
    st.push(i);
  else
  {
    while(!st.empty() && a[st.top()]>a[i])
    {
      temp=st.top();
      st.pop();
      area=a[temp]*(st.empty()?i:i-st.top()-1);

      if(area>max)max=area;
    }

    st.push(i);
  }
  i++;
  }

  while(!st.empty())
  {
    temp=st.top();
    st.pop();
    area=a[temp]*(st.empty()?n:n-st.top()-1);
    if(area>max)max=area;
  }

  cout<<max<<"\n";

}

int main()
{
  int n;
  cin>>n;
  while(n!=0)
  {
    wrapper(n);
    cin>>n;
  }

	cin.get();
	return 0;
}
