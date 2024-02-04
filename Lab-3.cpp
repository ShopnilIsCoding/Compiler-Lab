#include <iostream>
#include <string>

using namespace std;

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isSign(char c)
{
    return c == '^';
}

bool isValidString(const string &str)
{
    int currentState = 0;

    for (char c : str)
    {
        switch (currentState)
        {
        case 0:
            if (c >= '1' && c <= '9')
                currentState = 1;
            else if (c == '.')
                currentState = 2;
            else
                return false;
            break;
        case 1:
            if (isDigit(c))
                currentState = 1;
            else if (c == '.')
                currentState = 2;
            else if (c == 'e')
                currentState = 4;
            else
                return false;
            break;
        case 2:
            if (isDigit(c))
                currentState = 3;
            else
                return false;
            break;
        case 3:
            if (isDigit(c))
                currentState = 3;
            else if (c == 'e')
                currentState = 4;
            else
                return false;
            break;
        case 4:
            if (isSign(c))
                currentState = 5;
            else
                return false;
            break;
        case 5:
            if (isDigit(c))
                currentState = 6;
            else if (c == '.')
                currentState = 7;
            else
                return false;
            break;
        case 6:
            if (isDigit(c))
                currentState = 6;
            else if (c == '.')
                currentState = 7;
            else
                return false;
            break;
        case 7:
            if (isDigit(c))
                currentState = 8;
            else
                return false;
            break;
        case 8:
            if (isDigit(c))
                currentState = 8;
            else
                return false;
            break;
        }
    }

    return currentState == 8 || currentState==6;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isValidString(input))
    {
        cout << "Valid string" << endl;
    }
    else
    {
        cout << "Invalid string" << endl;
    }

    return 0;
}
