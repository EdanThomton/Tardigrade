/**
 * Non-operator standalone tokens
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../../token.cpp"

class Semicolon: public Token {
    public:
        Semicolon(): Token("Semicolon", "Semicolon"){}
};
class TypeNotation: public Token {
    public:
        TypeNotation(): Token("TypeNotation", "TypeNotation"){}
};
class Accessor: public Token {
    public:
        Accessor(): Token("Accessor", "Accessor"){}
};
class TerneryIf: public Token {
    public:
        TerneryIf(): Token("TerneryIf", "TerneryIf"){}
};
class TerneryElse: public Token {
    public:
        TerneryElse(): Token("TerneryElse", "TerneryElse"){}
};