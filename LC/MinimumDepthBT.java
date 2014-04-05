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
    public int minDepth(TreeNode root) {
        
        if(root==null)return 0;
        if(root.left ==null && root.right==null)return 1;
        int rt_d=0,lt_d=0;
        rt_d=minDepth(root.right);lt_d=minDepth(root.left);
        
        if(rt_d==0)return lt_d+1;
        else if(lt_d!=0)
        {   rt_d=(rt_d<lt_d)?rt_d+1:lt_d+1;
            return(rt_d);
        }
        else return rt_d+1;
        
        
    }
}