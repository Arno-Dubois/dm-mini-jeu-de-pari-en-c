#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int spendingMoney;
int randomNumber = 3;

void play() {
    int bet;
    printf("Combien voulez vous parier ? \n");
    scanf("%d", &bet);
    getchar();

    if(0 > bet || bet > spendingMoney) {
        printf("Mauvaise entrée, veuillez réessayer\n");
        play(spendingMoney);
        return;

    } if(rand() % (100 + 1 - 1) + 1 == randomNumber) {
        spendingMoney += bet;
        printf("Bravo vous avez gagner le pari ! Votre somme est doublée à %d€\n",spendingMoney);

    } else {
        spendingMoney -= bet;
        printf("Vous avez perdu, vous n'avez plus que %d€\n", spendingMoney);

    }
}

int main() {
    char str[8];

    srand(time(NULL));
    spendingMoney = rand() % (3000 + 1 - 100) + 100;

    printf("Bienvenue sur le jeu du pari en c, vous avez %d€, bonne chance !\n", spendingMoney);

    while(1) {
        printf("Voulez vous 'jouer' ou 'retirer' votre somme ?\n");
        fgets(str, 8, stdin);

        if(strcmp("jouer\n", str) == 0) play();
        else if(strcmp("retirer", str) == 0) {
            printf("Vous repartez avec un total de %d€, à bientôt !", spendingMoney);
            return 0;}
        else printf("Mauvaise entrée, veuillez réessayer\n");
    }

    return 1;
}
