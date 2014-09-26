class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> line;
        if(rowIndex < 0)
        {
            return line;
        }
        line.push_back(1);
        int i = 0;
        int j;
        while(i < rowIndex)
        {
            int s = line.size();
            int last = line[0];
            for(j = 1; j < s; j++)
            {
                int sum = last+line[j];
                last = line[j];
                line[j] = sum;
            }
            line.push_back(1);
            i++;
        }
        return line;
    }
};