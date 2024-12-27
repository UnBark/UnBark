#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Animal { // 기본 클래스 : Animal
public:
	Animal () {}
	virtual void makeSound() = 0;// 가상함수 선언
	virtual ~Animal() {} // 가상 소멸자
};

class Dog : public Animal { // 파생 클래스 : Dog
public:
	Dog() {} // 생성
	virtual void makeSound() override { 
		cout << "멍멍" << endl;  // 출력
	}
	virtual ~Dog() {} // 소멸
};

class Cat : public Animal { // 파생 클래스 : Cat
public:
	Cat() {} // 생성
	virtual void makeSound() override {
		cout << "야옹" << endl; // 출력
	}
	virtual ~Cat() {} // 소멸
};

class Cow : public Animal { // 파생 클래스 : Cow
public:
	Cow() {} // 생성
	virtual void makeSound() override {
		cout << "음머" << endl; // 출력
	}
	virtual ~Cow() {} // 소멸
};

class Tiger : public Animal { // 파생 클래스 : Cow
public:
	Tiger() {} // 생성
	virtual void makeSound() override {
		cout << "어흥" << endl; // 출력
	}
	virtual ~Tiger() {} // 소멸
};

class Monkey : public Animal { // 파생 클래스 : Cow
public:
	Monkey() {} // 생성
	virtual void makeSound() override {
		cout << "우끼끼" << endl; // 출력
	}
	virtual ~Monkey() {} // 소멸
};


class Zoo {
private:
	Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
	int number; // 동물의 갯수

public:
	Zoo() : number(0) {}

	void addAnimal(Animal* animal) { // 동물 객체를 zoo에 추가하는 함수
		if (number >= 10) {
			cout << "동물이 가득참!" << endl;
			return;
		}
		animals[number++] = animal;
	}

	void Sounds() { // 동물원의 모든 동물의 소리를 출력하는 함수
		for (int i = 0; i < number; i++) {
			animals[i]->makeSound();
		}
	}

	~Zoo() {// Zoo 소멸자
		for (int i = 0; i < number; i++) {
			delete animals[i];
		}
	}
};

Animal* randomAnimal() {
	int R_n;

	R_n = rand() % 5;

	switch (R_n) {
	case 0: return new Cat;
	case 1: return new Dog;
	case 2: return new Cow;
	case 3: return new Tiger;
	case 4: return new Monkey;
	}
	return nullptr;
}


int main() {

	srand(time(0)); // 랜덤 시드 초기화

	Zoo zoo1;

	for (int i = 0; i < 10; i++) { // 동물 랜덤 생성 및 추가
		zoo1.addAnimal(randomAnimal());
	}

	zoo1.Sounds();// 동물원에 있는 모든 동물들의 소리 출력

	// Zoo 소멸자가 동적 할당된 메모리를 자동으로 해제합니다.
	return 0;
	
}