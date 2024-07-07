#include <iostream>
#include <string>

using std::string;

class Solution {

public:

    bool is_palindrome(string s, long unsigned int min, long unsigned int max)
    {
        char left;
        char right;

        for (long unsigned int i = 0; i < max/2;++i)
        {
            left = s[min + i];
            right = s[max - 1 - i];

            if (left != right) {return false;}
        }
        return true;
    }

    string longestPalindrome(string s) {
        
        long unsigned int len = s.length();
        bool substr;
        long unsigned int max = len;
        long unsigned int temp_max_len = 0;
        long unsigned int min_ptr = 0;
        long unsigned int str_len = len;


        for (long unsigned int min = 0; min < str_len; ++min)
        {
            do
            {
                --len;
                substr = is_palindrome(s, min, max);
                --max;
            } while (!substr && len);

            len = str_len - min;
            
            if (temp_max_len < max - min + 1)
            {
                temp_max_len = max - min + 1;
                min_ptr = min;
            }
            max = str_len;
        }
        return s.substr(min_ptr, temp_max_len);
    }
};


int main()
{
    string str;
    Solution sol;
    std::cout << "Enter a string\n";
    getline(std::cin, str);

    str = sol.longestPalindrome(str);

    std::cout << "The longest palindromic string is: " << str << std::endl;

}