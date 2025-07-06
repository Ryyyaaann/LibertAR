#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "sys.h"

infoUsuario usuarios[MAX_USUARIOS];
int usuarios_cadastrados = 0;
int indice_usuario_logado = -1;
int master_logado = 0;
const char *MASTER_USER = "master";
const char *MASTER_PASS = "admin123";

int formulario()

{
    int Fsum = 0;
    char op4p, opTF[10];
    limparTela();

    printf("1. Em quanto tempo depois de acordar voce fuma o primeiro cigarro?\n");
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

    printf("2. Voce acha difícil ficar sem fumar em lugares onde é proibido (por exemplo, na igreja, no cinema, em bibliotecas, e outros.)?\n");
    printf("(a) Sim\n");
    printf("(b) Nao\n");
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
    else if (strcmp(opTF, "nao") == 0 || strcmp(opTF, "b") == 0)
    {
        Fsum += 0;
    }

    printf("3. Qual o cigarro do dia que traz mais satisfacao?\n");
    printf("(a) O primeiro da manha\n");
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
    else if (strcmp(opTF, "nao") == 0 || strcmp(opTF, "b") == 0)
    {
        Fsum += 0;
    }

    printf("4. Quantos cigarros voce fuma por dia?\n");
    printf("(a) Menos de 10\n");
    printf("(b) De 11 a 20\n");
    printf("(C) De 21 a 30\n");
    printf("(d) Mais de 31\n");
    scanf(" %c", &op4p);
    op4p = tolower(op4p);

    if (op4p == 'a')
    {
        Fsum += 0;
    }

    else if (op4p == 'b')
    {
        Fsum += 1;
    }

    else if (op4p == 'c')
    {
        Fsum += 2;
    }

    else if (op4p == 'd')
    {
        Fsum += 3;
    }

    printf("5. Voce fuma mais frequentemente pela manha?\n");
    printf("(a) Sim\n");
    printf("(b) Nao\n");
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

    printf("6. Voce fuma mesmo doente quando precisa ficar na cama a maior parte do tempo?\n");
    printf("(a) Sim\n");
    printf("(b) Nao\n");
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

    limparTela();
    printf("\n=== RESULTADO DO TESTE ===\n");
    printf("Pontuacao total: %d\n", Fsum);
    printf("Nível de dependencia: ");

    if (Fsum <= 2)
    {
        printf("MUITO BAIXA\n");
        printf("Parabéns! Voce tem poucas chances de ter síndrome de abstinencia.\n");
    }
    else if (Fsum <= 4)
    {
        printf("BAIXA\n");
        printf("Voce pode ter sintomas leves de abstinencia.\n");
    }
    else if (Fsum == 5)
    {
        printf("MÉDIA\n");
        printf("Voce pode ter sintomas moderados de abstinencia.\n");
    }
    else if (Fsum <= 7)
    {
        printf("ELEVADA\n");
        printf("Voce provavelmente terá sintomas de abstinencia. Considere buscar ajuda médica.\n");
    }
    else
    {
        printf("MUITO ELEVADA\n");
        printf("Voce certamente terá síndrome de abstinencia. É recomendado acompanhamento médico.\n");
    }

    // Resultado:
    // Avaliacão do resultado

    // Dependência (soma dos pontos):

    // 0-2: muito baixa
    // 3-4: baixa
    // 5: média
    // 6-7: elevada
    // 8-10: muito elevada

    system("pause");
    return Fsum;
}

float economiaPorDinheiro(float PrecoMaco, float MacoDia, int DiasSemFumar)
{
    return PrecoMaco * MacoDia * DiasSemFumar;
}

float CigarrosNaoFumados(int CigarrosDia, int DiasSemFumar)
{
    return CigarrosDia * DiasSemFumar;
}

