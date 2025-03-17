#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> &x, int a, int b)
{
    int p = x[b], y = a - 1;
    for (int z = a; z < b; z++)
    {
        if (x[z] <= p)
            swap(x[++y], x[z]);
    }
    swap(x[y + 1], x[b]);
    return y + 1;
}

void QuickSort(vector<int> &x, int a, int b)
{
    if (a < b)
    {
        int c = Partition(x, a, b);
        QuickSort(x, a, c - 1);
        QuickSort(x, c + 1, b);
    }
}

int main()
{
    clock_t start = clock();

    ifstream in("100000.txt");
    vector<int> x;
    int y;
    while (in >> y)
    {
        x.push_back(y);
    }
    in.close();

    QuickSort(x, 0, x.size() - 1);

    cout << endl;
    clock_t end = clock() - start;
    cout << "Duration: " << (double)end / CLOCKS_PER_SEC << " seconds";
    return 0;
}
