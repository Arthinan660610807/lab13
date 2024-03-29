#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double arr[], int size, double result[]) {
    if (size <= 0) {
        cerr << "Invalid array size." << endl;
        return;
    }


    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    result[0] = sum / size;

   
    double mean = result[0];
    double sumSquaredDiff = 0.0;
    for (int i = 0; i < size; ++i) {
        sumSquaredDiff += pow(arr[i] - mean, 2);
    }
    result[1] = sqrt(sumSquaredDiff / size);

   
    double product = 1.0;
    for (int i = 0; i < size; ++i) {
        product *= arr[i];
    }
    result[2] = pow(product, 1.0 / size);

  
    double reciprocalSum = 0.0;
    for (int i = 0; i < size; ++i) {
        reciprocalSum += 1.0 / arr[i];
    }
    result[3] = size / reciprocalSum;

   
    double max = arr[0];
    double min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    result[4] = max;
    result[5] = min;
}
