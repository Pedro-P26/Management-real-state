#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <locale.h>
#include <string.h>


int MenuGeral(){
	setlocale(LC_ALL,"Portuguese");
	int op1=0;

	printf("1-Adicionar Imóvel\n");
	printf("2-ALterar informação Imóvel\n");
	printf("3-Listar Imóvel\n");
	printf("4-Inativar Imovel\n");
	printf("5-Ficheiro Binario\n");
	printf("0-Voltar para trás\n");
	fflush(stdin);
	scanf("%i",&op1);
	
	return op1;
}
int MenuListar(){
	setlocale(LC_ALL,"Portuguese");
	int op2=0;
	printf("1-Listar imóveis geral\n");
	printf("2-Listar imóveis por ordem crescente do preço\n");
	printf("3-Listar imóveis por ordem decrescente do ano de construção\n");
	printf("4-Listar imóveis com ou sem animais de estimação\n");
	printf("5-Listar imóveis de uma determinada cidade\n");
	printf("6-Listar imóveis de um determinado tipo\n");
	printf("0-Voltar para trás\n");
	fflush(stdin);
	scanf("%i",&op2);
	
	return op2;
}
int MenuFichei(){
	setlocale(LC_ALL,"Portuguese");
	int op4=0;
	
	printf("1-Armazenar a informação\n");
	printf("2-Ler a informação\n");
	printf("0-Voltar para trás\n");
	fflush(stdin);
	scanf("%i",&op4);
	
	return op4;
}
int MenuCate(){
	setlocale(LC_ALL,"Portuguese");
	int op3=0;
	printf("\t\tIMOBILIARIO.LDA\n\n");
	printf("BEM VINDO AO ALUGUER IMOBILIARIO!\n\n");
	
	printf("1-Imóveis\n");
	printf("2-Clientes\n");
	printf("3-Aluguer\n");
	printf("0-Sair\n");
	fflush(stdin);
	scanf("%i",&op3);
	
	return op3;
}
int MenuClientes(){
	setlocale(LC_ALL,"Portuguese");
	int op5=0;
	
	printf("1-Adicionar Cliente\n");
	printf("2-Alterar dados do cliente\n");
	printf("3-Listar Clientes Geral\n");
	printf("4-Listar clientes por ordem alfabética do nome\n");
	printf("5-Listar todos os clientes de determinado país\n");
	printf("6-Dados do cliente pelo nif\n");
	printf("7-Ficheiro Binario\n");
	printf("0-Voltar para trás\n");
	fflush(stdin);
	scanf("%i",&op5);
	
	return op5;
}

int MenuAluguer(){
	setlocale(LC_ALL,"Portuguese");
	int op6=0;
	
	printf("1-Adicionar Aluguer\n");
	printf("2-Aluguer Ativo\n");
	printf("3-Aluguer por nif\n");
	printf("4-Imoveis para aluguer\n");
	printf("5-Aluguer por imóveis\n");
	printf("6-Ficheiro Binario\n");
	printf("0-Voltar para trás\n");
	fflush(stdin);
	scanf("%i",&op6);
	
	return op6;
}















