#include <iostream>
using namespace std;
#include <fstream>

int main()
{
    fstream arquivo;
    string nome, endereco;
    int idade, flag;
    double peso;
    do
    {
        arquivo.open("dados.txt", ios::in | ios::out | ios::app);
        if (arquivo.is_open())
        {
            cout << "Digite seu nome: ";
            getline(cin >> ws, nome);
            cout << "Digite seu endereco: ";
            getline(cin >> ws, endereco);
            cout << "Digite sua idade: ";
            cin >> idade;
            cout << "Digite seu peso: ";
            cin >> peso;
            arquivo << endl << nome << endl;
            arquivo << endereco << endl;
            arquivo << idade << endl;
            arquivo << peso;
            arquivo.seekg(0);
            while (arquivo.good()){
                getline(arquivo >> ws, nome);
                getline(arquivo >> ws, endereco);
                arquivo >> idade;
                arquivo >> peso;
                cout << "Nome: " << nome << endl;
                cout << "Endereco: " << endereco << endl;
                cout << "Idade: " << idade << endl;
                cout << "Peso: " << peso << "kg\n";
            }
            arquivo.close();
        }
        else
        {
            cout << "Arquivo nao encontrado." << endl;
        }
        cout << "insira 0 para encerrar: ";
        cin >> flag;
    } while (flag != 0);

    return 0;
}