#include <stdio.h>
#include <stdlib.h>
#include "imovel.h"
#include <locale.h>
#include <string.h>

int getdados(IMOVEL *newinfo){
	setlocale(LC_ALL,"Portuguese");
	printf("Dados do Imóvel:\n\n");
	fflush(stdin);
	printf("Morada Completa:");
	printf("\n");
	fflush(stdin);
	fgets(newinfo->moradaI,100,stdin);
	printf("Cidade:");
	printf("\n");
	fflush(stdin);
	fgets(newinfo->cidadeI,100,stdin);
	printf("Freguesia:");
	printf("\n");
	fflush(stdin);
	fgets(newinfo->freguesiaI,100,stdin);
	printf("Tipo de Imóvel:");
	printf("\n");
	fflush(stdin);
	fgets(newinfo->tipoI,10,stdin);
	printf("Área:");
	printf("\n");
	fflush(stdin);
	scanf("%f",&newinfo->areaI);
	printf("Numero de WCs:");
	printf("\n");
	fflush(stdin);
	scanf("%i",&newinfo->wcsI);
	printf("Ano de Construção:");
	printf("\n");
	fflush(stdin);
	scanf("%i",&newinfo->anoI);
	printf("Inativo?:");
	printf("\n");
	fflush(stdin);
	fgets(newinfo->inatividade,3,stdin);
	printf("Permite Animais S/N :");
	printf("\n");
	fflush(stdin);
	scanf("%c",&newinfo->animaisI);
	printf("Preço aluguer/mês:");
	printf("\n");
	fflush(stdin);
	scanf("%f",&newinfo->precoI);
	printf("Classe Energética:");
	printf("\n");
	fflush(stdin);
	fgets(newinfo->energiaI,10,stdin);
	printf("Observações:");
	printf("\n");
	fgets(newinfo->observacoesI,200,stdin);
	return 0;
}
int inseririni(ELEMENTO **inilista,IMOVEL newinfo){
	setlocale(LC_ALL,"Portuguese");
	ELEMENTO *novo=NULL;
	
	novo=(ELEMENTO *)calloc(1,sizeof(ELEMENTO));
	if(novo==NULL){
		printf("Out of memory!\n");
		return;
	}
	novo->imo=newinfo;
	novo->seguinte=NULL;
	
	if(*inilista==NULL){
		*inilista=novo;
	}else{
		novo->seguinte=*inilista;
		*inilista=novo;
	}
	return 0;
}

void listarporcidade(ELEMENTO *inilista,char cidade[100]){
	setlocale(LC_ALL,"Portuguese");
	ELEMENTO *aux=NULL;
	
	if(inilista==NULL){
		printf("Lista vazia!\n");
		return;
	}
	for(aux=inilista;aux!=NULL;aux=aux->seguinte){
		if(strcmp(cidade,aux->imo.cidadeI)==0){
				printf("Dados do Imóvel:\n");
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
				printf("\n\n");
		}
	}	
}
void listarportipo(ELEMENTO *inilista,char tipoI[20]){
	setlocale(LC_ALL,"Portuguese");
	ELEMENTO *aux=NULL;
	
	if(inilista==NULL){
		printf("Lista vazia!\n");
		return;
	}
	for(aux=inilista;aux!=NULL;aux=aux->seguinte){
		if(strcmp(tipoI,aux->imo.tipoI)==0){
				printf("Dados do Imóvel:\n");
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
				printf("\n\n");
		}
	}	
}

