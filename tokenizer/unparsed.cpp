/**
 * Unparsed Token
 * 
 * This is used as a buffer for code not parsed 
 * during the tokenization stage
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "token.cpp"

class Unparsed: public Token {

    private:
        string content;
    public:
        Unparsed(string content): Token("UNPARSED", "Unparsed(" + content + ")", content) {
            this->content = content;
        }
        string get_content() {
            return content;
        }
};

bool is_unparsed(Token t) {
    return (t.this_token() == "UNPARSED");
}