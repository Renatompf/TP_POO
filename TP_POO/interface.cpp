//#include "Interface.h"
//using namespace std;
//
//
//int Interface::conta_palavras(string comando) { //Conta o nº de palavras do comando inserido
//	int conta = 0, flag = 0;
//	for (int i = 0; comando[i] != '\0'; i++) {
//		if (!flag && comando[i] != ' ') {
//			flag = 1;              //A flag serve para determinar quando estamos a percorrer
//			conta++;             //uma palavra ou nao, ou seja, quando a flag passa de 0 para 1
//		}			     //e porque e uma nova palavra e incrementas
//		else if (comando[i] == ' ')
//			flag = 0;
//	}
//	return conta;
//}
//
//void Interface::executa(string comando) {  // funcao que divide um comando por numero de argumentos, separa cada um deles
//	string word1, word2, word3, word4, word5, file;  // tornando-os variaveis individuais para uso posterior
//	string first, second, third;
//	int numargs = this->conta_palavras(comando);
//	if (numargs == 1)
//		this->executa_um(comando);
//	else if (numargs == 2) {
//		std::istringstream iss(comando);
//		iss >> word1;
//		iss >> word2;
//		if (word1 == "executa")
//			this->executa_comandos(word1, word2);
//		else {
//			std::istringstream(word2) >> file;
//			this->executa_dois(word1, file);
//		}
//	}
//	else if (numargs == 3) {
//		std::istringstream iss(comando);
//		iss >> word1; iss >> word2; iss >> word3;
//		std::istringstream(word2) >> first;
//		std::istringstream(word3) >> second;
//		this->executa_tres(word1, first, second);
//	}
//	/*else if (numargs == 4) {
//		std::istringstream iss(comando);
//		iss >> word1; iss >> word2; iss >> word3; iss >> word4;
//		std::istringstream(word2) >> first;
//		std::istringstream(word4) >> second;
//		this->executa_quatro(word1, first, word3, second);
//	}*/
//	/*else if (numargs == 5) {
//	std:istringstream iss(comando);
//		iss >> word1; iss >> word2; iss >> word3; iss >> word4; iss >> word5;
//		std::istringstream(word3) >> first;
//		std::istringstream(word4) >> second;
//		std::istringstream(word5) >> third;
//		this->executa_cinco(word1, word2, first, second, third);
//	}*/
//}
//
//void Interface::executa_um(string comando) {
//	if (comando == "sair") //Posteriormente, chama uma função que limpa memória e sai
//		exit(0);
//	else if (comando == "lista") { //Dá início á simulação se tudo estiver correto
//		carros::getAsString();
//		pilotos::GetPilotoAsString();
//	}
//	else {
//		//  cout << "Comando inexistente/Incorreto. Tente novamente." << endl;
//		// getchar();
//		system("cls");
//	}
//}
//
//void Interface::executa_dois(string comando, string file) {
//	if (comando == "carregaP") { //Carrega os Pilotos
//		DVG::readfilePilotos(file);
//	}
//	else if (comando == "carregaC") { //Carrega os Carros
//		DVG::readfileCarros(file);
//	}
//	else if (comando == "carregaA") { //Carrega os Autodromos
//		DVG::readfileAutodromo(file);
//	}
//	else if (comando == "saidocarro") { //Faz um piloto sair de um carro
//		string car;
//		car = carros::getId;
//		if ();
//	}
//	else if (comando == "campeonato") {   //Define a percentagem inicial de espaços vazios com migalhas
//		DVG::GetAutodromo(); //função ainda por fazer
//	}
//}
//
//void Interface::executa_tres(string comando, string first, string second) {
//	if (comando == "entranocarro")
//		DVG::emparelha(first, second);
//	else if (comando == "apaga") {
//		if (first == p)
//			DVG::deletePiloto(second);
//		else if (first == c)
//			DVG::deleteCarro(second);
//		else if (first == a)
//			DVG::deleteAutodromo(second);
//	}
//	else {
//		cout << "Funcao inexistente. Tente novamente." << endl;
//		getchar();
//	}
//}
////
////void Interface::executa_quatro(string comando, int first, string word1, int second) {
////	int third = 0;
////	if (comando == "criaf" && fase == "simulacao")
////		a.criaf(first, word1, second);
////	else if (comando == "energformiga" && fase == "simulacao") {
////		std::istringstream(word1) >> third;
////		a.add_energformiga(first, third, second);
////	}
////}
////
////void Interface::executa_cinco(string comando, string tipo, int first, int second, int third) {
////	if (comando == "cria1" && fase == "simulacao")
////		a.cria1(tipo, first, second, third);
////}
////
//void Interface::executa_comandos(string comando, string nome_fich) {
//	if (comando == "executa") { //Lê os comandos do ficheiro
//		this->le_ficheiro(nome_fich);
//		system("cls");
//	}
//	else {
//		cout << "Funcao inexistente. Tente novamente." << endl;
//		getchar();
//	}
//}
////
////void Interface::inicializa_grelha() {
////	int lim = a.getLimite();
////	for (int i = 0; i <= lim; i++) {
////		Consola::gotoxy(0, i);
////		cout << "#" << endl;
////		Consola::gotoxy(i, 0);
////		cout << "#" << endl;
////		Consola::gotoxy(i, lim + 1);
////		cout << "#" << endl;
////		Consola::gotoxy(lim + 1, i);
////		cout << "#" << endl;
////		Consola::gotoxy(lim + 1, i + 1);
////		cout << "#" << endl;
////		Consola::gotoxy(lim + 3, i + 1);
////		if (i + 1 < lim + 1)
////			cout << i + 1 << endl;
////	}
////	Consola::gotoxy(0, lim + 4);
////}
////
////string Interface::mostra_config() const {
////	ostringstream os;
////	os << "Valores das Variaveis: defmundo-" << a.getLimite() << " | defen-" << a.getEnergia() << " | defpc-" << a.getPercentagem() << " | defvt-" << a.getValortransf() << " | defmi-" << a.get_p_ini_mig() << " | defme-" << a.get_en_ini_mig() << " |defnm-" << a.get_n_max_mig() << " |" << endl;
////	return os.str();
////}
//
//string Interface::getFase() const {
//	return fase;
//}
