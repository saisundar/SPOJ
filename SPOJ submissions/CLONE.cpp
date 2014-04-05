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

#define SIZE 26
class trie_node
{
  public:
  trie_node *arr[SIZE];
  int freq;
  short child;
  trie_node()
  {int i;
   freq=0;
   child=0;
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

  void insert(string &a)
  {
    trie_node* next;
    int i;
    if(root==NULL)
    {
      root =new trie_node();
    }
    next=root;
    for(i=0;a[i]!='\0';i++)
    {
        next->arr[a[i]-'A']=(next->arr[a[i]-'A']!=NULL)?next->arr[a[i]-'A']:new trie_node();
        next->child++;
        next=next->arr[a[i]-'A'];
        next->freq++;
    }
  }


};

void traverse_trie(trie_node* root,vector<short> &a)
{
int i;
  if (root==NULL)
    return;
  for(i=0;i<SIZE;i++)
    if(root->arr[i]!=NULL)
    {
      traverse_trie(root->arr[i],a);
    }

  if(root->child==0)
    a[root->freq-1]++;
}

void display_result(trie a,int m)
{

  vector<short> array(m);
  int i;

  trie_node* root=a.root;
  traverse_trie(root,array);

  dispout(array);

}

void wrapper(int z)
{
  int n,m,i;
  cin>>n>>m;
  while(n||m )
	{
   trie t1;

   for(i=0;i<n;i++)
   {
     string str;
     cin>>str;
     t1.insert(str);
   }
   display_result(t1,n);
   cin>>n>>m;
	}
}

int main()
{
	wrapper(0);
	cin.get();
	return 0;
}
