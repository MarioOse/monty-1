#include "monty.h"


data_t data = DATA_INIT;

/**
 * main - this opens the monty file and reads lines
 *
 * @argc: the number of arguments
 *
 * @argv: the array of arguments
 *
 * Return: 0 success, 1 failure
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	ssize_t bytes_read;
	size_t len = 0;
	char *line = NULL;
	char *token = NULL;
	int line_number = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	else
	{
		fp = fopen(argv[1], "r");
		
		if (fp == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		
		else
		{
			while ((bytes_read = getline(&line, &len, fp)) != -1)
			{
				line_number++;
				token = get_tokens(line, line_number);
				if (token != NULL)
					get_func(token, &head, line_number);
			}
			
			free(line);
			
			free_stack(head);
			
			fclose(fp);
		}
	}
	return (0);
}
