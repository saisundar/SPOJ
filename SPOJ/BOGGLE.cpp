# include<iostream>
using namespace std;
#include<cmath>
using namespace std;
#include <vector>
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

#define dispout(a) {int i;for(i=0;i<a.size();i++)cout<<a[i]<<"\n";}

//YOU SHOULD IDEALLY FREE ALL NODES IN THE TRIE BEFORE EXITING.I AM NOT DOING IT :P

#define SIZE 94
class trie_node
{
  public:
  trie_node *arr[SIZE];
  int freq;
  short child;
  short user;
  short length;
  bool word_end;
  trie_node()
  {int i;
   freq=0;
   child=0;
   user=150;
   length=0;
   word_end=false;
   for(i=0;i<SIZE;i++)
   arr[i]=NULL;
  }
};

class trie
{
  public:
    trie_node *root;

    trie()
    {
      root=new trie_node();
    }

  void insert(string &a,short user)
  {
    trie_node* next;
    int i=0;
    short len=0; 
    while(1)
    {

    next=root;
    len=0;
    for(;a[i]!='\0'&&a[i]!=' ';i++)
    {
      next->arr[a[i]-33]=(next->arr[a[i]-33]!=NULL)?next->arr[a[i]-33]:new trie_node();
        next->child++;
        len++;
        next=next->arr[a[i]-33];
        next->freq++;
    }
    next->word_end=true;
    if(next->user==150||next->user==user)
    next->user=user;
    else
      next->user=151;
    next->length=len;
    if(i==a.size())
      break;
    i++;
    }
  }
};

int inline compute_points(short len)
{

if(len<=4)return 1;
if(len==5)return 2;
if(len==6)return 3;
if(len==7)return 5;
else return 11;

}

void traverse_trie(trie_node* root,vector<int> &a)
{
int i;
  if (root==NULL)
    return;
  for(i=0;i<SIZE;i++)
    if(root->arr[i]!=NULL)
    {
      traverse_trie(root->arr[i],a);
    }

  if(root->word_end && root->user!=150 && root->user!=151)
  {
    a[root->user]+=compute_points(root->length);
  }
}

void display_result(trie a,int m)
{

  vector<int> array(m);
  int i,max=0;

  trie_node* root=a.root;
  traverse_trie(root,array);

  for(i=0;i<array.size();i++)
  if(array[i]>max)
    max=array[i];

  cout<<max<<"\n";
}

void wrapper(int z)
{
  trie t1;int i;
   for(i=0;i<z;i++)
   {
     string str,junk;
     cin.clear();
     getline(cin,str);
     t1.insert(str,i);
   }
  display_result(t1,z);
}

int main()
{
  int n;
  cin>>n;
  cin.ignore();
  wrapper(n);
  return 0;
}
