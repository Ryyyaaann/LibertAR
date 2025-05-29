#ifndef SYS_H
#define SYS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int formulario();
float economiaPorDinheiro();
float CigarrosNaoFumados();
int tempoVidaRecuperadoMinutos();
int menu();
void ColetarDados();
void exibirRelatorio();

typedef struct {
    char nome[50];
    int nivelDependencia;
    int cigarrosPorDia;
    float precoMaco;
    float macosPorDia; // Considere se isso pode ser calculado a partir de cigarrosPorDia e qtd cigarros/maço
    int diasSemFumar;
    time_t dataParada; // Armazena a data e hora em que a pessoa parou
} infoUsuario;

#endif