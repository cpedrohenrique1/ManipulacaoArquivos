#include <iostream>
using namespace std;
#include <stdio.h>
 
int main(){
    //      Abertura de Arquivos     //
    char texto[3];
    FILE *arquivo;
    arquivo = fopen ("test.txt", "r"); // Abre um arquivo texto existente para leitura
    
    if (arquivo == nullptr) {
        cout << "Arquivo não encontrado" << endl;
        arquivo = fopen ("test.txt", "w"); // Cria um arquivo
        fprintf (arquivo, "Ola"); // escreve dentro do arquivo
        fclose (arquivo); // fecha o arquivo
        cout << "Arquivo criado\n";
        arquivo = fopen ("test.txt", "r"); // abre o arquivo
    }

    fscanf (arquivo, "%s", &texto); // le o arquivo
    printf ("%s\n", texto); // escreve o que tem no arquivo
    
    fclose (arquivo); // fecha o arquivo

    return 0;
}
