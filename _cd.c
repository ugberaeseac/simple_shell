#include "shell.h"

/**
 * cd_home - function that changes directory to HOME directory.
 *
 * Return: void
 */
int cd_home(void)
{
	char *home;
	char *cwd;
	char *buf = NULL;
	size_t size = 0;

	cwd = getcwd(buf, size);
	home = _getenv("HOME");
	if (home == NULL)
	{
		cd_setenv("OLDPWD", cwd, 0);
		free(cwd);
		return (1);
	}
	if (chdir(home) == -1)
	{
		_puts("Change to home directory failed");
		_putchar('\n');
		free(cwd);
		return (1);
	}

	cd_setenv("OLDPWD", cwd, 0);
	cd_setenv("PWD", home, 0);
	free(cwd);
	return (1);
}



/**
 * cd_cwd - function that changes directory to the current working directory.
 *
 * Return: void
 */
int cd_cwd(void)
{
	char *cwd;
	char *buf = NULL;
	size_t size = 0;

	cwd = getcwd(buf, size);

	cd_setenv("PWD", cwd, 0);
	free(cwd);

	return (1);
}
