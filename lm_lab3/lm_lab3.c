#include<stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    char tablica_przejsc[4][3][10] = {
        {{"-,1,L"},{"-,1,L"},{"-,-,-"}},
        {{"-,4,-"},{"-,4,-"},{"1,3,-"}},
        {{"-,-,-"},{"-,-,-"},{"1,3,-"}},
        {{"-,-,-"},{"-,-,-"},{"-,-,-"}}
    };
    printf("podaj liczbe binarna jednocyfrowa do zwiekszenia o 2: ");
    char liczba[5];
    scanf("%s", &liczba);
    if(strlen(liczba)>2){
        printf("blad wprowadzonej liczby binarnej liczba nie jest jednocyfrowa!\n");
        return -1;
    }
    //skoro zaczynamy analizę od prawej strony to ustawiam index na ostatni znak
    int indeks_na_ktory_wskazuje_glowica = strlen(liczba)-1;
    // rozpoczynamy dzialanie od stanu  q0
    int aktualny_stan=0;
    do
    {
        printf("indeks glowicy %d ||| aktualny stan  %d ||| caly string %s ||| aktualnie analizowana litera %c |||\n",indeks_na_ktory_wskazuje_glowica,aktualny_stan,liczba,liczba[indeks_na_ktory_wskazuje_glowica]);
        // funkcja przejścia
        if(liczba[indeks_na_ktory_wskazuje_glowica]=='0'){
            if(tablica_przejsc[aktualny_stan][0][0]!='-'){
                liczba[indeks_na_ktory_wskazuje_glowica]=tablica_przejsc[aktualny_stan][0][0];
            }
            if(tablica_przejsc[aktualny_stan][0][4]!='-'){
                indeks_na_ktory_wskazuje_glowica--;
            }
            if(tablica_przejsc[aktualny_stan][0][2]!='-'){
                aktualny_stan = (int)tablica_przejsc[aktualny_stan][0][2]-48;
            }
        }
        else if (liczba[indeks_na_ktory_wskazuje_glowica]=='1')
        {
            if(tablica_przejsc[aktualny_stan][1][0]!='-'){
                liczba[indeks_na_ktory_wskazuje_glowica]=tablica_przejsc[aktualny_stan][1][0];
            }
            if(tablica_przejsc[aktualny_stan][1][4]!='-'){
                indeks_na_ktory_wskazuje_glowica--;
            }
            if(tablica_przejsc[aktualny_stan][1][2]!='-'){
                aktualny_stan = (int)tablica_przejsc[aktualny_stan][1][2]-48;
            }
        }
        else if(liczba[indeks_na_ktory_wskazuje_glowica]=='t')
        {
            if(tablica_przejsc[aktualny_stan][2][0]!='-'){
                liczba[indeks_na_ktory_wskazuje_glowica]=tablica_przejsc[aktualny_stan][2][0];
            }
            if(tablica_przejsc[aktualny_stan][2][4]!='-'){
                indeks_na_ktory_wskazuje_glowica--;
            }
            if(tablica_przejsc[aktualny_stan][2][2]!='-'){
                aktualny_stan = (int)tablica_przejsc[aktualny_stan][2][2]-48;
            }
        }
        else
        {
            if (indeks_na_ktory_wskazuje_glowica == -1)
            {
                printf("blad wprowadzonej liczby");
                return -1;
            }
            if(aktualny_stan==4)
            {
                printf("automat zakończył działanie w stanie błędu ");
                return -1;
            }
            
        }
        
    }while(aktualny_stan !=3 );
    printf("%s\n",liczba);

}
