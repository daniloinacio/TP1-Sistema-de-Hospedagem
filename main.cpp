#include <iostream>
#include "dominios.hpp"

using namespace std;

int main( )
{
    Agencia itau;
    string numero;

    cout << "Insira um número da agência:" << endl;
    cin >> numero;

    itau.setAgencia( numero );

    cout << "Número da agência inserido:\n" << numero << endl;



    return 0;
}
