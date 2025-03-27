#include <iostream>
#include <conio.h>
#include <vector>
bool GAME_OVER;
bool P1_TURN;
enum WINNER { P1, P2, TIE };
WINNER gameWinner;
char MAIN[5][5]; 
bool CHECKED[10];
void GAME_INIT();
void GAME_RUN();
void LOGIC();
void GAME_END();
void PRINT();
int main()
{
    std::cout << "----------TIC TAC TOE------------\n";
    std::cout << "Press 's' to start...\n";
    if (_getch() == 's') 
    { 
        START:
        system("cls");
        GAME_INIT();
        while (!GAME_OVER)
        {
            GAME_RUN();
            LOGIC();
            system("cls");
        }
    }
    PRINT();
    if (gameWinner == P1) std::cout << "Player 1 wins!\n";
    else if (gameWinner == P2) std::cout << "Player 2 wins!\n";
    else std::cout << "Draw!\n";

    std::cout << "Try again?(y/n)\n";
    if (_getch() == 'y') goto START;
    else if (_getch() == 'n') GAME_END();

    system("pause");
    return 0;
}
void PRINT()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) 
        {
            std::cout << MAIN[i][j];
        }
        std::cout << '\n';
    }
}
void GAME_INIT()
{
    
    for (int i = 1; i <= 9; i++) CHECKED[i] = false;
    GAME_OVER = false;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) 
        {
            if (i % 2 == 1) MAIN[i][j] = '-';
            else if (i % 2 == 0 && j % 2 == 0) MAIN[i][j] = ' ';
            else MAIN[i][j] = '|';
        }
    }
    P1_TURN = true;
}
void GAME_RUN()
{
    PRINT();
    if (P1_TURN) std::cout << "Player 1's turn (1-9): ";
    else std::cout << "Player 2's turn (1-9): ";

    char index = _getch();
    bool VALID_CHOICE = false;
    switch (index)
    {
        case '1':
            if (!CHECKED[1])
            {
                if (P1_TURN) MAIN[0][0] = 'X';
                else MAIN[0][0] = 'O';
                CHECKED[1] = true;
            }
            else VALID_CHOICE = true;
            break;
        
        case '2':
            if (!CHECKED[2])
            {
                if (P1_TURN) MAIN[0][2] = 'X';
                else MAIN[0][2] = 'O';
                CHECKED[2] = true;
            }
            else VALID_CHOICE = true;
            break;
        
        case '3':
            if (!CHECKED[3])
            {
                if (P1_TURN) MAIN[0][4] = 'X';
                else MAIN[0][4] = 'O';
                CHECKED[3] = true;
            }
            else VALID_CHOICE = true;
            break;
        
        case '4':
            if (!CHECKED[4])
            {
                if (P1_TURN) MAIN[2][0] = 'X';
                else MAIN[2][0] = 'O';
                CHECKED[4] = true;
            }
            else VALID_CHOICE = true;
            break;
        
        case '5':
            if (!CHECKED[5])
            {
                if (P1_TURN) MAIN[2][2] = 'X';
                else MAIN[2][2] = 'O';
                CHECKED[5] = true;
            }
            else VALID_CHOICE = true;
            break;
        
        case '6':
            if (!CHECKED[6])
            {
                if (P1_TURN) MAIN[2][4] = 'X';
                else MAIN[2][4] = 'O';
                CHECKED[6] = true;
            }
            else VALID_CHOICE = true;
            break;
        
        case '7':
            if (!CHECKED[7])
            {
                if (P1_TURN) MAIN[4][0] = 'X';
                else MAIN[4][0] = 'O';
                CHECKED[7] = true;
            }
            else VALID_CHOICE = true;
            break;
        
        case '8':
            if (!CHECKED[8])
            {
                if (P1_TURN) MAIN[4][2] = 'X';
                else MAIN[4][2] = 'O';
                CHECKED[8] = true;
            } 
            else VALID_CHOICE = true;
            break;
        
        case '9':
            if (!CHECKED[9])
            {
                if (P1_TURN) MAIN[4][4] = 'X';
                else MAIN[4][4] = 'O';
                CHECKED[9] = true;
            }
            else VALID_CHOICE = true;
            break;
        default:
            VALID_CHOICE = true;
            break;
    } 
    
    if (!VALID_CHOICE) P1_TURN = (P1_TURN) ? false : true;
}
bool ALL_CHECK()
{
    for (int i = 1; i < 10; i++) {
        if (!CHECKED[i]) return false;
    }
    return true;
}
void LOGIC() 
{
    char winner = ' ';
    if (MAIN[0][0] != ' ' && MAIN[0][0] == MAIN[0][2] && MAIN[0][2] == MAIN[0][4]) winner = MAIN[0][0];
    else if (MAIN[2][0] != ' ' && MAIN[2][0] == MAIN[2][2] && MAIN[2][2] == MAIN[2][4]) winner = MAIN[2][0];
    else if (MAIN[4][0] != ' ' && MAIN[4][0] == MAIN[4][2] && MAIN[4][2] == MAIN[4][4]) winner = MAIN[4][0];
    else if (MAIN[0][0] != ' ' && MAIN[0][0] == MAIN[2][0] && MAIN[2][0] == MAIN[4][0]) winner = MAIN[0][0];
    else if (MAIN[0][2] != ' ' && MAIN[0][2] == MAIN[2][2] && MAIN[2][2] == MAIN[4][2]) winner = MAIN[0][2];
    else if (MAIN[0][4] != ' ' && MAIN[0][4] == MAIN[2][4] && MAIN[2][4] == MAIN[4][4]) winner = MAIN[0][4];
    else if (MAIN[0][0] != ' ' && MAIN[0][0] == MAIN[2][2] && MAIN[2][2] == MAIN[4][4]) winner = MAIN[0][0];
    else if (MAIN[0][4] != ' ' && MAIN[0][4] == MAIN[2][2] && MAIN[2][2] == MAIN[4][0]) winner  = MAIN[0][4];

    if (winner != ' ') {
        gameWinner = (winner == 'X') ? P1 : P2; // Winner found      
        GAME_OVER = true;
    }
    else {
        if (ALL_CHECK()) {
            gameWinner = TIE;
            GAME_OVER  = true;
        }
    }

}
void GAME_END() 
{
    std::cout << "\nThank you!\n";
}