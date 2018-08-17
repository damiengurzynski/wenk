#include <stdio.h>

int     main(int argc, char **argv)
{
    (void)argc;
    FILE    *file;
    int     cc;
    int     l;
    int     w;
    int     c;
    char    words[20][20][20];
    
    l = 0;
    w = 0;
    c = 0;
    file = fopen("hi.txt", "r");
    while (1)
    {
        cc = fgetc(file);
        if (cc != EOF)
        {
            if (cc != '\n')
            {
                if (cc != ' ')
                {
                    words[l][w][c] = cc;
                    c++;
                }
                else
                {
                    words[l][w][c] = '\0';
                    c = 0;
                    w++;
                }
            }
            else
            {
                *words[l][w] = 0;
                c = 0;
                w = 0;
                l++;
            }
        }
        else
            break;
    }
    fclose(file);
    return (0);
}

