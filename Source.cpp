#include "String.h"

int main()
{
	setlocale(LC_ALL, "rus");
	String str1, str2;
	int choise = 0, index = 0;
	char symbol;
	enum MENU {
		EXIT = 0,
		SIN_STR,
		PRINT,
		COUNT_STRING,
		COUT_INDEX,
		FIND_SYMBOL
	};

	cout << "1 - ���� ����� ������\n2 - �����\n3 - ����� ���-�� �����\n4 - ����� ������� �� ������� �� 1 ������\n0 - �����\n";

	do
	{
		cin >> choise;

		switch (choise)
		{
		case SIN_STR:
			cin.ignore();
			cout << "������� ������: ";
			cin >> str1;
			cout << "������� ������ ������: ";
			cin >> str2;
			break;
		case PRINT:
			str1.print();
			str2.print();
			break;
		case COUNT_STRING:
			printf("���-�� �����: %d\n", str1.get_count());
			break;
		case COUT_INDEX:
			cout << "������� ������: ";
			cin >> index;
			cout << str1[index] << "\n";
			break;
		case FIND_SYMBOL:
			cout << "������� ������\n";
			cin >> symbol;
			cout << str2(symbol) << "\n";
			break;
		case EXIT:
			break;
		}

	} while (choise != 0);

	return 0;
}
