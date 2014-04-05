# include <iostream>
using namespace std;

int findMissingNum(int seq[],int length)
{

int l=0,r=length-1,mid=(l+r)/2,init=seq[0];

while(l<r)
{

if(seq[l]!=init+l)
	break;
if(seq[mid]>init+mid)
	{
		r=mid;
		mid=(l+r)/2;continue;
	}
l=mid+1;
mid=(l+r)/2;

}

return seq[l]-1;

}

int main()
{

int seq[]={43,44,45,46,47,48,49,51};

if(!seq)
	cout<<"empty array";

int init=seq[0],length=(sizeof(seq)/sizeof(*seq));

	if(seq[length-1]==init+length-1)
	{
		cout<<"no missing element";
		return 0;
	}


	cout<<"missing number is "<<findMissingNum(seq,length)<<"\n";

}