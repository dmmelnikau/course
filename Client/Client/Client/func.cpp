#pragma once
#include "includes.h"

void Add_user(SOCKET c_sock) {
	char string[100];
	system("cls");
	int check_num;
	int sw = 0, buff;

	while (sw != 3) {
		cout << "Введите фамилию: ";
		cin >> string;
		send(c_sock, string, 100, 0);
		cout << "Введите имя: ";
		cin >> string;
		send(c_sock, string, 100, 0);
		cout << "Введите отчество: ";
		cin >> string;
		send(c_sock, string, 100, 0);
		recv(c_sock, string, sizeof(string), 0);
		buff = atoi(string);
		if (buff == 0) {
			cout << "Пользователь с таким именем не существует." << endl;
			sw++;
		}
		else {
			sw = 3;
		}
	}
	buff = 0;
	while (1) {
		cout << "Введите логин" << endl;
		cin >> string;
		send(c_sock, string, 100, 0);
		recv(c_sock, string, sizeof(string), 0);
		check_num = atoi(string);
		if (check_num != 0) {
			cout << "Пользователь с таким логином уже существует." << endl;
		}
		if (check_num == 0)
			break;
	}
	while (1) {
		cout << "Введите пароль" << endl;
		cin >> string;
		if (strlen(string) < 3)
			cout << "Пароль должен быть больше 3 символов." << endl;
		else {
			send(c_sock, string, 100, 0);
			break;
		}
	}
	cout << "Данные успешно записаны." << endl;
	getchar();
}


int Login_in_menu(const char* name, SOCKET c_sock) {
	int i = 0;
	char string[100];
	system("cls");
	int k;
	int sw = 0;
	cout << "Введите логин: ";
	cin >> string;
	send(c_sock, string, 100, 0);
	cout << "Введите пароль: ";
	while (1) {
		string[i] = _getch();
		if ((string[i] == 0) || (string[i] == -32))
			continue;
		if (string[i] == 13)
			break;
		if (string[i] == '\b')
		{
			cout << "\b \b";
			i--;
		}
		else
		{
			cout << '*';
			i++;
		}
	}
	string[i] = '\0';
	send(c_sock, string, 100, 0);
	recv(c_sock, string, sizeof(string), 0); //получение результата
	k = atoi(string);
	if (k == 0) {
		cout << endl << "Такого пользователя не существует. Пройдите регистрацию." << endl;
		_getch(); _getch();
		return 0;
	}
	else {
		return k;
	}
}

void Add_Expert(SOCKET c_sock) {
	system("cls");
	char string[100];
	int n;
	cout << "Введите фамилию" << endl;
	cin >> string;
	send(c_sock, string, 100, 0);
	cout << "Введите имя" << endl;
	cin >> string;
	send(c_sock, string, 100, 0);
	cout << "Введите отчество" << endl;
	cin >> string;
	send(c_sock, string, 100, 0);
	cout << "Введите номер соответствующей категории." << endl;
	cout << "1) Первая категория" << endl;
	cout << "2) Вторая категория" << endl;
	cout << "3) Третья категория" << endl;
	n = Enter_post();
	itoa(n, string, 10);
	send(c_sock, string, 100, 0);
	cout << "Данные успешно записаны." << endl;
	getchar();
}

void Edit_user(SOCKET c_sock, const char* field) {

	char string[100];
	system("cls");
	Output_user(c_sock);

	int buff = 0, k = 0, t = 0;
	char* id = new char[256];
	cout << "Введите логин пользователя, информацию о котором хотите изменить" << endl;
	cin >> id;
	send(c_sock, id, 100, 0);
	while (t != 1){
		recv(c_sock, string, sizeof(string), 0); //получение результата
		k = atoi(string);
		if (k == 1) {
			if (strcmp(field, "login") == 0) {
				char login[100];
				cout << "Введите новый логин: " << endl;
				cin >> login;
				send(c_sock, login, 100, 0);

			}
			else if (strcmp(field, "password") == 0) {
				char password[100];
				cout << "Введите новый пароль: " << endl;
				cin >> password;
				send(c_sock, password, 100, 0);
			}
			buff++;
			break;
		}
	}
	if (buff == 0) {
		cout << "Такого пользователя не найдено." << endl;
	}
	else {
		cout << "Данные успешно изменены." << endl;
	}
	getchar();
}

