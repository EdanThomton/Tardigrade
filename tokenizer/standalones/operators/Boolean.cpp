/**
 * Boolean operators
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../../token.cpp"

class BooleanAnd: public Token {
    public:
        BooleanAnd(): Token("BooleanAnd", "BooleanAnd"){}
};
class BooleanOr: public Token {
    public:
        BooleanOr(): Token("BooleanOr", "BooleanOr"){}
};
class BooleanXor: public Token {
    public:
        BooleanXor(): Token("BooleanXor", "BooleanXor"){}
};

class BooleanAndEq: public Token {
    public:
        BooleanAndEq(): Token("BooleanAndEq", "BooleanAndEq"){}
};
class BooleanOrEq: public Token {
    public:
        BooleanOrEq(): Token("BooleanOrEq", "BooleanOrEq"){}
};
class BooleanXorEq: public Token {
    public:
        BooleanXorEq(): Token("BooleanXorEq", "BooleanXorEq"){}
};

class Not: public Token {
    public:
        Not(): Token("Not", "Not"){}
};