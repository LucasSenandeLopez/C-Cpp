/*

    We are proposed to make a program that, from a given "decrease ratio"; the percentage of height lost
    each iteration; computes when the object bounces up to less than a quarter of its original height

*/
#include <iostream>

using namespace std;

int main()
{
    const int height = 100;
    float decrease_ratio;
    float current_height;
    unsigned int iterations;

    cout << "Input a height ratio less than one and higher than zero as a decimal: \n";
    cin >> decrease_ratio;

    decrease_ratio = ((decrease_ratio >= 1.0f || decrease_ratio <= 0.0f) ? 0.1f : decrease_ratio);

    current_height = (float)height;

    for (iterations = 1; current_height > (float)(height / 4); ++iterations)
    {

        current_height *= (1.0f - decrease_ratio);

        cout << "Height after " << iterations << " iteration(s) is: " << current_height << " \n";

    }

    cout << "It took " << iterations - 1 << \
        " iterations to make the ball bounce less than a quarter of its initial height. \n";

    return 0;
}
