#include <iostream>
#include <string>
#include <limits> // for std::numeric_limits


char warmup(char c, int shift);
std::string caesar(std::string s, int shift);
std::string decipher(std::string s);
int max_index(double x);
void ignoreLine();
std::string getString();
bool yes_or_no();
int getInt();
char getChar();


void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int max_index(double x[], int size)
{
    double y {x[0]};
    int INDEX {};
    for(int counter {1}; counter < size; ++counter)
    {
        if (x[counter] >= y)
            {
                y = x[counter];
                INDEX = counter;
            }
    }
    return INDEX;
}


std::string decipher(std::string s)
{
    int let_freq[26]{3,-1,1,1,4,0,0,2,2,-5,-2,1,0,2,3,0,-6,2,2,3,1,-1,0,-5,0,-7};
    std::string string_array[26]{};
    double averages[26]{};
    double summa {0.0};
    char temp_c { };
    std::string temp_s {};
    for( int counter{0} ; counter <= 25; ++counter )
    {
        temp_s = caesar(s,counter);
        for( int inner_counter{0} ; inner_counter <= 25; ++inner_counter )
        {   
            temp_c = temp_s[inner_counter];
            if (temp_c < 'A' || (temp_c > 'Z' && temp_c < 'a') || temp_c > 'z')
                    continue;
            else if ('A' <= temp_c && temp_c <= 'Z')
                {
                    summa += let_freq[temp_c-'A'];
                }
            else
                summa += let_freq[temp_c-'a'];
        }
        summa = summa/temp_s.length();
        averages[counter] = summa;
        string_array[counter] = temp_s;
        
    }
    return string_array[max_index(averages,sizeof(averages)/sizeof(double))];
}

char warmup(char c, int shift)
{
    if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
        return c;
    
    int goo {0};
    
    if ('A' <= c && c <= 'Z')
        {
            c += 32;
            goo = 32;
        }
    
    int foo {c + shift%26};
    
    if ('a' <= foo && foo <= 'z')
        return foo - goo;
    else if (foo > 'z')
        return (('a' - 1) + (foo - 'z')%26) - goo;
    else
        return (('z' + 1) + (foo - 'a')%26) - goo;
}

std::string caesar(std::string s, int shift)
{
    std::string temp_s {""};
    for(int counter { 0 }; counter < s.length(); ++counter)
    {
        temp_s += warmup(s[counter], shift);
    }
    //std::cout << "caesar(" << s << ", " << shift << ") => " << temp_s << '\n';
    return temp_s;
}

std::string getString()
{   
    std::string x;
    getline(std::cin, x);
    return x;
}

char getChar()
{
    char x;
    std::cin >> x;
    ignoreLine(); // taktu fyrsta char sem sest i stream-inu og hentu rest
    return x;
}

bool yes_or_no()
{
    //std::cout << "Enter a character: ";
    while (true) // Loop until user enters a valid input
    {
        char x;
        std::cin >> x;
        ignoreLine();
        switch (x)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        default: // otherwise tell the user what went wrong
            std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
    }
}

int getInt()
{
    //std::cout << "Enter an integer: ";
    while (true) // Loop until user enters a valid input
    {
        int x;
        std::cin >> x;
        if (!std::cin) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            std::cerr << "ERROR, not an integer. Try again: ";
        }
        else // else our extraction succeeded
        {
            ignoreLine();
            return x; // so return the value we extracted
        }
    }
}

int main()
{
    //char stafur{ 'a' }; // count how many times the loop iterates
    /* caesar("a", 1);
    caesar("abcz", 1);
    caesar("irk", 13);
    caesar("fusion", 6);
    caesar("Daily programmer", 6);
    caesar("Jgore vxumxgsskx", -6); */

   /*  std::cout << decipher("Zol abyulk tl puav h ulda.") << '\n';
    std::cout << decipher("Tfdv ef wlikyvi, wfi uvrky rnrzkj pfl rcc nzky erjkp, szx, gfzekp kvvky.") << '\n';
    std::cout << decipher("Qv wzlmz bw uiqvbiqv iqz-axmml dmtwkqbg, i aeittwe vmmla bw jmib qba eqvoa nwzbg-bpzmm bquma mdmzg amkwvl, zqopb?") << '\n';
    std::cout << decipher("rypzaqhu vyyp khkhzvu") << '\n' << '\n'; */

    
    while (true)
    {

        std::cout << "Loop again (y/n)? ";

        if (!yes_or_no())
            break;

        std::cout << "Enter a sentence: " ;
        std::string inp {getString()};
        
        std::cout << "Decipher or shift (d/s)? ";
        char c{getChar()};

        if (c == 'd')
        {
            std::cout << decipher(inp) << '\n'; 
        }
        else
        {
        std::cout << "Shift by how many places: ";
        int enc {getInt()};
        std::cout <<  "The encrypted sentence is " << caesar(inp, enc) << '\n';
        }
    }
    
    std::cout <<  "See you later! ";
    return 0;
}