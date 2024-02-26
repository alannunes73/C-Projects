#include <stdio.h>
#include <string.h>

int converte_romano(char let){
    int resp;
    if (let == 'M')
        resp = 1000;
    else if (let == 'D')
        resp = 500;
    else if (let == 'C')
        resp = 100;
    else if (let == 'L')
        resp = 50;
    else if (let == 'X')
        resp = 10;
    else if (let == 'V')
        resp = 5;
    else if (let == 'I')
        resp = 1;
    else
        resp = 0;

    return resp;
}

int romano_Arabico(char num[], int len){
    int i, proximo;
    int resp[10], total = 0;

    for (i=0; i<len; i++){
        resp[i] = converte_romano(num[i]);
        resp[i+1] = converte_romano(num[i+1]);
        if (resp[i] == 1 && resp[i+1] >= 50){
            return 0;
        }
        if (resp[i] == 5 && resp[i+1] >= 5){
            return 0;
        }
        if (resp[i] == 10 && (resp[i+1] == 500 || resp[i+1] == 1000)){
            return 0;
        }
        if (resp[i] == 50 && (resp[i+1] >= 50)){
            return 0;
        }
        if (i+1 < len){
            proximo = converte_romano(num[i+1]);
        if (resp[i] >= proximo)
            total += resp[i];
        else{
            total += (proximo - resp[i]);
            i++;
        }

        } else{
        total += resp[i];
      }
    }
    return total;
}

char *arabico_Romano(int num){
    static char romano[20];

    if (num < 1 || num > 3999)
        return "Numero Invalido!";

    while (num >= 1000) {
        strcat(romano, "M");
        num -= 1000;
    }
    if (num >= 900) {
        strcat(romano, "CM");
        num -= 900;
    }
    while (num >= 500) {
        strcat(romano, "D");
        num -= 500;
    }
    if (num >= 400) {
        strcat(romano, "CD");
        num -= 400;
    }
    while (num >= 100) {
        strcat(romano, "C");
        num -= 100;
    }
    if (num >= 90) {
        strcat(romano, "XC");
        num -= 90;
    }
    while (num >= 50) {
        strcat(romano, "L");
        num -= 50;
    }
    if (num >= 40) {
        strcat(romano, "XL");
        num -= 40;
    }
    while (num >= 10) {
        strcat(romano, "X");
        num -= 10;
    }
    if (num >= 9) {
        strcat(romano, "IX");
        num -= 9;
    }
    while (num >= 5) {
        strcat(romano, "V");
        num -= 5;
    }
    if (num >= 4) {
        strcat(romano, "IV");
        num -= 4;
    }
    while (num >= 1) {
        strcat(romano, "I");
        num -= 1;
    }
    return romano;
}

int main(){
    char nromano[10];
    char *resultado;
    int resp, numero;
    int resp2;
    do{
        printf("1- Converter para algarismos romanos\n2- Converter para algarismos arabicos\n0- Sair\n");
        scanf("%d", &resp);
        while(resp != 1 && resp != 2 && resp != 0){
            printf("Escolha Invalida! Digite novamente: ");
            scanf("%d", &resp);
        }
        if (resp == 1){
            while(1){
                printf("Digite um numero: ");
                scanf("%d", &numero);
                if (numero < 1 || numero > 3999)
                    printf("Numero invalido!\n");
                else break;
            }
            resultado = arabico_Romano(numero);
            printf("%s\n", resultado);
            memset(resultado, 0, strlen(resultado));
        }
        if (resp == 2){
            scanf("%s", nromano);
            resp2 = romano_Arabico(nromano, strlen(nromano));
            if (resp2 == 0){
                printf("Numero Invalido!\n");
                strcpy(nromano, "");
            }else{
                printf("%d\n", resp2);
                strcpy(nromano, ""); }
        }
    }while(resp != 0);
    // if (resp == 1) -> executar função "arabico_Romano"
    // if (resp == 2) -> executar função "romano_Arabico"
    // if (resp == 0) -> sair do programa.

    return 0;
}
