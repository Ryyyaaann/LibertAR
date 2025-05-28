#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>






typedef struct 
{
    char nome[50];
    int nivelDependencia;
    int cigarrosPorDia;
    float precoMaco;
    float macosPorDia;
    int diasSemFumar;
    time_t dataParada;
}infoUsuario;



int formulario()

{
    int Fsum = 0;
    char op4p, opTF[10];
   
    printf("1. Em quanto tempo depois de acordar você fuma o primeiro cigarro?\n");
    printf("(a) Dentro de 5 minutos\n");
    printf("(b) 6-30 minutos\n");
    printf("(C) 31-60 minutos\n");
    printf("(d) Depois de 60 minutos\n");
    scanf(" %c", &op4p);
    op4p = tolower(op4p);
    if (op4p == 'a')
    {
        Fsum += 3;
    }
    else if (op4p == 'b')
    {
        Fsum += 2;
    }
    else if (op4p == 'c')
    {
        Fsum += 1;
    }
    else if (op4p == 'd')
    {
        Fsum += 0;
    }

    printf("2. Você acha difícil ficar sem fumar em lugares onde é proibido (por exemplo, na igreja, no cinema, em bibliotecas, e outros.)?\n");
    printf("(a) Sim\n");
    printf("(b) Não\n");
    scanf("%9s", &opTF);
    for (int i = 0; opTF[i]; i++)
    {
        opTF[i] = tolower(opTF[i]);
    }

    if (strcmp(opTF, "sim") == 0 || strcmp(opTF, "a") == 0)
    {
        Fsum += 1;
    }
    else if (strcmp(opTF, "não") == 0 || strcmp(opTF, "b") == 0)
    {
        Fsum += 0;
    }

    printf("3. Qual o cigarro do dia que traz mais satisfação?\n");
    printf("(a) O primeiro da manhã\n");
    printf("(b) Outros\n");
    scanf("%9s", &opTF);
    for (int i = 0; opTF[i]; i++)
    {
        opTF[i] = tolower(opTF[i]);
    }

    if (strcmp(opTF, "sim") == 0 || strcmp(opTF, "a") == 0)
    {
        Fsum += 1;
    }
    else if (strcmp(opTF, "não") == 0 || strcmp(opTF, "b") == 0)
    {
        Fsum += 0;
    }

    printf("4. Quantos cigarros você fuma por dia?\n");
    printf("(a) Menos de 10\n");
    printf("(b) De 11 a 20\n");
    printf("(C) De 21 a 30\n");
    printf("(d) Mais de 31\n");
    scanf(" %c", &op4p);
    op4p = tolower(op4p);

    if (op4p == 'a'){Fsum += 0;}

    else if (op4p == 'b'){Fsum += 1;}

    else if (op4p == 'c'){Fsum += 2;}
    
    else if (op4p == 'd'){Fsum += 3;}

    printf("5. Você fuma mais frequentemente pela manhã?\n");
    printf("(a) Sim\n");
    printf("(b) Não\n");
    scanf("%9s", &opTF);
    for (int i = 0; opTF[i]; i++)
    {
        opTF[i] = tolower(opTF[i]);
    }

    if (strcmp(opTF, "sim") == 0 || strcmp(opTF, "a") == 0)
    {
        Fsum += 1;
    }
    else if (strcmp(opTF, "não") == 0 || strcmp(opTF, "b") == 0)
    {
        Fsum += 0;
    }

    printf("6. Você fuma mesmo doente quando precisa ficar na cama a maior parte do tempo?\n");
    printf("(a) Sim\n");
    printf("(b) Não\n");
    scanf("%9s", &opTF);
    for (int i = 0; opTF[i]; i++)
    {
        opTF[i] = tolower(opTF[i]);
    }

    if (strcmp(opTF, "sim") == 0 || strcmp(opTF, "a") == 0)
    {
        Fsum += 1;
    }
    else if (strcmp(opTF, "não") == 0 || strcmp(opTF, "b") == 0)
    {
        Fsum += 0;
    }

    printf("\n=== RESULTADO DO TESTE ===\n");
    printf("Pontuação total: %d\n", Fsum);
    printf("Nível de dependência: ");
    
    if (Fsum <= 2) {
        printf("MUITO BAIXA\n");
        printf("Parabéns! Você tem poucas chances de ter síndrome de abstinência.\n");
    } else if (Fsum <= 4) {
        printf("BAIXA\n");
        printf("Você pode ter sintomas leves de abstinência.\n");
    } else if (Fsum == 5) {
        printf("MÉDIA\n");
        printf("Você pode ter sintomas moderados de abstinência.\n");
    } else if (Fsum <= 7) {
        printf("ELEVADA\n");
        printf("Você provavelmente terá sintomas de abstinência. Considere buscar ajuda médica.\n");
    } else {
        printf("MUITO ELEVADA\n");
        printf("Você certamente terá síndrome de abstinência. É recomendado acompanhamento médico.\n");
    }

    // Resultado:
    // Avaliação do resultado

    // Dependência (soma dos pontos):

    // 0-2: muito baixa
    // 3-4: baixa
    // 5: média
    // 6-7: elevada
    // 8-10: muito elevada

    system("pause");
    return Fsum;
}

float economiaPorDinheiro(float PrecoMaco, float MacoDia, int DiasSemFumar){
    return PrecoMaco * MacoDia * DiasSemFumar;

}

float CigarrosNaoFumados(int CigarrosDia, int DiasSemFumar){
    return CigarrosDia * DiasSemFumar;

}

int tempoVidaRecuperadoMinutos(int cigarrosPorDia, int diasSemFumar) {
    return cigarrosPorDia * diasSemFumar * 11;
}

void ColetarDados(infoUsuario *user){
    printf("(cadastro inicial)");
    printf("Nome:");
    scanf("%s",&user->nome);

    printf("cigarros por dia:");
    scanf("%i",&user->cigarrosPorDia);

    printf("preço do maço:");
    scanf("%f",&user->precoMaco);

    printf("maco por dia:");
    scanf("%f",&user->macosPorDia);

    printf("dias sem fumar:");
    scanf("%i",&user->diasSemFumar);

    printf("nivel de dependencia logo após o teste:");
    system("pause");
    user->nivelDependencia = formulario();    

    printf("Dados atualizados");
    system("pause");
}

void exibirRelatorio(infoUsuario *user){
    printf("O seu relatorio completo\n");
    printf("Nome %s\n", user->nome);
    printf("Nome %s\n", user->nome);

}

int menu(){
    int op;
    printf("======================================");
    printf("= 1 - Relatorio do usuario           =");
    printf("= 2 - Alterar dados                  =");
    printf("= 3 - Teste de dependencia           =");
    printf("= 0 - sair                           =");
    printf("=");
    printf("=");
    printf("=");
    printf("=");
    scanf(" %i",&op);
    return op;
}