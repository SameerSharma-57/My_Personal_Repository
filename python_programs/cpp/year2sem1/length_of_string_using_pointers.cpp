#include <iostream>
using namespace std;

int length_of_str(char strin[])
{
    char *ptr = strin;
    int cnt = 0;
    while (*ptr)
    {
        cnt += 1;
        ptr++;
    }
    return cnt;
}
int main()
{
    const int max = 100;
    char strin[max];
    cin.get(strin, max);
    cout << length_of_str(strin);
    return 0;
}