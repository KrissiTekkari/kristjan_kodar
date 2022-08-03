#include <string> // For std::string and std::getline
#include <iostream>

int main()
{

    std::cout << "Enter an integer: ";
    int smaller{};
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger{};
    std::cin >> larger;

    if (smaller > larger)
    {
        int x {smaller};
        smaller = larger;
        larger = x;
        
        std::cout << "Swapping the values\n";
        std::cout << "The smaller value is "<< smaller << '\n';
        std::cout << "The larger value is "<< larger << '\n';
    }

    return 0;
}