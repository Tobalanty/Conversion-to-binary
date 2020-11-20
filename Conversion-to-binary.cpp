#include <iostream>

int inputInteger() {                                                                    //Ввод

    std::cout << "Input an integer (0 -- 255): ";                                     
    int a;
    std::cin >> a;

    return a;
}

bool conversion(int a) {                                                                //Возвращаю 1 или 0 в зависимости от результата деления

    return !(a % 2 == 0);
}

int main()
{

    int a = inputInteger();
    bool binary[8];

    std::cout << "\n";

    for (int i = 0; i < 8 ; ++i) {                                                     //Записываю в массив значение каждого бита
        binary[i] = conversion(a);
        a = a / 2;
    }


    for (int i = 1; i < 9; ++i) {                                                       //Вывожу массив с конца и ставлю пробел после каждого 4-го бита
        std::cout << binary[7-(i-1)];
        if (i % 4 == 0)  {
            std::cout << " ";
        }
    }

    system("pause");
    return 0;
}