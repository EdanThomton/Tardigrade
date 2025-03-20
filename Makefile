tokenizer_test:
	g++ ./tests/tokenizer_test.cpp -o ./builds/tokenizer_test --std=c++17 -I ./tokenizer/header
	./builds/tokenizer_test