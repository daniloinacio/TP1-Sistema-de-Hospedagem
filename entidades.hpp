#ifndef ENTIDADES_HPP
#define ENTIDADES_HPP

#include "dominios.hpp"

using namespace std;

/// Classe da entidade de cart�o de cr�dito
class CartaoCredito
{
private:
    NumCartaoCred numero; ///< N�mero do cart�o
    DataValidade validade; ///< Data de validade do mesmo
    Identificador idUsuario;

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

    void setIdUsuario ( Identificador idUsuario)
    {
        this->idUsuario = idUsuario;
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

    Identificador getIdUsuario()
    {
        return idUsuario;
    }
};

///Classe que representa a entidade conta corrente e seu atributos.
class ContaCorrente
{
private:
	NumContaCorr numero; ///< n�mero associado a conta.
	Agencia agencia; ///< n�mero da ag�ncia da qual a conta pertence.
	Banco banco; ///< n�mero do banco do qual a ag�ncia pertence.
	Identificador idUsuario;

public:

	/// M�todo que atribui um numero a conta corrente.
	/**
		\param Um n�mero de conta corrente.
		\return Void.
	*/
	void setNumero( NumContaCorr numero )
	{
		this->numero = numero;
	}
	/// M�todo que atribui uma ag�ncia a conta corrente.
	/**
		\param Um n�mero de ag�ncia.
		\return Void.
	*/
	void setAgencia( Agencia agencia )
	{
		this->agencia = agencia;
	}

	/// M�todo que atribui um banco a conta corrente.
	/**
		\param Um n�mero de banco.
		\return Void.
	*/
	void setBanco( Banco banco)
	{
		this->banco = banco;
	}

	void setIdUsuario ( Identificador idUsuario )
	{
	    this->idUsuario = idUsuario;
	}

	/// M�todo que obt�m o numero da conta corrente.
	/**
		\param Void.
		\return O n�mero da conta corrente.
	*/
	NumContaCorr getNumero()
	{
		return numero;
	}
	/// M�todo que obt�m a ag�ncia da conta corrente.
	/**
		\param Void.
		\return O n�mero da ag�ncia.
	*/
	Agencia getAgencia()
	{
		return agencia;
	}
	/// M�todo que obt�m o banco da conta corrente.
	/**
		\param Void.
		\return O n�mero do banco.
	*/
	Banco getBanco()
	{
		return banco;
	}

	Identificador getIdUsuario()
	{
	    return idUsuario;
	}
};

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

class Resultado {

protected:
    int valor;

public:

    const static int SUCESSO = 0;
    const static int FALHA   = 1;

    void setValor(int valor){
        this->valor = valor;
    }

    int getValor() const {
        return valor;
    }
};

class ResultadoUsuario:public Resultado {

private:
    Usuario usuario;

public:
    void setUsuario(const Usuario &usuario){
        this->usuario = usuario;
    }

    Usuario getUsuario() const {
        return usuario;
    }
};

/// Classe que representa a entidade Acomoda��o e seus atributos.
class Acomodacao
{
private:
	Identificador identificador; ///< Identifica��o da acomoda��o.
	Identificador idUsuario;
	TpAcomodacao tipo; ///< O tipo ao qual a acomoda��o pertence.
	CapAcomodacao capacidade; ///< Valor da capacidade da acomoda��o.
	Data dataInicio; ///< Data de inicio do per�odo de disponibilidade da acomoda��o.
	Data dataTermino; ///< Data de termino do per�odo de disponibilidade da acomoda��o.
	Nome cidade; ///< Nome da cidade em que a acomoda��o est� localizada.
	Estado estado; ///< Sigla do estado em que a acomoda��o est� localizada.
	Diaria diaria; ///< Valor da di�ria da acomoda��o.

public:

	/// M�todo que atribui um identificador a acomoda��o
	/**
		\param Um identificador.
		\return Void.
	*/
	void setIdentificador( const Identificador &identificador )
	{
		this->identificador = identificador;
	}

