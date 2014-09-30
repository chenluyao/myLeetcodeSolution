public class Solution {
    public int maxProduct(int[] A) {
        int size = A.length;
        if(size == 1)
        {
            return A[0];
        }
        int posP = 0;// not initialize <- 0
        int negP = 0;// not initialize <- 0
        int maxP = 0;
        for(int i = 0; i < size; ++ i) // maxProduct ends at A[i]
        {
            int num = A[i];
            if(num == 0)
            {
                if(negP == 0){}
                else if(negP < 0)
                {
                    negP = 0;
                }
                
                if(posP == 0){}
                else if(posP > 0)
                {
                    maxP = posP > maxP? posP : maxP;
                    posP = 0;
                }
            }
            else if(num > 0)
            {
                if(negP == 0){}
                else if(negP < 0)
                {
                    negP *= num;
                }
                
                if(posP == 0)
                {
                    posP = num;
                }
                else if(posP > 0)
                {
                    posP *= num;
                }
            }
            else // num < 0
            {
                int nextPosP = 0;
                int nextNegP = 0;
                if(negP == 0)
                {
                    negP = num;
                }
                else if(negP < 0)
                {
                    nextPosP = negP * num;
                    negP = num;//
                }
                
                if(posP == 0){}
                else if(posP > 0)
                {
                    maxP = posP > maxP? posP : maxP;
                    nextNegP = posP * num;
                    posP = 0;
                }
                negP = negP < nextNegP? negP : nextNegP;
                posP = posP > nextPosP? posP : nextPosP;
            }
        }
        maxP = posP > maxP? posP : maxP;
        return maxP;
    }
}