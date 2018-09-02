#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <stdexcept>

using namespace std;

class Agencia
{
private:
    string numero;
    void validar( string ) throw ( invalid_argument );

public:
    void setAgencia( string numero ) throw ( invalid_argument )
    {
        validar( numero );
        this->numero = numero;
    }
    string getAgencia( ) const
    {
        return numero;
    }

};


#endif // DOMINIOS_HPP_INCLUDED
