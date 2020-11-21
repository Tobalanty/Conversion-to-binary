#include <iostream>

const int n{ 64 };

int inputInteger() {                                                                    //Ввод

    std::cout << "Input a "<< n << "-bit integer : ";                                     
    int a;
    std::cin >> a;

    return a;
}

bool conversionForPositive(int a) {                                                      //Возвращаю 1 или 0 в зависимости от результата выполнения функции

    return !(a % 2 == 0);
}

void output(int a) {

    bool binary[n];

    if (a > 0) {
        for (int i = 0; i < n; ++i) {                                                     //Записываю в массив значение каждого бита
            binary[i] = conversionForPositive(a);
            a /= 2;
        }

        for (int i = 1; i < n + 1; ++i) {                                                 //Вывожу массив с конца и ставлю пробел после каждого 4-го бита
            std::cout << binary[n - i];
            if (i % 4 == 0) {
                std::cout << " ";
            }
        }
    }
    else
        if (a == 0) {                                                                     //Если введён 0, то вывожу бинарный 0
            for (int i = 1; i < n + 1; ++i) {
                std::cout << "0";
                if (i % 4 == 0) {
                    std::cout << " ";
                }
            }
        }
        else
            if (a < 0) {                                                                  //Если число отрицательное, то использую метод "two's complement"
                a *= (-1);
                for (int i = 0; i < n; ++i) {                                             //Записываю в массив значение каждого бита (инвертированно) 
                    binary[i] = !(conversionForPositive(a));
                    a /= 2;                                                               //Делю на 2 для следующей итерации
                }

                if (binary[0] == false) {                                                 //Добавляю единицу к получившемуся двочиному числу
                    binary[0] = true;
                }
                else {
                        for (int i = 0; i < n; ++i) {

                            if (binary[i] == true) {
                            binary[i] = false;
                            }
                            else {
                                binary[i] = true;
                                break;
                            }

                        }
                }

                for (int i = 1; i < n + 1; ++i) {                                          //Вывожу полученное двочиное число и ставлю пробел после каждого 4-го бита
                    std::cout << binary[n - i];
                    if (i % 4 == 0) {
                        std::cout << " ";
                    }
                }
            }
}

int main()
{


    long long a = inputInteger();
    

   /*if (!isdigit(a)) {
        std::cout << "The entered value isn't a number\n";                        
        return 1;
    }*/

    std::cout << "\n";

    std::cout << "Your number in binary: ";
    output(a);
    std::cout << "\n";

    system("pause");
    return 0;
}