void imovelanimal(ELEMENTO *inilista,char animal[1]){
	ELEMENTO *aux=NULL;
	
	if(inilista==NULL){
		printf("Lista vazia!\n");
		return;
	}
	for(aux=inilista;aux!=NULL;aux=aux->seguinte){
		if(strcmp(animal,aux->imo.animaisI)==0){
			printf("Dados do Imóvel:\n");
				printf("Morada Completa:%s\n",aux->imo.moradaI);
				printf("Cidade:%s\n",aux->imo.cidadeI);
				printf("Freguesia:%s\n",aux->imo.freguesiaI);
				printf("Tipo de Imóvel:%s\n",aux->imo.tipoI);
				printf("Área:%f\n",aux->imo.areaI);
				printf("Numero de WCs:%i\n",aux->imo.wcsI);
				printf("Permite Animal:%c\n",aux->imo.animaisI);
				printf("Ano de Construção:%i\n",aux->imo.anoI);
				printf("Inatividade:%s\n",aux->imo.inatividade);
				printf("Preço aluguer/mês:%f\n",aux->imo.precoI);
				printf("Classe Energética:%s\n",aux->imo.energiaI);
				printf("Observações:%s\n",aux->imo.observacoesI);
				printf("\n\n");
		}
	}
}

void libertaLista(ELEMENTO **inilista){
	ELEMENTO *aux=NULL;
	ELEMENTO *proximo=NULL;
	
	aux=*inilista;
	*inilista=NULL;
	
	while(aux!=NULL){
		proximo = aux->seguinte;
		free(aux);
		aux=proximo;
	}
}
void listarimovelgeral(ELEMENTO *inilista){
	ELEMENTO *aux=NULL;
	
	if(inilista==NULL){
		printf("Lista Vazia!\n");
	}else{
		aux=inilista;
		while(aux!=NULL){
				printf("Dados do Imóvel:\n");
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
				printf("\n\n");
				
				aux=aux->seguinte;
		}
	}
}
void removerimovel(ELEMENTO **inilista,char morada[100]){
	ELEMENTO *current = *inilista;
	ELEMENTO *next = NULL;
	
	while(current!=NULL){
		if(current->imo.moradaI == morada){
			if(next == NULL){
				*inilista = current->seguinte;
			}else{
				next->seguinte = current->seguinte;
			}
			free(current);
			printf("Imovel removido!\n");
			return;
		}
		next = current;
		current = current->seguinte;
	}
}
void escreverimobinario(ELEMENTO *inilista,const char *infoimovel){
	FILE *fp=NULL;
	ELEMENTO *aux = inilista;
	fp=fopen("infoimovel.dat","ab");
	
	if(fp==NULL){
		printf("ERRO ao abrir o ficheiro!\n");
		return ;
	}
	
	while(aux!=NULL){
		fwrite(&aux->imo,sizeof(IMOVEL),1,fp);
		aux = aux->seguinte;
	}
	fclose(fp);
}
void lerimobinario(ELEMENTO **inilista){
	FILE *fp=NULL;
	IMOVEL newinfo;
	fp=fopen("infoimovel.dat","rb");
	
	if(fp==NULL){
		printf("ERRO ao abrir o ficheiro!\n");
		return;
	}
	
	
	while(fread(&newinfo,sizeof(IMOVEL),1,fp)){
		inseririni(inilista,newinfo);
	}

	fclose(fp);
}

