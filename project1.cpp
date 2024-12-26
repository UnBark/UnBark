#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void totAverage(int number[], int i) { // 합계 및 평균
	int size = i; // 갯수
	int tot = 0; // 합계

	for (i = 0; i < size; i++) {
		tot += number[i];
	}

	cout << "합계 : " << tot << endl;
	cout << "평균 : " << tot / size << endl;
}

void sortUp(int numbers[], int size) { // 오름차순 정렬
	
	for (int i = 0; i < size; i++) { // 첫번째 숫자부터 차례대로 비교
		
		for (int j = i + 1; j < size; j++) { // 그 다음 숫자부터 차례대로 비교
			if (numbers[i] > numbers[j]) {
				
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
				// 앞 숫자가 뒷 숫자보다 높으면 교채
			}
		}
	}
}

void sortDown(int numbers[], int size) { // 내림차순 정렬
	
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


	cout << "갯수 : ";
	cin >> tn;

	int* arr = new int[tn]();
	int size = _msize(arr) / sizeof(int);

	if (tn == 0) {
		cout << "잘못 입력했습니다." << endl;
	}
	else {

		for (int a = 0; a < _msize(arr) / sizeof(int); a++) { 
			cout << a + 1 << " 번째 정수 : ";
			cin >> arr[a]; // 차례대로 숫자를 입력하고

			totAverage(arr, size); // 그거에 따른 합계와 평균을 차례대로 나옴

		}

		cout << "정렬방식 : ";
		cin >> sort;

		if (sort == 1)
		{
			sortUp(arr, tn);
			cout << "오름차순 정렬 : ";
		}
		else if (sort == 2)
		{
			sortDown(arr, tn);
			cout << "내림차순 정렬 : ";
		}


	}
	for (int i = 0; i < tn; i++) {
		cout << arr[i] << " ";
	}




	delete[] arr;

	return 0;
}