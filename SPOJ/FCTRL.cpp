# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;

# ifdef debug 
# define dbgn(i,str)  cout<<"the value of"<<str<<" is "<<i<<"\n";
# else
# define dbgn(i,str)  (void)0;
#endif

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

int find_fact_zeros(int n)
{
  int i=1,num_zeros=0,five;
	dbgn(n,"n");
	for(i=1;i<13;i++)
	{
		dbgn(i,"i");
		five=pow(5.0,i);
		if((int(n/five) )>0)
			num_zeros+=(n/five);
		else
			break;
		dbgn(num_zeros," num_zeros");
	}
	return num_zeros;
}

void wrapper(int n)
{
	vector<int> a;
	int i,temp;
	for(i=0;i<n;i++)
	{
	cin>>temp;
	a.push_back(find_fact_zeros(temp));
	}
	dispout(a);
}

int main()
{
	int n,i;
	cin >>n;
	wrapper(n);
	cin.get();
	return 0;
}




