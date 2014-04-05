#include <iostream>
#include <cstdlib>
using namespace std;

class bitAcc
{
private:
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

int i=0,size=1000000;

bitAcc obj(size);

for(i=0;i<size;i++)
	if(i!=23456)
obj.set(i);

for(i=0;i<size;i++)
if(!obj.get(i))
	cout<<"missing number is"<<i<<endl;

return 0;
}