
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <functional>
using namespace std;

// Aqui creamos la funcion para imprimir la info de los candidatos
void informacionCandidatos() {
	int inf;
	cout << "Entre 1 para ver informacion sobre Donald Trump" << endl;
	cout << "Entre 2 para ver la informacion sobre Joe Biden" << endl;
	cout << "Entre 3 para ver la informacion de Robert Kennedy JR." << endl;
	cin >> inf;
	string line;
	ofstream outfile;
	ifstream infile;
	// Dependiendo de la opción del usuario, creamos un archivo con la informacion de cada candidato y luego se lee
	if (inf == 1) {
		outfile.open("Trump.txt");
		outfile << "Ex presidente, Millonario, Piel de mandarina, quiere crear un muro, Make america great again." << endl;
		outfile.close();
		infile.open("trump.txt");
	}
	else if (inf == 2) {
		outfile.open("Biden.txt");
		outfile << "Presidente Actual , Millonario, Odia las escaleras, Olvidadizo, Le gusta el mantecado." << endl;
		outfile.close();
		infile.open("Biden.txt");
	}
	else if (inf == 3) {
		outfile.open("Kennedy.txt");
		outfile << "UnderDog, Voz Ronca, Activista, Antivacunas." << endl;
		outfile.close();
		infile.open("Kennedy.txt");
	}
	else {
		cout << "Seleccion invalida :( " << endl;
		return;
	}
	// Se lee los archivos y se muestra la informacion
	while (getline(infile, line)) {
		cout << line;
	}
	infile.close();
}

// Aqui tenemos la Funcion para mostrar los resultados de la votacion
void verResultados(int trump, int biden, int kennedy) {
	int totalVotes = trump + biden + kennedy;
	if (totalVotes == 0) {
		cout << "No se han registrado votos aun." << endl;
	}
	else {
		// Aqui se calculan los porcentajes de votos para cada candidato
		double trumpPercentage = (double)trump / totalVotes * 100;
		double bidenPercentage = (double)biden / totalVotes * 100;
		double kennedyPercentage = (double)kennedy / totalVotes * 100;

		//muestros los resultados  
		cout << "Resultados de la votacion:" << endl;
		cout << "Donald J. Trump: " << trump << " votos (" << trumpPercentage << "%)" << endl;
		cout << "Joe R. Biden: " << biden << " votos (" << bidenPercentage << "%)" << endl;
		cout << "Robert F. Kennedy JR.: " << kennedy << " votos (" << kennedyPercentage << "%)" << endl;
	}
}

// esta es la funcion para generar un hash unico basado en el ID electoral del votante y el ID del candidato
size_t hashimura(string numElectoral, string idCand) {
	string IDNEW;
	IDNEW = numElectoral + idCand;
	hash<string> hash_fn;
	size_t hasi = hash_fn(IDNEW);
	return hasi;
}

// Main block de codigo
int main()
{
	// Aqui definimos todas las variables que se utilizaron en el codigo
	string idTrump = "6452349", idBiden = "9244621", idKennedy = "7852462";
	size_t hasho;
	string numElectoral, idCand, nameVotante;
	int menu = 0;
	int kennedy = 0, biden = 0, trump = 0;
	int voto, inf, key;
	int totalVotes = trump + biden + kennedy;
	string infVots[30][2];
	int CantVots = 0;


	// Bucle para poder correr el programa en un loop do-while
	do {
		// aqui mostramos el menu
		cout << "1: Registrar voto " << endl;
		cout << "2: Informacion candidatos" << endl;
		cout << "3: Ver resultados" << endl;
		cout << "4: Admin" << endl;
		cout << "5: Salir" << endl;
		cin >> menu;
		// Dependiendo de lo que escoga del usuario, se realiza una accion
		switch (menu) {
		case 1:
			// Aqui estamos abriendo el primer case que se utiliza para registrar los votantes
			cout << "Entre su nombre: " << endl;
			cin >> nameVotante;
			cout << "Entre su numero de ID electoral" << endl;
			cin >> numElectoral;
			cout << "Entre 1 para votar por Donald J. Trump: " << endl;
			cout << "Entre 2 para votar por Joe R. Biden" << endl;
			cout << "Entre 3 para votar por Robert F. Kennedy JR." << endl;
			cin >> voto;
			// Dependiendo de lo que escoga el usuario, se incrementa el contador de votos del candidato correspondiente
			if (voto == 1) {
				trump++;
				idCand = idTrump;
			}
			else if (voto == 2) {
				biden++;
				idCand = idBiden;
			}
			else if (voto == 3) {
				kennedy++;
				idCand = idKennedy;
			}
			else {
				cout << "Numero Invalido." << endl;
			}
			// Se genera el hash del voto
			hasho = hashimura(numElectoral, idCand);
			cout << "Gracias por su voto, " << nameVotante << ", su numero unico de votacion es: " << hasho << endl;
			// Se guarda la información del voto
			if (CantVots < 30) {
				infVots[CantVots][0] = nameVotante;
				infVots[CantVots][1] = to_string(hasho);
				CantVots++;
			}
			else {
				cout << "Cantidad maxima de votos alcanzado." << endl;
			}
			Sleep(6000);
			system("cls");
			break;
		case 2:
			// Se muestra la información de los candidatos
			informacionCandidatos();
			Sleep(10000);
			system("cls");
			break;
		case 3:
			// Se muestran los resultados de la votación
			verResultados(trump, biden, kennedy);
			Sleep(10000);
			system("cls");
			break;
		case 4:
			// Modo administrador
			cout << "Administrador, entre la clave de acceso: " << endl;
			cin >> key;
			// Si la clave administrativa es correcta, se muestra los hash de los usuarios
			if (key == 69420) {
				cout << "Acceso Concedido." << endl;
				Sleep(2000);
				system("cls");
				for (int i = 0; i < CantVots; i++) {
					cout << "Votante #" << i + 1 << ": " << infVots[i][0] << ", Hash: " << infVots[i][1] << endl;
				}
			}
			else {
				cout << "ACCESS DENIED." << endl;
				Sleep(2000);
				system("cls");
			}
		}

	} while (menu != 5); {
		cout << "Gracias por utilizar, adios." << endl;
		Sleep(3000);
		system("cls");

	}
	return 0;
}