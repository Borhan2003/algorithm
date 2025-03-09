#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &numbers, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = numbers[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = numbers[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            numbers[k++] = L[i++];
        else
            numbers[k++] = R[j++];
    }

    while (i < n1)
        numbers[k++] = L[i++];
    while (j < n2)
        numbers[k++] = R[j++];
}

void MergeSort(vector<int> &numbers, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(numbers, left, mid);
        MergeSort(numbers, mid + 1, right);
        Merge(numbers, left, mid, right);
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

    MergeSort(numbers, 0, numbers.size() - 1);

    cout << endl;
    clock_t duration = clock() - before;
    cout << "Duration: " << (double)duration / CLOCKS_PER_SEC << " seconds";
    return 0;
}
