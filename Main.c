#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include "RotaCab.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    int nVagasVan = 15;
    int nAlunos, funcao;

    printf("\nMONTANDO A ROTA\n\n");

    printf("Digite a quantidade de alunos que vão embora: \n");
    scanf("%d", &nAlunos);
    //DECLARANDO A QUANTIDADE DE FICHAS DE ALUNOS
    ficha DadosAlunos[nAlunos];
    //MONTANDO A MATRIZ DE ASSENTOS DA VAN
    int LinhaAssentos, ColunaAssentos = 3;
    LinhaAssentos = 5 *ceil(((float)nAlunos / (float)nVagasVan)); // CONSIDERANDO QUE EXISTEM 5 FILEIRAS P/VAN
    int Assentos[LinhaAssentos][ColunaAssentos];
    int countVans[2]; // INDICE 0 == CONTADOR POR FILEIRA E INDICE 1 == CONTADOR DE VANS;
    countVans[0] = 0;
    countVans[1] = calculodesenho(nVagasVan, nAlunos, LinhaAssentos, ColunaAssentos, &Assentos[0][0]);

    //LEITURA DOS DADOS DOS ALUNOS E ALOCAÇÃO
    for(int I = 0; I < nAlunos; I++)
    {
        system("cls");

        printf("\nLEITURA DE DADOS DOS ALUNOS E ALOCAÇÃO NA VAN: \n\n");

        printf("Serão necessarias ao menos %d van(s).\n", countVans[1]);
        printf("Assentos da van abaixo: \n\n");

        printardesenho(LinhaAssentos, ColunaAssentos, &Assentos[0][0], countVans[0]);
        RegistraAlunos(&DadosAlunos[I]);
        int posx, posy;
        printf("Digite o assento que ele irá ocupar: (Linha) (Coluna)\n");
        scanf("%d %d",&posy, &posx);
        AlocarAlunos(&Assentos[posy][posx], &DadosAlunos[I]);
        system("cls");

    }
    int ordementrega[nAlunos];
    FILE *Fordem;

    int FLAG_STOP = 0;
    while (FLAG_STOP == 0){


        printf("\n\n ROTA CRIADA \n\n");

        printf("<1> DEFINIR O DESTINO DA ROTA\n");
        printf("<2> DEFINIR A ORDEM DE ENTREGA DOS ALUNOS\n");
        printf("<3> MOSTRAR ASSENTOS ORGANIZADOS DA VAN \n");
        printf("<4> SALVAR A ORDEM DE ENTREGA EM UM ARQUIVO\n");
        printf("<5> MOSTRAR A FICHA COMPLETA DE UM ALUNO \n");
        printf("<6> SAIR \n ");

        scanf("%d", &funcao);
        switch(funcao){
            case 1:
                system("cls");
                printf("\n\n");
                CalculoDistancia(nAlunos, countVans[1]);
                break;

            case 2:
                system("cls");

                printf("DEFININDO A ORDEM DE ENTREGA \n\n");

                for(int i = 0; i<nAlunos; i++){
                    printf("%d- %s\n", (i+1), DadosAlunos[i].nome);
                }
                printf("\nDigite a ordem de entrega: \n");
                for(int i = 0; i<nAlunos; i++){
                    scanf("%d", &ordementrega[i]);
                }
                system("cls");
                break;
            case 3:
                system("cls");

                printf("DESENHO DA VAN: \n\n");

                printardesenho(LinhaAssentos, ColunaAssentos, &Assentos[0][0], countVans[0]);
                break;
            case 4:
                system("cls");
                if((Fordem = fopen("ordementrega.txt", "w+"))== NULL){
                    printf("\nErro ao abrir o arquivo\n");
                }
                else{
                    for(int i = 0; i<nAlunos; i++){
                        fprintf(Fordem, "%d- %s\n", (i+1), DadosAlunos[(ordementrega[i])-1].nome);
                    }
                    printf("\nArquivo Criado!\n");
                }
                break;
            case 5:
                system("cls");
                printf("TODOS OS ALUNOS REGISTRADOS\n\n");
                for(int i = 0; i<nAlunos; i++){
                    printf("%d- %s\n", DadosAlunos[i].Matricula, DadosAlunos[i].nome);
                }
                printf("\n\nDigite a matrícula do aluno: ");
                int buscamatricula;
                scanf("%d", &buscamatricula);
                for(int i = 0; i<nAlunos; i++){
                    if(buscamatricula == DadosAlunos[i].Matricula){
                        printf("\n\nNome: %s\n", DadosAlunos[i].nome);
                        printf("Matrícula: %d\n", DadosAlunos[i].Matricula);
                        printf("Endereço: %s\n", DadosAlunos[i].endereco);
                        printf("Cidade: %s\n", DadosAlunos[i].cidade);
                    }
                }
                break;
            case 6:
                printf("\n\nBOA VIAGEM!\n\n");
                FLAG_STOP++;
                break;
            default:
                printf("\nDIGITE UMA FUNÇÃO QUE EXISTA\n");
        }
    }

  return 0;

}

