#include <stdio.h>
#include <stdlib.h>
#include "brainfuck_parse.h"
#include "brainfuck_lexer.h"

void parseBrainfuck(const char* code)
{
	BrainfuckComm tokens[MAX_CODE_LENGTH];
	int numTokens = 0;

	// Tokenize the Brainfuck code
	tokenizeBrainfuck(code, tokens, &numTokens);

	 for (int i = 0; i < numTokens; ++i) {
		switch (tokens[i]) {
			case INC_PTR:
				// Handle increment pointer logic
				break;
			case DEC_PTR:
				
				break;
			case INC_VAL:
				
				break;
			case DEC_VAL:
				
				break;
			case OUTPUT:
				
				break;
			case INPUT:
				
				break;
			case LOOP_START:
				
				break;
			case LOOP_END:
				
				break;
			case INVALID_COMMAND:
			fprintf(stderr, "Error: Unknown command encountered.\n");
			exit(EXIT_FAILURE);
			break;

			default:
				break;
		}
	}
}