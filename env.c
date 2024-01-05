#include "shell.h"

/*
 * env_print current environment
 * use of built in env
 *
 */

void env_shell(void) {
	int i;

	for (i=0; environ[i] != NULL; i++) {
	       write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
       	       write(STDOUT_FILENO, "\n", 1);
	}
}	
