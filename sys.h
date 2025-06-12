#ifndef SYS_H
#define SYS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_USUARIOS 50

typedef struct
{
    char nome[50];
    char usuario[50];
    char senha[30];
    int cpf;
    int nivelDependencia;
    int cigarrosPorDia;
    float precoMaco;
    float macosPorDia;
    int diasSemFumar;
    time_t dataParada;
} infoUsuario;

int formulario();

float economiaPorDinheiro(float PrecoMaco, float MacoDia, int DiasSemFumar);
float CigarrosNaoFumados(int CigarrosDia, int DiasSemFumar);
int tempoVidaRecuperadoMinutos(int cigarrosPorDia, int diasSemFumar);
int menu();
void cadastrarUsuario();
void exibirRelatorio();
void limparTela();
void login();

extern int indice_usuario_logado;
extern int usuarios_cadastrados;
extern infoUsuario usuarios[MAX_USUARIOS];

#endif 