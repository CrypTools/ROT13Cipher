/*
-----------------------------------------------------------------------------

            Commentaire ^-^

-----------------------------------------------------------------------------
*/
#include <iostream>
#include <cstring>

#define MAX_INPUT_LENGHT 2147000 // small values causes bugs for obscure reasons around the end of the for-loop

using namespace std;

bool crypt(const char* plaintext, char* result);

int main()
{
    char input[MAX_INPUT_LENGHT], result[MAX_INPUT_LENGHT];

    cout << "Input: ";
    cin.getline(input, MAX_INPUT_LENGHT);

    if (crypt(input, result) == true){
        cout << endl << endl << "Result: " << result << endl;
        return 0;
    }
    else {
        cout << endl << endl << "Non-alphabet input" << endl;
        return 1;
    }
}

bool crypt(const char* plaintext, char* result)
{
    int uppercase_lower = 65, uppercase_upper = 90, lowercase_lower = 97, lowercase_upper = 122, space = 32;

    for (unsigned int i=0; i<strlen(plaintext); ++i){
        if (plaintext[i] == space) result[i] = space; // Space
        else if (!(plaintext[i] > lowercase_upper) && !(plaintext[i] < lowercase_lower)) result[i] = (plaintext[i] - 84) % 26 + 97; // -84 = -97 (ascii) + 13 (rot13)
        else if (!(plaintext[i] > uppercase_upper) && !(plaintext[i] < uppercase_lower)) result[i] = (plaintext[i] - 52) % 26 + 65; // -52 = -65 (ascii) + 13 (rot13)
        else return false;
    }
    return true;
}
