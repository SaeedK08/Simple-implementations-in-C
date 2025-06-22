#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LINE_SIZE 1024

#define BLACK_FG 30 
#define RED_FG 31 
#define GREEN_FG 32 
#define YELLOW_FG 33 
#define BLUE_FG 34 
#define MAGENTA_FG 35 
#define CYAN_FG 36 
#define WHITE_FG 37 
#define DEFAULT_FG 39 
#define BRIGHT_BLACK_FG 90 
#define BRIGHT_RED_FG 91 
#define BRIGHT_GREEN_FG 92 
#define BRIGHT_YELLOW_FG 93 
#define BRIGHT_BLUE_FG 94 
#define BRIGHT_MAGENTA_FG 95 
#define BRIGHT_CYAN_FG 96 
#define BRIGHT_WHITE_FG 97 
#define BLACK_BG 40 
#define RED_BG 41 
#define GREEN_BG 42 
#define YELLOW_BG 43 
#define BLUE_BG 44 
#define MAGENTA_BG 45 
#define CYAN_BG 46 
#define WHITE_BG 47 
#define DEFAULT_BG 49 
#define BRIGHT_BLACK_BG 100
#define BRIGHT_RED_BG 101 
#define BRIGHT_GREEN_BG 102 
#define BRIGHT_YELLOW_BG 103 
#define BRIGHT_BLUE_BG 104 
#define BRIGHT_MAGENTA_BG 105 
#define BRIGHT_CYAN_BG 106 
#define BRIGHT_WHITE_BG 107

#define BOLD 1  
#define FAINT 2
#define ITALIC 3
#define UNDERLINE 4
#define BLINK 5
#define INVERSE 6

void usage(void)
{
    printf("Usage: dumbat [OPTIONS]\n");
    printf("-b [color]: Apply a color to the background\n");
    printf("-B |color]: Apply a bright color to the background\n");
    printf("-f [color]: Apply a color to the foreground\n");
    printf("-F [color]: Apply a bright color to the foreground\n");
    printf("-h: Show this help message and exit\n");
    printf("-s [style]: Apply a style to the text (default bold)\n");
}

int main (int argc, char **argv)
{
    if (argc <= 1)
    {
        char temp;
        while (1)
        {
            scanf("%c" ,&temp);
            putchar(temp);
        }
    }
    int opt;
    uint8_t style = BOLD;
    uint8_t foreground = DEFAULT_FG;
    uint8_t background = DEFAULT_BG;
    
    while((opt = getopt(argc, argv, "s:f:F:b:B:h")) != -1)
    {
        switch (opt)
        {
            case 's':
                if (!strcasecmp(optarg, "bold"))            style = BOLD;
                else if (!strcasecmp(optarg, "faint"))      style = FAINT;
                else if (!strcasecmp(optarg, "italic"))     style = ITALIC;
                else if (!strcasecmp(optarg, "underline"))  style = UNDERLINE;
                else if (!strcasecmp(optarg, "blink"))      style = BLINK;
                else if (!strcasecmp(optarg, "inverse"))    style = INVERSE;
                else
                    printf("Invalid style selection\nValid styles are bold, faint, italic, underline, blink and inverse.\n");
                break;
            case 'f':
                if (!strcasecmp(optarg, "black"))        foreground = BLACK_FG;
                else if (!strcasecmp(optarg, "red"))     foreground = RED_FG;
                else if (!strcasecmp(optarg, "green"))   foreground = GREEN_FG;
                else if (!strcasecmp(optarg, "yellow"))  foreground = YELLOW_FG;
                else if (!strcasecmp(optarg, "blue"))    foreground = BLUE_FG;
                else if (!strcasecmp(optarg, "magenta")) foreground = MAGENTA_FG;
                else if (!strcasecmp(optarg, "cyan"))    foreground = CYAN_FG;
                else if (!strcasecmp(optarg, "white"))   foreground = WHITE_FG;
                else 
                    printf("Invalid color selection\nValid colors for foreground are black, red, green, yellow, blue, magenta, cyan and white.\n");
                break;
            case 'F':
                if (!strcasecmp(optarg, "black"))        foreground = BRIGHT_BLACK_FG;
                else if (!strcasecmp(optarg, "red"))     foreground = BRIGHT_RED_FG;
                else if (!strcasecmp(optarg, "green"))   foreground = BRIGHT_GREEN_FG;
                else if (!strcasecmp(optarg, "yellow"))  foreground = BRIGHT_YELLOW_FG;
                else if (!strcasecmp(optarg, "blue"))    foreground = BRIGHT_BLUE_FG;
                else if (!strcasecmp(optarg, "magenta")) foreground = BRIGHT_MAGENTA_FG;
                else if (!strcasecmp(optarg, "cyan"))    foreground = BRIGHT_CYAN_FG;
                else if (!strcasecmp(optarg, "white"))   foreground = BRIGHT_WHITE_FG;
                else 
                    printf("Invalid color selection\nValid colors for foreground are black, red, green, yellow, blue, magenta, cyan and white.\n");
                break;
            case 'b':
                if (!strcasecmp(optarg, "black"))        background = BLACK_BG;
                else if (!strcasecmp(optarg, "red"))     background = RED_BG;
                else if (!strcasecmp(optarg, "green"))   background = GREEN_BG;
                else if (!strcasecmp(optarg, "yellow"))  background = YELLOW_BG;
                else if (!strcasecmp(optarg, "blue"))    background = BLUE_BG;
                else if (!strcasecmp(optarg, "magenta")) background = MAGENTA_BG;
                else if (!strcasecmp(optarg, "cyan"))    background = CYAN_BG;
                else if (!strcasecmp(optarg, "white"))   background = WHITE_BG;
                else 
                    printf("Invalid color selection\nValid colors for background are black, red, green, yellow, blue, magenta, cyan and white.\n");
                break;
            case 'B':
                if (!strcasecmp(optarg, "black"))        background = BRIGHT_BLACK_BG;
                else if (!strcasecmp(optarg, "red"))     background = BRIGHT_RED_BG;
                else if (!strcasecmp(optarg, "green"))   background = BRIGHT_GREEN_BG;
                else if (!strcasecmp(optarg, "yellow"))  background = BRIGHT_YELLOW_BG;
                else if (!strcasecmp(optarg, "blue"))    background = BRIGHT_BLUE_BG;
                else if (!strcasecmp(optarg, "magenta")) background = BRIGHT_MAGENTA_BG;
                else if (!strcasecmp(optarg, "cyan"))    background = BRIGHT_CYAN_BG;
                else if (!strcasecmp(optarg, "white"))   background = BRIGHT_WHITE_BG;
                else 
                    printf("Invalid color selection\nValid colors for background are black, red, green, yellow, blue, magenta, cyan and white.\n");
                break;
            case 'h':
            case '?':
                usage();
                exit(0);
            default:
                abort();
        }
    }
    
    if (optind == argc)
    {
        printf("dumbat: No file/path was provided\n");
        return 1;
    }
    const char *filePath = argv[optind];
    FILE *fp = fopen(filePath, "r");
    if (!fp)
    {
        perror("dumbat");              
        return 1;
    }
    char fileContent[LINE_SIZE];
    while (fgets(fileContent, sizeof(fileContent), fp))
    {
        printf("\x1b[%u;%u;%um" ,style ,foreground ,background);
        int value = fputs(fileContent, stdout);
        if (value == EOF)
        {
            abort();
        }
    }
    fclose(fp);

    return 0;   
}