#include <stdio.h>
#include <stdlib.h>
#include "aluguer.h"
#include "imovel.h"
#include "clientes.h"
#include <locale.h>
#include <string.h>




int adicionaraluguer(ELEMT **inifila,ALUGUER newAluguer){
	ELEMT *novo=NULL;
	
	novo=(ELEMT *)calloc(1,sizeof(ELEMT));
	
	if(novo==NULL){
		printf("Out of memory!\n");
		return;
	}
	novo->alu=newAluguer;
	novo->seguinte=NULL;
	
	if(*inifila==NULL){
		*inifila=novo;
	}else{
		novo->seguinte=*inifila;
		*inifila=novo;
	}
	return 0;
}

void getdadosalu(ELEMENTO **inilista,ALUGUER **newAluguer,IMOVEL *newinfo){
	ELEMENTO *aux=*inilista;
	
	printf("Introduza o nome do cliente:");
	printf("\n");
	fflush(stdin);
	fgets(newAluguer->nomee,200,stdin);
	printf("Introduza o nif do cliente:");
	printf("\n");
	fflush(stdin);
	scanf("%d",&newAluguer->nif_a);
	printf("Introduza a morada do imóvel:");
	printf("\n");
	fflush(stdin);
	fgets(newAluguer->moradaa,200,stdin);
	
	printf("Introduza a data de início do aluguer (DD/MM/AAAA): ");
    fgets(newAluguer->datainicio,11,stdin);
    printf("Introduza a data de fim do aluguer (DD/MM/AAAA): ");
    fgets(newAluguer->datafim,11,stdin);
    
    
    int diaInicio, mesInicio, anoInicio;
    int diaFim, mesFim, anoFim;
    
    sscanf(newAluguer->datainicio, "%d/%d/%d", &diaInicio, &mesInicio, &anoInicio);
    sscanf(newAluguer->datafim, "%d/%d/%d", &diaFim, &mesFim, &anoFim);
    
    int diasAluguer = (diaFim - diaInicio) + ((mesFim - mesInicio) * 30) + ((anoFim - anoInicio) * 365);

    if (diasAluguer < 7) {
        printf("O período mínimo de aluguer é de uma semana. Por favor, selecione um período válido.\n");
        return;
	}
	int op=0;
	
	printf("Preco=%f\n",aux->imo.precoI);
	printf("Ajustar com o cliente?(0-sim/1-nao)\n");
	scanf("%d",&op);
	
	if(op==0){
		printf("Novo preco aluguer:");
		printf("\n");
		fflush(stdin);
		scanf("%f",&newAluguer->preco);
	}
	printf("Data do Pagamento (DD/MM/AAAA) : ");
	printf("\n");
	fgets(newAluguer->datapagamento,11,stdin);
	
}

void aluguer_ativo(ELEMT *inifila){
	ELEMT *aux=NULL;
	
	printf("Todos os Alugueres ativos:\n");
	
	for(aux=inifila;aux!=NULL;aux=aux->seguinte){
		printf("Morada:%s\n",aux->alu.moradaa);
		printf("Nome Cliente:%s\n",aux->alu.nomee);
		printf("NIF:%d\n",aux->alu.nif_a);
		printf("Data de Inicio:%s\n",aux->alu.datainicio);
		printf("Data de Fim:%s\n",aux->alu.datafim);
		printf("Preco:%.2f\n",aux->alu.preco);
		printf("Data de Pagamento:%s\n\n",aux->alu.datapagamento);
		
	}
}

void aluguer_pornif(ELEMT *inifila,int nif){
	ELEMT *aux=NULL;
	
	printf("Alugueres dos cliente com NIF :%d\n",nif);
	
	for(aux=inifila;aux!=NULL;aux=aux->seguinte){
		if(aux->alu.nif_a==nif){
			printf("Morada:%s\n",aux->alu.moradaa);
			printf("Nome Cliente:%s\n",aux->alu.nomee);
			printf("NIF:%d\n",aux->alu.nif_a);
			printf("Data de Inicio:%s\n",aux->alu.datainicio);
			printf("Data de Fim:%s\n",aux->alu.datafim);
			printf("Preco:%.2f\n",aux->alu.preco);
			printf("Data de Pagamento:%s\n\n",aux->alu.datapagamento);
		}
		printf("Nao existe alugueres registados com o NIF:%d",nif);
	}
	
}

void imoveisparaaluguer(ELEMENTO *inilista,char tipo[]){
	ELEMENTO *aux=NULL;
	
	printf("Imoveis disponiveis para aluguer do tipo %s\n",tipo);
	
	for(aux=inilista;aux!=NULL;aux=aux->seguinte){
		if(strcmp(aux->imo.tipoI,tipo)==0){
			printf("Morada Completa:%s\n",aux->imo.moradaI);
				printf("Cidade:%s\n",aux->imo.cidadeI);
				printf("Freguesia:%s\n",aux->imo.freguesiaI);
				printf("Tipo de Imóvel:%s\n",aux->imo.tipoI);
				printf("Área:%f\n",aux->imo.areaI);
				printf("Numero de WCs:%i\n",aux->imo.wcsI);
				printf("Permite Animais:%c\n",aux->imo.animaisI);
				printf("Ano de Construção:%i\n",aux->imo.anoI);
				printf("Inatividade:%s\n",aux->imo.inatividade);
				printf("Preço aluguer/mês:%f\n",aux->imo.precoI);
				printf("Classe Energética:%s\n",aux->imo.energiaI);
				printf("Observações:%s\n",aux->imo.observacoesI);
				printf("\n");
		}
		printf("Sem imoveis disponiveis para alugar!\n");
	}
}
void aluguerporimovel(ELEMT *inifila,char morada[]){
	ELEMT *aux=NULL;
	
	printf("Alugueres efetuados do imovel com morada:%s\n",morada);
	
	for(aux=inifila;aux!=NULL;aux=aux->seguinte){
		if(strcmp(aux->alu.moradaa,morada)==0){
			printf("Data de Inicio:%s\n",aux->alu.datainicio);
			printf("Data de Fim:%s\n",aux->alu.datafim);
			printf("Nome Cliente:%s\n\n",aux->alu.nomee);
		}
		printf("Nada registado!\n");
	}
}
void escreveralubinario(ELEMT *inifila,const char *infoaluguer){
	FILE *fp=NULL;
	ELEMT *aux = inifila;
	
	fp=fopen("infoaluguer.dat","ab");
	
	if(fp==NULL){
		printf("ERRO ao abrir o ficheiro!\n");
		return ;
	}
	
	while(aux!=NULL){
		fwrite(&aux->alu,sizeof(ALUGUER),1,fp);
		aux = aux->seguinte;
	}
	fclose(fp);
}

void leralubinario(ELEMT **inifila){
	FILE *fp=NULL;
	ALUGUER newAluguer;
	
	fp=fopen("infoaluguer.dat","rb");
	
	if(fp==NULL){
		printf("ERRO ao abrir o ficheiro!\n");
		return;
	}
		
	while(fread(&newAluguer,sizeof(ALUGUER),1,fp)){
		adicionaraluguer(inifila,newAluguer);
		
	}
	fclose(fp);
}
















