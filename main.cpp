#include <iostream>
#include "dominios.hpp"

using namespace std;

int main( )
{
    Agencia agencia;
    Banco caixa;
    CapAcomodacao capacidade;
    string numero;
    int valor;


    cout << "Insira um número da agência:" << endl;
    cin >> numero;

    agencia.setAgencia( numero );

    cout << "Número da agência inserido:\n" << numero << endl;

    cout << "Insira um número de banco:" << endl;
    cin >> numero;

    caixa.setBanco( numero );

    cout << "Número de banco inserido:\n" << numero << endl;

    cout << "Insira a capacidade de acomodação:" << endl;
    cin >> valor;

    capacidade.setCapAcomodacao( valor );

    cout << "Valor da capacidade inserido:\n" << valor << endl;

    return 0;
}
