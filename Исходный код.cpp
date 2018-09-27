#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <clocale>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Ukrainian");
	string path = "BOOKS.DAT";

	struct books
	{
		char surname[20];
		char ini[20];
		char name[30];
		char names[30];
		int year;
	};
	
	//stopec = { "Прізвище:", "Ініціали:", "Назви книги:", "Видавницто:" }, book1 = { "Кідрук", "М.Б.", "Жорстоке небо", "Укркнига" }, book2 = { "Кідрук", "М.Б.", "Зазирни у мої сни", "Укркнига" }, book3 = { "Ковтонюк", "М.В.", "Хакєрмен", "Даркбук" };
	int f;
	cout << "Введіть кількість книг";
	cin >> f;
	struct books* books1 = new struct books [f];
	ofstream emp_file(path, ios::binary);
	int m = 0;
	for (int i = 0; i < f; i++){
		cout << "surname^ ";
		cin >> (books1 + i)->surname;
		cout << "name^ ";
		cin >> (books1 + i)->name;
		cout << "names^ ";
		cin >> (books1 + i)->names;
		cout << "ini^ ";
		cin >> (books1 + i)->ini;
		cout << "year^ ";
		cin >> (books1 + i)->year;
		if ((books1 + i)->year >= 2000){
			m++;
		}
	}
	emp_file.write((char *)&m, sizeof(m));
	for (int i = 0; i < f; i++){
		if ((books1 + i)->year >= 2000){
			emp_file.write((char *)(books1 + i), sizeof(struct books)); 
		}
	}
	emp_file.close();

	ifstream fin;
	fin.open(path, ios::binary);
	struct books *bs = new struct books[f];
	int n = 0;
	fin.read((char *)&n, sizeof(n));
	int j = 0;
	if (!fin.is_open())
	{
		cout << "Файл не знайдений" << endl;
	}
	else{
		cout << "Файл успішно відкритий" << endl;
	
		while (n){
			fin.read((char*)(bs + j), sizeof(struct books));
			n--;
			j++;
		}

	}
	for (int i = 0; i < j; i++)
	{
		cout << (bs + i)->name << "       " << (bs + i)->surname << "      " << (bs + i) ->year << endl;
	}
	fin.close();
	system("pause");
}