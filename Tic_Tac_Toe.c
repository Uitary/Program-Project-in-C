// Tic Tac Toe 
#include <stdio.h>
#include <stdlib.h>

#define STATS_FILE  "ttt_stats.dat"
#define SAVE_FILE   "ttt_save.dat"

typedef struct {
    int wins;
    int losses;
    int draws;
} Stats;

typedef struct {
    char board[3][3];
    int  active;   
} SavedGame;


char  board[3][3];
int   gameOver = 0;
Stats stats    = {0, 0, 0};


void resetBoard();
void displayBoard();
void playerMove();
void aiMove();
void checkWinner();
int  tryLine(char mark);

void loadStats();
void saveStats();
void printStats();

void saveGame();
void deleteSave();
int  loadGame();

void runGame();
void menu();

void resetBoard()
{
    char init[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = init[i][j];
}

void displayBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

void playerMove()
{
    int position, row, col;

    while (1)
    {
        printf("Select position (1-9): ");
        scanf("%d", &position);

        if (position < 1 || position > 9)
        {
            printf("Invalid position. Try again.\n");
            continue;
        }

        row = (position - 1) / 3;
        col = (position - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("That square is taken. Try again.\n");
            continue;
        }

        break;
    }

    board[row][col] = 'X';
}

int tryLine(char mark)
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] != 'X' && board[i][2] != 'O') { board[i][2] = 'O'; return 1; }
        if (board[i][0] == mark && board[i][2] == mark && board[i][1] != 'X' && board[i][1] != 'O') { board[i][1] = 'O'; return 1; }
        if (board[i][1] == mark && board[i][2] == mark && board[i][0] != 'X' && board[i][0] != 'O') { board[i][0] = 'O'; return 1; }
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] != 'X' && board[2][i] != 'O') { board[2][i] = 'O'; return 1; }
        if (board[0][i] == mark && board[2][i] == mark && board[1][i] != 'X' && board[1][i] != 'O') { board[1][i] = 'O'; return 1; }
        if (board[1][i] == mark && board[2][i] == mark && board[0][i] != 'X' && board[0][i] != 'O') { board[0][i] = 'O'; return 1; }
    }

    // Main diagonal
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] != 'X' && board[2][2] != 'O') { board[2][2] = 'O'; return 1; }
    if (board[0][0] == mark && board[2][2] == mark && board[1][1] != 'X' && board[1][1] != 'O') { board[1][1] = 'O'; return 1; }
    if (board[1][1] == mark && board[2][2] == mark && board[0][0] != 'X' && board[0][0] != 'O') { board[0][0] = 'O'; return 1; }

    // Anti-diagonal
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] != 'X' && board[2][0] != 'O') { board[2][0] = 'O'; return 1; }
    if (board[0][2] == mark && board[2][0] == mark && board[1][1] != 'X' && board[1][1] != 'O') { board[1][1] = 'O'; return 1; }
    if (board[1][1] == mark && board[2][0] == mark && board[0][2] != 'X' && board[0][2] != 'O') { board[0][2] = 'O'; return 1; }

    return 0;
}

void aiMove()
{
    if (tryLine('O')) return;
    if (tryLine('X')) return;
    if (board[1][1] != 'X' && board[1][1] != 'O') { board[1][1] = 'O'; return; }

    int corners[4][2] = {{0,0},{0,2},{2,0},{2,2}};
    for (int i = 0; i < 4; i++)
    {
        int r = corners[i][0], c = corners[i][1];
        if (board[r][c] != 'X' && board[r][c] != 'O') { board[r][c] = 'O'; return; }
    }

    int sides[4][2] = {{0,1},{1,0},{1,2},{2,1}};
    for (int i = 0; i < 4; i++)
    {
        int r = sides[i][0], c = sides[i][1];
        if (board[r][c] != 'X' && board[r][c] != 'O') { board[r][c] = 'O'; return; }
    }
}

void checkWinner()
{
    // Rows and columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 'X') { printf("You win!\n");  stats.wins++;   }
            else                    { printf("AI wins!\n");  stats.losses++; }
            gameOver = 1;
            return;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == 'X') { printf("You win!\n");  stats.wins++;   }
            else                    { printf("AI wins!\n");  stats.losses++; }
            gameOver = 1;
            return;
        }
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == 'X') { printf("You win!\n");  stats.wins++;   }
        else                    { printf("AI wins!\n");  stats.losses++; }
        gameOver = 1;
        return;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == 'X') { printf("You win!\n");  stats.wins++;   }
        else                    { printf("AI wins!\n");  stats.losses++; }
        gameOver = 1;
        return;
    }

    // Draw
    int empty = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                empty++;

    if (empty == 0)
    {
        printf("It's a draw!\n");
        stats.draws++;
        gameOver = 1;
    }
}

void loadStats()
{
    FILE *fp = fopen(STATS_FILE, "rb");
    if (fp == NULL)
    {
        stats.wins = stats.losses = stats.draws = 0;
        return;
    }

    fread(&stats, sizeof(Stats), 1, fp);
    fclose(fp);
}

void saveStats()
{
    FILE *fp = fopen(STATS_FILE, "wb");
    if (fp == NULL)
    {
        printf("Warning: could not save stats.\n");
        return;
    }

    fwrite(&stats, sizeof(Stats), 1, fp);
    fclose(fp);
}

void printStats()
{
    int total = stats.wins + stats.losses + stats.draws;
    printf("\n=== Your Statistics ===\n");
    printf("  Games played : %d\n", total);
    printf("  Wins         : %d\n", stats.wins);
    printf("  Losses       : %d\n", stats.losses);
    printf("  Draws        : %d\n", stats.draws);
    if (total > 0)
        printf("  Win rate     : %.1f%%\n", (stats.wins * 100.0) / total);
    printf("=======================\n\n");
}

void saveGame()
{
    FILE *fp = fopen(SAVE_FILE, "wb");
    if (fp == NULL)
    {
        printf("Warning: could not save game.\n");
        return;
    }

    SavedGame sg;
    sg.active = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            sg.board[i][j] = board[i][j];

    fwrite(&sg, sizeof(SavedGame), 1, fp);
    fclose(fp);
}

void deleteSave()
{
    remove(SAVE_FILE);
}

int loadGame()
{
    FILE *fp = fopen(SAVE_FILE, "rb");
    if (fp == NULL)
        return 0;

    SavedGame sg;
    fread(&sg, sizeof(SavedGame), 1, fp);
    fclose(fp);

    if (!sg.active)
        return 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = sg.board[i][j];

    return 1;
}

void runGame()
{
    gameOver = 0;
    displayBoard();

    while (!gameOver)
    {
        playerMove();
        saveGame();          
        displayBoard();
        checkWinner();
        if (gameOver) break;

        aiMove();
        saveGame();          
        displayBoard();
        checkWinner();
    }

    saveStats();             
    deleteSave();           
}

void menu()
{
    int choice;

    while (1)
    {
        printf("=== Tic Tac Toe ===\n");
        printf("[1] New Game\n");
        printf("[2] Resume Saved Game\n");
        printf("[3] Statistics\n");
        printf("[4] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                resetBoard();
                deleteSave();
                runGame();
                break;

            case 2:
                if (loadGame())
                {
                    printf("Resuming saved game...\n");
                    runGame();
                }
                else
                {
                    printf("No saved game found.\n\n");
                }
                break;

            case 3:
                printStats();
                break;

            case 4:
                printf("Goodbye!\n");
                return;

            default:
                printf("Invalid choice. Try again.\n\n");
        }
    }
}

int main()
{
    loadStats();
    menu();
    return 0;
}
