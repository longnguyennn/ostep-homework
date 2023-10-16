#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100; // Inititialize variable `x` to 100 in the main process.
    printf("Before calling fork(): x = %d\n", x);
    const int rc = fork();
    if (rc < 0)
    {
        perror("Fork failed");
        return 1;
    }
    else if (rc == 0)
    {
        x = 50; // Set `x` to 50 in the child process.
    }
    else
    {
        x = 200; // Set `x` to 200 in the parent process.
    }
    printf("(pid:%d) x = %d\n", getpid(), x);
    return 0;
}