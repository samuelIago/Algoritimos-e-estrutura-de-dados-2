#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct Info{
    char nome[100];
    int mat;
    int turma;
    float nota;
};

struct Node{
    struct Info info;
    struct Node *esq;
    struct Node *dir;
};

struct Info criarInfo(char *nome, int mat, int turma, float nota);
struct Node* criarNode(struct Info info);
int comparar(struct Info a, struct Info b);
struct Node *inserir(struct Node *raiz, struct Info info);
void imprimirInOrdem(struct Node* raiz);
void imprimirPreOrdem(struct Node* raiz);
void imrprimirPosOrdem(struct Node* raiz);
void lerArquivo(char* arquivo, struct Node** raiz);
void buscarNo(struct Node* raiz, char* nome);
void buscarNoAuxiliar(struct Node* raiz, char* nome, int profundidade, struct Node* pai);

int main(){
    srand(time(0)); // essa função serve para gerar numeros aleatorios
    char NomeBuscado[50] = "SAMUEL IAGO DE FARIAS CABRAL";

    struct Node* raiz = NULL;
    lerArquivo("alunos-arvore.txt", &raiz);
    printf("Imprimindo a arvore In-Ordem:\n");
    printf("\n");

    printf("Imprimindo a arvore Pre-Ordem:\n");
    imprimirPreOrdem(raiz);
    printf("\n");

    printf("Imprimindo a arvore Pos-Ordem:\n");
    imrprimirPosOrdem(raiz);
    printf("\n");
    
    buscarNo(raiz, NomeBuscado);

    return 0;
}

struct Info criarInfo(char *nome, int mat, int turma, float nota){
    struct Info res;
    strcpy(res.nome, nome);
    res.mat = mat;
    res.turma = turma;
    res.nota = nota;
    return res;
}

struct Node* criarNode(struct Info info){
    struct Node* res = (struct Node*)malloc(sizeof(struct Node));
    res->info = info;
    res->dir = 0;
    res->esq = 0;
    return res;
}

int comparar(struct Info a, struct Info b){
    return strcmp(a.nome, b.nome);
}

struct Node *inserir(struct Node *raiz, struct Info info){
    if(raiz == 0){
        return criarNode(info);
    }
    int x = comparar(raiz->info, info);
    if(x < 0){
        raiz->dir = inserir(raiz->dir, info);
    }else if(x > 0){
        raiz->esq = inserir(raiz->esq, info);
    }
    return raiz;
}

void imprimirInOrdem(struct Node* raiz){
    if(raiz != NULL){
        imprimirInOrdem(raiz->esq);
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
        imprimirInOrdem(raiz->dir);
    }
}

void imprimirPreOrdem(struct Node* raiz){
    if(raiz != NULL){
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
    }
}

void imrprimirPosOrdem(struct Node* raiz){
    if(raiz != NULL){
        imrprimirPosOrdem(raiz->esq);
        imrprimirPosOrdem(raiz->dir);
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
    }
}

void lerArquivo(char* arquivo, struct Node** raiz){
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    char nome[100];
    int mat, turma;
    while (fscanf(file, "%d %d %99[^\n]", &mat, &turma, nome) != EOF) {
        // essa função serve para que quando encontrar o \n trocar por \0 para que essa linha seja finalizada e que va para a próxima sem problemas
        nome[strcspn(nome, "\n")] = 0;

        float nota = rand() % 10;
        struct Info info = criarInfo(nome, mat, turma, nota);
        *raiz = inserir(*raiz, info);
    }

    fclose(file);
}

//Essa função serve para auxiliar na busca do meu nome, quem é meu pai e meus filhos e qual a minha profundidade
void buscarNoAuxiliar(struct Node* raiz, char* nome, int profundidade, struct Node* pai) {
    int cmp = strcmp(raiz->info.nome, nome);//se o nome no no atual nao for oque eu quero, ele nao vai retornar 0 então continua
    if (cmp == 0) {
        printf("Meu nome esta na profundidade %d.\n",profundidade);
        if (pai != NULL) {
            printf("Nome do no pai: %s\n", pai->info.nome);
        }
        if (raiz->esq != NULL) {
            printf("Nome do filho a esquerda: %s\n", raiz->esq->info.nome);
        } else {
            printf("Nao tem filho na esquerda.\n");
        }
        if (raiz->dir != NULL) {
            printf("Nome do filho a direita: %s\n", raiz->dir->info.nome);
        } else {
            printf("Nao tem filho na direita.\n");
        }
    } else if (cmp < 0) { // Se o nome buscado for maior, entao vai buscar na subarvore na direita
        buscarNoAuxiliar(raiz->dir, nome, profundidade + 1, raiz);
    } else {// Se o nome buscado for menor, entao vai buscar na subarvore na esquerda
        buscarNoAuxiliar(raiz->esq, nome, profundidade + 1, raiz);
    }
}
//essa funcao começa a busca
void buscarNo(struct Node* raiz, char* nome) {
    buscarNoAuxiliar(raiz, nome, 0, NULL);
}