void Edit_expert(SOCKET c_sock, const char* field) {
	system("cls");

	int buff = 0, k = 0, t = 0, count = 0;
	char name[100];

	if (strcmp(field, "lastname") == 0) {
		cout << "Введите новую фамилию: " << endl;
		cin >> name;
		send(c_sock, name, 100, 0);
	}
	else if (strcmp(field, "firstname") == 0) {
		cout << "Введите новок имя: " << endl;
		cin >> name;
		send(c_sock, name, 100, 0);

	}
	else if (strcmp(field, "fathername") == 0) {
		cout << "Введите новое отчество: " << endl;
		cin >> name;
		send(c_sock, name, 100, 0);

	}
	else if (strcmp(field, "post") == 0) {
		cout << "Введите номер соответствующей категории." << endl;
		cout << "1) Первая категория" << endl;
		cout << "2) Вторая категория" << endl;
		cout << "3) Третья категория" << endl;
		buff = Enter_post();
		itoa(buff, name, 10);
		send(c_sock, name, 100, 0);

	}
	buff++;
	if (buff == 0) {
		cout << "Такого пользователя не найдено." << endl;
	}
	else {
		cout << "Данные успешно изменены." << endl;
	}
	getchar();
}

void Add_Name_Aims(SOCKET c_sock) {
	system("cls");
	Output_Name_Aims(c_sock);
	char name[256];
	cout << "Введите альтернативное решение" << endl;
	cin.rdbuf();
	gets_s(name);
	send(c_sock, name, 100, 0);
	cout << "Данные успешно записаны." << endl;
	getchar();
}

void Delete_Name_Aims(SOCKET c_sock) {
	system("cls");
	Output_Name_Aims(c_sock);
	char c_name[256];
	char name[256];
	cout << "Введите альтернативное решение, которое хотите удалить: " << endl;
	cin.sync();
	gets_s(name);
	send(c_sock, name, 100, 0);

	int buff;
	char buf[255];
	recv(c_sock, buf, sizeof(buf), 0);
	buff = atoi(buf);
	if (buff == 0) {
		cout << "Альтернативного решения с таким названием не найдено." << endl;
	}
	else {
		cout << "Данные успешно удалены." << endl;
	}
	getchar();
}

void Output_Name_Aims(SOCKET c_sock) {
	system("cls");
	int buff;
	char string[100];
	recv(c_sock, string, sizeof(string), 0);
	buff = atoi(string);
	cout << "Альтернативы:" << endl;
	for (int i = 0; i < buff; i++) {
		recv(c_sock, string, 100, 0);
		cout << string << endl;
	}
	//_getch(); _getch();
	getchar();
}

void Delete_user(SOCKET c_sock) {
	system("cls");
	char* login = new char[256], string[100];
	int k = 0, buff = 0;
	Output_user(c_sock);
	cout << "Введите логин пользователя, которого хотите удалить: " << endl;
	cin >> login;
	send(c_sock, login, 100, 0);
	recv(c_sock, string, sizeof(string), 0);
	buff = atoi(string);
	if (buff == 0) {
		cout << "Такого пользователя не найдено." << endl;
	}
	else {
		cout << "Данные успешно удалены." << endl;
	}
	getchar();
}

void Headtable_user() {
	cout << setw(113) << setfill('=') << "=" << endl;
	cout << "|" << setiosflags(ios::left) << setw(3) << setfill(' ') << "№";
	cout << "|" << setiosflags(ios::left) << setw(45) << setfill(' ') << "ФИО";
	cout << "|" << setiosflags(ios::left) << setw(30) << setfill(' ') << "Логин" << "|";
	cout << setiosflags(ios::left) << setw(30) << setfill(' ') << "Пароль" << "|" << endl;
	cout << setw(113) << setfill('=') << "=" << endl;
}

