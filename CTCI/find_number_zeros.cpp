# include <iostream>
using namespace std;

int findZeros(int seq[],int length)
{

int l=0,r=length-1,mid=(l+r)/2;

while(l<r)
{

if(mid==l)
	break;
if(seq[mid]==0)
{
	r=mid;
}
else
l=mid;

mid=(l+r)/2;

}

return (length-mid-1);

}
int main()
{

int seq[]={1,1,1,1,1,1,0};

int length=length=(sizeof(seq)/sizeof(*seq));

cout<<"the number of zeroes is "<<findZeros(seq,length)<<"\n";
}