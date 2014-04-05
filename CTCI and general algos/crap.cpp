#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <csignal>
using namespace std;

# define debug 1
# ifdef debug
# define dbgn(str1,str2) cout<<setw(50)<<str1<<": "<< setw(10)<< str2<< setw(100)<<__FILE__<<":"<<__LINE__<<endl;
# else
# define dbgn(str1,str2) (void)0;
#endif
#define __func__ __FUNCTION__

char testLog[15];
int test=0;
void testInc()
{
testLog[test++]='P';

}
#define TestSucc() {cout<<"****"<<__func__<<" passed!!!****"<<endl;testInc();}

void testDisp()
{

for(int i=0;i<3 && i< test;i++)
	cout<<"test number "<<i<<((testLog[i]=='P')?" passed":" failed")<<endl;
for(int i=4;i<6 && i< test;i++)
	cout<<"test number 4"<<(i==0?"A":"B")<<((testLog[i]=='P')?" passed":" failed")<<endl;
for(int i=6;i<15 && i< test;i++)
	cout<<"test number "<<i-1<<((testLog[i]=='P')?" passed":" failed")<<endl;
}
void signalHandler( int signum )
 {
     cout << "Crash occurred (" << signum << "debug carefully.....\n";
     // cleanup and close up stuff here
     // terminate program
     testDisp();
    exit(signum);

 }
void testInit()
{
	signal (SIGINT, signalHandler);
	signal (SIGABRT, signalHandler);
	signal (SIGILL, signalHandler);
	signal (SIGSEGV, signalHandler);
	signal (SIGINT, signalHandler);
	signal (SIGTERM, signalHandler);

}

typedef enum { TypeInt = 0, TypeReal, TypeVarChar } AttrType;

int main()
{

	char * summa= (char*)malloc(8);int * summa1= (int*)malloc(4);
	void * test=malloc(4);
	testInit();
	int *p = NULL;
	*p = 1;

	string s="CRAP";
	string idx="idx";
	string table="table";

	


	return 0;
}
