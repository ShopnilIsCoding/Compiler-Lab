#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cctype>

using namespace std;

bool isIdentifier(string word)
{
    return (word[0] >= 'a' && word[0] <= 'z') ||
           (word[0] >= 'A' && word[0] <= 'Z') ||
           word[0] == '_';
}

bool isSymbol(string word)
{
    return word.size() == 1 && (word[0] == '{' || word[0] == '}' || word[0] == '(' || word[0] == ')' || word[0] == '[' || word[0] == ']' ||
                                word[0] == ';' || word[0] == ',' || word[0] == '.' || word[0] == ':' || word[0] == '"' || word[0] == '\'');
}

bool isOperator(string word)
{
    return word[0] == '=' || word[0] == '+' || word[0] == '-' || word[0] == '*' || word[0] == '/' ||
           word[0] == '%' || word[0] == '<' || word[0] == '>' || word[0] == '!' || word[0] == '&' ||
           word[0] == '|' || word[0] == '^' || word[0] == '~' || word[0] == '?' || word[0] == ':' || word == "<<";
}

bool isKeyword(string word)
{
    return word == "break" || word == "char" || word == "continue" || word == "do" ||
           word == "double" || word == "else" || word == "float" || word == "for" ||
           word == "if" || word == "int" || word == "long" || word == "return" ||
           word == "while" || word == "cout" || word == "cin" || word == "endl" ||
           word == "main" || word == "void";
}

bool isInteger(string word)
{
    for (char c : word) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool isFloat(string word)
{
    bool dotFound = false;
    for (char c : word) {
        if (c == '.') {
            if (dotFound)
                return false; 
            dotFound = true;
        }
        else if (!isdigit(c))
            return false; 
    }
    return true;
}

bool isExponential(string word) {
    size_t ePos = word.find('e');
    size_t caretPos = word.find('^');

    if (ePos != string::npos && caretPos != string::npos && ePos < caretPos) {

        string base = word.substr(0, ePos);
        string exponent = word.substr(caretPos + 1);

        return (isFloat(base) || isInteger(base)) && (isFloat(exponent) || isInteger(exponent));
    }

    return false; 
}


int Tokenizer(string code,
              vector<string> &keywords,
              vector<string> &identifiers,
              vector<string> &symbols,
              vector<string> &operators,
              vector<string> &integers,
              vector<string> &floats,
              vector<string> &exponentials)
{
    int token = 0;
    stringstream ss(code);
    string word;
    set<string> matching;
    while (ss >> word)
    {
        if (isKeyword(word))
        {
            keywords.push_back(word);
            token++;
        }
        else if (isIdentifier(word))
        {
            identifiers.push_back(word);
            token++;
        }
        else if (isSymbol(word))
        {
            symbols.push_back(word);
            token++;
        }
        else if (isOperator(word))
        {
            operators.push_back(word);
            token++;
        }
        else if (isInteger(word))
        {
            integers.push_back(word);
            token++;
        }
        else if (isFloat(word))
        {
            floats.push_back(word);
            token++;
        }
        else if (isExponential(word))
        {
            exponentials.push_back(word);
            token++;
        }
    }
    return token;
}

int main()
{
    string code;
    cout << "Enter code In a single line and provide space after each Token -->> " << endl;
    cout << "Enter code : ";
    getline(cin, code);
    vector<string> keywords, identifiers, symbols, operators, integers, floats, exponentials;
    Tokenizer(code, keywords, identifiers, symbols, operators, integers, floats, exponentials);


    cout << "Identifiers : " << identifiers.size() << "   ";
    for (string word : identifiers)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Keywords : " << keywords.size() << "   ";
    for (string word : keywords)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Symbols : " << symbols.size() << "   ";
    for (string word : symbols)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Operators : " << operators.size() << "   ";
    for (string word : operators)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Integers : " << integers.size() << "   ";
    for (string word : integers)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Floats : " << floats.size() << "   ";
    for (string word : floats)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Exponentials : " << exponentials.size() << "   ";
    for (string word : exponentials)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Token Count : " << Tokenizer(code, keywords, identifiers, symbols, operators, integers, floats, exponentials);

    return 0;
}