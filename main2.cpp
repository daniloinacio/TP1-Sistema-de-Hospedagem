#include <iostream>
#include "containers.hpp"
#include "controladoras.hpp"
#include "interfaces.hpp"
#include "entidades.hpp"
#include "dominios.hpp"

using namespace std;

int main()
{
ContainerUsuario container;
CntrMAAutenticacao cntrMAAutenticacao;
CntrMSUsuario cntrMSUsuario;
CntrMAUsuario cntrUsuario;

// Setando os objetos acima criados
cntrMSUsuario.setContainer( &container );
cntrMAAutenticacao.setCntrMSAutenticacao( &cntrMSUsuario );
cntrUsuario.setCntrMSUsuario( &cntrMSUsuario );

// Criando identificador temporario e bool de resultado
Identificador *identificador = new Identificador();
bool resultado;

cntrUsuario.cadastrarUsuario( identificador );
resultado = cntrUsuario.iniciarMenuUsuario( identificador );
cout << resultado << endl;

delete identificador;
return 0;
}
