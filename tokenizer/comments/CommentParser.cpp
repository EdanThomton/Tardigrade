/**
 * Second stage of the tokenization pipeline
 * Locates comments and removes commented tokens and code
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "Comment.cpp"
#include "../token.cpp"
#include "../unparsed.cpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum CommentMode {
    NO_COMMENT,
    SINGLE_LINE,
    MULTI_LINE
};

class CommentParser {

    private:

        static vector<Token>* for_each_unparsed(Token t) {

            vector<Token>* result = new vector<Token>();

            string c = t.get_content();

            string lit = "";
            for(int i = 0; i < c.length(); i++) {
                char current = c[i];
                char next = c[i+1];
                string both = "";
                both += current;
                both += next;

                if(both == "/*") {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(CommentStart());
                    lit = "";
                    i++;
                } else if(both == "*/") {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(CommentEnd());
                    lit = "";
                    i++;
                } else if(both == "//") {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(SingleLineCommentStart());
                    lit = "";
                    i++;
                } else if(current == '\n') {
                    if(lit != "") { result->push_back(Unparsed(lit)); }
                    result->push_back(SingleLineCommentEnd());
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

            CommentMode mode = CommentMode::NO_COMMENT;

            for(int i = 0; i < next.size(); i++) {
                Token t = next[i];
                switch(mode) {
                    case CommentMode::NO_COMMENT:
                        if(t.this_token() == "SingleLineCommentStart") {
                            mode = CommentMode::SINGLE_LINE;
                            next.erase(next.begin() + i);
                            i--;
                        } else if(t.this_token() == "CommentStart") {
                            mode = CommentMode::MULTI_LINE;
                            next.erase(next.begin() + i);
                            i--;
                        } else if(t.this_token() == "SingleLineCommentEnd") {
                            next.erase(next.begin() + i);
                            i--;
                        } else if(t.this_token() == "CommentEnd") {
                            throw "Invalid Closing Comment Tag! (*/)";
                        }
                        break;
                    case CommentMode::SINGLE_LINE:
                        if(t.this_token() == "SingleLineCommentEnd") {
                            mode = CommentMode::NO_COMMENT;
                        }
                        next.erase(next.begin() + i);
                        i--;
                        break;
                    case CommentMode::MULTI_LINE:
                        if(t.this_token() == "CommentEnd") {
                            mode = CommentMode::NO_COMMENT;
                        }
                        next.erase(next.begin() + i);
                        i--;
                        break;
                }

            }
            *token_arr = next;
        }

};