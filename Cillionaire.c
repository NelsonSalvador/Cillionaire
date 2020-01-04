#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MSG_QUIT "*** Sad to see you go..."
#define MSG_SAVE "Ok, your progress has been saved. See you later!"
#define MSG_ERROR_MOVE "Illegal move"

void print_menu(void);
void print_status(int, char *, int, int);
int rand_number();

int main(int argc, char **argv)
{
    int i;
    int level = 0;
    char choose;
    char name[20];
    int J50 = 1, J25 = 1;

    /*Inicialização da seed*/
    if (argc == 1)
    {
        srand(time(0));
    }
    else if (argc == 3)
    {
        srand(argv[3]);
    }
    else if (argc == 5)
    {

    }
    else
    {
        return 0;
    }
    

    print_menu();

    for (i = 1; i > 0; i++)
    {
        scanf(" %c", &choose);
        switch (choose)
        {
        case 'n':
            scanf("%s", name);
            print_status(level, name, J50, J25);
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

int rand_number()
{
    int p;
    int n = abs(3) + 1;
    p = (rand() % n) + 1;
    return p;
}

/*Imprime o menu*/
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
/*Imprime o status do jogo*/
void print_status(int level, char *name, int J50, int J25)
{
    char *j50 = "YES", *j25 = "YES";
    if (J50 == 0)
    {
        j50 = "NO";
    }

    if (J25 == 0)
    {
        j25 = "NO";
    }
    
    puts("********************************************");
    printf("*** Name:  %s                            *\n", name);
    printf("*** Level: %d                            *\n", level);
    printf("*** j50:   %s                            *\n", j50);
    printf("*** j25:   %s                            *\n", j25);
    puts("********************************************");
}