void Print_user(SOCKET c_sock, int n) {
	char login[100];
	char password[100];
	char lastname[100];
	char firstname[100];
	char fathername[100];
	recv(c_sock, lastname, sizeof(lastname), 0);
	recv(c_sock, firstname, sizeof(firstname), 0);
	recv(c_sock, fathername, sizeof(fathername), 0);
	recv(c_sock, login, sizeof(login), 0);
	recv(c_sock, password, sizeof(password), 0);
	cout << "|" << setiosflags(ios::left) << setw(3) << setfill(' ') << n;
	cout << "|" << setiosflags(ios::left) << setw(15) << setfill(' ') << lastname << " " << setiosflags(ios::left) << setw(15) << setfill(' ') << firstname << " " << setiosflags(ios::left) << setw(13) << setfill(' ') << fathername;
	cout << "|" << setiosflags(ios::left) << setw(30) << setfill(' ') << login;
	cout << "|" << setiosflags(ios::left) << setw(30) << setfill(' ') << password << "|" << endl;
	cout << setiosflags(ios::left) << setw(113) << setfill('-') << " " << endl;
}

void Output_user(SOCKET c_sock) {
	system("cls");
	int k;
	char string[100];
	recv(c_sock, string, sizeof(string), 0);
	k = atoi(string);
	if (k == 0) {
		cout << "Файл пуст" << endl;
	}
	else {
		Headtable_user();
		int n = 1;
		for (int i = 0; i < k; i++) {
			Print_user(c_sock, n);
			n++;
		}
	}
}

void Headtable_expert() {
	cout << setw(82) << setfill('=') << "=" << endl;
	cout << "|" << setiosflags(ios::left) << setw(3) << setfill(' ') << "Код";
	cout << "|" << setiosflags(ios::left) << setw(45) << setfill(' ') << "ФИО";
	cout << "|" << setiosflags(ios::left) << setw(30) << setfill(' ') << "Категория" << "|" << endl;
	cout << setw(82) << setfill('=') << "=" << endl;
}

void Print_expert(SOCKET c_sock) {
	char code[100];
	char post[100];
	char lastname[100];
	char firstname[100];
	char fathername[100];
	recv(c_sock, code, sizeof(code), 0);
	recv(c_sock, post, sizeof(post), 0);
	recv(c_sock, lastname, sizeof(lastname), 0);
	recv(c_sock, firstname, sizeof(firstname), 0);
	recv(c_sock, fathername, sizeof(fathername), 0);
	cout << "|" << setiosflags(ios::left) << setw(3) << setfill(' ') << code;
	cout << "|" << setiosflags(ios::left) << setw(15) << setfill(' ') << lastname << " " << setiosflags(ios::left) << setw(15) << setfill(' ') << firstname << " " << setiosflags(ios::left) << setw(13) << setfill(' ') << fathername << "|";
	cout << setiosflags(ios::left) << setw(30) << setfill(' ') << post << "|" << endl;
	cout << setiosflags(ios::left) << setw(82) << setfill('-') << " " << endl;
}
void c_Find_user(SOCKET c_sock) {
	
}

void Output_expert(SOCKET c_sock) {
	system("cls");
	int k;
	char string[100];
	recv(c_sock, string, sizeof(string), 0);
	k = atoi(string);
	if (k == 0) {
		cout << "Файл пуст" << endl;
	}
	else {
		Headtable_expert();
		int n = 1;
		for (int i = 0; i < k; i++) {
			Print_expert(c_sock);
			n++;
		}
	}
	getchar();
}

void Delete_expert(SOCKET c_sock) {
	system("cls");
	char  string[100];
	int k = 0, buff = 0, code;
	Output_expert(c_sock);
	cout << "Введите код эксперта, которого хотите удалить: " << endl;
	code = Enter_int();
	itoa(code, string, 10);
	send(c_sock, string, 100, 0);
	recv(c_sock, string, sizeof(string), 0);
	buff = atoi(string);
	if (buff == 0) {
		cout << "Такого пользователя не найдено." << endl;
	}
	else {
		cout << "Данные успешно удалены." << endl;
	}
	getchar();
}

