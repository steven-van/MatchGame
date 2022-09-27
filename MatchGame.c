#include "functions.c"

int main()
{
    int choice;
    int gameMode;

    printf("Bonjour et bienvenue dans le jeu des allumettes\n\nAvant de jouer, vous pouvez consulter les regles du jeu ou les credits.\n\nQue faire ?\n\n1 - Jouer\n2 - Voir les regles du jeu\n3 - Voir les credits\n4 - Quitter\n\nVotre choix : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Choisissez votre mode de jeu :\n\n1 - Humain VS Ordinateur - Facile\n2 - Humain VS Ordinateur - Difficile\n3 - 2 joueurs\n4 - Ordinateur VS Ordinateur\n\nVotre choix : ");
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
        case 4:
            computerGame();
            break;
        default:
            break;
        }
        break;
    case 2:
        printf("Le but du jeu est simple :\n\nCe jeu se joue a deux. Vous avez un nombre n d'allumettes.\nA tour de role, chacun des deux joueurs enleve entre 1 et 3 allumettes selon ce qu'il souhaite. Le perdant est celui qui doit enlever la derniere allumette.\n\nIl existe 3 modes de jeu :\n1 - Humain VS Ordi - Facile\n2 - Humain VS Ordi - Difficile\n3 - 2 joueurs\n\nBon jeu !");
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
}