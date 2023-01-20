/// Chiriac Raluca-Roxana
/// Grupa 164

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {neimprumutat, imprumutat} status_enum;
typedef struct
{
    unsigned int numar_pagini: 15;
    char autor[100];
    char editura[100];
    char titlu[100];
    int cod;
    char gen[101];
    status_enum stat;
} carte;

typedef struct
{
    char nume[101];
    int cod;
    unsigned int nr_pagini: 15;
    char editura[101];
    status_enum stat;
} revista;

typedef struct
{
    carte* carti;
    revista* reviste;
    char bibliotecar[100];
    char locatie[1000];
    int id;
    char nume[101];

} biblioteca;

int n_carti, n_reviste, ok_reviste, ok_carti;

carte cautare_carte(char nume[100], biblioteca a)
{
    for (int i=0;i<n_carti;i++)
    {
        if (strcmp(a.carti[i].titlu, nume) == 0)
            return a.carti[i];
    }

}

int cautare_carte_verificare (char nume[100], biblioteca a)
{
    for (int i=0;i<n_carti;i++)
    {
        if (strcmp(a.carti[i].titlu,nume) == 0 )
            return 1;
    }
    return 0;
}

revista cautare_revista(char nume[101], biblioteca a)
{
    for (int i=0;i<n_reviste;i++)
    {
        if (strcmp(a.reviste[i].nume, nume) == 0)
            return a.reviste[i];
    }
}

int cautare_revista_verificare (char nume[101], biblioteca a)
{
    for (int i=0;i<n_reviste;i++)
    {
        if (strcmp(a.reviste[i].nume,nume) == 0 )
            return 1;
    }
    return 0;
}


