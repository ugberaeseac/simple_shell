#include "shell.h"

/**
 * cd_home - function that changes directory to HOME directory.
 *
 * Return: change directory on success or 1 if failed
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
		cd_setenv("OLDPWD", cwd, 1);
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

	cd_setenv("OLDPWD", cwd, 1);
	cd_setenv("PWD", home, 1);
	free(cwd);
	return (0);
}



/**
 * cd_cwd - function that changes directory to the current working directory.
 *
 * Return: change directory on success or 1 if failed
 */
int cd_cwd(void)
{
	char *cwd;
	char *buf = NULL;
	size_t size = 0;

	cwd = getcwd(buf, size);
	cd_setenv("PWD", cwd, 0);

	free(cwd);
	return (0);
}

/**
 * cd_toggle - function that toggles the previous working directory
 *
 * Return: change directory on success or 1 if failed
 */
int cd_toggle(void)
{
	char *cwd, *oldpwd;
	char *tmpcwd, *tmpoldpwd;
	char *buf = NULL;
	size_t size = 0;

	cwd = getcwd(buf, size);
	if (cwd == NULL)
	{
		free(cwd);
		return (1);
	}
	oldpwd = _strdup(_getenv("OLDPWD"));
	tmpcwd = _strdup(cwd);
	cd_setenv("OLDPWD", tmpcwd, 1);
	tmpoldpwd = _strdup(oldpwd);
	cd_setenv("PWD", tmpoldpwd, 1);

	if (chdir(tmpoldpwd) == -1)
	{
		cd_setenv("PWD", tmpcwd, 1);
		free(tmpoldpwd);
		free(tmpcwd);
		free(oldpwd);
		free(cwd);
		return (1);
	}

	free(tmpoldpwd);
	free(tmpcwd);
	free(oldpwd);
	free(cwd);

	return (0);
}



/**
 * cd_abspath - function that changes directory to the path
 * entered by the user
 * @path: path
 *
 * Return: change directory on success or 1 if failed
 */
int cd_abspath(char *path)
{
	char *cwd;
	char *buf = NULL;
	size_t size = 0;

	cwd = getcwd(buf, size);
	if (cwd == NULL)
	{
		free(cwd);
		return (1);
	}
	cd_setenv("OLDPWD", cwd, 1);
	if (chdir(path) == -1)
	{
		_puts("Cannot change directory to the given path\n");
		free(cwd);
		return (1);
	}
	cd_setenv("PWD", path, 1);

free(cwd);
return (0);
}
