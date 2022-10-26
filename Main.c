#include <stdio.h>
#include <stdlib.h>


int main(){
  int horario, nVans[3], nVagas[3], cont = 0, nVagasVan = 15;

  /*horario 0 = 12 horas
    horario 1 = 15 horas
    horario 1 = 17 horas*/
  for (int i = 0; i < 3; i++)
  {
    printf("Digite a quantidade de vans no horario (%d): \n", (i));
    scanf("%d", &nVans[i]);
    nVagas[i]  = nVans[i] * nVagasVan;
    cont += nVagas[i];
  }

  int IdAluno[cont], OrdemEntrega[cont][3];

  for (int i = 0; i < cont; i++)
  {
    printf("Digite o ID do aluno: \n");
    scanf("%d", &IdAluno[i]);
    printf("Digite o horário de saída \n");
    printf("Horários disponíveis: 12, 15 e 17 \n");
    scanf("%d",&horario);
    switch (horario){
    case 12:
      if(nVagas[0] <1 ){
        printf("Vagas esgotadas!");
      }
      else{
        nVagas[0]--;
        OrdemEntrega[cont][0] = IdAluno[i];
        printf("Restam %d vagas para a van de 12 horas\n", nVagas[0]);
      }
      break;
    case 15:
      if(nVagas[1] <1 ){
        printf("Vagas esgotadas!");
      }
      else{
        nVagas[1]--;
        OrdemEntrega[cont][1] = IdAluno[i];
        printf("Restam %d vagas para a van de 15 horas\n", nVagas[1]);
      }
      break;
    case 17:
      if(nVagas[2] <1 ){
       printf("Vagas esgotadas!");
      }
      else{
        nVagas[2]--;
        OrdemEntrega[cont][2] = IdAluno[i];
        printf("Restam %d vagas para a van de 17 horas\n", nVagas[2]);
      }
      break;
    default:
      printf("Horário indisponivel\n");
      break;
    }
  } 
    return 0;

}