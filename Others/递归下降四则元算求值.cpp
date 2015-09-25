/*
expr ::= expr + term
    |   expr - term
    |   term

term ::= term * factor
    |   term / factor
    |   factor

factor ::= ( expr )
    |   NUM
*/

#include <iostream>

using namespace std;

float expr(char* s, int& pos);
float term(char* s, int& pos);
float factor(char* s, int& pos);
float number(char* s, int& pos);

float expr(char* s, int& pos) {
    float v = term(s, pos);
    while (s[pos] == '+' || s[pos] == '-') {
        if (s[pos++] == '+')
            v += term(s, pos);
        else
            v -= term(s, pos);
    }
    return v;
}

float term(char* s, int& pos) {
    float v = factor(s, pos);
    while (s[pos] == '*' || s[pos] == '/') {
        if (s[pos++] == '*')
            v *= factor(s, pos);
        else
            v /= factor(s, pos);
    }
    return v;
}

float factor(char* s, int& pos) {
    if (s[pos] == '(') {
        pos++;
        float v = expr(s, pos);
        pos++;
        return v;
    } else {
        return number(s, pos);
    }
}

float number(char* s, int& pos) {
    int n = 0;
    while (s[pos] >= '0' && s[pos] <= '9')
        n = n * 10 + s[pos++] - '0';
    return (float)n;
}

float calc(char* exp) {
    int pos = 0;
    return expr(exp, pos);
}

int main() {
    char s[] = "2015-9*22";
    cout << calc(s) << endl;
}
