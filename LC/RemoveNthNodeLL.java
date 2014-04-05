/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i=0;
        
        ListNode fast=head,slow=head,prev=null,temp;
        
        for(i=0;i<n;i++)fast=fast.next;
        
        while(fast!=null)
        {
            fast=fast.next;
            prev=slow;
            slow=slow.next;
            
        }
        
        temp=slow.next;
        if(prev==null)head=head.next;
        else prev.next=temp;
        slow=null;
        
        
        return(head);
        
        
        
    }
}