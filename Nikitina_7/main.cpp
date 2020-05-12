#include <iostream>
using namespace std;

void read_mas(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] = ";
		cin >> mas[i];
	}
}

void random_mas(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 10;
	}
}

void write_mas(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}

int count_even(int* mas, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] % 2 == 0)
		{
			count++;
		}
	}
	return count;
}

int count_neven(int* mas, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] % 2 != 0)
		{
			count++;
		}
	}
	return count;
}

void get_stats(int* mas, int size, int& even, int& neven)
{
	even = count_even(mas, size);
	neven = count_neven(mas, size);
}

void remove_non_repeated(int** mas, int& size)
{
	int index = 0;
	int* src = *mas; //исходный массив
	int k = 0; //количество удалённых элементов
	for (; index < size; index++)
	{
		bool repeats = false;
		for (int i = 0; i < size; i++)
		{
			if (i != index && src[i] == src[index])
			{
				repeats = true;
			}
		}
		
		src[index - k] = src[index];

		if (!repeats)
		{
			k++;
		}
	}

	size = size - k; //меняем размер

	int* dest = new int[size]; //новый массив
	index = 0;
	for (; index < size; index++)
	{
		dest[index] = src[index];
	}
	*mas = dest; //пересохраняем массив
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Автор: Никитина Дарья Сергеевна\n";
	cout << "Программа для работы с массивом с помощью функций\n";

	int n = 8;
	int* mas = new int[n]{27, 3, 91, 12, 3, 41, 19, 3};

	int t = 0;
	cout << "Хотите заполнить массив самостоятельно (1)?: ";
	cin >> t;

	cout << "Введите размер массива: ";
	cin >> n;
	
	if (t == 1)
	{		
		mas = new int[n];
		read_mas(mas, n);
	}
	else
	{
		random_mas(mas, n);
	}

	cout << "Вы работаете с массивом: ";
	write_mas(mas, n);

	int even = 0, neven = 0;
	get_stats(mas, n, even, neven);

	cout << "В этом массиве: " << even << " чётных и " << neven << " нечётных элементов.\n";

	remove_non_repeated(&mas, n);

	cout << "Массив после удаления неповторяющихся: ";
	write_mas(mas, n);
	cout << "В массиве осталось " << n << " элементов\n";

	system("pause");
	return 0;
}
