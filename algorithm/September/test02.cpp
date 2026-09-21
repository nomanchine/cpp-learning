#include <iostream>
using namespace std;

int main()
{
    int num[] = { 2, 7, 11, 15 };
    int size = 4;
    int target = 9;

    int* left = num;
    int* right = num + size - 1;

    while (left < right)
    {
        int sum = *left + *right;

        if (sum == target)
        {
            cout << "[" << left - num + 1 << ","
                 << right - num + 1 << "]" << endl;
            break;
        }
        else if (sum > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return 0;
}