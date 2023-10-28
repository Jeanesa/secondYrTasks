// Created by: Jeanesa Dugang
// Course and Section: BSCS-2A
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

struct playerInfo {
    char playerName[31];
    int playerFGA;
    int playerFGM;
};

void getRecord(struct playerInfo[]);
void displayRecord(struct playerInfo[]);
float computeFGP(int playerFGA, int playerFGM);

int main() {
    struct playerInfo totalPlayers[MAX];
    getRecord(totalPlayers);
    displayRecord(totalPlayers);
    return 0;
}

void getRecord(struct playerInfo totalPlayers[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("\nRECORDS OF FIELD GOAL PERFORMANCES OF BASKETBALL PLAYERS\n");
        printf("Enter player %d name: ", i+1);
        scanf(" %[^\n]", totalPlayers[i].playerName);
        printf("Input Field Goal Attempt: ");
        scanf("%d", &totalPlayers[i].playerFGA);
        printf("Input Field Goal Made: ");
        scanf("%d", &totalPlayers[i].playerFGM);
    }
}

void displayRecord(struct playerInfo totalPlayers[]) { 
    int i;
    float FGP;
    system("cls");
    printf("    %-25s %-10s %-10s %-10s %-10s\n", "PLAYER", "FGA", "FGM", "FGP%", "REMARKS");
    for (i = 0; i < MAX; i++) {
        FGP = computeFGP(totalPlayers[i].playerFGA, totalPlayers[i].playerFGM);
        printf("%d.) %-25s %-10d %-10d %-5.2f%%\t%-10s\n", i + 1, totalPlayers[i].playerName, totalPlayers[i].playerFGA,
               totalPlayers[i].playerFGM, FGP, FGP > 50.0 ? "HIGH" : "LOW");
    }
}

float computeFGP(int playerFGA, int playerFGM) {
    if (playerFGA == 0) {
        return 0.0;
    }
    return ((float)playerFGM / playerFGA) * 100;
}
