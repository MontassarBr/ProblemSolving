class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack <int> s1;
    queue<int> s3;
      for(int el:popped){
        s3.push(el);
      }
      for (int el:pushed)
      {
        if (el==s3.front())
        {
            s3.pop();
        if (!s1.empty() && !s3.empty())
        {
            while (s1.top()==s3.front()  )
            {
            s1.pop();
            s3.pop();
            if (s1.empty() || s3.empty())
            {
                break;
            }
        }
        
            
            
            }
            
        }
        else{
            s1.push(el);
        }
      }
      while (!s1.empty() && !s3.empty())
      {
        if (s1.top()==s3.front())
        {
            s1.pop();
            s3.pop();
        }
        else
        {
            return false;
        }
        
      }
      return s3.empty() && s1.empty();
      
        }
        
};
