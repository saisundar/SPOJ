#include <iostream>
using namespace std;
# define max(a,b) ((a>b)?a:b)
int main() {
int a[]={10,9,8,7,6,5},max=-1;
int lis[]={-1,-1,-1,-1,-1,-1},i,j;
lis[0]=1;
for(i=1;i<6;i++)
{		
  for(j=0;j<i;j++)
{ if((a[j]<a[i]) && lis[j]>=lis[i])lis[i]=lis[j]+1;  
}
}
for(i=0;i<6;i++)
  max=max(max,lis[i]);
cout<<"the longest incresing subsequece is of length \t"<<max<<"\n";
}