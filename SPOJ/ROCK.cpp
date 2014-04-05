# include <iostream>
using namespace std;
#include <cmath>
using namespace std;
#include <vector>
using namespace std;
#include <cstdlib>
using namespace std;
#include <string>
using namespace std;
//#define debug 1
//# define getint(n,m) cin>>n;for(m=n;m>0;m--)cin>>n;
# ifdef debug
# define dbgn(i,str)  cout<<str<<" = "<<i<<"\n";
# define dbgp(str)    cout<<str<<"\n";
# else
# define dbgn(i,str)  (void)0;
# define dbgp(str)    (void)0;
#endif

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\t";}
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)

int** matrix ;


int recurse(vector<int> &rock,int low,int up)
{
dbgn("within recurse low=",low);
dbgn("within recurse high=",up);
// dbgn("within recurse value=",matrix[low][up]);
// dbgn("within recurse rock=",rock[low]);
  if(matrix[low][up]!=-1)
    return matrix[low][up];

  int left,right,i,sum,diff=up-low,mid=diff/2;

  for(i=low;i<up;i++)
{
  left=recurse(rock,low,i);
  right=recurse(rock,i+1,up);
  dbgn("leftvalue=",left);
  dbgn("rightvalue=",right);
  sum=left+right;

  if((diff)%2==0 && sum>mid)
  {
    dbgn("entered here","so updated");
    sum=diff+1;
    matrix[low][up]=max(sum,matrix[low][up]);
  }
  else
  matrix[low][up]=max(sum,matrix[low][up]);
}
 dbgn("matrix[low][up]=",matrix[low][up]);
return matrix[low][up];
}
int number_of_segments(vector<int> &rock,int length)
{
int rows = length ,cols = length;
matrix = new int*[rows];
dbgn("within number_of_segments",length);
if (rows)
{
    matrix[0] = new int[rows * cols];
    for (int i = 1; i < rows; ++i)
        matrix[i] = matrix[0] + i * cols;
}

for(int i=0;i<length;i++)
{
  for(int j=0;j<length;j++)
    matrix[i][j]=-1;
}
for(int i=0;i<length;i++)
  {
    matrix[i][i]=rock[i];
    dbgn(" ",matrix[i][i]);
  }
 int res=recurse(rock,0,length-1);

delete [] matrix[0];
delete [] matrix;

return res;
}

void wrapper(int n)
{
  int num=0,j=0,i=0;
  dbgn("within wrapper",n);
  for(j=0;j<n;j++)
  {
  cin>>num;
  dbgn("within wrapper","1");
  cin.clear();
  cin.ignore(1000,'\n');
  string str;
  int num_zeros=0,num_ones=0,up=0,tmp;

  cin>>str;
  
  if( num<=0)
  {
  cout<<"0\n";
  continue;
  }
  vector<int> rock(num); 
  up=num;

  for(i=0;i<up ;i++)
  {
    if(str[i]=='1'){
      num_ones++;
       rock[i]=1;
     }
    else 
    {
      num_zeros++;
      rock[i]=0;
    }
   
  }

  tmp=2*num_ones-1;
  if(num_ones>num_zeros)
  {
   cout<<min(num,tmp)<<"\n";
   continue;
  }
  if(num_zeros==num)
  {
   cout<<"0"<<"\n";
   continue;
  }
  cout<<number_of_segments(rock,up)<<"\n";
  }
}

int main()
{
  int n;
  cin.clear();
  cin>>n;
  wrapper(n);
  cin.get();
  return 0;
}


