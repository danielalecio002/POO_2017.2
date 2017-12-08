#include <iostream>
#include <vector>

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}
struct Operacao{
    string descricao;
    float valor;
    float saldo;

    Operacao(string descricao = "", float valor = 0){
        this->descricao = descricao;
        this->valor = valor;

    }
};
class Conta{
private:
    int id;
    float saldo {0};
    vector <Operacao> extrato;
public:
    Conta(int id = 0){
        this->id = id;
    }
    float getSaldo(){
        return this->saldo;
    }
    int getId(){
        return this->id;
    }
    void setId(int id){
        this->id = id;
    }
    bool saque(float valor){
        if((valor > saldo) || (valor < 0))
            return false;
        this->saldo -= valor;
        this->extrato.push_back(Operacao("saque -", valor));
        return true;
    }
    bool deposito(float valor){
        if(valor < 1)
            return false;
        this->saldo += valor;
        this->extrato.push_back(Operacao("deposito +", valor));
        return true;

    }
    vector <Operacao> getExtrato(){

        return this->extrato;
    }


};
void start(Conta& conta){
    conta = Conta(8776);
    conta.deposito(1000);
    conta.saque(50);

}
int menu(Conta& conta ){
    string op = "";
    start(conta);
    cout << "- iniciar $num"
         << "\n- saldo"
         << "\n- deposito $valor"
         << "\n- saque $valor"
         << "\n- extrato" << endl;

    while(op != "sair"){
        cin >> op;


        if(op == "iniciar")
            conta = Conta(read<int>());
        if(op == "saldo")
            cout << conta.getSaldo() << endl;
        if(op == "deposito")
            cout << (conta.deposito(read<float>())? "ok\n" : "erro\n");
        if(op == "saque")
            cout <<(conta.saque(read<float>())? "ok\n" : "erro\n");
        if(op == "extrato"){
            for(auto operacao : conta.getExtrato()){
                cout<< operacao.descricao << operacao.valor <<endl;

            }
         cout << "Saldo Atual: "<< conta.getSaldo()<< endl;
        }
        }
}


int main(){
    Conta conta;
    menu(conta);
}
