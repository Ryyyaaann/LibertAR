#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sys.h"



int main(){
    int op = -1;

    printf("Seja bem-vindo !\n");

    cadastrarUsuario();
    while (op != 0)
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
                formulario();
            break;

            case 0:
                limparTela();
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
