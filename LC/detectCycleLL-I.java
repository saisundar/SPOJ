/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        ListNode fast=head,slow=head;
        
        while(fast!=null)
        {
            fast=(fast.next==null)?null:fast.next.next;
            slow=slow.next;
            
            if(slow==fast && slow!=null)
            return true;
            
        }
        
        return false;
        
        
    }
}