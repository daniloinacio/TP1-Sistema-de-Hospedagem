#include <iostream>

#include "testes_dominios.hpp"

using namespace std;

int main( )
{
    // Testes para a unidade Agencia
    TUAgencia agenciaTeste;

    cout << "Teste de unidade da classe Agencia:\n";

    switch( agenciaTeste.rodarTestes() )
    {
    case TUAgencia::SUCESSO:
        cout << "Testes rodaram sem falhas\n";
        break;
    case TUAgencia::FALHA:
        cout << "Houveram falhas nos testes\n";
        break;
    }

    cout << "\n";

    // Testes para a classe Banco
    TUBanco bancoTeste;

    cout << "Teste de unidade da classe Banco:\n";

    switch( bancoTeste.rodarTestes() )
    {
    case TUBanco::SUCESSO:
        cout << "Testes rodaram sem falhas\n";
        break;
    case TUBanco::FALHA:
        cout << "Houveram falhas nos testes\n";
        break;
    }

    cout << "\n";

    // Testes para a unidade CapAcomodacao
    TUCapAcomodacao capacidadeTeste;

    cout << "Teste de unidade da classe CapAcomodacao:\n";

    switch( capacidadeTeste.rodarTestes() )
    {
    case TUCapAcomodacao::SUCESSO:
        cout << "Testes rodaram sem falhas\n";
        break;
    case TUCapAcomodacao::FALHA:
        cout << "Houveram falhar nos testes\n";
        break;
    }

    Data dataTest;
    string data = "01/jun/2018";

    dataTest.setData(data);

    return 0;
}
