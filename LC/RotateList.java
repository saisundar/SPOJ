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
    public ListNode rotateRight(ListNode head, int n) {
        
        if(head==null) return null;
        int count=0,rem=0;
        ListNode temp=null,last=null;
        
        
        for(count=0,temp=head;temp!=null;temp=temp.next,count++)if (temp.next==null)last=temp;
        if(last!=null)last.next=head;
        if(n>=count)rem=count-(n%count);else rem=count-n;
        temp=head;
        for(int i=0;i<rem;i++){last=temp;temp=temp.next;}
        if(last!=null)last.next=null;
        
        return(temp);
    }
}