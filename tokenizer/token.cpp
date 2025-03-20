/**
 * Class methods for the Token type
 * 
 * @author Edan Thomton
 * @date 3/20/25
 */

#pragma once
#include <string>

using namespace std;

class Token {

    private:
        string s;
        string p;
        string c;
    public:
        Token(string s) {
            this->s = s;
            this->p = "Token(" + s + ")";
            this->c = "";
        };
        Token(string s, string p) {
            this->s = s;
            this->p = p;
            this->c = "";
        };
        Token(string s, string p, string c) {
            this->s = s;
            this->p = p;
            this->c = c;
        };
        string this_token() {
            return s;
        };
        string get_content() { return c; }
        string to_string() { return p; };

};