#include <iostream>
#include <fstream>
#include <string>

#include "tokenizer.cpp"

int main() {

    Tokenizer tokenizer;

    ifstream file("./tests/test.tg");
    if(!file.is_open()) {
        cerr << "Failed to open file!" << endl;
        return -1;
    }

    string line;
    string program = "";
    while(getline(file, line)) {
        program += line;
    }
    file.close();

    try {
        tokenizer.tokenize(program);
    } catch(const char* c) {
        cerr << c << endl;
        return -1;
    }

    tokenizer.print_tokens();

    return 0;

}