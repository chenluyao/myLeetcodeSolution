class Solution {
public:
    int candy(vector<int> &ratings) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int m ;
        int i;
        m = ratings.size();
        if(m < 2)
        {
            return m;
        }
        // what about equal rating? not have to be equal!
        int * cand = new int[m];
        int last = ratings[0]+1;
        for(i = 0; i < m; ++i)
        {
            if(ratings[i] <= last)
            {
                cand[i] = 1;
            }
            else
            {
                cand[i] = cand[i-1]+1;
            }
            last = ratings[i];
        }
        last = ratings[m-1]+1;
        int pre;
        for(i = m-1; i >=0; --i)
        {
            if(ratings[i] <= last)
            {
            }
            else
            {
                pre = cand[i];
                cand[i] = pre > cand[i+1]+1 ? pre : cand[i+1]+1;
            }
            last = ratings[i];
        }
        int sum = 0;
        for(i = 0; i < m; ++i)
        {
            sum += cand[i];
        }
        delete []cand;
        return sum;
    }
};