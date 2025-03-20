/**
 * Third stage of the tokenization pipeline
 * Handles all grouping symbols ((), [], {}, and <>)
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "CodeBlock.cpp"
#include "ArgumentBlock.cpp"
#include "Accessor.cpp"
#include "Template.cpp"
#include "../token.cpp"
#include "../unparsed.cpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum GroupingMode {
    NO_GROUPING,
    CODEBLOCK,
    ARGUMENTBLOCK,
    ACCESSOR
};
class GroupingParser {

    private:

        static vector<Token>* for_each_unparsed(Token t) {

            vector<Token>* result = new vector<Token>();

            string c = t.get_content();

            string lit = "";

            GroupingMode mode = GroupingMode::NO_GROUPING;
            for(int i = 0; i < c.length(); i++) {
                char current = c[i];

                if(current == '{') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(CodeBlockStart());
                    lit = "";
                } else if(current == '}') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(CodeBlockEnd());
                    lit = "";
                } else if(current == '(') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(ArgumentBlockStart());
                    lit = "";
                } else if(current == ')') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(ArgumentBlockEnd());
                    lit = "";
                } else if(current == ',') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(ArgumentSeparator());
                    lit = "";
                } else if(current == '[') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(AccessorStart());
                    lit = "";
                } else if(current == ']') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(AccessorEnd());
                    lit = "";
                } else if(current == '<') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(TemplateStart());
                    lit = "";
                } else if(current == '>') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(TemplateEnd());
                    lit = "";
                } else {
                    lit += current;
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