#include <iostream>
#include<Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int a;
	do
	{
		cout << "Введіть кількість елементів масиву(максиммум 10)";
		cin >> a;
		if (a > 10)
			cout << "Кількість елементів не повинна перевишувати 10"<<endl;
	} while (a > 10);
	int arr[9];
	int i;
	int j;
	int b;
	int exch;
	int swap;
	int poshyk;
	for (i = 0; i <= a-1; i++)
	{
		cout << "Введіть " << i + 1 << "-ий елемент масиву" << endl;
		cin >> arr[i];
	}

	cout << "Введення числа для пошуку " << endl;
	cin >> poshyk;
	cout << "Пошук перебором " << endl;
	for (i = 0; i <= a - 1; i++)
	{
		if (arr[i] == poshyk)
		{
			cout << "Елемент знайдено. Номере елемента " << i + 1 << endl;
			break;
		}
		if (i == a - 1 && arr[i] != poshyk)
			cout << "Елемент не знайдено" << endl;
	}
	
	cout << "Двійковий пошук " << endl;
	int mid;
	int index = -1;
	int left = 0, right = a - 1;	
	while (left <= right)
	{
	    mid = (left + right) / 2;
		if (arr[mid] == poshyk)
		{
			index = mid;
			break;
		}
		else if (arr[mid] < poshyk)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		
	}
	if (index != -1)
		cout << "Елемент знайдено. Номере елемента " << index + 1 << endl;
	else
		cout << "Елемент не знайдено" << endl;
	
	
	
	
	
	cout << endl;
	cout << "Сортування вибором(у порядку зменшення): " << endl;
	for (i = 0; i <= a - 1; i++)
	{
		for (j = a - 1; j > i; j--)
		{
			if (arr[j] < arr[i])
			{
				swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}

		}
	}
	for (i = 0; i <= a - 1; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;

	cout << "Сортування вставками(у порядку збільшення): " << endl;
	for (i = 0; i <= a - 1; i++)
	{
		b = i;
		exch = 0;
		swap = arr[i];
		for (j = i+1; j <= a - 1; j++)
		{
			if (arr[j] > swap)
			{
				b=j;
				swap = arr[j];
				exch=1;
			}

		}
		if (exch)
		{
			arr[b] = arr[i];
			arr[i] = swap;
		}
	}
	for (i = 0; i <= a - 1; i++)
	{
		cout << arr[i] << ", ";
	}
	return 0;

}


