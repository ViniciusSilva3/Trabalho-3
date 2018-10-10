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

    char  leitor, leitor2;
    uint32_t contador =0;
    uint8_t verificador=0;
    while(1){
        while(1){ // while para verificar se linha inicia com coment
            do{
                leitor = fgetc(arquivo);
            }while( leitor == 32 || leitor == '\n'); //** le espcos em branco */
            leitor2 = fgetc(arquivo);
            verificador = verifica_coment_longo(arquivo, leitor, leitor2);
            if ( verificador == 0 )
                break;
        } // end while 
        verificador = verifica_coment(leitor, leitor2); //** Le o primeiro caractere valido de uma linha
	    while( 1 ){
		    leitor = fgetc(arquivo);
            if ( leitor == '/'){ //** If para verificar se existe comentario no meio de uma linha
                leitor = fgetc(arquivo);
                if( leitor == '/' || leitor == '*'){
                    fseek(arquivo, -2, SEEK_CUR);
                    contador++;
                    break;
                }
            } // end do if verificando se existe um comentario no meio da linha
            //** se existir comentario no meio da linha, é quebrado o loop de contar linha */

		    if ( leitor == -1 || leitor == '\n' ) { //** verifica se chegou em uma troca de linha */
                if ( verificador == 0 )
                    contador++;
			    break;
            } // end if
	    }
        leitor = fgetc(arquivo); //** Verifica se depois de uma quebra de linha acabou o arquivo
	    if ( leitor == -1 ) //** Verifica se chegou no fim do arquivo */
		    break;
        fseek(arquivo, -1, SEEK_CUR); //** volta um caractere caso nao tenha lido eof */
    } // end while mais externo
    return contador;
} // end conta_linha

uint8_t verifica_coment(char valor_lido, char valor_lido2) {
 /**
 * @brief Verifica se o inicio da linha eh um comentario
 * @return Retorna 1 caso comece com '/' e '0' caso contratrio
 * @param Um char
 */
    if ( valor_lido == '/' && valor_lido2 == '/' )
        return 1;
    else
        return 0;
}// end verifica comment

uint8_t verifica_coment_longo(FILE *arquivo, char valor_lido, char valor_lido2){
 /**
 * @brief Verifica se o inicio da linha eh um comentario longo
 * @return Retorna 1 quando terminou de ler o comentario longo, 0 caso tenha sido acessada errado
 * @param Recebe o arquivo que esta sendo lido, e o valor dos dois primeiros caracteres validos de uma linha
 */
    char leitor;
    if ( valor_lido == '/' && valor_lido2 == '*' ) {
        while(1){
            leitor = fgetc(arquivo);
            if( leitor == '*'){
                leitor = fgetc(arquivo);
                if( leitor == '/' ) //** Terminou a leitura do comentario longo */
                    break;
                fseek(arquivo, -1, SEEK_CUR); //** Volta o leitor para opcao correta */
            }
        } //end while
        return 1;
    } //end if
    return 0;
} //end verifica_coment_longo
