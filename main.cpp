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
        arquivo = fopen ("test.txt", "w");
        fprintf (arquivo, "Ola");
        fclose (arquivo);
        cout << "Arquivo criado\n";
        arquivo = fopen ("test.txt", "r");
    }

    fscanf (arquivo, "%s", &texto);
    printf ("%s\n", texto);
    
    fclose (arquivo);

    return 0;
}