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
    public int sumNumbers(TreeNode root) {
        int sum=0;
        sum=sumNum(root,sum);
        return sum;
 }
    
    public int sumNum(TreeNode root,int fromup){
        int sum=0;
        if(root==null)return fromup;
        int up=(fromup*10)+root.val;
        if(root.left==null && root.right==null)
        return up;
        if(root.left!=null)
        sum=sumNum(root.left,up);
        if(root.right!=null)
        sum+=sumNum(root.right,up);
        return sum;
    }
}