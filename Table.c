/*--------------------- EXERCICE 2 ----------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Deifnir un constant pour la longeur de tableau */
#define NB 10

/* Definir un type de tableau */
typedef int tab[10];

/* 1 : Remplissage du tableau */
//Par utilisateur
void array1(tab x)
{
    int i;
    for (i=0;i<NB;i++)
    {
        printf("Case %d : ", i+1);
        scanf("%d", &x[i]);
    }
}
//Par random
void array2(tab x)
{
    int i; 

    srand(time(NULL));

    for (i=0;i<NB;i++)
    {
        x[i] = rand () % 21;
    }
}

/* 2 : Afficher le contenu d'un tableau */
void affichetable(tab x)
{
    int i;

    for (i=0;i<NB;i++)
    {
        printf("|%d ", x[i]);
    }
}

/* 3: Rechercher une valeur saisie par l'utilisateur */
int chercher(int n, tab x)
{
    int valche, i, verite;
    
    i = 0;
    verite = 0;
    do
    {
        valche = x[i];
        i++;
    } while (i<NB && valche != n);
    
    if (n == valche)
    {
        verite = 1;
    }

    return verite;
}

/* 4 : Recherche la valeur minimum dans le tableau */
int valeurmin(tab x)
{
    int min, i;
    
    min = x[0];
    for (i=0;i<NB;i++)
    {
        if (x[i]<min)
        {
            min = x[i];
        }
    }

    return min;
}

/* 5 : Compter le nombre d'occurence d'une valeur demandée dans un tableau */
int compteur(int n, tab x)
{
    int i;
    int compteur = 0;

    for (i=0;i<NB;i++)
    {
        if (n == x[i])
        {
            compteur++;
        }
    }

    return compteur;
}

/* 6 : Calculer la moyenne des valeurs d'un tableau */
float moyenne(tab x)
{
    int i;
    float somme = 0;

    for (i=0;i<NB;i++)
    {
        somme = somme + x[i];
    }

    return somme/NB;
}

/* 7: Determiner si un tableau est palindrome */
int palindrome(tab x) {
    int check = 1;
    int i = 0;
    int j = NB-1;
    while ((i<(NB/2) && j>(NB/2)) && check == 1)
    {
        if (x[i] != x[j])
        {
            check = 0;
        }
        i++;
        j--;
    }

    return check;
}

/* Programme principal */
int main ()
{
    int i, j, valeur, recherche, min, compt, palin, choix, souschoix, nombre;
    float somme;
    tab table;

    /* Creation du menu */
    do
    {
        printf("******************************************************************\n");
        printf("1. Remplir un tableau\n");
        printf("2. Afficher les valeurs d'un tableau\n");
        printf("3. Rechercher une valeur dans un tableau, saisie par l'utilisateur\n");
        printf("4. Rechercher la valeur minimum d'un tableau\n");
        printf("5. Compter la nombre d'occurences d'une valeur demandée\n");
        printf("6. Calculer la moyenne des valeurs d'un tableau\n");
        printf("7. Quitter\n");
        printf("8. Tester si le tableau est un palindrome\n");
        printf("******************************************************************\n");
        printf("Veuillez saisir votre choix : ");
        scanf("%d", &choix);
        printf("******************************************************************\n");

        switch (choix)
        {
            /* Remplir le tableau */
            case 1:
            printf("1. Remplir manuellement\n");
            printf("2. Saisie aléatoire\n");
            printf("******************************************************************\n");
            printf("Veuillez saisir votre choix pour la methode de remplissage : ");
            scanf("%d", &souschoix);
            if (souschoix == 1)
            {
                /* Par utilisateur */
                array1(table);
            }
            else
            {
                /* Par aléatoire */
                array2(table);
            }
            break;

            /* Afficher les valeurs dans le tableau */
            case 2:
            affichetable(table);
            printf("\n");
            break;

            /* Rechercher une valeur dans le tableau */
            case 3:
            printf("Veuillez saisir une valeur à rechercher: ");
            scanf("%d", &valeur);
            recherche = chercher(valeur, table);

            if (recherche == 1) {
                printf("Valeur est trouvée\n");
            } 
            else
            {
                printf("Valeur n'est pas trouvée\n");
            }
            break;

            /* Recherche la valeur minimum*/
            case 4:
            printf("La valeur minimum est : %d\n", valeurmin(table));
            break;

            /* Calculer le nombre d'occurence d'un nombre */
            case 5:
            printf("Veuillez saisir une valeur : ");
            scanf("%d", &valeur);
            printf("Le nombre d'occurence de %d est : %d\n", valeur, compteur(valeur, table));
            break;

            /* Calculer la moyenne */
            case 6:
            printf("La moyenne est : %.3f\n", moyenne(table));
            break;

            /* Fin du programme */
            case 7:
            printf("-----------------\n");
            printf("Fin du programme.\n");
            printf("-----------------");
            break;

            /* Tester si le tableau est un palindrome ou pas */
            case 8:
            palin = palindrome(table);
            if (palin == 1)
            {
                printf("Le tableau est palindrome\n");
            }
            else 
            {
                printf("Le tableau n'est pas palindrome\n");
            }
            break;

            /* Message d'erreur */
            default :
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            printf("Choix n'est pas entre 1 et 7");
            printf("\n");
        }
    } while (choix != 7);

    return 0;
}