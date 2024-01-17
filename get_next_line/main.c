#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *test;

    fd = open("i.txt", O_RDONLY);
    if(fd == -1)
        return (-1);
    test = get_next_line(fd);
    printf("%s", test);
    free(test);

     test = get_next_line(fd);
    printf("%s", test);
    free(test);


}