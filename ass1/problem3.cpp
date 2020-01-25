#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::string str = "";
    std::cout << "Enter the string: ";
    std::getline(std::cin, str);

    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string current;

    while (std::getline(ss, current, ' '))
    {
        if (current[0] == 'A' || current[0] == 'E' || current[0] == 'I' || current[0] == 'O' || current[0] == 'U' || current[0] == 'Y' || current[0] == 'a' || current[0] == 'e' || current[0] == 'i' || current[0] == 'o' || current[0] == 'u' || current[0] == 'y')
        {
            current.append("-way");
        }
        else
        {
            int i = 0;
            current.append("-");
            while (!(current[0] == 'A' || current[0] == 'E' || current[0] == 'I' || current[0] == 'O' || current[0] == 'U' || current[0] == 'Y' || current[0] == 'a' || current[0] == 'e' || current[0] == 'i' || current[0] == 'o' || current[0] == 'u' || current[0] == 'y'))
            {
                if (i >= current.size())
                {
                    current.append("way");
                    i += 3;
                    break;
                }
                std::rotate(current.begin(), current.begin() + 1, current.end());
                i++;
            }
            if (i >= current.size())
            {
                tokens.push_back(current);
                break;
            }
            current.append("ay");
        }

        tokens.push_back(current);
    }

    for (std::string token : tokens)
    {
        std::cout << token << " ";
    }
    std::cout << std::endl;
}