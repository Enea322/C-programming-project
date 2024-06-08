#include <stdio.h>
#include <stdlib.h>

// Function declarations
void displayMenu();
void displayBasicRules();
void displayStrategies();
void displayAdditionalTips();
void displayHelp();
void displayPlayOptions();
void displayPlayOptions();
void playAgainstComputer();
void initializeBoard(char board[6][7]);
void displayBoard(char board[6][7]);
int makeMove(char board[6][7], int col, char disc);
int checkWin(char board[6][7], char disc);
int isBoardFull(char board[6][7]);
int getComputerMove(char board[6][7]);

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPlayOptions();
                break;
            case 2:
                displayHelp();
                break;
            case 3:
                printf("Exiting the game. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

        printf("\n"); // Add a newline for better readability
    }

    return 0;
}

void displayMenu() {
    printf("Connect Four Game\n");
    printf("*****************\n");
    printf("1. Play\n");
    printf("2. Help\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}
// Some basic rules of the game
void displayBasicRules() {
    printf("\nHow to Play Connect Four:\n");
    printf("1. The game is played on a grid that's 7 columns by 6 rows.\n");
    printf("2. Players take turns dropping a disc into one of the columns.\n");
    printf("3. The disc falls to the lowest empty position within the column.\n");
    printf("4. The objective is to be the first to form a horizontal, vertical,\n");
    printf("   or diagonal line of four discs.\n");
    printf("5. The game ends when a player achieves four in a row or the board is full.\n");
    printf("6. If the board is full and no player has four in a row, the game is a draw.\n");
    printf("\nPress Enter to return to the help menu...");
    getchar();
    getchar();
}

// Gives some strategies
void displayStrategies() {
    printf("\nStrategies:\n");
    printf("1. Center Control: Focus on occupying the central columns. The middle column is\n");
    printf("   particularly valuable as it allows the most opportunities for connecting four discs.\n");
    printf("2. Blocking Opponents: Always keep an eye on your opponent's moves. If they are close\n");
    printf("   to connecting four discs, play your disc to block them.\n");
    printf("3. Plan Ahead: Think one or two moves ahead. Try to anticipate where your opponent\n");
    printf("   might be aiming to connect their discs and plan your strategy accordingly.\n");
    printf("4. Vertical vs. Horizontal: Vertical connections are often less obvious to opponents\n");
    printf("   than horizontal ones, making them harder to block. Balance your approach between\n");
    printf("   creating vertical and horizontal lines.\n");
    printf("5. Diagonal Lines: Don’t overlook the power of diagonal lines. They can be more\n");
    printf("   challenging for your opponent to spot and block.\n");
    printf("\nPress Enter to return to the help menu...");
    getchar();
    getchar();
}

// Gives some tips to help the user
void displayAdditionalTips() {
    printf("\nAdditional Tips:\n");
    printf("1. First Move Advantage: The player who goes first has a slight advantage. If you're\n");
    printf("   the first player, make the most of your opening moves by playing in the central columns.\n");
    printf("2. Avoiding Traps: Be cautious of setting up a win for your opponent while focusing on\n");
    printf("   your own strategy. Sometimes the best move is defensive.\n");
    printf("3. Practice Different Scenarios: Play against the computer or friends\n");
    printf("   to experience various game situations. This will help you recognize patterns and improve\n");
    printf("   your decision-making skills.\n");
    printf("\nPress Enter to return to the help menu...");
    getchar();
    getchar();
}

// Menu inside the Help function
void displayHelp() {
    int helpChoice;

    while (1) {
        printf("\nHelp Menu:\n");
        printf("1. Basic Rules\n");
        printf("2. Strategies\n");
        printf("3. Additional Tips\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &helpChoice);

        switch (helpChoice) {
            case 1:
                displayBasicRules();
                break;
            case 2:
                displayStrategies();
                break;
            case 3:
                displayAdditionalTips();
                break;
            case 4:
                return; // Return to main menu
            default:
                printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
        }

        printf("\n"); // Adds a newline
    }
}

// Menu inside the Play function
void displayPlayOptions() {
    int playChoice;

    while (1) {
        printf("\nPlay Menu:\n");
        printf("1. Play against another player\n");
        printf("2. Play against the computer\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &playChoice);

        switch (playChoice) {
            case 1:
                printf("You selected to play against another player.\n");
                // For now does nothing
                break;
            case 2:
                 playAgainstComputer();
                return; // After the game ends, return to the main menu
                break;
            case 3:
                return; // Return to main menu
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

        printf("\n");

    }
}

void playAgainstComputer() {
    char board[6][7];
    int playerTurn = 1; // 1 for player, 0 for computer
    int col;
    char playerDisc = 'O';
    char computerDisc = 'X';

    initializeBoard(board);

    while (1) {
        displayBoard(board);

        if (playerTurn) {
            printf("Player's turn (O). Enter column (0-6): ");
            scanf("%d", &col);

            if (col < 0 || col > 6 || !makeMove(board, col, playerDisc)) {
                printf("Invalid move. Try again.\n");
                continue;
            }
        } else {
            col = getComputerMove(board);
            printf("Computer's turn (X). It chooses column %d\n", col);
            makeMove(board, col, computerDisc);
        }

        if (checkWin(board, playerTurn ? playerDisc : computerDisc)) {
            displayBoard(board);
            printf("%s wins!\n", playerTurn ? "Player" : "Computer");
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            printf("The game is a draw!\n");
            break;
        }

        playerTurn = !playerTurn; // Switch turns
    }

    printf("\nPress Enter to return to the main menu...");
    getchar(); // Wait for user input
    getchar(); // Wait for Enter key
}

void initializeBoard(char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[6][7]) {
     system("clear"); // Clears the screen
    printf("\n 0 1 2 3 4 5 6\n");
    printf("---------------\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
        printf("---------------\n");
    }

}

int makeMove(char board[6][7], int col, char disc) {
    for (int i = 5; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = disc;
            return 1;
        }
    }
    return 0;
}

int checkWin(char board[6][7], char disc) {
    char computerDisc = 'X';
    char playerDisc = 'O';

    // Check if the computer can win in the next move
    for (int col = 0; col < 7; col++) {
        if (makeMove(board, col, computerDisc)) {
            if (checkWin(board, computerDisc)) {
                // Undo move
                for (int i = 0; i < 6; i++) {
                    if (board[i][col] == computerDisc) {
                        board[i][col] = ' ';
                        break;
                    }
                }
                return col;
            }
            // Undo move
            for (int i = 0; i < 6; i++) {
                if (board[i][col] == computerDisc) {
                    board[i][col] = ' ';
                    break;
                }
            }
        }
    }

    // Check if the player can win in the next move, and block them
    for (int col = 0; col < 7; col++) {
        if (makeMove(board, col, playerDisc)) {
            if (checkWin(board, playerDisc)) {
                // Undo move
                for (int i = 0; i < 6; i++) {
                    if (board[i][col] == playerDisc) {
                        board[i][col] = ' ';
                        break;
                    }
                }
                return col;
            }
            // Undo move
            for (int i = 0; i < 6; i++) {
                if (board[i][col] == playerDisc) {
                    board[i][col] = ' ';
                    break;
                }
            }
        }
    }

    // Try to take the center column if possible
    if (board[0][3] == ' ') {
        return 3;
    }

    // Pick the first available column (fallback)
    for (int col = 0; col < 7; col++) {
        if (board[0][col] == ' ') {
            return col;
        }
    }

    return -1; // This should never happen if the game is not a draw
}
char computerDisc = 'X';
    char playerDisc = 'O';

    // Check if the computer can win in the next move
    for (int col = 0; col < 7; col++) {
        if (makeMove(board, col, computerDisc)) {
            if (checkWin(board, computerDisc)) {
                // Undo move
                for (int i = 0; i < 6; i++) {
                    if (board[i][col] == computerDisc) {
                        board[i][col] = ' ';
                        break;
                    }
                }
                return col;
            }
            // Undo move
            for (int i = 0; i < 6; i++) {
                if (board[i][col] == computerDisc) {
                    board[i][col] = ' ';
                    break;
                }
            }
        }
    }

    // Check if the player can win in the next move, and block them
    for (int col = 0; col < 7; col++) {
        if (makeMove(board, col, playerDisc)) {
            if (checkWin(board, playerDisc)) {
                // Undo move
                for (int i = 0; i < 6; i++) {
                    if (board[i][col] == playerDisc) {
                        board[i][col] = ' ';
                        break;
                    }
                }
                return col;
            }
            // Undo move
            for (int i = 0; i < 6; i++) {
                if (board[i][col] == playerDisc) {
                    board[i][col] = ' ';
                    break;
                }
            }
        }
    }

    // Try to take the center column if possible
    if (board[0][3] == ' ') {
        return 3;
    }

    // Pick the first available column (fallback)
    for (int col = 0; col < 7; col++) {
        if (board[0][col] == ' ') {
            return col;
        }
    }

    return -1; // This should never happen if the game is not a draw
}
