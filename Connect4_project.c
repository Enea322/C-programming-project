#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Function declarations
void displayMenu();
void displayBasicRules();
void displayStrategies();
void displayAdditionalTips();
void displayHelp();
void displayPlayOptions();
void displayPlayOptions();
void playAgainstComputer();
void playAgainstPlayer();
void initializeBoard(char board[6][7]);
void displayBoard(char board[6][7]);
int makeMove(char board[6][7], int col, char disc);
int checkWin(char board[6][7], char disc);
int isBoardFull(char board[6][7]);
int getComputerMove(char board[6][7], char disc);

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            displayPlayOptions();
            break;
        case 2:
            displayHelp();
            break;
        case 3:
            system("cls");
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
    system("cls");
    printf("Connect Four Game\n");
    printf("*****************\n");
    printf("1. Play\n");
    printf("2. Help\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}
// Some basic rules of the game
void displayBasicRules() {
    system("cls");
    printf("How to Play Connect Four:\n");
    printf("*****************\n");
    printf("1. The game is played on a grid that's 7 columns by 6 rows.\n");
    printf("2. Players take turns dropping a disc into one of the columns.\n");
    printf("3. The disc falls to the lowest empty position within the column.\n");
    printf("4. The objective is to be the first to form a horizontal, vertical,\n");
    printf("   or diagonal line of four discs.\n");
    printf("5. The game ends when a player achieves four in a row or the board is full.\n");
    printf("6. If the board is full and no player has four in a row, the game is a draw.\n");
    printf("\nPress Enter to return to the help menu...");
    _getch();
}

// Gives some strategies
void displayStrategies() {
    system("cls");
    printf("Strategies:\n");
    printf("*****************\n");
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
    _getch();
}

// Gives some tips to help the user
void displayAdditionalTips() {
    system("cls");
    printf("Additional Tips:\n");
    printf("*****************\n");
    printf("1. First Move Advantage: The player who goes first has a slight advantage. If you're\n");
    printf("   the first player, make the most of your opening moves by playing in the central columns.\n");
    printf("2. Avoiding Traps: Be cautious of setting up a win for your opponent while focusing on\n");
    printf("   your own strategy. Sometimes the best move is defensive.\n");
    printf("3. Practice Different Scenarios: Play against the computer or friends\n");
    printf("   to experience various game situations. This will help you recognize patterns and improve\n");
    printf("   your decision-making skills.\n");
    printf("\nPress Enter to return to the help menu...");
    _getch();
}

// Menu inside the Help function
void displayHelp() {
    int helpChoice;

    while (1) {
        system("cls");
        printf("Help Menu:\n");
        printf("*****************\n");
        printf("1. Basic Rules\n");
        printf("2. Strategies\n");
        printf("3. Additional Tips\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf_s("%d", &helpChoice);

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
        system("cls");
        printf("Play Menu:\n");
        printf("*****************\n");
        printf("1. Play against another player\n");
        printf("2. Play against the computer\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf_s("%d", &playChoice);

        switch (playChoice) {
        case 1:
            playAgainstPlayer();
            return; // After the game ends, return to the main menu
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
        system("cls");
        displayBoard(board);

        if (playerTurn == 1) {
            printf("Player's turn (O). Enter column (0-6): ");
            scanf_s("%d", &col);

            if (col < 0 || col > 6 || !makeMove(board, col, playerDisc)) {
                printf("Invalid move. Try again.\n");
                continue;
            }
        }
        if (playerTurn == 0) {
            col = getComputerMove(board, computerDisc);
            printf("Computer's turn (X). It chooses column %d\n", col);
            makeMove(board, col, computerDisc);
            _getch();
        }

        if (checkWin(board, playerTurn ? playerDisc : computerDisc)) {
            system("cls");
            displayBoard(board);
            printf("%s wins!\n", playerTurn ? "Player" : "Computer");
            break;
        }

        if (isBoardFull(board)) {
            system("cls");
            displayBoard(board);
            printf("The game is a draw!\n");
            break;
        }
        // Switch Player to AI
        if (playerTurn == 1) {
            playerTurn = 0;
        }
        else
            if (playerTurn == 0) {
                playerTurn = 1;
            }
    }

    printf("\nPress Enter to return to the main menu...");
    _getch(); // Wait for user input
}

void playAgainstPlayer() {
    char board[6][7];
    int playerTurn = 0; // 0 for Player 1, 1 for Player 2
    int col;
    char player1Disc = 'O';
    char player2Disc = 'X';

    initializeBoard(board);

    while (1) {
        displayBoard(board);

        if (playerTurn == 0) {
            printf("Player 1's turn (O). Enter column (0-6): ");
            col = 0;
            scanf_s("%d", &col);

            if (col < 0 || col > 6 || !makeMove(board, col, player1Disc)) {
                printf("Invalid move. Try again.\n");
                continue;
            }
        }
        else if (playerTurn == 1) {
            printf("Player 2's turn (X). Enter column (0-6): ");
            col = 0;
            scanf_s("%d", &col);

            if (col < 0 || col > 6 || !makeMove(board, col, player2Disc)) {
                printf("Invalid move. Try again.\n");
                continue;
            }
        }

        if (checkWin(board, playerTurn ? player1Disc : player2Disc)) {
            system("cls");
            displayBoard(board);
            printf("%s wins!\n", playerTurn ? "Player 1" : "Player 2");
            break;
        }

        if (isBoardFull(board)) {
            system("cls");
            displayBoard(board);
            printf("The game is a draw!\n");
            break;
        }
        // Switch Players
        if (playerTurn == 0) {
            playerTurn = 1;
        }
        else if (playerTurn == 1) {
            playerTurn = 0;
        }
    }

    printf("\nPress Enter to return to the main menu...");
    scanf_s(""); // Wait for user input
}

void initializeBoard(char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[6][7]) {
    printf("\n  0   1   2   3   4   5   6 \n");
    printf("-----------------------------\n");
    for (int i = 0; i < 6; i++) {
        printf("|");
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 'O') {
                printf("\033[0;32m");
                printf(" O ");          // Prints a green 'O' for the player
                printf("\033[0m");
            }
            else
                if (board[i][j] == 'X') {
                    printf("\033[0;31m");
                    printf(" X ");          // Prints a red 'X' for the other player
                    printf("\033[0m");
                }
                else {
                    printf(" %c ", board[i][j]);
                }
            printf("|");
        }
        if (i < 5) {
            printf("\n");
        }
    }
    printf("\n-----------------------------\n");
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
    // Check horizontal
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == disc && board[i][j + 1] == disc && board[i][j + 2] == disc && board[i][j + 3] == disc) {
                return 1;
            }
        }
    }

    // Check vertical
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == disc && board[i + 1][j] == disc && board[i + 2][j] == disc && board[i + 3][j] == disc) {
                return 1;
            }
        }
    }

    // Check diagonal (bottom-left to top-right)
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == disc && board[i - 1][j + 1] == disc && board[i - 2][j + 2] == disc && board[i - 3][j + 3] == disc) {
                return 1;
            }
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == disc && board[i + 1][j + 1] == disc && board[i + 2][j + 2] == disc && board[i + 3][j + 3] == disc) {
                return 1;
            }
        }
    }

    return 0;
}

