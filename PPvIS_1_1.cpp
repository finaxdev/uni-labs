#include <iostream>
#include <string>

using namespace std;

class Product {
private:
	string Name;
	string Manufactuer;
	int Amount;
	int Coords[4];
public:
	//Конструктор по умолчанию
	Product() : Name("SomeName"), Manufactuer("AnyManufactuer"), Amount(0)
	{ }
	//Конструкторы с параметрами
	Product(string Name_, string Manufactuer_, int Amount_) : Name(Name_), Manufactuer(Manufactuer_), Amount(Amount_)
	{ }
	Product(int Amount_) : Amount(Amount_)
	{ }
	//Перегруженнные операторы
	Product operator++() {
		return Product(++Amount);
	}
	Product operator+(Product P) const {
		int A = Amount + P.Amount;
		return Product(A);
	}
	Product operator+=(Product P) {
		Name += " & " + P.Name;
		Manufactuer += " & " + P.Manufactuer;
		Amount += P.Amount;
		*Coords = *P.Coords;
		return 0;
	}
	//Прототипы методов класса
	void setName(string Name);
	string getName();
	void setManufactuer(string Manufactuer);
	string getManufactuer();
	void setAmount(int Amount);
	int getAmount();
	void setCoords(int* Coord);
	int* getCoords();
};

void Product::setName(string Name_) {
	Name = Name_;
}

string Product::getName() {
	return Name;
}

void Product::setManufactuer(string Manufactuer_) {
	Manufactuer = Manufactuer_;
}

string Product::getManufactuer() {
	return Manufactuer;
}

void Product::setAmount(int Amount_) {
	Amount = Amount_;
}

int Product::getAmount() {
	return Amount;
}

void Product::setCoords(int* Coords_) {
	for (int i = 0; i < 5; i++) Coords[i] = Coords_[i];
}

int* Product::getCoords() {
	return Coords;
}


int main() {
	setlocale(0, "");

	int arrayOfDates[4] = {0};
	int *arr = new int[4];
	string s; int var;

	Product Bread; // конструктор по умолчанию
	Product Milk("Vkusnoe", "Savushkin Produkt", 30); //конструктор с парметрами(Name, Manufactuer, Amount)
	Product Juice(Bread); //конструктор копирования
	
	// SET & GET:
	cout << "Input name: "; cin >> s; Bread.setName(s); 
	cout << "Output name: " << Bread.getName() << endl;
	cout << "Input manufactuer: "; cin >> s; Bread.setManufactuer(s); 
	cout << "Output manufactuer: " << Bread.getManufactuer() << endl;
	cout << "Imput amount of products: "; cin >> var; Bread.setAmount(var); 
	cout << "Output amount of products: " << Bread.getAmount() << endl;
	cout << "Input coordinates of geo-location to deliver: "; for (int i = 0; i < 4; i++) cin >> arrayOfDates[i]; Bread.setCoords(arrayOfDates); 
	cout << "Output coordinates: ";	arr = Bread.getCoords(); for (int i = 0; i < 4; i++) cout << arr[i] << " ";
	cout << endl;

	//Перегруженный_Оператор1
	cout << "Overloading operator prefix increment: " << endl;
	cout << "Bread Amount: " << Bread.getAmount();
	cout << " -> ";
	++Bread;
	cout << Bread.getAmount() << endl;
	// Перегруженный_Оператор2
	Product TempProduct;
	cout << "Overloading addition operator: " << endl;
	cout << "Bread Amount: " << Bread.getAmount();
	cout << ", Milk Amount: " << Milk.getAmount();
	cout << " -> ";
	TempProduct = Bread + Milk;
	cout << TempProduct.getAmount() << endl;
	// Перегруженный_Оператор3
	Product Kakao;
	cout << "Obj. Kakao: " << endl;
	cout << Kakao.getName() << ", " << Kakao.getManufactuer() << ", " << Kakao.getAmount();
	Kakao += Bread;
	cout << " -> ";
	cout << Kakao.getName() << ", " << Kakao.getManufactuer() << ", " << Kakao.getAmount();
	cout << endl << endl;
	
	system("pause");
	return 0;
}    
