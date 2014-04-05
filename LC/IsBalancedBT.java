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
    
    public int getHeight_bal(TreeNode root){
        
        if(root==null)return 0;
        
        int rt_ht=getHeight_bal(root.right);int lt_ht=getHeight_bal(root.left),ht=-1;
        
        if(rt_ht==-1||lt_ht==-1)return -1;
        
        if(rt_ht>lt_ht)
        {
            if(rt_ht-lt_ht>1)return -1;
            ht=rt_ht+1;
        }
        else
        {
            if(lt_ht-rt_ht>1)return -1;
            ht=lt_ht+1;
        }
            
        
        return ht;
        
    }
    
    public boolean isBalanced(TreeNode root) {
        int height=getHeight_bal(root);
        if(height==-1)return false;
        return true;
     
    }
}