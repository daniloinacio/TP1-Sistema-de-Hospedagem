#include "controladoras.hpp"
#include "dominios.hpp"
#include "containers.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

bool CntrMASistema::menuPrincipal(Identificador *idUsuario)
{
    int opcao = -1;

    while( opcao != SAIR )
    {
        cout << endl << "----------------------------------------------------" << endl;
        cout <<         "                Menu principal                      " << endl;
        cout <<         "----------------------------------------------------" << endl;
        cout <<         "Cadastrar usuario - " << CADASTRAR_USUARIO << endl;
        cout <<         "Fazer login       - " << FAZER_LOGIN << endl;
        cout <<         "Sair              - " << SAIR << endl;

        do
        {
            cout << "Escolha uma das opcoes: ";
            cin >> opcao;
        } while( opcao < CADASTRAR_USUARIO || opcao > SAIR );

        switch( opcao )
        {
        case CADASTRAR_USUARIO:
            resultado = cntrMAUsuario->cadastrarUsuario( idUsuario );
            break;

        case FAZER_LOGIN:
            resultado = cntrMAAutenticacao->autenticar( idUsuario );
            if ( resultado == true )
            {
                resultado = menuLogin( idUsuario );
            }
            break;

        case SAIR:
            resultado = false;
            break;
        }
    } // while( opcao != SAIR)

    return resultado;
}

bool CntrMASistema::menuLogin(Identificador *idUsuario)
{
    int opcao = -1;
    resultado = true;

    while( opcao != SAIR )
    {
        cout << endl << "----------------------------------------------------" << endl;
        cout <<         "                   Menu de login                    " << endl;
        cout <<         "----------------------------------------------------" << endl;
        cout <<         "Opcoes de acomodacao - " << MENU_ACOMODACAO << endl;
        cout <<         "Opcoes de usuario    - " << MENU_USUARIO << endl;
        cout <<         "Sair                 - " << SAIR << endl;

        do
        {
            cout << "Escolha uma opcao: ";
            cin >> opcao;
        } while( opcao < MENU_ACOMODACAO || opcao > SAIR );

        switch( opcao )
        {
        case MENU_ACOMODACAO:
            cntrMAAcomodacao->iniciarMenuAcomodacao( *idUsuario );
            break;

        case MENU_USUARIO:
            resultado = cntrMAUsuario->iniciarMenuUsuario( idUsuario );
            break;

        case SAIR:
            resultado = false;
            break;
        }
    } // while( opcao != SAIR)

    return resultado;
}

bool CntrMAAutenticacao::autenticar( Identificador *identificador )
{
    cout << endl << "----------------------------------------------------" << endl;
	cout <<         "Insira o Identificador:" << endl;
	cin >> identificadorStr;
	cout <<         "Insira a senha:" << endl;
	cin >> senhaStr;

	try
	{
        identificadorTemp.setIdentificador( identificadorStr );
        senha.setSenha( senhaStr );
	}
	catch( invalid_argument excecao )
	{
		cout << "Identificador ou senha em formato errado." << endl;
		return false;
	}

	resultadoOperacao = cntrMSAutenticacao->autenticar( identificadorTemp, senha );

	if ( resultadoOperacao == true )
	{
		cout << "Atenticacao bem sucedida." << endl;
		identificador->setIdentificador(identificadorTemp.getIdentificador());
	}
	else
	{
		cout << "Falha na autenticacao. Identificador ou senha incorretos." << endl;
	}
	return resultadoOperacao;
<<<<<<< HEAD
}

bool CntrMAUsuario::cadastrarUsuario( Identificador *identificador )
{
    cout << "Insira o nome do usuario:" << endl;
    cin >> nomeStr;
    cout << "Insira o identificador do usuario:" << endl;
    cin >> identificadorStr;
    cout << "Insira a senha do usuario:" << endl;
    cin >> senhaStr;

    try
    {
        idTemp.setIdentificador( identificadorStr );
        nomeTemp.setNome( nomeStr );
        senhaTemp.setSenha( senhaStr );
    }
    catch( invalid_argument excecao )
    {
        cout << "Identificador, nome ou senha em formato errado." << endl;
        return false;
    }

    resultadoOperacao = cntrMSUsuario->validarUsuario(idTemp, senhaTemp);
    if( resultadoOperacao == false )
    {
        cout << "Erro, usuario ja existe." << endl;
    }
    else
    {
        identificador->setIdentificador( idTemp.getIdentificador() );
        novoUsuario.setIdentificador( idTemp );
        novoUsuario.setSenha( senhaTemp );
        novoUsuario.setNome( nomeTemp );
        resultadoOperacao = cntrMSUsuario->incluirUsuario(novoUsuario);
        cout << "Operacao bem sucedida." << endl;
    }
    return resultadoOperacao;
}

