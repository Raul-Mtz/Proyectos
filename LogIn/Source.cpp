#include <Windows.h>
#include  <iostream>
#include  "sha256.h"
#include   <fstream>
#include    <string>

using namespace std;

//
void registrate();
void login();
int main();
//

SHA256 sha256;

struct persona{

	string usuario;
	string pass;

};

void registrate(){

	locale::global(locale("spanish"));

rep2:

	cin.ignore();
	
	system("cls");

	//
	bool wspace = false;
	persona     userreg;
	string   segundoint;
	string lineant = "";
	string       linea1;
	string       nlinea;
	char        espacio;
	//

	std::cout << "Introduce tu nombre de usuario: ";
	std::getline(cin, userreg.usuario);


	for (int i = 0; i <= userreg.usuario.length(); i++){
		espacio = userreg.usuario[i];
		
		if (espacio == ' '){
			wspace = true;
		}

	}

	if (userreg.usuario.empty() || wspace == true){
		cout << "\n\n¡Tu nombre de usuario no puede estar vacío!\n\n\n";
		system("pause");
		goto rep2;
	}

	ifstream usuario1;
	usuario1.open("C:\\users\\raul\\desktop\\loginfinal\\usuarios.txt", ios::in);

	while (linea1 != userreg.usuario){
		std::getline(usuario1, linea1);

		if (linea1 != lineant){
			lineant = linea1;
			std::getline(usuario1, linea1, ':');
			
			if (linea1 == userreg.usuario){
				cout << "¡El nombre de usuario:" << "'" << userreg.usuario << "' " << "ya está ocupado!\nElige uno nuevo... \n\n";
				usuario1.close();
				system("pause");
				goto rep2;
			}

		}

		else{
			usuario1.close();
			break;
		}

	}

repetir:

	std::cout << "\nIntroduce tu contraseña: ";
	std::getline(cin, userreg.pass);
	std::cout << "Introduce tu contraseña nuevamente: ";
	std::getline(cin, segundoint);

	if (segundoint == userreg.pass){
		std::cout << "\n\n¡Correcto!";

		ofstream escribir;
		escribir.open("C:\\users\\raul\\desktop\\loginfinal\\usuarios.txt", ios::out | ios::app);
		escribir << userreg.usuario + ":" + sha256(userreg.pass) << "\n";
		escribir.close();

		Sleep(1500);
		main();
	}

	else{
		std::cout << "\n\nParece que esa no es tu contraseña...\nIntroduce una nueva";
		Sleep(1500);
		goto repetir;
	}

};

void login(){

	locale::global(locale("spanish"));

	system("cls");

	//
	persona userlog;
	string conjunto;
	string lineant = "";
	string linea;
	//

	std::cout << "Introduce tu nombre de usuario: ";
	cin.ignore();
	std::getline(cin, userlog.usuario);
	std::cout << "Introduce tu contraseña: ";
	std::getline(cin, userlog.pass);

	conjunto = userlog.usuario + ":" + sha256(userlog.pass);

	ifstream archivo("c:\\users\\raul\\desktop\\loginfinal\\usuarios.txt", ios::in);

	while (linea != conjunto){
		std::getline(archivo, linea);

		if (linea != lineant){
			lineant = linea;
			
			if (linea == conjunto){
				std::cout << "\n\n¡Te has loggeado exitosamente!\n\n\n";
				archivo.close();
				system("pause");
				main();
			}

		}

		else{
			std::cout << "\n\n¡No te has loggeado exitosamente!\n\n\n";
			Sleep(1000);
			archivo.close();
			main();
		}

	}

};

int main(){

	locale::global(locale("spanish"));

rep:

	system("cls");
	
	//
	int res;
	//

	std::cout << " ---------- \n";
	std::cout << "|  LOG IN  |\n";
	std::cout << " ---------- \n";
	std::cout << "Opciones:\n1.-Loggeate\n2.-Registrate\n3.-Salir\n\n ";

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

};