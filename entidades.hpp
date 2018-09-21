#ifndef ENTIDADES_HPP
#define ENTIDADES_HPP

#include "dominios.hpp"

/// Classe da entidade de cart�o de cr�dito
class CartaoCredito
{
private:
    NumCartaoCred numero; ///< N�mero do cart�o
    DataValidade validade; ///< Data de validade do mesmo

public:
    void setCartaoCredito( string, string ) throw ( invalid_argument );
};

#endif // ENTIDADES_HPP
