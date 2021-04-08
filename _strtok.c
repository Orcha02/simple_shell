#include "headers.h"

/**
 * find_lenght - calculate the lenght of command line
 *@s: char pointer
 * Return: Always 0 (Success)
 */

unsigned int find_lenght(char *s)
{
        unsigned int count_tok = 0, i = 0, flag = 0;

        while(s[i] != '\0')
        {

                if (s[i] != ' ')
                        flag = 1;
                if ((flag && s[i + 1] == ' ') || (flag && s[i + 1] == '\0'))
                {
                        ++count_tok;
                        flag = 0;
                }
                ++i;
        }
        return(count_tok);
}
