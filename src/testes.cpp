// Copyright [2018] <Vinicius>
#define CATCH_CONFIG_MAIN
#include "leitor.h"

TEST_CASE( "Trabalho 3" ){
    SECTION( "Testa a abertura de arquivos" ){
      FILE *fp1;
        fp1 = abre_arquivo("arquivo_a_ler1.c"); //** Arquivo nao existe */
        REQUIRE( fp1 == NULL );
        fp1 = abre_arquivo("arquivo_a_ler.c"); //** Arquivo Existe */
        REQUIRE( fp1 != NULL );

      fclose(fp1);
    }//End section 1
} // end test case
