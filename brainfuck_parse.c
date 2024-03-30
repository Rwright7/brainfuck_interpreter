#include <stdio.h>
#include <stdlib.h>
#include "brainfuck_parse.h"
#include "brainfuck_lexer.h"


void precomputeBrackets(const BrainfuckComm tokens[], int numTokens, int bracketMap[]){
	int stack[MAX_CODE_LENGTH];
	int stackPointer = -1;

	for (int i = 0; i < numTokens; i++){
		if (tokens[i] == LOOP_START){
			stack[++stackPointer]= i;
		}else if (tokens[i] == LOOP_END){
			if (stackPointer < 0){
				fprintf(stderr, "Error: Unmatched closing bracket.\n");
				exit(EXIT_FAILURE);
			}
			int startIndex = stack[stackPointer];
			bracketMap[startIndex] = i;
			bracketMap[i] = startIndex;
		}
	}
	if (stackPointer >= 0){
		fprintf(stderr,"Error: Unmatched opening bracket.\n");
		exit(EXIT_FAILURE);
	}
}


void parseBrainfuck(const BrainfuckComm tokens[], int numTokens)
{
	unsigned char memory[MAX_CODE_LENGTH] = {0};
	unsigned char *ptr = memory;
	int bracketMap[MAX_CODE_LENGTH] = {0};

	precomputeBrackets(tokens, numTokens, bracketMap);


	for (int i = 0; i < numTokens; i++) {
		BrainfuckComm command = tokens[i];

		switch (command) {
			case INC_PTR:
				if (ptr < memory + MAX_CODE_LENGTH - 1){
					ptr++;
				}else{
					fprintf(stderr, "Error: Pointer moved beyond tape boundary.\n");
					exit(EXIT_FAILURE);
				}
				break;
			case DEC_PTR:
				if (ptr > memory){
					ptr--;
				}else{
					fprintf(stderr, "Error: Pointer moved before tape start.\n");
					exit(EXIT_FAILURE);
				}
				break;
			case INC_VAL:
				(*ptr)++;
				break;
			case DEC_VAL:
				(*ptr)--;
				break;
			case OUTPUT:
				putchar(*ptr);
				break;
			case INPUT:
				*ptr = (unsigned char)getchar();
				//*ptr = getchar();
				break;
			case LOOP_START:
				if (*ptr == 0) {
					i = bracketMap[i];
				}
				break;
			case LOOP_END:
				if (*ptr != 0) {
					i = bracketMap[i];
				}
			default:
				fprintf(stderr, "Error: Unknown command encountered.\n");
				exit(EXIT_FAILURE);
				break;
		}
	}
}
