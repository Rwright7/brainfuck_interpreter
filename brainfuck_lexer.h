#ifndef BRAINFUCK_LEXER_H
#define BRAINFUCK_LEXER_H

#define		MAX_CODE_LENGTH 3000

typedef enum {
	INC_PTR,
	DEC_PTR,
	INC_VAL,
	DEC_VAL,
	OUTPUT,
	INPUT,
	LOOP_START,
	LOOP_END,
	INVALID_COMMAND
} BrainfuckComm;

void tokenizeBrainfuck(const char* code, BrainfuckComm tokens[], int* numTokens);

#endif