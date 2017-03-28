#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#define MAXBUF 1000

int main()
{
    char buffer[MAXBUF] = {0};
    FILE *fd = popen("ps -a", "r");
    if (NULL == fd)
    {
        printf("Error in popen");
        return 0;;
    }
    fread(buffer, MAXBUF, 1, fd);
    for(int i=0;i<MAXBUF;i++)
    {
      std::cout << "LINE[" << i << "]: " << buffer[i] << std::endl;
    }
    //printf("%s",buffer);
    pclose(fd);
}
