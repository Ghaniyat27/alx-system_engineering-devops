#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

/**
 * infinite_while - A Function's That Run's Forever and Return's Nothing
 * Return: 0 In The End
*/
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - The Entry To a Program That Create's 5 Zombie Process
 * Return: 0 on Sucess(s)
*/
int main(void)
{
	int children_processes = 0;
	pid_t pid;

	while (children_processes < 5)
	{
		pid = fork();
		if (!pid)
			break;
		printf("Zombie process created, PID: %i\n", (int)pid);
		children_processes++;
	}
	if (pid != 0)
		infinite_while();
	return (0);
}
