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
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        
        ArrayList<ArrayList<Integer>> list=new ArrayList<ArrayList<Integer>>();
        
        LO(root,list,0);
        
        return list;
    }
    
    public void LO(TreeNode root,ArrayList<ArrayList<Integer>> list,int depth) {
    
    if(root==null)return;
    if(list.size()<=depth)
    {
        
        list.add(new ArrayList<Integer>());
    }
    LO(root.left,list,depth+1);
    list.get(depth).add(root.val);
    LO(root.right,list,depth+1);
    
    }
        
}