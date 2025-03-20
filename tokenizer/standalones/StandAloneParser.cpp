#pragma once
#include "operators/Arithmetic.cpp"
#include "operators/Bitwise.cpp"
#include "operators/Boolean.cpp"
#include "operators/OtherOperators.cpp"
#include "tokens/NonOps.cpp"
#include "../token.cpp"
#include "../unparsed.cpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class StandAloneParser {

    private:

        static vector<Token>* for_each_unparsed(Token t) {

            vector<Token>* result = new vector<Token>();

            string c = t.get_content();
            c += "    ";

            string lit = "";

            for(int i = 0; i < c.length(); i++) {
                char current = c[i];
                char next0 = c[i+1];
                char next1 = c[i+2];

                switch(current) {
                case '+':
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(AddEq());
                        lit = "";
                        i++;
                        break; // +=
                    case '+': 
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Increment());
                        lit = "";
                        i++;
                        break; // ++
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Add());
                        lit = "";
                        break; // +
                    }
                    break;
                case '-':
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(SubEq());
                        lit = "";
                        i++;
                        break; // -=
                    case '-':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Decrement());
                        lit = "";
                        i++;
                        break; // --
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Sub());
                        lit = "";
                        break; // -
                    }
                    break;
                case '*':
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(MulEq());
                        lit = "";
                        i++;
                        break; // *=
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Mul());
                        lit = "";
                        break; // *
                    }
                    break;
                case '/':
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(DivEq());
                        lit = "";
                        i++;
                        break; // /=
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Div());
                        lit = "";
                        break; // /
                    }
                    break;
                case '%':
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(ModEq());
                        lit = "";
                        i++;
                        break; // %=
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Mod());
                        lit = "";
                        break; // %
                    }
                    break;
                case '&':
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(AndEq());
                        lit = "";
                        i++;
                        break; // &=
                    case '&':
                        switch(next1) {
                        case '=':
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(BooleanAndEq());
                            lit = "";
                            i+=2;
                            break; // &&=
                        default:
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(BooleanAnd());
                            lit = "";
                            i++;
                            break; // &&
                        }
                        break;
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(And());
                        lit = "";
                        break; // &
                    }
                    break;
                case '|':
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(OrEq());
                        lit = "";
                        i++;
                        break; // |=
                    case '|':
                        switch(next1) {
                        case '=':
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(BooleanOrEq());
                            lit = "";
                            i+=2;
                            break; // ||=
                        default:
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(BooleanOr());
                            lit = "";
                            i++;
                            break; // ||
                        }
                        break;
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Or());
                        lit = "";
                        break; // |
                    }
                    break;
                case '^':
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(XorEq());
                        lit = "";
                        i++;
                        break; // ^=
                    case '^':
                        switch(next1) {
                        case '=':
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(BooleanXorEq());
                            lit = "";
                            i+=2;
                            break; // ^^=
                        default:
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(BooleanXor());
                            lit = "";
                            i++;
                            break; // ^^
                        }
                        break;
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Xor());
                        lit = "";
                        break; // ^
                    }
                    break;
                case '<': 
                    switch(next0) {
                    case '=':
                        switch(next1) {
                        case '>':
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(ThreeWayComparison());
                            lit = "";
                            i+=2;
                            break; // <=>
                        default:
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(LessThanOrEqual());
                            lit = "";
                            i++;
                            break; // <=
                        }
                        break;
                    case '<': 
                        switch(next1) {
                        case '=':
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(ShiftLeftEq());
                            lit = "";
                            i+=2;
                            break; // <<=
                        default:
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(ShiftLeft());
                            lit = "";
                            i++;
                            break; // <<
                        }
                        break;
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(LessThan());
                        lit = "";
                        break; // <
                    }
                    break;
                case '>': 
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(GreaterThanOrEqual());
                        lit = "";
                        i++;
                        break; // >=
                    case '>': 
                        switch(next1) {
                        case '=':
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(ShiftRightEq());
                            lit = "";
                            i+=2;
                            break; // >>=
                        default:
                            if(lit != "") { result->push_back(Unparsed(lit)); }
                            result->push_back(ShiftRight());
                            lit = "";
                            i++;
                            break; // >>
                        }
                        break;
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(GreaterThan());
                        lit = "";
                        break; // >
                    }
                    break;
                case '~':
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(Negate());
                    lit = "";
                    break; // ~
                case '!': 
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(NotEquals());
                        lit = "";
                        i++;
                        break; // !=
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Not());
                        lit = "";
                        break; // !
                    }
                    break;
                case '=': 
                    switch(next0) {
                    case '=':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Equals());
                        lit = "";
                        i++;
                        break; // ==
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(SetEquals());
                        lit = "";
                        break; // =
                    }
                    break;
                case '.': 
                    switch(next0) {
                    case '.':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Range());
                        lit = "";
                        i++;
                        break; // ..
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(Accessor());
                        lit = "";
                        break; // .
                    }
                    break;
                case ';':
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(Semicolon());
                    lit = "";
                    break; // ;
                case ':':
                    switch(next0) {
                    case ':':
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(TerneryElse());
                        lit = "";
                        i++;
                        break; // ::
                    default:
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        result->push_back(TypeNotation());
                        lit = "";
                        break; // :
                    }
                    break;
                case '?':
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(TerneryIf());
                    lit = "";
                    break; // ?
                default:
                    lit += current;
                    break;
                }
            }
            if(lit != "") { result->push_back(Unparsed(lit)); }

            return result;
        }
    public:
        static void pass(vector<Token>* token_arr) {
            vector<Token> next = vector<Token>();
            for(int i = 0; i < token_arr->size(); i++) {
                Token t = (*token_arr)[i];
                if(is_unparsed(t)) {
                    vector<Token>* res = for_each_unparsed(t);

                    for(int j = 0; j < res->size(); j++) {
                        Token t2 = (*res)[j];
                        next.push_back(t2);
                    }

                    delete res;
                } else {
                    next.push_back(t);
                }
            }
            *token_arr = next;
        }

};