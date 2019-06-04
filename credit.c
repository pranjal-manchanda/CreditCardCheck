#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main()
{
    long long credNum = get_long_long("Please enter a credit card number: ");
    long long brand = credNum;

    int current, evenSum = 0, oddSum = 0, count = 1;// Initialize variables

    while (credNum > 0)
    {
        current = credNum % 10;
        //printf("%i\n", current);
        //^^Check to see which number we are currently on
        if (count % 2 == 0)
        {
            current *= 2;
            //printf("Even: %i\n", current);
            //^^Check to mark order of numbers as even
            if (current >= 10)
            {
                evenSum += (current % 10);
                current /= 10;
                evenSum += current;
            }
            else
            {
                evenSum += current;
            }
        }

        else if (count % 2 == 1)
        {
            //printf("Odd: %i\n", current);
            ////^^Check to mark order of numbers as odd
            oddSum += current;
        }
        credNum /= 10;
        count++;
    }

    // If sum does not equal 0, then it is automatically invalid
    if ((evenSum + oddSum) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Amex has 15 digits
    if (count - 1 == 15)
    {
        brand = brand / pow(10, count - 3);
        //printf("First 2 Digits: %lld\n", brand);
        //^^Check first 2 digits

        if (brand == 34 || brand == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
        return 0;
    }

    // Check if Visa or Mastercard
    else
    {
        //Visa can have 13 or 16 digits
        if (count - 1 == 13)
        {
            brand = brand / pow(10, count - 2);
            //printf("First Digit: %lld\n", brand);
            //^^Check first number

            if (brand == 4)
            {
                printf("VISA\n");
            }

            else
            {
                printf("INVALID\n");
            }

            return 0;
        }

        //Visa or Mastercard
        else if (count - 1 == 16)
        {
            brand = brand / pow(10, count - 3);
            //printf("First 2 Digits: %lld\n", brand);
            //^^Check first 2 digits

            //Narrow down to 1 digit to see if Visa
            int visaCheck = brand;
            visaCheck /= 10;

            // printf("%lld\n", brand);

            // Check for VISA
            if (visaCheck == 4)
            {
                printf("VISA\n");
            }

            // Check for Mastercard
            else if (brand == 51 || brand == 52 || brand == 53 || brand == 54 || brand == 55)
            {
                printf("MASTERCARD\n");
            }

            // Invalid output
            else
            {
                printf("INVALID\n");
            }

            return 0;
        }

        // If none of the above, then Invalid
        else
        {
            printf("INVALID\n");
        }
    }
}