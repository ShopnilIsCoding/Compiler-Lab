#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

bool isIdentifier(const string& word) {
    for (char c : word) {
        if (!((c >= 'a' && c <= 'z') ||
              (c >= 'A' && c <= 'Z') ||
              c == '_')) {
            return false;
        }
    }
    return true;
}

bool isSymbol(const string& word) {
    return word.size() == 1 && (word[0] == '{' || word[0] == '}' || word[0] == '(' || word[0] == ')' || word[0] == '[' || word[0] == ']' ||
           word[0] == ';' || word[0] == ',' || word[0] == '.' || word[0] == ':' || word[0] == '"' || word[0] == '\'');
}

bool isCodeOperator(const string& word) {
    return word.size() == 1 && (word[0] == '=' || word[0] == '+' || word[0] == '-' || word[0] == '*' || word[0] == '/' ||
           word[0] == '%' || word[0] == '<' || word[0] == '>' || word[0] == '!' || word[0] == '&' ||
           word[0] == '|' || word[0] == '^' || word[0] == '~' || word[0] == '?' || word[0] == ':');
}

bool isKeyword(const string& word) {
    return word == "break" || word == "char" || word == "continue" || word == "do" ||
           word == "double" || word == "else" || word == "float" || word == "for" ||
           word == "if" || word == "int" || word == "long" || word == "return" ||
           word == "while" || word == "cout" || word == "cin";
}

void analyzeCode(const string& code,
                 vector<string>& keywords,
                 vector<string>& identifiers,
                 vector<string>& symbols,
                 vector<string>& operators) {
    stringstream ss(code);
    string word;
    set<string> uniqueWords;
    while (ss >> word) {
        if (uniqueWords.insert(word).second) {
            if (isKeyword(word)) {
                keywords.push_back(word);
            } else if (isIdentifier(word)) {
                identifiers.push_back(word);
            } else if (isSymbol(word)) {
                symbols.push_back(word);
            } else if (isCodeOperator(word)) {
                operators.push_back(word);
            }
        }
    }
}

int main() {
    string code;
    cout << "Enter code: ";
    getline(cin, code);
    vector<string> keywords, identifiers, symbols, operators;
    analyzeCode(code, keywords, identifiers, symbols, operators);

    cout << "Keywords: ";
    for (const string& word : keywords) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Identifiers: ";
    for (const string& word : identifiers) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Symbols: ";
    for (const string& word : symbols) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Operators: ";
    for (const string& word : operators) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
