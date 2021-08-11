#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

// Здравствуйте, это вообще моя первая работа с хэшем и Open SSL, приложил все усилия, что оно работало



int printB( int *B)
{
    for (int i = 0; i < 8; i++)
        std::cout << B[i];

    return 0;
}

int comparison(unsigned char *A, unsigned char *B) //Собственно сравнение хэшей чтобы найти нужный, просто пробегаемся по всему массиву
{
    int T = 1;
    for (int i = 0; i < 16; i++)
    {
        if (A[i] != B[i])
            T = 0;
    }
    return T;
}

int initialization( char *A, unsigned char *md5digest) //Инициализация, вынес, чтобы не повторяться
{
    MD5_CTX md5handler;

    MD5_Init(&md5handler);
    MD5_Update(&md5handler, A, 8);
    MD5_Final(md5digest, &md5handler);
    return 0;
}

using namespace std;

int main()
{
    MD5_CTX md5handler;
    unsigned char md5digest1[MD5_DIGEST_LENGTH];
    unsigned char md5digest2[MD5_DIGEST_LENGTH];
    int c1;
    int a, b, c, d, e, f, g, h, T;
    int B[8];
    char A1[8], B1[8];

    std::cout << "Do you want to enter number, or char?\n For number - 1, for char - 0\n";
    std::cin >> T;
    
    if (T == 1)
    {
        for (int i = 0; i<8; i++)
        { 
            std::cout << "You should enter the ASCII number of symbol in cash to get right information\n"; //Чтобы программа работала корректно, необходимо ввести номера ASCII-символов. 
            std::cout << "Enter " << i+1 << " number\n";                                                  // Например, у восьми единиц будет следующая комбинация: 138 254 248 109 227 176 239 241 222 215 89 26 165 255 39 105
            std::cin >> a;
            A1[i] = a;
        }

        initialization(A1, md5digest1);
    }

    if (T == 0)
    {
        for (int i = 0; i < 16; i++)
        {
            std::cout << "Enter " << i + 1 << " element\n"; //Если выбрали этот режим - введите число, затем программа закеширует его, сравнит с кэшами других чисел и определит какое число было введено
            std::cin >> c1;
            md5digest1[i] = c1;
        }
    }

        for (a = 0; a < 10; a++) //Пробегаемся от 00000000 до 99999999, хэшируем и сравниваем
        {
            B[0] = a;
            B1[0] = a;
            for (b = 0; b < 10; b++)
            {
                B[1] = b;
                B1[1] = b;
                for (c = 0; c < 10; c++)
                {
                    B[2] = c;
                    B1[2] = c;
                    for (d = 0; d < 10; d++)
                    {
                        B[3] = d;
                        B1[3] = d;
                        for (e = 0; e < 10; e++)
                        {
                            B[4] = e;
                            B1[4] = e;
                            for (f = 0; f < 10; f++)
                            {
                                B[5] = f;
                                B1[5] = f;
                                for (g = 0; g < 10; g++)
                                {
                                    B[6] = g;
                                    B1[6] = g;
                                    for (h = 0; h < 10; h++)
                                    {
                                        B[7] = h;
                                        B1[7] = h;
                                        initialization(B1, md5digest2);
                                        T = comparison(md5digest1, md5digest2);
                                        if (T == 1)
                                        {
                                            std::cout << "Here are your number:\n";
                                            printB(B);
                                            printf("\n");
                                            return 0;
                                        }
                                            
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
    
    

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
