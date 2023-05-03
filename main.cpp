#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <numeric>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    /* Проверка ввода данных (справочно)
    while(true)
    {
        float value; // попробуйте разные типы данных
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
            std::cout << value << '\n';
    }

    return 0;
     */
    std::string inputNum;
    std::string checkNum;
    int i,j,k;
    int bullsNum;
    int cowsNum;
    int bulls[5] {0};

    while (true) {
        std::cout<< "Введите задуманное число: ";
        std::cin>>checkNum;

        cowsNum=0;
        bullsNum=0;

        //annul "bulls"
        for (i=1;i<5;i++) {
            bulls[i]=-1;
        }
        //annul "bulls"

        if (checkNum.length()!=4
                || checkNum[0] < '0' || checkNum[0] > '9'
                || checkNum[1] < '0' || checkNum[1] > '9'
                || checkNum[2] < '0' || checkNum[2] > '9'
                || checkNum[3] < '0' || checkNum[3] > '9'
                || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка ввода данных\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            while (true) {
                std::cout<< "Введите число угадывающего: ";
                std::cin>>inputNum;

                if (inputNum.length()!=4
                    || inputNum[0] < '0' || inputNum[0] > '9'
                    || inputNum[1] < '0' || inputNum[1] > '9'
                    || inputNum[2] < '0' || inputNum[2] > '9'
                    || inputNum[3] < '0' || inputNum[3] > '9'
                    || std::cin.fail() || std::cin.peek() != '\n') {
                    std::cerr << "Ошибка ввода данных\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    bullsNum=0;
                    // check & count & mind "Bulls"
                    for (i=0;i<4;i++) {
                        if (inputNum[i]==checkNum[i]) { // check "bulls"
                            bullsNum++;//count "bulls"
                            bulls[bullsNum]=checkNum[i]; // mind "bulls"
                        }
                    }
                    for (i=0;i<4;i++) {
                        for (j=0;j<4;j++) {
                            if (inputNum[i]==checkNum[j] && i!=j
                                    && inputNum[i]!=bulls[1]
                                    && inputNum[i]!=bulls[2]
                                    && inputNum[i]!=bulls[3]
                                    && inputNum[i]!=bulls[4]) { //if "cows" value equals some "bulls" value, we ignore this "cow"
                                cowsNum++;
                            }

                        }
                    }


                    // check & count & mind "Bulls"
                }
                std::cout<<cowsNum<<" cows "<<bullsNum<<" bulls\n";
                if (bullsNum==4) {
                    std::cout<<"Число угадано!\n";
                    break;
                }
            }

        }



    }

}