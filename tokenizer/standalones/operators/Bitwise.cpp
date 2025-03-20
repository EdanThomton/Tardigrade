/**
 * Bitwise operators
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../../token.cpp"

class And: public Token {
    public:
        And(): Token("And", "And"){}
};
class Or: public Token {
    public:
        Or(): Token("Or", "Or"){}
};
class Xor: public Token {
    public:
        Xor(): Token("Xor", "Xor"){}
};
class ShiftLeft: public Token {
    public:
        ShiftLeft(): Token("ShiftLeft", "ShiftLeft"){}
};
class ShiftRight: public Token {
    public:
        ShiftRight(): Token("ShiftRight", "ShiftRight"){}
};

class AndEq: public Token {
    public:
        AndEq(): Token("AndEq", "AndEq"){}
};
class OrEq: public Token {
    public:
        OrEq(): Token("OrEq", "OrEq"){}
};
class XorEq: public Token {
    public:
        XorEq(): Token("XorEq", "XorEq"){}
};
class ShiftLeftEq: public Token {
    public:
        ShiftLeftEq(): Token("ShiftLeftEq", "ShiftLeftEq"){}
};
class ShiftRightEq: public Token {
    public:
        ShiftRightEq(): Token("ShiftRightEq", "ShiftRightEq"){}
};

class Negate: public Token {
    public:
        Negate(): Token("Negate", "Negate"){}
};