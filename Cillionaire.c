#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define MSG_QUIT "*** Sad to see you go..."
#define MSG_SAVE "Ok, your progress has been saved. See you later!"
#define MSG_ERROR_MOVE "Illegal move"
#define MAX 256

void print_menu(void);
void print_status(int, char *, int, int);
int rand_number();
int print_GAME(int, char ,char *, char *, char *, char *, char *, char *);
int answer_return(int, char, int);


int main(int argc, char **argv)
{
    int j, a, c;
    int level[9] = {0, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000};
    char choose;
    char name[20];
    char fname[20];
    char rname[20];
    int J50 = 1, J25 = 1;
    char frase[MAX];
    int n_questions = 0;
    char open[64];
    int i = 0;
    int t = 0;
    int y = 0;
    int l = 0;
    char quest_d;
    char resposta_1[MAX], resposta_2[MAX], resposta_3[MAX], resposta_4[MAX], Quest[MAX];

    /*Inicialização da seed*/
    if (argc > 5)
    {
        printf("To many arguments!\n");
    }
    else if (argc == 2 || argc == 4)
    {
        printf("Not enough arguments!\n");
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "-s") == 0)
        {
            srand(atoi(argv[2]));
            strcpy(open, "Perguntas.ini");
        }
            
        else if (strcmp(argv[1], "-f") == 0)
        {
            strcpy(open, argv[2]);
            srand(time(0));
        }
    }
    else if (argc == 5)
    {
        if (strcmp(argv[1], "-s") == 0)
        {
            srand(atoi(argv[2]));
            strcpy(open, argv[4]);
        }
            
        else if (strcmp(argv[1], "-f") == 0)
        {
            strcpy(open, argv[2]);
            srand(atoi(argv[4]));
        }
    }
    else
    {
        print_menu();
        printf(">");
        puts(MSG_QUIT);
        return 0;
    }///Abertura e leitura do ficheiro de perguntas para a memoria dinamica
    typedef struct {
        char question[256];
        char answers[4][64];
        char cattegory[128];
        char difficulty;
    }pergunta;
    
    pergunta * questions = NULL;
    FILE * fp;
    fp = fopen(open, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Erro ao abrir o ficheiro.txt\n");
        return 0;
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
    printf(">");
    scanf("%c", &choose);
    ///ciclo infinito para as opcões do menu
    for (j = 1; j > 0; j++)
    {
        switch (choose)
        {
        case 'n':
            scanf("%s", name);
            printf("***Hi %s, let's get started!\n", name);
            while (j > 0)
            {
                print_status(level[l], name, J50, J25);
            // Ciclo para verificação se a pergunta corresponde ao nivel certo, caso esteja quebra o ciclo
            while(y == 0)
            {
                strcpy(Quest, questions[t].question);
                strcpy(resposta_1, questions[t].answers[0]);
                strcpy(resposta_2, questions[t].answers[1]);
                strcpy(resposta_3, questions[t].answers[2]);
                strcpy(resposta_4, questions[t].answers[3]);
                quest_d = questions[t].difficulty;
                y = print_GAME(level[l], quest_d, resposta_1, resposta_2, resposta_3, resposta_4, Quest, name);
                a = y;
                t ++;
            }

            printf(">");
            scanf(" %c", &choose);
            //Elemina a pergunta da memória dinamica
            for (c = t - 1; c < n_questions; c++)
                questions[c] = questions[c+1];

            y = 0;
            t = 0;
            if (choose == 'j')
            {

            }
            //Quebra o Ciclo 
            if (choose != 'A' && choose != 'B' && choose != 'C' && choose != 'D')
                break;
            l = answer_return(a, choose, l);
            }

            break;
        case 'q':
            puts(MSG_QUIT);
            return 0;
            break;
        case 'h':
            print_menu();
            printf(">");
            scanf(" %c", &choose);
            break;
        case 'r':
            scanf("%s", rname);
            FILE *rf;
            rf = fopen(rname, "r");
            if (rf == NULL)
            {
                fprintf(stderr, "Erro ao abrir o ficheiro.txt\n");
                return 0;
            }
            fgets(frase, MAX, rf);
            strcpy(name, &frase[0]);

            ///fgets(l, MAX, rf);

            ///fgets(J25, MAX, rf);

            ///fgets(J50, MAX, rf);

            fclose(rf);
            printf(">");
            scanf(" %c", &choose);

            break;
        case 's':
        //cria um ficheiro com e guarda a informação la 
            scanf("%s", fname);
            FILE *f;
            f = fopen(fname, "w");
            if (f == NULL)
            {
                fprintf(stderr, "Erro ao abrir o ficheiro.txt\n");
                return 0;
            }
            fprintf(f, "%s\n", name);
            fprintf(f, "%d\n", l);
            fprintf(f, "%d\n", J25);
            fprintf(f, "%d\n", J50);
            fclose(f);
            printf("Ok, your progress has been saved. See you later!\n");
            return 0;
            break;
        case 'c':
            printf("Creator: Nelson Salvador - 21904295\n");
            scanf(" %c", &choose);
            break;
        default:
            break;
        }
    }
}
// gera um numero aleatório entre 0 e 3
int rand_number()
{
    int p;
    int n = abs(3);
    p = (rand() % n);
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
    printf("*** Name:  %s                           *\n", name);
    printf("*** Level: %d                               *\n", level);
    printf("*** j50:   %s                             *\n", j50);
    printf("*** j25:   %s                             *\n", j25);
    puts("********************************************");
}
int print_GAME(int level, char quest_d, char *resposta_1, char *resposta_2, char *resposta_3, char *resposta_4, char *Quest, char *name)
{
    int p;
    char h[4][64];
    char temp[64];

    strncpy(h[0], resposta_1, 64);
    strncpy(h[1], resposta_2, 64);
    strncpy(h[2], resposta_3, 64);
    strncpy(h[3], resposta_4, 64);
    p = rand_number();
    //imprime as perguntas, baralhadas, conforme o nivel do jogado 
    if (level <= 1000)
    {
        if (quest_d != 'e')
        {
            return 0;
        } 
        else
        {
            strncpy(temp, h[p], 64);
            strncpy(h[p], h[0], 64);
            strncpy(h[0], temp, 64);
            printf("*** Question: %s", Quest);
            printf("*** A: %s", h[0]);
            printf("*** B: %s", h[1]);
            printf("*** C: %s", h[2]);
            printf("*** D: %s", h[3]);
            
            return p + 1;
        }
    }
    else if (level == 2000 || level == 5000)
    {
        if (quest_d != 'm')
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
            
            return p + 1;
        }
    }
    else if (level == 10000 || level == 20000 || level == 50000)
    {
        if (quest_d != 'h')
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
            
            return p + 1;
        }
    }
    else if (level == 100000)
    {
        printf("This is incredible! You have won!\n");
        printf("Congratulations %s!\n", name);
        return 0;
    }
    return 0;
}
// Verifica se a resposta do jogado está correta
int answer_return(int a, char choose, int l)
{
    if (choose == 'A')
    {
        if (a == 1)
        {
            printf("*** Hooray!\n");
            return l + 1;
        }
        else
        {
            printf("***Wrong!\n");
            if (l != 0)
                return l - 1;
            return l;
        }
    }
    else if (choose == 'B')
    {
        if (a == 2)
        {
            printf("*** Hooray!\n");
            return l + 1;
        }
        else
        {
            printf("***Wrong!\n");
            if (l != 0)
                return l - 1;
            return l;
        }
            
    }
    else if (choose == 'C')
    {
        if (a == 3)
        {
            printf("*** Hooray!\n");
            return l + 1;
        }
            
        else
        {
            printf("***Wrong!\n");
            if (l != 0)
                return l - 1;
            return l;
        }
            
    }
    else if (choose == 'D')
    {
        if (a == 4)
        {
            printf("*** Hooray!\n");
            return l + 1;
        }
            
        else
        {
            printf("***Wrong!\n");
            if (l != 0)
                return l - 1;
            return l;
        }
            
    }
    else
    {
        return l;
    }
    
}