void Set_values(SOCKET c_sock) {
	char  buf[100], name1[100], name2[100];
	int k = 0, buff = 0, count_aims, value;
	recv(c_sock, buf, sizeof(buf), 0);
	count_aims = atoi(buf);
	if (count_aims == 0){
		cout << "Альтернативы не заданы" << endl;
	}
	else {
		cout << "Введите оценки целям." << endl;
		cout << "Если 1-я альтернатива предпочтительнее 2-ой введите 1" << endl;
		cout << "Если 2-я альтернатива предпочтительнее 1-ой введите 0" << endl;
		cout << "Если 1-я и 2-я альтернативы одинаковы по значимости введите 2" << endl;
		for (int i = 0; i < count_aims; i++) {
			for (int j = i; j < count_aims; j++) {
				if (i != j) {
					recv(c_sock, name1, sizeof(buf), 0);
					recv(c_sock, name2, sizeof(buf), 0);
					cout << "Какая альтернатива предпочтительнее?" << endl;
					cout << name1 << " или " << name2 << "?" << endl;
					cout << "Введите оценку:  " << endl;
					value = Enter_value();
					itoa(value, buf, 10);
					send(c_sock, buf, 100, 0);
				}
			}
		}
		cout << "Значения записаны" << endl;
	}
	getchar();
}

void Edit_values(SOCKET c_sock) {
	char  buf[100], name1[100], name2[100];
	int k = 0, buff = 0, count_aims;
	recv(c_sock, buf, sizeof(buf), 0);
	count_aims = atoi(buf);
	if (count_aims == 0) {
		cout << "альтернативы не заданы" << endl;
	}
	else {
		int** values = new int*[count_aims];
		for (int i = 0; i < count_aims; i++) {
			values[i] = new int[count_aims];
		}

		char ch;
		int code;
		for (int i = 0; i < count_aims; i++) {
			for (int j = 0; j < count_aims; j++) {
				recv(c_sock, buf, 100, 0);
				if (strcmp(buf, "Файл пуст") == 0) {
					cout << "Файл пуст" << endl;
					_getch(); _getch();
					return;
				}
				values[i][j] = atoi(buf);
			}
		}
		cout << "Измените оценки целям." << endl;
		cout << "Если 1-я альтернатива предпочтительнее 2-ой введите 1" << endl;
		cout << "Если 2-я альтернатива предпочтительнее 1-ой введите 0" << endl;
		cout << "Если 1-я и 2-я альтернативы одинаковы по значимости введите 2" << endl;
		for (int i = 0; i < count_aims; i++) {
			for (int j = i; j < count_aims; j++) {
				if (i != j) {
					int q = 0;
					recv(c_sock, name1, sizeof(buf), 0);
					recv(c_sock, name2, sizeof(buf), 0);
					cout << name1 << " или " << name2 << ":";
					cout << values[i][j] << endl;
					cout << "Если хотите изменить оценку введите нажмите 1, если нет нажмите любую клавишу" << endl;
					while (q == 0) {
						ch = _getch();
						if ((ch == 0) || (ch == -32))
							continue;
						code = static_cast<int>(ch);
						if (code == 49) {
							cout << "Введите оценку:  " << endl;
							values[i][j] = Enter_value();
							itoa(values[i][j], buf, 10);
							send(c_sock, buf, 100, 0);
							q++;
						}
						else {
							itoa(values[i][j], buf, 10);
							send(c_sock, buf, 100, 0);
							q++;
						}
					}
				}
			}
		}
		cout << "Значения записаны" << endl;
	}
	getchar();
}

