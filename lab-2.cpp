#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int q0 = 0;
const int q1 = 1;
const int q2 = 2;
const int q3 = 3;
const int q4 = 4;

bool floatingPoint(string a)
{
    int state = q0;

    for (char ch : a)
    {
        switch (state)
        {
        case q0:
            if (isdigit(ch))
            {
                state = q1;
            }
            else if (ch == '.')
            {
                state = q2;
            }
            else
            {
                return false;
            }
            break;

        case q1:
            if (isdigit(ch))
            {
            }
            else if (ch == '.')
            {
                state = q2;
            }
            else
            {
                return false;
            }
            break;

        case q2:
            if (isdigit(ch))
            {
                state = q4;
            }
            else
            {
                return false;
            }
            break;

        case q3:
            if (isdigit(ch))
            {
                state = q4;
            }
            else
            {
                return false;
            }
            break;

        case q4:
            if (isdigit(ch))
            {
            }
            else
            {
                return false;
            }
            break;
        }
    }

    return state == q1 || state == q4;
}

int main()
{
    string i;

    cout << "Enter a number ";
    cin >> i;

    if (floatingPoint(i))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}
