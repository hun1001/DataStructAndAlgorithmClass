#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

const string FileName = "Storage.txt";

// �������δ� ��������� �̸��� �������
// �պ��� ����
class Person {
private:
	
	string _sex;
	string _birthYear;
	int _age;
	string _area;
	bool _validation;

public:
	char _rrn[14];
	Person() {
		cout << "-���� �ֹε�Ϲ�ȣ�� �Է����ּ���: ";
		cin >> _rrn;
		system("cls");
		_sex = "";
		_age = 0;
		SetSex();
		SetBirthYear();
		AreaCheck();
		_validation = ValidationTest();	
	}

	void SetSex() {
		switch (_rrn[6] - '0')
		{
		case 1:
		case 3:
			_sex = "��";
			break;
		case 2:
		case 4:
			_sex = "��";
			break;
		default:
			cout << "�߸��Է���" << endl;
			exit(-1);
			break;
		}
	}

	void SetBirthYear() {
		time_t timer = time(NULL);
		struct tm* t = localtime(&timer);

		char year[4];
		if ((_rrn[6] - '0') <= 2) {
			year[0] = '1';
			year[1] = '9';
		}
		else {
			year[0] = '2';
			year[1] = '0';
		}
		year[2] = _rrn[0];
		year[3] = _rrn[1];
		_birthYear = year;
		_age = (t->tm_year + 1900) - stoi(year) + 1;
	}

	void PrintInfo() {
		cout << "����: " << _sex << endl;
		// �� �κ� ���ٷ� �����ߴµ� ������ ���ȳ� []() -> (){} �̰ſ��� �����ٵ� ��� �ȳ���
		cout << "����⵵: " << _birthYear[0] << _birthYear[1] << _birthYear[2] << _birthYear[3] << endl;
		cout << "����: " << _age << endl;
		cout << "����: " << _area << endl;
		cout << std::boolalpha << "��ȿ��: " << _validation << endl;
	}

	void AreaCheck() {
		if ((stoi(_birthYear) >= 2020 && int(atoi(new char[2]{ _rrn[2], _rrn[3] })) >= 10)|| (stoi(_birthYear) >= 2021)) {
			_area = "�ֹι�ȣ �������� �ֹι�ȣ�Դϴ�";
			return;
		}
		int areaNum = atoi(new char[2] { _rrn[7], _rrn[8] });
		if (areaNum >= 0 && areaNum <= 8) {
			_area = "����Ư����";
		}
		else if (areaNum >= 9 && areaNum <= 12) {
			_area = "�λ걤����";
		}
		else if (areaNum >= 13 && areaNum <= 15) {
			_area = "��õ������";
		}
		else if (areaNum >= 16 && areaNum <= 25) {
			_area = "��⵵";
		}
		else if (areaNum >= 26 && areaNum <= 34) {
			_area = "������";
		}
		else if (areaNum >= 35 && areaNum <= 39) {
			_area = "��û�ϵ�";
		}
		else if (areaNum >= 40 && areaNum <= 41) {
			_area = "����������";
		}
		else if (areaNum >= 42 && areaNum <= 47 && areaNum != 44) {
			_area = "��û����";
		}
		else if (areaNum == 44 || areaNum == 96) {
			_area = "����Ư����ġ��";
		}
		else if (areaNum >= 48 && areaNum <= 54) {
			_area = "����ϵ�";
		}
		else if (areaNum >= 55 && areaNum <= 64) {
			_area = "���󳲵�";
		}
		else if (areaNum == 55 || areaNum == 56 || areaNum == 65 || areaNum == 66) {
			_area = "���ֱ�����";
		}
		else if (areaNum >= 67 && areaNum <= 69) {
			_area = "�뱸������";
		}
		else if (areaNum >= 70 && areaNum <= 81) {
			_area = "���ϵ�";
		}
		else if (areaNum >= 82 && areaNum <= 84 || areaNum >= 86 && areaNum <= 91) {
			_area = "��󳲵�";
		}
		else if (areaNum == 85 || areaNum == 90) {
			_area = "��걤����";
		}
		else if (areaNum >= 92 && areaNum <= 95) {
			_area = "����Ư����ġ��";
		}
	}

	bool ValidationTest() {
		int multipliedNumber[13] = { 2,3,4,5,6,7,8,9,2,3,4,5 };
		int temp[13];
		int sum = 0;
		for (int i = 0; i < 13; i++) {
			temp[i] = (_rrn[i] - '0') * multipliedNumber[i];
			sum += temp[i];
		}
		return (11 - (sum % 11)) % 10 == (_rrn[12] - '0');
	}
};

class FileSave {
private:
	ofstream _fout;
	ifstream _readFromFile;
	vector<string> _memory;

	void LoadMemory() {
		stringstream ss;
		_readFromFile.open(FileName);
		ss << _readFromFile.rdbuf();
		cout << ss.str();
		_readFromFile.close();
	}

public:
	FileSave() {
		_fout.open(FileName);
		LoadMemory();
	}

	void InputFile(char* c) {
		_fout << c;
	}

	~FileSave() {
		_fout.close();
	}
};


int main() {
	Person person;
	FileSave file;
	file.InputFile(person._rrn);
	person.PrintInfo();
}