int isBoardFull(char board[6][7]) {
    for (int i = 0; i < 7; i++) {
        if (board[0][i] == ' ') {
            return 0;
        }
    }
    return 1;
}

int getComputerMove(char board[6][7], char disc) {
    // Better (but still simple) AI:

    int c = 0; //Current considered column
    int dev = 0; //Deviations from "4-in-a-row"

    // First: Chooses the first available win

    // Check horizontal
    for (int i = 5, c = 0, dev = 0; i >= 0; i--) {
        for (int j = 0; j < 4 || dev < 2; j++) {
            if (board[i][j] == ' ' || board[i][j] == disc) {
                if (board[i][j] == ' ') {
                    dev++;
                    c = j;
                }
                j++;
                for (; j < 7 && dev < 2; j++) {
                    if (board[i][j] == ' ') {
                        if (i != 5) {
                            if (board[i + 1][j] != ' ') {
                                dev++;
                                c = j;
                            }
                        }
                        else {
                            dev++;
                            c = j;
                        }
                    }
                    else if (board[i][j] != disc) {
                        dev = 2;
                    }
                    if (board[i + 1][j] == ' ') {
                        dev = 2;
                    }
                }
            }
        }
        if (dev < 2) {
            return c;
        }
    }
    // Check vertical
    for (int i = 5; i > 2; i--) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == disc && board[i - 1][j] == disc && board[i - 2][j] == disc && board[i - 3][j] == ' ') {
                return j;
            }
        }
    }
    // Check diagonal (bottom-left to top-right)
    for (int i = 5, c = 0, dev = 0; i >= 0; i--) {
        for (int j = 0; j < 4 || dev < 2; j++) {
            if (board[i][j] == ' ' || board[i][j] == disc) {
                if (board[i][j] == ' ') {
                    dev++;
                    c = j;
                }
                j++, i--;
                for (; j < 7 && dev < 2 && i >= 0; j++, i--) {
                    if (board[i][j] == ' ') {
                        if (i != 5) {
                            if (board[i + 1][j] != ' ') {
                                dev++;
                                c = j;
                            }
                        }
                        else {
                            dev++;
                            c = j;
                        }
                    }
                    else if (board[i][j] != disc) {
                        dev = 2;
                    }
                    if (board[i + 1][j] == ' ') {
                        dev = 2;
                    }

                }
            }
        }
        if (dev < 2) {
            return c;
        }
    }
    // Check diagonal (top-left to bottom-right)
    for (int i = 0, c = 0, dev = 0; i <= 5; i++) {
        for (int j = 0; j < 4 || dev < 2; j++) {
            if (board[i][j] == ' ' || board[i][j] == disc) {
                if (board[i][j] == ' ') {
                    dev++;
                    c = j;
                }
                j++, i++;
                for (; j < 7 && dev < 2 && i >= 0; j++, i++) {
                    if (board[i][j] == ' ') {
                        if (i != 5) {
                            if (board[i + 1][j] != ' ') {
                                dev++;
                                c = j;
                            }
                        }
                        else {
                            dev++;
                            c = j;
                        }
                    }
                    else if (board[i][j] != disc) {
                        dev = 2;
                    }
                    if (i + 1 != 5) {
                        if (board[i + 1][j] == ' ') {
                            dev = 2;
                        }
                    }
                }
            }
        }
        if (dev < 2) {
            return c;
        }
    }

    // Second:Prevents the players win

    // Check horizontal
    for (int i = 5, c = 0, dev = 0; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == ' ' || board[i][j] == 'O') {
                if (board[i][j] == ' ') {
                    dev++;
                    c = j;
                }
                j++;
                for (; j < 7 && dev < 2; j++) {
                    if (board[i][j] == ' ') {
                        if (i != 5) {
                            if (board[i + 1][j] != ' ') {
                                dev++;
                                c = j;
                            }
                        }
                        else {
                            dev++;
                            c = j;
                        }
                    }
                    else if (board[i][j] != 'O') {
                        dev = 2;
                    }
                    if (board[i + 1][j] == ' ') {
                        dev = 2;
                    }
                }
            }
        }
        if (dev < 2) {
            return c;
        }
    }
    // Check vertical
    for (int i = 5; i > 2; i--) {
        for (int j = 0, dev = 0; j < 7; j++) {
            if (board[i][j] == 'O' && board[i - 1][j] == 'O' && board[i - 2][j] == 'O' && board[i - 3][j] == ' ') {
                return j;
            }
        }
    }
    // Check diagonal (bottom-left to top-right)
    for (int i = 5, c = 0, dev = 0; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == ' ' || board[i][j] == 'O') {
                if (board[i][j] == ' ') {
                    dev++;
                    c = j;
                }
                j++, i--;
                for (; j < 7 && dev < 2 && i >= 0; j++, i--) {
                    if (board[i][j] == ' ') {
                        if (i != 5) {
                            if (board[i + 1][j] != ' ') {
                                dev++;
                                c = j;
                            }
                        }
                        else {
                            dev++;
                            c = j;
                        }
                    }
                    else if (board[i][j] != 'O') {
                        dev = 2;
                    }
                    if (board[i + 1][j] == ' ') {
                        dev = 2;
                    }

                }
            }
        }
        if (dev < 2) {
            return c;
        }
    }
    // Check diagonal (top-left to bottom-right)
    for (int i = 0, c = 0, dev = 0; i <= 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == ' ' || board[i][j] == 'O') {
                if (board[i][j] == ' ') {
                    dev++;
                    c = j;
                }
                j++, i++;
                for (; j < 7 && dev < 2 && i >= 0; j++, i++) {
                    if (board[i][j] == ' ') {
                        if (i != 5) {
                            if (board[i + 1][j] != ' ') {
                                dev++;
                                c = j;
                            }
                        }
                        else {
                            dev++;
                            c = j;
                        }
                    }
                    else if (board[i][j] != 'O') {
                        dev = 2;
                    }
                    if (i + 1 != 5) {
                        if (board[i + 1][j] == ' ') {
                            dev = 2;
                        }
                    }
                }
            }
        }
        if (dev < 2) {
            return c;
        }
    }

    // Third: Chooses a column

    // Tries to take the center column
    if (board[5][3] == ' ') {
        return 3;
    }
    // Chooses the first and lowest uneven column spot
    for (int i = 5; 0 <= i; i--) {
        for (int j = 0; j < 7; j++, j++) {
            if (board[i][j] == ' ') {
                return j;
            }
        }
    }
    // Chooses the first & lowest available spot (fallback)
    for (int i = 5; i >= 6; i--) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == ' ') {
                return j;
            }
        }
    }
    return -1; // This should never happen if the game is not a draw
}
