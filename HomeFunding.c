#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Precos e tipos de materiais de construcao retirados do site: https://www.tocaobra.com.br/categoria/materiais-de-construcao

//Variaveis de Menu
int menuInicial, menuCadastro, menuProjetista, menuDoacao, menuEdicao,  menuEdicao2;
int menuEdicaoProjetista, menuEdicaoProjetista2, menuDoacao, menuDoacao2,  finalizaCarrinho;


//Variaveis dos tipos de projetos
struct TipoProjeto
{
	char nomeProjeto[30];
	int aco, tijolo, madeira, telha;
	float areia, cal, cimento, argamassa, custoAreia, custoCal, custoAco, custoTijolo, custoMadeira, custoCimento, custoArgamassa, custoTelha, custo;
};
struct TipoProjeto projeto[50];
int qtdProjetos, voltaProj, i, iTotal, saveProj, editaProj; 
char nomeProjeto[30];


//Variveis dos projetistas
struct Projeto
{
	char nomeProjetista[30], beneficiarioProjetista[30], responsavelProjetista[30], nomeProjetoEscolhido[30];
	int acoProjeto, tijoloProjeto, madeiraProjeto, telhaProjeto, qtdCasas;
	float areiaProjeto, calProjeto, cimentoProjeto, argamassaProjeto, custo, valorDoado, valorDoacao;
};
struct Projeto projetista[50];
int qtdProjetista, voltaProjetista, k, kTotal, saveProjetista, editaProjetista; 
char escolhaProjeto[30], nomeProjetoProjetista[30];


//Variaveis das doacoes
struct Doacao
{
	char nomeProjetoDoacao[30];
	float valorDoacao;	
};
struct Doacao doacao[50];
char nomeProjetoDoacao[30], retirarDoacaoCart[30];
int x, xTotal, valorDoado;
float valorDoado2, valorDoado3, valorTotal, retirarValorDoado;


int main()
{
    do
    {
    	menuInicio:
    	printf("**********************************************\n");
		printf("*                 HomeFunding                *\n");
		printf("**********************************************\n");
		printf("*                Menu de Opcoes              *\n");
		printf("*                                            *\n");
		printf("*[1] Intranet HomeFunding                    *\n");
		printf("*[2] Projetistas                             *\n");
		printf("*[3] Doadores                                *\n");
		printf("*[4] Finalizar Programa                      *\n");
		printf("*                                            *\n");
		printf("**********************************************\n");
    	scanf("%d", &menuInicial);
        system("cls || clear");

        switch(menuInicial)
        {
            case 1:
            	do
            		{
            			MenuInicio1:
						printf("**********************************************\n");
						printf("*             Intranet HomeFunding           *\n");
						printf("**********************************************\n");
						printf("*                Menu de Opcoes              *\n");
						printf("*                                            *\n");
						printf("*[1] Cadastro Tipos de Projetos              *\n");
						printf("*[2] Edicao de Tipos de Projetos             *\n");
						printf("*[3] Voltar ao Menu Principal                *\n");
						printf("*                                            *\n");
						printf("**********************************************\n");
            			scanf("%d", &menuCadastro);	
            			system("cls || clear");
            			
            			switch (menuCadastro)
            				{
            					case 1:
            						cadastroTipoProjeto();
            						break;
            						
            					case 2:
            						editarTipoProjeto();
            						break;
            						
            					case 3:
            						goto menuInicio; //Volta a linha 50 inicio do menu principal
            						
            					case 0:
								default:
									system("cls || clear");
            						printf("Opcao Invalida. Tente novamente.\n");
            						goto MenuInicio1; //Voltar a linha 70 inicio do menu da intranet da empresa
							}
					} while (menuCadastro);
                break;

            case 2:
                do 
				{
					menuInicio2:
					printf("**********************************************\n");
					printf("*                 Projetistas                *\n");
					printf("**********************************************\n");
					printf("*                Menu de Opcoes              *\n");
					printf("*                                            *\n");
					printf("*[1] Cadastro de novo projeto                *\n");
					printf("*[2] Edicao de projeto                       *\n");
					printf("*[3] Voltar ao Menu Principal                *\n");
					printf("*                                            *\n");
					printf("**********************************************\n");
            		scanf("%d", &menuProjetista);
					system("cls || clear");
					
					switch (menuProjetista)
            				{
            					case 1:
            						cadastroProjetista();
            						break;
            						
            					case 2:
            						editarProjetista();
            						break;
            						
            					case 3:
            						goto menuInicio; //Volta a linha 50 inicio do menu principal
            						
            					case 0:
								default:
            						system("cls || clear");
            						printf("Opcao Invalida. Tente novamente.\n");
            						goto menuInicio2; //Volta a linha 109 inicio do menu dos criadores de projeto
							}	
				} while (menuProjetista);
                break;

            case 3:
                menuDoacaoP();
                break;

            case 4:
                printf("Obrigado!");
                return 0;
			
			case 0:
			default:
                printf("Opcao Invalida. Tente novamente.\n");
            	goto menuInicio; //Volta a linha 50 inicio do menu principal
        }
    } while(menuInicial);
}

