#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &numbers)
{
    int n = numbers.size();
    for (int j = 1; j < n; j++)
    {
        int key = numbers[j];
        int i = j - 1;
        while (i >= 0 && numbers[i] > key)
        {
            numbers[i + 1] = numbers[i];
            i--;
        }
        numbers[i + 1] = key;
    }
}
clock_t before = clock();

int main()
{
    clock_t before = clock();

    ifstream in("100000.txt");
    vector<int> numbers;
    int num;
    while (in >> num)
    {
        numbers.push_back(num);
    }
    in.close();
    InsertionSort(numbers);
    cout << endl;
    clock_t duration = clock() - before;
    cout << "Duration: " << (double)duration / CLOCKS_PER_SEC << " seconds";
    return 0;
}
