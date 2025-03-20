/**
 * Class methods for the tokenizer
 * 
 * Passes the program through the four tokenization stages.
 * 
 * @author Edan Thomton
 * @date 3/20/25
 */

#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "token.cpp"
#include "unparsed.cpp"
#include "literals/LiteralParser.cpp"
#include "comments/CommentParser.cpp"
#include "grouping/GroupingParser.cpp"
#include "standalones/StandAloneParser.cpp"
#include "tokens/TokenParser.cpp"

#include "tokenizer.h"

void Tokenizer::tokenize(string program) {
    tokens.push_back(Unparsed(program));
    LiteralParser::pass(&tokens);
    CommentParser::pass(&tokens);
    GroupingParser::pass(&tokens);
    StandAloneParser::pass(&tokens);
    TokenParser::pass(&tokens);
}
void Tokenizer::print_tokens() {
    for(int i = 0; i < tokens.size(); i++) {
        Token t = tokens[i];
        cout << t.to_string() << ",\n";
    }
    cout << endl;
}