//Funcao que cadastra novos tipos de projetos na lista principal de tipos de projetos = i, o cadastro recebe novos valores a cada registro
int cadastroTipoProjeto ()
{
	cadastroProjInicio:
	system("cls || clear");
    
    printf("Quantos tipos de projetos deseja cadastrar?\n");
    scanf("%d", &qtdProjetos);
    
    while (qtdProjetos <= 0)
    	{
    		TenteNovamente9:
    		printf("\nDeseja retornar ao menu anterior?\n[1]Sim \n[2]Nao\n");
    		scanf("%d", &voltaProj);
    		
    		switch (voltaProj)
    			{
    				case 1:
    					system("cls || clear");
						return 0;
						
					case 2:
						goto cadastroProjInicio; //Volta a linha 163 inicio da funcao de cadastro de tipos de projetos
						
					case 0:
					default:
						printf("Opcao Invalida. Tente novamente.\n");
            			goto TenteNovamente9; //Volta a linha 171 para que o usuario tente novamente caso digite um valor diferente das opcoes fornecidas
				}
		}
		
    for (i=i ; i<qtdProjetos+iTotal ; i++)
    	{
    		system("cls || clear");
    		printf("Cadastro de Tipo de Projeto");
    		printf("\n-------------------------------------");
    		fflush(stdin);
		    printf("\nNome do tipo de projeto: ");
		    gets(projeto[i].nomeProjeto);
		    
		    printf("\nCadastro de Material do Tipo de Projeto");
		    printf("\n-------------------------------------");
		    
		    //Retirados do site: https://www.tocaobra.com.br/categoria/materiais-de-construcao
		    printf("\nQuantidade de areia em quilos que sera utilizado?\n");
		    scanf("%f", &projeto[i].areia);
		    projeto[i].custoAreia = projeto[i].areia * 0.06;
		    
		    printf("\nQuantidade de cal em quilos que sera utilizado?\n");
		    scanf("%f", &projeto[i].cal);
		    projeto[i].custoCal = projeto[i].cal * 0.75;
		    
		    printf("\nQuantidade de vergalhoes de aco em unidades que sera utilizado?\n");
		    scanf("%d", &projeto[i].aco);
		    projeto[i].custoAco = projeto[i].aco * 28.16;
		    
		    printf("\nQuantidade de tijolos em unidades que sera utilizado?\n");
		    scanf("%d", &projeto[i].tijolo);
		    projeto[i].custoTijolo = projeto[i].tijolo * 2.25;
		    
			printf("\nQuantidade de madeira em unidades que sera utilizado?\n");
		    scanf("%d", &projeto[i].madeira);
		    projeto[i].custoMadeira = projeto[i].madeira * 7.70;
		    
		    printf("\nQuantidade de cimento em quilos que sera utilizado?\n");
		    scanf("%f", &projeto[i].cimento);
		    projeto[i].custoCimento = projeto[i].cimento * 0.80;
		    
		    printf("\nQuantidade de argamassa em quilos que sera utilizado?\n");
		    scanf("%f", &projeto[i].argamassa);
		    projeto[i].custoArgamassa = projeto[i].argamassa * 1.11;
		    
		    printf("\nQuantidade de telha em unidades que sera utilizado?\n");
		    scanf("%d", &projeto[i].telha);
		    projeto[i].custoTelha = projeto[i].telha * 34;
		    
		    projeto[i].custo = projeto[i].custoAreia + projeto[i].custoCal + projeto[i].custoAco + projeto[i].custoTijolo + projeto[i].custoMadeira + projeto[i].custoCimento + projeto[i].custoArgamassa + projeto[i].custoTelha;
    	}
    	
    iTotal = iTotal + qtdProjetos;
    
	system("cls || clear");	
	printf("Confirme seu cadastro");
	for (i=i-qtdProjetos ; i<iTotal ; i++)
		{	
			printf("\n-------------------------------------");
		    printf("\nTipo de Projeto: %s\n", projeto[i].nomeProjeto);
			printf("\nLista de Materiais\n");
			printf("\n-> %.2f kg de Areia", projeto[i].areia);
			printf("\n-> %.2f kg de Cal", projeto[i].cal);
			printf("\n-> %d unid. de Aco", projeto[i].aco);
			printf("\n-> %d unid. de Tijolo", projeto[i].tijolo);
		    printf("\n-> %d unid. de Madeira", projeto[i].madeira);
		    printf("\n-> %.2f kg de Cimento", projeto[i].cimento);
		    printf("\n-> %.2f kg de Argamassa", projeto[i].argamassa);
		    printf("\n-> %d unid. de Telha", projeto[i].telha);
		    printf("\n\n-> Custo do tipo de projeto: R$%.2f", projeto[i].custo);
		    
		}
    printf("\n-------------------------------------");
    
    TenteNovamente1:
    printf ("\n\nDeseja salvar seu(s) registro(s)? \n[1]Salvar e voltar ao menu anterior. \n[2]Nao. Editar registro(s).\n");
    scanf("%d", &saveProj);
    
    switch (saveProj)
    	{
    		case 1:
    			system("cls || clear");
    			printf("Registro salvo com sucesso!\n\n");
    			break;
    			
    		case 2:
    			iTotal = iTotal - qtdProjetos;
    			i = i - qtdProjetos;
    			goto cadastroProjInicio; //Volta a linha 163 inicio da funcao de cadastro de tipos de projetos
    		
    		case 0:
			default:
    			printf("Opcao Invalida. Tente novamente.\n");
    			goto TenteNovamente1; //Volta a linha 226 para que o usuario tente novamente caso digite um valor diferente das opcoes fornecidas
		} 
}

