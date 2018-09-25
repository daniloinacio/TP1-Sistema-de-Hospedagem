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
        \param Nome String de at� 15 caracteres
    */
    void setNome ( string ) throw ( invalid_argument );

    /// Associa um identificador a um certo usu�rio
    /**
        \param Identificador String de 5 letras
    */
    void setIdentificador ( string ) throw ( invalid_argument );

    /// Associa uma senha a um certo usu�rio
    /**
        \param Senha string de 8 caracteres
    */
    void setSenha ( string ) throw ( invalid_argument );


    /// Retorna o nome do usu�rio
    /**
        \return Nome Nome do usu�rio
    */
    string getNome()
    {
        return nome.getNome();
    }

    /// Retorna o identificador do usu�rio
    /**
        \return Identificador Identificador do usu�rio
    */
    string getIdentificador()
    {
        return identificador.getIdentificador();
    }

    /// Retorna a senha do usu�rio
    /**
        \return Senha Senha do usu�rio
    */
    string getSenha()
    {
        return senha.getSenha();
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
        \param Numero N�mero do cart�o de cr�dito em formato de string
        \return void
    */
    void setNumero ( string ) throw ( invalid_argument );

    /// Seta a data de validade do cart�o
    /**
        \param Validade Data de validade em forma de string, por exemplo: "11/19"
        \return void
    */
    void setValidade ( string ) throw ( invalid_argument );

    /// Retorna o n�mero do cart�o em formato de string
    string getNumero()
    {
        return numero.getNumCartaoCred();
    }

    /// Retorna o n�mero do cart�o em formato de string
    string getValidade()
    {
        return validade.getDataValidade();
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
