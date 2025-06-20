#define FILE_SIZE 30720

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
//#include <unistd.h>

int main (int argc, char **argv)
{
    if (argc <= 1)
    {
        char temp;
        while (1)
        {
            scanf("%c" ,&temp);
            printf("%c" ,temp);
        }
    }
    const char *filePath = argv[1];
    FILE *fp = fopen(filePath, "r");
    if (!fp)
    {
        perror("litecat");
        return 1;
    }
    
    char fileContent[FILE_SIZE];
    while (fgets(fileContent, sizeof(fileContent), fp))
    {
        printf("%s" ,fileContent);
    }
    fclose(fp);

    return 0;   
}
/*
*   TODO: Try first misiing around with ncurses to highlight the code and see if it somehow works in some generic way. 
*   For code hightlighting an another library should be used like syntect
*/