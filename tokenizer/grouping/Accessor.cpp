/**
 * Accessor grouping
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../token.cpp"

class AccessorStart: public Token {
    public:
        AccessorStart(): Token("AccessorStart", "AccessorStart"){}
};
class AccessorEnd: public Token {
    public:
        AccessorEnd(): Token("AccessorEnd", "AccessorEnd"){}
};