//Funcao para edicao dos tipos de projetos cadastrados na lista principal de tipos de projetos = i
int editarTipoProjeto()
{
	editarTipoProjetoInicio:
	system("cls || clear");
		
	do
    {
    	menuEdicao:
        system("cls || clear");
        menuEdicao2:
    	printf("**********************************************\n");
		printf("*             Intranet HomeFunding           *\n");
		printf("**********************************************\n");
		printf("*                Menu de Opcoes              *\n");
		printf("*                                            *\n");
		printf("*[1] Ver lista completa de tipos de projetos *\n");
		printf("*[2] Buscar tipo de projeto por nome         *\n");
		printf("*[3] Remover tipo de projeto da lista        *\n");
		printf("*[4] Voltar ao Menu Principal                *\n");
		printf("*                                            *\n");
		printf("**********************************************\n");
    	scanf("%d", &menuEdicao);
        system("cls || clear");
        
        switch (menuEdicao)
        	{
        		case 1:
        			if(iTotal == 0)
        				{
        					printf("**********************************************\n");
        					printf("*      Nenhum tipo de projeto cadastrado     *\n");
							goto menuEdicao2; //Volta para a linha 259 inicio do menu de edicao dos tipos de projetos sem system clear	
						}	
        			printf("**********************************************\n");
        			EscolhaEdicaoInicio:
        			for (i=0 ; i<iTotal ; i++)
					{	
					    printf("Tipo de Projeto: %s\n", projeto[i].nomeProjeto);
						printf("\nLista de Materiais\n");
					    printf("\n-> %.2f kg de Areia", projeto[i].areia);
						printf("\n-> %.2f kg de Cal", projeto[i].cal);
						printf("\n-> %d unid. de Aco", projeto[i].aco);
						printf("\n-> %d unid. de Tijolo", projeto[i].tijolo);
					    printf("\n-> %d unid. de Madeira", projeto[i].madeira);
					    printf("\n-> %.2f kg de Cimento", projeto[i].cimento);
					    printf("\n-> %.2f kg de Argamassa", projeto[i].argamassa);
					    printf("\n-> %d unid. de Telha", projeto[i].telha);
					    printf("\n\n-> Custo do projeto: R$%.2f", projeto[i].custo);
					    printf("\n**********************************************\n");
						
					}
					
					do
					{
						TenteNovamente2:
						printf("\nDigite a opcao: \n[1] Editar tipo de projeto \n[2] Remover item da lista de tipos de projetos \n[3] Voltar ao menu anterior \n");
						scanf("%d", &menuEdicao2);
						
						switch (menuEdicao2)
							{
								case 1:
									BuscaInicio:
									if(iTotal == 0)
				        				{
				        					printf("**********************************************\n");
				        					printf("*      Nenhum tipo de projeto cadastrado     *\n");
											goto menuEdicao2; //Volta para a linha 259 inicio do menu de edicao dos tipos de projetos sem system clear	
										}
									fflush(stdin);
									printf("Qual o tipo de projeto deseja editar?\n");
									gets(nomeProjeto);
									fflush(stdin);
									
									for (i=0 ; i<iTotal ; i++)
										{
											if (strcmp (nomeProjeto, projeto[i].nomeProjeto) == 0)
												{
													EdicaoInicio:
													system("cls || clear");
													printf("Nome do tipo de projeto escolhido: %s\n", nomeProjeto);
													fflush(stdin);
													
												    printf("-------------------------------------\n");
										    		fflush(stdin);
												    printf("Novo nome do tipo de projeto: ");
												    gets(projeto[i].nomeProjeto);
												    printf("\nCadastro de Material do Tipo de Projeto");
												    printf("\n-------------------------------------");
												    
													//Retirados do site: https://www.tocaobra.com.br/categoria/materiais-de-construcao
												    printf("\nQuantidade de areia em quilos que sera utilizado?\n");
												    scanf("%f", &projeto[i].areia);
												    projeto[i].custoAreia = projeto[i].areia * 0.06;
												    
												    printf("\nQuantidade de cal em quilos que sera utilizado?\n");
												    scanf("%f", &projeto[i].cal);
												    projeto[i].custoCal = projeto[i].cal * 0.75;
												    
												    printf("\nQuantidade de vergalhoes de aco em unidades que sera utilizado?\n");
												    scanf("%d", &projeto[i].aco);
												    projeto[i].custoAco = projeto[i].aco * 28.16;
												    
												    printf("\nQuantidade de tijolos em unidades que sera utilizado?\n");
												    scanf("%d", &projeto[i].tijolo);
												    projeto[i].custoTijolo = projeto[i].tijolo * 2.25;
												    
													printf("\nQuantidade de madeira em unidades que sera utilizado?\n");
												    scanf("%d", &projeto[i].madeira);
												    projeto[i].custoMadeira = projeto[i].madeira * 7.70;
												    
												    printf("\nQuantidade de cimento em quilos que sera utilizado?\n");
												    scanf("%f", &projeto[i].cimento);
												    projeto[i].custoCimento = projeto[i].cimento * 0.80;
												    
												    printf("\nQuantidade de argamassa em quilos que sera utilizado?\n");
												    scanf("%f", &projeto[i].argamassa);
												    projeto[i].custoArgamassa = projeto[i].argamassa * 1.11;
												    
												    printf("\nQuantidade de telha em unidades que sera utilizado?\n");
												    scanf("%d", &projeto[i].telha);
												    projeto[i].custoTelha = projeto[i].telha * 34;
												    
												    projeto[i].custo = projeto[i].custoAreia + projeto[i].custoCal + projeto[i].custoAco + projeto[i].custoTijolo + projeto[i].custoMadeira + projeto[i].custoCimento + projeto[i].custoArgamassa + projeto[i].custoTelha;
												    
												    system("cls || clear");
												    printf("-------------------------------------");
													printf("\nTipo de Projeto: %s\n", projeto[i].nomeProjeto);
													printf("\nLista de Materiais\n");
													printf("\n-> %.2f kg de Areia", projeto[i].areia);
													printf("\n-> %.2f kg de Cal", projeto[i].cal);
													printf("\n-> %d unid. de Aco", projeto[i].aco);
													printf("\n-> %d unid. de Tijolo", projeto[i].tijolo);
												    printf("\n-> %d unid. de Madeira", projeto[i].madeira);
												    printf("\n-> %.2f kg de Cimento", projeto[i].cimento);
												    printf("\n-> %.2f kg de Argamassa", projeto[i].argamassa);
												    printf("\n-> %d unid. de Telha", projeto[i].telha);
												    printf("\n\n-> Custo do tipo de projeto: R$%.2f", projeto[i].custo);	
												    printf("\n-------------------------------------");
												    
												    TenteNovamente3:
												    printf ("\n\nDeseja alterar seu registro? \n[1]Alterar e voltar ao menu anterior. \n[2]Nao. Editar registro.\n");
												    scanf("%d", &editaProj);
												    
												    switch (editaProj)
												    	{
												    		case 1:
												    			system("cls || clear");
												    			printf("Registro alterado com sucesso!\n\n");
												    			goto menuEdicao2; //Volta a linha 258 inicio do menu de edicao de tipo de projeto sem o system clear
												    			
												    		case 2:
												    			goto EdicaoInicio; //Volta a linha 298 inicio da edicao do projeto escolhido
																
															case 0:
															default:
												    			printf("Opcao Invalida. Tente novamente.\n");
																goto TenteNovamente3; //Volta a linha 326 para que o usuario tente novamente caso escolha fora das opcoes fornecidas
														} 
												}
										}
									break;
								
								case 2:
									printf("\n");
									goto inicioRemoverTipoProjeto; //Vai para linha 476 inicio da remoção de um item da lista de tipos de projetos
								
								case 3:
									goto menuEdicao; //Volta a linha 256 inicio do menu de edicao de tipo de projeto com system clear
									
								case 0:
								default:
									printf("Opcao Invalida. Tente novamente.\n");
									goto TenteNovamente2; //Volta a linha 281 para que o usuario tente novamente caso escolha fora das opcoes fornecidas
							}
					} while (menuEdicao2);
					break;
					
				case 2:
        			goto BuscaInicio; //Volta a linha 288 inicio do processo de edicao dos tipos de projetos
        		
        		case 3:
        			if(iTotal == 0)
        				{
        					printf("**********************************************\n");
        					printf("*      Nenhum tipo de projeto cadastrado     *\n");
							goto menuEdicao2; //Volta para a linha 259 inicio do menu de edicao dos tipos de projetos sem system clear	
						}
					
					system("cls || clear");
					inicioRemoverTipoProjeto:
					
					fflush(stdin);
					printf("Qual o tipo de projeto deseja remover?\n");
					gets(nomeProjeto);
					fflush(stdin);
									
        			for (i=0 ; i<iTotal ; i++)
						{
							if (strcmp (nomeProjeto, projeto[i].nomeProjeto) == 0)
								{
									if (iTotal == 1)
										{
											strcpy(projeto[i].nomeProjeto, "");
											projeto[i].areia = 0;
											projeto[i].cal = 0;
											projeto[i].aco = 0;
											projeto[i].tijolo = 0;
											projeto[i].madeira = 0;
											projeto[i].cimento = 0;
											projeto[i].argamassa = 0;
											projeto[i].telha = 0;
											projeto[i].custo = 0;
											
											iTotal = iTotal - 1;
											system("cls || clear");
							    			printf("Registro removido com sucesso!\n\n");
							    			goto menuEdicao2; //Volta a linha 258 inicio do menu de edicao de tipo de projeto sem o system clear
										}
											
									for (i=i ; i<iTotal ; i++)
										{
											strcpy(projeto[i].nomeProjeto, projeto[i+1].nomeProjeto);
											projeto[i].areia = projeto[i+1].areia;
											projeto[i].cal = projeto[i+1].cal;
											projeto[i].aco = projeto[i+1].aco;
											projeto[i].tijolo = projeto[i+1].tijolo;
											projeto[i].madeira = projeto[i+1].madeira;
											projeto[i].cimento = projeto[i+1].cimento;
											projeto[i].argamassa = projeto[i+1].argamassa;
											projeto[i].telha = projeto[i+1].telha;
											projeto[i].custo = projeto[i+1].custo;
										}
										
									i = i - 1;
									iTotal = iTotal - 1;
								}
						}
					
					system("cls || clear");
	    			printf("Registro removido com sucesso!\n\n");
	    			goto menuEdicao2; //Volta a linha 258 inicio do menu de edicao de tipo de projeto sem o system clear
        			
        		case 4:
        			return 0;
        		
        		case 0:
				default:
        			printf("Opcao Invalida. Tente novamente.\n");
        			goto menuEdicao2; //Volta a linha 258 inicio do menu de edicao de tipo de projeto sem o system clear
			}
	} while (menuEdicao);
}

