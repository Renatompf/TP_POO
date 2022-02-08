#include "DVG.h"
#include "crazy.h"
#include "rapido.h"
#include "surpresa.h"


DVG::DVG() {};

//READ FILES
void DVG::readfilePilotos(string filename) {
	ifstream file;
	string Tipo, Nome;
	pilotos* p;

	file.open(filename);
	if (file.is_open()) {
		while (!file.eof()) {
			file >> Tipo >> Nome;
			if(Tipo == "Crazy")
				p = new crazy(Tipo, Nome);
			if (Tipo == "Rapido")
				p = new rapido(Tipo, Nome);
			if (Tipo == "Surpresa")
				p = new surpresa(Tipo, Nome);
			vec_pilotos.push_back(p);
			//cout << Tipo << " " << Nome << endl;
		}
	}
	else {
		cout << "O ficheiro dos pilotos não abriu!!" << endl;
	}
	cout << "Pilotos:" << endl;
	for (int i = 0; i < vec_pilotos.size(); i++) //RETIRAR ANTES DE ENVIAR
		cout << vec_pilotos[i]->getTipo() << " " << vec_pilotos[i]->getNome() << endl;
}

void DVG::readfileCarros(string filename) {
	ifstream file;
	string label, model;
	int inicialCap, maxCap;
	carros* c;

	file.open(filename);
	if (file.is_open()) {
		while (!file.eof()) {
			file >> inicialCap >> maxCap >> label >> model;
			c = new carros(inicialCap, maxCap, label, model);
			vec_carros.push_back(c);
		}
	}
	else {
		cout << "O ficheiro dos carros não abriu!!" << endl;
	}
	cout << "Carros:" << endl;
	for (int i = 0; i < vec_carros.size(); i++) //RETIRAR ANTES DE ENVIAR
		cout << vec_carros[i]->getCap_inicial() << " " << vec_carros[i]->getCap_max()  << " " << vec_carros[i]->getMarca() << " " << vec_carros[i]->getModelo()
		<< " Id:" << vec_carros[i]->getId()<< endl;
}

void DVG::readfileAutodromo(string filename) {
	ifstream file;
	string Nome;
	int N_Carros, Comprimento;
	Autodromo* a;

	file.open(filename);
	if (file.is_open()) {
		while (!file.eof()) {
			file >> N_Carros >> Comprimento >> Nome;
			a = new Autodromo(N_Carros, Comprimento, Nome);
			vec_autodromos.push_back(a);
		}
	}
	else {
		cout << "O ficheiro dos autodromos não abriu!!" << endl;
	}
	cout << "Autodromos:" << endl;
	for (int i = 0; i < vec_autodromos.size(); i++) //RETIRAR ANTES DE ENVIAR
		cout << vec_autodromos[i]->getNcarros() << " " << vec_autodromos[i]->getDistancia() << " " << vec_autodromos[i]->getNomeA() << endl;
}

//ADDS FUNCTIONS
pilotos* DVG::addPiloto(string nome_pi, string tipo_pi) {
	pilotos* p;

	if (searchPiloto(nome_pi) == nullptr) {
		if (tipo_pi == "Crazy")
			p = new crazy(tipo_pi, nome_pi);
		if (tipo_pi == "Rapido")
			p = new rapido(tipo_pi, nome_pi);
		if (tipo_pi == "Surpresa")
			p = new surpresa(tipo_pi, nome_pi);
		if (tipo_pi == "Incerto")
			p = new incerto(tipo_pi, nome_pi);

		vec_pilotos.push_back(p);
		for (int i = 0; i < vec_pilotos.size(); i++)
			cout << vec_pilotos[i]->GetPilotoAsString() << "\n";
		return p;
	}
	return nullptr;
}

void DVG::addCarro(int inicialCap, int maxCap, string label, string model) {
	carros* c = new carros(inicialCap, maxCap, label, model);
	vec_carros.push_back(c);
	for (int i = 0; i < vec_carros.size(); i++) {
		cout << vec_carros[i]->getAsString() << endl;
		cout << "\n\n";
	}
}

void DVG::addAutodromo(int ncars, int lenght, string name) {
	Autodromo* autodrom = new Autodromo(ncars, lenght, name);
	vec_autodromos.push_back(autodrom);
}

//SEARCH FUNCTIONS
pilotos* DVG::searchPiloto(string nome_pi) const {
	for (vector <pilotos*>::const_iterator it = vec_pilotos.cbegin(); it != vec_pilotos.cend(); it++)
		if ((*it)->getNome() == nome_pi)
			return *it;
	return nullptr;
}

carros* DVG::searchCarro(char identifier) {
	for (int i = 0; i < vec_carros.size(); i++) {
		if (vec_carros[i]->getId() == identifier) {
			return vec_carros[i];
		}
	}
	return nullptr;
}

Autodromo* DVG::searchAutodromo(string name) {
	for (int i = 0; i < vec_autodromos.size(); i++) {
		if (vec_autodromos[i]->getNomeA() == name) {
			return vec_autodromos[i];
		}
	}
	return nullptr;
}

