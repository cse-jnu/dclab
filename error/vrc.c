#include <stdio.h>
#include <string.h>

void parityCalculate(char *seq, char *parity)
{

    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (seq[i] == '1')
        {
            count++;
        }
    }
    parity[0] = (count % 2 == 0) ? '0' : '1';
    parity[1] = '\0';
}

void main()
{
    char str[100];
}