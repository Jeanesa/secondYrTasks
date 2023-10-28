//Created by: Jeanesa Dugang
//Course and Section: BSCS-2A
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void getRecord();
void displayRecord();
int currentRecord = 0;

struct playerInfo {
    char playerName[31];
    int playerFGA;
    int playerFGM;
};

struct playerInfo totalPlayer[MAX];

double computeFGP(int playerFGM, int playerFGA) {
    if (playerFGA == 0) {
        return 0.0;
    }
    return (double)(playerFGM) / (playerFGA) * 100.0;
}

int main() {
    int userChoice;
    do {
        printf("\nRECORDS OF FIELD GOAL PERFORMANCES OF BASKETBALL PLAYERS\n");
        printf("(You can input up to %d players) \n\n", MAX);
        printf("\tMENU\n");
        printf("1. ADD RECORD\n");
        printf("2. DISPLAY RECORD\n");
        printf("3. EXIT\n");
        printf("Enter your choice: ");
        if (scanf("%d", &userChoice) != 1) {
            printf("Invalid input. Please enter a numeric choice.\n");
            while (getchar() != '\n') continue;
            continue;
        }
        switch (userChoice) {
            case 1:
                getRecord();
                break;
            case 2:
                displayRecord();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (userChoice != 3);

    return 0;
}

void getRecord() {
    if (currentRecord < MAX) {
        struct playerInfo newPlayer;
        printf("\nEnter player name: ");
        scanf(" %[^\n]", newPlayer.playerName);
        printf("Input Field Goal Attempts: ");
        scanf("%d", &newPlayer.playerFGA);
        printf("Input Field Goal Made: ");
        scanf("%d", &newPlayer.playerFGM);
        totalPlayer[currentRecord++] = newPlayer;
        printf("******Record added successfully******\n\n");
    } else {
        printf("Maximum number of players reached.\n");
    }
}

void displayRecord() {
    system("cls");
    int i = 0;
    if (currentRecord == 0) {
        printf("No data to display. Enter data first.\n");
    } else {
        printf("\nRecords of Field Goal Performances of Basketball Players\n");
        printf("    %-25s %-10s %-10s %-10s %-10s\n", "PLAYER", "FGA", "FGM", "FGP%", "REMARKS"); //header
        for (i = 0; i < currentRecord; ++i) {
            double FGP = computeFGP(totalPlayer[i].playerFGM, totalPlayer[i].playerFGA);
            printf("%d.) %-25s %-10d %-10d %-5.2f%%\t%-10s\n", i + 1, totalPlayer[i].playerName, //table
                   totalPlayer[i].playerFGA, totalPlayer[i].playerFGM, FGP,
                   FGP > 50.0 ? "HIGH" : "LOW");
        }
    }
}

