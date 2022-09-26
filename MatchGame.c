#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void createMatches(int tabMatches[], int nbMatches)
{
    int *ptr = tabMatches;
    for (int i = 0; i < nbMatches; i++)
    {
        *(ptr + i) = 1;
    }
}

int canRemoveMatch(int tabMatches[], int index, int length)
{
    if (index >= 0 && index < length && tabMatches[index] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getRemainingMatches(int tabMatches[], int length)
{
    int cpt = 0;
    for (int i = 0; i < length; i++)
    {
        if (tabMatches[i] == 1)
        {
            cpt++;
        }
    }
    return cpt;
}

int playerChoice(int maxToRemove, int maxRemovable)
{
    int nb;

    printf("Indiquez le nombre d'allumettes a retirer (<= 3) : ");
    scanf("%d", &nb);
    while (nb < 1 || nb > maxToRemove || nb > maxRemovable)
    {
        printf("Invalide ! Recommencez \n");
        scanf("%d", &nb);
    }

    return nb;
}

void removeMatch(int tabMatches[], int index)
{
    int *ptr = tabMatches;
    *(ptr + index) = 0;
}

int isWinGame(int tabMatches[], int length)
{
    return getRemainingMatches(tabMatches, length) == 1;
}

int isLoseGame(int tabMatches[], int length)
{
    return getRemainingMatches(tabMatches, length) == 0;
}

int isEndGame(int tabMatches[], int length)
{
    if (isWinGame(tabMatches, length) || isLoseGame(tabMatches, length))
    {
        return 1;
    }

    return 0;
}

int aiChoice(int max, int remaining)
{
    int nbToRemove;

    if (remaining % 4 == 3)
    {
        nbToRemove = 2;
    }
    else if (remaining % 4 == 2)
    {
        nbToRemove = 1;
    }
    else if (remaining % 4 == 0)
    {
        nbToRemove = 3;
    }
    else
    {
        do
        {
            nbToRemove = (rand() % max) + 1;
        } while (nbToRemove > remaining);
    }

    return nbToRemove;
}

void displayMatches(int tabMatches[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (tabMatches[i] == 1)
        {
            printf("| ");
        }
        else
        {
            printf("X ");
        }
        if (i >= 9)
        {
            printf(" ");
        }
    }
    printf("\n");
    for (int i = 1; i <= length; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int randomRange(int min, int max) // [min ; max[
{
    srand(time(NULL));
    return (rand() % (max - min)) + min;
}

void onePlayerNaive()
{
    int nbMatches;
    int remaining;
    int nbToRemove;
    int matchToRemove;
    int MAX = 3;
    int numPlayer = randomRange(0, 2) + 1;
    char playerOne[20];
    char computer[] = "Ordinateur";

    printf("Veuillez entrer le nom du joueur : ");
    scanf("%s", playerOne);

    printf("Veuillez saisir le nombre d'allumettes total : ");
    scanf("%d", &nbMatches);

    int matches[nbMatches];

    createMatches(matches, nbMatches);
    displayMatches(matches, nbMatches);

    while (!isEndGame(matches, nbMatches))
    {
        numPlayer = (numPlayer % 2) + 1;

        remaining = getRemainingMatches(matches, nbMatches);
        printf("Il reste %d allumettes a retirer\n", remaining);

        printf("%s - ", numPlayer == 1 ? playerOne : computer);

        if (numPlayer == 2)
        {
            do
            {
                nbToRemove = (rand() % MAX) + 1;
            } while (nbToRemove > remaining);
        }
        else
        {
            nbToRemove = playerChoice(MAX, remaining);
        }

        for (int i = 0; i < nbToRemove; i++)
        {
            do
            {
                matchToRemove = rand() % nbMatches;
            } while (!canRemoveMatch(matches, matchToRemove, nbMatches));

            removeMatch(matches, matchToRemove);
        }

        printf("%s a retire %d allumette(s)\n", numPlayer == 1 ? playerOne : computer, nbToRemove);

        displayMatches(matches, nbMatches);

        printf("\n");
    }
    printf("%s ", numPlayer == 1 ? playerOne : computer);

    if (isWinGame(matches, nbMatches))
    {
        printf("a gagne");
    }
    else
    {
        printf("a perdu");
    }
}

void onePlayerSmart()
{
    int nbMatches;
    int remaining;
    int nbToRemove;
    int matchToRemove;
    int MAX = 3;
    int numPlayer = randomRange(0, 2) + 1;
    char playerOne[20];
    char computer[] = "Ordinateur";

    printf("Veuillez entrer le nom du joueur : ");
    scanf("%s", playerOne);

    printf("Veuillez saisir le nombre d'allumettes total : ");
    scanf("%d", &nbMatches);

    int matches[nbMatches];

    createMatches(matches, nbMatches);
    displayMatches(matches, nbMatches);

    while (!isEndGame(matches, nbMatches))
    {
        numPlayer = (numPlayer % 2) + 1;

        remaining = getRemainingMatches(matches, nbMatches);
        printf("Il reste %d allumettes a retirer\n", remaining);
        printf("%s - ", numPlayer == 1 ? playerOne : computer);

        if (numPlayer == 2)
        {
            nbToRemove = aiChoice(MAX, remaining);
        }
        else
        {
            nbToRemove = playerChoice(MAX, remaining);
        }

        for (int i = 0; i < nbToRemove; i++)
        {
            do
            {
                matchToRemove = rand() % nbMatches;
            } while (!canRemoveMatch(matches, matchToRemove, nbMatches));

            removeMatch(matches, matchToRemove);
        }

        printf("%s a retire %d allumette(s)\n", numPlayer == 1 ? playerOne : computer, nbToRemove);
        displayMatches(matches, nbMatches);

        printf("\n");
    }
    printf("%s ", numPlayer == 1 ? playerOne : computer);
    if (isWinGame(matches, nbMatches))
    {
        printf("a gagne");
    }
    else
    {
        printf("a perdu");
    }
}

void twoPlayersGame()
{
    int nbMatches;
    int remaining;
    int nbToRemove;
    int matchToRemove;
    int MAX = 3;
    int numPlayer = randomRange(0, 2) + 1;
    char playerOne[20];
    char playerTwo[20];

    printf("Veuillez entrer le nom du joueur 1 : ");
    scanf("%s", playerOne);
    printf("Veuillez entrer le nom du joueur 2 : ");
    scanf("%s", playerTwo);

    printf("Veuillez saisir le nombre d'allumettes total : ");
    scanf("%d", &nbMatches);

    int matches[nbMatches];

    createMatches(matches, nbMatches);
    displayMatches(matches, nbMatches);

    while (!isEndGame(matches, nbMatches))
    {
        numPlayer = (numPlayer % 2) + 1;

        remaining = getRemainingMatches(matches, nbMatches);
        printf("Il reste %d allumettes a retirer\n", remaining);

        printf("%s - ", numPlayer == 1 ? playerOne : playerTwo);

        nbToRemove = playerChoice(MAX, remaining);

        for (int i = 0; i < nbToRemove; i++)
        {
            do
            {
                matchToRemove = rand() % nbMatches;
            } while (!canRemoveMatch(matches, matchToRemove, nbMatches));

            removeMatch(matches, matchToRemove);
        }
        displayMatches(matches, nbMatches);

        printf("\n");
    }
    printf("%s ", numPlayer == 1 ? playerOne : playerTwo);
    if (isWinGame(matches, nbMatches))
    {
        printf("a gagne");
    }
    else
    {
        printf("a perdu");
    }
}

int main()
{
    int choice;
    int gameMode;

    printf("Bonjour et bienvenue dans le jeu des allumettes\n\nVous allez avoir 3 menus.\nVous choisirez d'abord si vous voulez voir les regles u jeu ou non, puis le nombre d'allumettes a utiliser, et enfin le nombre de joueurs.\n\nQue faire ?\n\n1 - Jouer\n2 - Voir les regles du jeu\n3 - Voir les credits\n4 - Quitter\n\nVotre choix : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Choisissez votre mode de jeu :\n\n1 - Humain VS Ordinateur - Facile\n2 - Humain VS Ordinateur - Difficile\n3 - 2 joueurs\n\nVotre choix : ");
        scanf("%d", &gameMode);
        switch (gameMode)
        {
        case 1:
            onePlayerNaive();
            break;
        case 2:
            onePlayerSmart();
            break;
        case 3:
            twoPlayersGame();
            break;
        default:
            break;
        }
        break;
    case 2:
        printf("Le but du jeu est simple :\n\nCe jeu se joue a deux. Vous avez un nombre n d'allumettes.\nA tour de role, chacun des deux joueurs enleve entre 1 et 3 allumettes selon ce qu'il souhaite. Le perdant est celui qui doit enlever la derniere allumette.\n\nAttention il existe 3 niveaux de difficulte en version Humain VS Ordi.\nLe premier est plutot simple a battre, donc pour les debutants. Mais le dernier...\nContactez moi si vous avez reussi (screenshot evidemment) mon e-mail est dans les credits");
        break;
    case 3:
        printf("Auteur : VAN Steven\nMail : steven-van@outlook.fr\nGitHub : github.com/steven-van");
        break;
    case 4:
        printf("Bye bye ! :)");
        exit(0);
    default:
        exit(0);
    }
    // Refacto le tableau en int decrementable ?
}