#include <iostream>

#include "testes_dominios.hpp"
#include "testes_entidades.hpp"

using namespace std;

int main( )
{
    // Testes de unidade da classe Agencia
    TUAgencia agenciaTeste;

    cout << "Testes classe Agencia:\n";

    switch( agenciaTeste.rodarTestes() )
    {
    case TUAgencia::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUAgencia::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da classe Banco
    TUBanco bancoTeste;

    cout << "Testes classe Banco:\n";

    switch( bancoTeste.rodarTestes() )
    {
    case TUBanco::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUBanco::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da classe CapAcomodacao
    TUCapAcomodacao capacidadeTeste;

    cout << "Testes classe CapAcomodacao:\n";

    switch( capacidadeTeste.rodarTestes() )
    {
    case TUCapAcomodacao::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUCapAcomodacao::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da classe Data
    TUData dataTeste;

    cout << "Testes classe Data:\n";

    switch( dataTeste.rodarTestes() )
    {
    case TUData::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUData::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da classe DataValidade
    TUDataValidade dataValidadeTeste;

    cout << "Testes classe DataValidade:\n";

    switch( dataValidadeTeste.rodarTestes() )
    {
    case TUDataValidade::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUDataValidade::FALHA:
        cout << "Falha\n";
        break;
    }


    cout << "\n";

    // Testes de unidade da classe NumCartaoCred
    TUNumCartaoCred numCartaoCredTeste;

    cout << "Testes classe NumCartaoCred:\n";

    switch( numCartaoCredTeste.rodarTestes() )
    {
    case TUNumCartaoCred::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUNumCartaoCred::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da classe Senha
    TUSenha SenhaTeste;

    cout << "Testes classe Senha:\n";

    switch( SenhaTeste.RodarTestes() )
    {
    case TUSenha::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUSenha::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da clase Estado
    TUEstado EstadoTeste;

    cout << "Testes classe Estado:\n";

    switch( EstadoTeste.RodarTestes() )
    {
    case TUEstado::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUEstado::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da clase Identificador
    TUIdentificador IdTeste;

    cout << "Testes classe Identificador:\n";

    switch( IdTeste.RodarTestes() )
    {
    case TUIdentificador::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUIdentificador::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

    // Testes de unidade da clase TpAcomodacao
    TUTpAcomodacao TpAcTeste;

    cout << "Testes classe TpAcomodacao:\n";

    switch( TpAcTeste.RodarTestes() )
    {
    case TUTpAcomodacao::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUTpAcomodacao::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

        // Testes de unidade da classe Diaria
    TUDiaria diaria;

    cout << "Teste de unidade da classe Diaria:\n";

    switch( diaria.rodarTestes() )
    {
    case TUDiaria::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUDiaria::FALHA:
        cout << "Falha\n";
        break;
    }


    cout << "\n";
    // Testes de unidade da classe NumContaCorr
    TUNumContaCorr numContaCorr;

    cout << "Teste de unidade da classe NumContaCorr:\n";

    switch( numContaCorr.rodarTestes() )
    {
    case TUNumContaCorr::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUNumContaCorr::FALHA:
        cout << "Falha\n";
        break;
    }


    cout << "\n";

    // Testes de unidade da classe Nome
    TUNome nome;

    cout << "Teste de unidade da classe Nome:\n";

    switch( nome.rodarTestes() )
    {
    case TUNome::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUNome::FALHA:
        cout << "Falha\n";
        break;
    }


    cout << "\n";
    cout << "-----------------------------------------------\n";
    cout << "Testes para as classes de entidades:\n\n";

    // Testes de unidade da classe CartaoCredito
    TUCartaoCred CarCredTeste;
    cout << "Testes classe CartaoCredito:\n";

    switch( CarCredTeste.RodarTestes() )
    {
    case TUCartaoCred::SUCESSO:
        cout << "Sucesso\n";
        break;
    case TUCartaoCred::FALHA:
        cout << "Falha\n";
        break;
    }

    // Testes de unidade da classe Usuario
    TUUsuario UsuarioTeste;
    cout << "Testes classe Usuario:\n";

    switch( UsuarioTeste.RodarTestes() )
    {
    case TUUsuario::SUCESSO:
        cout << "Sucesso\n";
        break;

    case TUUsuario::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";
    // Testes de unidade da classe Acomodacao
    TUAcomodacao acomodacaoTeste;
    cout << "Testes classe Acomodacao:\n";

    switch( acomodacaoTeste.RodarTestes() )
    {
    case TUAcomodacao::SUCESSO:
        cout << "Sucesso\n";
        break;

    case TUAcomodacao::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";
    // Testes de unidade da classe ContaCorrente
    TUContaCorrente contaCorrenteTeste;
    cout << "Testes classe ContaCorrente:\n";

    switch( contaCorrenteTeste.RodarTestes() )
    {
    case TUContaCorrente::SUCESSO:
        cout << "Sucesso\n";
        break;

    case TUContaCorrente::FALHA:
        cout << "Falha\n";
        break;
    }

    cout << "\n";

    return 0;
}
