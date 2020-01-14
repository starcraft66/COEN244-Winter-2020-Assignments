#include <iostream>
#include <cstring>

int DecimalValue(char r)
{
    switch (r)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;

    default:
        return -1;
    }
}

int RomanToDecimal(char str[])
{
    int res = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        int s1 = DecimalValue(str[i]);
        if (i + 1 < strlen(str))
        {
            int s2 = DecimalValue(str[i + 1]);
            if (s1 >= s2)
            {
                res = res + s1;
            }
            else
            {
                res = res + s2 - s1;
                i++;
            }
        }
        else
        {
            res = res + s1;
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    char roman[999];

    std::cout << "Enter the roman numeral: ";
    std::cin >> roman;

    std::cout << "The roman number " << roman << " is " << RomanToDecimal(roman) << " in decimal." << std::endl;
    return 0;
}