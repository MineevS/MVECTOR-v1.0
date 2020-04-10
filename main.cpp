//Вызов операций.

#include "MyVector.h"

int main(int argc, char** argv)
{	//+
	MyVector Vector1;  // вызовется конструктор без параметров
	//+
	MyVector Vector2(10, 0.0); //вызовется конструктор с параметром //Создаем вектор на '10' элементов со значением "0.0d"
	//+
	MyVector Vector3(Vector1), Vector4 = Vector2; // в обоих случаях вызовется конструктор копирования
	//+
	MyVector Vector5, Vector6;
	//+
	Vector5 = Vector6;
	//+
	cout << Vector2.capacity() << endl;
	//+
	cout << Vector2.size() << endl;
	//+
	cout << Vector2.loadFactor() << endl;
	//+
	cout << Vector2[5] << endl;
	//+
	Vector2.pushBack(6);
	//+
	Vector2.insert(4, Vector3);
	//+
	Vector2.insert(6, 7);
	//+
	Vector2.popBack();
	//+
	Vector2.erase(2);
	//+
	Vector2.erase(2, 3);
	//+
	Vector2.find(4, true);
	//+
	Vector2.reserve(10);
	//+
	Vector2.resize(4, 5);
	//+
	Vector2.capacity();
	//+
	Vector2.Show_ResizeStrategy();
	//+
	Vector2.clear();
	
	return 0;
}