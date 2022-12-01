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
            cout << "Arquivo lido\n";
            break;
        case 'a':
            arquivo = fopen("test.txt", "a"); // edita o arquivo existente
            cout << "Arquivo aberto\n";
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
    fecharArquivo(arquivo);
}

void escreverArquivo(){ //escreve algo no arquivo
    FILE *arquivo;
    char texto[20];
    arquivo = abrirArquivo('r');
    while (fscanf(arquivo, "%s", texto) != EOF){
        cout << texto << endl;
    }
    fecharArquivo(arquivo);
}
 
int main(){
    //      Abertura de Arquivos     //
    FILE *arquivo;
    int modo;
    char entrada[20];
    int flag;
    do{
            try{
            cout << "1 - Criar arquivo" << endl;
            cout << "2 - Ler arquivo" << endl;
            cout << "3 - Editar arquivo" << endl;
            cout << "Insira o modo de arquivo: ";
            cin >> modo;
            switch (modo){
                case 1:
                    arquivo = abrirArquivo('w');
                    fecharArquivo(arquivo);
                    break;
                case 2:
                    escreverArquivo();
                    break;
                case 3:
                    cout << "Insira o texto: ";
                    cin >> entrada;
                    editarArquivo(entrada);
                    break;
            }
        }
        catch(string error){
            cout << "Erro " << error << endl;
        }
        cout << "insira 0 para encerrar\n";
        cin >> flag;
    }while (flag != 0);

    return 0;
}