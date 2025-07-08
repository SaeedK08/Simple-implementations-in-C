#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    int opt;
    int index;
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    while ((opt = getopt(argc, argv, "abc:")) != -1)
    {
        switch (opt)
        {
            case 'a':
                aflag = 1; 
                break;
            case 'b': 
                bflag = 1;
                break;
            case 'c': 
                cvalue = optarg;
                break;
            case '?':
                if (optopt == 'c')
                {
                    fprintf(stderr, "Option '-%c' requires an argument.\n", optopt);
                }
                else if (isprint(optopt)) 
                {
                    fprintf(stderr, "Unknown option '-%c." ,optopt);
                }
                else
                {
                    fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
                }
                return 1;
            default: 
                // Should never reach here
                abort();

        }
    }
    printf("aflag = %d, bfalg = %d, cvalue = %s\n" ,aflag, bflag, cvalue);
    for (index = optind; index < argc; index++)
    {
        printf("Non-option argument %s\n" ,argv[index]);
    }
    return 0;
}