//OBTEM FUNCTIONS
int DVG::ObtemNPilotos() {
	int i = 0;
	for (i; i < vec_pilotos.size(); i++);
	return i;
}

int DVG::obtemNCarros() {
	int i = 0;
	while (i < vec_carros.size()) {
		i++;
	}
	return i;
}

//DELETE FUNCTIONS
void DVG::deleteCarro(char identifier) {
	int i = 0;

	for (i = 0; vec_carros[i]->getId() != identifier; i++);
	delete vec_carros[i];
	vec_carros.erase(vec_carros.begin() + i);
	cout << "\n\n\n";
	for (i = 0; i < vec_carros.size(); i++) { //RETIRAR ANTES DE ENVIAR
		cout << vec_carros[i]->getId() << endl;
	}
}

void DVG::deletePiloto(string name) {
	int i = 0;
	for (i = 0; vec_pilotos[i]->getNome() != name; i++);
	delete vec_pilotos[i];
	vec_pilotos.erase(vec_pilotos.begin() + i);
	cout << "\n\n\n";
	for (i = 0; i < vec_pilotos.size(); i++) {//RETIRAR ANTES DE ENVIAR
		cout << vec_pilotos[i]->getNome() << endl;
	}
}

void DVG::deleteAutodromo(string nome) {
	int i = 0;
	for (i = 0; vec_autodromos[i]->getNomeA() != nome; i++);
	delete vec_autodromos[i];
	vec_autodromos.erase(vec_autodromos.begin() + i);
	cout << "\n\n\n";
	for (i = 0; i < vec_autodromos.size(); i++) { //RETIRAR ANTES DE ENVIAR
		cout << vec_autodromos[i]->getNomeA() << endl;
	}
}

/*void DVG::addCarro(carros* c) {
	vec_carros.push_back(c);
}*/

/*void DVG::addCarro(string label) {
	carros* c = new carros (label);
	vec_carros.push_back(c);
}*/

/*void DVG::addPiloto(pilotos* p) {
	vec_pilotos.push_back(p);
}*/

void DVG::listaConteudo() {
	for (int i = 0; i < vec_pilotos.size(); i++) {
		cout << vec_pilotos[i]->GetPilotoAsString();
	}
	for (int i = 0; i < vec_carros.size(); i++) {
		cout << vec_carros[i]->getAsString();
	}
}

void DVG::emparelha(char car_id, string pilot_name) {

	carros* c = searchCarro(car_id);
	if (c != nullptr) {
		if (c->getPiloto() == nullptr) {
			pilotos* p = searchPiloto(pilot_name);
			if (p != nullptr) {
				if (p->getCarro() == nullptr) {
					p->setCarro(c);
					c->setPiloto(p);
					cout << "\nO piloto " << pilot_name << " emparelhou com o carro " << car_id << endl;
				}
				else
					cout << "\nO piloto ja tem carro\n";
			}
			else
				cout << "\nO piloto nao existe\n";
		}
		else
			cout << "\nO carro ja tem piloto\n";
	}
	else
		cout << "\nO carro nao existe\n";
}

void DVG::desemparelha(char car_id) {
	carros* c = searchCarro(car_id);
	if (c != nullptr) {
		if (c->getPiloto() != nullptr) {
			c->getPiloto()->setCarro(nullptr);
			c->setPiloto(nullptr);
			cout << "O carro " << car_id << " ficou sem piloto\n";
		}
		else
			cout << "o carro " << car_id << " nao tem piloto para desemparelhar" << endl;
	}
	else
		cout << "\nO carro " << car_id << " nao existe\n";
};

void DVG::carregaTudo() {
	for (int i = 0; i < vec_carros.size(); i++) {
		vec_carros[i]->setCap_inicial(vec_carros[i]->getCap_max());
	}
}

void DVG::carregaBat(char car_id, int energy) {
	for (int i = 0; i < vec_carros.size(); i++) {
		if (car_id == vec_carros[i]->getId()) {
			if (energy + vec_carros[i]->getCap_inicial() >= vec_carros[i]->getCap_max())
				vec_carros[i]->setCap_inicial(vec_carros[i]->getCap_max());
			else
				vec_carros[i]->setCap_inicial(vec_carros[i]->getCap_inicial() + energy);
		}
	}
}

void DVG::acidente(char car_id) {
	for (int i = 0; i < vec_carros.size(); i++) {
		if (car_id == vec_carros[i]->getId()) {
			desemparelha(car_id);
			vec_carros[i]->setEstado(1); //PQ FICA IRREPARÁVEL
		}
	}
}

void DVG::stop(string nome) {
	for (int i = 0; i < vec_pilotos.size(); i++) {
		if (nome == vec_pilotos[i]->getNome()) {
			vec_pilotos[i]->getCarro()->setAcelerador(0);
			vec_pilotos[i]->getCarro()->setTravao(1);
			vec_pilotos[i]->getCarro()->setVelocidade(0);
		}
	}
}

DVG::~DVG(){
	for (carros* c : vec_carros)
		delete c;	
	for (pilotos* p : vec_pilotos)
		delete p;
}