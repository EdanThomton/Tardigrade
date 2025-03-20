/**
 * Other various standalone operators
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../../token.cpp"

class Equals: public Token {
    public:
        Equals(): Token("Equals", "Equals"){}
};
class NotEquals: public Token {
    public:
        NotEquals(): Token("NotEquals", "NotEquals"){}
};
class GreaterThan: public Token {
    public:
        GreaterThan(): Token("GreaterThan", "GreaterThan"){}
};
class LessThan: public Token {
    public:
        LessThan(): Token("LessThan", "LessThan"){}
};
class GreaterThanOrEqual: public Token {
    public:
        GreaterThanOrEqual(): Token("GreaterThanOrEqual", "GreaterThanOrEqual"){}
};
class LessThanOrEqual: public Token {
    public:
        LessThanOrEqual(): Token("LessThanOrEqual", "LessThanOrEqual"){}
};
class ThreeWayComparison: public Token {
    public:
        ThreeWayComparison(): Token("ThreeWayComparison", "ThreeWayComparison"){}
};

class SetEquals: public Token {
    public:
        SetEquals(): Token("SetEquals", "SetEquals"){}
};
class Range: public Token {
    public:
        Range(): Token("Range", "Range"){}
};