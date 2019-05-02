//tic-tac-toe v1.5.2

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <synchapi.h>
#include <conio.h>

int main(void) {

    unsigned short x,y, kXwon = 0, kOwon = 0, draws = 0, move = 1;
    char choice = 'Y';

    system( "mode 46,22" );
    system("cls");
    Sleep(500);
    printf("\n\n\n\n\n\n\n\n\n\n"
           "                   Welcome!");
    Sleep(2000);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n"
           "                How to play?");
    Sleep(2000);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n"
           "          Type coordinates of field\n"
           "             to put X or O in it.");
    Sleep(5000);
    printf("\n              Enjoy playing ;)");
    Sleep(2000);

    while (choice == 'Y' || choice == 'y') {

        char a[3][3] = {
                {'_', '_', '_'},
                {'_', '_', '_'},
                {'_', '_', '_'}
        };
        unsigned short k = 0, winner = 2;

        system("cls");

        while (k < 9) {
            if (winner == 2) // check: someone won?
            {
                printf("\n             tic-tac-toe v1.5.2\n");
                printf("       atryomsth | artyom.sth@gmail.com\n\n\n");
                if (move % 2 == 1) {
                    printf("                X's turn   ");
                } else {
                    printf("                O's turn   ");
                }
                printf("       Results\n");
                printf("           ------------------     X:     %hu\n"
                       "                                  O:     %hu\n"
                       "               0    1    2        Draws: %hu\n\n", kXwon, kOwon, draws);

                for (int i = 0; i < 3; i++) // print matrix
                {
                    printf("           %d ", i);
                    for (int j = 0; j < 3; j++) {
                        printf("  %c  ", a[i][j]);
                    }
                    printf("\n\n");
                }

                printf("           ------------------\n"
                       "            Enter (x y): ");
                scanf("%hu%*c%hu", &y, &x); // scan coordinates
                printf("\n");


                if (a[x][y] == '_') // check: is move valid?
                {
                    a[x][y] = move % 2 == 1 ? 'X' : 'O';

                    move++; // switсh move queue
                    k++;
                } else {
                    system("cls");

                    printf("\n\n\n\n\n\n\n\n\n\n"
                           "               Invalid input");
                    Sleep(1500);
                    system("cls");
                }

                system("cls"); // clean terminal

                char XO[2] = {'X', 'O'};
                for (int j = 0; j < 2; j++) // winning conditionals
                {
                    for (int i = 0; i < 3; i++) {
                        if ((a[i][0] == XO[j]) && (a[i][1] == XO[j]) && (a[i][2] == XO[j])) {
                            winner = XO[j];
                            break;
                        }
                    }

                    for (int i = 0; i < 3; i++) {
                        if ((a[0][i] == XO[j]) && (a[1][i] == XO[j]) && (a[2][i] == XO[j])) {
                            winner = XO[j];
                            break;
                        }
                    }

                    if ((a[0][0] == XO[j]) && (a[1][1] == XO[j]) && (a[2][2] == XO[j])) {
                        winner = XO[j];
                        break;
                    } else if ((a[0][2] == XO[j]) && (a[1][1] == XO[j]) && (a[2][0] == XO[j])) {
                        winner = XO[j];
                        break;
                    }
                }
            } else break;
        }

        // so, who won? or draw?
        printf("\n             tic-tac-toe v1.5.2\n");
        printf("       atryomsth | artyom.sth@gmail.com\n\n\n");
        if (winner == 2) {
            printf("                  Draw");
            draws++;
        } else {
            printf("              %c is winner!", winner);
            if (winner == 'X')
            {
                kXwon++;
                move = 2;
            } else if (winner == 'O')
            {
                kOwon++;
                move = 1;
            }
        }
        printf("        Results\n");
        printf("           ------------------     X:     %hu\n"
               "                                  O:     %hu\n"
               "               0    1    2        Draws: %hu\n\n", kXwon, kOwon, draws);

        for (int i = 0; i < 3; i++) // print matrix
        {
            printf("           %d ", i);
            for (int j = 0; j < 3; j++) {
                printf("  %c  ", a[i][j]);
            }
            printf("\n\n");
        }

        printf("           ------------------\n");
        printf("\a          Play again? (Y/N): ");
        choice = getche();
        Sleep(500);
    }
    return 0;
}
