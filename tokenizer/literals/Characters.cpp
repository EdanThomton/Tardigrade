/**
 * Character literal
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../token.cpp"

class Character: public Token {
    private:
        string literal;
    public:
        Character(string literal): Token("Character", "Character(" + literal + ")"){
            this->literal = literal;
        }
};