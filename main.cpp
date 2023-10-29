#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
void OutputArray(double* arr, const int size, int i);
void FillArrayRandomVal(double* arr, const int size, double start, double end, int i);
int quantityOfPosElem(double* arr, const int size, int counter, int i);
double Sum_after_zero(double* arr, const int size,bool is_sum, double sum, int i);
void RewritingArray(double* array, double*& array_result, int size, int counter, int isInt, int i);
int main()
{
	srand(unsigned(time(0)));
	double start_random, end_random;
	int sum = 0, quantity = 0, n;
	cout << "n: "; cin >> n;
	cout << "start of random : "; cin >> start_random;
	cout << "end of random : "; cin >> end_random;

	double* a = new double[n];
	double* arr_result = new double[n];
	FillArrayRandomVal(a, n, start_random, end_random, 0);
	OutputArray(a, n, 0);
	cout << "quantity of positive values: " << quantityOfPosElem(a, n, 0, 0)
		<< "\nsum after zero: " << Sum_after_zero(a, n, 0, 0, 0) << endl;
	RewritingArray(a, arr_result, n, 0, 0, 0);
	OutputArray(arr_result, n, 0);
	delete[]a;

	return 0;
}
void FillArrayRandomVal(double* arr, const int size, double start, double end, int i)
{
	if (i < size)
	{
		arr[i] = start + (end - start) * ((double)rand()) / RAND_MAX;
		FillArrayRandomVal(arr, size, start, end, i + 1);

	}
}
void OutputArray(double* arr, const int size, int i)
	{

	if (i < size)
	{
		cout << setw(12) << arr[i];
		OutputArray(arr, size, i + 1);

	}
	else
	{
		cout << endl;
	}
}
int quantityOfPosElem(double* arr, const int size, int counter, int i)
{
	if (i < size)
	{
		if (arr[i] > 0.)
		{
			quantityOfPosElem(arr, size, counter + 1, i + 1);
		}
		else
		{
			quantityOfPosElem(arr, size, counter, i + 1);
		}
	}
	else
	{
		return counter;
	}
}
double Sum_after_zero(double* arr, const int size, bool is_sum, double sum, int i)
{
	if (i < size)
	{
		if (arr[i] == 0. || is_sum)
		{
			is_sum = 1;
			sum += arr[i];
		}
		Sum_after_zero(arr, size, is_sum, sum, i + 1);
	}
	else
	{
		return sum;
	}
}
void RewritingArray(double* array, double*& array_result, int size, int counter, int isInt, int i)
{
	if(i <= size)
	{
		if (i < size)
		{
			if (isInt == 0 && int(array[i]) == 0)
			{
				array_result[counter++] = array[i];
			}
			if (isInt == 1 && int(array[i]) != 0)
			{
				array_result[counter++] = array[i];
			}
			RewritingArray(array, array_result, size, counter, isInt, i + 1);
		}
		if (i == size && isInt == 0)
		{
			RewritingArray(array, array_result, size, counter, 1, 0);
		}
		if (i == size && isInt == 1)
		{
			return;
		}
	}
}