void alterarinfoimovel(ELEMENTO *inilista,char *morada,float novo_preco,char *nova_obser){
	ELEMENTO *aux=NULL;
		
	if(inilista == NULL){
		printf("Lista vazia!\n");
		return;
	}
	
	for(aux=inilista;aux!=NULL;aux=aux->seguinte){
		if(strcmp(morada,aux->imo.moradaI)==0){
			aux->imo.precoI=novo_preco;
			strncpy(aux->imo.observacoesI,nova_obser,sizeof(aux->imo.observacoesI));
			printf("Informacoes alteradas com sucesso!\n");
			return;
		}
	}
	printf("Imovel indisponível!\n");	
}
void alterarinatividade(ELEMENTO *inilista,char *morada,char *inatividade){
	ELEMENTO *aux=NULL;
		
	if(inilista == NULL){
		printf("Lista vazia!\n");
		return;
	}
	
	for(aux=inilista;aux!=NULL;aux=aux->seguinte){
		if(strcmp(morada,aux->imo.moradaI)==0){
			strncpy(aux->imo.inatividade,inatividade,sizeof(aux->imo.inatividade));
			printf("Informacoes alteradas com sucesso!\n");
			return;
		}
	}
	printf("Imovel indisponível!\n");	
}
void listarcrespreco(ELEMENTO *inilista){
	ELEMENTO *atual,*anterior,*aux;
	
	if(inilista==NULL){
		printf("Lista vazia!\n");
		return;
	}
	for(atual=inilista->seguinte;atual!=NULL;atual=atual->seguinte){
		anterior=inilista;
		
		while(anterior!=atual && anterior->imo.precoI<=atual->imo.precoI){
			anterior=anterior->seguinte;
		}
		if(anterior!=atual){
			aux=atual;
			atual=atual->seguinte;
			
			aux->seguinte=NULL;
			
			aux->seguinte=anterior->seguinte;
			anterior->seguinte=aux;
		}
	}
	printf("Lista de imoveis por ordem crescente de preco:\n");
    	for (aux = inilista; aux != NULL; aux = aux->seguinte) {
        	printf("Dados do Imovel:\n");
        	printf("Morada Completa: %s\n", aux->imo.moradaI);
        	printf("Cidade: %s\n", aux->imo.cidadeI);
        	printf("Freguesia: %s\n", aux->imo.freguesiaI);
        	printf("Tipo de Imovel: %s\n", aux->imo.tipoI);
        	printf("Area: %f\n", aux->imo.areaI);
        	printf("Numero de WCs: %i\n", aux->imo.wcsI);
        	printf("Permite Animal: %c\n", aux->imo.animaisI[0]);
        	printf("Ano de Construcao: %i\n", aux->imo.anoI);
        	printf("Inatividade:%s\n",aux->imo.inatividade);
        	printf("Preco aluguer/mes: %f\n", aux->imo.precoI);
        	printf("Classe Energetica: %s\n", aux->imo.energiaI);
        	printf("Observacoes: %s\n\n", aux->imo.observacoesI);
	}
}
void decimoano(ELEMENTO *inilista){
    ELEMENTO *aux1, *aux2;
    IMOVEL temp;
    
    if(inilista == NULL){
        printf("Lista vazia!\n");
        return;
    }
    for(aux1 = inilista; aux1->seguinte != NULL; aux1 = aux1->seguinte){
        for(aux2 = aux1->seguinte; aux2 != NULL; aux2 = aux2->seguinte){
            if(aux1->imo.anoI < aux2->imo.anoI){
                
                temp = aux1->imo;
                aux1->imo = aux2->imo;
                aux2->imo = temp;
            }
        }
    }
    printf("Lista de imoveis por ordem decrescente do ano de construcao:\n");
    for(aux1 = inilista; aux1 != NULL; aux1 = aux1->seguinte){
        printf("Dados do Imovel:\n");
        printf("Morada Completa:%s\n",aux1->imo.moradaI);
        printf("Cidade:%s\n",aux1->imo.cidadeI);
        printf("Freguesia:%s\n",aux1->imo.freguesiaI);
        printf("Tipo de Imovel:%s\n",aux1->imo.tipoI);
        printf("Area:%f\n",aux1->imo.areaI);
        printf("Numero de WCs:%i\n",aux1->imo.wcsI);
        printf("Permite Animal:%c\n",aux1->imo.animaisI);
        printf("Ano de Construcao:%i\n",aux1->imo.anoI);
        printf("Inatividade:%s\n",aux1->imo.inatividade);
        printf("Preco aluguer/mês:%f\n",aux1->imo.precoI);
        printf("Classe Energetica:%s\n",aux1->imo.energiaI);
        printf("Observacoes:%s\n",aux1->imo.observacoesI);
        printf("\n\n");
    }
}

























