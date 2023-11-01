#include <iostream> 
#include <time.h>
#include <iomanip>
using namespace std;


void Create(int* x, const int size, const int Low, const int High, int i)
{
    x[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(x, size, Low, High, i + 1);
}
void Print(int* x, const int size, int i)
{
    cout << setw(4) << x[i];
    if (i < size - 1)
        Print(x, size, i + 1);
    else
        cout << endl;
}
double Find(int* a, int size, int i, int p, int y) {
    if (i == size) {
        if (y > 0)
            return (p * 1.0) / (y * 1.0);
        else
            return -1;
    }

    if (a[i] % 2 == 0) {
        p = p + i;
        y++;
    }

    return Find(a, size, i + 1, p, y);
}
int main()
{
    srand((unsigned)time(NULL));
    const int n = 5;
    int a[n];
    int Low = 8;
    int High = 18;
    Create(a, n, Low, High,0);
    Print(a, n,0);
    cout << Find(a, n,0,0,0) << endl;
    return 0;
}