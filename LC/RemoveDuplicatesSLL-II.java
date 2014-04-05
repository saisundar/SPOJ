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
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null)return null;
        
        ListNode first=null,prev=null,dummy=new ListNode(-1),temp=null;
        int count;
        dummy.next=head;
        prev=dummy;first=head;
        count=1;
        for(temp=head.next;temp!=null;temp=temp.next)
        {
            if(temp.val==first.val)
            {
                count++;
            }
            else
            {
                if(count>1)
                {
                    prev.next=temp;
                    first=temp;
                    count=1;
                }
                else
                {
                   prev=first;
                   first=temp; 
                   
                }
            }
        }
        if(count>1)
        {
            prev.next=null;
            
        }
        
        return dummy.next;
    }
}