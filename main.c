#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "imovel.h"
#include "menu.h"
#include "clientes.h"
#include "aluguer.h"
#include <string.h>


int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	ELEMENTO *inilista=NULL;
	IMOVEL newinfo;
	ELE *ini=NULL;
	CLIENTES newCliente;
	ELEMT *inifila=NULL;
	ALUGUER newAluguer;
	//ALUGUER alu;
	float novo_preco=0;
	int op1=0,op2=0,op3=0,op4=0,op5=0,op6=0,numero=0;
	char cidade[100],tipoI[20],animal[2],morada[100],nova_obser[200],inatividade[3],tipo[10];
	char novo_email[200],nomeCliente[100],pais[100];
	int novo_ntele=0,nif=0;
	
do{
	op3=MenuCate();
	system("cls");
	switch(op3){
		case 0:
			printf("Volte Sempre!\n");
			break;
		case 1:
			do{
				op1=MenuGeral();
				system("cls");
				switch(op1){
					case 0:
						printf("Voltar para menu anterior!\n");
						system("cls");
						break;
					case 1:
						getdados(&newinfo);
						inseririni(&inilista,newinfo);
						system("cls");
					break;
					case 2:
						printf("Alteracao preco e a observacao do imovel\n");
						printf("Introduza a morada do imovel:\n");
						fflush(stdin);
						fgets(morada,100,stdin);
						printf("Introduza novo preco:\n");
						fflush(stdin);
						scanf("%f",&novo_preco);
						printf("Introduza nova observacao:\n");
						fflush(stdin);
						fgets(nova_obser,200,stdin);
						alterarinfoimovel(inilista,morada,novo_preco,nova_obser);
						system("cls");
					break;
					case 3:
						do{
							op2=MenuListar();
							system("cls");
							switch(op2){
								case 0:
									printf("Voltar para o menu anterior!\n");
									system("cls");
									break;
								case 1:
									listarimovelgeral(inilista);
									break;
								case 2:
									listarcrespreco(inilista);
									break;
								case 3:
									decimoano(inilista);
									break;
								case 4:
									printf("Imovel com ou sem animal:\n");
									fflush(stdin);
									scanf("%c",&animal);
									imovelanimal(inilista,animal);
									break;
								case 5:
									printf("Introduza a cidade:\n");
									fflush(stdin);
									fgets(cidade,100,stdin);
									listarporcidade(inilista,cidade);	
									break;
								case 6:
									printf("Tipo de Imóvel:\n");
									fflush(stdin);
									fgets(tipoI,20,stdin);
									listarportipo(inilista,tipoI);
									break;
				
								default:
									printf("Opção inválida!\n");
							}	
						}while(op2!=0);
						break;
					case 4:
						printf("Alterar inatividade do imovel\n");
						printf("Introduza a morada do imovel:\n");
						fflush(stdin);
						fgets(morada,100,stdin);
						printf("Inatividade:\n");
						fflush(stdin);
						fgets(inatividade,3,stdin);
						alterarinatividade(inilista,morada,inatividade);
						break;
					case 5:
						do{
							op4=MenuFichei();
							system("cls");
							switch(op4){
								case 0:
									printf("Voltar para o menu anterior!\n");
									system("cls");
									break;
								case 1:
									escreverimobinario(inilista, "infoimovel.dat");
									break;
								case 2:
									lerimobinario(&inilista);
									
									break;
								default:
									printf("Opcao invalida!\n");
							}
						}while(op4!=0);
						break;
				}
				
			}while(op1!=0);
			break;
		case 2:
			do{
				op5=MenuClientes();
				system("cls");
				switch(op5){
					case 0:
						printf("Voltar para trás\n");
						system("cls");
						break;
					case 1:
						dadosClientes(&newCliente);
						adicionarCliente(&ini,newCliente);
						break;
					case 2:
						printf("Alterar informacoes!\n");
						printf("Introduza o nome:\n");
						fflush(stdin);
						fgets(nomeCliente,100,stdin);
						printf("Novo email:\n");
						fflush(stdin);
						fgets(novo_email,200,stdin);
						printf("Novo nºtelefone:\n");
						fflush(stdin);
						scanf("%i",&novo_ntele);
						alterarinfocliente(ini,nomeCliente,novo_ntele,novo_email);
						break;
					case 3:
						listarClientes(ini);
						break;
					case 4:
						inserirClienteOrdenado(newCliente,&ini);
						break;
					case 5:
						printf("Introduza o pais:\n");
						fflush(stdin);
						fgets(pais,100,stdin);
						clientesporpais(ini,pais);
						break;
					case 6:
						printf("Introduza o nif:\n");
						fflush(stdin);
						scanf("%i",&nif);
						clientespornif(ini,nif);
						break;
					case 7:
						do{
							op4=MenuFichei();
							system("cls");
							switch(op4){
								case 0:
									printf("Voltar para trás\n");
									system("cls");
									break;
								case 1:
									escreverclibinario(ini,"infocliente.dat");
									break;
								case 2:
									lerclibinario(&ini);
									
									break;
								default:
									printf("Opcao inválida");
							}
						}while(op4!=0);
						break;
					default:
						printf("Opcao inválida!\n");
				}
			}while(op5!=0);
			break;
		case 3:
			do{
				op6=MenuAluguer();
				system("cls");
				
				switch(op6){
					case 0:
						printf("Voltar para trás\n");
						system("cls");
						break;
					case 1:
						getdadosalu(&inilista,&newAluguer,newinfo);
						adicionaraluguer(&inifila,newAluguer);
						break;
					case 2:
						aluguer_ativo(inifila);
						break;
					case 3:
						aluguer_pornif(inifila,nif);
						break;
					case 4:
						imoveisparaaluguer(inilista,tipo);
						break;
					case 5:
						aluguerporimovel(inifila,morada);
						break;
					case 6:
						do{
							op4=MenuFichei();
							system("cls");
							switch(op4){
								case 0:
									printf("Voltar para trás\n");
									system("cls");
									break;
								case 1:
									escreveralubinario(inifila,"infoaluguer.dat");
									
									break;
								case 2:
									leralubinario(&inifila);
									
									break;
								default:
									printf("Opcao inválida");
							}
						}while(op4!=0);
						break;
					
					default:
						printf("Opcao invalida!\n");
				}
			}while(op6!=0);
		break;
	}
	
}while(op3!=0);
libertaLista(&inilista);
libertrarclientes(ini);
	
		
	return 0;
}
