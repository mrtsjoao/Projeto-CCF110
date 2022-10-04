#include <stdio.h>
#include <stdlib.h>


int main(){
  int horario, nVans[3], nVagas[3], cont;

  //DEFINIMOS QUE CADA VAN POSSUI 15 VAGAS
  for (int i = 0; i < 3; i++)
  {
    printf("Digite a quantidade de vans: \n");
    scanf("%d", &nVans[i]);
    nVagas[i]  = nVans[i] * 15;
    cont += nVagas[i];
  }
  for (int i = 0; i < cont; i++)
  {
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
        printf("Restam %d vagas para a van de 12 horas\n", nVagas[0]);
      }
      break;
    case 15:
      if(nVagas[1] <1 ){
        printf("Vagas esgotadas!");
      }
      else{
        nVagas[1]--;
        printf("Restam %d vagas para a van de 15 horas\n", nVagas[1]);
      }
      break;
    case 17:
      if(nVagas[2] <1 ){
       printf("Vagas esgotadas!");
      }
      else{
        nVagas[2]--;
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