bool CntrMAUsuario::descadastrarUsuario( Identificador *idUsuario )
{
    resultadoOperacao = cntrMSUsuario->removerUsuario( *idUsuario );
    if( resultadoOperacao == false )
    {
        cout << "Nao foi possivel realizar o descadastro." << endl;
        return false;
    }
    else
    {
        cout << "Descadastramento realizado com sucesso." << endl;
        return true;
    }
}

bool CntrMAUsuario::cadastrarConta( Identificador *idUsuario)
{
    cout << "Insira a agencia:" << endl;
    cin >> agenciaStr;
    cout << "Insira o banco:" << endl;
    cin >> bancoStr;
    cout << "Insira o numero da conta:" << endl;
    cin >> numContaStr;

    try
    {
        agenciaTemp.setAgencia(agenciaStr);
        bancoTemp.setBanco(bancoStr);
        contaTemp.setNumContaCorr(numContaStr);
    }
    catch( invalid_argument excecao )
    {
        cout << "Agencia, banco ou numero da conta em formato invalido" << endl;
        return false;
    }

    novaConta.setAgencia(agenciaTemp);
    novaConta.setBanco(bancoTemp);
    novaConta.setNumero(contaTemp);
    novaConta.setIdUsuario(*idUsuario);

    resultadoOperacao = cntrMSUsuario->incluirConta( novaConta );

    if( resultadoOperacao == true )
    {
        cout << "Cadastro de conta realizado com sucesso" << endl;
        return true;
    }
    else
    {
        cout << "Nao foi possivel realizar o cadastro da conta" << endl;
        return false;
    }
}

bool CntrMAUsuario::cadastrarCartao( Identificador *idUsuario )
{
    cout << "Insira o numero do cartao:" << endl;
    cin >> numCartStr;
    cout << "Insira a data de validade:" << endl;
    cin >> valiCartStr;

    try
    {
        valiTemp.setDataValidade(valiCartStr);
        numCartTemp.setNumCartaoCred(numCartStr);
    }
    catch( invalid_argument excecao )
    {
        cout << "Numero ou validade do cartao em formato invalido." << endl;
        return false;
    }

    novoCartao.setIdUsuario( *idUsuario );
    novoCartao.setNumero( numCartTemp );
    novoCartao.setValidade( valiTemp );

    resultadoOperacao = cntrMSUsuario->incluirCartao( novoCartao );

    if( resultadoOperacao == true )
    {
        cout << "Cadastro realizado com sucesso." << endl;
        return true;
    }
    else
    {
        cout << "Nao foi possivel terminar o cadastro." << endl;
        return false;
    }
}
=======
}

bool CntrMAUsuario::cadastrarUsuario( Identificador *identificador )
{
    cout << endl << "----------------------------------------------------" << endl;
    cout << "Insira o nome do usuario:" << endl;
    cin >> nomeStr;
    cout << "Insira o identificador do usuario:" << endl;
    cin >> identificadorStr;
    cout << "Insira a senha do usuario:" << endl;
    cin >> senhaStr;

    try
    {
        idTemp.setIdentificador( identificadorStr );
        nomeTemp.setNome( nomeStr );
        senhaTemp.setSenha( senhaStr );
    }
    catch( invalid_argument excecao )
    {
        cout << "Identificador, nome ou senha em formato errado." << endl;
        return false;
    }

    resultadoOperacao = cntrMSUsuario->validarUsuario(idTemp, senhaTemp);
    if( resultadoOperacao == false )
    {
        cout << "Erro, usuario ja existe." << endl;
    }
    else
    {
        identificador->setIdentificador( idTemp.getIdentificador() );
        novoUsuario.setIdentificador( idTemp );
        novoUsuario.setSenha( senhaTemp );
        novoUsuario.setNome( nomeTemp );
        resultadoOperacao = cntrMSUsuario->incluirUsuario(novoUsuario);
        cout << "Operacao bem sucedida." << endl;
    }
    return resultadoOperacao;
}

bool CntrMAUsuario::descadastrarUsuario( Identificador *idUsuario )
{
    resultadoOperacao = cntrMSUsuario->removerUsuario( *idUsuario );
    if( resultadoOperacao == false )
    {
        cout << endl << "Nao foi possivel realizar o descadastro." << endl;
        return false;
    }
    else
    {
        cout << endl << "Descadastramento realizado com sucesso." << endl;
        return true;
    }
}

