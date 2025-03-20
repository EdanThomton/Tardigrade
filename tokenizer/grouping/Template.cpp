/**
 * Template grouping
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../token.cpp"

class TemplateStart: public Token {
    public:
        TemplateStart(): Token("TemplateStart", "TemplateStart"){}
};
class TemplateEnd: public Token {
    public:
        TemplateEnd(): Token("TemplateEnd", "TemplateEnd"){}
};