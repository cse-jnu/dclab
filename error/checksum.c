#include <stdio.h>
#include <string.h>

void add(char *a, char *b, char *sum)
{
    int carry = 0;
    for (int i = 7; i >= 0; i--)
    {
        if (carry == 0)
        {
            if (a[i] == '1' && b[i] == '1')
            {
                sum[i] = '0';
                carry = 1;
            }
            else if (a[i] == '1' || b[i] == '1')
            {
                sum[i] = '1';
            }
            else
            {
                sum[i] = '0';
            }
        }
        else
        {
            if (a[i] == '1' && b[i] == '1')
            {
                sum[i] = '1';
            }
            else if (a[i] == '1' || b[i] == '1')
            {
                sum[i] = '0';
            }
            else
            {
                sum[i] = '1';
                carry = 0;
            }
        }
    }
    if (carry)
    {
        char temp[9] = "00000001";
        add(sum, temp, sum);
    }

    sum[8] = '\0';
}

void complement(char *s, char *result)
{
    for (int i = 0; i < 8; i++)
    {
        result[i] = (s[i] == '1') ? '0' : '1';
    }
    result[8] = '\0';
}

int main()
{
    char a[9], b[9], checksum[9];

    printf("Enter 8-bit code for a and b: ");
    scanf("%s %s", a, b);

    char sum[9];
    add(a, b, sum);

    complement(sum, checksum);

    printf("%s %s %s\n", a, b, checksum);

    char x[9], y[9], z[9], res[9];

    printf("Enter receiver receive: ");
    scanf("%s %s %s", x, y, z);

    char temp_sum[9];
    add(x, y, temp_sum);
    add(temp_sum, z, res);

    int error = 0;
    for (int i = 0; i < 8; i++)
    {
        if (res[i] == '0')
        {
            error = 1;
            break;
        }
    }

    if (error)
    {
        printf("NOT CORRECT\n");
    }
    else
    {
        printf("CORRECT\n");
    }

    return 0;
}
