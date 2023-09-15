#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

bool isPrime(int number)	// Функція, що перевіряє число на простоту
{
	if (number % 2 == 0 || number <= 1)
	{
		return false;
	}
	for (int i = 3; i <= ceil(sqrt(number)); i += 2)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

int toSevenDig(int number)	// Функція для переведення натурального десяткового числа в 7-ву систему числення
{
	int remain, result = 0, multiplier = 1;
	while (number != 0)
	{
		remain = number % 7;
		result += remain * multiplier;
		multiplier *= 10;
		number = floor( number / 7);
	}
	return result;
}

int toDecimal(int number)	// Функція для переведення числа з 7-ої системи числення у десяткову
{
	int power = 0, result = 0;
	while (floor(number / pow(10, power)) != 0)
	{
		power++;
	}
	while (power >= 0)
	{
		result += (floor(number / pow(10, power - 1)) - floor(number / pow(10, power)) * 10) * pow(7, power - 1);
		power--;
	}
	return result;
}

int maxNumFunc(int N, int maxi = -1)	// Рекурсивна функція для знаходження максимальної цифри числа
{
	int Num = N % 10;
	if (Num > maxi)
	{
		maxi = Num;
	}
	if (N > 9)
	{
		return maxNumFunc(floor(N / 10), maxi);
	}
	return maxi;
}

int main()
{
	int taskNum;
	while (true)
	{
		cout << "Enter the task number(or '0' to exit): ";	// Алгоритм вибору завдання
		cin >> taskNum;

		if (taskNum == 0)	// Вихід з програми
		{
			return 0;
		}

		else if (taskNum == 1)	// 1 завдання
		{
			int reqOrder[4]{ 24, 37, 46, 111 }, reqNum[4], primeNum = 1, Num, reqOrderNum = 0;

			cout << "First task will be solved by using 2 different algorithms.\n\n";

			clock_t startTime = clock();	// Початок заміру часу

			for (int i = 0; i <= 10000; i++)	// Для порівння часу виконання двох алгоритмів їх буде активовано по 10000 разів
			{
				for (Num = 3; primeNum <= 111; Num++)	// Перший алгоритм через функцію перевірки простоти
				{
					if (isPrime(Num) == 1)
					{
						primeNum++;
						if (primeNum == reqOrder[reqOrderNum])
						{
							reqNum[reqOrderNum] = Num;
							reqOrderNum++;
						}
					}
				}
			}

			clock_t endTime = clock();	// Кінець заміру часу
			double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;

			cout << "First algorithm was completed for 10000 times in " << seconds << " seconds and got such results:\n";
			cout << "24th prime number would be " << reqNum[0] << ", 37th - " << reqNum[1] << ", 46th - " << reqNum[2] << " and 111th - " << reqNum[3] << ".\n\n";

			int N = 1000;
			bool* sieve = new bool[N + 1];
			primeNum = 0;
			reqOrderNum = 0;

			startTime = clock();	// Початок заміру часу

			for (int i = 0; i <= 10000; i++)
			{
				sieve[0] = false;	// Другий алгоритм через Решето Ератосфена
				sieve[1] = false;

				for (Num = 2; Num <= N; Num++)
				{
					if (sieve[Num] != false)
					{
						sieve[Num] = true;
						for (int j = Num * Num; j <= N; j += Num)
						{
							sieve[j] = false;
						}
						primeNum++;
						if (primeNum == reqOrder[reqOrderNum])
						{
							reqNum[reqOrderNum] = Num;
							reqOrderNum++;
						}
					}
				}
				
			}

			endTime = clock();	// Кінець заміру часу
			seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;

			cout << "Second algorithm was completed for 10000 times in " << seconds << " seconds and got such results:\n";
			cout << "24th prime number would be " << reqNum[0] << ", 37th - " << reqNum[1] << ", 46th - " << reqNum[2] << " and 111th - " << reqNum[3] << ".\n\n";
		}
		else if (taskNum == 2)	// 2 завдання
		{
			int Num, NumInSeven, NumInTen;
			while (true)
			{
				cout << "Enter the natural number to test the functions of converting to the seven-digit system and vice versa: ";
				cin >> Num;
				if (Num >= 1)
				{
					break;
				}
				else
				{
					cout << "You've entered the wrong value. Try again.\n";
				}
			}
			NumInSeven = toSevenDig(Num);	// Застосування функцій переведення в інші системи числення
			NumInTen = toDecimal(toSevenDig(Num));
			cout << "\nIn seven-digit system the number " << Num << " will look like " << NumInSeven << " and if you\n";
			cout << "use second function, the seven-digit number will have value " << NumInTen << ".\n\n";
		}
		else if (taskNum == 3)	// 3 завдання
		{
			int Num, maxNum;
			while (true)	// Тут застосовано єдиний цикл тільки для того, щоб впевнитись, що користувач ввів саме натуральне число
			{
				cout << "Enter the natural number: ";
				cin >> Num;
				if (Num >= 1)
				{
					break;
				}
				else
				{
					cout << "You have entered the wrong value. Try again.\n";
				}
			}
			maxNum = maxNumFunc(Num);	// Застосування рекурсивної функції
			cout << "The maximum number of N = " << Num << " would be " << maxNum << ".\n\n";
		}
		else
		{
		cout << "Task with such number doesn't exist.\n\n";	// Якщо вибрано номер неіснуючого завдання
		}
	}
}
