// Smit Lila
// Class (CECS 325-02)
// Project Name (Prog 5 - Threads)
// Due Date (11/02/2023)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <string>
#include <thread> 
#include <iostream>
#include <fstream>
using namespace std;


int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
 
void countSort(int arr[], int n, int exp)
{
 
    int output[n];
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
 
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void merge(int *a1, int a1_size, int *a2, int a2_size){
    
    int result[a1_size + a2_size];
    int i=0, j=0, k=0;

    while(i < a1_size && j < a2_size)
    {
        if(a1[i] < a2[j])
        {
            result[k] = a1[i];
            i++;
        }
        else
        {
            result[k] = a2[j];
            j++;
        }
        k++;
    }
    
    while (i < a1_size) {
        result[k] = a1[i];
        i++;
        k++;
    }

    while (j < a2_size) {
        result[k] = a2[j];
        j++;
        k++;
    }

    for (i = 0; i < k; i++) {
        a1[i] = result[i];
    }

}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Please provide input and output filenames.\n";
        cout << "Example: ./mysort numbers.dat mysort.out\n";
        
        exit(EXIT_SUCCESS);
    }

    const int MAX = 1000000;
    ofstream fout;
    ifstream fin;
    int n;
    int arr[MAX];

    fin.open(argv[1]);

    int index = 0;
    while (fin >> n)
    {
        arr[index++] = n;
    }

    int *th1 = arr;
    int *th2 = arr + 125000;
    int *th3 = arr + 250000;
    int *th4 = arr + 375000;
    int *th5 = arr + 500000;
    int *th6 = arr + 625000;
    int *th7 = arr + 750000;
    int *th8 = arr + 875000;
    
    thread thread1(radixSort, &arr[0], 125000);
    thread thread2(radixSort, &arr[125000], 125000);
    thread thread3(radixSort, &arr[250000], 125000);
    thread thread4(radixSort, &arr[375000], 125000);
    thread thread5(radixSort, &arr[500000], 125000);
    thread thread6(radixSort, &arr[625000], 125000);
    thread thread7(radixSort, &arr[750000], 125000);
    thread thread8(radixSort, &arr[875000], 125000);
    
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();

    merge(arr, 125000, arr+125000, 125000);
    merge(arr + 250000, 125000, arr+375000, 125000);
    merge(arr + 500000, 125000, arr+625000, 125000);
    merge(arr + 750000, 125000, arr+875000, 125000);

    merge(arr, 250000, arr+250000, 250000);
    merge(arr+500000, 250000, arr+750000, 250000);

    merge(arr, 500000, arr+500000, 500000);
    
    for (int i = 0; i < MAX; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

