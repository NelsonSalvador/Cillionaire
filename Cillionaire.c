#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define MSG_QUIT "*** Sad to see you go..."
#define MSG_SAVE "Ok, your progress has been saved. See you later!"
#define MSG_ERROR_MOVE "Illegal move"
#define MAX 128

void print_menu(void);
void print_status(int, char *, int, int);
int rand_number();


int main()
{
    int j;
    int level = 0;
    char choose;
    char name[20];
    int J50 = 1, J25 = 1;
    char frase[MAX];
    int n_questions = 0;
    int i = 0;
    int t = 3;

    /*Inicialização da seed
    if (argc == 1)
    {
        srand(time(0));
    }
    else if (argc == 3)
    {
        srand(argv[2]);
    }
    else if (argc == 5)
    {

    }
    else
    {
        return 0;
    }*/
    typedef struct {
        char question[128];
        char answers[4][64];
        char cattegory[128];
        char difficulty;
    }pergunta;
    
    pergunta * questions = NULL;
    FILE * fp;
    fp = fopen("Perguntas.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Erro ao abrir o ficheiro.txt\n");
        return 1;
    }
    while(fgets(frase, MAX, fp) != NULL)
    {
        if (frase[0] == ';')
            continue;
        fgets(frase, MAX, fp);
        fgets(frase, MAX, fp);
        fgets(frase, MAX, fp);
        fgets(frase, MAX, fp);
        fgets(frase, MAX, fp);
        fgets(frase, MAX, fp);
        n_questions ++;
    }
    questions = (pergunta *) calloc(n_questions, sizeof(pergunta));
    
    fseek (fp, 0, SEEK_SET);
    while(fgets(frase, MAX, fp) != NULL)
    {
        if (frase[0] == ';')
            continue;

        strcpy(questions[i].question, &frase[9]);

        fgets(frase, MAX, fp);
        strcpy(questions[i].answers[0], &frase[8]);

        fgets(frase, MAX, fp);
        strcpy(questions[i].answers[1], &frase[8]);

        fgets(frase, MAX, fp);
        strcpy(questions[i].answers[2], &frase[8]);

        fgets(frase, MAX, fp);
        strcpy(questions[i].answers[3], &frase[8]);

        fgets(frase, MAX, fp);
        strcpy(questions[i].cattegory, &frase[9]);

        fgets(frase, MAX, fp);
        if (strcmp(frase, "DIFFICULTY=easy\n") == 0)
            questions[i].difficulty = 'e';
        else if (strcmp(frase, "DIFFICULTY=medium\n") == 0)
            questions[i].difficulty = 'm';
        else
        {
            questions[i].difficulty = 'h';
        }
        
        i ++;
    }

    fclose(fp);

    print_menu();

    for (j = 1; j > 0; j++)
    {
        scanf(" %c", &choose);
        switch (choose)
        {
        case 'n':
            scanf("%s", name);
            print_status(level, name, J50, J25);
            
            printf("*** Question: %s", questions[t].question);
            printf("*** OP 1: %s", questions[t].answers[0]);
            printf("*** OP 2: %s", questions[t].answers[1]);
            printf("*** OP 3: %s", questions[t].answers[2]);
            printf("*** OP 4: %s", questions[t].answers[3]);
            printf("*** Cat: %s", questions[t].cattegory);
            printf("*** def: %c\n", questions[t].difficulty);
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