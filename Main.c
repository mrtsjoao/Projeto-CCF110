#include <stdio.h>

int main(){
int countTotal, nAlunosTotal, TipoVan, Vaga_Van15 = 15, Vaga_Van12 = 15, Vaga_Van17 = 15;

printf()






//Preechimento de vaga nas vans
printf("Quantos alunos serão adicionados?: ");
scanf("%d", &nAlunosTotal);
countTotal = nAlunosTotal;
for(int i = 1; i <= nAlunosTotal; i++){
    printf("Escolha um Horario: (0) Meio dia // (1) Três horas // (2) Cinco horas\n");
    scanf("%d",&TipoVan);
    if(TipoVan == 0){
        Vaga_Van12 = Vaga_Van12 - 1;
    }
    else if(TipoVan == 1){
        Vaga_Van15 = Vaga_Van15 - 1;
    }
    else if(TipoVan == 2){
        Vaga_Van17 = Vaga_Van17 - 1;
    }

    countTotal--;

    printf("Faltam %d alunos \n", countTotal);
    printf("Faltam %d vagas na van de meio dia \n", Vaga_Van12);
    printf("Faltam %d vagas na van das 15 \n", Vaga_Van15);

    }

return 0;
}