/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    boolean first=false,swap=false;
    TreeNode a=null,b=null;
    TreeNode prev=null;
    
    public void recoverTree(TreeNode root) {
        
        recurse(root);
        
        if(!swap)
        {
            int temp=a.val;
                a.val=b.val;
                b.val=temp;
                
                return;
        }
    }
    
    public void recurse(TreeNode root){
        if(root==null)return;
        
        recurse(root.left);
        
        if((prev!=null) && root.val<prev.val)
        {
             b=root;
            if(!first)
            {
                a=prev;
                first=true;
            }
            else
            {
                int temp=a.val;
                a.val=b.val;
                b.val=temp;
                swap=true;
                return;
            }
           
        }
        
         prev=root;
         
         recurse(root.right);
    }
}