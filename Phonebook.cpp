#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

struct Phonebook {
	string from;
	string to;
	string date;
	string time;
	int duration;
};
vector <Phonebook> findFrom(vector<Phonebook> &record, int* location, string from) {
	for (int i = 0; i < record.size(); i++) {
		location = find(record[i], record[i] + record.size(), from);
		cout << i << "\t\t" << record[i].from << "\t\t" << record[i].to << "\t\t" << record[i].date << "\t\t"
			<< record[i].time << "\t\t"
			<< record[i].duration << endl;
	}
	return record;
}
vector <Phonebook> findTo(vector<Phonebook> &record, int* location, string to) {
	for (int i = 0; i < record.size(); i++) {
		location = find(record[i], record[i] + record.size(), to);
		cout << i << "\n" << record[i].from << "\t\t" << record[i].to << "\t\t" << record[i].date << "\t\t"
			<< record[i].time << "\t\t"
			<< record[i].duration << endl;
	}
	return record;
}
vector <Phonebook> addElement(vector<Phonebook> &record, string from, string to, string date, string time, int duration) {
	Phonebook t = { from, to, date, time, duration };
	record.push_back(t);
	return record;
}
vector <Phonebook> deletedElement(vector<Phonebook> &record, int del) {
	record.erase(record.begin() + del);
	return record;
}
vector <Phonebook> sortDate(vector<Phonebook> &record) {
	for (int i = 0; i < record.size() - 1; i++) {
		for (int j = 0; j < record.size() - i - 1; j++) {
			if (record[j].date > record[j + 1].date) 
				swap(record[j], record[j + 1]);
		}
	}
	return record;
}
vector <Phonebook> sortTime(vector<Phonebook> &record) {
	for (int i = 0; i < record.size() - 1; i++) {
		for (int j = 0; j < record.size() - i - 1; j++){
			if (record[i].time > record[i + 1].time) 
				swap(record[i], record[i + 1]);
		}
	}
	return record;
}
vector <Phonebook> sortDuration(vector<Phonebook> &record) {
	for (int i = 0; i < record.size() - 1; i++) {
		for (int j = 0; j < record.size() - i - 1; j++) {
			if (record[j].duration > record[j + 1].duration) 
				swap(record[j], record[j + 1]);
		}
	}
	return record;
}
	void show(vector<Phonebook> rec) {
	for (int i = 0; i < rec.size(); i++)
		cout << i << "\t\t" << rec[i].from << "\t\t" << rec[i].to << "\t\t" << rec[i].date << "\t\t" << rec[i].time << "\t\t"
		<< rec[i].duration << endl;
}
int main() {
	vector<Phonebook> record;
	addElement(record, "Vasya", "Kate", "01.03.2018", "16:34", 34);
	addElement(record, "Natalia", "Andrey", "07.09.2018", "19:05", 23);
	addElement(record, "Vova", "Gena", "02.09.2018", "13:28", 87);
	int n;
	cout << "Какой вызов вы хотите удалить ?";
	cin >> n;
	deletedElement(record, n);
	sortDate(record);
	show(record);
	sortTime(record);
	show(record);
	findFrom(record,"Natalia");
	findTo(data, "Kate");
	sortDuration(record);
	show(record);
	return 0;
}