//Funcao que cadastra novos projetos na lista principal de projetos = k, o cadastro recebe novos valores a cada registro
int cadastroProjetista ()
{
	cadastroProjetistaInicio:
	system("cls || clear");
    if(iTotal == 0)
		{
			printf("**********************************************\n");
			printf("*      Nenhum tipo de projeto cadastrado     *\n");	
			return 0;
		}
    printf("Quantos projetos deseja cadastrar?\n");
    scanf("%d", &qtdProjetista);
    
    while (qtdProjetista <= 0)
    	{
    		TenteNovamente10:
    		printf("\nDeseja retornar ao menu anterior?\n[1]Sim \n[2]Nao\n");
    		scanf("%d", &voltaProjetista);
    		
    		switch (voltaProjetista)
    			{
    				case 1:
    					system("cls || clear");
						return 0;
						
    				case 2:
    					goto cadastroProjetistaInicio; //Volta a linha 376 inicio do cadastro de um projeto
    					
    				case 0:
    				default:
    					printf("Opcao Invalida. Tente novamente.\n");
        				goto TenteNovamente10; //Volta a linha 385 para que o usuario tente novamente caso escolha fora das opcoes fornecidas
				}
		}
		
    for (k=k ; k<qtdProjetista+kTotal ; k++)
    	{
    		system("cls || clear");
    		printf("Cadastro de Projeto");
    		printf("\n-------------------------------------");
			fflush(stdin);
		    printf("\nNome do projeto: ");
		    gets(projetista[k].nomeProjetista);
		    
		    fflush(stdin);
		    printf("\nLugar / Pessoa que recebera o projeto: ");
		    gets(projetista[k].beneficiarioProjetista);
		    
		    fflush(stdin);
		    printf("\nNome do criador do projeto: ");
		    gets(projetista[k].responsavelProjetista);
			fflush(stdin);
			
			printf("\nEscolha o tipo de projeto");
			printf("\n-------------------------------------\n");
			for (i=0 ; i<iTotal ; i++)
				{	
					printf("Tipo de projeto: %s\n", projeto[i].nomeProjeto);
					printf("-------------------------------------\n");
				}
				
			gets(escolhaProjeto);
			fflush(stdin);
			
			printf("\nQuantas casas seram construidas?\n");
			scanf("%d", &projetista[k].qtdCasas);
						
			for (i=0 ; i<iTotal ; i++)
				{
					if (strcmp (escolhaProjeto, projeto[i].nomeProjeto) == 0)
						{
							strcpy(projetista[k].nomeProjetoEscolhido, projeto[i].nomeProjeto);
							projetista[k].areiaProjeto = projeto[i].areia * projetista[k].qtdCasas;
							projetista[k].calProjeto = projeto[i].cal * projetista[k].qtdCasas;
							projetista[k].acoProjeto = projeto[i].aco * projetista[k].qtdCasas;
							projetista[k].tijoloProjeto = projeto[i].tijolo * projetista[k].qtdCasas;
							projetista[k].madeiraProjeto = projeto[i].madeira * projetista[k].qtdCasas;
							projetista[k].cimentoProjeto = projeto[i].cimento * projetista[k].qtdCasas;
							projetista[k].argamassaProjeto = projeto[i].argamassa * projetista[k].qtdCasas;
							projetista[k].telhaProjeto = projeto[i].telha * projetista[k].qtdCasas;
							projetista[k].custo = projeto[i].custo * projetista[k].qtdCasas;
						}
				}
		}
	
	kTotal = kTotal + qtdProjetista;
		
	system("cls || clear");	
	printf("Confirme seu cadastro");
	for (k=k-qtdProjetista ; k<kTotal ; k++)
		{	
			printf("\n-------------------------------------");
		    printf("\nNome do projeto: %s\n", projetista[k].nomeProjetista);
			printf("\nLugar / Pessoa que recebera o projeto: %s\n", projetista[k].beneficiarioProjetista);
			printf("\nNome do criador do projeto: %s\n", projetista[k].responsavelProjetista);
			printf("\nTipo de projeto: %s\n", projetista[k].nomeProjetoEscolhido);
			printf("\nQuantidade de casas que deseja construir: %d\n", projetista[k].qtdCasas);
			printf("\nMateriais necessarios\n");
			printf("\n-> %.2f kg de Areia", projetista[k].areiaProjeto);
			printf("\n-> %.2f kg de Cal", projetista[k].calProjeto);
			printf("\n-> %d unid. de Aco", projetista[k].acoProjeto);
			printf("\n-> %d unid. de Tijolo", projetista[k].tijoloProjeto);
		    printf("\n-> %d unid. de Madeira", projetista[k].madeiraProjeto);
		    printf("\n-> %.2f kg de Cimento", projetista[k].cimentoProjeto);
		    printf("\n-> %.2f kg de Argamassa", projetista[k].argamassaProjeto);
		    printf("\n-> %d unid. de Telha", projetista[k].telhaProjeto);
		    printf("\n\n-> Custo do total do projeto: R$%.2f", projetista[k].custo);
		}
    printf("\n-------------------------------------");
    
    TenteNovamente4:
    printf ("\n\nDeseja salvar seu(s) registro(s)? \n[1]Salvar e voltar ao menu anterior. \n[2]Nao. Editar registro(s).\n");
    scanf("%d", &saveProjetista);
    
    switch (saveProjetista)
    	{
    		case 1:
    			system("cls || clear");
    			printf("Registro salvo com sucesso!\n\n");
    			break;
    			
    		case 2:
    			kTotal = kTotal - qtdProjetista;
    			k = k - qtdProjetista;
    			goto cadastroProjetistaInicio; //Volta a linha 376 inicio do cadastro de um projeto
    			
    		case 0:
			default:
    			printf("Opcao Invalida. Tente novamente.\n");
    			goto TenteNovamente4; //Volta a linha 462 para que o usuario tente novamente caso escolha fora das opcoes fornecidas
		}
}

