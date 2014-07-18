#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <direct.h>

using namespace std;

struct persona{

	string usuario;
	string pass;

};

void login();
int main();

void registrate(){

	locale::global(locale("spanish"));
	system("cls");
	//
	persona userreg;
	string segundoint;
	string linant = "";
	string lin;
	string linea21;
	//

	cout << "Introduce tu nombre de usuario: ";
	cin.ignore();
	getline(cin, userreg.usuario);
	/*ifstream usuario;
	usuario.open("C:\\users\\raul\\desktop\\login2\\usuarios.txt");

	while (f < 1){
	getline(usuario, lin);
	if (lin != linant) {
	lin = linant;
	}
	};

	if (lin == userreg.usuario){
	cout << "\n\n¡Ese nombre de usuario ya está !\n\n";
	}*/
repetir:
	cout << "\n\nIntroduce tu contraseña: ";
	getline(cin, userreg.pass);
	cout << "\nIntroduce tu contraseña nuevamente: ";
	getline(cin, segundoint);

	if (segundoint == userreg.pass){
		cout << "\n\n¡Correcto!\n\n";
	}

	else{
		cout << "\n\nParece que esa no es tu contraseña...\nIntroduce una nueva";
		Sleep(1500);
		goto repetir;
	}

	ifstream usuariosant;
	usuariosant.open("C:\\users\\raul\\desktop\\login2\\usuarios.txt", ios::in);
	cin.ignore();
	getline(usuariosant, linea21);
	cin.ignore();
	getline(usuariosant, linea21);

	ofstream escribir;
	escribir.open("C:\\users\\raul\\desktop\\login2\\usuarios.txt", ios::out);
	escribir << linea21 << "\n" << userreg.usuario + ":" + userreg.pass + "\n" << "\n";

	/*fstream us;
	us.open("C:\\Users\Raul\\Desktop\\login2\\usuarios.txt", ios::in | ios::out);
	cin.ignore();
	//getline(us, linea21);
	
	us << "\n" << userreg.usuario + ":" + userreg.pass + "\n" << "\n";	
	*/
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
	cout << "\nIntroduce tu contraseña: ";
	getline(cin, userlog.pass);

	conjunto = userlog.usuario + ":" + userlog.pass;

	ifstream archivo("c:\\users\\raul\\desktop\\login2\\usuarios.txt");

	while (linea != conjunto){
		getline(archivo, linea);
		
		if (linea != lineant){
			lineant = linea;
			if (linea == conjunto){
				cout << "¡Te has loggeado exitosamente!\n";
			}
		}

		else{
			cout << "\n¡No te has loggeado exitosamente!\n";
			Sleep(1000);
			main();
		}
	}

}

int main(){
	locale::global(locale("spanish"));
	system("mode 40,25");
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