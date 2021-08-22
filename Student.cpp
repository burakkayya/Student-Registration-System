#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

typedef struct ogrenciler {

	string numara;
	string adsoyad;
	string kurs;
	unsigned int vize;
	unsigned fin;
	float avr;
	string harf;
	string adres;
	string tel;
	string mail;


}ogrenciler;

void ekle(ogrenciler[], int);
void sil(ogrenciler[], int);
void guncelle(ogrenciler[], int);
void liste(ogrenciler[], int);
void menu(ogrenciler[], int);

void main() {


	int* ogrencisayisi, sayi,i;

	cout << "Enter number of students: ";
	cin >> sayi;
	struct ogrenciler* q = new struct ogrenciler[sayi];
	//ogrencisayisi = new int[sayi];

	for (i = 0; i < sayi; i++) {

		q[i].numara = "0";
		q[i].adsoyad = "";
		q[i].mail = "";
		q[i].harf = "";
		q[i].tel = "";
		q[i].adres = "";
		q[i].kurs = "";
		q[i].vize = 0;
		q[i].fin = 0;
		q[i].avr = 0;

	}

	menu(q, sayi);

	system("PAUSE");
}

void menu(ogrenciler list[], int n) {

	char secim;

	cout << endl;
	cout << "			 MENU" << endl;
	cout << endl;
	cout << "		ADD NEW STUDENT(A)"<< endl;
	cout << endl;
	cout << "		DELETE (D)        "<< endl;
	cout << endl;
	cout << "		UPDATE(U)         " << endl;
	cout << endl;
	cout << "		LIST(L)           " << endl;
	cout << endl;
	cout << "		QUIT(Q)           " << endl;
	cout << endl;

	cin >> secim;

	if (secim == 'Q' || secim == 'q') {
		cout << "QUIT" << endl;
	}
	else {
		if (secim == 'A' || secim == 'a')
			ekle(list, n);

		if (secim == 'D' || secim == 'd')
			sil(list, n);

		if (secim == 'U' || secim == 'u')
			guncelle(list, n);

		if (secim == 'L' || secim == 'l')
			liste(list, n);
	}

}

void ekle(ogrenciler list[], int n) {

	int i, sayacc = 0;

	for(i=0;i<n;i++){
		sayacc = 0;
	if (list[i].numara == "0") {
		sayacc++;
		cout << endl;
			cout << "Enter ID: ";
			cin >> list[i].numara;
			if (list[i].numara.length() > 12)
				(list[i].numara).resize(12);
			cin.ignore();

			cout << "Enter Name and Surname: ";
			getline(cin, list[i].adsoyad);
			if (list[i].numara.length() > 30)
				(list[i].adsoyad).resize(30);
			cin.ignore();

			cout << "Enter Course: ";
			getline(cin, list[i].kurs);
			cin.ignore();

			cout << "Enter Midterm: ";
			cin >> list[i].vize;
			cin.ignore();

			cout << "Enter Final: ";
			cin >> list[i].fin;
			cin.ignore();

			list[i].avr = (0.4) * (float)(list[i].vize) + (0.6) * (float)(list[i].fin);

			if (list[i].avr >= 90)
				list[i].harf = "AA";

			else if (list[i].avr >= 85)
				list[i].harf = "BB";

			else if (list[i].avr >= 75)
				list[i].harf = "CC";

			else if (list[i].avr >= 50)
				list[i].harf = "DD";

			else if (list[i].avr < 50)
				list[i].harf = "FF";


			cout << "Enter Address: ";
			getline(cin, list[i].adres);
			cin.ignore();

			cout << "Enter Phone number: ";
			getline(cin, list[i].tel);
			cin.ignore();

			cout << "Enter Mail: ";
			getline(cin, list[i].mail);
			cin.ignore();
		}
	
}
	if (sayacc == 0) {
		cout << endl;
		cout << "YOUR LIST IS FULL PLEASE GO MENU TO DELETE SOMEBODY" << endl;
		cout << endl;
	}
		menu(list, n);
}

