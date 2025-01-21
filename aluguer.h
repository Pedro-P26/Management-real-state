#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct alu{
	char nomee[200];
	char moradaa[200];
	int nif_a;
	char datainicio[11];
	char datafim[11];
	float preco;
	char datapagamento[11];
}ALUGUER;

typedef struct elemt{
	ALUGUER alu;
	struct elemt *seguinte;
}ELEMT;

void imoveisparaaluguer(ELEMENTO *inilista,char tipo[]);
void aluguer_pornif(ELEMT *inifila,int nif);
void aluguer_ativo(ELEMT *inifila);
void getdadosalu(ELEMENTO **inilista,ALUGUER **newAluguer,IMOVEL *newinfo);
int adicionaraluguer(ELEMT **inifila,ALUGUER newAluguer);
