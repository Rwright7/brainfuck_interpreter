#include "brainfuck_lexer.h"

void tokenizeBrainfuck(const char* code, BrainfuckComm tokens[], int* numTokens)
{
	*numTokens = 0;

	while(*code != '\0')
	{
		switch(*code)
		{
			case '>':
				tokens[*numTokens] = INC_PTR;
				break;
			case '<':
				tokens[*numTokens] = DEC_PTR;
				break;
			case '+':
				tokens[*numTokens] = INC_VAL;
				break;
			case '-':
				tokens[*numTokens] = DEC_VAL;
				break;
			case '.':
				tokens[*numTokens] = OUTPUT;
				break;
			case ',':
				tokens[*numTokens] = INPUT;
				break;
			case '[':
				tokens[*numTokens] = LOOP_START;
				break;
			case ']':
				tokens[*numTokens] = LOOP_END;
				break;
			// Ignore other characters
			default:
				tokens[*numTokens] = INVALID_COMMAND;
				break;
		}
		(*numTokens)++;
			code++;
	}
}