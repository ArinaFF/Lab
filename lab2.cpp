#include <iostream>
#include <bitset>
//����� 1. �������� ������
int main()
{
	setlocale(LC_ALL, "Russian"); // ��� �������� �� ������� ����
	short A, i, a;
	short short_b = sizeof(short) * 8; //�������� �� 8 ����� ��������� � ���. ������ short

	std::cout << " Enter A" << std::endl;
	std::cin >> A;
	std::cout << " Enter i" << std::endl;
	std::cin >> i;
	a = A; // ��� ������� ����� ��������� �������� �������� �

	if (i >= 0 && i < short_b) { //�������� i
	}

	else {
		std::cout << " �� ���������� �������� i";
		return 0;
	}


	short value_i = A & (1 << i); //����� ����� �� �������� i ���

	if (value_i == 0) {
		A = A * A;
		A = A & ~(1 << i); // ��������� i ��� ���������� � 0
		std::cout << "A = " << std::bitset<8>(a) << std::endl; //��
		std::cout << "A = " << std::bitset<8>(A) << std::endl; // �����
	}
	else {
		short a1 = 125 & 0b10101010; // ������� ������ ���� ����� 125 �� 0
		std::cout << " 125 => " << a1 << " = " << std::bitset<8>(a1) << std::endl;
		return 0;
	}

	//����� 2


	std::cout << "������� ����� �������� :"; // ������ ������������ ������ ����� ��������
	int N;
	std::cin >> N;
	switch (N) {
	case 113: // ����� �������� � ��� �������
		std::cout << " ����������� - �������";
		break;
	case 114:
		std::cout << "����������� - ������������";
		break;
	case 117:
		std::cout << "����������� - ��������";
		break;
	case 118:
		std::cout << "����������� - �����������";
		break;
	case 119:
		std::cout << "����������� - ����������";
		break;
	case 125:
		std::cout << "����������� - �������";
		break;
	case 136:
		std::cout << "����������� - ������������";
		break;
	case 141:
		std::cout << "����������� - ������������";
		break;
	case 148:
		std::cout << "����������� - �������������";
		break;
	case 161:
		std::cout << "����������� - �������";
		break;
	case 191:
		std::cout << "����������� - �������������";
		break;
	case 593:
		std::cout << "����������� - �������";
		break;
	case 802:
		std::cout << "����������� - �������";
		break;
	default: std::cout << "����������� �������"; // ����� ��� ��������� ������ ��������

	}
	return 0;


	}
