// Aqui vai ficar a definicao do leiotr de linhas
// Copyright [2018] <Vinicius>
#ifndef _HOME_VINICIUS_DOCUMENTOS_MP_TRABALHO__3_TRABALHO3_INCLUDE_LEITOR_H_
#define _HOME_VINICIUS_DOCUMENTOS_MP_TRABALHO__3_TRABALHO3_INCLUDE_LEITOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "catch.hpp"

/**
 * @file doxygen_cpp.h
 * @author Vinicius
 * @date 10 OUT 2018
 * @brief Arquivo contendo a implementacao de funcoes basicas de um leitor de quantidade de linhas
 *
 */
FILE* abre_arquivo(const char *);
uint32_t conta_linha(FILE *);
uint8_t verifica_coment(char, char);
uint8_t verifica_coment_longo(FILE *, char, char); 

#endif  // _HOME_VINICIUS_DOCUMENTOS_MP_TRABALHO_1_INCLUDE_LEITOR_H_
