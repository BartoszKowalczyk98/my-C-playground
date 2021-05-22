#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>


int main(int argc, char const *argv[])
{
    printf("Podaj wyrazenie do sprawdzenia: ");
    char wyrazenie[300];
    regex_t regex;
    int reti;
    scanf("%s", &wyrazenie);
    printf("%s\n",wyrazenie);
    
}
