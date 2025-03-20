/**
 * First stage of the tokenization pipeline
 * Literals (String and Character literals)
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "Strings.cpp"
#include "Characters.cpp"
#include "../token.cpp"
#include "../unparsed.cpp"
#include <vector>
#include <iostream>

using namespace std;

enum ActiveLiteral {
    NONE,
    SINGLE_LINE_STRING,
    MULTI_LINE_STRING,
    CHARACTER
};

class LiteralParser {

    private:
        static vector<Token>* for_each_unparsed(Token t) {

            vector<Token>* result = new vector<Token>();

            string c = t.get_content();
            ActiveLiteral mode = ActiveLiteral::NONE;

            string lit = "";
            for(int i = 0; i < c.length(); i++) {
                char current = c[i];

                switch(mode) {

                case NONE:
                    if(current == '\"') {
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        lit = "";
                        mode = SINGLE_LINE_STRING;
                    } else if(current == '`') {
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        lit = "";
                        mode = MULTI_LINE_STRING;
                    } else if(current == '\'') {
                        if(lit != "") { result->push_back(Unparsed(lit)); }
                        lit = "";
                        mode = CHARACTER;
                    } else {
                        lit += current;
                    }
                    break;
                case SINGLE_LINE_STRING:
                    if(current == '\n') {
                        throw "INVALID STRING LITERAL ("" literals must be single-line)";
                    }
                    if(current == '\"') {
                        if(c[i+1] == 'u') {
                            result->push_back(UnformattedString(lit));
                            i++;
                        } else {
                            result->push_back(FormattedString(lit));
                        }
                        mode = NONE;
                        lit = "";
                    } else {
                        lit += current;
                    }
                    break;
                case MULTI_LINE_STRING:
                    if(current == '`') {
                        if(c[i+1] == 'u') {
                            result->push_back(UnformattedString(lit));
                            i++;
                        } else {
                            result->push_back(FormattedString(lit));
                        }
                        lit = "";
                        mode = NONE;
                    } else {
                        lit += current;
                    }
                    break;
                case CHARACTER:
                    if(current == '\'') {
                        result->push_back(Character(lit));
                        mode = NONE;
                        lit = "";
                    } else {
                        lit += current;
                    }
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