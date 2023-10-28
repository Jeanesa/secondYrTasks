#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX 3

// GLOBAL VARIABLES
struct playerInfo {
    char name[31];
    int FGA;
    int FGM;
    float FGP;
};
int i;

// FUNCTION DECLARATIONS
void getRecord(struct playerInfo player[]);
void displayRecord(struct playerInfo player[]);
float computeFGP(int FGM, int FGA);

int main() {
    struct playerInfo player[MAX];
    getRecord(player);
    displayRecord(player);
    return 0;
}

void getRecord(struct playerInfo player[]) {
    for (i = 0; i < MAX; i++) {
        printf("\nRECORDS OF FIELD GOAL PERFORMANCES OF BASKETBALL PLAYERS\n");
        printf("Enter player %d name: ", i + 1);
        scanf(" %[^\n]", player[i].name); 
        printf("Input Field Goal Attempt: ");
        scanf("%d", &player[i].FGA);
        printf("Input Field Goal Made: ");
        scanf("%d", &player[i].FGM);
    }
}

void displayRecord(struct playerInfo player[]) {
    system("cls");
    printf("    %-25s %-10s %-10s %-10s %-10s\n", "PLAYER", "FGA", "FGM", "FGP%", "REMARKS");
    for (i = 0; i < MAX; i++) {
        float FGP = computeFGP(player[i].FGM, player[i].FGA); 
        printf("%d.) %-25s %-10d %-10d %-5.2f%%\t%-10s\n", i + 1, player[i].name, 
		player[i].FGA, player[i].FGM, FGP, FGP > 50.0 ? "HIGH" : "LOW");
    }
}

float computeFGP(int FGM, int FGA) {
    if (FGA == 0) {
        return 0.0;
    }
    return ((float)FGM / FGA) * 100;
}
