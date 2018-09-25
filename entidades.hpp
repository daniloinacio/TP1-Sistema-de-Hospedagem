#ifndef ENTIDADES_HPP
#define ENTIDADES_HPP

#include "dominios.hpp"

/// Classe para que identifica um usuário do sistema
class Usuario
{
private:
    Nome nome; ///< String de até 15 caracteres
    Identificador identificador; ///< Srting 5 caracteres somente de letras
    Senha senha; ///< String de até 8 caracteres

public:
    /// Associa um nome ao usuário
    /**
        \param Nome String de até 15 caracteres
    */
    void setNome ( string ) throw ( invalid_argument );

    /// Associa um identificador a um certo usuário
    /**
        \param Identificador String de 5 letras
    */
    void setIdentificador ( string ) throw ( invalid_argument );

    /// Associa uma senha a um certo usuário
    /**
        \param Senha string de 8 caracteres
    */
    void setSenha ( string ) throw ( invalid_argument );


    /// Retorna o nome do usuário
    /**
        \return Nome Nome do usuário
    */
    string getNome()
    {
        return nome.getNome();
    }

    /// Retorna o identificador do usuário
    /**
        \return Identificador Identificador do usuário
    */
    string getIdentificador()
    {
        return identificador.getIdentificador();
    }

    /// Retorna a senha do usuário
    /**
        \return Senha Senha do usuário
    */
    string getSenha()
    {
        return senha.getSenha();
    }
};

/// Classe da entidade de cartão de crédito
class CartaoCredito
{
private:
    NumCartaoCred numero; ///< Número do cartão
    DataValidade validade; ///< Data de validade do mesmo

public:
    /// Seta o número do cartão de crédito
    /**
        \param Numero Número do cartão de crédito em formato de string
        \return void
    */
    void setNumero ( string ) throw ( invalid_argument );

    /// Seta a data de validade do cartão
    /**
        \param Validade Data de validade em forma de string, por exemplo: "11/19"
        \return void
    */
    void setValidade ( string ) throw ( invalid_argument );

    /// Retorna o número do cartão em formato de string
    string getNumero()
    {
        return numero.getNumCartaoCred();
    }

    /// Retorna o número do cartão em formato de string
    string getValidade()
    {
        return validade.getDataValidade();
    }
};

#endif // ENTIDADES_HPP
