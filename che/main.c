#include<stdio.h>

//function to print an array
void printIntArray(int * arr, int n){

    int i = 0;
    for(i = 0; i < n; i++)
        printf("%d",arr[i]);
    printf("\n");
}


int array_to_num(int arr[],int n){
    char str[6][3];
    int i;
    char number[16] = {'\n'};

    for(i=0;i<n;i++) sprintf(str[i],"%d",arr[i]);
    for(i=0;i<n;i++)strcat(number,str[i]);

    i = atoi(number);
    return i;
}

// function to convert decimal to binary
int* decToBinary(int n)
{
    // array to store binary number
    static int binaryNum[16];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    return binaryNum;
}

int* decToOctal(int n)
{

    // array to store octal number
    int octalNum[16];

    // counter for octal number array
    int i = 0;
    while (n != 0) {

        // storing remainder in octal array
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }

    int j,k;
    static int f_octal[16];

    for (j = i - 1, k=0; j >= 0; j--, k++)
        f_octal[k] = octalNum[j];

    return f_octal;
}

char* decToHex(int* input, int binary_size){
    int hexConstant[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000,
                         1001, 1010, 1011, 1100, 1101, 1110, 1111};

    long long binary, tempBinary;
    char hex[16];
    int index, i, digit;

    /* Input binary number from user */
    int* input_binary = decToBinary(input);
    int x = array_to_num(input_binary, binary_size);
    binary = x;

    /* Copy binary number to temp variable */
    tempBinary = binary;
    index = 0;

    /* Find hexadecimal of binary number */
    while(tempBinary!=0)
    {
        /* Group binary to last four digits */
        digit = tempBinary % 10000;

        /* Find hexadecimal equivalent of last four digit */
        for(i=0; i<16; i++)
        {
            if(hexConstant[i] == digit)
            {
                if(i<10)
                {
                    /* 0-9 integer constant */
                    hex[index] = (char)(i + 48);
                }
                else
                {
                    /* A-F character constant */
                    hex[index] = (char)((i-10) + 65);
                }

                index++;
                break;
            }
        }

        /* Remove the last 4 digits as it is processed */
        tempBinary /= 10000;
    }
    hex[index] = '\0';

    /* Reverse the hex digits */
    strrev(hex);

    return hex;
}

// Driver program to test above functions
int main()
{
    int n = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    int* binary = decToBinary(n);
    printIntArray(binary, 5); // first value is the array and the second is the number of digits
    int* octal = decToOctal(n);
    printIntArray(octal, 2);
    char* hex = decToHex(n, 5);
    printf("%s", hex);

    return 0;
}
