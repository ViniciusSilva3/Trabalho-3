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


/*
FILE *fp = fopen(arquivo, "r");
char  leitor;
for(int i = 0 ; i<10; i++){
	while( 1 ){
		leitor = fgetc(fp);
		printf("%c", leitor);
		if ( leitor == -1 || leitor == 'n' )
			break;
	}
	if ( leitor == -1 )
		break;
	i++;
}
fclose(fp);
return 0; }

*/

