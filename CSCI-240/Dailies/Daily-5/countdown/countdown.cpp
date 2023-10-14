// 240 Count Down daily

#include <iomanip>
#include <iostream>

int main()
{
    int N;

            std::cout << "N value (must be greater than or equal to 1)? ";

    do
    {

        std::cin >> N;
        if (N < 1)
        {
            std::cout << "Error: the N-value must be greater than or equal to 1. Try again: ";
        }
    } while (N < 1);

    std::cout << std::endl;

    for (int i = N; i >= 1; i--)
    {
        std::cout.width(3);
        std::cout << i << " ";
    }

    std::cout << std::endl;
    return 0;
}
