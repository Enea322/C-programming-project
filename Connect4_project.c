#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Connect Four Game\n");
    printf("*****************\n");
    printf("1. Play\n");
    printf("2. Help\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        // Below is the menu, this are the options for now

        switch (choice) {
            case 1:
                printf("You selected Play.\n");
                // This does nothing for now
                break;
            case 2:
                printf("You selected Help.\n");
                // This does nothing for now
                break;
            case 3:
                printf("Exiting the game. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

        printf("\n");
            
    }

    return 0;
}
