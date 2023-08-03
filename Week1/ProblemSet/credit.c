#include <stdio.h>
#include <math.h>

int sumMultf (int num);

int main (void) {
    long long int creditNum;

    printf("Enter your credit card number: ");
    scanf("%lli", &creditNum);

    int length = 0;

    if (creditNum > 10000000000000000) printf("INVALID\n");
    else if (creditNum > 999999999999999) length = 16;
    else if (creditNum > 99999999999999) length = 15;
    else if (creditNum > 9999999999999) printf("INVALID\n");
    else if (creditNum > 999999999999) length = 13;
    else printf("INVALID\n"); 

    int numbers [length];
    long long int temp = creditNum;

    for (int i = 0; i < length; i++){
        numbers[i] = temp % 10;

        temp = floor(temp / 10);
    }

    int sumMult = 0;

    for (int i = 1; i < length; i += 2){
         sumMult = sumMult + sumMultf(numbers[i]);
    }

    for (int i = 0; i < length; i += 2){
        sumMult = sumMult + numbers[i];
    }

    if ((sumMult % 10) == 0){
        switch (numbers[length - 1])
        {
        case 3:
            printf("American Express\n");
            break;
        case 4:
            printf("VISA\n");
            break;
        case 5:
            printf("MASTERCARD\n");
            break;
        default:
            printf("INVALID\n");
            break;
        }
    }
    else {
        printf("INVALID\n");
    }

    int end;
    scanf("%i", &end);
}

int sumMultf (int num) {
    int temp = num * 2;
    int sum = 0;

    if (temp > 9){
        sum = sum + (temp % 10);

        temp = floor(temp / 10);
        sum = sum + temp;

        return sum;
    }
    else {
        return temp;
    }
}