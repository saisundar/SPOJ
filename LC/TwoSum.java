public class Solution {
    public int[] twoSum(int[] numbers, int target) { 
        
        java.util.HashMap<Integer,Integer> set=new java.util.HashMap<Integer,Integer>();
        int i=0,idx1=0,idx2=0;
        for(i=0;i<numbers.length;i++)
        {
           if(set.containsKey(target-numbers[i]))
           {
               idx1=set.get(target-numbers[i]);
               idx2=i;
               break;
          }
          set.put(new Integer(numbers[i]),new Integer(i));
           
        }
        
        int[] a={idx1+1,idx2+1};
        
        return a;
        
    }
}