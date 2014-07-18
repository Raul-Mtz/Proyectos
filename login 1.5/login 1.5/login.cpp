#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

//
void login();
void registrate();
int main();
//

struct persona{

	string usuario;
	string pass;

};

void registrate(){

	locale::global(locale("spanish"));
	system("cls");

	//
	persona userreg;
	string segundoint;
	string linant = "";
	string lin;
	//

	cout << "Introduce tu nombre de usuario: ";
	cin.ignore();
	getline(cin, userreg.usuario);

	/*Usuario repetido
	char nombre[userreg.usuario.length];
	ifstream usuario;
	usuario.open("C:\\users\\raul\\desktop\\login2\\usuarios.txt");

	while (!usuario.eof()){
	getline(usuario, lin);
	if (lin != linant) {
	lin = linant;
	}
	lin = nombre;
	if (lin == userreg.usuario){
	cout << "hola";
	}
	};
	*/

repetir:

	cout << "\nIntroduce tu contraseña: ";
	getline(cin, userreg.pass);
	cout << "Introduce tu contraseña nuevamente: ";
	getline(cin, segundoint);

	if (segundoint == userreg.pass){
		cout << "\n\n¡Correcto!";

		ofstream escribir;
		escribir.open("C:\\users\\raul\\desktop\\login 1.5\\usuarios.txt", ios::out | ios::app);
		escribir << userreg.usuario + ":" + userreg.pass << "\n";
		escribir.close();

		Sleep(1500);
		main();
	}

	else{
		cout << "\n\nParece que esa no es tu contraseña...\nIntroduce una nueva";
		Sleep(1500);
		goto repetir;
	}

}

void login(){

	locale::global(locale("spanish"));
	system("cls");

	//
	persona userlog;
	string conjunto;
	string lineant = "";
	string linea;
	//

	cout << "Introduce tu nombre de usuario: ";
	cin.ignore();
	getline(cin, userlog.usuario);
	cout << "Introduce tu contraseña: ";
	getline(cin, userlog.pass);

	conjunto = userlog.usuario + ":" + userlog.pass;

	ifstream archivo("c:\\users\\raul\\desktop\\login 1.5\\usuarios.txt", ios::in);

	while (linea != conjunto){
		getline(archivo, linea);

		if (linea != lineant){
			lineant = linea;
			if (linea == conjunto){
				cout << "\n\n¡Te has loggeado exitosamente!\n\n\n";
				archivo.close();
				system("pause");
				main();
			}
		}

		else{
			cout << "\n\n¡No te has loggeado exitosamente!\n\n\n";
			Sleep(1000);
			archivo.close();
			main();
		}
	}

}

int main(){
	locale::global(locale("spanish"));

rep:

	system("cls");

	int res;

	cout << " ---------- \n";
	cout << "|  LOG IN  |\n";
	cout << " ---------- \n";
	cout << "Opciones:\n1.-Loggeate\n2.-Registrate\n3.-Salir\n\n ";

	cin >> res;

	if (res == 1){
		login();
	}

	else if (res == 2){
		registrate();
	}

	else if (res == 3){
		cout << "\n";
		return 0;
	}

	else{
		cout << "¡'" << res << "' No es un argumento válido!\nIntroduce una respuesta válida...\n";
		goto rep;
	}

}