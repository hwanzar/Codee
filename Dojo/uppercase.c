#include <stdio.h>

#include <string.h>
int main()
{
    char nyuuryoku[20];
    char ookiiji[20];
    int i = 0;

    printf("Insert letter: ");
    scanf("%s", nyuuryoku);

    for (i = 0; strlen(nyuuryoku) > i; i++)
    {
        if (nyuuryoku[i] - 'a' >= 0)
        {
            ookiiji[i] = nyuuryoku[i] - 'a' + 'A';
        }
        else
        {
            ookiiji[i] = nyuuryoku[i];
        }
    }

    printf("Large letter: %s", ookiiji);
    int k = strlen(ookiiji);
    printf("%d", k);
    return 0;
}