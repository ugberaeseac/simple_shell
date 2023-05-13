# getpid
system call >>
	A process is an instance of an executing program, that has a unique process ID
this process ID is used by system calls and many function to manipulate and interact with
processes ( Different PID mean Different Process )

> prototype : pid_t getpid(void);

# getppid
each child process has a parent process that we can as well get the ID of that using
getppid if you run your program several times within the same shell you will get the same ID
why this ?

> prototype : pid_t getppid(void);

# getline
is defined in <stdio.h> The getline() function takes three arguments and returs  the number of characters we entered.

- The size_t type prompt variable is used to hold the return value.
- The string input is saved in the memory location pointed to by the pointer buffer declared earlier in the code.
- stdin is used by the getline() method for standard input.

> prototype : size_t getline (char **string, size_t *n, FILE *stream);

# strtok
is defined in <string.h> The strtok function takes two parameters the string to be splited and the delemiter that separate
words returns each time a token then we will call it for the first time it will hold the first token and the second call we have
to update the first argument of strtok so that the strtok function continue where left in mean second token and so on

> prototype : char *strtok(char *string,char *delem);

# execve
is defined in <unistd.h> it does execute a binary file or a script function returns nothing on success and -1 if Failed

> prototype : int execve(const char *pathname, char *const argv[], char *const envp[]);

# fork()
include<unistd.h> and include<sys/types.h>
create a child process
Return Value :  On  success,  the  PID of the child process is returned in the parent, and 0 is returned in the child.
Once fork successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.
On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately.
