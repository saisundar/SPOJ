#include <iostream>
using namespace std;

# define max(a,b) ((a>b)?a:b)

int main() {
	
int a[]={1,2,3,-6,4,2};

int sum=a[0],sti=0,endi=0,i,sumtill=a[0];

for(i=1;i<6;i++)
{
 sumtill=max(a[i],sumtill+a[i]);

if(sumtill>sum)
{
sum=sumtill;
if(sumtill==a[i])sti=i;
endi=i;
}

}
                          
cout<<"max sum"<<sum;
cout<<"\n from index\t"<<sti<<"to index\t"<<endi<<"\n";					  


}