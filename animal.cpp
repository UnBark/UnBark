#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Animal { // �⺻ Ŭ���� : Animal
public:
	Animal () {}
	virtual void makeSound() = 0;// �����Լ� ����
	virtual ~Animal() {} // ���� �Ҹ���
};

class Dog : public Animal { // �Ļ� Ŭ���� : Dog
public:
	Dog() {} // ����
	virtual void makeSound() override { 
		cout << "�۸�" << endl;  // ���
	}
	virtual ~Dog() {} // �Ҹ�
};

class Cat : public Animal { // �Ļ� Ŭ���� : Cat
public:
	Cat() {} // ����
	virtual void makeSound() override {
		cout << "�߿�" << endl; // ���
	}
	virtual ~Cat() {} // �Ҹ�
};

class Cow : public Animal { // �Ļ� Ŭ���� : Cow
public:
	Cow() {} // ����
	virtual void makeSound() override {
		cout << "����" << endl; // ���
	}
	virtual ~Cow() {} // �Ҹ�
};

class Tiger : public Animal { // �Ļ� Ŭ���� : Cow
public:
	Tiger() {} // ����
	virtual void makeSound() override {
		cout << "����" << endl; // ���
	}
	virtual ~Tiger() {} // �Ҹ�
};

class Monkey : public Animal { // �Ļ� Ŭ���� : Cow
public:
	Monkey() {} // ����
	virtual void makeSound() override {
		cout << "�쳢��" << endl; // ���
	}
	virtual ~Monkey() {} // �Ҹ�
};


class Zoo {
private:
	Animal* animals[10]; // ���� ��ü�� �����ϴ� ������ �迭
	int number; // ������ ����

public:
	Zoo() : number(0) {}

	void addAnimal(Animal* animal) { // ���� ��ü�� zoo�� �߰��ϴ� �Լ�
		if (number >= 10) {
			cout << "������ ������!" << endl;
			return;
		}
		animals[number++] = animal;
	}

	void Sounds() { // �������� ��� ������ �Ҹ��� ����ϴ� �Լ�
		for (int i = 0; i < number; i++) {
			animals[i]->makeSound();
		}
	}

	~Zoo() {// Zoo �Ҹ���
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

	srand(time(0)); // ���� �õ� �ʱ�ȭ

	Zoo zoo1;

	for (int i = 0; i < 10; i++) { // ���� ���� ���� �� �߰�
		zoo1.addAnimal(randomAnimal());
	}

	zoo1.Sounds();// �������� �ִ� ��� �������� �Ҹ� ���

	// Zoo �Ҹ��ڰ� ���� �Ҵ�� �޸𸮸� �ڵ����� �����մϴ�.
	return 0;
	
}