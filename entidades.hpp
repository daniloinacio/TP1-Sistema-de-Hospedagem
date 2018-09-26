#ifndef ENTIDADES_HPP
#define ENTIDADES_HPP

#include "dominios.hpp"

using namespace std;

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
        \param nome Objeto com o nome a ser estabelecido
    */
    void setNome ( Nome nome )
    {
        this->nome = nome;
    }

    /// Associa um identificador a um certo usuário
    /**
        \param identificador Objeto com o identificador que se quer associar
    */
    void setIdentificador ( Identificador identificador )
    {
        this->identificador = identificador;
    }

    /// Associa uma senha a um certo usuário
    /**
        \param Senha Objeto com a senha que se quer atribuir
    */
    void setSenha ( Senha senha )
    {
        this->senha = senha;
    }


    /// Retorna o nome do usuário
    /**
        \return Nome Objeto com o nome do usuário
    */
    Nome getNome()
    {
        return nome;
    }

    /// Retorna o identificador do usuário
    /**
        \return Identificador objeto que identifica o usuário
    */
    Identificador getIdentificador()
    {
        return identificador;
    }

    /// Retorna a senha do usuário
    /**
        \return Senha Objeto com a senha do usuário
    */
    Senha getSenha()
    {
        return senha;
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
        \param numero Objeto com o número de cartão de crédito que se quer associar
        \return void
    */
    void setNumero ( NumCartaoCred numero )
    {
        this->numero = numero;
    }

    /// Seta a data de validade do cartão
    /**
        \param validade Objeto com a data de validade que se quer associar
        \return void
    */
    void setValidade ( DataValidade validade)
    {
        this->validade = validade;
    }

    /// Retorna um objeto com o número do cartão
    NumCartaoCred getNumero()
    {
        return numero;
    }

    /// Retorna um objetivo de validade com a validade com cartão
    DataValidade getValidade()
    {
        return validade;
    }
};

class Acomodacao
{
private:
	Identificador identificador;
	TpAcomodacao tipo;
	CapAcomodacao capacidade;
	Data dataInicio;
	Data dataTermino;
	Nome cidade;
	Estado estado;
	Diaria diaria;
public:
	void setIdentificador( const Identificador &identificador )
	{
		this->identificador = identificador;
	}
	void setTipo( TpAcomodacao tipo )
	{
		this->tipo = tipo;
	}
	void setCapacidade( CapAcomodacao capacidade )
	{
		this->capacidade = capacidade;
	}
	void setDataInicio( Data dataInicio )
	{
		this->dataInicio = dataInicio;
	}
	void setDataTermino( Data dataTermino )
	{
		this->dataTermino = dataTermino;
	}
	void setCidade( Nome cidade )
	{
		this->cidade = cidade;
	}
	void setEstado( Estado estado )
	{
		this->estado = estado;
	}
	void setDiaria( Diaria diaria )
	{
		this->diaria = diaria;
	}
	Identificador getIdentificador()
	{
		return identificador;
	}
	TpAcomodacao getTipo()
	{
		return tipo;
	}
	CapAcomodacao getCapacidade()
	{
		return capacidade;
	}
	Data getDataInicio()
	{
		return dataInicio;
	}
	Data getDataTermino()
	{
		return dataTermino;
	}
	Nome getCidade()
	{
		return cidade;
	}
	Estado getEstado()
	{
		return estado;
	}
	Diaria getDiaria()
	{
		return diaria;
	}
};

class ContaCorrente
{
private:
	NumContaCorr numero;
	Agencia agencia;
	Banco banco;
public:
	void setNumero( NumContaCorr numero )
	{
		this->numero = numero;
	}
	void setAgencia( Agencia agencia )
	{
		this->agencia = agencia;
	}
	void setBanco( Banco banco)
	{
		this->banco = banco;
	}

	NumContaCorr getNumero()
	{
		return numero;
	}
	Agencia getAgencia()
	{
		return agencia;
	}
	Banco getBanco()
	{
		return banco;
	}
};

#endif // ENTIDADES_HPP
