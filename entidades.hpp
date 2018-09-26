#ifndef ENTIDADES_HPP
#define ENTIDADES_HPP

#include "dominios.hpp"

using namespace std;

/// Classe para que identifica um usu�rio do sistema
class Usuario
{
private:
    Nome nome; ///< String de at� 15 caracteres
    Identificador identificador; ///< Srting 5 caracteres somente de letras
    Senha senha; ///< String de at� 8 caracteres

public:
    /// Associa um nome ao usu�rio
    /**
        \param nome Objeto com o nome a ser estabelecido
    */
    void setNome ( Nome nome )
    {
        this->nome = nome;
    }

    /// Associa um identificador a um certo usu�rio
    /**
        \param identificador Objeto com o identificador que se quer associar
    */
    void setIdentificador ( Identificador identificador )
    {
        this->identificador = identificador;
    }

    /// Associa uma senha a um certo usu�rio
    /**
        \param Senha Objeto com a senha que se quer atribuir
    */
    void setSenha ( Senha senha )
    {
        this->senha = senha;
    }


    /// Retorna o nome do usu�rio
    /**
        \return Nome Objeto com o nome do usu�rio
    */
    Nome getNome()
    {
        return nome;
    }

    /// Retorna o identificador do usu�rio
    /**
        \return Identificador objeto que identifica o usu�rio
    */
    Identificador getIdentificador()
    {
        return identificador;
    }

    /// Retorna a senha do usu�rio
    /**
        \return Senha Objeto com a senha do usu�rio
    */
    Senha getSenha()
    {
        return senha;
    }
};

/// Classe da entidade de cart�o de cr�dito
class CartaoCredito
{
private:
    NumCartaoCred numero; ///< N�mero do cart�o
    DataValidade validade; ///< Data de validade do mesmo

public:
    /// Seta o n�mero do cart�o de cr�dito
    /**
        \param numero Objeto com o n�mero de cart�o de cr�dito que se quer associar
        \return void
    */
    void setNumero ( NumCartaoCred numero )
    {
        this->numero = numero;
    }

    /// Seta a data de validade do cart�o
    /**
        \param validade Objeto com a data de validade que se quer associar
        \return void
    */
    void setValidade ( DataValidade validade)
    {
        this->validade = validade;
    }

    /// Retorna um objeto com o n�mero do cart�o
    NumCartaoCred getNumero()
    {
        return numero;
    }

    /// Retorna um objetivo de validade com a validade com cart�o
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
