/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int getPeakIndex(MountainArray &arr)
    {
        int l = 0 , h = arr.length() - 1;
        while(l < h)
        {
            int m = l + (h - l) / 2;
            if(arr.get(m) < arr.get(m + 1))
            {
                l = m + 1;
            }
            else
            {
                h = m;
            }
        } 
        return l;
    }

    int findInTerrain(int pi , int target , MountainArray &arr , bool isUpTerrain)
    {
        int l , h;
        if(isUpTerrain)
        {
            l = 0 , h = pi;
        }
        else
        {
            l = pi + 1 , h = arr.length() - 1;
        }
        while(l <= h)
        {
            int m = l + (h - l) / 2;
            int currEl = arr.get(m);
            if(currEl == target) return m;
            else if(currEl < target)
            {
                if(isUpTerrain) l = m + 1;
                else h = m - 1;
            }
            else
            {
                if(isUpTerrain) h = m - 1;
                else l = m + 1;
            }
        }
        return -1;
    }


    int findInMountainArray(int target, MountainArray &arr) {
        int peakInd = getPeakIndex(arr);

        // find left
        int leftAns = findInTerrain(peakInd , target , arr , true);
        if(leftAns != -1) return leftAns;

        return findInTerrain(peakInd , target , arr , false);
        
    }
};
