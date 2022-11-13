#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
  int nVagasVan =15;
  int nAlunos;

  system("cls");
  printf("Bem vindo usuário!\n");
  printf("Digite a quantidade de alunos que vão embora: \n");
  scanf("%d", &nAlunos);

  //CALCULO DO DESENHO DOS ASSENTOS DISPONIVEIS
  int LinhaAssentos, ColunaAssentos = 3;
  if(nAlunos < nVagasVan)
  {
    LinhaAssentos = 5;
  }
  else{
    LinhaAssentos = 5 *ceil(((float)nAlunos / (float)nVagasVan)); // CONSIDERANDO QUE EXISTEM 5 FILEIRAS P/VAN
  }

  int Assentos[LinhaAssentos][ColunaAssentos];
  int countVans[2]; // INDICE 0 == CONTADOR POR FILEIRA E INDICE 1 == CONTADOR DE VANS;
  countVans[0] = 0;
  countVans[1] = 0;
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
    char nomes[nAlunos][30];
    int IDs[nAlunos];
for(int I = 0; I < nAlunos; I++)
  {
    system("cls");
    printf("Serao necessarias ao menos %d van(s).\n", countVans[1]);
    printf("ASSENTOS DISPONIVEIS SEPARADOS POR VANS\n");
    
    printf("Van nº 1 \n");
    
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

    //LISTA DE ALUNOS COM NOMES LIGADOS A MATRICULA POR PONTEIROS
    fflush(stdin);
    printf("Digite o %dº nome: ", I+1);
    scanf("%25[^\n]", nomes[I]);
    fflush(stdin);
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
      Assentos[posy][posx] = IDs[I];
      I--;
    }
    else{
        Assentos[posy][posx] = IDs[I];
    }
  }
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

  int cidades;
  for (int i = 0; i < countVans[1] i++)
  {
    printf("Digite a cidade para qual a van %d está indo:\n 1 - Betim. \n 2 - Contagem.\n 3 - Barreiro (Belo Horizonte)\n ", i + 1);
    scanf("%d", &cidades);
    if (cidades == 1)
    {
        printf("A van %d está indo para Betim.\n Distância: 35 Km \n Tempo de viagem até a cidade: 37 minutos.\n", i+1);
    }else if (cidades == 2)
    {
      printf("A van %d está indo para Contagem.\n Distância: 57,4 Km \n Tempo de viagem até a cidade: 54 minutos.\n", i + 1);
    }else if (cidades == 3)
    {
     printf("A van %d está indo para Barreiro (Belo Horizonte).\n Distância: 61,6 Km \n Tempo de viagem até a cidade: 1 hora e 2 minutos. \n", i+1);
    }
  }
  
    
}
    countVans[0] = 0;
  return 0;
}