void sil(ogrenciler list[], int n) {

	int sec, i;
	string ad, ID;
	cout << endl;
	cout << "Delete a student by ID (1)" << endl;
	cout << endl;
	cout << "Delete one ore more students by name (2): ";
	cin >> sec;

	if (sec == 1) {

		cout << "Enter th ID: ";
		cin >> ID;

		for (i = 0; i < n; i++) {

			if (list[i].numara == ID) {

				list[i].numara = "0";
				list[i].adsoyad = "";
				list[i].mail = "";
				list[i].harf = "";
				list[i].tel = "";
				list[i].adres = "";
				list[i].kurs = "";
				list[i].vize = 0;
				list[i].fin = 0;
				list[i].avr = 0;

			}

		}

	}

	if (sec == 2) {
		int j;
		cout << "Enter the Name: ";
		cin >> ad;
		string str = "";

		for (i = 0; i < n; i++) {

			str = "";

			for (j = 0; j < list[i].adsoyad.length(); j++) {
				if (list[i].adsoyad[j] != ' ') {
					str += list[i].adsoyad[j];
				}
				else
					break;
			}

			if (ad == str) {

				list[i].numara = "0";
				list[i].adsoyad = "";
				list[i].mail = "";
				list[i].harf = "";
				list[i].tel = "";
				list[i].adres = "";
				list[i].vize = 0;
				list[i].fin = 0;
				list[i].avr = 0;

			}
		}
	}
	menu(list, n);
}

void guncelle(ogrenciler list[], int n) {

	int i;
	string ID;
	cout << "Enter the ID: ";
	cin >> ID;

	for (i = 0; i < n; i++) {

		if (list[i].numara == ID) {
			cout << endl;
			cout << "Enter new ID: ";
			cin >> list[i].numara;
			cin.ignore();
			cout << "Enter new Name and Surname: ";
			getline(cin, list[i].adsoyad);
			cin.ignore();

			cout << "Enter new Course: ";
			getline(cin, list[i].kurs);
			cin.ignore();

			cout << "Enter new Midterm: ";
			cin >> list[i].vize;
			cin.ignore();

			cout << "Enter new Final: ";
			cin >> list[i].fin;
			cin.ignore();

			list[i].avr = (0.4) * (float)(list[i].vize) + (0.6) * (float)(list[i].fin);

			if (list[i].avr >= 90)
				list[i].harf = "AA";

			else if (list[i].avr >= 85)
				list[i].harf = "BB";

			else if (list[i].avr >= 75)
				list[i].harf = "CC";

			else if (list[i].avr >= 50)
				list[i].harf = "DD";

			else if (list[i].avr < 50)
				list[i].harf = "FF";

			cout << "Enter new Address: ";
			getline(cin, list[i].adres);
			cin.ignore();

			cout << "Enter new Phone number: ";
			getline(cin, list[i].tel);
			cin.ignore();

			cout << "Enter new Mail: ";
			getline(cin, list[i].mail);
			cin.ignore();
		}

	}
	cout << endl;
	menu(list, n);
}

