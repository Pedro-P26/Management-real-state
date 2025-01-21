#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <locale.h>
#include <string.h>


int dadosClientes(CLIENTES *newCliente){
	setlocale(LC_ALL,"Portuguese");
	printf("Dados do cliente:\n");
	fflush(stdin);
	printf("Nome:");
	printf("\n");
	fflush(stdin);
	fgets(newCliente->nomeC,100,stdin);
	printf("Morada:");
	printf("\n");
	fflush(stdin);
	fgets(newCliente->moradaC,200,stdin);
	printf("País:");
	printf("\n");
	fflush(stdin);
	fgets(newCliente->paisC,100,stdin);
	printf("Nif:");
	printf("\n");
	fflush(stdin);
	scanf("%i",&newCliente->nifC);
	printf("nCC:");
	printf("\n");
	fflush(stdin);
	scanf("%i",&newCliente->nCCC);
	printf("Numero telemóvel:");
	printf("\n");
	fflush(stdin);
	scanf("%i",&newCliente->ntele);
	printf("Email:");
	printf("\n");
	fflush(stdin);
	fgets(newCliente->emailC,200,stdin);
}
void adicionarCliente(ELE **ini, CLIENTES newCliente){
	setlocale(LC_ALL,"Portuguese");
	ELE *novo=NULL;
	
	novo=(ELE *)calloc(1,sizeof(ELE));
	if(novo==NULL){
		printf("Out of memory!\n");
		return;
	}
	novo->cli=newCliente;
	novo->seguinte=NULL;
	
	if(*ini==NULL){
		*ini=novo;
	}else{
		novo->seguinte=*ini;
		*ini=novo;
	}

}
void listarClientes(ELE *ini){
	ELE *atual = ini;
	int codigoCliente = 1;

	if (ini == NULL) {
		printf("Lista Vazia!\n");
		return;
	}


	printf("Lista de Clientes:\n");
	while (atual != NULL) {
		printf("Código do Cliente: %d\n", codigoCliente);
		printf("Nome: %s\n", atual->cli.nomeC);
		printf("Morada: %s\n", atual->cli.moradaC);
		printf("País: %s\n", atual->cli.paisC);
		printf("NIF: %d\n", atual->cli.nifC);
		printf("NCCC: %d\n", atual->cli.nCCC);
		printf("Numero telemóvel:%i\n",atual->cli.ntele);
		printf("Email: %s\n", atual->cli.emailC);
		printf("\n");
		atual = atual->seguinte;
		codigoCliente++;
	}
}
void liberarLista(ELE **ini){
    ELE *atual = *ini;
    ELE *proximo;

    while (atual != NULL) {
        proximo = atual->seguinte;
        free(atual);
        atual = proximo;
    }

    *ini = NULL; 
}
void clientesporpais(ELE *ini,char pais[100]){
	setlocale(LC_ALL,"Portuguese");
	ELE *aux=NULL;
	
	if(ini==NULL){
		printf("Lista vazia!\n");
		return;
	}
	for(aux=ini;aux!=NULL;aux=aux->seguinte){
		if(strcmp(pais,aux->cli.paisC)==0){
				printf("Nome:%s\n",aux->cli.nomeC);
				printf("Morada:%s\n",aux->cli.moradaC);
				printf("País:%s\n",aux->cli.paisC);
				printf("Nif:%i\n",aux->cli.nifC);
				printf("nCC:%i\n",aux->cli.nCCC);
				printf("Numero telefone:%i\n",aux->cli.ntele);
				printf("Email:%s\n",aux->cli.emailC);	
				printf("\n");
		}
	}	
}
void clientespornif(ELE *ini,int nif){
	setlocale(LC_ALL,"Portuguese");
	ELE *aux=NULL;
	
	if(ini==NULL){
		printf("Lista vazia!\n");
		return;
	}
	for(aux=ini;aux!=NULL;aux=aux->seguinte){
		if(nif==aux->cli.nifC){
				
				printf("Nome:%s\n",aux->cli.nomeC);
				printf("Morada:%s\n",aux->cli.moradaC);
				printf("País:%s\n",aux->cli.paisC);
				printf("Nif:%i\n",aux->cli.nifC);
				printf("nCC:%i\n",aux->cli.nCCC);
				printf("Numero telemóvel:%i\n",aux->cli.ntele);
				printf("Email:%s\n",aux->cli.emailC);	
				printf("\n");
		}
	}	
}
void alterarinfocliente(ELE *ini,char *nome,float novo_ntele,char *novo_email){
	ELE *aux=NULL;
		
	if(ini == NULL){
		printf("Lista vazia!\n");
		return;
	}
	
	for(aux=ini;aux!=NULL;aux=aux->seguinte){
		if(strcmp(nome,aux->cli.nomeC)==0){
			aux->cli.ntele=novo_ntele;
			strncpy(aux->cli.emailC,novo_email,sizeof(aux->cli.emailC));
			printf("Informacoes alteradas com sucesso!\n");
			return;
		}
	}
	printf("Cliente indisponível!\n");	
}
int inserirClienteOrdenado(CLIENTES newCliente, ELE **ini) {
    ELE *aux = *ini, *novo, *anterior = NULL;
    novo = (ELE *)calloc(1, sizeof(ELE));

    if (novo == NULL) {
        printf("Out of memory!\n");
        return -1;
    }

    novo->cli = newCliente;
    novo->seguinte = NULL;

    if (*ini == NULL) {
        *ini = novo;
        return 0;
    }

    aux = *ini;
    while (aux != NULL && strcmp(aux->cli.nomeC, newCliente.nomeC) < 0) {
        anterior = aux;
        aux = aux->seguinte;
    }

    if (anterior == NULL) {
        novo->seguinte = *ini;
        *ini = novo;
    } else {
        novo->seguinte = anterior->seguinte;
        anterior->seguinte = novo;
    }

    return 0;
}
void alistarClientes(ELE *ini){
    ELE *atual = ini;
    while (atual != NULL) {
        CLIENTES newCliente = atual->cli;
        printf("Nome: %s\n", newCliente.nomeC);
        printf("Morada: %s\n", newCliente.moradaC);
        printf("País: %s\n", newCliente.paisC);
        printf("NIF: %d\n", newCliente.nifC);
        printf("NCCC: %d\n", newCliente.nCCC);
        printf("Ntele: %d\n", newCliente.ntele);
        printf("Email: %s\n", newCliente.emailC);
        printf("-------------------------\n");
        atual = atual->seguinte;
    }
}
void libertrarclientes(ELE *ini){
    ELE *atual = ini;
    while (atual != NULL) {
        ELE *proximo = atual->seguinte;
        free(atual);
        atual = proximo;
    }
}
void escreverclibinario(ELE *ini,const char *infocliente){
	FILE *fp=NULL;
	ELE *aux = ini;
	fp=fopen("infocliente.dat","ab");
	
	if(fp==NULL){
		printf("ERRO ao abrir o ficheiro!\n");
		return;
	}
	
	while(aux!=NULL){
		fwrite(&aux->cli,sizeof(CLIENTES),1,fp);
		aux = aux->seguinte;
	}
	fclose(fp);
}
void lerclibinario(ELE **ini){
	FILE *fp=NULL;
	CLIENTES newCliente;
	fp=fopen("infocliente.dat","rb");
	
	if(fp==NULL){
		printf("ERRO ao abrir o ficheiro!\n");
		return;
	}
		
	while(fread(&newCliente,sizeof(CLIENTES),1,fp)){
		adicionarCliente(ini,newCliente);
	}
	fclose(fp);
}

