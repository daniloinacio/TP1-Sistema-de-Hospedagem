#include <iostream>

#include "testes_dominios.hpp"

using namespace std;

int main( )
{
    // Testes para a unidade Agencia
    TUAgencia agencia_teste;

    cout << "Teste de unidade da classe Agencia:\n";

    switch( agencia_teste.RodarTestes() )
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
    TUBanco banco_teste;

    cout << "Teste de unidade da classe Banco:\n";

    switch( banco_teste.RodarTestes() )
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
    TUCapAcomodacao capacidade_teste;

    cout << "Teste de unidade da classe CapAcomodacao:\n";

    switch( capacidade_teste.RodarTestes() )
    {
    case TUCapAcomodacao::SUCESSO:
        cout << "Testes rodaram sem falhas\n";
        break;
    case TUCapAcomodacao::FALHA:
        cout << "Houveram falhar nos testes\n";
        break;
    }

    return 0;
}