bool CntrMAUsuario::cadastrarConta( Identificador *idUsuario)
{
    cout << endl << "----------------------------------------------------" << endl;
    cout << "Insira a agencia:" << endl;
    cin >> agenciaStr;
    cout << "Insira o banco:" << endl;
    cin >> bancoStr;
    cout << "Insira o numero da conta:" << endl;
    cin >> numContaStr;

    try
    {
        agenciaTemp.setAgencia(agenciaStr);
        bancoTemp.setBanco(bancoStr);
        contaTemp.setNumContaCorr(numContaStr);
    }
    catch( invalid_argument excecao )
    {
        cout << "Agencia, banco ou numero da conta em formato invalido" << endl;
        return false;
    }

    novaConta.setAgencia(agenciaTemp);
    novaConta.setBanco(bancoTemp);
    novaConta.setNumero(contaTemp);
    novaConta.setIdUsuario(*idUsuario);

    resultadoOperacao = cntrMSUsuario->incluirConta( novaConta );

    if( resultadoOperacao == true )
    {
        cout << "Cadastro de conta realizado com sucesso" << endl;
        return true;
    }
    else
    {
        cout << "Nao foi possivel realizar o cadastro da conta" << endl;
        return false;
    }
}

bool CntrMAUsuario::cadastrarCartao( Identificador *idUsuario )
{
    cout << endl << "----------------------------------------------------" << endl;
    cout << "Insira o numero do cartao:" << endl;
    cin >> numCartStr;
    cout << "Insira a data de validade:" << endl;
    cin >> valiCartStr;

    try
    {
        valiTemp.setDataValidade(valiCartStr);
        numCartTemp.setNumCartaoCred(numCartStr);
    }
    catch( invalid_argument excecao )
    {
        cout << "Numero ou validade do cartao em formato invalido." << endl;
        return false;
    }

    novoCartao.setIdUsuario( *idUsuario );
    novoCartao.setNumero( numCartTemp );
    novoCartao.setValidade( valiTemp );

    resultadoOperacao = cntrMSUsuario->incluirCartao( novoCartao );

    if( resultadoOperacao == true )
    {
        cout << "Cadastro realizado com sucesso." << endl;
        return true;
    }
    else
    {
        cout << "Nao foi possivel terminar o cadastro." << endl;
        return false;
    }
}
>>>>>>> 92279db8067ab157fc742345f33fd841c18c9639

bool CntrMSUsuario::autenticar( const Identificador &identificador, const Senha &senha)
{
    ResultadoUsuario resultado;
    resultado = container->buscarUsuario( identificador );

	if ( ( resultado.getValor() == Resultado::SUCESSO ) &&
	 (resultado.getUsuario().getSenha().getSenha() == senha.getSenha() ) )
	{
        return true;
	}

    return false;
}
<<<<<<< HEAD

bool CntrMSUsuario::validarUsuario( const Identificador &identificador, const Senha &senha )
{
    ResultadoUsuario resultado;
    resultado = container->buscarUsuario( identificador );

    if( resultado.getValor() == Resultado::SUCESSO )
    {
        return false;
    }

    return true;
}