int tempoVidaRecuperadoMinutos(int cigarrosPorDia, int diasSemFumar)
{
    return (cigarrosPorDia * diasSemFumar) * 11;
}
void login()
{

    int temp_indice_usario = -1;
    char login[50];
    char senha[30];
    printf("Login: ");
    getchar();
    scanf("%s", login);

    printf("Senha:");
    getchar();
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = 0;

    if (strcmp(login, MASTER_USER) == 0 && strcmp(senha, MASTER_PASS) == 0)
    {
        printf("logado como Master");
        master_logado = 1;
        indice_usuario_logado = -1;
        system("pause");
        return;
    }

    master_logado = 0;
    if (usuarios_cadastrados == 0)
    {
        printf("Nenhum usuario cadastrado.\n");
        system("pause");
        return;
    }

    for (int i = 0; i < usuarios_cadastrados; i++)
    {
        if (strcmp(login, usuarios[i].usuario) == 0)
        {
            temp_indice_usario = i;
            break;
        }
    }
    if (temp_indice_usario != -1)
    {
        printf("Senha:");
        getchar();
        fgets(senha, sizeof(senha), stdin);
        senha[strcspn(senha, "\n")] = 0;

        if (strcmp(senha, usuarios[temp_indice_usario].senha) == 0)
        {
            printf("Login bem sucedido");
            indice_usuario_logado = temp_indice_usario;
        }
        else
        {
            printf("senha incorreta");
            indice_usuario_logado = -1;
        }
    }
    else
    {
        printf("usuario nao encontrado");
        indice_usuario_logado = -1;
    }
    system("pause");
}

void cadastrarUsuario()
{
    if (usuarios_cadastrados >= MAX_USUARIOS)
    {
        printf("Limite de usuarios atingido!\n");
        system("pause");
        return;
    }

    infoUsuario *user = &usuarios[usuarios_cadastrados];

    printf("(cadastro inicial)\n");
    printf("Nome:");
    scanf(" %[^\n]", user->nome);

    printf("Usuario:");
    scanf("%s", user->usuario);

    printf("Senha:");
    scanf("%s", user->senha);

    printf("Cigarros por dia:");
    scanf(" %d", &user->cigarrosPorDia);

    printf("Preco do maco:");
    scanf(" %f", &user->precoMaco);

    printf("Dias sem fumar:");
    scanf(" %d", &user->diasSemFumar);

    user->macosPorDia = (float)user->cigarrosPorDia / 20;

    printf("Nivel de dependencia logo após o teste:");
    system("pause");
    user->nivelDependencia = formulario();

    usuarios_cadastrados++;

    limparTela();
    printf("Dados atualizados");
    system("pause");
}
void EditarUsuario()
{

    infoUsuario *user = &usuarios[indice_usuario_logado];

    printf("(Edicão das informacões)\n");
    printf("Nome:");
    scanf(" %[^\n]", user->nome);

    printf("Usuario:");
    scanf("%s", user->usuario);

    printf("Senha:");
    scanf("%s", user->senha);

    printf("Cigarros por dia:");
    scanf(" %d", &user->cigarrosPorDia);

    printf("Preco do maco:");
    scanf(" %f", &user->precoMaco);

    printf("Dias sem fumar:");
    scanf(" %d", &user->diasSemFumar);

    user->macosPorDia = (float)user->cigarrosPorDia / 20;

    limparTela();
    printf("Dados atualizados");
    system("pause");
}

void exibirRelatorio()
{
    if (indice_usuario_logado == -1)
    {
        printf("Precisa logar");
    }
    else
    {

        printf("O seu relatorio completo\n");
        printf("Nome: %s\n", usuarios[indice_usuario_logado].nome);
        printf("Cigarros por dia (antes de parar): %d\n", usuarios[indice_usuario_logado].cigarrosPorDia);
        printf("Macos por dia: %.2f\n", usuarios[indice_usuario_logado].macosPorDia);
        printf("Dias sem fumar: %d\n", usuarios[indice_usuario_logado].diasSemFumar);

        float economia = economiaPorDinheiro(usuarios[indice_usuario_logado].precoMaco, usuarios[indice_usuario_logado].macosPorDia, usuarios[indice_usuario_logado].diasSemFumar);

        float naoFumados = CigarrosNaoFumados(usuarios[indice_usuario_logado].cigarrosPorDia, usuarios[indice_usuario_logado].diasSemFumar);

        float tempoVida = tempoVidaRecuperadoMinutos(usuarios[indice_usuario_logado].cigarrosPorDia, usuarios[indice_usuario_logado].diasSemFumar);

        printf("Ja foi economizado %.2f reais\n", economia);

        printf("Ja foram %.2f   cigarros nao fumados\n", naoFumados);

        printf("O tempo de vida recuperado foi de %.0f minutos\n", tempoVida);
    }
    system("pause");
}

