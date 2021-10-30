#include <iostream>
#include <string>
#include <vector>

class dish
{
	std::string nume;
	double pret;
public:
	dish() {};
	dish(const std::string& nume, const double& pret);
	const std::string& getNume() const;
	const double& getPret() const;
	dish(const dish& C);
	dish& operator=(const dish& C);
	friend std::ostream& operator<<(std::ostream& out, const dish& dish);
	~dish() {};
};

dish::dish(const std::string& nume, const double& pret)
{
	this->nume = nume;
	this->pret = pret;
}

const std::string& dish::getNume() const
{
	return nume;
}

const double& dish::getPret() const
{
	return pret;
}

dish::dish(const dish& C)
{
	this->nume = C.nume;
	this->pret = C.pret;
}

dish& dish::operator=(const dish& C)
{
	if (this != &C)
	{
		this->nume = C.nume;
		this->pret = C.pret;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const dish& dish)
{
	out <<dish.nume << "\t" << dish.pret << std::endl;
	return out;
}


class restaurant
{
	std::string nume;
	std::vector<dish> meniu;
public:
	restaurant() {};
	restaurant(const std::string& nume, const std::vector<dish>& meniu);
	const std::string& getNume() const;
	const std::vector<dish>& getMeniu() const;
	void adauga(dish d);
	friend std::ostream& operator<<(std::ostream& out, const restaurant& restaurant);
	~restaurant() {};
};

restaurant::restaurant(const std::string& nume, const std::vector<dish>& meniu)
{
	this->nume = nume;
	this->meniu = meniu;
}

const std::string& restaurant::getNume() const
{
	return nume;
}


const std::vector<dish>& restaurant::getMeniu() const
{	
	return meniu;
}


void restaurant::adauga(dish d)
{
	meniu.push_back(d);
}

std::ostream& operator<<(std::ostream& out, const restaurant& restaurant)
{
	out << "RESTAURANT " << restaurant.nume;
	return out;
}

class user
{
	std::string username;
	std::string nume;
	std::string prenume;

public:
	user() {};
	user(const std::string& username, const std::string& nume, const std::string& prenume);
	const std::string& getUsername() const;
	const std::string& getNume() const;
	const std::string& getPrenume() const;
	void deconnect();
	friend std::ostream& operator<<(std::ostream& out, const user& user);
	~user() {};
};

user::user(const std::string& username, const std::string& nume, const std::string& prenume)
{
	this->username = username;
	this->nume = nume;
	this->prenume = prenume;
}

const std::string& user::getUsername() const
{
	return username;
}

const std::string& user::getNume() const
{
	return nume;
}

const std::string& user::getPrenume() const
{
	return prenume;
}

void user::deconnect()
{
	std::cout << "\nUtilizatorul " << username << " s-a deconectat.\n" << std::endl;
	std::cout << "-------------------------///-----------------------------\n" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const user& user)
{
	out << "\nS-a conectat utilizatorul " << user.username << " (" << user.prenume << " " << user.nume << ")" << std::endl;
	return out;
}

class comanda
{
	int nr_comanda;
	restaurant res;
	user u;
public:
	comanda(const int& nr_com, const restaurant& res, const user& u);
	void afiseaza_meniu();
	void adauga_comanda(const dish &d);
	//DE FACUT !!! PRET TOTAL COMANDA !!!
	friend std::ostream& operator<<(std::ostream& out, comanda& comanda);
	~comanda() {};
};


comanda::comanda(const int& nr_com, const restaurant& res, const user& u)
{
	nr_comanda = nr_com;
	this->res = res;
	this->u = u;
}

void comanda::afiseaza_meniu()
{
	
	std::cout << "\n" << u.getUsername() << " a selectat Restaurantul " << res.getNume() << "\n\n    MENIU" << std::endl;
	for (dish d : res.getMeniu())
		std::cout << d;
}

void comanda::adauga_comanda(const dish& d)
{
	std::cout << "\n" << u.getUsername() << " a adaugat in lista " << d.getNume() <<".";
}

std::ostream& operator<<(std::ostream& out, comanda& comanda)
{
	out << "\nComanda " << comanda.nr_comanda <<  " a fost plasata." << std::endl;
	return out;
}

int main()
{
	dish d1{ "Pizza", 21.5 }, d2{ "Paste", 24.0 };

	restaurant r1{ "Ceva", {d1} };
	restaurant r2{ "La Maria", {d1,d2} };

	r1.adauga({ d2 });
	r2.adauga({ "Fasole cu ciolan", 35.5 });

	std::vector<restaurant> restaurante;

	restaurante.push_back(r1);
	restaurante.push_back(r2);

	std::cout << "---Lista restaurante---" << std::endl;

	for (auto i = restaurante.begin(); i != restaurante.end(); i++)
	{
		std::cout << (*i) << std::endl;
	}

	std::cout << "-----------------------" << std::endl;

	user u1{ "test", "Vasile", "Ion" };
	std::cout << u1;

	comanda c1{123, r2, u1};

	c1.afiseaza_meniu();
	c1.adauga_comanda(d2);
	c1.adauga_comanda({ "Fasole cu ciolan", 35.5 });
	std::cout << c1;

	u1.deconnect();

	user u2{ "testulet", "Mircea", "Marin" };
	std::cout << u2;

	comanda c2{ 321, r1, u2 };

	c2.afiseaza_meniu();
	c2.adauga_comanda(d1);
	std::cout << c2;

	u2.deconnect();

	return 0;
}


