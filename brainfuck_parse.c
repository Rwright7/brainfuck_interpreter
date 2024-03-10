#include <stdio.h>
#include <stdlib.h>
#include "brainfuck_parse.h"
#include "brainfuck_lexer.h"

void parseBrainfuck(const BrainfuckComm tokens[], int numTokens)
{

	unsigned char memory[MAX_CODE_LENGTH] = {0};
	unsigned char *ptr = memory;
	int loop_stack[MAX_CODE_LENGTH] = {0};
	int stack_pointer = -1;

	for (int i = 0; i < numTokens; i++) {
		BrainfuckComm command = tokens[i];

		switch (command) {
			case INC_PTR:
				//printf("Before INC_PTR, pointer at: %ld\n", ptr - memory);
				if (ptr < memory + MAX_CODE_LENGTH - 1){
					ptr++;
				}else{
					fprintf(stderr, "Error: Pointer moved beyond tape boundary.\n");
					exit(EXIT_FAILURE);
				}
				break;
			case DEC_PTR:
				//printf("Before DEC_PTR, pointer at: %ld\n", ptr - memory);
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
					int depth = 1;
					while (depth > 0) {
						i++;
						if (tokens[i] == LOOP_START) {
							depth++;
						} else if (tokens[i] == LOOP_END) {
							depth--;
						}
					}
				} else {
					loop_stack[++stack_pointer] = i;
				}
				break;
			case LOOP_END:
				if (*ptr != 0) {
					i = loop_stack[stack_pointer--];
				} else {
					stack_pointer--;
				}
				break;
			default:
				fprintf(stderr, "Error: Unknown command encountered.\n");
				exit(EXIT_FAILURE);
				break;
		}
	}
}
