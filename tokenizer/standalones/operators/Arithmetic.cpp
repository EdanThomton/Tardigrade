/**
 * Arithmetic Operators
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../../token.cpp"

class Add: public Token {
    public:
        Add(): Token("Add", "Add"){}
};
class Sub: public Token {
    public:
        Sub(): Token("Sub", "Sub"){}
};
class Mul: public Token {
    public:
        Mul(): Token("Mul", "Mul"){}
};
class Div: public Token {
    public:
        Div(): Token("Div", "Div"){}
};
class Mod: public Token {
    public:
        Mod(): Token("Mod", "Mod"){}
};

class AddEq: public Token {
    public:
        AddEq(): Token("AddEq", "AddEq"){}
};
class SubEq: public Token {
    public:
        SubEq(): Token("SubEq", "SubEq"){}
};
class MulEq: public Token {
    public:
        MulEq(): Token("MulEq", "MulEq"){}
};
class DivEq: public Token {
    public:
        DivEq(): Token("DivEq", "DivEq"){}
};
class ModEq: public Token {
    public:
        ModEq(): Token("ModEq", "ModEq"){}
};

class Increment: public Token {
    public:
        Increment(): Token("Increment", "Increment"){}
};
class Decrement: public Token {
    public:
        Decrement(): Token("Decrement", "Decrement"){}
};