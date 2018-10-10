#include "leitor.h"
// Copyright [2018] <Vinicius>

FILE* abre_arquivo(const char *arquivo){
    /**
 * @brief Tenta abrir um arquivo.cpp para leitura
 * @return Retorna NULL se a insercao for falha, e o ponteiro para o arquivo caso seja um sucesso
 * @param Uma string contendo o nome do arquivo a ser aberto
 */
    FILE *fp = fopen(arquivo, "r");
    if( fp == NULL ){
        printf("Erro ao abrir arquivo\n");
        return fp;
    } // end if
    else
        return fp;
} // end abre arquivo


uint32_t conta_linha(FILE *arquivo){
    /**
 * @brief Conta a quantidade de linhas que sao executadas de um programa
 * @return Retorna a quantidade de linhas lidas
 * @param Um ponteiro apontando para o arquivo aberto
 */

    char  leitor;
    uint32_t contador =0;
    //for(int i = 0 ; i<10; i++){
    while(1){
	    while( 1 ){
		    leitor = fgetc(arquivo);
		    printf("%c", leitor);
		    if ( leitor == -1 || leitor == 'n' ){ //** verifica se chegou em uma troca de linha */
                contador++;
			    break;
            } // end if
	    }
	    if ( leitor == -1 ) //** Verifica se chegou no fim do arquivo */
		    break;
    } // end while mais externo
    return contador;
} // end conta_linha