	void setIdUsuario( Identificador idUsuario )
	{
	    this->idUsuario = idUsuario;
	}

	/// M�todo que atribui um tipo a acomoda��o
	/**
		\param Um tipo de acomoda��o.
		\return Void.
	*/
	void setTipo( TpAcomodacao tipo )
	{
		this->tipo = tipo;
	}

	/// M�todo que atribui uma capacidade a acomoda��o
	/**
		\param Um valor de capacidade.
		\return Void.
	*/
	void setCapacidade( CapAcomodacao capacidade )
	{
		this->capacidade = capacidade;
	}

	/// M�todo que atribui uma data de inicio a acomoda��o
	/**
		\param Uma data.
		\return Void.
	*/
	void setDataInicio( Data dataInicio )
	{
		this->dataInicio = dataInicio;
	}

	/// M�todo que atribui uma data de termino a acomoda��o
	/**
		\param Uma data.
		\return Void.
	*/
	void setDataTermino( Data dataTermino )
	{
		this->dataTermino = dataTermino;
	}

	/// M�todo que atribui uma cidade a acomoda��o
	/**
		\param O nome de uma cidade.
		\return Void.
	*/
	void setCidade( Nome cidade )
	{
		this->cidade = cidade;
	}

	/// M�todo que atribui um Estado a acomoda��o
	/**
		\param A sigla de um estado brasileiro.
		\return Void.
	*/
	void setEstado( Estado estado )
	{
		this->estado = estado;
	}

	/// M�todo que atribui um valor de di�ria a acomoda��o
	/**
		\param Um valor de di�ria.
		\return Void.
	*/
	void setDiaria( Diaria diaria )
	{
		this->diaria = diaria;
	}

	/// M�todo que obt�m o identificador da acomoda��o
	/**
		\param Void.
		\return O identificador da acomoda��o.
	*/
	Identificador getIdentificador()
	{
		return identificador;
	}

	/// M�todo que obt�m o tipo da acomoda��o
	/**
		\param Void.
		\return O tipo da acomoda��o.
	*/
	TpAcomodacao getTipo()
	{
		return tipo;
	}

	/// M�todo que obt�m a capacidade da acomoda��o
	/**
		\param Void.
		\return A capacidade da acomoda��o.
	*/
	CapAcomodacao getCapacidade()
	{
		return capacidade;
	}

	/// M�todo que obt�m a data de inicio da disponibilidade da acomoda��o
	/**
		\param Void.
		\return A data de inicio da disponibilidade da acomoda��o.
	*/
	Data getDataInicio()
	{
		return dataInicio;
	}

	/// M�todo que obt�m a data de termino da disponibilidade da acomoda��o
	/**
		\param Void.
		\return A data de termino da disponibilidade da acomoda��o.
	*/
	Data getDataTermino()
	{
		return dataTermino;
	}

	/// M�todo que obt�m a cidade da acomoda��o
	/**
		\param Void.
		\return A cidade da acomoda��o.
	*/
	Nome getCidade()
	{
		return cidade;
	}

	/// M�todo que obt�m o estado da acomoda��o
	/**
		\param Void.
		\return O estado da acomoda��o.
	*/
	Estado getEstado()
	{
		return estado;
	}

	/// M�todo que obt�m a di�ria da acomoda��o.
	/**
		\param Void.
		\return A di�ria da acomoda��o.
	*/
	Diaria getDiaria()
	{
		return diaria;
	}

	Identificador getIdUsuario()
	{
	    return idUsuario;
	}
};

class ResultadoAcomodacao:public Resultado {

private:
    Acomodacao acomodacao;

public:
    void setAcomodacao(const Acomodacao &acomodacao){
        this->acomodacao = acomodacao;
    }

    Acomodacao getAcomodacao() const {
        return acomodacao;
    }
};
#endif // ENTIDADES_HPP
