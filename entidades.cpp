#include "entidades.hpp"

void CartaoCredito::setCartaoCredito(string numero, string validade) throw ( invalid_argument )
{
    this->numero.setNumCartaoCred( numero );
    this->validade.setDataValidade( validade );
}
