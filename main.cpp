#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFF 256
enum BOOL { FALSE, TRUE };
typedef int BOOL;

BOOL isNumeric(char* arg)
{
    BOOL hasDigit = FALSE;
    char* ptr = arg;

    while(*ptr!='\0' && *ptr!='\n') 
    {
        if(*ptr<'0' || *ptr>'9')
            return FALSE;
        else 
            hasDigit = TRUE;

        ptr++;
    }
    return hasDigit;
}

int main (int argc, char** argv) 
{
    char* linha_completa;
    char buffer[MAX_BUFF];
    int i, j, n;
    
    // ler input do utilizador e testar se é válido
    buffer[0] = '\0';

    while(!isNumeric(buffer) || atoi(buffer)<5 || atoi(buffer)>80)
    {
        printf( "\nIntroduza um numero entre 5 e 80: ");
        fgets(buffer, MAX_BUFF, stdin);
    }
    
    n = atoi(buffer);
    linha_completa = (char*) malloc(n+1);
    memset(linha_completa, '*', n);
    linha_completa[n] = '\0';

    // primeira linha 
    puts(linha_completa);

    // linhas do meio
    for (i=1; i<=n-1; i++)
    {
        for (j=0; j<=n; j++)
        {
            if(j==i || j==n-i-1) putchar('*');
            else putchar(' ');
        }
        putchar('\n');
    }

    // última linha 
    puts(linha_completa);

    return 0;
}
