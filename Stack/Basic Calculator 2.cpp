// https://leetcode.com/problems/basic-calculator-ii/
// Given a string s which represents an expression, evaluate
// this expression and return its value.

int calculate(string str)
{
    char operation = '+';
    stack<int> s;
    int currNo = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]) && i != str.length() - 1)
            continue;
        if (isdigit(str[i]))
            currNo = currNo * 10 + (str[i] - '0');
        if (!isdigit(str[i]) || i == str.length() - 1)
        {
            cout << i;
            if (operation == '+')
                s.push(currNo);
            else if (operation == '*')
            {
                int temp = s.top();
                s.pop();
                s.push(temp * currNo);
            }
            else if (operation == '-')
                s.push(-currNo);
            else if (operation == '/')
            {
                int temp = s.top();
                s.pop();
                s.push(temp / currNo);
            }
            currNo = 0;
            operation = str[i];
        }
    }
    int res = 0;
    while (s.size())
    {
        res += s.top();
        s.pop();
    }
    return res;
}