#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void totAverage(int number[], int i) { // �հ� �� ���
	int size = i; // ����
	int tot = 0; // �հ�

	for (i = 0; i < size; i++) {
		tot += number[i];
	}

	cout << "�հ� : " << tot << endl;
	cout << "��� : " << tot / size << endl;
}

void sortUp(int numbers[], int size) { // �������� ����
	
	for (int i = 0; i < size; i++) { // ù��° ���ں��� ���ʴ�� ��
		
		for (int j = i + 1; j < size; j++) { // �� ���� ���ں��� ���ʴ�� ��
			if (numbers[i] > numbers[j]) {
				
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
				// �� ���ڰ� �� ���ں��� ������ ��ä
			}
		}
	}
}

void sortDown(int numbers[], int size) { // �������� ����
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (numbers[i] < numbers[j]) {
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

int main() {

	int tn = 0;
	int sort = 0;


	cout << "���� : ";
	cin >> tn;

	int* arr = new int[tn]();
	int size = _msize(arr) / sizeof(int);

	if (tn == 0) {
		cout << "�߸� �Է��߽��ϴ�." << endl;
	}
	else {

		for (int a = 0; a < _msize(arr) / sizeof(int); a++) { 
			cout << a + 1 << " ��° ���� : ";
			cin >> arr[a]; // ���ʴ�� ���ڸ� �Է��ϰ�

			totAverage(arr, size); // �װſ� ���� �հ�� ����� ���ʴ�� ����

		}

		cout << "���Ĺ�� : ";
		cin >> sort;

		if (sort == 1)
		{
			sortUp(arr, tn);
			cout << "�������� ���� : ";
		}
		else if (sort == 2)
		{
			sortDown(arr, tn);
			cout << "�������� ���� : ";
		}


	}
	for (int i = 0; i < tn; i++) {
		cout << arr[i] << " ";
	}




	delete[] arr;

	return 0;
}