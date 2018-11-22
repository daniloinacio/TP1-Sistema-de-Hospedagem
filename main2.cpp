#include <iostream>
#include "containers.hpp"
#include "controladoras.hpp"
#include "interfaces.hpp"
#include "entidades.hpp"
#include "dominios.hpp"

using namespace std;

int main()
{
ContainerUsuario containerUsuario;
ContainerAcomodacao containerAcomodacao;

CntrMAAutenticacao cntrMAAutenticacao;
CntrMAAcomodacao cntrMAAcomodacao;

//CntrMAUsuario cntrUsuario;
//CntrMSUsuario cntrMSUsuario;
CntrMSAcomodacao cntrMSAcomodacao;

//Identificador idUsuario;
//idUsuario.setIdentificador("danil");

cntrMSAcomodacao.setContainer( &containerAcomodacao );
cntrMAAcomodacao.setCntrMSAcomodacao(&cntrMSAcomodacao);
//cntrMAAcomodacao.iniciarMenuAcomodacao( idUsuario );

//ContainerUsuario container;
//CntrMAAutenticacao cntrMAAutenticacao;
CntrMSUsuario cntrMSUsuario;
CntrMAUsuario cntrUsuario;

// Setando os objetos acima criados
cntrMSUsuario.setContainer( &containerUsuario );
//cntrMAAutenticacao.setCntrMSAutenticacao( &cntrMSAcomodacao );
cntrUsuario.setCntrMSUsuario( &cntrMSUsuario );

// Criando identificador temporario e bool de resultado
//Identificador *identificador = new Identificador();
bool resultado;

//cntrUsuario.cadastrarUsuario( identificador );
//resultado = cntrUsuario.iniciarMenuUsuario( identificador );
//cout << resultado << endl;

//delete identificador;

CntrMASistema sistema;
sistema.setCntrMAUsuario( &cntrUsuario );
sistema.setCntrMAAcomodacao( &cntrMAAcomodacao );
sistema.setCntrMAAutenticacao( &cntrMAAutenticacao );
Identificador *idUsuario = new Identificador();
resultado = sistema.menuPrincipal( idUsuario );

return 0;
}
