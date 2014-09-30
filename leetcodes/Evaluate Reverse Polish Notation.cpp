class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.size() == 0)
        {
            return 0;
        }
        stack<int> numbers;
        while(!numbers.empty())
        {
            numbers.pop();
        }
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < tokens.size(); ++ i )
        {
            string s = tokens[i];
            if(s.size() != 1 || ! isOperator(s[0]))
            {
                int num0 = atoi(s.c_str());
                numbers.push(num0);
            }
            else
            {
                switch (s[0])
                {
                    case '+': 
                    if(!numbers.empty())
                    {
                        num2 = numbers.top(); 
                        numbers.pop();
                        num1 = numbers.top(); 
                        numbers.pop();
                    }
                    numbers.push(num1+num2);
                    break;
                    case '-': 
                    if(!numbers.empty())
                    {
                        num2 = numbers.top(); 
                        numbers.pop();
                        num1 = numbers.top(); 
                        numbers.pop();
                    }
                    numbers.push(num1-num2);
                    break;
                    case '*': 
                    if(!numbers.empty())
                    {
                        num2 = numbers.top(); 
                        numbers.pop();
                        num1 = numbers.top(); 
                        numbers.pop();
                    }
                    numbers.push(num1*num2);
                    break;
                    case '/': 
                    if(!numbers.empty())
                    {
                        num2 = numbers.top(); 
                        numbers.pop();
                        num1 = numbers.top(); 
                        numbers.pop();
                    }
                    if(num2 != 0)
                    {
                        numbers.push((int)(num1/num2));
                    }
                    else return 0;
                    break;
                    default: break;
                }
            }
        }
        return numbers.top();
    }
    bool isOperator(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
};