#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

void loadingscreen()
{
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@///////////////////////////////////////////////////////////////////@@@@@@\n");
    printf("@@@@@@@// ///////////////////////////////////////////////////////////// //@@@@@@\n");
    printf("@@@@@@@// ///////////////////////////////////////////////////////////// //@@@@@@\n");
    printf("@@@@@@@// ///////////////////////////////////////////////////////////// //@@@@@@\n");
    printf("@@@@@@@// //////////////////                        /////////////////// //@@@@@@\n");
    printf("@@@@@@@// /////////////////   /////////////////////   ///////////////// //@@@@@@\n");
    printf("@@@@@@@// ////////////////   ///////////////////////  ///////////////// //@@@@@@\n");
    printf("@@@@@@@// ////////////////  ////////////////////////   //////////////// //@@@@@@\n");
    printf("@@@@@@@// ///////////////   /////////////////////////   /////////////// //@@@@@@\n");
    printf("@@@@@@@// ////////////                                     //////////// //@@@@@@\n");
    printf("@@@@@@@// //////////                                        /////////// //@@@@@@\n");
    printf("@@@@@@@// //////////   ////                           ////  /////////// //@@@@@@\n");
    printf("@@@@@@@// //////////                                        /////////// //@@@@@@\n");
    printf("@@@@@@@// //////////                                        /////////// //@@@@@@\n");
    printf("@@@@@@@// ///////////                                       /////////// //@@@@@@\n");
    printf("@@@@@@@// /////////////      ///////////////////////      ///////////// //@@@@@@\n");
    printf("@@@@@@@// /////////////      ///////////////////////      ///////////// //@@@@@@\n");
    printf("@@@@@@@// ///////////////////////////////////////////////////////////// //@@@@@@\n");
    printf("@@@@@@@// ///////////////////////////////////////////////////////////// //@@@@@@\n");
    printf("@@@@@@@// /////      ///   ///      //  ///  /  //  ///  ///     ////// //@@@@@@\n");
    printf("@@@@@@@// /////  ///  /  /  //  ///  /  /  ///  //    /  /   ////////// //@@@@@@\n");
    printf("@@@@@@@// /////     //      //      //      //  //  /    /  ////  ///// //@@@@@@\n");
    printf("@@@@@@@// /////  ////   ///     ///  /  ///  /  //  ///  ///     ////// //@@@@@@\n");
    printf("@@@@@@@// ///////////////////////////////////////////////////////////// //@@@@@@\n");
    printf("@@@@@@@// ///////////////////////////////////////////////////////////// //@@@@@@\n");
    printf("@@@@@@@// ///////////////////////////////////////////////////////////// //@@@@@@\n");
    printf("@@@@@@@///////////////////////////////////////////////////////////////////@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    Sleep(2000);
}

bool loading = false;

struct Parcare {
    char nr[50];
    char culoare[50];
    char zona[50];
    int durata;
    float fee;
};

void adaugare() {

    setvbuf(stdout, NULL, _IOLBF, 0);

    FILE *filePointer;
    filePointer = fopen("fisier.txt", "a");

    printf("===================\n");
    printf("<< Plata parcare>> \n");
    printf("===================\n\n");

    char nr[50], culoare[50], zona[50];
    int durata;
    float fee;

    printf("Introduceti durata parcarii: ");
    scanf("%d", &durata);

    printf("Introduceti numarul de inmatriculare al masinii: ");
    getchar();
    gets(nr);

    printf("Introduceti culoarea zonei (rosie/galbena/verde): ");
        do  {
            scanf(" %s", culoare);
        if (strcmp(culoare, "rosie") == 0)
            {
                fee = durata * 1.5;
                break;
            }
        else if (strcmp(culoare, "galbena") == 0)
            {
                fee = durata * 1.0;
                break;
            }
        else if (strcmp(culoare, "verde") == 0)
            {
                fee = durata * 2.0;
                break;
            }
        else
            printf("Culoarea introdusa nu este valida. Introduceti culoarea din nou (rosie/galbena/verde): ");
            } while (1);


    printf("Introduceti zona: ");
    getchar();
    gets(zona);

    printf("\nPlata realizata cu succes\n\n");

    if (filePointer == NULL) {
        printf("Fisierul nu poate fi accesat.");
    } else {
        fprintf(filePointer, "Masina %s a parcat pe %s, in zona %s, pe o durata de %d ore. Pretul este de %.1f RON\n", nr, zona, culoare, durata, fee);

        fclose(filePointer);
    }
}

void afisare() {

    setvbuf(stdout, NULL, _IOLBF, 0);

    char linie[50];

    printf("=========================\n");
    printf("<< Vizualizare istoric >>\n");
    printf("=========================\n\n");

    FILE * filePointer = fopen("fisier.txt", "r");

    if (filePointer == NULL) {
        printf("Fisierul nu poate fi accesat.");
    }
    else {
        while (fgets(linie, 50, filePointer)) {
            if (linie[0] != '\n') {
                linie[strcspn(linie, "\n")] = '\0';
                printf("%s\n\n", linie);
            }
        }
        fclose(filePointer);
    }

    printf("\n");
}

int main()
{
    setvbuf(stdout, NULL, _IOLBF, 0);
    //printf("\033[0;30m");
    if(loading == false)
    {

        loadingscreen();
        loading = true;
    }
    system("cls");
    while(1)
    {
        system("cls");
        printf("==========================\n");
        printf("<< PLATA PARCARE ONLINE >>\n");
        printf("==========================\n\n");
        printf("1. Vizualizare tarife\n");
        printf("2. Plata parcare\n");
        printf("3. Vizualizare istoric\n\n");
        printf("4. Iesire\n\n\n");

        int choice;
        do {
            printf("Selecteaza optiunea dorita: ");
            scanf("%d",&choice);
        }while(choice < 1 || choice > 4);

        system("cls");
	while(1)
	{
        if(choice == 1)
        {
          printf("========================\n");
          printf("<< Vizualizare tarife >>\n");
          printf("========================\n\n");
          printf("Zona galbena - 1 RON/ora\n");
          printf("Zona rosie - 1.5 RON/ora\n");
          printf("Zona verde - 2 RON/ora\n\n");
          system("pause");
          break;
        }
        else if(choice == 2)
        {
            adaugare();
            system("pause");
            break;
        }
        else if(choice == 3)
        {
            afisare();
            system("pause");
            break;
        }
        else if(choice == 4)
            return 0;
	}
    }
    return 0;
}


