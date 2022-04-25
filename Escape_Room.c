#include <stdio.h>
#include <stdlib.h>
#include<time.h> 
#include<ncurses.h> 
#include<string.h>
#define SIZE 20

char mapa[10][18] =
{
    "11111111111111111",
    "10100000000000001",
    "10000011110000001",
    "10101000111111101",
    "10010100111111101",
    "10110000000000001",
    "10111000000000001",
    "10011100110000001",
    "10100000110000001",
    "11111111111111111",
};




int pohyb_p;
int xp_pozicia = 1;
int yp_pozicia = 1;


/*farby*/
void red() {
    printf("\033[1;31m");
}
void green() {
    printf("\033[0;32m");
}
void yellow() {
    printf("\033[0;33m");
}
void blue() {
    printf("\033[0;34m");
}
void magenta() {
    printf("\033[0;35m");
}
void white() {
    printf("\033[0m");
}


void setUsername(char *user)
{
char buffer[SIZE];
strcpy(buffer, user);
}


int main()
{
    
    int x, y;
    int* x_ptr = &xp_pozicia;
    int* y_ptr = &yp_pozicia;
    char postava = { 'x' };
    char user[SIZE];

    printf("Zadajte meno uzivatela:");
    scanf("%s", user);
    setUsername(user);
    
    /*umiestnenie otázky*/
    srand(time(0));
    int n = rand() % 3;
    char question = mapa[n + 6][n + 4] =  '?';

    /*Vyplnenie mapy*/
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 18; y++)
        {
            if (mapa[x][y] == '0')
                mapa[x][y] = '.';

            else if (mapa[x][y] == '1')
            {
                mapa[x][y] = '#';
            }

        }

    }

    void (*farby[7])() = { red,green,yellow,blue,magenta,white };
    char player = mapa[yp_pozicia][xp_pozicia] = postava;
    /*Vytvorenie mapy*/
    do
    {

        printf("Hello %s, Welcome in Escape Room! \n", user);
        printf("Movement: WASD \n");

        for (x = 0; x < 10; x++)
        {
            printf("\n \t");
            for (y = 0; y < 18; y++)
            {

                printf("%c", mapa[x][y]);
                if (mapa[x][y + 1] == mapa[yp_pozicia][xp_pozicia])
                {
                    farby[1]();
                }
                else if (mapa[x][y + 1] == mapa[n + 6][n + 4]) {
                    farby[0]();
                }

                else { farby[5](); }
            }
        }

	printf("\n \t");
	initscr();
	noecho();
	raw();
        int pohyb_p = getch();
	endwin();
        switch (pohyb_p)
        {
        case 119:
            if (mapa[yp_pozicia - 1][xp_pozicia] == '#')
            {
                player = mapa[yp_pozicia][xp_pozicia] = postava;
                mapa[yp_pozicia - 1][xp_pozicia] =  '#';
            }
            else
            {
                mapa[yp_pozicia][xp_pozicia] = '.';
                player = mapa[yp_pozicia - 1][xp_pozicia] = postava;
                (*y_ptr)--;
            }
            break;

        case 115:
            if (mapa[yp_pozicia + 1][xp_pozicia] == '#')
            {
                player = mapa[yp_pozicia][xp_pozicia] = postava;
                mapa[yp_pozicia + 1][xp_pozicia] = '#';
            }
            else
            {
                mapa[yp_pozicia][xp_pozicia] = '.';
                player = mapa[yp_pozicia + 1][xp_pozicia] = postava;
                (*y_ptr)++;
            }
            break;
        case 100:
            if (player = mapa[yp_pozicia][xp_pozicia + 1] == '#')
            {
                player = mapa[yp_pozicia][xp_pozicia] = postava;
                mapa[yp_pozicia][xp_pozicia + 1] = '#';
            }
            else
            {
                mapa[yp_pozicia][xp_pozicia] = '.';
                player = mapa[yp_pozicia][xp_pozicia + 1] = postava;
                (*x_ptr)++;
            }
            break;
        case 97:
            if (mapa[yp_pozicia][xp_pozicia - 1] == '#')
            {
                player = mapa[yp_pozicia][xp_pozicia] = postava;
                mapa[yp_pozicia][xp_pozicia - 1] = '#';
            }
            else
            {
                mapa[yp_pozicia][xp_pozicia] = '.';
                player = mapa[yp_pozicia][xp_pozicia - 1] = postava;
                (*x_ptr)--;
            }
            break;
        }


        system("clear");


    } while (mapa[yp_pozicia][xp_pozicia] != mapa[n + 6][n + 4]);


	
	return 0; 
}