//Funcao para edicao dos projetos cadastrados na lista principal de projetos = k
int editarProjetista ()
{
	editarTipoProjetistaInicio:
	system("cls || clear");
		
	do
    {
    	menuEdicaoProjetista:
        system("cls || clear");
        menuEdicaoProjetista2:
        printf("**********************************************\n");
		printf("*                 Projetistas                *\n");
		printf("**********************************************\n");
		printf("*                Menu de Opcoes              *\n");
		printf("*                                            *\n");
		printf("*[1] Ver lista de projetos                   *\n");
		printf("*[2] Buscar projeto por nome                 *\n");
		printf("*[3] Remover projeto da lista                *\n");
		printf("*[4] Voltar ao Menu Principal                *\n");
		printf("*                                            *\n");
		printf("**********************************************\n");
    	scanf("%d", &menuEdicaoProjetista);
        system("cls || clear");
        
        switch (menuEdicaoProjetista)
        	{
        		case 1:
        			if(kTotal == 0)
        				{
        					printf("**********************************************\n");
        					printf("*           Nenhum projeto cadastrado        *\n");
							goto menuEdicaoProjetista2; //Volta para a linha 516 inicio do menu de edicao dos projetos cadastrados sem system clear	
						}	
        			printf("**********************************************\n");
        			EscolhaEdicaoProjetistaInicio:
        			for (k=0 ; k<kTotal ; k++)
						{
			    			printf("Nome do Projeto: %s\n", projetista[k].nomeProjetista);
							printf("\nLugar / Pessoa que recebera o projeto: %s\n", projetista[k].beneficiarioProjetista);
							printf("\nNome do criador do projeto: %s\n", projetista[k].responsavelProjetista);
							printf("\nTipo de Projeto: %s\n", projetista[k].nomeProjetoEscolhido);
							printf("\nQuantidade de casas que deseja construir: %d\n", projetista[k].qtdCasas);
							printf("\nMateriais necessarios\n");
							printf("\n-> %.2f kg de Areia", projetista[k].areiaProjeto);
							printf("\n-> %.2f kg de Cal", projetista[k].calProjeto);
							printf("\n-> %d unid. de Aco", projetista[k].acoProjeto);
							printf("\n-> %d unid. de Tijolo", projetista[k].tijoloProjeto);
						    printf("\n-> %d unid. de Madeira", projetista[k].madeiraProjeto);
						    printf("\n-> %.2f kg de Cimento", projetista[k].cimentoProjeto);
						    printf("\n-> %.2f kg de Argamassa", projetista[k].argamassaProjeto);
						    printf("\n-> %d unid. de Telha", projetista[k].telhaProjeto);
						    printf("\n\n-> Custo do total do projeto: R$%.2f\n", projetista[k].custo);
						    printf("**********************************************\n");
						}
					
					do
					{
						TenteNovamente5:
						printf("Digite a opcao: \n[1] Editar Projeto \n[2] Remover item da lista de projetos \n[3] Voltar ao menu anterior \n\n");
						scanf("%d", &menuEdicaoProjetista2);
						
						switch (menuEdicaoProjetista2)
							{
								case 1:
									BuscaProjetistaInicio:
									if(kTotal == 0)
				        				{
				        					printf("**********************************************\n");
				        					printf("*           Nenhum projeto cadastrado        *\n");
											goto menuEdicaoProjetista2; //Volta para a linha 516 inicio do menu de edicao dos projetos cadastrados sem system clear	
										}
									fflush(stdin);
									printf("Qual projeto deseja editar?\n");
									gets(nomeProjetoProjetista);
									fflush(stdin);
									
									for (k=0 ; k<kTotal ; k++)
										{
											if (strcmp (nomeProjetoProjetista, projetista[k].nomeProjetista) == 0)
												{
													EdicaoProjetistaInicio:
													system("cls || clear");
													printf("Nome projeto escolhido: %s\n", nomeProjetoProjetista);
													fflush(stdin);
													
												    printf("-------------------------------------");
    		
												    printf("\nNome do projeto: ");
												    gets(projetista[k].nomeProjetista);
												    
												    fflush(stdin);
												    printf("\nLugar / Pessoa que recebera o projeto: ");
												    gets(projetista[k].beneficiarioProjetista);
												    
												    fflush(stdin);
												    printf("\nNome do criador do projeto: ");
												    gets(projetista[k].responsavelProjetista);
													fflush(stdin);
													
													printf("\nEscolha o tipo de projeto");
													printf("\n-------------------------------------\n");
													for (i=0 ; i<iTotal ; i++)
														{	
															printf("Tipo de Projeto: %s\n", projeto[i].nomeProjeto);
															printf("-------------------------------------\n");
														}
														
													gets(escolhaProjeto);
													fflush(stdin);
													
													printf("\nQuantas casas seram construidas?\n");
													scanf("%d", &projetista[k].qtdCasas);
			
													for (i=0 ; i<iTotal ; i++)
														{
															if (strcmp (escolhaProjeto, projeto[i].nomeProjeto) == 0)
																{
																	strcpy(projetista[k].nomeProjetoEscolhido, projeto[i].nomeProjeto);
																	projetista[k].areiaProjeto = projeto[i].areia * projetista[k].qtdCasas;
																	projetista[k].calProjeto = projeto[i].cal * projetista[k].qtdCasas;
																	projetista[k].acoProjeto = projeto[i].aco * projetista[k].qtdCasas;
																	projetista[k].tijoloProjeto = projeto[i].tijolo * projetista[k].qtdCasas;
																	projetista[k].madeiraProjeto = projeto[i].madeira * projetista[k].qtdCasas;
																	projetista[k].cimentoProjeto = projeto[i].cimento * projetista[k].qtdCasas;
																	projetista[k].argamassaProjeto = projeto[i].argamassa * projetista[k].qtdCasas;
																	projetista[k].telhaProjeto = projeto[i].telha * projetista[k].qtdCasas;
																	projetista[k].custo = projeto[i].custo * projetista[k].qtdCasas;
																}
														}
												    
												    system("cls || clear");
												    printf("-------------------------------------");
												    printf("\nNome do Projeto: %s\n", projetista[k].nomeProjetista);
													printf("\nLugar / Pessoa que recebera o projeto: %s\n", projetista[k].beneficiarioProjetista);
													printf("\nNome do criador do projeto: %s\n", projetista[k].responsavelProjetista);
													printf("\nTipo de Projeto: %s\n", projetista[k].nomeProjetoEscolhido);
													printf("\nQuantidade de casas que deseja construir: %d\n", projetista[k].qtdCasas);
													printf("\nMateriais necessarios\n");
													printf("\n-> %.2f kg de Areia", projetista[k].areiaProjeto);
													printf("\n-> %.2f kg de Cal", projetista[k].calProjeto);
													printf("\n-> %d unid. de Aco", projetista[k].acoProjeto);
													printf("\n-> %d unid. de Tijolo", projetista[k].tijoloProjeto);
												    printf("\n-> %d unid. de Madeira", projetista[k].madeiraProjeto);
												    printf("\n-> %.2f kg de Cimento", projetista[k].cimentoProjeto);
												    printf("\n-> %.2f kg de Argamassa", projetista[k].argamassaProjeto);
												    printf("\n-> %d unid. de Telha", projetista[k].telhaProjeto);
												    printf("\n\n-> Custo do total do projeto: R$%.2f", projetista[k].custo);
												    printf("\n-------------------------------------");
												    
												    TenteNovamente6:
												    printf ("\n\nDeseja alterar seu registro? \n[1]Alterar e voltar ao menu anterior. \n[2]Nao. Editar registro.\n");
												    scanf("%d", &editaProjetista);
												    
												    switch (editaProjetista)
												    	{
												    		case 1:
												    			system("cls || clear");
												    			printf("Registro alterado com sucesso!\n\n");
												    			goto menuEdicaoProjetista2; //Volta a linha 494 inicio do menu de edicao de projetos sem system clear
												    		
												    		case 2:
												    			goto EdicaoProjetistaInicio; //Volta a linha 537 inicio da edicao de um projeto
												    			
												    		case 0:
															default:
												    			printf("Opcao Invalida. Tente novamente.\n");
												    			goto TenteNovamente6; //Volta a linha 591 para que o usuario tente novamente caso escolha uma opcao fora das fornecidas
														} 
												}
										}
									break;
								
								case 2:
									printf("\n");
									goto inicioRemoverProjeto; //Vai para a linha 855 inicio da remoção de um item da lista de projetos;
								
								case 3:
									goto menuEdicaoProjetista; //Volta a linha 492 inicio do menu de edicao de projetos
									
								case 0:
								default:
									printf("Opcao Invalida. Tente novamente.\n");
        							goto TenteNovamente5; //Volta a linha 519 para que o usuario tente novamente caso escolha uma opcao fora das fornecidas
							}
					} while (menuEdicaoProjetista2);
					
					break;
				
				case 2:
					goto BuscaProjetistaInicio; //Volta a linha 526 inicio da edicao de um projeto
				
				case 3:
					if(kTotal == 0)
        				{
        					printf("**********************************************\n");
        					printf("*           Nenhum projeto cadastrado        *\n");
							goto menuEdicaoProjetista2; //Volta para a linha 516 inicio do menu de edicao dos projetos cadastrados sem system clear	
						}
							
					system("cls || clear");
					inicioRemoverProjeto:
					
					fflush(stdin);
					printf("Qual projeto deseja remover?\n");
					gets(nomeProjetoProjetista);
					fflush(stdin);
									
        			for (k=0 ; k<kTotal ; k++)
						{
							if (strcmp (nomeProjetoProjetista, projetista[k].nomeProjetista) == 0)
								{
									if (kTotal == 1)
										{
											strcpy(projetista[k].nomeProjetista, "");
											strcpy(projetista[k].beneficiarioProjetista, "");
											strcpy(projetista[k].responsavelProjetista, "");
											strcpy(projetista[k].nomeProjetoEscolhido, "");
											projetista[k].qtdCasas = 0;
											projetista[k].areiaProjeto = 0;
											projetista[k].calProjeto = 0;
											projetista[k].acoProjeto = 0;
											projetista[k].tijoloProjeto = 0;
											projetista[k].madeiraProjeto = 0;
											projetista[k].cimentoProjeto = 0;
											projetista[k].argamassaProjeto = 0;
											projetista[k].telhaProjeto = 0;
											projetista[k].custo = 0;
											
											kTotal = kTotal - 1;
											system("cls || clear");
							    			printf("Registro removido com sucesso!\n\n");
							    			goto menuEdicaoProjetista2; //Volta a linha 494 inicio do menu de edicao de projetos sem system clear
										}
											
									for (k=k ; k<kTotal ; k++)
										{
											strcpy(projetista[k].nomeProjetista, projetista[k+1].nomeProjetista);
											strcpy(projetista[k].beneficiarioProjetista, projetista[k+1].beneficiarioProjetista);
											strcpy(projetista[k].responsavelProjetista, projetista[k+1].responsavelProjetista);
											strcpy(projetista[k].nomeProjetoEscolhido, projetista[k+1].nomeProjetoEscolhido);
											projetista[k].qtdCasas = projetista[k+1].qtdCasas;
											projetista[k].areiaProjeto = projetista[k+1].areiaProjeto;
											projetista[k].calProjeto = projetista[k+1].calProjeto;
											projetista[k].acoProjeto = projetista[k+1].acoProjeto;
											projetista[k].tijoloProjeto = projetista[k+1].tijoloProjeto;
											projetista[k].madeiraProjeto = projetista[k+1].madeiraProjeto;
											projetista[k].cimentoProjeto = projetista[k+1].cimentoProjeto;
											projetista[k].argamassaProjeto = projetista[k+1].argamassaProjeto;
											projetista[k].telhaProjeto = projetista[k+1].telhaProjeto;
											projetista[k].custo = projetista[k+1].custo;
										}
										
									k = k - 1;
									kTotal = kTotal - 1;
								}
						}
					
					system("cls || clear");
	    			printf("Registro removido com sucesso!\n\n");
	    			goto menuEdicaoProjetista2; //Volta a linha 494 inicio do menu de edicao de projetos sem system clear
	    			
	    		case 4:
					return 0;
					
				case 0:
				default:
					printf("Opcao Invalida. Tente novamente.\n");
        			goto menuEdicaoProjetista2; //Volta a linha 494 inicio do menu de edicao de projetos sem system clear
			}
	} while (menuEdicaoProjetista);
}

