#include <iostream>
#include <iomanip>
#include <cstring>
#include <stack>

// PEDMAS
int Precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int Operation(int a, int b, char op)
{
    //std::cout << op << std::endl;
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

int EvaluateExpr(char input[])
{
    int i;
    std::stack<int> values;
    std::stack<char> ops;

    for (i = 0; i < strlen(input); i++)
    {
        //std::cout << input[i] << std::endl;

        if (input[i] == ' ')
            continue;

        if (input[i] == '(')
        {
            //std::cout << "pushing " << input[i] << " to ops" << std::endl;
            ops.push(input[i]);
        }
        else if (isdigit(input[i]))
        {
            int val = 0;

            while (i < strlen(input) &&
                   isdigit(input[i]))
            {
                val = (val * 10) + (input[i] - '0');
                //std::cout << "current: " << input[i] << " next: " << input[i + 1] << std::endl;
                if (isdigit(input[i + 1]))
                {
                    std::cout << "i++\n";
                    i++;
                }
                else
                {
                    break;
                }
            }
            //std::cout << "pushing " << val << " to values" << std::endl;
            values.push(val);
        }
        else if (input[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                //std::cout << "popping " << val2 << " from values" << std::endl;
                values.pop();

                int val1 = values.top();
                //std::cout << "popping " << val1 << " from values" << std::endl;
                values.pop();

                char op = ops.top();
                //std::cout << "popping " << op << " from ops" << std::endl;
                ops.pop();

                //std::cout << "performing operation " << val1 << " " << op << " " << val2 << std::endl;
                values.push(Operation(val1, val2, op));
            }

            if (!ops.empty())
            {
                //std::cout << "popping " << ops.top() << " from ops" << std::endl;
                ops.pop();
            }
        }

        else
        {
            while (!ops.empty() && Precedence(ops.top()) >= Precedence(input[i]))
            {
                int val2 = values.top();
                //std::cout << "popping " << val2 << " from values" << std::endl;
                values.pop();

                int val1 = values.top();
                //std::cout << "popping " << val1 << " from values" << std::endl;
                values.pop();

                char op = ops.top();
                //std::cout << "popping " << op << " from ops" << std::endl;
                ops.pop();

                //std::cout << "performing operation " << val1 << " " << op << " " << val2 << std::endl;
                values.push(Operation(val1, val2, op));
            }

            //std::cout << "pushing " << input[i] << " to ops" << std::endl;
            ops.push(input[i]);
        }
    }

    while (!ops.empty())
    {
        int val2 = values.top();
        //std::cout << "popping " << val2 << " from values" << std::endl;
        values.pop();

        int val1 = values.top();
        //std::cout << "popping " << val1 << " from values" << std::endl;
        values.pop();

        char op = ops.top();
        //std::cout << "popping " << op << " from ops" << std::endl;
        ops.pop();

        //std::cout << "pushing " << input[i] << " to ops" << std::endl;
        values.push(Operation(val1, val2, op));
    }

    return values.top();
}

int main(int argc, char *argv[])
{
    char str[9999];
    std::cout << "Enter the math expression: ";
    std::cin.getline(str, 9999);

    std::cout << "The result of " << str << " is "
              << EvaluateExpr(str) << "." << std::endl;
    return 0;
}