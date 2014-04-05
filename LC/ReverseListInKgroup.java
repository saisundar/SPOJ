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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        dummy=reverse(dummy,k);
        return dummy.next;
    }
    
    public ListNode reverse(ListNode head, int k)
    {
        if(head==null)return null;
        ListNode prev=null,temp=null,nxt=null,t=null,p=null;
        int length=0,i=0,j=0;
        
        for(length=0,temp=head.next;temp!=null;temp=temp.next,length++);
        
        int rem=length%k;int num=length/k;
        prev=head;temp=head.next;nxt=null;
        for(i=0;i<num;i++)
        {
            t=temp;p=prev;
            for(j=0;j<k;j++,prev=temp,temp=nxt)
            {
                nxt=temp.next;temp.next=prev;
            }
            t.next=temp;
            p.next=prev;
            prev=t;
            
        }
        return head;
    }
}