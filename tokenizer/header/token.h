/**
 * Main token class
 * 
 * @author Edan Thomton
 * @date 3/19/25
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
        Token(string s);
        Token(string s, string p);
        Token(string s, string p, string c);
        string this_token();
        string get_content();
        string to_string();

};