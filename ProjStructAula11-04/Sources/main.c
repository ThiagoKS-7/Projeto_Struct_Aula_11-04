#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//numero de students
#define TAM 2
//capacidade maxima do atributo
#define LEN 200
//porcentagem A1
#define PORC_A1 0.2
//porcentagem A2
#define PORC_A2 0.3
//porcentagem A3
#define PORC_A3 0.5
//nota de corte para aprovação
#define PASSING_SCORE 7



//DEFINIR STRUCT ANTES DAS FUNÇÕES
//Struct com name, email,registration e notas
typedef struct {
    char **name[50];
    char **email[100];
    int registration;
    float A1;
    float A2;
    float A3;
    int average;
} Student;




 //calcula a média aritmética de 3 notas
float arithmeticAverage (float A1, float A2, float A3, float average) {
     float grade1, grade2,grade3;
     grade1 = PORC_A1 * A1;
     grade2 = PORC_A2 * A2;
     grade3 = PORC_A3 * A3;
     average = (grade1 + grade2 + grade3);

     printf("Media: %.2f\n", average);
     return average;
 }

//pergunta campos e "cadastra" eles num dos students da struct
void registerStudent(Student students[LEN]) {
     for ( int pos = 0; pos < TAM; pos ++) {
        printf("Informe o campo nome %d: ", pos + 1);
        scanf("%s", &students[pos].name);
        printf("Informe o campo email %d: ", pos + 1);
        scanf("%s", &students[pos].email);
        printf("Informe o campo matricula %d: ", pos + 1);
        scanf("%d", &students[pos].registration);
        printf("Informe o campo A1 %d: ", pos + 1);
        scanf("%f", &students[pos].A1);
        printf("Informe o campo A2 %d: ", pos + 1);
        scanf("%f", &students[pos].A2);
        printf("Informe o campo A3 %d: ", pos + 1);
        scanf("%f", &students[pos].A3);
        printf("----------------------------\n");
        printf("CADASTRO REALIZADO COM SUCESSO!\n");
        printf("----------------------------\n\n");
    }
}

//checa se o aluno foi aprovado ou não
void checkApproval(float average) {
    if (average >= 7) {
        printf("Aprovado: Sim\n");
    } else {
        printf("Aprovado: Nao\n");
    }
}

//lista todos os campos de cada indice da struct
void listStudents(Student students[LEN]) {
    printf("\n");
    for( int x = 0; x < TAM; x++) {
        if (students[x].registration != -1) {
            printf("(%d)\nNome: %s\nEmail: %s\nMatricula: %d\n",x, students[x].name, 
                students[x].email, students[x].registration);
            students[x].average = arithmeticAverage (students[x].A1,students[x].A2,students[x].A3, students[x].average);
            checkApproval(students[x].average);
            printf("----------------------------\n");
        }
    }
    printf("\n");
}

//mostra um menu na tela e pede uma opção pra o usuario. Se o 
// valor não estiver entre 0 e 3, repete o código
int mainMenu(int opt) {
    printf("Menu Principal\n");
    printf("==============\n");
    printf("1. cadastrar alunos\n");
    printf("2. listar alunos\n");
    printf("3. excluir aluno\n");
    printf("0. sair\n\n");
    //atribui o valor 0 pra variavel opt
    opt = 0;
    do {
        printf("informe opcao desejada: ");
        scanf("%i", &opt);
    } while (opt < 0 || opt > 3);
    
    return opt;
}

// como o name sugere, limpa a tela
void clearMonitor() {
    printf("\e[1;1H\e[2J");
}

// limpa todos os campos registration
void clearRegistration(Student students[LEN]) {
    for (int i = 0 ; i < TAM; i++){
        students[i].registration = -1;
    }
 }


//limpa todos os campos de um aluno específico
//por checar na listagem se a matricula vale -1, não obriga a limpar o nome e o email
void removeStudent(Student students[LEN]) {
    int i = -1;
    printf("Indique a posicao do array que quer alterar: ");
    scanf("%d", &i);
    students[i].registration = -1;
    students[i].A1 = -1;
    students[i].A2 = -1;
    students[i].A3 = -1;
    printf("----------------------------\n");
    printf("EXCLUSAO REALIZADA COM SUCESSO!\n");
    printf("----------------------------\n\n");
 }



int main() {
    // delcarando uma variavel students com tamanho TAM (students[TAM])
    Student* students = malloc(TAM * sizeof *students);
    // declarando variáveis
    int opt;

    //limpa matricula
    clearRegistration(students);
    //limpa tela
    clearMonitor();

    //enquanto a opção for diferente de "sair" (0)
    while (opt != 0) {
        // atribui a variavel opt o valor retornado pela func mainMenu
        opt = mainMenu(opt);
        // checa qual caso foi escolhido
        switch (opt)
        {
        case 1:
            //cadastra aluno
            registerStudent(students);
            break;
        case 2:
            //lista alunos
            listStudents(students);
            break;
        case 3:
            //deleta aluno
            removeStudent(students);
            break;      
        default:
            break;
        }
    }
    system("pause");
    return 0;
}
