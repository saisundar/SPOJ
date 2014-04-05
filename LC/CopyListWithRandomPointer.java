/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 **/
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
    
    RandomListNode head1,prev,prev1,nxt,nxt1;
    int i,n;
    if(head!=null){ head1=new RandomListNode(head.label);head1.next=null;head1.random=null;}else return null;
    
    for(i=0,nxt=head;nxt!=null;i++,nxt=nxt.next);n=i;
    RandomListNode[] arr_next =new RandomListNode[n];
    int ind=0;
    prev=head; prev1=head1;
    nxt=head.next;
    arr_next[ind++]=nxt;
    head.next=head1;
    head1.random=head;
    while(nxt!=null)
    {
        nxt1=new RandomListNode(nxt.label);nxt1.next=null;nxt1.random=null;
        prev1.next=nxt1;
        prev=nxt;prev1=nxt1;
        nxt=prev.next;
        arr_next[ind++]=nxt;
        prev.next=prev1;prev1.random=prev;
    }
    
    for(nxt1=head1;nxt1!=null;nxt1=nxt1.next)
    {
        nxt=nxt1.random;
        nxt1.random=(nxt.random!=null)?nxt.random.next:null;
    }
    
    prev=head;
    for(i=0;i<n;i++)
    {
        prev.next=arr_next[i];
        prev=prev.next;
    }
    
    return head1;
    }
}