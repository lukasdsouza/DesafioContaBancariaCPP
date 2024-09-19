#include <iostream>
#include <string>
using namespace std;

const int MAX_USUARIOS = 10;

struct Usuario {
    string nome;
    string cpf;
    string endereco;
    string telefone;
    double saldo = 0.0;
};

bool validarCPF(const string &cpf) {
    return cpf.length() == 11;
}

void criarUsuario(Usuario usuarios[], int &numUsuarios) {
    if (numUsuarios >= MAX_USUARIOS) {
        cout << "Número máximo de usuários atingido!" << endl;
        return;
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, usuarios[numUsuarios].nome);

    do {
        cout << "CPF (11 dígitos): ";
        getline(cin, usuarios[numUsuarios].cpf);

        if (!validarCPF(usuarios[numUsuarios].cpf)) {
            cout << "CPF inválido! O CPF deve conter 11 dígitos." << endl;
        }
    } while (!validarCPF(usuarios[numUsuarios].cpf));

    cout << "Endereço: ";
    getline(cin, usuarios[numUsuarios].endereco);

    cout << "Telefone: ";
    getline(cin, usuarios[numUsuarios].telefone);

    usuarios[numUsuarios].saldo = 0.0;

    numUsuarios++;
    cout << "Usuário criado com sucesso!" << endl;
}

void removerUsuario(Usuario usuarios[], int &numUsuarios) {
    string cpf;
    cout << "Digite o CPF do usuário a ser removido: ";
    cin >> cpf;

    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].cpf == cpf) {
            for (int j = i; j < numUsuarios - 1; ++j) {
                usuarios[j] = usuarios[j + 1];
            }
            numUsuarios--;
            cout << "Usuário removido com sucesso!" << endl;
            return;
        }
    }

    cout << "Usuário não encontrado." << endl;
}

void alterarUsuario(Usuario usuarios[], int numUsuarios) {
    string cpf;
    cout << "Digite o CPF do usuário para alterar: ";
    cin >> cpf;

    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].cpf == cpf) {
            cout << "Digite o novo nome: ";
            cin.ignore();
            getline(cin, usuarios[i].nome);

            cout << "Digite o novo endereço: ";
            getline(cin, usuarios[i].endereco);

            cout << "Digite o novo telefone: ";
            getline(cin, usuarios[i].telefone);

            cout << "Usuário alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "Usuário não encontrado." << endl;
}

void saque(Usuario usuarios[], int numUsuarios) {
    string cpf;
    double valor;

    cout << "Digite o CPF do usuário para saque: ";
    cin >> cpf;

    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].cpf == cpf) {
            cout << "Digite o valor do saque: R$ ";
            cin >> valor;

            if (valor > usuarios[i].saldo) {
                cout << "Saldo insuficiente!" << endl;
            } else {
                usuarios[i].saldo -= valor;
                cout << "Saque realizado com sucesso! Novo saldo: R$ " << usuarios[i].saldo << endl;
            }
            return;
        }
    }

    cout << "Usuário não encontrado." << endl;
}

void deposito(Usuario usuarios[], int numUsuarios) {
    string cpf;
    double valor;

    cout << "Digite o CPF do usuário para depósito: ";
    cin >> cpf;

    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].cpf == cpf) {
            cout << "Digite o valor do depósito: R$ ";
            cin >> valor;

            usuarios[i].saldo += valor;
            cout << "Depósito realizado com sucesso! Novo saldo: R$ " << usuarios[i].saldo << endl;
            return;
        }
    }

    cout << "Usuário não encontrado." << endl;
}

void mostrarSaldo(Usuario usuarios[], int numUsuarios) {
    string cpf;

    cout << "Digite o CPF do usuário para consultar saldo: ";
    cin >> cpf;

    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].cpf == cpf) {
            cout << "Saldo atual de " << usuarios[i].nome << ": R$ " << usuarios[i].saldo << endl;
            return;
        }
    }

    cout << "Usuário não encontrado." << endl;
}

int main() {
    Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = 0;
    int opcao;

    do {
        cout << "\n--- Sistema Bancário ---\n";
        cout << "1. Criar usuário\n";
        cout << "2. Remover usuário\n";
        cout << "3. Alterar informações do usuário\n";
        cout << "4. Saque\n";
        cout << "5. Depósito\n";
        cout << "6. Mostrar saldo\n";
        cout << "7. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                criarUsuario(usuarios, numUsuarios);
                break;
            case 2:
                removerUsuario(usuarios, numUsuarios);
                break;
            case 3:
                alterarUsuario(usuarios, numUsuarios);
                break;
            case 4:
                saque(usuarios, numUsuarios);
                break;
            case 5:
                deposito(usuarios, numUsuarios);
                break;
            case 6:
                mostrarSaldo(usuarios, numUsuarios);
                break;
            case 7:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 7);

    return 0;
}