void Output_aims_and_values(SOCKET c_sock) {
	char  buf[100], name1[100], name2[100];
	int k = 0, buff = 0, count_aims;
	recv(c_sock, buf, sizeof(buf), 0);
	count_aims = atoi(buf);
	if (count_aims != 0) {
		for (int i = 0; i < count_aims; i++) {
			if (k == 1)
				break;
			for (int j = 0; j < count_aims; j++) {
				if (i != j) {
					recv(c_sock, name1, sizeof(buf), 0);
					if (strcmp(name1, "-") == 0) {
						recv(c_sock, name1, sizeof(buf), 0);
						cout << name1 << endl;
						k = 1;
						break;
					}
					else {
						recv(c_sock, name2, sizeof(buf), 0);
						cout << name1 << " или " << name2 << endl;
						cout << " Оценка:  ";
						recv(c_sock, buf, sizeof(buf), 0);
						cout << buf << endl;
					}
				}
			}
		}
	}
	else
		cout << "Альтернативы не заданы" << endl;
	getchar();
}

void Methods(SOCKET c_sock) {
	char  buf[100], name[100], res[100];
	int k = 0, buff = 0, count_aims, value;

	recv(c_sock, buf, sizeof(buf), 0);
	count_aims = atoi(buf);
	if (count_aims != 0) {
		recv(c_sock, name, sizeof(buf), 0);
		recv(c_sock, res, sizeof(buf), 0);
		if (strcmp(name, "4") == 0) {
			cout << res;
		}
		else {
			cout << "Лучшая альтернатива" << endl;
			cout << name << ": " << res << endl;
		}
	}
	else
		cout << "Альтернативы не заданы" << endl;
	getchar();
}

void Best_result(SOCKET c_sock) {
	system("cls");
	char  buf[100], name[100], res[100];
	int k = 0, buff = 0, count_aims, value;

	recv(c_sock, buf, sizeof(buf), 0);
	count_aims = atoi(buf);
	if (count_aims != 0) {
		recv(c_sock, buf, sizeof(buf), 0);
		/*if (strcmp(buf,"0")) {
		cout << "Нет записей" << endl;
		}
		else {*/
		recv(c_sock, name, sizeof(buf), 0);
		recv(c_sock, res, sizeof(buf), 0);
		cout << "Лучшая альтернатива" << endl;
		cout << name << ": " << res << endl;
		//}
	}
	else
		cout << "Цели не заданы" << endl;
	getchar();
}

void All_result(SOCKET c_sock) {
	system("cls");
	char  buf[100], name[100], res[100];
	int k = 0, buff = 0, count_aims, value, l = 0;
	vector<string> name_aims;
	recv(c_sock, buf, sizeof(buf), 0);
	count_aims = atoi(buf);
	if (count_aims != 0) {
		for (int i = 0; i < count_aims; i++) {
			recv(c_sock, name, sizeof(buf), 0);
			name_aims.push_back(name);
		}
		cout << endl;

		double** values_for_expert = new double*[count_aims];
		for (int i = 0; i < count_aims; i++) {
			values_for_expert[i] = new double[count_aims];
		}

		int count_ex;
		recv(c_sock, buf, sizeof(buf), 0);
		count_ex = atoi(buf);

		for (int i = 0; i < count_ex; i++) {
			int k;
			recv(c_sock, buf, sizeof(buf), 0);
			k = atoi(buf);
			if (k == 0) {
				recv(c_sock, buf, sizeof(buf), 0);
				k = atoi(buf);
				cout << "Эксперт " << k << endl;
				double newvalues;
				int value = 0;
				double sum = 0;
				for (int i = 0; i < count_aims; i++) {
					for (int j = 0; j < count_aims; j++) {
						recv(c_sock, buf, sizeof(buf), 0);
						values_for_expert[i][j] = atoi(buf);
					}
				}
				cout << setiosflags(ios::left) << setw(40) << setfill(' ') << " ";
				for (string a : name_aims) {
					cout << setiosflags(ios::left) << setw(40) << setfill(' ') << a;
				}
				cout << endl;
				for (int i = 0; i < count_aims; i++) {
					cout << setiosflags(ios::left) << setw(40) << setfill(' ') << name_aims[i];
					for (int j = 0; j < count_aims; j++) {
						cout << setiosflags(ios::left) << setw(40) << setfill(' ') << values_for_expert[i][j];
					}
					cout << endl;
				}
				cout << endl;
			}
			else
				l++;

		}
		if (l == count_ex) {
			cout << "Значения не заданы" << endl;
		}
		else {
			cout << "Результат альтернатив " << endl;
			for (int i = 0; i < count_aims; i++) {
				recv(c_sock, name, sizeof(buf), 0);
				recv(c_sock, res, sizeof(buf), 0);
				cout << name << ": " << res << endl;
			}
			cout << endl;
		}


	}
	else
		cout << "Альтернативы не заданы" << endl;
	getchar();
}

