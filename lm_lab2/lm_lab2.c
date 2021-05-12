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
    int tablica_stanow[100][100]= {0};
    int ile_aktywnych_stanow = 0;

    // wczytywanie pliku
    printf("Podaj nazwę pliku: ");
    char nazwa_pliku[20];
    scanf("%s",&nazwa_pliku);
    
    FILE *f = fopen("testingnfa.txt","r");
    if(f == NULL){
        printf("Blad podczas wczytywania pliku!\n");
        return -1;
    }
    char ch;


    printf("rozpoczynam wczytywanie z pliku: \n");
    while((ch = fgetc(f)) != EOF){
        ile_aktywnych_stanow++;
        for (int i = 0; i < ile_aktywnych_stanow; i++)
        {
            // if do rozpoznawania znaku na wejsciu i przejściu do odpowiedniego dla niego stanu 
            if(ch == '0'){
                if(tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][0][0]!=0){
                    tablica_stanow[i][ile_aktywnych_stanow] = tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][0][0];
                }
            }
            else if (ch == '1')
            {
                if(tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][1][0]!=0){
                    tablica_stanow[i][ile_aktywnych_stanow] = tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][1][0];
                }
            }
            else if (ch == '2')
            {
               if(tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][2][0]!=0){
                    tablica_stanow[i][ile_aktywnych_stanow] = tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][2][0];
                }
            }
            else if (ch == '3')
            {
                if(tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][3][0]!=0){
                    tablica_stanow[i][ile_aktywnych_stanow] = tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][3][0];
                }
            }
            else if (ch == 'a')
            {
                if(tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][4][0]!=0){
                    tablica_stanow[i][ile_aktywnych_stanow] = tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][4][0];
                }
            }
            else if (ch == 'b')
            {
                if(tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][5][0]!=0){
                    tablica_stanow[i][ile_aktywnych_stanow] = tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][5][0];
                }
            }
            else if (ch == 'c')
            {
                if(tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][6][0]!=0){
                    tablica_stanow[i][ile_aktywnych_stanow] = tablica_przejsc[tablica_stanow[i][ile_aktywnych_stanow]][6][0];
                }
            }
            else if (ch=='#')
            {
                // printowanie tablicy przejsc w ładny sposób

                for (int j = 0; j < ile_aktywnych_stanow; j++)
                {
                    
                    printf("q0");
                    for (int k = 0; k < ile_aktywnych_stanow; k++)
                    {
                        /* code */
                        if(tablica_stanow[j][k]!=0)
                        {
                            printf(" -> q%d",  tablica_stanow[j][k]);
                        }
                        
                    }
                    printf("\n");
                    
                }
                printf("\n");

                ile_aktywnych_stanow=0;
                for (int j = 0; j < 100; j++)
                {
                    for (int k = 0; k < 100; k++)
                    {
                        tablica_stanow[j][k]=0;
                    }
                }
            }
            else
            {
                fclose(f);
                printf("blad czytania znakow z pliku");
                return -1;
            }
        }

        

    }
    fclose(f);
    return 0;
}
