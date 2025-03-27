#include <iostream>
#include <conio.h>
#include <vector>
bool GAME_OVER, P1_TURN, CHECKED[10];
enum WINNER { P1, P2, TIE , CPU };
WINNER gameWinner;
char MAIN[5][5], GAME_MODE, INPUT, WIN;
void GAME_INIT();
void GAME_RUN();
void LOGIC();
void GAME_END();
void PRINT();
int main()
{
    std::cout << "----------TIC TAC TOE------------\n";
    std::cout << "Press 's' to start...\n";
    while (1) 
    { 
        INPUT = _getch(); 
        if (INPUT=='s') break; 
        else std::cout<<"Wrong input!\n"; 
    }
    if (INPUT == 's') 
    { 
        START:
        system("cls");
        std::cout << "---------Choose game mode-----------\n";
        std::cout << "1. Player vs CPU\n";
        std::cout << "2. Player vs Player\n";
        std::cout << "3. Quit\n";
        while (1)
        {
            GAME_MODE = _getch();
            if (GAME_MODE == '1' || GAME_MODE == '2' || GAME_MODE == '3') break;
            else std:: cout << "Wrong input!\n";
        }
        if (GAME_MODE == '3') goto END;
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
    if (GAME_MODE == '1')
    {
        if (gameWinner == P1) std::cout << "Player wins!\n";
        else if (gameWinner == CPU) std::cout << "CPU wins!\n";
        else std::cout<< "Draw!\n";
    }
    else if (GAME_MODE == '2')
    {
        if (gameWinner == P1) std::cout << "Player 1 wins!\n";
        else if (gameWinner == P2) std::cout << "Player 2 wins!\n";
        else std::cout << "Draw!\n";
    }
    std::cout << "Try again?(y/n)\n";
    while (1)
    {
        INPUT = _getch();
        if (INPUT == 'y') goto START;
        else if (INPUT == 'n') goto END;
        
        else std::cout << "Wrong input!\n";
    }
    END:
    GAME_END();
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
    if (GAME_MODE == '1')
    {
        PRINT();
        std::cout << "Your turn (1-9): ";
        while (1)
        {
            INPUT = _getch();
            if (INPUT >= '1' && INPUT <= '9' && !CHECKED[INPUT - '0']) break;
            else std::cout<<"Wrong input!\n";
        }
        switch (INPUT) //HUMAN
        {
            case '1':
                MAIN[0][0] = 'X';
                CHECKED[1] = true;
                break;
            case '2':
                MAIN[0][2] = 'X';
                CHECKED[2] = true;
                break;
            case '3':
                MAIN[0][4] = 'X';
                CHECKED[3] = true;
                break;
            case '4':
                MAIN[2][0] = 'X';
                CHECKED[4] = true;
                break;
            case '5':
                MAIN[2][2] = 'X';
                CHECKED[5] = true;
                break;
            case '6':
                MAIN[2][4] = 'X';
                CHECKED[6] = true;
                break;
            case '7':
                MAIN[4][0] = 'X';
                CHECKED[7] = true;
                break;
            case '8':
                MAIN[4][2] = 'X';
                CHECKED[8] = true;
                break;
            case '9':
                MAIN[4][4] = 'X';
                CHECKED[9] = true;
                break;
            default:
                break;
        }
        LOGIC();
        if (!GAME_OVER)
        {
            int CPU_CHOICE;
            while (true)  
            {
                CPU_CHOICE = rand() % 9 + 1; //range = max - min + 1;
                if (!CHECKED[CPU_CHOICE])
                {
                    CHECKED[CPU_CHOICE] = true;
                    break;
                }
            }
            switch (CPU_CHOICE) //CPU
            {
            case 1:
                MAIN[0][0] = 'O';
                break;
            case 2:
                MAIN[0][2] = 'O';
                break;
            case 3:
                MAIN[0][4] = 'O';
                break;
            case 4:
                MAIN[2][0] = 'O';
                break;
            case 5:
                MAIN[2][2] = 'O';
                break;
            case 6:
                MAIN[2][4] = 'O';
                break;
            case 7:
                MAIN[4][0] = 'O';
                break;
            case 8:
                MAIN[4][2] = 'O';
                break;
            case 9:
                MAIN[4][4] = 'O';
                break;
            default:
                break;
            }
        }
    }
    else if (GAME_MODE == '2')
    {
        PRINT();
        if (P1_TURN) std::cout << "Player 1's turn (1-9): ";
        else std::cout << "Player 2's turn (1-9): ";
        while (1) 
        {
            INPUT = _getch();
            if (INPUT >= '1' && INPUT <= '9' && !CHECKED[INPUT - '0']) break;
            else std::cout<< "Wrong input!\n";
        }
        switch (INPUT)
        {
            case '1':
                if (P1_TURN) MAIN[0][0] = 'X';
                else MAIN[0][0] = 'O';
                CHECKED[1] = true;
                break;
            
            case '2':
                if (P1_TURN) MAIN[0][2] = 'X';
                else MAIN[0][2] = 'O';
                CHECKED[2] = true;
                break;
            
            case '3':
                if (P1_TURN) MAIN[0][4] = 'X';
                else MAIN[0][4] = 'O';
                CHECKED[3] = true;
                break;
            
            case '4':
                if (P1_TURN) MAIN[2][0] = 'X';
                else MAIN[2][0] = 'O';
                CHECKED[4] = true;
                break;
            
            case '5':
                if (P1_TURN) MAIN[2][2] = 'X';
                else MAIN[2][2] = 'O';
                CHECKED[5] = true;
                break;
            
            case '6':
                if (P1_TURN) MAIN[2][4] = 'X';
                else MAIN[2][4] = 'O';
                CHECKED[6] = true;
                break;
            
            case '7':
                if (P1_TURN) MAIN[4][0] = 'X';
                else MAIN[4][0] = 'O';
                CHECKED[7] = true;
                break;
            
            case '8':
                if (P1_TURN) MAIN[4][2] = 'X';
                else MAIN[4][2] = 'O';
                CHECKED[8] = true;
                break;
            
            case '9':
                if (P1_TURN) MAIN[4][4] = 'X';
                else MAIN[4][4] = 'O';
                CHECKED[9] = true;
                break;
            default:
                break;
        } 
        
        P1_TURN = (P1_TURN) ? false : true;   
    }
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
    WIN = ' ';
    if (MAIN[0][0] != ' ' && MAIN[0][0] == MAIN[0][2] && MAIN[0][2] == MAIN[0][4]) WIN = MAIN[0][0];
    else if (MAIN[2][0] != ' ' && MAIN[2][0] == MAIN[2][2] && MAIN[2][2] == MAIN[2][4]) WIN = MAIN[2][0];
    else if (MAIN[4][0] != ' ' && MAIN[4][0] == MAIN[4][2] && MAIN[4][2] == MAIN[4][4]) WIN = MAIN[4][0];
    else if (MAIN[0][0] != ' ' && MAIN[0][0] == MAIN[2][0] && MAIN[2][0] == MAIN[4][0]) WIN = MAIN[0][0];
    else if (MAIN[0][2] != ' ' && MAIN[0][2] == MAIN[2][2] && MAIN[2][2] == MAIN[4][2]) WIN = MAIN[0][2];
    else if (MAIN[0][4] != ' ' && MAIN[0][4] == MAIN[2][4] && MAIN[2][4] == MAIN[4][4]) WIN = MAIN[0][4];
    else if (MAIN[0][0] != ' ' && MAIN[0][0] == MAIN[2][2] && MAIN[2][2] == MAIN[4][4]) WIN = MAIN[0][0];
    else if (MAIN[0][4] != ' ' && MAIN[0][4] == MAIN[2][2] && MAIN[2][2] == MAIN[4][0]) WIN  = MAIN[0][4];

    if (WIN != ' ') {// Winner found     
        if (GAME_MODE == '1') gameWinner = (WIN == 'X') ? P1 : CPU;
        else if (GAME_MODE == '2') gameWinner = (WIN == 'X') ? P1 : P2;  
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