void My_result(SOCKET c_sock) {
	char  buf[100], name[100], res[100];
	int k = 0, buff = 0, count_aims, value;
	vector<string> name_aims;
	recv(c_sock, buf, sizeof(buf), 0);
	count_aims = atoi(buf);
	if (count_aims != 0) {
		for (int i = 0; i < count_aims; i++) {
			recv(c_sock, name, sizeof(buf), 0);
			name_aims.push_back(name);
		}
		cout << endl;

		double** values_for_expert = new double*[count_aims];
		for (int i = 0; i < count_aims; i++) {
			values_for_expert[i] = new double[count_aims];
		}
		int k;
		recv(c_sock, buf, sizeof(buf), 0);
		k = atoi(buf);
		if (k == 0) {
			recv(c_sock, buf, sizeof(buf), 0);
			k = atoi(buf);
			cout << "Эксперт " << k << endl;
			double newvalues;
			int value = 0;
			double sum = 0;
			for (int i = 0; i < count_aims; i++) {
				for (int j = 0; j < count_aims; j++) {
					recv(c_sock, buf, sizeof(buf), 0);
					values_for_expert[i][j] = atoi(buf);
				}
			}
			cout << setiosflags(ios::left) << setw(40) << setfill(' ') << " ";
			for (string a : name_aims) {
				cout << setiosflags(ios::left) << setw(40) << setfill(' ') << a;
			}
			cout << endl;
			for (int i = 0; i < count_aims; i++) {
				cout << setiosflags(ios::left) << setw(40) << setfill(' ') << name_aims[i];
				for (int j = 0; j < count_aims; j++) {
					cout << setiosflags(ios::left) << setw(40) << setfill(' ') << values_for_expert[i][j];
				}
				cout << endl;
			}
			cout << endl;

		}
		else {
			cout << "У вас нет значений" << endl;
		}

	}
	else
		cout << "Альтернативные решения не заданы" << endl;
	getchar();
}

int Enter_value() {
	int fl;
	excep ex;
	int value;
	do {
		fl = 0;
		try
		{
			cin >> value;
			if (cin.fail()) {
				fl = 1;
				throw ex;
			}
			else {
				if (value > 2 || value < 0) {
					fl = 1;
					throw ex;
				}
			}
		}
		catch (excep &ex)
		{
			cout << ex.what("Введено некорректное значение");
			cout << "\n";
			cin.clear();
			cin.ignore(5000, '\n');
		}
	} while (fl == 1);
	return value;
};

int Enter_post() {
	int fl;
	excep ex;
	int n;
	do {
		fl = 0;
		try
		{
			cin >> n;
			if (cin.fail()) {
				fl = 1;
				throw ex;
			}
			else {
				if (n > 3 || n < 1) {
					fl = 1;
					throw ex;
				}
			}
		}
		catch (excep &ex)
		{
			cout << ex.what("Введено некорректное значение");
			cout << "\n";
			cin.clear();
			cin.ignore(5000, '\n');
		}
	} while (fl == 1);
	return n;
};

int Enter_int() {
	int fl;
	excep ex;
	int n;
	do {
		fl = 0;
		try
		{
			cin >> n;
			if (cin.fail()) {
				fl = 1;
				throw ex;
			}
		}
		catch (excep &ex)
		{
			cout << ex.what("Введено некорректное значение");
			cout << "\n";
			cin.clear();
			cin.ignore(5000, '\n');
		}
	} while (fl == 1);
	return n;
};