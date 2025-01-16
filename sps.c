#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printChoice(int choice) {
    if (choice == 0) {
        printf("Stone");
    } else if (choice == 1) {
        printf("Paper");
    } else {
        printf("Scissors");
    }
}

int main() {
    int userChoice, computerChoice;
    char playAgain;

    // Seed the random number generator
    srand(time(0));

    printf("Welcome to the Stone, Paper, Scissors Game!\n");

    do {
        printf("\nEnter your choice:\n");
        printf("0: Stone\n1: Paper\n2: Scissors\n");
        printf("Your choice: ");
        scanf("%d", &userChoice);

        if (userChoice < 0 || userChoice > 2) {
            printf("Invalid choice! Please choose 0, 1, or 2.\n");
            continue;
        }

        // Generate computer choice
        computerChoice = rand() % 3;

        printf("\nYou chose: ");
        printChoice(userChoice);
        printf("\nComputer chose: ");
        printChoice(computerChoice);
        printf("\n");

        // Determine the winner
        if (userChoice == computerChoice) {
            printf("It's a draw!\n");
        } else if ((userChoice == 0 && computerChoice == 2) ||
                   (userChoice == 1 && computerChoice == 0) ||
                   (userChoice == 2 && computerChoice == 1)) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThank you for playing!\n");
    return 0;
}
