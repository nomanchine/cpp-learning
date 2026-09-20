#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num[] = { -7, -3, 2, 3, 11 };
    int size = 5;

    int* left = num;
    int* right = num + size - 1;

    int result[5];
    int index = size - 1;

    while (left <= right)
    {
        if (abs(*left) > abs(*right))
        {
            result[index] = (*left) * (*left);
            left++;
        }
        else
        {
            result[index] = (*right) * (*right);
            right--;
        }

        index--;
    }

    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    system("pause");
    return 0;
}
