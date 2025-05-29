#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sys.h"


int main(){
    int op;
    infoUsuario user = {0};
    printf("Seja bem-vindo !\n");

    ColetarDados(&user);
    while (op != 0)
    {
        int op = menu();
        switch (op)
        {
            case 1:
                system("cls");
                system("clear");
                exibirRelatorio(&user);
            break;
            
            case 2:
                system("cls");
                system("clear");
                ColetarDados(&user);
            
            break;
            
            case 3:
                system("cls");
                system("clear");
                formulario(&user);
            break;

            case 0:
                system("cls");
                system("clear");
                break;
       
            default:
                printf("Digite uma opção existente");
                break;
       }
    }
    printf("Obrigado pela preferencia");
    return 0;
}
