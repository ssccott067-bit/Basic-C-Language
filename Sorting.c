#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Définir un tableau */
#define CASE 10
typedef int nombre[CASE];

// Remplir le tableau 
 void remplir_aleatoire (nombre x) {
    int i;

    srand(time(NULL));

    for (i=0;i<CASE;i++)
    {
        x[i] = rand () % 21;
    }
}

// Afficher le contenu dans le tableau 
void afficher_tableau (nombre x) {
    int i;

    for (i=0;i<CASE;i++)
    {
        printf("| %d ", x[i]);
    }

    printf("\n");
}

// Trier à bulles 
void tri_bulles (nombre x) {
    int i;
    int j;

    for (i=1;i<CASE;i++)
    {
        for (j=0;j<CASE-i;j++)
        {
            // Comparer et changer si besoin
           if (x[j] > x[j+1]) 
           {
            x[j+1] = x[j+1] + x[j];
            x[j] = x[j+1] - x[j];
            x[j+1] = x[j+1] - x[j];
           }
        }
    }
}

// Trier par selection 
void tri_selection (nombre x) {
    int i;
    int j;
    int indmin;

    for (i=0;i<CASE-1;i++)
    {
        indmin = i;

        // Chercher le plus petit element 
        for (j=i+1;j<CASE;j++)
        {
            if (x[indmin] > x[j])
            {
                indmin = j;
            }
        }

        // Changer si besoin 
        if (indmin != i)
        {
            x[i] = x[i] + x[indmin];
            x[indmin] = x[i] - x[indmin];
            x[i] = x[i] - x[indmin];
        }
    }
}

//Trier par insertion 
void tri_insertion (nombre x) {
    int cle;
    int i, j;

    for (i=1;i<CASE;i++)
    {
        cle = x[i];
        j = i - 1;

        /* Décaller les éléments */
        while (j >= 0 && x[j] > cle)
        {
            x[j+1] = x[j];
            j = j - 1;
        }

        x[j+1] = cle;
    }
}

//Trier par fusion (éclatement)
//fonction de fusionner
void fusion (nombre x, int gauche, int milieu, int droite) {
    int i, j, k; 
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    // pour copier les elements de tableau 
    int T1[n1], T2[n2];

    // copier les elements dans le tableau T1
    for (i=0;i<n1;i++)
    {
        T1[i] = x[gauche + i];
    }

    // copier les elements dans le tableau T2
    for (j=0;j<n2;j++)
    {
        T2[j] = x[milieu + 1 + j];
    }

    // fusioner les tableaux T1 et T2 dans le tableau principal 
    i = 0;
    j = 0;
    k = gauche;

    while (i<n1 && j<n2) 
    {
        if (T1[i] <= T2[j])
        {
            x[k] = T1[i];
            i += 1;
        } 
        else 
        {
            x[k] = T2[j];
            j += 1;
        }
        k += 1;
    }

    // copier les elements restants de tableau T1
    while (i < n1) 
    {
        x[k] = T1[i];
        i += 1;
        k += 1;
    }

    // copier les elements restants de tableau T2
    while (j < n2)
    {
        x[k] = T2[j];
        j += 1;
        k += 1;
    }
}

// fonction combiner en triant les tableaux de gauche à droite 
void tri_fusion (nombre x, int gauche, int droite) {
    int milieu; 

    if (gauche < droite)
    {
        // calculer le point de milieu 
        milieu = gauche + (droite - gauche) / 2;

        // trier 
        tri_fusion(x, gauche, milieu);
        tri_fusion(x, milieu + 1, droite);

        // combiner 
        fusion(x, gauche, milieu, droite); 
    }
}

// recherche dichotomique 
int recherche_dichotomique (nombre x, int cherche, int gauche, int droite) {
    int i, milieu;

    milieu = (droite + gauche) / 2 ;

    if (gauche > droite) 
    {
        return -1;
    }
    else if (x[milieu] < cherche)
    {
        return recherche_dichotomique(x, cherche, milieu + 1, droite);
    }
    else if (x[milieu] > cherche)
    {
        return recherche_dichotomique(x, cherche, gauche, milieu - 1);
    }
    else 
    {
        return cherche;
    }
}

// tri quicksort 
void tri_quicksort (nombre x, int gauche, int droite) 
{
    int i, k, temporaire; 

    i = gauche;
    k = droite;

    if (gauche >= droite)
    {
        return;
    }

    while (i < k)
    {

        // parcourir le tableau de gauche à droite 
        while (i < k && x[k] >= x[gauche])
        {
            k -= 1;
        }

        // parcourir le tableau de gauche à droite 
        while (i < k && x[i] <= x[gauche])
        {
            i += 1;
        }

        // échanger les valeurs 
        temporaire = x[k];
        x[k] = x[i];
        x[i] = temporaire;

    }

    // échanger le pivot avec la valeur de k 
    temporaire = x[gauche];
    x[gauche] = x[k];
    x[k] = temporaire;

    tri_quicksort(x, gauche, k - 1);
    tri_quicksort(x, k + 1, droite); 

}

/* --------------- Programme Principale --------------- */
int main () {
    int choix;
    nombre element;
    int k, n;
    int cherche; 

    do
    {
        //printf("")';
        printf("*********************************** \n");
        printf("1. remplir aléatoirement un tableau \n");
        printf("2. afficher un tableau \n");
        printf("3. effectuer un tri à bulles \n");
        printf("4. effectuer un tri par sélection \n");
        printf("5. effectuer un tri par insertion \n");
        printf("6. effectuer un tri par fusion/éclatement \n");
        printf("7. quitter \n");
        printf("8. recherche dichotomique \n"); 
        printf("9. effectuer un tri quicksort \n");
        printf("*********************************** \n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1 : 
            // remplir tableau aléatoirement 
            remplir_aleatoire(element); 
            printf("Tableau est remplis ! \n");
            break;

            case 2 :
            // afficher le tableau 
            afficher_tableau(element);
            break;

            case 3 : 
            // tri à bulles
            tri_bulles(element);
            printf("Tri est fini ! \n");
            break;

            case 4 :
            // tri par sélection 
            tri_selection(element);
            printf("Tri est fini ! \n");
            break;

            case 5 : 
            // tri par insertion 
            tri_insertion(element);
            printf("Tri est fini ! \n");
            break;

            case 6 : 
            // tri par fusion/éclatement
            tri_fusion(element, 0, CASE-1);
            printf("Tri est fini ! \n");
            break; 

            case 7 : 
            // terminer le programme 
            printf("Fin du programme \n");
            printf("*********************************** ");
            break;

            case 8 : 
            // recherche dichotomique 
            printf("Saisir le nombre cherché : ");
            scanf("%d", &cherche);

            if (recherche_dichotomique(element, cherche, 0, CASE -1) == -1)
            {
                printf("Il n'y en a pas \n");
            } 
            else 
            {
                printf("Trouvé ! \n");
            }
            break;

            case 9 : 
            // tri quicksort 
            tri_quicksort(element, 0, CASE - 1);
            printf("Tri est fini ! \n");
            break;

            default : 
            // message d'erreur 
            printf("Erreur : Veuillez choisir les choix suivants \n");

        }
    } while (choix != 7);

    return 0;
}