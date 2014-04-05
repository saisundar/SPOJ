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

#define SIZE 52
class lst_node
{
  public:
    string st;
    lst_node *next;
    lst_node(string &a,int start,int length)
    {
      next=NULL;
      st=a.substr(start,length);  
    }
};
class trie_node
{
  public:
  trie_node *arr[SIZE];
  int freq;
  short child;
  bool first;
  lst_node *node;
  trie_node()
  {int i;
   freq=0;
   child=0;
   first=false;
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
    int i,sec;
    unsigned short index=0;
    lst_node *prev=NULL;
    dbgn(a,"inserting");
    if(root==NULL)
    {
      root =new trie_node();
    }
    next=root;
    for(i=0;a[i]!=32;i++)
    {
        dbgn(int(a[i]),"ascii value of");
        index=(a[i]>='A' && a[i]<='Z')?(a[i]-'A'):(a[i]-'a'+26);
        next->arr[index]=(next->arr[index]!=NULL)?next->arr[index]:new trie_node();  
        next->child++;
        next=next->arr[index];
        next->freq++;
    }
    if(next->freq==1)next->first=true;
    next->node=(next->node!=NULL)?next->node:new lst_node(a,0,i);
    prev=next->node;
    i++;
    sec=i;
    next=root;
    for(;a[i]!='\0';i++)
    {
        index=(a[i]>='A' && a[i]<='Z')?(a[i]-'A'):(a[i]-'a'+26);
        next->arr[index]=(next->arr[index]!=NULL)?next->arr[index]:new trie_node();  
        next->child++;
        next=next->arr[index];
        next->freq++;
    }
    next->node=(next->node!=NULL)?next->node:new lst_node(a,sec,i-sec);
    prev->next=next->node;
  }

};

bool traverse_trie(trie_node* root)
{
  int i;
  if (root==NULL)
    return false;
  if(root->child!=0)
  {
    for(i=0;i<SIZE;i++)
      if(root->arr[i]!=NULL)
      {
        if( traverse_trie(root->arr[i]))return true;
      }
   return false;
  }
  else
  {
    if(root->first && root->freq==1)
    {      
      lst_node *temp;
      for(temp=root->node;temp!=NULL;temp=temp->next)
        cout<<temp->st<<"\n";
      return true;
    }
    return false;
  }
}

void display_result(trie a)
{

  trie_node* root=a.root;
  traverse_trie(root);
}

void wrapper(int z)
{
  int n,m,i,j;
	for(i=0;i<z;i++)
  {
   trie t1;

   cin>>n;
   dbgn(n,"n");
   cin.clear();
   cin.ignore();
   for(j=0;j<n-1;j++)
   {
     string str;
     cin.clear();
     getline(cin,str);
     t1.insert(str);
   }
   cout<<"Scenario #"<<i+1<<":"<<"\n";
   display_result(t1);
   cout<<"\n";
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
