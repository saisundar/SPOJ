# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
using namespace std;
#include <cstdlib>
using namespace std;

# define debug 1
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
#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i];cout<<"\n";}
#define iseq(a,b) ((a==b)?(true):(false))

static inline void comp_lp(char *pat,int *lp,int l)
{
  lp[0]=0;
  int i,prev_len=0;
  i=1;
  while(i<l)
  {
    if(iseq(*(pat+i),*(pat+prev_len)))
    {
      prev_len++;*(lp+i)=prev_len;i++;
    }
    else
    {
      if(prev_len)prev_len=*(lp+prev_len-1);
      else
        *(lp+i++)=0;
    }
  }
}
void kmp(char *pat,int l)
{
  int *lp=new int[l];
  *lp=0;
  comp_lp(pat,lp,l);
  int i=0,j=0;
  char str;
  scanf("%c",&str);
  while(str!='\n')
  {
    if(iseq(str,*(pat+j)))
    {i++;j++;
      if(j==l)
      {
        printf("%d\n",i-j);
        j=*(lp+j-1);
      }
      scanf("%c",&str);;
      continue;
    }
    if(j)j=*(lp+j-1);
    else
    {
      i++;
      scanf("%c",&str);
    }
  }
  free(lp);
}

void wrapper(int n)
{
  int i,temp;
  while(scanf("%d\n",&n)!=EOF)
  {
  char *pat=new char[n];  
  scanf("%s\n",pat);
  fflush(stdin);
  kmp(pat,n);
  free (pat);
  printf("\n");
  }
}

int main()
{
	wrapper(0);
	cin.get();
	return 0;
}
