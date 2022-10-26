#include <stdio.h>
#include <stdlib.h>


int main(){
  int nVans[3], nVagas[3], cont = 0, nVagasVan;
  int nAlunos;
  

  system("cls");
  printf("Bem vindo usuário!\n");
  printf(" Digite a quantidade de alunos que vão embora: \n");
  scanf("%d", &nAlunos);
  printf("Digite a quantidade de vagas por van: ");
  scanf("%d", &nVagasVan);


  //CALCULO DOS DESENHO DOS ASSENTOS DISPONIVEIS
  int LinhaAssentos, ColunaAssentos = 3;
  LinhaAssentos = nAlunos / ColunaAssentos;
  if (nAlunos % ColunaAssentos != 0)
  {
    LinhaAssentos++;
  }

  int Assentos[LinhaAssentos][ColunaAssentos];
  int countVans[2];
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


    int IDs[nAlunos];
    printf("Digite o ID do alunos: ");
    scanf("%d", &IDs[I]);
    printf("\n");

    int posx, posy;
    printf("Digite o assento que ele irá ocupar: (Linha) (Coluna)\n");
    scanf("%d %d",&posy, &posx);
    Assentos[posy][posx] = IDs[I];
    if (Assentos[posy][posx] != 0)
    {
      printf("Lugar já está ocupado!");
    }
    
  }
  
  return 0;
}