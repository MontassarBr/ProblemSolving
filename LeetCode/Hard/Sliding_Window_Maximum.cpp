class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int m ;
        vector<int>res;
        int i=0;
        int j=k;
        multiset<int>s;
        for (int i = 0; i < k; i++)
        {
            s.insert(nums[i]);
        }
        
    while (j<nums.size())
    {   
        m=*s.rbegin();
        res.push_back(m);
    s.erase(s.lower_bound(nums[i]));
    s.insert(nums[j]);
    i++;
    j++; 
            
    }
   
    m=*s.begin();
        for(int el:s){
            if (el>m)
            {
                m=el;
            }
                    }
        res.push_back(m);
 return res;
    }
};
