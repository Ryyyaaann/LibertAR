// ProjetoODS_GrupoLibertAR_RyanDosSantosFrança_LeandroOliveiraCunha_GabrielVictorMunizCampos_EmanuelSantosSales

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sys.h"

int main()
{
    int op = -1;

    printf("Seja bem-vindo !\n");

    while (1)
    {
        op = menu();
        switch (op)
        {
        case 1:
            limparTela();
            login();
            break;

        case 2:
            limparTela();
            exibirRelatorio();
            break;

        case 3:
            limparTela();
            cadastrarUsuario();

            break;

        case 4:
            limparTela();
            EditarUsuario();
            break;
        case 5:
            limparTela();
            formulario();
            break;
        case 6:
            limparTela();
            consultarUsuario();
            break;
        case 7:
            limparTela();
            filtro();
            break;

        case 0:
            limparTela();
            if (indice_usuario_logado != -1 || master_logado == 1)
            {
                indice_usuario_logado = -1;
                master_logado = 0;
                printf("Logout realizado com sucesso.\n");
                system("pause");
            }

            else
            {
                printf("Obrigado pela preferencia!\n");
                return 0;
            }
            break;

        default:
            printf("Digite uma opção existente");
            system("pause");
            break;
        }
    }
    printf("Obrigado pela preferencia");
    return 0;
}
