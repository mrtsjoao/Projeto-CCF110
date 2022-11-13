#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(){
  int nVagasVan =15;
  int nAlunos;

  system("cls");
  printf("Bem vindo usuário!\n");
  printf("Digite a quantidade de alunos que vão embora: \n");
  scanf("%d", &nAlunos);

  //CALCULO DOS DESENHO DOS ASSENTOS DISPONIVEIS
  int LinhaAssentos, ColunaAssentos = 3;
  LinhaAssentos = nAlunos / ColunaAssentos;
  if (nAlunos % ColunaAssentos != 0)
  {
    LinhaAssentos++;
  }

  int Assentos[LinhaAssentos][ColunaAssentos];
  int countVans[2]; // INDICE 0 == CONTADOR POR FILEIRA E INDICE 1 == CONTADOR GERAL;
  countVans[0] = 0;
  countVans[1] = 1;
  for(int i = 0; i< LinhaAssentos; i++)
  {
    for(int j = 0; j < ColunaAssentos; j++)
    {
      Assentos[i][j] = 0;
      countVans[0]++;
    }
    if(countVans[0] >= nVagasVan)
    {
      if(nVagasVan != nAlunos)
      {
        countVans[1]++;
      }
      countVans[0] = 0;
    }
  }

  //LEITURA DOS DADOS DOS ALUNOS
  int IDs[nAlunos];
  for(int I = 0; I < nAlunos; I++)
  {
    system("cls");
    printf("Serao necessarias ao menos %d van(s).\n", countVans[1]);
    printf("ASSENTOS DISPONIVEIS SEPARADOS POR VANS\n");
    for(int i = 0; i< LinhaAssentos; i++)
    {
      printf("| ");
      for(int j = 0; j < ColunaAssentos; j++)
      {
        printf("%d ", Assentos[i][j]);
        countVans[0]++;
      }
      printf("| \n");
      if(countVans[0] >= nVagasVan)
      {
        printf("\n");
        countVans[0] = 0;
      }
    }
    countVans[0] = 0;

    printf("Digite o ID do alunos: ");
    scanf("%d", &IDs[I]);
    printf("\n");

    int posx, posy, pause;
    printf("Digite o assento que ele irá ocupar: (Linha) (Coluna)\n");
    scanf("%d %d",&posy, &posx);
    if (Assentos[posy][posx] != 0)
    {
      printf("Lugar já está ocupado!");
      printf("O Aluno %d será substituido por %d: Confirme sua ação com (1)", Assentos[posy][posx], IDs[I]);
      scanf("%d", &pause);
    }
    Assentos[posy][posx] = IDs[I];
  }

  //LISTA DE ALUNOS COM NOMES LIGADOS A MATRICULA POR PONTEIROS
  /*LEITURA DE NOMES:

  char nomes[5][25];
    for (int i = 0; i < 5; i++)
    {
        printf("Digite o %dº nome: ", i +1);
        scanf("%25[^\n]", nomes[i]);
        fflush(stdin);
    } */




  return 0;
}