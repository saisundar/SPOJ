public class LRUCache {
    private class Node{
        
        public int key;
        public int value;
        
        Node(int k,int val)
        {
            key=k;value=val;
        }
    }
    int size;
    LinkedList<Node> List;
    HashMap<Integer,Node> hshmap;
    
    public LRUCache(int capacity) {
        size=capacity;
        List=new LinkedList<Node>();
        hshmap =new HashMap<Integer,Node>();
    }
    
    public int get(int key) {
        if(hshmap.containsKey(key))
        {
            Node temp=hshmap.get(key);
            List.remove(temp);
            List.addFirst(temp);
            return temp.value;
        }
        
        return -1;
    }
    
    public void set(int key, int value) {
        Node temp=null;
        if(hshmap.containsKey(key))
        {
            temp=hshmap.get(key);
            temp.value=value;
            List.remove(temp);
            List.addFirst(temp);
            return;
        }
        else if(List.size()==size)
        {
            temp=List.removeLast();
            hshmap.remove(temp.key);
    
        }
        
        temp=new Node(key,value);
        List.addFirst(temp);
        hshmap.put(key,temp);
        
    }
}