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

int i=0;

bitAcc obj(32000);

obj.set(5);
obj.set(7);obj.set(29);obj.set(4567);

for(i=0;i<32000;i++)
{

if(obj.get(i))
	cout<<i<<endl;

obj.set(i);

}

return 0;
}