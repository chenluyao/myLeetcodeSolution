public class Solution {
    public String reverseWords(String s) {
        s.trim();
        String [] a = s.split(" ");
        StringBuilder revStr = new StringBuilder();
        for(int i = a.length-1; i >= 0; -- i)
        {
            if(!(a[i].equals("")))
            {
                revStr.append(a[i]);
                revStr.append(" ");
            }
        }
        return revStr.toString().trim();
    }
}