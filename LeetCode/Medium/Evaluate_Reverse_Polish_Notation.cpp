class Solution {
public:
    int evalRPN(vector<string>& tokens) {
            stack<int>n;
            int n1;
            int n2;
      for(int i=0;i<tokens.size();i++)
        if (tokens[i].compare("+")==0)
        {
           n1=n.top();
           n.pop() ;
           n2=n.top();
           n.pop();
           n.push(n1+n2);
        }
        else if (tokens[i].compare("-")==0)
        {
            n1=n.top();
           n.pop() ;
           n2=n.top();
           n.pop();
           n.push(n2-n1);
        }
        else if (tokens[i].compare("*")==0)
        {
            n1=n.top();
           n.pop() ;
           n2=n.top();
           n.pop();
           n.push(n1*n2);
        }
        else if (tokens[i].compare("/")==0)
        {
            n1=n.top();
           n.pop() ;
           n2=n.top();
           n.pop();
           n.push(n2/n1);
        }
        else
        {
            n.push(stoi(tokens[i]));
        }
        return n.top();
        
    }
};
