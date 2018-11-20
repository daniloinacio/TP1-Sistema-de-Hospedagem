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

cntrMSUsuario.setContainer( &container );
cntrMAAutenticacao.setCntrMSAutenticacao( &cntrMSUsuario );
cntrUsuario.setCntrMSUsuario( &cntrMSUsuario );
Identificador *identificador = new Identificador();
bool resultado;

resultado = cntrUsuario.cadastrarUsuario( identificador );
cout << endl << "Resultado: " << resultado << endl;
delete identificador;
return 0;
}
