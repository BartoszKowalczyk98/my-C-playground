#include<stdio.h>
int main(int argc, char const *argv[])
{
    int tablica_przejsc[17][7][2] = {
        {{1,0},{3,0},{5,0},{7,0},{10,0},{12,0},{14,0}},
        {{2}  ,{}   ,{}   ,{}   ,{}    ,{}    ,{}},
        {{9}  ,{}   ,{}   ,{}   ,{}    ,{}    ,{}},
        {{}   ,{4}  ,{}   ,{}   ,{}    ,{}    ,{}},
        {{}   ,{9}  ,{}   ,{}   ,{}    ,{}    ,{}},
        {{}   ,{}   ,{6}  ,{}   ,{}    ,{}    ,{}},
        {{}   ,{}   ,{9}  ,{}   ,{}    ,{}    ,{}},
        {{}   ,{}   ,{}   ,{8}  ,{}    ,{}    ,{}},
        {{}   ,{}   ,{}   ,{9}  ,{}    ,{}    ,{}},
        {{9}  ,{9}  ,{9}  ,{9}  ,{9}   ,{9}   ,{9}},
        {{}   ,{}   ,{}   ,{}   ,{11}  ,{}    ,{}},
        {{}   ,{}   ,{}   ,{}   ,{16}  ,{}    ,{}},
        {{}   ,{}   ,{}   ,{}   ,{}    ,{13}  ,{}},
        {{}   ,{}   ,{}   ,{}   ,{}    ,{16}  ,{}},
        {{}   ,{}   ,{}   ,{}   ,{}    ,{}    ,{15}},
        {{}   ,{}   ,{}   ,{}   ,{}    ,{}    ,{16}},
        {{16} ,{16} ,{16} ,{16} ,{16}  ,{16}  ,{16}}
    };
    int aktualny_stan = 0;
    int wrzucona_moneta = 0;
    int tablica_stanow[100][3]= {};

    FILE *f = fopen("testingnfa.txt","r");
    if(f == NULL){
        printf("Blad podczas wczytywania pliku!\n");
        return -1;
    }
    char ch;
    printf("zaczynamy wczytywanie: \n");
    printf("q0 -> ");
    while((ch = fgetc(f)) != EOF){
        if(ch == '0'){
            aktualny_stan = tablica_przejsc[aktualny_stan][0][0];
            printf("0 -> q%d -> ", aktualny_stan);
        }
        else if (ch == '1')
        {
            aktualny_stan = tablica_przejsc[aktualny_stan][1][0];
            printf("1 -> q%d -> ", aktualny_stan);
        }
        else if (ch == '2')
        {
            aktualny_stan = tablica_przejsc[aktualny_stan][2][0];
            printf("2 -> q%d -> ", aktualny_stan);
        }else if (ch == '3')
        {
            aktualny_stan = tablica_przejsc[aktualny_stan][3][0];
            printf("3 -> q%d -> ", aktualny_stan);
        }else if (ch == 'a')
        {
            aktualny_stan = tablica_przejsc[aktualny_stan][4][0];
            printf("a -> q%d -> ", aktualny_stan);
        }else if (ch == 'b')
        {
            aktualny_stan = tablica_przejsc[aktualny_stan][5][0];
            printf("b -> q%d -> ", aktualny_stan);
        }else if (ch == 'c')
        {
            aktualny_stan = tablica_przejsc[aktualny_stan][6][0];
            printf("c -> q%d -> ", aktualny_stan);
        }
        else if (ch=='#')
        {
            printf("stan koncowy dla slowa to %d\n",aktualny_stan);
            aktualny_stan=0;
        }
        

    }
    fclose(f);
    return 0;
}
