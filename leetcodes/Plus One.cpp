class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        int m = digits.size();
        int i;
        int carry = 1;
        for(i = m -1; i >= 0; i--)
        {
            int r = digits[i] + carry;
            if(r < 10)
            {
                digits[i] = r;
                break;
            }
            else
            {
                digits[i] = r % 10;
                if(i == 0)
                {
                    digits.insert(digits.begin(),1);
                }
            }
            
        }
        return digits;
    }
};