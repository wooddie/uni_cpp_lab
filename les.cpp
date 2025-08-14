#include <iostream>
 
int main()
{
	
    int value = 45;
    int *ptr = &value; // объявляем указатель и инициализируем его адресом переменной value
    ptr = &value; // присваиваем адрес value для ptr

    return 0;
}