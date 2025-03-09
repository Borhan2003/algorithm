#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100000;
int heap[MAX_SIZE], SIZE = 0;

void insert(int x)
{
    heap[++SIZE] = x;
    int n = SIZE;
    while (n > 1 && heap[n / 2] < heap[n])
    {
        swap(heap[n / 2], heap[n]);
        n /= 2;
    }
}

void Delete()
{
    if (SIZE == 0)
        return;
    swap(heap[1], heap[SIZE]);
    SIZE--;
    int i = 1;
    while (2 * i <= SIZE)
    {
        int largest = i;
        if (heap[2 * i] > heap[largest])
            largest = 2 * i;
        if (2 * i + 1 <= SIZE && heap[2 * i + 1] > heap[largest])
            largest = 2 * i + 1;
        if (largest == i)
            break;
        swap(heap[i], heap[largest]);
        i = largest;
    }
}

void HeapSort(vector<int> &numbers)
{
    SIZE = 0;
    for (int num : numbers)
    {
        insert(num);
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = heap[1];
        Delete();
    }
}

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

    HeapSort(numbers);

    cout << endl;
    clock_t duration = clock() - before;
    cout << "Duration: " << (double)duration / CLOCKS_PER_SEC << " seconds";
    return 0;
}
