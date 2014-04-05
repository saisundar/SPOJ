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
    
    public boolean isMirror(TreeNode T1,TreeNode T2 )
    {
        
        if(T1==null && T2 == null)return true;
        if(T1==null||T2==null)return false;
        
        return( (T1.val==T2.val) && isMirror(T1.left,T2.right) && isMirror(T1.right,T2.left));
        
    }
    public boolean isSymmetric(TreeNode root) {
        
        if(root==null)return true;
        return isMirror(root.left,root.right);
    }
}