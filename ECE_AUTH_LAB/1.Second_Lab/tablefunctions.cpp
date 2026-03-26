#include <iostream>
#include <math.h>

void swap(double &a, double &b);
double max(const double arr[], int dimension);
double min(const double arr[], int dimension);
void mysort(double arr[], int dimsnsion);
double mendian(const double arr[], int dimension);
double standdev(const double arr[], int dimension);
void display(const double arr[], int dimension);
double k_min(const double arr[], int dimension);
double k_max(const double arr[], int dimension);

using namespace std;

double max(const double arr[], int dimension)
{
    double max = arr[0];
    for (int i = 0; i < dimension; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
double min(const double arr[], int dimension)
{
    double min = arr[0];
    for (int i = 0; i < dimension; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}
void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}
void mysort(double arr[], int dimsnsion)
{
    for (int i = 0; i < dimsnsion - 1; i++)
        for (int k = 0; k < dimsnsion - i - 1; k++)
            if (arr[k + 1] < arr[k])
                swap(arr[k], arr[k + 1]);
}
double mendian(const double arr[], int dimension)
{
    double mendian_val;
    double *sorted_matrix = new double[dimension];
    for (int i = 0; i < dimension; i++)
        sorted_matrix[i] = arr[i];
    mysort(sorted_matrix, dimension);
    if (dimension % 2)
        mendian_val = sorted_matrix[(dimension - 1) / 2];
    else
        mendian_val = (sorted_matrix[(dimension) / 2] + sorted_matrix[(dimension - 2) / 2]) / 2.0f;
    return mendian_val;
}
double standdev(const double arr[], int dimension)
{
    double mendian_value = mendian(arr, dimension);
    double sum;
    for (int i = 0; i < dimension; i++)
        sum += (arr[i] - mendian_value) * (arr[i] - mendian_value);
    return sqrt((sum / dimension));
}
void display(const double arr[], int dimension)
{
    for (int i = 0; i < dimension; i++)
        cout << arr[i] << ",";
    cout << endl;
}
double k_min(const double arr[], int dimension, int k)
{
    double *sorted_matrix = new double[dimension];
    for (int i = 0; i < dimension; i++)
        sorted_matrix[i] = arr[i];
    mysort(sorted_matrix, dimension);
    return sorted_matrix[k - 1];
}
double k_max(const double arr[], int dimension, int k)
{
    double *sorted_matrix = new double[dimension];
    for (int i = 0; i < dimension; i++)
        sorted_matrix[i] = arr[i];
    mysort(sorted_matrix, dimension);
    return sorted_matrix[dimension - k];
}

int main(void)
{
    double arr[10] = {9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0};
    bool a = true, b = true;
    cout << (true && true || false) << endl;
    return 0;
}
