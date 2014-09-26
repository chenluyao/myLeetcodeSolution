/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int maxCount = 0;
        vector<double> ks;
        int vertCount = 0;
        int sameCount = 0;
        double k;
        if(points.size() == 0 || points.size() == 1)
        {
            return points.size();
        }
        for(int i = 0; i < points.size() - 1; ++i)
        {
            Point startPoint = points[i];
            vertCount = 0;
            sameCount = 0;
            ks.clear();
            for(int j = i+1; j < points.size(); ++j)
            {
                Point endPoint = points[j];
                if(endPoint.x == startPoint.x && endPoint.y != startPoint.y)
                {
                    ++ vertCount;
                }
                else if(endPoint.x == startPoint.x && endPoint.y == startPoint.y)
                {
                    ++ sameCount;
                }
                else
                {
                    k = (double)(endPoint.y - startPoint.y)/(double)(endPoint.x - startPoint.x);
                    ks.push_back(k);
                }
            }
            if(vertCount+sameCount > maxCount)
            {
                maxCount = vertCount+sameCount;
            }
            if(!ks.empty())
            {
                sort(ks.begin(),ks.end());
                vector<double>::iterator it;
                int count = 1; // ks.size() == 1, count = 1
                if(ks.size() > 1)
                {
                    for(it = ks.begin() + 1; it != ks.end(); ++it)
                    {
                        double k1 = *it;
                        double k2 = *(it - 1) ;
                        if((k1 - k2) < 0.0001 && (k2 - k1) < 0.0001)
                        {
                            ++ count;
                        }
                        else
                        {
                            if(count +sameCount > maxCount)
                            {
                                maxCount = count +sameCount;
                            }
                            count = 1;
                        }
                    }
                }
                if(count +sameCount> maxCount)
                {
                    maxCount = count+sameCount;
                }
            }
            
        }
        return maxCount+1;
    }
};