#include <iostream>

#include "testes_dominios.hpp"

using namespace std;

int main( )
{
    // Testes de unidade da classe Agencia
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

    // Testes de unidade da classe Banco
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

    // Testes de unidade da classe CapAcomodacao
    TUCapAcomodacao capacidadeTeste;

    cout << "Teste de unidade da classe CapAcomodacao:\n";

    switch( capacidadeTeste.rodarTestes() )
    {
    case TUCapAcomodacao::SUCESSO:
        cout << "Testes rodaram sem falhas\n";
        break;
    case TUCapAcomodacao::FALHA:
        cout << "Houveram falhas nos testes\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da classe Data
    TUData dataTeste;

    cout << "Teste de unidade da classe Data:\n";

    switch( dataTeste.rodarTestes() )
    {
    case TUData::SUCESSO:
        cout << "Testes rodaram sem falhas\n";
        break;
    case TUData::FALHA:
        cout << "Houveram falhas nos testes\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da classe DataValidade
    TUDataValidade dataValidadeTeste;

    cout << "Teste de unidade da classe DataValidade:\n";

    switch( dataValidadeTeste.rodarTestes() )
    {
    case TUDataValidade::SUCESSO:
        cout << "Testes rodaram sem falhas\n";
        break;
    case TUDataValidade::FALHA:
        cout << "Houveram falhas nos testes\n";
        break;
    }


    cout << "\n";

    // Testes de unidade da classe NumCartaoCred
    TUNumCartaoCred numCartaoCredTeste;

    cout << "Teste de unidade da classe NumCartaoCred:\n";

    switch( numCartaoCredTeste.rodarTestes() )
    {
    case TUNumCartaoCred::SUCESSO:
        cout << "Testes rodaram sem falhas\n";
        break;
    case TUNumCartaoCred::FALHA:
        cout << "Houveram falhas nos testes\n";
        break;
    }

    return 0;
}
