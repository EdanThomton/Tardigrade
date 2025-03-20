/**
 * Final stage of the tokenization pipeline
 * 
 * @author Edan Thomton
 * @date 3/20/25
 */

#pragma once
#include "../token.cpp"
#include "../unparsed.cpp"
#include <vector>
#include <iostream>

using namespace std;

class TokenParser {

    private:
        static vector<Token>* for_each_unparsed(Token t) {

            vector<Token>* result = new vector<Token>();

            string c = t.get_content();

            string lit = "";
            for(int i = 0; i < c.length(); i++) {
                char current = c[i];

                if(current == ' ' || current == '\t') {
                    if(lit != "") { result->push_back(Token(lit)); }
                    lit = "";
                } else {
                    lit += current;
                }
            }
            if(lit != "") { result->push_back(Token(lit)); }

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