#include <iostream>
using namespace std;
#include <stdio.h>

FILE *abrirArquivo(char modo){
    FILE *arquivo;
    switch (modo){
        case 'w':
            arquivo = fopen("test.txt", "w");
            cout << "Arquivo criado\n";
            break;
        case 'r':
            arquivo = fopen("test.txt", "r");
            cout << "Arquivo aberto\n";
            break;
        case 'a':
            arquivo = fopen("test.txt", "a");
            break;
        default:
            throw string("Modo invalido, tente novamente\n");
            break;
    }

    if (arquivo == NULL){
        throw string("Arquivo nao encontrado");
    }
    return arquivo;
}

void fecharArquivo(FILE *arquivo){
    fclose (arquivo);
}

void editarArquivo( char entrada[30]){
    FILE *arquivo;
    arquivo = abrirArquivo('a');
    fprintf(arquivo, "%s\n", entrada);
}
 
int main(){
    //      Abertura de Arquivos     //
    FILE *arquivo;
    char modo;
    char entrada[30];
    try{
        cout << "Insira o modo de arquivo: ";
        cin >> modo;
        arquivo = abrirArquivo(modo);
        switch (modo){
            case 'w':
                cout << "Insira o texto: ";
                cin >> entrada;
                editarArquivo(entrada);
                break;
            case 'r':
                while (fscanf(arquivo, "%s", entrada) != EOF){
                    cout << entrada << endl;
                }
                break;
            case 'a':
                cout << "Insira o texto: ";
                cin >> entrada;
                editarArquivo(entrada);
                break;
        }
    }
    catch(string error){
        cout << "Erro " << error << endl;
    }

    return 0;
}