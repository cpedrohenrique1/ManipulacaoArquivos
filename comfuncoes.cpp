#include <iostream>
using namespace std;
#include <stdio.h>

// Função abre o arquivo no modo digitado
FILE *abrirArquivo(char modo){
    FILE *arquivo;
    switch (modo){
        case 'w':
            arquivo = fopen("test.txt", "w"); // cria arquivo para escrita
            cout << "Arquivo criado\n";
            break;
        case 'r':
            arquivo = fopen("test.txt", "r"); // abre arquivo para leitura
            cout << "Arquivo aberto\n";
            break;
        case 'a':
            arquivo = fopen("test.txt", "a"); // edita o arquivo existente no final
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

void fecharArquivo(FILE *arquivo){ //fecha o arquivo digitado
    fclose (arquivo);
    cout << "Arquivo fechado\n";
}

void editarArquivo( char entrada[30]){ //edita o arquivo
    FILE *arquivo;
    arquivo = abrirArquivo('a');
    fprintf(arquivo, "%s\n", entrada);
}

void escreverArquivo(){ //escreve algo no arquivo
    FILE *arquivo;
    char texto[20];
    arquivo = abrirArquivo('r');
    while (fscanf(arquivo, "%s", texto) != EOF){
        cout << texto << endl;
    }
}
 
int main(){
    //      Abertura de Arquivos     //
    FILE *arquivo;
    char modo;
    char entrada[20];
    try{
        cout << "Insira o modo de arquivo: ";
        cin >> modo;
        arquivo = abrirArquivo(modo);
        fecharArquivo(arquivo);
        switch (modo){
            case 'w':
                cout << "Insira o texto: ";
                cin >> entrada;
                editarArquivo(entrada);
                break;
            case 'r':
                escreverArquivo();
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
    fecharArquivo(arquivo);

    return 0;
}