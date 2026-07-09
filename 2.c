#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, destination;
    char buffer[100];
    int bytes;

    source = open("source.txt", O_RDONLY);

    if (source < 0)
    {
        printf("Source file not found\n");
        return 1;
    }

    destination = open("destination.txt", O_CREAT | O_WRONLY, 0644);

    while ((bytes = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, bytes);
    }

    close(source);
    close(destination);

    printf("File copied successfully.\n");

    return 0;
}