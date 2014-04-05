# include <iostream>
using namespace std;
# include<cctype>
using namespace std;
# include <string.h>
# define null 0

void reverse_strl(char *a,int st,int en)
{
 if(a==null||st>=en)
 return;
cout<<"st="<<st<<"en="<<en<<"\n";
 
 int len=en-st+1,mid=(len)/2,i;
 char temp;
 for(i=0;i<mid;i++)
 {temp=a[st+i];
 a[st+i]=a[en-i];
 a[en-i]=temp;
 }
 cout <<a<<"\n";
 return;
 }

int main()
{
char a[20]="naa oru mutaalunga";
cout<<a<<"\n";
reverse_strl(a,0,strlen(a)-1);
int st=0,en=0,i=0;
for(i=0;i<=strlen(a);i++)
{
 if(!isalpha(a[i]))
 {
  en=i-1;
  reverse_strl(a,st,en);
  st=en+2;
  }
  }
return 0;
}



 