bool CntrMSUsuario::incluirUsuario(const Usuario &novoUsuario)
{
    ResultadoUsuario resultado;
    resultado = container->incluirUsuario( novoUsuario );

    if( resultado.getValor() == Resultado::SUCESSO )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CntrMSUsuario::incluirConta(const ContaCorrente &novaConta)
{
    ResultadoConta resultado;
    resultado = container->incluirConta( novaConta );
    if( resultado.getValor() == Resultado::SUCESSO )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CntrMSUsuario::incluirCartao(const CartaoCredito &novoCartao)
{
    ResultadoCartao resultado;
    resultado = container->incluirCartao( novoCartao );
    if(resultado.getValor() == Resultado::SUCESSO)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CntrMSUsuario::removerUsuario(const Identificador &idUsuario)
{
    ResultadoUsuario resultadoUsuario;
    ResultadoAcomodacao resultadoAcomodacao;
    ResultadoReserva resultadoReserva;

    resultadoAcomodacao = containerAcomodacoes->buscarAcomodacao( idUsuario );
    resultadoReserva = containerAcomodacoes->buscarReservaUsuario( idUsuario );

    if( (resultadoAcomodacao.getAcomodacoes().empty() == true) && (resultadoReserva.getReservas().empty() == true) )
    {
        resultadoUsuario = container->removerUsuario( idUsuario );
        container->removerCartao( idUsuario );
        container->removerConta( idUsuario );
        if( resultadoUsuario.getValor() == Resultado::SUCESSO)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool CntrMAUsuario::iniciarMenuUsuario(Identificador *idUsuario)
{
    int opcao = -1;
    int resultado = false;

    cout << endl << "Menu do usuario." << endl << endl;
    cout << "Descadastrar usuario     - " << DESCADASTRAR << endl;
    cout << "Cadastrar cartao         - " << CADASTRAR_CARTAO << endl;
    cout << "Cadastrar conta corrente - " << CADASTRAR_CONTA << endl;
    cout << "Sair                     - " << SAIR << endl;

    do
    {
        cout << "Selecione uma opcao: ";
        cin >> opcao;
    } while( opcao < DESCADASTRAR || opcao > SAIR );

    switch( opcao )
    {
    case DESCADASTRAR:
        resultado = descadastrarUsuario( idUsuario );
        break;

    case CADASTRAR_CARTAO:
        resultado = cadastrarCartao( idUsuario );
        break;

    case CADASTRAR_CONTA:
        resultado = cadastrarConta( idUsuario );
        break;
    }

    return resultado;
=======

bool CntrMSUsuario::incluirUsuario(const Usuario &novoUsuario)
{
    ResultadoUsuario resultado;
    resultado = container->incluirUsuario( novoUsuario );

    if( resultado.getValor() == Resultado::SUCESSO )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CntrMSUsuario::incluirConta(const ContaCorrente &novaConta)
{
    ResultadoConta resultado;
    resultado = container->incluirConta( novaConta );
    if( resultado.getValor() == Resultado::SUCESSO )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CntrMSUsuario::incluirCartao(const CartaoCredito &novoCartao)
{
    ResultadoCartao resultado;
    resultado = container->incluirCartao( novoCartao );
    if(resultado.getValor() == Resultado::SUCESSO)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CntrMSUsuario::removerUsuario(const Identificador &idUsuario)
{
    ResultadoUsuario resultadoUsuario;
    ResultadoAcomodacao resultadoAcomodacao;
    ResultadoReserva resultadoReserva;

    resultadoAcomodacao = containerAcomodacoes->buscarAcomodacao( idUsuario );
    resultadoReserva = containerAcomodacoes->buscarReservaUsuario( idUsuario );

    if( (resultadoAcomodacao.getAcomodacoes().empty() == true) && (resultadoReserva.getReservas().empty() == true) )
    {
        resultadoUsuario = container->removerUsuario( idUsuario );
        container->removerCartao( idUsuario );
        container->removerConta( idUsuario );
        if( resultadoUsuario.getValor() == Resultado::SUCESSO)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool CntrMAUsuario::iniciarMenuUsuario(Identificador *idUsuario)
{
    int opcao = -1;
    int resultado = false;

    cout << endl << "----------------------------------------------------" << endl;
    cout <<         "                Menu do usuario                     " << endl;
    cout <<         "----------------------------------------------------" << endl;
    cout <<         "Descadastrar usuario     - " << DESCADASTRAR << endl;
    cout <<         "Cadastrar cartao         - " << CADASTRAR_CARTAO << endl;
    cout <<         "Cadastrar conta corrente - " << CADASTRAR_CONTA << endl;
    cout <<         "Sair                     - " << SAIR << endl;

    do
    {
        cout << "Selecione uma opcao: ";
        cin >> opcao;
    } while( opcao < DESCADASTRAR || opcao > SAIR );

    switch( opcao )
    {
    case DESCADASTRAR:
        resultado = descadastrarUsuario( idUsuario );
        break;

    case CADASTRAR_CARTAO:
        resultado = cadastrarCartao( idUsuario );
        break;

    case CADASTRAR_CONTA:
        resultado = cadastrarConta( idUsuario );
        break;
    }

    return resultado;
>>>>>>> 92279db8067ab157fc742345f33fd841c18c9639
}

void CntrMAAcomodacao::iniciarMenuAcomodacao( const Identificador &idUsuario )
{

    int opcao;

    while(true)
    {

        // Apresentar as opções.
        cout << "----------------------------------------------------" << endl;
        cout << endl << "Menu Acomodacao" << endl << endl;

        cout << "Acomodacoes Disponiveis   - " << EXIBIR << endl;
        cout << "Cadastrar Acomodacao      - " << CADASTRAR << endl;
        cout << "Descadastrar Acomodacao   - " << DESCADASTRAR << endl;
        cout << "Cadastrar Disponibilidade - " << DISPONIBILIDADE << endl;
        cout << "Fazer Reserva             - " << FAZER_RESERVA << endl;
        cout << "Cancelar Reserva          - " << CANCELAR_RESERVA << endl;
        cout << "Sair                      - " << SAIR << endl;
        cout << "Selecione uma opcao :";

        cin >> opcao;

        switch(opcao)
        {
            case EXIBIR:            exibirAcomodDisp( idUsuario );

                            break;
            case CADASTRAR:         cadastrarAcomodacao( idUsuario );

                            break;
            case DESCADASTRAR:
                                    descadastrarAcomodacao( idUsuario );

                            break;
            case DISPONIBILIDADE:
                                    cadastrarDisponibilidade(idUsuario);

                            break;
            case FAZER_RESERVA:
                                    fazerReserva(idUsuario);
                            break;
            case CANCELAR_RESERVA:
            						cancelarReserva(idUsuario);
                            break;
            case SAIR:

                            break;
        }

        if(opcao == SAIR){
            break;
        }

    }

    return;
}


void CntrMAAcomodacao::cadastrarAcomodacao( const Identificador &idUsuario)
{
    float diariaFlt;
    int capacidadeInt, resposta, operacao, resultado;
    string identificadorStr;
    string estadoStr;
    string cidadeStr;
    string tipoStr;
    Diaria diaria;
    Identificador idAcomodacao;
    Nome cidade;
    Estado estado;
    CapAcomodacao capacidade;
    TpAcomodacao tipo;
    Acomodacao acomodacao;

    resultado = cntrMSAcomodacao->verificarConta(idUsuario);
    if(resultado == false)
    {
        cout << "Usuario não possui conta corrente cadastrada." << endl;
        return;

    }

    do
    {
        operacao = SUCESSO;
        resposta = SIM;
        cout << "----------------------------------------------------" << endl;
        cout << "Insira os dados da Acomodacao que deseja cadastrar: " << endl;
        cout << "Identificador: " << endl;
        cin >> identificadorStr;
        cout << "Tipo: " << endl;
        cin >> tipoStr;
        cout << "Estado: " << endl;
        cin >> estadoStr;
        cout << "Cidade: " << endl;
        cin >> cidadeStr;
        cout << "Capacidade " << endl;
        cin >> capacidadeInt;
        cout << "Diaria " << endl;
        cin >> diariaFlt;
        try{

            idAcomodacao.setIdentificador(identificadorStr);
            tipo.setTpAcomodacao(tipoStr);
            estado.setEstado(estadoStr);
            cidade.setNome(cidadeStr);
            capacidade.setCapAcomodacao(capacidadeInt);
            diaria.setDiaria(diariaFlt);
        }
        catch ( invalid_argument excecao )
        {
            operacao = FALHA;
            cout << "Dados fornecidos em formato errado" << endl;
            cout << "Deseja tentar novamente?" << endl;
            cout << "Sim  -" << SIM << endl;
            cout << "Não  -" << NAO << endl;
            cin >> resposta;
        }

        if ( resposta == NAO )
        {
            cout << "----------------------------------------------------" << endl;
            return;
        }

    }while(operacao == FALHA);

    acomodacao.setCapacidade(capacidade);
    acomodacao.setDiaria(diaria);
    acomodacao.setTipo(tipo);
    acomodacao.setIdentificador(idAcomodacao);
    acomodacao.setCidade(cidade);
    acomodacao.setEstado(estado);
    acomodacao.setIdUsuario(idUsuario);
    resultado = cntrMSAcomodacao->cadastrarAcomodacao(acomodacao);
    if ( resultado == true)
    {
        cout << "Acomodacao cadastrada" << endl;
    }
    else
    {
        cout << "Falha no cadastramento da Acomodacao" << endl;
    }

    cout << "----------------------------------------------------" << endl;

    return;
}


void CntrMAAcomodacao::descadastrarAcomodacao( const Identificador &idUsuario)
{
    int operacao, resposta, resultado;
    string identificador;
    Identificador idAcomodacao;

    do
    {
        operacao = SUCESSO;
        resposta = SIM;
        cout << "Digite o identifcador da acomodacao que deseja descadastrar:" << endl;
        cin >> identificador;
        try{

            idAcomodacao.setIdentificador(identificador);
        }
        catch ( invalid_argument excecao )
        {
            operacao = FALHA;
            cout << "Dados fornecidos em formato errado" << endl;
            cout << "Deseja tentar novamente?" << endl;
            cout << "Sim  -" << SIM << endl;
            cout << "Não  -" << NAO << endl;
            cin >> resposta;
        }
        if ( resposta == NAO )
        {
            cout << "----------------------------------------------------" << endl;
            return;
        }
    }while(operacao == FALHA);

    resultado = cntrMSAcomodacao->descadastrarAcomodacao(idUsuario, idAcomodacao);
    if ( resultado == Resultado::SUCESSO )
    {
        cout << "Acomodacao descadastrada" << endl;
    }
    else
    {
        cout << "Falha no descadastramento da Acomodacao" << endl;
    }

    cout << "----------------------------------------------------" << endl;
    return;

}


void CntrMAAcomodacao::exibirAcomodDisp( const Identificador &idUsuario )
{
    int operacao;
    int resposta;
    string estadoStr;
    string dataInicioStr;
    string dataTerminoStr;
    string cidadeStr;
    int capacidadeInt;
    Nome cidade;
    Estado estado;
    Data dataInicio;
    Data dataTermino;
    CapAcomodacao capacidade;
    Acomodacao acomodDesejada;
    list<Acomodacao> acomodDisp;

    do
    {
        operacao = SUCESSO;
        resposta = SIM;
        cout << "----------------------------------------------------" << endl;
        cout << "Forneça os dados da Acomodação que deseja:\n" << endl;
        cout << "Estado:" << endl;
        cin >> estadoStr;
        cout << "Cidade:" << endl;
        cin >> cidadeStr;
        cout << "Data de inicio da estadia:" << endl;
        cin >> dataInicioStr;
        cout << "Data de termino da estadia:" << endl;
        cin >> dataTerminoStr;
        cout << "capacidade" << endl;
        cin >> capacidadeInt;

        try
        {

            cidade.setNome( cidadeStr );
            estado.setEstado( estadoStr );
            capacidade.setCapAcomodacao( capacidadeInt );
            dataInicio.setData( dataInicioStr );
            dataTermino.setData( dataTerminoStr );
        }
        catch ( invalid_argument excecao )
        {
            operacao = FALHA;
            cout << "Dados fornecidos em formato errado" << endl;
            cout << "Deseja tentar novamente?" << endl;
            cout << "Sim  -" << SIM << endl;
            cout << "Não  -" << NAO << endl;
            cin >> resposta;
        }
        if ( resposta == NAO )
        {
            cout << "----------------------------------------------------" << endl;
            return;
        }

    }while(operacao == FALHA);
    // Cria uma acomodação modelo para fazer a buscas
    acomodDesejada.setCidade(cidade);
    acomodDesejada.setEstado(estado);
    acomodDesejada.setDataTermino(dataTermino);
    acomodDesejada.setDataInicio(dataInicio);
    acomodDesejada.setCapacidade(capacidade);
    ResultadoAcomodacao resultado;

    resultado = cntrMSAcomodacao->AcomodacoesDisp(acomodDesejada);
    acomodDisp = resultado.getAcomodacoes();
    list<Acomodacao>::iterator elemento;


    if (resultado.getValor() == Resultado::FALHA)
    {
        cout << "Não foram encontradas acomodacoes com essas caracteristicas." << endl;
        cout << "----------------------------------------------------" << endl;
    }
    else
    {
        cout << "----------------------------------------------------" << endl;
        cout << "Acomodacões disponiveis:" << endl;
        // Exibe na tela as caracteristicas das acomodações encontradas
        for( elemento = acomodDisp.begin(); elemento != acomodDisp.end(); elemento++ )
        {
            cout << "Identificador: " << elemento->getIdentificador().getIdentificador() << endl;
            cout << "Tipo: " << elemento->getTipo().getTpAcomodacao();
            cout << "Capacidade: " << elemento->getCapacidade().getCapAcomodacao() << endl;
            cout << "Diaria: " << elemento->getDiaria().getDiaria() << endl;
            cout << "Cidade: " << elemento->getCidade().getNome() << endl;
            cout << "Estado: " << elemento->getEstado().getEstado() << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }

    return;
}


void CntrMAAcomodacao::cadastrarDisponibilidade(const Identificador &idUsuario )
{
    int operacao, resposta;
    bool resultado;
    string identificador, dataInicioStr, dataTerminoStr;
    Data dataInicio, dataTermino;
    Disponibilidade disponibilidade;
    Identificador idAcomodacao;
    do
    {
        operacao = SUCESSO;
        resposta = SIM;
        cout << "Digite o identifcador da acomodacao que deseja cadastrar uma disponibilidade" << endl;
        cin >> identificador;
        cout << "Digite a data de inicio da disponibilidade:" << endl;
        cin >> dataInicioStr;
        cout << "Digite a data de termino da disponibilidade:" << endl;
        cin >> dataTerminoStr;
        try{

            idAcomodacao.setIdentificador(identificador);
            dataInicio.setData(dataInicioStr);
            dataTermino.setData(dataTerminoStr);
        }
        catch ( invalid_argument excecao )
        {
            operacao = FALHA;
            cout << "Dados fornecidos em formato errado" << endl;
            cout << "Deseja tentar novamente?" << endl;
            cout << "Sim  -" << SIM << endl;
            cout << "Não  -" << NAO << endl;
            cin >> resposta;
        }
        if ( resposta == NAO )
        {
            cout << "----------------------------------------------------" << endl;
            return;
        }
    }while(operacao == FALHA);

    disponibilidade.setIdAcomodacao(idAcomodacao);
    disponibilidade.setDataInicio(dataInicio);
    disponibilidade.setDataTermino(dataTermino);
    resultado = cntrMSAcomodacao->cadastrarDisponibilidade(idUsuario, disponibilidade);
    if ( resultado == Resultado::SUCESSO )
    {
        cout << "Disponibilidade cadastrada" << endl;
    }
    else
    {
        cout << "Falha no cadastramento da disponibilidade" << endl;
    }

    cout << "----------------------------------------------------" << endl;
    return;

}

void CntrMAAcomodacao::fazerReserva( const Identificador &idUsuario )
{
    int resultado;
    int operacao;
    int resposta;
    Reserva reserva;
    string dataInicioStr, dataTerminoStr, identificador;
    Identificador idAcomodacao;
    Data dataInicio, dataTermino;

    //verifica se o usuario tem cartão de crédito
    resultado = cntrMSAcomodacao->verificarCartao(idUsuario);
    if(resultado == false)
    {
        cout << "Usuario não possui cartão cadastrado." << endl;
        return;

    }
    do{

        operacao = SUCESSO;
        resposta = SIM;
        cout << "Digite o identificador da acomodacao que deseja reservar:" << endl;
        cin >> identificador;
        cout << "Digite a data de inicio da reserva:" << endl;
        cin >> dataInicioStr;
        cout << "Digite a data de termino da reserva:" << endl;
        cin >> dataTerminoStr;
        try
        {
            dataInicio.setData(dataInicioStr);
            dataTermino.setData(dataTerminoStr);
            idAcomodacao.setIdentificador(identificador);
        }
        catch ( invalid_argument excecao )
        {
            operacao = FALHA;
            cout << "Dados fornecidos em formato errado" << endl;
            cout << "Deseja tentar novamente?" << endl;
            cout << "Sim  -" << SIM << endl;
            cout << "Não  -" << NAO << endl;
            cin >> resposta;
        }
        if ( resposta == NAO )
        {
            cout << "----------------------------------------------------" << endl;
            return;
        }

    }while(operacao == FALHA);

    reserva.setIdAcomodacao(idAcomodacao);
    reserva.setIdUsuario( idUsuario );
    reserva.setDataInicio( dataInicio );
    reserva.setDataTermino( dataTermino );

    resultado = cntrMSAcomodacao->fazerReserva(reserva);
    if (resultado == true)
    {
        cout << "Reserva realizada com sucesso." << endl;
    }
    else{
        cout << "Falha na realização da reserva." << endl;
    }

    cout << "----------------------------------------------------" << endl;
    return;
}


void CntrMAAcomodacao::cancelarReserva( const Identificador &idUsuario )
{
    int resultado;
    int operacao;
    int resposta;
    Reserva reserva;
    string dataInicioStr, dataTerminoStr, identificador;
    Identificador idAcomodacao;
    Data dataInicio, dataTermino;

    do{

        operacao = SUCESSO;
        resposta = SIM;
        cout << "Digite o identificador da acomodacao que foi reservada:" << endl;
        cin >> identificador;
        cout << "Digite a data de inicio da reserva:" << endl;
        cin >> dataInicioStr;
        cout << "Digite a data de termino da reserva:" << endl;
        cin >> dataTerminoStr;
        try
        {
            dataInicio.setData(dataInicioStr);
            dataTermino.setData(dataTerminoStr);
            idAcomodacao.setIdentificador(identificador);
        }
        catch ( invalid_argument excecao )
        {
            operacao = FALHA;
            cout << "Dados fornecidos em formato errado" << endl;
            cout << "Deseja tentar novamente?" << endl;
            cout << "Sim  -" << SIM << endl;
            cout << "Não  -" << NAO << endl;
            cin >> resposta;
        }
        if ( resposta == NAO )
        {
            cout << "----------------------------------------------------" << endl;
            return;
        }

    }while(operacao == FALHA);

    reserva.setIdAcomodacao(idAcomodacao);
    reserva.setIdUsuario( idUsuario );
    reserva.setDataInicio( dataInicio );
    reserva.setDataTermino( dataTermino );

    resultado = cntrMSAcomodacao->cancelarReserva(reserva);
    if (resultado == true)
    {
        cout << "Reserva cancelada com sucesso." << endl;
    }
    else{
        cout << "Reserva não encontrada." << endl;
    }

    cout << "----------------------------------------------------" << endl;
    return;
}



bool CntrMSAcomodacao::cadastrarAcomodacao( const Acomodacao &acomodacao )
{
    ResultadoAcomodacao resultado;
    resultado = containerAcomodacao->incluirAcomodacao(acomodacao);
    return resultado.getValor();
}

bool CntrMSAcomodacao::descadastrarAcomodacao( const Identificador &idUsuario, const Identificador &idAcomodacao )
{
    ResultadoAcomodacao resultado;
    ResultadoAcomodacao resultadoAcomod;
    ResultadoReserva resultadoReserva;

    string identificador = idAcomodacao.getIdentificador();
    list<Acomodacao> acomodacoes;
    list<Acomodacao>::iterator elemento;

    resultadoAcomod = containerAcomodacao->buscarAcomodacao(idUsuario);
    acomodacoes = resultadoAcomod.getAcomodacoes();
    resultadoReserva = containerAcomodacao->buscarReservaAcomodacao(idAcomodacao);
    if (resultadoAcomod.getValor() == Resultado::FALHA || resultadoReserva.getValor() == Resultado::SUCESSO)
    {
        return false;
    }
    else if (resultadoAcomod.getValor() == Resultado::SUCESSO)
    {
        for(elemento = acomodacoes.begin(); elemento != acomodacoes.end(); elemento++)
        {
            if(elemento->getIdentificador().getIdentificador() == identificador )
            {
                resultado = containerAcomodacao->removerAcomodacao(idAcomodacao);
                return resultado.getValor();
            }
        }
    }

    return false;
}

ResultadoAcomodacao CntrMSAcomodacao::AcomodacoesDisp( const Acomodacao &acomodModelo )
{
    ResultadoAcomodacao resultado;

    resultado = containerAcomodacao->buscarAcomodacaoDisp(acomodModelo);

    return resultado;
}

bool CntrMSAcomodacao::cadastrarDisponibilidade( const Identificador &idUsuario , Disponibilidade disponibilidade )
{
    ResultadoAcomodacao resultado;
    ResultadoDisponib resultadoDisp;
    string identificador = disponibilidade.getIdAcomodacao().getIdentificador();
    list<Acomodacao> acomodacoes;
    list<Acomodacao>::iterator elemento;

    resultado = containerAcomodacao->buscarAcomodacao(idUsuario);
    acomodacoes = resultado.getAcomodacoes();

    if(resultado.getValor() == Resultado::SUCESSO)
    {
        for(elemento = acomodacoes.begin(); elemento != acomodacoes.end(); elemento++)
        {
            if (elemento->getIdentificador().getIdentificador() == identificador)
            {
                resultadoDisp = containerAcomodacao->incluirDisponib(disponibilidade);
                if (resultadoDisp.getValor() == Resultado::SUCESSO)
                {
                    return true;
                }
            }
        }
        return false;
    }
    return false;
}

bool CntrMSAcomodacao::cancelarReserva( Reserva reserva )
{
	ResultadoReserva resultado;
	resultado = containerAcomodacao->removerReserva(reserva);

	return resultado.getValor();
}

bool CntrMSAcomodacao::verificarCartao( const Identificador &idUsuario )
{
    ResultadoCartao resultado;

    resultado = containerUsuario->buscarCartao(idUsuario);

    return resultado.getValor();
}

bool CntrMSAcomodacao::verificarConta( const Identificador &idUsuario )
{
    ResultadoConta resultado;

    resultado = containerUsuario->buscarConta(idUsuario);

    return resultado.getValor();
}


bool CntrMSAcomodacao::fazerReserva( Reserva reserva)
{
    ResultadoDisponib resultadoDisp;
    ResultadoReserva resultadoReserva;
    string identificador = reserva.getIdAcomodacao().getIdentificador();
    list<Disponibilidade> disponiveis;
    list<Disponibilidade>::iterator elemento;

    resultadoDisp = containerAcomodacao->buscarDisponib(reserva.getDataInicio(), reserva.getDataTermino());
    disponiveis = resultadoDisp.getDisponibilidades();
    for (elemento = disponiveis.begin(); elemento != disponiveis.end(); elemento++)
    {
        if (elemento->getIdAcomodacao().getIdentificador() == identificador)
        {
            containerAcomodacao->removerDisponib(*elemento);
            resultadoReserva = containerAcomodacao->incluirReserva(reserva);
            return resultadoReserva.getValor();
        }
    }
    return false;

}
