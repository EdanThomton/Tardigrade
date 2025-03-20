/**
 * Code block grouping
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../token.cpp"

class CodeBlockStart: public Token {
    public:
        CodeBlockStart(): Token("CodeBlockStart", "CodeBlockStart"){}
};
class CodeBlockEnd: public Token {
    public:
        CodeBlockEnd(): Token("CodeBlockEnd", "CodeBlockEnd"){}
};