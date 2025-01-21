#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct cli{
	char nomeC[100];
	char moradaC[200];
	char paisC[100];
	int nifC;
	int nCCC;
	int ntele;
	char emailC[200];
}CLIENTES;

typedef struct el{
	CLIENTES cli;
	struct el *seguinte;
}ELE;

int dadosClientes(CLIENTES *newCliente);
void adicionarCliente(ELE **ini, CLIENTES newCliente);
void listarClientes(ELE *ini);
void libertarclientes(ELE **ini);
void clientesporpais(ELE *ini,char pais[100]);
void clientespornif(ELE *ini,int nif);
void alterarinfocliente(ELE *ini,char *nome,float novo_ntele,char *novo_email);
void escreverclibinario(ELE *ini,const char *infocliente);
void lerclibinario(ELE **ini);
int inserirClienteOrdenado(CLIENTES newCliete,ELE **ini);
