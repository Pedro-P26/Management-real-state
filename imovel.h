#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct imo{
	char moradaI[100];
	char cidadeI[100];
	char freguesiaI[100];
	char tipoI[10];
	float areaI;
	int wcsI;
	int anoI;
	float precoI;
	char energiaI[10];
	char observacoesI[200];
	char animaisI[1];
	char inatividade[3];
}IMOVEL;

typedef struct elem{
	IMOVEL imo;
	struct elem *seguinte;
}ELEMENTO;

int getdados(IMOVEL *newinfo);
int inseririni(ELEMENTO **inilista,IMOVEL newinfo);
void listarporcidade(ELEMENTO *inilista,char cidade[100]);
void listarportipo(ELEMENTO *inilista,char tipoI[20]);
void imovelanimal(ELEMENTO *inilista,char animal[10]);
void removerimovel(ELEMENTO **inilista,char morada[100]);
void libertaLista(ELEMENTO **inilista);
void listarimovelgeral(ELEMENTO *inilista);
void escreverimobinario(ELEMENTO *inilista,const char *infoimovel);
void lerimobinario(ELEMENTO **inilista);
void alterarinfoimovel(ELEMENTO *inilista,char *morada,float novo_preco,char *nova_obser);
void listarcrespreco(ELEMENTO *inilista);
void decimoano(ELEMENTO *inilista);
void alterarinatividade(ELEMENTO *inilista,char *morada,char *inatividade);














