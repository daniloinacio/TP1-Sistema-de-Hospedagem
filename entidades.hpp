#ifndef ENTIDADES_HPP
#define ENTIDADES_HPP

#include "dominios.hpp"

/// Classe da entidade de cartão de crédito
class CartaoCredito
{
private:
    NumCartaoCred numero; ///< Número do cartão
    DataValidade validade; ///< Data de validade do mesmo

public:
    void setCartaoCredito( string, string ) throw ( invalid_argument );
};

#endif // ENTIDADES_HPP
