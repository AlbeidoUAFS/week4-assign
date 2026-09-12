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
    char **strings;
    char input[SIZE];
    int count = 0;
   
    strings = malloc((SIZE + 1) * sizeof(char *));

    if (strings == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    while (count < SIZE && getString(input, SIZE) > 0)
    {        
        strings[count] = newString(input, strlen(input) + 1);

        if (strings[count] == NULL)
        {
            printf("sting of %d is null.", count);           
            for (int i = 0; i < count; i++)
            {
                free(strings[i]);
            }

            free(strings);
            return 1;
        }

        count++;
    }
   
    strings[count] = NULL;
   
    showArray(strings, count);
  
    for (int i = 0; i < count; i++)
    {
        free(strings[i]);
    }
    
    free(strings);

    return 0;
}

char *newString(char *str, int size)
{
    char *newStr;

    newStr = malloc(size);

    if (newStr == NULL)
    {
        return NULL;
    }

    strcpy(newStr, str);

    return newStr;
}

void showArray(char **strings,  int count)
{
    char **current = strings;

    while (*current != NULL)
    {
        printf("%s\n", *current);
        current++;
    }
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