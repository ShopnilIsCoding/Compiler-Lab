#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

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

bool isCodeOperator(string word)
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
           word == "while" || word == "cout" || word == "cin" || word == "endl";
}

void analyzeCode(string code,
                 vector<string> &keywords,
                 vector<string> &identifiers,
                 vector<string> &symbols,
                 vector<string> &operators)
{
    stringstream ss(code);
    string word;
    set<string> uniqueWords;
    while (ss >> word)
    {
        if (uniqueWords.insert(word).second)
        {
            if (isKeyword(word))
            {
                keywords.push_back(word);
            }
            else if (isIdentifier(word))
            {
                identifiers.push_back(word);
            }
            else if (isSymbol(word))
            {
                symbols.push_back(word);
            }
            else if (isCodeOperator(word))
            {
                operators.push_back(word);
            }
        }
    }
}

int main()
{
    string code;
    cout << "Enter code In a single line and provide space after each Token -->> " << endl;
    cout << "Enter code : ";
    getline(cin, code);
    vector<string> keywords, identifiers, symbols, operators;
    analyzeCode(code, keywords, identifiers, symbols, operators);

    cout << "Keywords: ";
    for (string word : keywords)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Identifiers: ";
    for (string word : identifiers)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Symbols: ";
    for (string word : symbols)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Operators: ";
    for (string word : operators)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}

// Enter code In a single line and provide space after each Token -->>

// example input

// int main ( )
// {
// int x = 10 ;
// int y = 20 ;
// cout << "Sum: " << ( x + y ) << endl ;
// return 0 ;
// }

// example output

// Keywords: int cout endl return
// Identifiers: main x y
// Symbols: ( ) { ; " }
// Operators: = << +