void liste(ogrenciler list[], int n) {

	int i, sec;

	cout << "List all student informations (1)" << endl;
	cout << "List a specific student by ID (2) " << endl;
	cout << "List one or more specific students by name (3)" << endl;
	cout << "List all stduents taken given a specific course (4)" << endl;
	cout << "List letter grades of students for a course (5)" << endl;

	cin >> sec;

	if (sec == 1) {

		for (i = 0; i < n; i++) {
			if (list[i].numara != "0") {
				cout << endl;
				cout << "ID		Name Surname		Course		Midterm		Final		Average		Letter		Address			Phone			Mail " << endl;			cout << list[i].numara;
			cout << "\t";
			cout << "\t";
			
			cout << list[i].adsoyad;
			cout << "\t";
			cout << "\t";
			
			cout << list[i].kurs;
			cout << "\t";
			cout << "\t";
			
			cout << list[i].vize;
			cout << "\t";
			cout << "\t";
			
			cout << list[i].fin;
			cout << "\t";
			cout << "\t";
			
			cout << list[i].avr;
			cout << "\t";
			cout << "\t";
			
			cout << list[i].harf;
			cout << "\t";
			cout << "\t";
		
			cout << list[i].adres;
			cout << "\t";
			cout << "\t";
			
			cout << list[i].tel;
			cout << "\t";
			cout << "\t";
			
			cout << list[i].mail;
			cout << "\t";
			cout << "\t";
			cout << endl;
			cout << endl;

		}

	}
}
	if (sec == 2) {

		string ID;

		cout << "Enter the ID: ";
		cin >> ID;

		for (i = 0; i < n; i++) {

			if (ID == list[i].numara) {
				if (list[i].numara != "0") {

					cout << endl;
					cout << "ID		Name Surname		Course		Midterm		Final		Average		Letter		Address			Phone			Mail " << endl;					cout << list[i].numara;
					cout << "\t";
					cout << "\t";

					cout << list[i].adsoyad;
					cout << "\t";
					cout << "\t";

					cout << list[i].kurs;
					cout << "\t";
					cout << "\t";


					cout << list[i].vize;
					cout << "\t";
					cout << "\t";

					cout << list[i].fin;
					cout << "\t";
					cout << "\t";

					cout << list[i].avr;
					cout << "\t";
					cout << "\t";

					cout << list[i].harf;
					cout << "\t";
					cout << "\t";

					cout << list[i].adres;
					cout << "\t";
					cout << "\t";

					cout << list[i].tel;
					cout << "\t";
					cout << "\t";

					cout << list[i].mail;
					cout << "\t";
					cout << "\t";
					cout << endl;
					cout << endl;

			}

		}
	}
}
	if (sec == 3) {

		string ad, str = "";
		int j;
		cout << "Enter the Name: ";
		cin >> ad;
		for (i = 0; i < n; i++) {

			str = "";

			for (j = 0; j < ad.length(); j++) {
				if (list[i].adsoyad[j] != ' ') {
					str += list[i].adsoyad[j];
				}
				else
					break;
			}

			if (ad == str) {
				if (list[i].numara != "0") {
					cout << endl;
					cout << "ID		Name Surname		Course		Midterm		Final		Average		Letter		Address			Phone			Mail " << endl;					cout << list[i].numara;
					cout << "\t";
					cout << "\t";

					cout << list[i].adsoyad;
					cout << "\t";
					cout << "\t";

					cout << list[i].kurs;
					cout << "\t";
					cout << "\t";

					cout << list[i].vize;
					cout << "\t";
					cout << "\t";

					cout << list[i].fin;
					cout << "\t";
					cout << "\t";

					cout << list[i].avr;
					cout << "\t";
					cout << "\t";

					cout << list[i].harf;
					cout << "\t";
					cout << "\t";

					cout << list[i].adres;
					cout << "\t";
					cout << "\t";

					cout << list[i].tel;
					cout << "\t";
					cout << "\t";

					cout << list[i].mail;
					cout << "\t";
					cout << "\t";
					cout << endl;
					cout << endl;


			}
		}

	}
}
	if (sec == 4) {

		string kur;
		int j;
		cout << "Enter the Course: ";
		cin >> kur;
		for (i = 0; i < n; i++) {
			if (kur == list[i].kurs) {
				if (list[i].numara != "0") {

					cout << endl;
					cout << "ID		Name Surname		Course		Midterm		Final		Average		Letter		Address			Phone			Mail " << endl;					cout << list[i].numara;
					cout << "\t";
					cout << "\t";

					cout << list[i].adsoyad;
					cout << "\t";
					cout << "\t";

					cout << list[i].kurs;
					cout << "\t";
					cout << "\t";

					cout << list[i].vize;
					cout << "\t";
					cout << "\t";

					cout << list[i].fin;
					cout << "\t";
					cout << "\t";

					cout << list[i].avr;
					cout << "\t";
					cout << "\t";

					cout << list[i].harf;
					cout << "\t";
					cout << "\t";

					cout << list[i].adres;
					cout << "\t";
					cout << "\t";

					cout << list[i].tel;
					cout << "\t";
					cout << "\t";

					cout << list[i].mail;
					cout << "\t";
					cout << "\t";
					cout << endl;
					cout << endl;

			}
		}
	}
}

	if (sec == 5) {

		string har;

		cout << "Enter the Letter: ";
		cin >> har;

		for (i = 0; i < n; i++) {
			if (list[i].numara != "0") {
				if (har == list[i].harf) {

					cout << endl;
					cout << "ID		Name Surname		Course		Midterm		Final		Average		Letter		Address			Phone			Mail " << endl;
					cout << list[i].numara;
					cout << "\t";
					cout << "\t";

					cout << list[i].adsoyad;
					cout << "\t";
					cout << "\t";

					cout << list[i].kurs;
					cout << "\t";
					cout << "\t";

					cout << list[i].vize;
					cout << "\t";
					cout << "\t";

					cout << list[i].fin;
					cout << "\t";
					cout << "\t";

					cout << list[i].avr;
					cout << "\t";
					cout << "\t";

					cout << list[i].harf;
					cout << "\t";
					cout << "\t";

					cout << list[i].adres;
					cout << "\t";
					cout << "\t";

					cout << list[i].tel;
					cout << "\t";
					cout << "\t";

					cout << list[i].mail;
					cout << "\t";
					cout << "\t";
					cout << endl;
					cout << endl;

				}

			}
		}
	}

	menu(list, n);
}