void consultarUsuario()
{
    if (master_logado == 0)
    {
        printf("apenas adiministradores\n");
        system("pause");
        return;
    }
    int temp_indice_usario = -1;

    char nome[50];
    printf("buscar por nome do usuario: ");
    scanf(" %s", nome);
    for (int i = 0; i < usuarios_cadastrados; i++)
    {
        if (strcmp(nome, usuarios[i].nome) == 0)
        {
            temp_indice_usario = i;
            printf("O seu relatorio completo\n");
            printf("Nome: %s\n", usuarios[temp_indice_usario].nome);
            printf("Cigarros por dia (antes de parar): %d\n", usuarios[temp_indice_usario].cigarrosPorDia);
            printf("Macos por dia: %.2f\n", usuarios[temp_indice_usario].macosPorDia);
            printf("Dias sem fumar: %d\n", usuarios[temp_indice_usario].diasSemFumar);

            float economia = economiaPorDinheiro(usuarios[temp_indice_usario].precoMaco, usuarios[temp_indice_usario].macosPorDia, usuarios[temp_indice_usario].diasSemFumar);

            float naoFumados = CigarrosNaoFumados(usuarios[temp_indice_usario].cigarrosPorDia, usuarios[temp_indice_usario].diasSemFumar);

            float tempoVida = tempoVidaRecuperadoMinutos(usuarios[temp_indice_usario].cigarrosPorDia, usuarios[temp_indice_usario].diasSemFumar);

            printf("Ja foi economizado %.2f reais\n", economia);

            printf("Ja foram %.2f   cigarros nao fumados\n", naoFumados);

            printf("O tempo de vida recuperado foi de %.0f minutos\n", tempoVida);
            break;
        }
    }

    system("pause");
}

void filtro()
{
    if (master_logado == 0)
    {
        printf("apenas adiministradores\n");
        system("pause");
        return;
    }

    int temp_indice_usario = -1;

    int nivel_dependencia;
    printf("nivel de dependencia: ");
    scanf(" %d", &nivel_dependencia);
    for (int i = 0; i < usuarios_cadastrados; i++)
    {
        if (nivel_dependencia == usuarios[i].nivelDependencia)
        {
            temp_indice_usario = i;
            printf("O seu relatorio completo\n");
            printf("Nome: %s\n", usuarios[temp_indice_usario].nome);
            printf("Cigarros por dia (antes de parar): %d\n", usuarios[temp_indice_usario].cigarrosPorDia);
            printf("Macos por dia: %.2f\n", usuarios[temp_indice_usario].macosPorDia);
            printf("Dias sem fumar: %d\n", usuarios[temp_indice_usario].diasSemFumar);

            float economia = economiaPorDinheiro(usuarios[temp_indice_usario].precoMaco, usuarios[temp_indice_usario].macosPorDia, usuarios[temp_indice_usario].diasSemFumar);

            float naoFumados = CigarrosNaoFumados(usuarios[temp_indice_usario].cigarrosPorDia, usuarios[temp_indice_usario].diasSemFumar);

            float tempoVida = tempoVidaRecuperadoMinutos(usuarios[temp_indice_usario].cigarrosPorDia, usuarios[temp_indice_usario].diasSemFumar);

            printf("Ja foi economizado %.2f reais\n", economia);

            printf("Ja foram %.2f   cigarros nao fumados\n", naoFumados);

            printf("O tempo de vida recuperado foi de %.0f minutos\n", tempoVida);
            printf("\n\n");
        }
    }

    system("pause");
}

int menu()
{
    limparTela();
    int op;
    printf("======================================\n");
    printf("=      BEM-VINDO AO 'libertAR'       =\n");
    printf("======================================\n");

    if (master_logado)
    {
        printf("= Logado como: MASTER                =\n");
        printf("======================================\n");
        printf("= 3 - Cadastrar Novo Usuario         =\n");
        printf("= 6 - Consultar usuarios             =\n");
        printf("= 7 - Filtrar por Dependencia        =\n");
        printf("= 0 - Logout                         =\n");
    }
    else if (indice_usuario_logado != -1)
    {

        printf("= Logado como: %-20.20s =\n", usuarios[indice_usuario_logado].usuario);
        printf("======================================\n");
        printf("= 2 - Ver meu Relatorio de Progresso =\n");
        printf("= 4 - Editar minhas informacoes      =\n");
        printf("= 5 - Fazer Teste de Dependencia     =\n");
        printf("= 0 - Logout                         =\n");
    }
    else
    {

        printf("= 1 - Login                          =\n");
        printf("= 3 - Cadastrar Novo Usuario         =\n");
        printf("= 0 - Sair do Programa               =\n");
    }

    printf("======================================\n");
    printf("Escolha uma opcao: ");
    scanf(" %i", &op);

    return op;
}

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}