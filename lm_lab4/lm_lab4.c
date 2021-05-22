#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>


int main(int argc, char const *argv[])
{
    regex_t regex;
    int reti;
    /* Compile regular expression */
    reti = regcomp(&regex, "^(([0]|[1-9]+)[0-9]*)([/+-/^///*](([0]|[1-9]+)[0-9]*))*([;](([0]|[1-9]+)[0-9]*)([/+-/^///*](([0]|[1-9]+)[0-9]*))*)*$", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }
    printf("Podaj wyrazenie do sprawdzenia: ");
    char wyrazenie[300];
    scanf("%s", &wyrazenie);
    
    /* Execute regular expression */
    reti = regexec(&regex, wyrazenie, 0, NULL, 0);
    if (!reti) {
        printf("%s  ",wyrazenie);
        puts("wyrazenie jest zgodne z gramatyka");
    }
    else if (reti == REG_NOMATCH) {
        printf("%s  ",wyrazenie);
        puts("wyrazenie nie jest zgodne z gramatyka");
    }
    else {
        regerror(reti, &regex, wyrazenie, sizeof(wyrazenie));
        fprintf(stderr, "Regex match failed: %s\n", wyrazenie);
        exit(1);
    }

    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    
}
