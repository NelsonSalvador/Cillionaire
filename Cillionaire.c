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
int print_GAME(int, char ,char *, char *, char *, char *, char *);


int main()
{
    int j, a;
    int level = 0;
    char choose;
    char name[20];
    int J50 = 1, J25 = 1;
    char frase[MAX];
    int n_questions = 0;
    int i = 0;
    int t = 0;
    int y = 0;
    char quest_d;
    char resposta_1[MAX], resposta_2[MAX], resposta_3[MAX], resposta_4[MAX], Quest[MAX];

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
        questions[i].difficulty = frase[11];
        
        i ++;
    }

    fclose(fp);

    print_menu();

    scanf(" %c", &choose);
    for (j = 1; j > 0; j++)
    {
        switch (choose)
        {
        case 'n':
            scanf(" %s", name);
            print_status(level, name, J50, J25);
            while(y == 0)
            {
                strcpy(Quest, questions[t].question);
                strcpy(resposta_1, questions[t].answers[0]);
                strcpy(resposta_2, questions[t].answers[1]);
                strcpy(resposta_3, questions[t].answers[2]);
                strcpy(resposta_4, questions[t].answers[3]);
                quest_d = questions[t].difficulty;
                y = print_GAME(level, quest_d, resposta_1, resposta_2, resposta_3, resposta_4, Quest);
                a = y;
                t ++;
            }
            y = 0;
            t = 0;
            scanf(" %c", &choose);
            if (choose == 'A')
            {
                if (a == 1)
                    printf("*** Horay!\n");
                else
                    printf("Wrong!\n");
                scanf(" %c", &choose);
            }
            else if (choose == 'B')
            {
                if (a == 2)
                    printf("*** Horay!\n");
                else
                    printf("Wrong!\n");
                scanf(" %c", &choose);
            }
            else if (choose == 'C')
            {
                if (a == 3)
                    printf("*** Horay!\n");
                else
                    printf("Wrong!\n");
                scanf(" %c", &choose);
            }
            else if (choose == 'D')
            {
                if (a == 4)
                    printf("*** Horay!\n");
                else
                    printf("Wrong!\n");
                scanf(" %c", &choose);
            }
            break;
        case 'q':
            return 0;
            break;
        case 'h':
            print_menu();
            scanf(" %c", &choose);
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
int print_GAME(int level, char quest_d, char *resposta_1, char *resposta_2, char *resposta_3, char *resposta_4, char *Quest)
{
    int p;
    char h[4][64];
    char temp[64];

    strncpy(h[0], resposta_1, 64);
    strncpy(h[1], resposta_2, 64);
    strncpy(h[2], resposta_3, 64);
    strncpy(h[3], resposta_4, 64);
    p = rand_number();

    if (level <= 1000)
    {
        if (quest_d != 'e')
        {
            return 0;
        } 
        else
        {
            strncpy(temp, h[p - 1], 64);
            strncpy(h[p - 1], h[0], 64);
            strncpy(h[0], temp, 64);
            printf("*** Question: %s", Quest);
            printf("*** A: %s", h[0]);
            printf("*** B: %s", h[1]);
            printf("*** C: %s", h[2]);
            printf("*** D: %s", h[3]);
            return p;
        }
    }
    return 0

}