void printardesenho(int L, int C, int *M, int cont){

    for(int i = 0; i< L; i++)
    {
        printf("|");
        for(int j = 0; j < C; j++)
        {
                printf(" %d ", *M);
                cont++;
                M++;
        }
        printf("| \n");
        if(cont >= 15)
        {
            printf("\n");
            cont = 0;
        }
    }
    cont = 0;
}

int calculodesenho(int VagaVans, int qAlunos, int Linha, int Coluna, int *Assent){

    int cont1 = 0, cont2 = 1;

    for(int i = 0; i< Linha; i++)
    {
        for(int j = 0; j < Coluna; j++)
        {
            *Assent = 0;
            Assent++;
            cont1++;
        }
        if(cont1 >= VagaVans)
        {
            if(VagaVans != qAlunos)
            {
                cont2++;
            }
            cont1 = 0;
        }
    }
    if(qAlunos == 15)
        cont2 = 1;
    else
        cont2--;
    return cont2;
}

void RegistraAlunos(ficha *ptrficha){
  static int n = 0;
  ficha Dados;
  fflush(stdin);
  printf("Digite o %dº nome: ", n +1);
  gets(Dados.nome);
  fflush(stdin);
  printf("Digite a matricula do aluno: ");
  scanf("%d", &Dados.Matricula);
  printf("Digite a cidade do Aluno %d: ", Dados.Matricula);
  fflush(stdin);
  gets(Dados.cidade);
  printf("Digite o Endereço do Aluno %d: ", Dados.Matricula);
  fflush(stdin);
  gets(Dados.endereco);
  *ptrficha = Dados;
  n++;
}
void AlocarAlunos(int *pmAssentos, ficha *Daluno)
{
    int pause;
    if (*pmAssentos != 0)
    {
      printf("Lugar já está ocupado!");
      printf("O Aluno %d será substituido por %d: Confirme sua ação com (1)", *pmAssentos, (*Daluno).Matricula);
      scanf("%d", &pause);
    }

    *pmAssentos = (*Daluno).Matricula;
}

void CalculoDistancia(int nAlu, int Count){

  float mediaAlunos = nAlu/Count, tempo, distancia;
  int cidade;
  for(int i = 0; i<Count; i++)
  {
    printf("\nDigite qual cidade a van(%d) vai passar: \n<0> BETIM\n<1> CONTAGEM\n<2> BELO HORIZONTE\n", (i+1));
    scanf("%d", &cidade);
    switch (cidade){
        case 0:
            distancia = 25.97 + mediaAlunos;
            tempo = (distancia / 30) * 60;
            printf("A van %d vai passar por BETIM e terá uma rota com: \nDistância percorrida de %.2f KM \nTempo até o ultimo destino de %.2f Min\n", (i+1), distancia, tempo);
            break;
        case 1:
            distancia = 15.62 + mediaAlunos;
            tempo = (distancia / 30) * 60;
            printf("A van %d vai passar por CONTAGEM e terá uma rota com: \nDistância percorrida de %.2f KM \nTempo até o ultimo destino de %.2f Min\n", (i+1), distancia, tempo);
            break;
        case 2:
            distancia = 30.67 + mediaAlunos;
            tempo = (distancia / 30) * 60;
            printf("A van %d vai passar por BARRERO e terá uma rota com: \nDistância percorrida de %.2f KM \nTempo até o ultimo destino de %.2f Min\n", (i+1), distancia, tempo);
            break;
        default:
            printf("CIDADE NÃO INDETIFICADA, TENTE NOVAMENTE: ");
            i--;
            break;
    }
  }
}
