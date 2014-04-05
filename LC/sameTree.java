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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        
        if(p==null && q==null)return true;
        if(p==null||q==null)return false;
        
        return(isSameTree(p.right,q.right) && isSameTree(p.left,q.left) && p.val==q.val);
    }
}