#ifndef ROTACAB_H_INCLUDED
#define ROTACAB_H_INCLUDED

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
void CalculoDistancia(int nAlu, int Count);


#endif // ROTACAB_H_INCLUDED
