#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

char makan[9] = {'1','2','3','4','5','6','7','8','9'};

void Color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void print_table() {
    printf("        |        |        \n");

    for (int i = 0; i < 9; i++) {
        if (makan[i] == 'X') {
            Color(12);
        } else if (makan[i] == 'O') {
            Color(9); 
        } else {
            Color(15);
        }
        printf("   %c    ", makan[i]);

        Color(15);
        if (i % 3 != 2) printf("|");
        else printf("\n        |        |        \n");

        if (i == 2 || i == 5) printf("--------------------------\n");
    }
}

char winer() {
    if (makan[0] == makan[1] && makan[1] == makan[2]) return makan[0];
    if (makan[3] == makan[4] && makan[4] == makan[5]) return makan[3];
    if (makan[6] == makan[7] && makan[7] == makan[8]) return makan[6];
    if (makan[0] == makan[3] && makan[3] == makan[6]) return makan[0];
    if (makan[1] == makan[4] && makan[4] == makan[7]) return makan[1];
    if (makan[2] == makan[5] && makan[5] == makan[8]) return makan[2];
    if (makan[0] == makan[4] && makan[4] == makan[8]) return makan[0];
    if (makan[2] == makan[4] && makan[4] == makan[6]) return makan[2];

    bool mosavi = true;
    for (int i = 0; i <= 8; i++) {
        if (makan[i] != 'X' && makan[i] != 'O') {
            mosavi = false;
            break;
        }
    }
    if (mosavi) return 'D';
    return ' ';
}
void seda(int frequency, int duration) {
        Beep(frequency, duration);
}


void pc() {
    for (int i = 0; i <= 8; i++) {
        if (makan[i] != 'X' && makan[i] != 'O') {
            char temp = makan[i];
            makan[i] = 'O';
            if (winer() == 'O') {
                seda(800, 300);
                return;
            }
            makan[i] = temp;
        }
    }
    for (int i = 0; i <= 8; i++) {
        if (makan[i] != 'X' && makan[i] != 'O') {
            char temp = makan[i];
            makan[i] = 'X';
            if (winer() == 'X') {
                makan[i] = 'O';
                seda(800, 300);
                return;
            }
            makan[i] = temp;
        }
    }
    if (makan[4] != 'X' && makan[4] != 'O') {
        makan[4] = 'O';
        seda(800, 300);
        return;
    }
    if (makan[0] != 'X' && makan[0] != 'O') {
        makan[0] = 'O';
        seda(800, 300);
        return;
    }
    if (makan[2] != 'X' && makan[2] != 'O') {
        makan[2] = 'O';
        seda(800, 300);
        return;
    }
    if (makan[6] != 'X' && makan[6] != 'O') {
        makan[6] = 'O';
        seda(800, 300);
        return;
    }
    if (makan[8] != 'X' && makan[8] != 'O') {
        makan[8] = 'O';
        seda(800, 300);
        return;
    }
    for (int i = 0; i <= 8; i++) {
        if (makan[i] != 'X' && makan[i] != 'O') {
            makan[i] = 'O';
            seda(800, 300);
            return;
        }
    }
}


int main() {

    int daryaft;
    char nobat = 'X';
    print_table();
    printf("Enter number between 1-9\n");
    printf("You=>X\nPC=>O\n");

    while (1) {
        if (nobat == 'X') {
            while (1) {
                printf("your turn\n");
                scanf("%d", &daryaft);
                if (daryaft >= 1 && daryaft <= 9 && makan[daryaft - 1] != 'X' && makan[daryaft - 1] != 'O') {
                    daryaft--;
                    makan[daryaft] = 'X';
                    seda(600, 300);
                    nobat = 'O';
                    break;
                }
                printf("wrong move please try again...\n");
            }
        } else {
            pc();
            nobat = 'X';
        }

        system("cls");
        print_table();

        char result = winer();
        if (result != ' ') {
            if (result == 'D') {
                printf("Draw\n");
            } else {
                printf("winner is %c\n", result);
            }
            break;
        }
    }

    getche();
    return 0;
}