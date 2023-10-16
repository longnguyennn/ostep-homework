#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    // Open a file for writing
    const char *filename = "output.txt";
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    const int rc = fork();
    if (rc < 0)
    {
        perror("Fork failed");
        return 1;
    }
    int i = 0;
    while (i < 3)
    {
        // Write process id to the file
        fprintf(file, "pid: %d\n", getpid());
        // Flush the buffer to ensure data is written immediately to the file
        fflush(file);
        // Sleep for 1 second after write
        sleep(1);
        i++;
    }
    // Close file after finish writing
    fclose(file);
    return 0;
}