//Funcao que contem a tela de menu de doacao
int menuDoacaoP()
{
	do 
		{
			system("cls || clear");
			menuDoacaoInicio:
			printf("**********************************************\n");
			printf("*                   Doacao                   *\n");
			printf("**********************************************\n");
			printf("*                Menu de Opcoes              *\n");
			printf("*                                            *\n");
			printf("*[1] Ver lista de projetos                   *\n");
			printf("*[2] Buscar por nome do projeto              *\n");
			printf("*[3] Suas doacoes                            *\n");
			printf("*[4] Voltar ao Menu Principal                *\n");
			printf("*                                            *\n");
			printf("**********************************************\n");
            scanf("%d", &menuDoacao);
			system("cls || clear");
			
					
			switch (menuDoacao)
            	{
            		case 1:
            			if(kTotal == 0)
        				{
        					printf("**********************************************\n");
        					printf("*           Nenhum projeto cadastrado        *\n");
        					goto menuDoacaoInicio; //Volta para a linha 679 inicio do menu de doacao sem system clear
        				}
            			printf("-------------------------------------\n");
            			for (k=0 ; k<kTotal ; k++)
							{
							    printf("Nome do Projeto: %s\n", projetista[k].nomeProjetista);
								printf("\nLugar / Pessoa que recebera o projeto: %s\n", projetista[k].beneficiarioProjetista);
								printf("\nNome do criador do projeto: %s\n", projetista[k].responsavelProjetista);
								printf("\nTipo de Projeto: %s\n", projetista[k].nomeProjetoEscolhido);
								printf("\nQuantidade de casas que deseja construir: %d\n", projetista[k].qtdCasas);
								printf("\nMateriais necessarios\n");
								printf("\n-> %.2f kg de Areia", projetista[k].areiaProjeto);
								printf("\n-> %.2f kg de Cal", projetista[k].calProjeto);
								printf("\n-> %d unid. de Aco", projetista[k].acoProjeto);
								printf("\n-> %d unid. de Tijolo", projetista[k].tijoloProjeto);
							    printf("\n-> %d unid. de Madeira", projetista[k].madeiraProjeto);
							    printf("\n-> %.2f kg de Cimento", projetista[k].cimentoProjeto);
							    printf("\n-> %.2f kg de Argamassa", projetista[k].argamassaProjeto);
							    printf("\n-> %d unid. de Telha", projetista[k].telhaProjeto);
								printf("\n\n-> Custo do total do projeto: R$%.2f / R$%.2f\n", projetista[k].valorDoado, projetista[k].custo);
								
								if (projetista[k].valorDoado >= projetista[k].custo)
									{
										printf("\nMeta atingida! Muito obrigado por sua ajuda!\n\n");
									}
								
								printf("-------------------------------------\n");
							}
									
						do
							{
								TenteNovamente7:
								printf("Digite a opcao: \n[1] Doar \n[2] Voltar ao menu anterior \n");
								scanf("%d", &menuDoacao2);
										
								switch (menuDoacao2)
									{
										case 1:
											BuscaDoacaoInicio:
											if(kTotal == 0)
						        				{
						        					printf("**********************************************\n");
						        					printf("*           Nenhum projeto cadastrado        *\n");
						        					goto menuDoacaoInicio; //Volta para a linha 679 inicio do menu de doacao sem system clear
						        				}
											fflush(stdin);
											printf("A qual projeto deseja doar?\n");
											gets(nomeProjetoDoacao);
											fflush(stdin);
													
											for (k=0 ; k<kTotal ; k++)
												{
													if (strcmp (nomeProjetoDoacao, projetista[k].nomeProjetista) == 0)
														{
															for (x=x ; x<xTotal+1 ; x++) //Lista Carrinho de doacoes
																{
																	DoacaoProjetistaInicio:
																	system("cls || clear");
																	
																	strcpy (doacao[x].nomeProjetoDoacao, nomeProjetoDoacao);
																	
																	printf("Nome do projeto escolhido: %s\n", doacao[x].nomeProjetoDoacao);
																	fflush(stdin);
																			
																	printf("-------------------------------------");
																	
																	ValorDoacaoInicio:
																	printf("\nDigite a opcao de doacao: \n[1] R$10.00 \n[2] R$50.00 \n[3] R$100.00 \n[4] Digite o valor\n");
																	scanf("%d", &valorDoado);
															
																	switch (valorDoado)
																		{
																			case 1:
																				valorDoado2 = 10.00;
																				break;
																			
																			case 2:
																				valorDoado2 = 50.00;
																				break;
																				
																			case 3:
																				valorDoado2 = 100.00;
																				break;
																				
																			case 4:
																				printf("Quanto deseja doar? R$ ");
																				scanf("%f", &valorDoado3);
																				
																				valorDoado2 = valorDoado3;
																				
																				break;
																				
																			case 0:
																			default:
																				printf("Opcao Invalida. Tente novamente");
																				goto ValorDoacaoInicio; //Volta a linha 714 para que o usuario tente novamente caso escolha uma opcao fora das fornecidas
																		}
																 
																	doacao[x].valorDoacao = doacao[x].valorDoacao + valorDoado2;
																	
																	system("cls || clear");
																	printf("Doacao adicionada ao carrinho com sucesso!\n\n");
														    	}
														    	
														    	xTotal = xTotal + 1;
														    	goto menuDoacaoInicio; //Volta a linha 645 inicio do menu de doacoes
														}
												}
										
										case 2:
											system("cls || clear");
											goto menuDoacaoInicio; //Volta a linha 645 inicio do menu de doacoes
											
										case 0:
										default:
											printf("Opcao Invalida. Tente novamente.\n");
											goto TenteNovamente7; //Volta a linha 680 para que o usuario tente novamente caso escolha uma opcao fora das fornecidas
									}
							} while (menuDoacao2);
            			break;
            						
            		case 2:
            			goto BuscaDoacaoInicio; //Volta a linha 687 inicio de doacao para um projeto
            		
            		case 3:
            			valorTotal = 0;
            			system("cls || clear");
            			printf("-------------------------------------\n");
            			printf("Carrinho de doacoes\n");
            			
            			if(xTotal == 0)
            				{
            					printf("-------------------------------------\n");
            					printf("Nenhum item no carrinho\n");
							}
            			
            			for (x=0 ; x<xTotal ; x++)
            				{
            					printf("-------------------------------------\n");
            					printf("Nome do projeto: %s\n", doacao[x].nomeProjetoDoacao);
            					printf("Valor doacao: R$%.2f\n", doacao[x].valorDoacao);
            					
            					valorTotal = valorTotal + doacao[x].valorDoacao;
							}
							
						printf("-------------------------------------\n");
						printf("Valor total: R$%.2f\n", valorTotal);
						printf("-------------------------------------\n");
						
						TenteNovamente8:
						printf ("\n\nDeseja concluir suas doacoes? \n[1]Doar e voltar ao menu anterior. \n[2]Retirar doacao do carrinho \n[3]Nao. Continuar doando.\n");
						scanf("%d", &finalizaCarrinho);
												    
						switch (finalizaCarrinho)
							{
								case 1:
									system("cls || clear");
									
									//Verificacao se ha itens dentro do carrinho
									if (xTotal == 0)
										{
											system("cls || clear");
				        					printf("**********************************************\n");
				        					printf("*          Nenhuma doacao no carrinho        *\n");
				        					goto menuDoacaoInicio; //Volta para a linha 679 inicio do menu de doacao sem system clear
				        				}
									
									for (k=0 ; k<kTotal ; k++)
										{
											for (x=0 ; x<xTotal ; x++)
												{
													if (strcmp (doacao[x].nomeProjetoDoacao, projetista[k].nomeProjetista) == 0)
														{
															//Adicionando os valores doados da lista do carrinho aos projetos cadastrados na lista de projetos
															projetista[k].valorDoado = projetista[k].valorDoado + doacao[x].valorDoacao;
														}
												}
										}
									
									//Zerando o carrinho	
									for (x=0 ; x<xTotal ; x++)
										{
											strcpy(doacao[x].nomeProjetoDoacao, "");
											doacao[x].valorDoacao = 0;
										}
									x=0;
									xTotal = 0;	
									valorTotal = 0;
									
									printf("Doacoes enviadas com sucesso! Muito Obrigado!\n\n");
									goto menuDoacaoInicio; //Volta a linha 645 inicio do menu de doacoes
									
								case 2:
									//Verificacao se ha itens dentro do carrinho
									if (xTotal == 0)
										{
											system("cls || clear");
				        					printf("**********************************************\n");
				        					printf("*          Nenhuma doacao no carrinho        *\n");
				        					printf("**********************************************\n");
				        					goto menuDoacaoInicio; //Volta para a linha 1048 inicio do carrinho de doacao sem system clear
				        				}
				        				
									printf("\nQual doacao deseja retirar?\n");
									fflush(stdin);
									gets(retirarDoacaoCart);
									fflush(stdin);
									printf("\nQual o valor da doacao a ser retirada?\n");
									scanf("%f", &retirarValorDoado);
									
									for (x=0 ; x<xTotal ; x++)
										{
											if (strcmp (retirarDoacaoCart, doacao[x].nomeProjetoDoacao) == 0 && retirarValorDoado == doacao[x].valorDoacao)
												{	
													valorTotal = valorTotal - retirarValorDoado;
														
													for (x=x ; x<xTotal ; x++)
														{
															strcpy(doacao[x].nomeProjetoDoacao, doacao[x+1].nomeProjetoDoacao);
															doacao[x].valorDoacao = doacao[x+1].valorDoacao;	
														}
														
													x = x - 1;
													xTotal = xTotal - 1;
												}
										}
										
									system("cls || clear");	
									printf("Doacao retirada com sucesso!\n\n");
									goto menuDoacaoInicio; //Volta a linha 645 inicio do menu de doacoes
												    		
								case 3:
									system("cls || clear");
									goto menuDoacaoInicio; //Volta a linha 645 inicio do menu de doacoes
												    			
								case 0:
								default:
									printf("Opcao Invalida. Tente novamente.\n");
									goto TenteNovamente8; //Volta a linha 791 para que o usuario tente novamente caso escolha uma opcao fora das fornecidas
							} 
							
            			break;
								
            		case 4:
            			return 0;
            		
            		case 0:
					default:
            			printf("Opcao Invalida. Tente novamente.\n");
            			goto menuDoacaoInicio; //Volta a linha 645 inicio do menu de doacoes
				}	
		} while (menuDoacao);	
}
