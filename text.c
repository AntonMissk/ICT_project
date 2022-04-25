
#include <iostream>
#include <ctype.h>
void letters(char text[])
{
    int n = strlen(text);
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (isalpha(text[i]) != 0)
            count += 1;
    }
    printf("number of letters is: %d\n", count);

}


void numbers(char text[])
{
    int n = strlen(text);
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (isdigit(text[i]) != 0)
            count += 1;
    }
    printf("number of digits is: %d\n", count);

}


void maxDelkaSlova(char text[])
{
    int n = strlen(text);
    int max = 0;
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (isalpha(text[i]) != 0 and isalpha(text[i]) != ' ')
            count += 1;
        else
            count = 0;
        if (max < count)
            max = count;

    }
    printf("word length is: %d\n", max);
}


int main()
{
    char text[100];
    letters(text);
    numbers(text);
    maxDelkaSlova(text);
    return 0;
}