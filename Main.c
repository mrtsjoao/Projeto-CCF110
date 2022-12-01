#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct Alunos
{
  int Matricula;
  char nome[30];
  char endereco[30];
  char cidade[30];
}ficha;

void RegistraAlunos(ficha *ptrficha);
void printardesenho (int L, int C, int *M, int cont);
int calculodesenho (int VagaVans, int qAlunos, int Linha, int Coluna, int *Assent);
void AlocarAlunos(int *pmAssentos, ficha *Daluno);

int main(){
    int nVagasVan =15;
    int nAlunos;

    system("cls");
    printf("Bem vindo usuário!\n");
    printf("\nDigite a quantidade de alunos que vão embora: \n");
    scanf("%d", &nAlunos);

    ficha DadosAlunos[nAlunos];

    int LinhaAssentos, ColunaAssentos = 3;
    LinhaAssentos = 5 *ceil(((float)nAlunos / (float)nVagasVan)); // CONSIDERANDO QUE EXISTEM 5 FILEIRAS P/VAN
    int Assentos[LinhaAssentos][ColunaAssentos];
    int countVans[2]; // INDICE 0 == CONTADOR POR FILEIRA E INDICE 1 == CONTADOR DE VANS;
    countVans[0] = 0;

    countVans[1] = calculodesenho(nVagasVan, nAlunos, LinhaAssentos, ColunaAssentos, &Assentos[0][0]);

  //LEITURA DOS DADOS DOS ALUNOS
  for(int I = 0; I < nAlunos; I++)
  {
    system("cls");
    printf("Serao necessarias ao menos %d van(s).\n", countVans[1]);
    printf("ASSENTOS DISPONIVEIS SEPARADOS POR VANS\n\n");
    printardesenho(LinhaAssentos, ColunaAssentos, &Assentos[0][0], countVans[0]);

    //LISTA DE ALUNOS COM NOMES
    RegistraAlunos(&DadosAlunos[I]);

    int posx, posy;
    printf("Digite o assento que ele irá ocupar: (Linha) (Coluna)\n");
    scanf("%d %d",&posy, &posx);
    AlocarAlunos(&Assentos[posy][posx], &DadosAlunos[I]);

  system("cls");
  }
  printardesenho(LinhaAssentos, ColunaAssentos, &Assentos[0][0], countVans[0]);

  float Distancia_cidade[3], tempo[3]; // 0 -> BETIM, 1 -> CONTAGEM, 2 -> BH (BARREIRO)
  float mediaAlunos = nAlunos/countVans[1], *pmedia; // PARA TER UMA MEDIA DE ALUNOS P/VAN
  pmedia = &mediaAlunos;
  Distancia_cidade[0] = 25.97 + *pmedia; //CONSIDERANDO QUE A DISTANCIA ENTRE UM ALUNO A OUTRO = 1KM
  Distancia_cidade[1] = 15.62 + *pmedia;
  Distancia_cidade[2] = 30.67 + *pmedia;
  tempo[0] = Distancia_cidade[0] / 30;
  tempo[1] = Distancia_cidade[1] / 30;
  tempo[2] = Distancia_cidade[2] / 30;

  int cidade;
  for(int i = 0; i<countVans[1]; i++)
  {
    printf("\nDigite qual cidade a van vai passar: \n<0> BETIM\n<1> CONTAGEM\n<2> BELO HORIZONTE\n");
    scanf("%d", &cidade);
    switch (cidade)
    {
      case 0:
      printf("A distancia media aproximada até Betim e: %.2f KM\nO tempo medio da rota inteira e: %.2f Horas",Distancia_cidade[0], tempo[0]);
      break;
      case 1:
      printf("A distancia media aproximada até Contagem e: %.2f KM\nO tempo medio da rota inteira e: %.2f Horas",Distancia_cidade[1], tempo[1]);
      break;
      case 2:
      printf("A distancia media aproximada até Belo Horizonte e: %.2f KM\nO tempo medio da rota inteira e: %.2f Horas",Distancia_cidade[2], tempo[2]);
      break;
      default:
      printf("Cidade não encontrada!");
      i++;

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
  printf("A sua matricula: ");
  scanf("%d", &Dados.Matricula);
  printf("Endereço do Aluno %d: ", Dados.Matricula);
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

