#include "entidades.hpp"

// Classe de Cartão de crédito
void CartaoCredito::setNumero(string numero) throw ( invalid_argument )
{
    this->numero.setNumCartaoCred( numero );
}

void CartaoCredito::setValidade( string validade ) throw ( invalid_argument )
{
    this->validade.setDataValidade( validade );
}

// Classe de Usuário
void Usuario::setNome ( string nome ) throw ( invalid_argument )
{
    this->nome.setNome(nome);
}

void Usuario::setIdentificador( string identificador ) throw ( invalid_argument )
{
    this->identificador.setIdentificador(identificador);
}

void Usuario::setSenha( string senha ) throw ( invalid_argument )
{
    this->senha.setSenha(senha);
}
