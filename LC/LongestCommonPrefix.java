class Solution {
public:

    string commonPrefix(string a,string b)
    {
        
        int aLen=a.length(),bLen=b.length(),min=(aLen<bLen?aLen:bLen);
        int i;
        
        for(i=0;i<min;i++)
        {
            if(a[i]!=b[i])
            break;
        }
        
        if(i==0)return "";
        
        return(a.substr(0,i));
      
    }
    
    string longestCommonPrefix(vector<string> &strs) {
        
        int len=strs.size();
        if(len<1)return "";
        if(len==1)return strs[0];
        
        int i;
        string cSub=commonPrefix(strs[0],strs[1]);
        
        for(i=2;i<len;i++)
        {
           cSub= commonPrefix(cSub,strs[i]);
            
        }
        
        return cSub;
        
    }
};