/*-------------------------- Exercice 1, 3 et 4 ---------------------------*/

#include <stdio.h>

/* Écrire les fonctions pour faire les opérations mathématiques */

/* Fonction d'addition */
float addition (float nombre1, float nombre2)
{
    return nombre1 + nombre2;
}

/* Fonction de soustraction */
float soustraction(float nombre1, float nombre2)
{
    return nombre1 - nombre2;
}

/* Fonction de multiplication */
float multiplication(float nombre1, float nombre2)
{
    return nombre1 * nombre2;
}

/* Fonction de division */
float division(float nombre1, float nombre2)
{
    return nombre1 / nombre2;
}

/* Fonction de puissance */
float puissance(float nombre1, int n)
{
    float puis = 1;
    int i;
    
    /* Pour calculer la puissance de n où n est un entier negatif, enlevez la condition 'if' dans le case puissance, la condition 'if' dans la fonction, et changer le boucle 'for' dans la fonction puissance */
    /*
    int clone = n;
    if (n < 0)
    {
        clone = clone * -1;
    }

    for (i=0;i<clone;i++)
    {
        puis = puis * nombre1;
    }

    puis = 1/puis;  */

    for (i=0;i<n;i++)  /* <- À mettre en commentaire */
    {
        puis = puis * nombre1;
    }   

    return puis;
}

/* Déterminer si un nombre est heureux */
int est_heureux(int nombre)
{
    int somme = 0;
    int i, temporaire, clone;

    temporaire = nombre;
    clone = nombre;

    do
    {
        while (temporaire != 0)
        {
            i = temporaire%10;
            somme = somme + i*i;
            temporaire = temporaire - i;
            temporaire = temporaire/10;
        }

        temporaire = somme;
        clone = somme;
        somme = 0;
    } while (clone >= 10 );
    
    return clone;
}

/* Déterminer si les deux nombres distincts sont amis */
int sont_amis(int nombre1, int nombre2)
{
    int i;
    int somme1 = 1;
    int somme2 = 1;

    for (i=2;i*i<=nombre1;i++)
    {
        if (nombre1%i == 0)
        {
            somme1 += i;
            if (i != nombre1/i)
            {
                somme1 += nombre1/i;
            }
        }
    }

    for (i=2;i*i<=nombre2;i++)
    {
        if (nombre2%i == 0)
        {
            somme2 += i;
            if (i != nombre2/i)
            {
                somme2 += nombre2/i;
            }
        }
    }

    return ((somme1 == nombre2) && (somme2 == nombre1));
}

/* Programme principal */
int main ()
{
    float donne1, donne2;
    char operateur;

    do 
    {
        /* Le menu de choix */
        printf("\n");
        printf("Saisir dans l'ordre donnée1 opérateur donnée2\n");
        printf("1. Entrez + pour addition\n");
        printf("2. Entrez - pour soustraction\n");
        printf("3. Entrez * pour multiplication\n");
        printf("4. Entrez / pour division\n");
        printf("5. Entrez ^ pour la puissance\n");
        printf("6. Entrez S pour quitter\n");
        printf("7. Entrez H pour déterminer si le nombre est heureux\n");
        printf("8. Entrez A pour déterminer si les nombres sont amis\n");
        printf("****************************************************\n");
       printf("? ");
       scanf("%f %c %f", &donne1, &operateur, &donne2);

        switch (operateur) 
        {
            /* Pour addition */
            case '+': 
            printf("= %.2f\n", addition(donne1, donne2));
            break;

            /* Pour soustraction */
            case '-': 
            printf("= %.2f\n", soustraction(donne1, donne2));
            break;

            /* Pour multiplication */
            case '*':
            printf("= %.2f\n", multiplication(donne1, donne2));
            break;

            /* Pour division */
            case '/':
            if (donne2 == 0)        /* <- À mettre en commentaire */
            {
                printf("erreur : division par 0\n");
            }
            else
            {
                printf("= %.2f\n", division(donne1, donne2));
            }
            break;

            /* Pour puissance */
            case '^': 
            if (donne2 < 0)     
            {
                printf("erreur : l'exposant doit être un entier positif ou nul\n");     
            }
            else
            {   
                printf("= %.2f\n", puissance(donne1, donne2));
            }

            /*
            printf("= %.2f\n", puissance(donne1, donne2)); */ /* <- À enlever */
            break;

            /* Terminer le programme */
            case 'S':
            printf("Fin du programme.\n");
            break;

            /* Déterminer si un nombre est heureux */
            case 'H':
            if (est_heureux(donne1) == 1)
            {
                printf("= %.0f est un nombre heureux\n", donne1);
            }
            else
            {
                printf("= %.0f n'est pas un nombre heureux\n", donne1);
            }
            break;

            /* Déterminer si les deux nombres sont amis */
            case 'A':
            if (sont_amis(donne1, donne2) == 1)
            {
                printf("= %.0f et %.0f sont amis\n", donne1, donne2);
            }
            else
            {
                printf("= %.0f et %.0f ne sont pas amis\n", donne1, donne2);
            }
            break;

            /* Message d'erreur dans l'opérateur */
            default:
            printf("erreur : opérateur %c inconnu\n", operateur);
        }
        printf("****************************************************");
    } while (operateur != 'S');

    return 0;
}


