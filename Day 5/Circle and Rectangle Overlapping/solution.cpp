class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        int xclose = (xc < x1) ? x1 : (xc > x2) ? x2 : xc;
        int yclose = (yc < y1) ? y1 : (yc > y2) ? y2 : yc;
        int dist = pow(abs(xclose - xc),2) +  pow(abs(yclose - yc),2);
        return dist <= pow(radius,2);
    }
};
