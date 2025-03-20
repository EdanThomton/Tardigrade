/**
 * Class methods for the Token type
 * 
 * @author Edan Thomton
 * @date 3/20/25
 */

#pragma once
#include <string>
#include "token.h"

using namespace std;

Token::Token(string s) {
    this->s = s;
    this->p = "Token(" + s + ")";
    this->c = "";
}
Token::Token(string s, string p) {
    this->s = s;
    this->p = p;
    this->c = "";
}
Token::Token(string s, string p, string c) {
    this->s = s;
    this->p = p;
    this->c = c;
}
string Token::this_token() {
    return s;
}
string Token::get_content() { return c; }
string Token::to_string() { return p; }