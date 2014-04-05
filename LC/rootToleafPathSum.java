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
    public boolean hasPathSum(TreeNode root, int sum) {
     
     if(root==null)return false;
     
     boolean isLeaf=(root.right==null && root.left==null);
     
     if(isLeaf && root.val==sum)return true;
     return(hasPathSum(root.right,sum-root.val) ||hasPathSum(root.left,sum-root.val) );
        
    }
}