#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// *** Function Prototypes ***
char *newString(char *str, int size);
void showArray(char **strings, int count);
int getString(char str[], int max);

int main(int argc, char *argv[])
{
    char *strings[SIZE];
    char input[SIZE];
    int count = 0;

   while (count < SIZE && getString(input, SIZE) > 0)
    {  
        strings[count] = newString(input, strlen(input) + 1);

        if (strings[count] == NULL)
        {
            printf("strings of %d is null", count);
            return 1;
        }

        count++;
    }

  
    showArray(strings, count);

   
    for (int i = 0; i < count; i++)
    {
        free(strings[i]);
    }

    return 0;
}

int getString(char str[], int max)
{
    int ch = 0;
    int i = 0;

    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (i < max)
        {
            str[i] = ch;
            i++;
        }
    }

    str[i] = '\0';

    return i;
}

char *newString(char *str, int size)
{
    char *newStr = malloc(size);

    if (newStr == NULL)
    {
        return NULL;
    }

    strcpy(newStr, str);

    return newStr;
}

void showArray(char **strings, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", strings[i]);
    }
}