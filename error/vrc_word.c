#include <stdio.h>
#include <string.h>

void add_parity_bit(char *ascii_code, char *ascii_with_parity)
{
    int ones = 0;
    for (int i = 0; i < 7; i++)
    {
        if (ascii_code[i] == '1')
        {
            ones++;
        }
    }
    if (ones % 2 == 0)
    {
        ascii_with_parity[7] = '0';
    }
    else
    {
        ascii_with_parity[7] = '1';
    }
    ascii_with_parity[8] = '\0';
}

void print_transmission(char *message, char transmitted_data[][9], int length)
{
    printf("Transmitted Data with Even Parity:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%s ", transmitted_data[i]);
    }
    printf("\n");
}

void receiver_check(char transmitted_data[][9], int length)
{
    printf("Receiver's Check for Errors:\n");
    for (int i = 0; i < length; i++)
    {
        int ones = 0;
        for (int j = 0; j < 8; j++)
        {
            if (transmitted_data[i][j] == '1')
            {
                ones++;
            }
        }
        if (ones % 2 == 0)
        {
            printf("Character %d is correct (even parity)\n", i + 1);
        }
        else
        {
            printf("Error detected in character %d!\n", i + 1);
        }
    }
}

int main()
{
    char message[1024];
    printf("Enter a message: ");
    scanf("%s", message);
    int length = strlen(message);
    char transmitted_data[length][9];

    for (int i = 0; i < length; i++)
    {
        char ascii_code[8];
        char ascii_with_parity[9];

        for (int j = 6; j >= 0; j--)
        {
            ascii_code[j] = (message[i] & 1) ? '1' : '0';
            message[i] >>= 1;
        }
        ascii_code[7] = '\0';

        add_parity_bit(ascii_code, ascii_with_parity);

        strcpy(transmitted_data[i], ascii_with_parity);
    }

    print_transmission(message, transmitted_data, length);

    char received_data[length][9];
    for (int i = 0; i < length; i++)
    {
        strcpy(received_data[i], transmitted_data[i]);
    }

    received_data[2][3] = '0';

    receiver_check(received_data, length);

    return 0;
}
