#include <iostream>
//#include "dominios.hpp"

#include "testes_dominios.hpp"

using namespace std;

int main( )
{
    TUAgencia agencia_teste;

    switch( agencia_teste.run() )
    {
    case TUAgencia::SUCESSO:
        cout << "Deu certo, uhuul!!";
        break;
    case TUAgencia::FALHA:
        cout << "Opa, acho que algo deu errado";
        break;
    }

    return 0;
}
