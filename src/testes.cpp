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
    SECTION( "TESTA A QUANTIDADE DE LINHAS " ){
        FILE *fp1;
        fp1 = abre_arquivo("arquivo_a_ler.c");
        uint32_t verificador = conta_linha(fp1);
        REQUIRE ( verificador == 3 );
        fclose(fp1);
    } // end section 2

    SECTION( "TESTA SE INICIA COM COMENTARIO simples " ){
        FILE *fp1;
        fp1 = abre_arquivo("arquivo_a_ler.c");
        char leitor, leitor2;
        leitor = fgetc(fp1);
        leitor2 = fgetc(fp1);
        uint8_t teste = verifica_coment(leitor, leitor2);
        REQUIRE ( teste == 1 );
    
        fclose(fp1);
    } // end section 3

    SECTION( "TESTA SE INICIA COM COMENTARIO LONGO " ){
        FILE *fp1;
        fp1 = abre_arquivo("arquivo_a_ler2.c");
        char leitor, leitor2;
        leitor = fgetc(fp1);
        leitor2 = fgetc(fp1);
        uint8_t teste = verifica_coment_longo(fp1, leitor, leitor2);
        REQUIRE ( teste == 1 );
        uint32_t verificador = conta_linha(fp1); // inicia apos a leitura do comentario longo
        REQUIRE( verificador == 5 );
        fclose(fp1);
    } // end section 3

} // end test case
