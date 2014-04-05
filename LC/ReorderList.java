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
    
    public ListNode reorder(ListNode n1,ListNode n2)
    {
        ListNode first,nxt,temp;
        if(n1==null)return null;
        first=n1;nxt=n2;
        
        while(first!=null)
        {
            temp=first.next;
            first.next=nxt;
            first=nxt;
            nxt=temp;
        }
        
        return n1;
        
    }    
    public ListNode reverse_iter(ListNode head) {
		ListNode prev = null, temp = head, nxt = null;
		for (temp = head; temp != null; prev = temp, temp = nxt) {
			nxt = temp.next;
			temp.next = prev;
		}
	    head = prev;
	    return head;
	}
    public void reorderList(ListNode head) {
        ListNode fast=head,slow=head,prev_slow=null;
        if(head==null)return;
        
        while(fast!=null)
        {   prev_slow=slow;
            slow=slow.next;
            fast=fast.next==null?null:fast.next.next;
        }
        
        prev_slow.next=null;
        slow=reverse_iter(slow);
        ListNode temp=reorder(head,slow);
        
    }
}