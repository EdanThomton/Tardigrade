/**
 * Main tokenizer class
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include <vector>

#include "token.h"

class Tokenizer {
    private:
        vector<Token> tokens;
    public:
        void tokenize(string program);
        void print_tokens();
};