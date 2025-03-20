/**
 * Argument/Parenthesis grouping
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../token.cpp"

class ArgumentBlockStart: public Token {
    public:
        ArgumentBlockStart(): Token("ArgumentBlockStart", "ArgumentBlockStart"){}
};
class ArgumentSeparator: public Token {
    public:
        ArgumentSeparator(): Token("ArgumentSeparator", "ArgumentSeparator"){}
};
class ArgumentBlockEnd: public Token {
    public:
        ArgumentBlockEnd(): Token("ArgumentBlockEnd", "ArgumentBlockEnd"){}
};