# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
#include <cstring>
using namespace std;
#include <cstdlib>
using namespace std;
//# define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug 
# define dbgn(i,str)  cout<<"the value of"<<str<<" is "<<i<<"\n";
# else
# define dbgn(i,str)  (void)0;
#endif

#define md(val) ((val<0)?(val*-1):(val*1))
#define mn(m1,m2) (m1=((m1>m2)?m2:m1))
#define mx(m1,m2) (m1=((m1<m2)?m2:m1))
#define max(m1,m2) ((m1>m2)?m1:m2)
#define min(m1,m2) ((m1<m2)?m1:m2)
#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

#define hashval(str,len,val) {int z;for(val=0,z=0;z<len;z++){val+=19*(str[z]*(z+1))%101;}}


char *hsh[101];
int num;

static inline void del()
{
  short j;
  char c[16];
  int ascii_sum=0,next;
  scanf("%s\n",c);
  hashval(c,strlen(c),ascii_sum);
 for(j=0;j<=19;j++)
  {
    next=((ascii_sum%101+(j*(j+23)))%101)%101;
    if(hsh[next]==NULL)continue;
    if(strncmp(hsh[next],c,16)==0)
    {
      free(hsh[next]);
      hsh[next]=NULL;
      num--;
      break;
    }
  }
}

static inline void add()
{
  short j,len,first_loc=-1;
  char c[16];
  int ascii_sum=0,next;
  char *temp=NULL;
  scanf("%s\n",c);
  len=strlen(c)+1;
  temp=new char[len];
  strncpy(temp,c,len);
  bool found=false;

  hashval(temp,len,ascii_sum);
  for(j=0;j<=19;j++)
  {
    next=(ascii_sum%101+(j*(j+23))%101)%101;
    if(hsh[next])
    {
      if(strncmp(hsh[next],temp,16))
      continue;
      found=true;
      break;
    }
    else if(first_loc==-1)
    first_loc=next;
  }

  if(found){free (temp);}
  else if(first_loc!=-1)
  {
    hsh[first_loc]=temp;
    num++;
    temp=NULL;
  }
}

void hash(short tests)
{

 char f,s,t,fo; 
 short i=0,j;
 num=0;
 for(i=0;i<tests;i++)
 {
   scanf("%c%c%c%c",&f,&s,&t,&fo);
   if((f=='A')&&(s=='D')&&(t=='D')&&(fo==':'))add();
   else del();
 }
 printf("%d\n",num);
 for(i=0;i<101;i++)
  if(hsh[i])
  {
    cout<<i<<":"<<hsh[i]<<"\n";
    free(hsh[i]);
    hsh[i]=NULL;
  }
}

void wrapper(int n)
{
  unsigned short tests;
  short i;
  for(i=0;i<101;i++)
  hsh[i]=NULL;

  for(i=0;i<n;i++)
  {
   scanf("%hu\n",&tests);
   hash(tests);
  }
}

int main()
{
  int n;
  cin>>n;
  wrapper(n);
	cin.get();
	return 0;
}
