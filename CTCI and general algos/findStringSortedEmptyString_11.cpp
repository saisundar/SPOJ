#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

# define debug 1
# ifdef debug
# define dbgn(str1,str2) cout<<str1<<": "<<str2<<endl;
# else
# define dbgn(str1,str2) (void)0;
#endif

class bitAcc
{
public:
int* array;

bitAcc(int size)
{

	int i=0;
	array=new int[size/32];

	for(i=0;i<size/32;i++)array[i]=0;

}
~bitAcc()
{

	free(array);
}
void set(int pos)
{

	int intNum=pos/32;
	int bitOff=pos%32;
	array[intNum]|=1<<bitOff;

}

bool get(int pos)
{

	int intNum=pos/32;
	int bitOff=pos%32;
	//cout<<(array[intNum]&(1<<bitOff))<<endl;
	return( (array[intNum]&(1<<bitOff)) !=0);
}

};

int main()
{

unsigned i=0;
unsigned int size=1000000000,start,end;

unsigned int blocksize=pow(2,20);
unsigned int  noOfBlocks = pow(2,32)/blocksize;

unsigned int* count=new unsigned int[noOfBlocks];

dbgn("blocksize",blocksize);
dbgn("noOfBlocks",noOfBlocks);
for(i=0;i<size;i++)
{if(i!=2345678)
count[i/blocksize]++;
}

dbgn("int oper is done","");

for(i=0;i<noOfBlocks;i++)
if(count[i]!=blocksize)
	break;

start=blocksize*i;
end=blocksize*(i+1);

dbgn("start",start);
dbgn("end",end);
bitAcc obj(blocksize);

for(i=0;i<size;i++)
	{
		if(i!=2345678 && i>=start && i<end)
			obj.set(i-start);

	}
dbgn("block hashed","on to missing elemnt detection");
for(i=0;i<blocksize;i++)
if(!obj.get(i))
	cout<<"missing number is"<<start+i<<endl;

return 0;
}