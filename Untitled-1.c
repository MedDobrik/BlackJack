#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int RandomCard(){
    srand(time(0));
    int rd_num = rand() % (11 - 2 + 1) + 2;
    return rd_num;
}


void main() {
    // printf("%d", RandomCard());
    int Player = RandomCard() + RandomCard();
    sleep(1.4);
    int Dealer = RandomCard();
    char hit_stand;

    printf("\nDealer Has %d\n You Have %d", Dealer, Player);

    if (Player > 21){
        printf("\nYou Bust");
    }
    else{
        while (Player < 21 && hit_stand != 's'){
            printf("\nHit / Stand (h/s) : ");
            scanf("%c", &hit_stand);
            if ( hit_stand == 'h'){
                Player += RandomCard();
            }
        printf("\nDealer Has %d\n You Have %d\n", Dealer, Player);
        }
        if (Player > 21){
            printf("You Bust");
        }
        else{
            while (Dealer < 17){
                Dealer += RandomCard();
            printf("Dealer Has %d\n You Have %d\n", Dealer, Player);
            sleep(1);

            }
            if (Dealer > 21){
                printf("Dealer Bust, You WIN");
            }

            else if (Player > Dealer){
                printf("\nYou Win");
            }
            else {printf("\nYou Lose");}
        }
    }
}