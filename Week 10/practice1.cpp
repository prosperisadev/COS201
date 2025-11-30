/*Create an array of integers from user input and find the max and its index,
  min and its index, sum, find if a specific number exists in the array,
  and generate a random number and add it to the array using only plain functions.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX_SIZE = 10;

int findMax(int arr[], int size) {
    if (size <= 0) return 0;
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

int findMaxIndex(int arr[], int size) {
    if (size <= 0) return -1;
    int idx = 0;
    for (int i = 1; i < size; ++i) if (arr[i] > arr[idx]) idx = i;
    return idx;
}

int findMin(int arr[], int size) {
    if (size <= 0) return 0;
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) if (arr[i] < minVal) minVal = arr[i];
    return minVal;
}

int findMinIndex(int arr[], int size) {
    if (size <= 0) return -1;
    int idx = 0;
    for (int i = 1; i < size; ++i) if (arr[i] < arr[idx]) idx = i;
    return idx;
}

int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += arr[i];
    return sum;
}

bool numberExists(int arr[], int size, int number) {
    for (int i = 0; i < size; ++i) if (arr[i] == number) return true;
    return false;
}

int addRandomNumber(int arr[], int size, int maxSize) {
    if (size >= maxSize) return size; // no space
    arr[size] = rand() % 100;
    return size + 1;
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter the number of integers you want to input (max " << MAX_SIZE << ")";
    cout << ": ";
    if (!(cin >> n) || n <= 0 || n > MAX_SIZE) {
        cout << "Invalid size.\n";
        return 0;
    }

    int arr[MAX_SIZE];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int maxVal = findMax(arr, n);
    int maxIdx = findMaxIndex(arr, n);
    int minVal = findMin(arr, n);
    int minIdx = findMinIndex(arr, n);

    cout << "Max value: " << maxVal << " at index " << maxIdx << endl;
    cout << "Min value: " << minVal << " at index " << minIdx << endl;

    int sum = calculateSum(arr, n);
    cout << "Sum of all elements: " << sum << endl;

    int searchNum;
    cout << "Enter a number to search in the array: ";
    cin >> searchNum;
    if (numberExists(arr, n, searchNum)) cout << searchNum << " exists in the array." << endl;
    else cout << searchNum << " does not exist in the array." << endl;

    n = addRandomNumber(arr, n, MAX_SIZE);
    cout << "Array after adding a random number:\n";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