void afisare(biblioteca a)
{
    printf(" \n ||| Afisare ||| \n ");
    printf("\n");
    printf("ID-ul bibliotecii este: %d \n", a.id );
    printf("Numele bibliotecii este: %s \n", a.nume );
    printf("Numele bibliotecarului este: %s \n", a.bibliotecar );
    printf("Locatia bibliotecii este: %s \n", a.locatie );
    printf("Numele bibliotecii este: %s \n", a.nume );
    printf("Ea contine %d carti  si %d reviste \n", n_carti, n_reviste);

    if (n_carti!=0)
    {
        for (int i=0; i<n_carti; i++)
        {
            printf("\n");
            printf("Cartea #%d  \n \n", i );
            printf("Titlul cartii este: %s \n", a.carti[i].titlu );
            printf("Autorul cartii este: %s \n", a.carti[i].autor );
            printf("Editura cartii este: %s \n", a.carti[i].editura );
            printf("Autorul cartii este: %s \n", a.carti[i].autor );
            printf("Genul cartii este: %s \n", a.carti[i].gen);
            printf("Statusul cartii este: %s \n", (a.carti[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
        }
    }

    if (n_reviste!=0)
    {
        printf("\n\n");
        for (int i=0; i<n_reviste; i++)
        {
            printf("\n");
            printf("Revista #%d  \n \n", i );

            printf("Codul revistei este: %d \n", a.reviste[i].cod );
            printf("Titlul revistei este: %s \n", a.reviste[i].nume );
            printf("Editura revistei este: %s \n", a.reviste[i].editura );
            printf("Numarul de pagini al revistei este: %d \n", a.reviste[i].nr_pagini );
            printf("Statusul revistei este: %s \n", (a.reviste[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
        }
    }
}
void fflushstdin ()
{
    int c;
    while ((c = fgetc (stdin)) != EOF && c != '\n');
}

int main()
{
    FILE *f = fopen("intrare.txt","r");
    biblioteca a;
    char temp;
    char nume1[101];
    /// printf("Introduceti numele bibliotecii! \n");
    fscanf(f, "%[^\n]", nume1);
    strcpy(a.nume,nume1);

    /// printf("Introduceti numele Bibliotecarului! \n");
    char nume2[101];
    fscanf(f,"%c",&temp);
    fscanf(f, "%[^\n]", nume2);
    strcpy(a.bibliotecar,nume2);

    /// printf("Introduceti locatia bibliotecii \n");
    char nume3[101];
    fscanf(f,"%c",&temp);   /// ca sa pot citi cu spatii
    fscanf(f,"%[^\n]", nume3);
    strcpy(a.locatie,nume3);

    /// printf("Introduceti id-ul bibliotecii \n");
    int aux;
    fscanf(f,"%d", &aux);
    a.id= aux;

    /// printf("Ce date introduceti prima data? \n Tastati '1' pentru carti sau tastati '2' pentru reviste \n");
    int var;
    fscanf(f,"%d", &var);
    switch(var)
    {


    case 1 :
    {
        carti:
        {
        /// printf("Cate carti doriti sa cititi? \n");
        int n12= 0;
        ok_carti = 1;
        fscanf(f,"%d", &n12);
        a.carti = (carte*)malloc(n12*sizeof(carte));
        n_carti = n12;
        /// printf("Aveti de citit %d carti! \n", n12);
        for (int i=0; i<n12; i++)
        {
            ///printf("Cartea #%d \n \n", i);

            char aux1[101];
            /// printf("Introduceti titlul cartii! \n");
            fscanf(f,"%c",&temp);
            fscanf(f,"%[^\n]", aux1);
            strcpy(a.carti[i].titlu,aux1);
            char aux2[101];
            /// printf("Introduceti autorul cartii! \n");
            fscanf(f,"%c",&temp);
            fscanf(f,"%[^\n]",aux2);
            strcpy(a.carti[i].autor,aux2);
            char aux3[101];
            /// printf("Introduceti editura cartii! \n");
            fscanf(f,"%c",&temp);
            fscanf(f,"%[^\n]",aux3);
            strcpy(a.carti[i].editura,aux3);
            char aux4[101];
            /// printf("Introduceti genul cartii! \n");
            fscanf(f,"%c",&temp);
            fscanf(f,"%99s",aux4);
            strcpy(a.carti[i].gen,aux4);
            int aux5;
            /// printf("Introduceti numarul de pagini! \n");
            fscanf(f,"%d",&aux5);
            a.carti[i].numar_pagini=aux5;
            int aux6;
            ///  printf("Introduceti codul de identificare a cartii! \n");
            fscanf(f,"%d",&aux6);
            a.carti[i].cod=aux6;
            int rasplocal;
            /// printf("Care este statusul cartii? Inchiriata(1) sau Neinchiriata(2)? Scrieti cifra corespunzatoare! \n");
            fscanf(f,"%d", &rasplocal);
            if (rasplocal== 2)
                a.carti[i].stat=neimprumutat;
            else
                a.carti[i].stat=imprumutat;
           ///  printf("%s", "Doriti sa introduceti in baza de date si reviste? ( 1 pentru Da , 2 pentru Nu ) \n");
           ///  printf("%s", "Daca ati introdus deja, nu mai puteti introduce!  \n");
            int aux7;
            fscanf(f, "%d", &aux7);
            if (aux7==1 && ok_reviste == 0)
                goto reviste;
            else
                if (ok_reviste == 1 && aux7 == 1)
                    printf(" \n Ati citit deja revistele! \n");
        }
        break;
    }
   }
   case 2:
    {
reviste:
    {
       ///  printf("Cate reviste doriti sa cititi? \n");
        ok_reviste=1;
        int n12= 0;
        fscanf(f,"%d", &n12);
        a.reviste = (revista*)malloc(n12*sizeof(revista));
        n_reviste = n12;
        /// printf("Aveti de citit %d reviste! \n", n12);
        for (int i=0; i<n12; i++)
        {
            ///printf("Revista #%d \n \n", i);
            char aux11[101];
            ///  printf("Introduceti titlul revistei! \n");
            fscanf(f,"%c",&temp);
            fscanf(f,"%[^\n]",aux11);
            strcpy(a.reviste[i].nume,aux11);
            char aux31[101];
            /// printf("Introduceti editura revistei! \n");
            fscanf(f,"%c",&temp);
            fscanf(f,"%[^\n]",aux31);
            strcpy(a.reviste[i].editura,aux31);
            int aux5;
            /// printf("Introduceti numarul de pagini! \n");
            fscanf(f,"%d",&aux5);
            a.reviste[i].nr_pagini=aux5;
            int aux6;
            /// printf("Introduceti codul de identificare al revistei! \n");
            fscanf(f,"%d",&aux6);
            a.reviste[i].cod=aux6;

            int rasplocal;
            /// printf("Care este statusul revistei? Inchiriata(1) sau Neinchiriata(2)? Scrieti cifra corespunzatoare! \n");
            fscanf(f,"%d", &rasplocal);
            if (rasplocal== 2)
                a.reviste[i].stat=neimprumutat;
            else
                a.reviste[i].stat=imprumutat;

           ///  printf("%s", "Doriti sa introduceti in baza de date si carti? ( 1 pentru Da , 2 pentru Nu ) \n");
           ///  printf("%s", "Daca ati introdus deja, nu mai puteti introduce!  \n");

            int aux9;
            fscanf(f, "%d", &aux9);
            if (aux9==1 && ok_carti == 0)
                goto carti;
            else
                if (ok_carti == 1 && aux9 == 1)
                    printf(" \n Ati citit deja cartile! \n");

        }
        break;
    }
 }
    default:
    {
        printf("Optiue invalida! \n");
        return 0;
    }
    }
meniu:
    {
   printf("------------------ Meniu ---------------------- \n");
   printf("\n");
   printf("1. Afisati toata biblioteca impreuna cu toate detaliile despre carti si reviste \n");
   printf("2. Afisati cartile neimprumutate / imprumutate \n");
   printf("3. Afisati revistele neimprumutate / imprumutate \n");
   printf("4. Afisati articolele imprumutate / neimprumutate \n");
   printf("5. Afisati detaliile despre o carte \n");
   printf("6. Afisati detaliile despre o revista \n");
   printf("7. Eliminati carti din biblioteca \n");
   printf("8. Eliminati reviste din biblioteca \n");
   printf("9. Adaugati un numar dat de carti in biblioteca \n");
   printf("10. Adaugati un numar dat de reviste in biblioteca \n");
   printf("\n \n");
   printf("11. Iesiti din program \n");
   printf("\n \n");
   printf("Introduceti numarul optinuii pe care doriti sa o executati, DOAR NUMARUL, dupa care apasati tasta ENTER! \n");
   int raspuns;
   scanf("%d", &raspuns);
#ifdef _WIN32
    system("cls");
#endif // _WIN32
#ifdef linux
    system("clear");
#endif // linux
#ifdef __APPLE__
    system("clear");
#endif // apple
   switch(raspuns)
{
   case 1:
       {
           afisare(a);
           printf("\n \n");
            printf("                   ------ Afisarea s-a sfarsit ------   \n");
            printf("        ------ Apasati tasta ENTER pentru a afisa meniul -------       \n");
            char ch;
           ch=getchar();   /// verifica daca s-a apasat tasta enter
           fflushstdin();
           if(ch=='\n')
            {
                #ifdef _WIN32
                    system("cls");
                #endif // _WIN32         /// comenzile pentru golirea de ecran portabile
                #ifdef linux
                    system("clear");
                #endif // linux
                #ifdef __APPLE__
                    system("clear");
                #endif // apple
            }
           goto meniu;
       }
   case 2:
        {
            printf("Pentru cartile NEimprumutate apasati tasta 1, pentru cele imprumutate apasati tasta 2 \n");
            int raspuns_local;
            scanf("%d", &raspuns_local);
            if (raspuns_local == 1)
            {
                int nr=0;
                 if (n_carti!=0)
                    {

                        for (int i=0; i<n_carti; i++)
                            if (a.carti[i].stat==neimprumutat)
                            {
                                printf("\n");
                                printf("Id-ul cartii este: %d \n", a.carti[i].cod);
                                printf("Titlul cartii este: %s \n", a.carti[i].titlu );
                                printf("Autorul cartii este: %s \n", a.carti[i].autor );
                                printf("Editura cartii este: %s \n", a.carti[i].editura );
                                printf("Autorul cartii este: %s \n", a.carti[i].autor );
                                printf("Genul cartii este: %s \n", a.carti[i].gen);
                                nr++;
                                printf("Statusul cartii este: %s \n", (a.carti[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
                            }
                    }
                else
                    printf("Nu exista carti in baza de date! \n");
                if (nr==0)
                    printf("Nu exista carti neimprumutate in baza de date! \n");
            }
            else
                if (raspuns_local == 2)
                    {
                        int nr=0;
                         if (n_carti!=0)
                            {
                                for (int i=0; i<n_carti; i++)
                                    if (a.carti[i].stat==imprumutat)
                                    {
                                        printf("\n");
                                        printf("Id-ul cartii este: %d \n", a.carti[i].cod);
                                        printf("Titlul cartii este: %s \n", a.carti[i].titlu );
                                        printf("Autorul cartii este: %s \n", a.carti[i].autor );
                                        printf("Editura cartii este: %s \n", a.carti[i].editura );
                                        printf("Autorul cartii este: %s \n", a.carti[i].autor );
                                        printf("Genul cartii este: %s \n", a.carti[i].gen);
                                        nr++;
                                        printf("Statusul cartii este: %s \n", (a.carti[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
                                    }
                            }
                        else
                            printf("Nu exista carti in baza de date! \n");
                        if (nr==0)
                            printf("Nu exista carti imprumutate in baza de date! \n");
                    }
                    else
                        printf("Optiune invalida!");

            printf("\n \n");
            printf("                   ------ Afisarea s-a sfarsit ------   \n");
            printf("        ------ Apasati tasta ENTER pentru a afisa meniul -------       \n");
            char ch;
           ch=getchar();
           fflushstdin();
           if(ch=='\n')
            {
                #ifdef _WIN32
                    system("cls");
                #endif // _WIN32
                #ifdef linux
                    system("clear");
                #endif // linux
                #ifdef __APPLE__
                    system("clear");
                #endif // apple
            }
           goto meniu;

        }

   case 3:
    {
        printf("Pentru revistele NEimprumutate apasati tasta 1, pentru cele imprumutate apasati tasta 2 \n");
            int raspuns_local;
            scanf("%d", &raspuns_local);
            if (raspuns_local == 1)
            {
                int nr=0;
                 if (n_reviste!=0)
                    {

                        for (int i=0; i<n_reviste; i++)
                            if (a.reviste[i].stat==neimprumutat)
                            {
                                printf("\n");

                                nr++;
                                printf("Codul revistei este: %d \n", a.reviste[i].cod );
                                printf("Titlul revistei este: %s \n", a.reviste[i].nume );
                                printf("Editura revistei este: %s \n", a.reviste[i].editura );
                                printf("Numarul de pagini al revistei este: %d \n", a.reviste[i].nr_pagini );
                                printf("Statusul revistei este: %s \n", (a.reviste[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
                            }
                    }
                else
                    printf("Nu exista reviste in baza de date! \n");
                if (nr==0)
                    printf("Nu exista reviste neimprumutate in baza de date! \n");
            }
            else
                if (raspuns_local == 2)
                    {
                        int nr=0;
                         if (n_reviste!=0)
                            {

                                for (int i=0; i<n_reviste; i++)
                                    if (a.reviste[i].stat==imprumutat)
                                    {
                                        printf("\n");

                                        nr++;
                                        printf("Codul revistei este: %d \n", a.reviste[i].cod );
                                        printf("Titlul revistei este: %s \n", a.reviste[i].nume );
                                        printf("Editura revistei este: %s \n", a.reviste[i].editura );
                                        printf("Numarul de pagini al revistei este: %d \n", a.reviste[i].nr_pagini );
                                        printf("Statusul revistei este: %s \n", (a.reviste[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
                                    }
                            }
                        else
                            printf("Nu exista reviste in baza de date! \n");
                        if (nr==0)
                            printf("Nu exista reviste imprumutate in baza de date! \n");

                    }

                    else
                    {
                        printf("Optiune invalida!");

                    }
            printf("\n \n");
            printf("                   ------ Afisarea s-a sfarsit ------   \n");
            printf("        ------ Apasati tasta ENTER pentru a afisa meniul -------       \n");
            char ch;
           ch=getchar();
           fflushstdin();
           if(ch=='\n')
            {
                #ifdef _WIN32
                    system("cls");
                #endif // _WIN32
                #ifdef linux
                    system("clear");
                #endif // linux
                #ifdef __APPLE__
                    system("clear");
                #endif // apple
            }
           goto meniu;

        }
   case 4:
    {
        printf("Pentru articolele NEimprumutate apasati tasta 1, pentru cele imprumutate apasati tasta 2 \n");
        int raspuns_local;
        scanf("%d", &raspuns_local);
        if (raspuns_local == 1)
        {
                 int nr=0;
                 int nr1=0;
                 if (n_reviste!=0)
                    {
                        printf("\n");
                        printf("Reviste neimprumutate: \n");
                        for (int i=0; i<n_reviste; i++)
                            if (a.reviste[i].stat==neimprumutat)
                            {
                                printf("\n");

                                nr++;
                                printf("Codul revistei este: %d \n", a.reviste[i].cod );
                                printf("Titlul revistei este: %s \n", a.reviste[i].nume );
                                printf("Editura revistei este: %s \n", a.reviste[i].editura );
                                printf("Numarul de pagini al revistei este: %d \n", a.reviste[i].nr_pagini );
                                printf("Statusul revistei este: %s \n", (a.reviste[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
                            }
                    }
                else
                    printf("Nu exista reviste in baza de date! \n");
                if (nr==0)
                    printf("Nu exista reviste neimprumutate in baza de date! \n");
                 if (n_carti!=0)
                    {
                        printf("\n");
                        printf("Carti neimprumutate: \n");
                        for (int i=0; i<n_carti; i++)
                            if (a.carti[i].stat==neimprumutat)
                            {
                                printf("\n");
                                printf("Id-ul cartii este: %d \n", a.carti[i].cod);
                                printf("Titlul cartii este: %s \n", a.carti[i].titlu );
                                printf("Autorul cartii este: %s \n", a.carti[i].autor );
                                printf("Editura cartii este: %s \n", a.carti[i].editura );
                                printf("Autorul cartii este: %s \n", a.carti[i].autor );
                                printf("Genul cartii este: %s \n", a.carti[i].gen);
                                nr1++;
                                printf("Statusul cartii este: %s \n", (a.carti[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
                            }
                    }
                else
                    printf("Nu exista carti in baza de date! \n");
                if (nr1==0)
                    printf("Nu exista carti neimprumutate in baza de date! \n");
        }

            if (raspuns_local == 2)
            {
                        int nr=0;
                        int nr1=0;
                         if (n_reviste!=0)
                            {
                                printf("\n");
                                printf("Reviste imprumutate: \n");
                                for (int i=0; i<n_reviste; i++)
                                    if (a.reviste[i].stat==imprumutat)
                                    {
                                        printf("\n");

                                        nr++;
                                        printf("Codul revistei este: %d \n", a.reviste[i].cod );
                                        printf("Titlul revistei este: %s \n", a.reviste[i].nume );
                                        printf("Editura revistei este: %s \n", a.reviste[i].editura );
                                        printf("Numarul de pagini al revistei este: %d \n", a.reviste[i].nr_pagini );
                                        printf("Statusul revistei este: %s \n", (a.reviste[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
                                    }
                            }
                        else
                            printf("Nu exista reviste in baza de date! \n");
                        if (nr==0)
                            printf("Nu exista reviste imprumutate in baza de date! \n");

                         if (n_carti!=0)
                            {
                                printf("\n");
                                printf("Carti imprumutate: \n");
                                for (int i=0; i<n_carti; i++)
                                    if (a.carti[i].stat==imprumutat)
                                    {
                                        printf("\n");
                                        printf("Id-ul cartii este: %d \n", a.carti[i].cod);
                                        printf("Titlul cartii este: %s \n", a.carti[i].titlu );
                                        printf("Autorul cartii este: %s \n", a.carti[i].autor );
                                        printf("Editura cartii este: %s \n", a.carti[i].editura );
                                        printf("Autorul cartii este: %s \n", a.carti[i].autor );
                                        printf("Genul cartii este: %s \n", a.carti[i].gen);
                                        nr1++;
                                        printf("Statusul cartii este: %s \n", (a.carti[i].stat==neimprumutat)?"neimprumutata":"imprumutata" );
                                    }
                            }
                        else
                            printf("Nu exista carti in baza de date! \n");
                        if (nr1==0)
                            printf("Nu exista carti imprumutate in baza de date! \n");

                    }
            printf("\n \n");

            printf("                   ------ Afisarea s-a sfarsit ------   \n");
            printf("        ------ Apasati tasta ENTER pentru a afisa meniul -------       \n");
            char ch;
           ch=getchar();
           fflushstdin();
           if(ch=='\n')
            {
                #ifdef _WIN32
                    system("cls");
                #endif // _WIN32
                #ifdef linux
                    system("clear");
                #endif // linux
                #ifdef __APPLE__
                    system("clear");
                #endif // apple
            }
           goto meniu;
            }
   case 5:
    {
        printf("Introduceti titlul cartii despre care doriti sa aflati informatii! \n");
        char nume_temp1[100];
        char temp;

        scanf("%c",&temp);
        scanf("%[^\n]",nume_temp1);
        printf("\n");

        if (cautare_carte_verificare(nume_temp1,a) == 1)
        {
            printf("Id-ul cartii este: %d \n", cautare_carte(nume_temp1,a).cod);
            printf("Titlul cartii este: %s \n", cautare_carte(nume_temp1,a).titlu );
            printf("Autorul cartii este: %s \n", cautare_carte(nume_temp1,a).autor );
            printf("Editura cartii este: %s \n", cautare_carte(nume_temp1,a).editura );
            printf("Autorul cartii este: %s \n", cautare_carte(nume_temp1,a).autor );
            printf("Genul cartii este: %s \n", cautare_carte(nume_temp1,a).gen);
            printf("Statusul cartii este: %s \n", (cautare_carte(nume_temp1,a).stat==neimprumutat)?"neimprumutata":"imprumutata" );
        }
        else
            printf("Nu s-a gasit cartea cu titlul introdus!");

        printf("\n \n");
        printf("                   ------ Afisarea s-a sfarsit ------   \n");
        printf("        ------ Apasati tasta ENTER pentru a afisa meniul -------       \n");
        char ch;
       ch=getchar();
       fflushstdin();
       if(ch=='\n')
        {
            #ifdef _WIN32
                system("cls");
            #endif // _WIN32
            #ifdef linux
                system("clear");
            #endif // linux
            #ifdef __APPLE__
                system("clear");
            #endif // apple
        }
       goto meniu;
    }
   case 6:
    {

        printf("Introduceti numele revistei despre care doriti sa aflati informatii! \n");
        char nume_temp1[100];
        char temp;

        scanf("%c",&temp);
        scanf("%[^\n]",nume_temp1);
        printf("\n");

        if (cautare_revista_verificare(nume_temp1,a) == 1)
        {
            printf("Codul revistei este: %d \n", cautare_revista(nume_temp1,a).cod );
            printf("Titlul revistei este: %s \n", cautare_revista(nume_temp1,a).nume );
            printf("Editura revistei este: %s \n", cautare_revista(nume_temp1,a).editura );
            printf("Numarul de pagini al revistei este: %d \n", cautare_revista(nume_temp1,a).nr_pagini );
            printf("Statusul revistei este: %s \n", (cautare_revista(nume_temp1,a).stat==neimprumutat)?"neimprumutata":"imprumutata" );
        }
        else
            printf("Nu s-a gasit revista cu numele introdus!");
        printf("\n \n");
        printf("                   ------ Afisarea s-a sfarsit ------   \n");
        printf("        ------ Apasati tasta ENTER pentru a afisa meniul -------       \n");
        char ch;
       ch=getchar();
       fflushstdin();
       if(ch=='\n')
        {
            #ifdef _WIN32
                system("cls");
            #endif // _WIN32
            #ifdef linux
                system("clear");
            #endif // linux
            #ifdef __APPLE__
                system("clear");
            #endif // apple
        }
       goto meniu;
    }


   case 7:
    {
        printf("Introduceti titlurilor cartilor unul cate unul urmate de tasta ENTER dupa fiecare nume! \n");
        printf("Daca doriti sa va opriti, tastati 'stop' ! \n");
        int ok=1;
        while (ok)
        {
            char nume_temp[100];
            char temp;
            scanf("%c",&temp);
            scanf("%[^\n]",nume_temp);

            if (cautare_carte_verificare(nume_temp,a)== 1)
            {
                if (( n_carti -1) != 0)
                {
                    int k=0;
                    for (int i=0;i<n_carti;i++)
                        if (strcmp(nume_temp,a.carti[i].titlu)!=0)
                            a.carti[k++]=a.carti[i];
                    a.carti= (carte*)realloc(a.carti, k*sizeof(carte));
                    n_carti=n_carti-1;
                }
                else
                   {
                    n_carti=0;
                    free(a.carti);
                   }
                printf("Carte stearsa cu succes!\n");
                printf("Cititi in continuare alt titlu! \n");
                printf("\n");

            }
            else
                if (strcmp(nume_temp,"stop")== 0)
                    {
                        ok=0;
                        printf("        ------ Apasati tasta ENTER pentru a va intoarce la meniul principal -------       \n");
                       char ch1;
                       ch1=getchar();
                       fflushstdin();
                       if(ch1=='\n')
                        {
                            #ifdef _WIN32
                                system("cls");
                            #endif // _WIN32
                            #ifdef linux
                                system("clear");
                            #endif // linux
                            #ifdef __APPLE__
                                system("clear");
                            #endif // apple
                        }

                       goto meniu;
                    }
            else
                printf("Carte negasita! \n");

        }
    }

   case 8:
    {
        printf("Introduceti numele revistelor unul cate unul urmate de tasta ENTER dupa fiecare nume! \n");
        printf("Daca doriti sa va opriti, tastati 'stop' ! \n");
        int ok=1;
        while (ok)
        {
            char nume_temp[100];
            char temp;
            scanf("%c",&temp);
            scanf("%[^\n]",nume_temp);

            if (cautare_revista_verificare(nume_temp,a)== 1)
            {
                if (( n_reviste -1) != 0)
                {
                    int k=0;
                    for (int i=0;i<n_reviste;i++)
                        if (strcmp(nume_temp,a.reviste[i].nume)!=0)
                            a.reviste[k++]=a.reviste[i];
                    a.reviste= (revista*)realloc(a.reviste, k*sizeof(carte));
                    n_reviste=n_reviste-1;
                }
                else
                   {
                    n_reviste=0;
                    free(a.reviste);
                   }
                printf("Revista stearsa cu succes!\n");
                printf("Cititi in continuare alt nume! \n");
                printf("\n");
            }
            else
                if (strcmp(nume_temp,"stop")== 0)
                    {
                        ok=0;
                        printf("        ------ Apasati tasta ENTER pentru a va intoarce la meniul principal -------       \n");
                       char ch1;
                       ch1=getchar();
                       fflushstdin();
                       if(ch1=='\n')
                        {
                            #ifdef _WIN32
                                system("cls");
                            #endif // _WIN32
                            #ifdef linux
                                system("clear");
                            #endif // linux
                            #ifdef __APPLE__
                                system("clear");
                            #endif // apple
                        }

                       goto meniu;
                    }
            else
                printf("Revista negasita! \n");
        }
    }

   case 9:
    {
        printf("Cate carti doriti sa adaugati? \n");
        int local=0;
        scanf("%d",&local);
        for (int i=0;i<local;i++)
        {
             a.carti= (carte*)realloc(a.carti, (n_carti+1)*sizeof(carte));

            printf("\n \n");
            printf("Cartea #%d de adaugat \n", i);
            printf("Dati urmatoarele detalii despre carte: \n");

            printf("\n");
            char aux1[101];
             printf("Introduceti titlul cartii:  ");

            scanf("%c",&temp);
            scanf("%[^\n]", aux1);
            strcpy(a.carti[n_carti].titlu,aux1);

            printf("\n");
            char aux2[101];
            printf("Introduceti autorul cartii:  ");
            scanf("%c",&temp);
            scanf("%[^\n]",aux2);
            strcpy(a.carti[n_carti].autor,aux2);

            printf("\n");
            char aux3[101];
            printf("Introduceti editura cartii:  ");
            scanf("%c",&temp);
            scanf("%[^\n]",aux3);
            strcpy(a.carti[n_carti].editura,aux3);

            printf("\n");
            char aux4[101];
            printf("Introduceti genul cartii:  ");
            scanf("%c",&temp);
            scanf("%99s",aux4);
            strcpy(a.carti[n_carti].gen,aux4);

            printf("\n");
            int aux5;
            printf("Introduceti numarul de pagini:  ");
            scanf("%d",&aux5);
            a.carti[n_carti].numar_pagini=aux5;

            printf("\n");
            int aux6;
            printf("Introduceti codul de identificare a cartii:  ");
            scanf("%d",&aux6);
            a.carti[n_carti].cod=aux6;

            printf("\n");
            int rasplocal;
            printf("Care este statusul cartii? Inchiriata(1) sau Neinchiriata(2)? /nScrieti cifra corespunzatoare:  ");
            scanf("%d", &rasplocal);
            if (rasplocal== 2)
                a.carti[n_carti].stat=neimprumutat;
            else
                a.carti[n_carti].stat=imprumutat;
            n_carti=n_carti+1;
            printf("Carte adaugata cu succes! \n");

        }

        printf("\n \n");
        printf("                          ------ Carti adaugate cu succes! --------                       \n");
        printf("        ------ Apasati tasta ENTER pentru a va intoarce la meniul principal -------       \n");
       char ch1;
       ch1=getchar();
       fflushstdin();
       if(ch1=='\n')
        {
            #ifdef _WIN32
                system("cls");
            #endif // _WIN32
            #ifdef linux
                system("clear");
            #endif // linux
            #ifdef __APPLE__
                system("clear");
            #endif // apple
        }
       goto meniu;
    }
   case 10:
    {
        printf("Cate reviste doriti sa adaugati? \n");
        int local=0;
        scanf("%d",&local);
        for (int i=0;i<local;i++)
        {
             a.reviste= (revista*)realloc(a.reviste, (n_reviste+1)*sizeof(revista));
            printf("\n \n");
            printf("Revista #%d de adaugat \n", i);
            printf("Dati urmatoarele detalii despre revista: \n");

            printf("\n");
            char aux11[101];
            printf("Introduceti titlul revistei:  ");
            scanf("%c",&temp);
            scanf("%[^\n]",aux11);
            strcpy(a.reviste[n_reviste].nume,aux11);

            printf("\n");
            char aux31[101];
            printf("Introduceti editura revistei:  ");
            scanf("%c",&temp);
            scanf("%[^\n]",aux31);
            strcpy(a.reviste[n_reviste].editura,aux31);

            printf("\n");
            int aux5;
            printf("Introduceti numarul de pagini:  ");
            scanf("%d",&aux5);
            a.reviste[n_reviste].nr_pagini=aux5;

            printf("\n");
            int aux6;
            printf("Introduceti codul de identificare al revistei:  ");
            scanf("%d",&aux6);
            a.reviste[n_reviste].cod=aux6;

            printf("\n");
            int rasplocal;
            printf("Care este statusul revistei? Inchiriata(1) sau Neinchiriata(2)? \nScrieti cifra corespunzatoare:  ");
            scanf("%d", &rasplocal);
            if (rasplocal== 2)
                a.reviste[n_reviste].stat=neimprumutat;
            else
                a.reviste[n_reviste].stat=imprumutat;

            n_reviste=n_reviste+1;

            printf("Revista adaugata cu succes! \n");
        }

        printf("\n \n");
        printf("                          ------ Reviste adaugate cu succes! --------                       \n");
        printf("        ------ Apasati tasta ENTER pentru a va intoarce la meniul principal -------       \n");
       char ch1;
       ch1=getchar();
       fflushstdin();
       if(ch1=='\n')
        {
            #ifdef _WIN32
                system("cls");
            #endif // _WIN32

            #ifdef linux
                system("clear");
            #endif // linux

            #ifdef __APPLE__
                system("clear");
            #endif // apple
        }

       goto meniu;
    }
   case 11:
    {
        #ifdef _WIN32
            system("cls");
        #endif // _WIN32

        #ifdef linux
            system("clear");
        #endif // linux

        #ifdef __APPLE__
            system("clear");
        #endif // apple

        printf("Va multumesc pentru utilizarea aplicatiei! La revedere! \n");
        if (n_reviste!=0)
        free(a.reviste);
        if (n_carti!=0)
            free(a.carti);

        fclose(f);

        return 0;
    }

   default:
    {
        printf("                          ------ Optiune invalida! --------                       \n");
        printf("        ------ Apasati tasta ENTER pentru a va intoarce la meniul principal -------       \n");
       char ch1;
       ch1=getchar();
       fflushstdin();
       if(ch1=='\n')
        {
            #ifdef _WIN32
                system("cls");
            #endif // _WIN32

            #ifdef linux
                system("clear");
            #endif // linux

            #ifdef __APPLE__
                system("clear");
            #endif // apple
        }
       goto meniu;
    }
}
 }

    return 0;
}
