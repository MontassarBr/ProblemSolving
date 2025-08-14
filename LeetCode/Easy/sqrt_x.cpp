class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        start =0;
        end = x;
        while(start<=end):
            mid=start+((end-start)/2)
            if ((mid*mid)==x):
                return mid
            
            elif ((mid*mid)>x):
                end=mid-1;
            else:
                start=mid+1
                res=mid
        return res
