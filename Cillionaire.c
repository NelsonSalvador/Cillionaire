#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MSG_QUIT "*** Sad to see you go..."
#define MSG_SAVE "Ok, your progress has been saved. See you later!"
#define MSG_ERROR_MOVE "Illegal move"

void print_menu(void);

int main()
{
    int i;
    char choose;
    print_menu();
    for (i = 1; i > 0; i++)
    {
        scanf("%c", &choose);
        switch (choose)
        {
        case 'n':
            
            break;
        case 'q':
            return 0;
            break;
        case 'h':
            print_menu();
            break;
        case 'r':

            break;
        case 's':
        
            break;
        
        default:
            break;
        }
    }
}

void print_menu(void)
{
    puts("********************************************");
    puts("***            CILLIONAIRE                 *");
    puts("********************************************");
    puts("*** n <name>     - new game                *");
    puts("*** q            - quit                    *");
    puts("*** h            - show this menu          *");
    puts("*** r <filename> - resume game             *");
    puts("*** s <filename> - save progress and quit  *");
    puts("*** j 50         - play 50:50 joker        *");
    puts("*** j 25         - play 25:75 joker        *");
    puts("*** c            - show credits            *");
    puts("********************************************");
}