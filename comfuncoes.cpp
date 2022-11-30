#include <iostream>
using namespace std;
#include <stdio.h>

void abrirArquivo(FILE *arquivo, char modo){
    switch (modo){
        case 'g':
            arquivo = fopen("test.txt", "w");
            break;
        case 'l':
            arquivo = fopen("test.txt", "r");
            break;
    }

    if (arquivo == NULL){
        throw string("Arquivo não encontrado");
    }
}

void fecharArquivo(FILE *arquivo){
    fclose (arquivo);
}
 
int main(){
    //      Abertura de Arquivos     //
    FILE *arquivo;
    

    return 0;
}
