/**
 * String literals
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../token.cpp"

class FormattedString: public Token {
    private:
        string literal;
    public:
        FormattedString(string literal): Token("FormattedString", "FormattedString(" + literal + ")"){
            this->literal = literal;
        }
};
class UnformattedString: public Token {
    private:
        string literal;
    public:
        UnformattedString(string literal): Token("UnformattedString", "UnformattedString(" + literal + ")"){
            this->literal = literal;
        }
};