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

/**
 * cd_toggle - function that toggles the previous working directory
 *
 * Return: void
 */
int cd_toggle(void)
{
	char *cwd, *oldpwd;
	char *tmpcwd, *tmpoldpwd;
	char *buf = NULL;
	size_t size = 0;

	cwd = getcwd(buf, size);
	if (cwd == NULL)
		return (1);

	oldpwd = _strdup(getenv("OLDPWD"));
	tmpcwd = _strdup(cwd);
	cd_setenv("OLDPWD", tmpcwd, 1);
	tmpoldpwd = _strdup(oldpwd);
	cd_setenv("PWD", tmpoldpwd, 1);

	if (chdir(tmpoldpwd) == -1)
	{
		cd_setenv("PWD", tmpcwd, 1);
		return (1);
	}

	free(tmpoldpwd);
	free(tmpcwd);
	free(oldpwd);
	free(cwd);

return (1);
}
