#include <stdio.h>
#include <string.h>

void XOR(char *a, char *b, char *result)
{
    int i;
    for (i = 0; i < strlen(b); i++)
    {
        if (a[i] == b[i])
        {
            result[i] = '0';
        }
        else
        {
            result[i] = '1';
        }
    }
    for (i; i < strlen(a); i++)
    {
        result[i] = a[i];
    }
    result[i] = '\0';
}

void removePreZeros(char *s)
{
    int i = 0;
    while (s[i] == '0')
    {
        i++;
    }
    memmove(s, s + i, strlen(s) - i + 1);
}

void CalculateCRC(char *m, char *d, char *crc)
{
    char curr[1024];
    strcpy(curr, m);

    int m_len = strlen(m);
    int d_len = strlen(d);

    for (int i = 0; i < d_len - 1; i++)
    {
        curr[m_len + i] = '0';
    }
    curr[m_len + d_len - 1] = '\0';

    while (strlen(curr) > d_len - 1)
    {
        char temp[1024];
        XOR(curr, d, temp);
        strcpy(curr, temp);
        removePreZeros(curr);
    }

    int crc_len = d_len - 1;
    int curr_len = strlen(curr);
    char final[1024];
    if (curr_len < crc_len)
    {
        int diff = crc_len - curr_len;
        char temp[crc_len - diff];

        for (int i = 0; i < diff; i++)
        {
            temp[i] = '0';
        }
        temp[diff] = '\0';
        strcpy(final, temp);
        strcat(final, curr);
        curr[curr_len + diff] = '\0';
    }

    strcpy(crc, final);
}

int main()
{
    char m[1024], d[1024], crc[1024], rm[1024], r_crc[1024];

    printf("Enter message: ");
    scanf("%s", m);
    printf("Enter divisor: ");
    scanf("%s", d);

    CalculateCRC(m, d, crc);
    printf("CRC: %s\n", crc);
    printf("Message with CRC: %s%s\n", m, crc);

    printf("Enter received message: ");
    scanf("%s", rm);

    CalculateCRC(rm, d, r_crc);

    int isError = 0;
    for (int i = 0; i < strlen(r_crc); i++)
    {
        if (r_crc[i] == '1')
        {
            isError = 1;
            break;
        }
    }

    if (isError)
    {
        printf("Error detected in received message\n");
    }
    else
    {
        printf("No error detected in received message\n");
    }

    return 0;
}
