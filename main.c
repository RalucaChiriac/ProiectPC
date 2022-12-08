/// Chiriac Raluca-Roxana
/// Grupa 164

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rlutil.h>
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

void afisare(biblioteca a)
{
    printf(" \n ||| Afisare ||| \n ");
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


int main()
{
    FILE *f = fopen("intrare.txt","r");
    biblioteca a;

    char nume1[101];
    /// printf("Introduceti numele bibliotecii! \n");
    fscanf(f, "%99s", nume1);
    strcpy(a.nume,nume1);

    /// printf("Introduceti numele Bibliotecarului! \n");
    char nume2[101];
    fscanf(f, "%99s", nume2);
    strcpy(a.bibliotecar,nume2);

    /// printf("Introduceti locatia bibliotecii \n");
    char nume3[101];
    fscanf(f,"%99s", nume3);
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
            fscanf(f,"%99s", aux1);
            strcpy(a.carti[i].titlu,aux1);

            char aux2[101];
            /// printf("Introduceti autorul cartii! \n");
            fscanf(f,"%99s",aux2);
            strcpy(a.carti[i].autor,aux2);

            char aux3[101];
            /// printf("Introduceti editura cartii! \n");
            fscanf(f,"%99s",aux3);
            strcpy(a.carti[i].editura,aux3);

            char aux4[101];
            /// printf("Introduceti genul cartii! \n");
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
            fscanf(f,"%99s",aux11);
            strcpy(a.reviste[i].nume,aux11);

            char aux31[101];
            /// printf("Introduceti editura revistei! \n");
            fscanf(f,"%99s",aux31);
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
        return 0;
    }

    }

    afisare(a);

    if (n_reviste!=0)
        free(a.reviste);

    if (n_carti!=0)
        free(a.carti);

    fclose(f);

    return 0;
}
