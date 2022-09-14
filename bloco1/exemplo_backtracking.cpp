// gerador de palavras de a - z com Max caracteres...

#include <iostream>
#include <cstdio>

#define MAX 4

void palavra(char *p, int cont)
{
    if (cont == MAX)
    {
        printf("%s\n", p);
    }
    else
        for (int c = 'a'; c < 'z'; c++)
        {
            p[cont]= c;
            palavra(p, cont+1);
        }
}

int main(int argc, char const *argv[])
{
    char pal[MAX + 1];

    pal[MAX] = '\0';
    palavra(pal, 0);

    

    return 0;
}
