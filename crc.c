#include <stdio.h>
#include <string.h>

int i, j, keylen, msglen, flag;
char sendData[100], recData[100], key[30], temp[30], quot[100], rem[30], key1[30];

void division(char input[100])
{
    for (i = 0; i < keylen - 1; i++)
    {
        input[msglen + i] = '0';
    }
    for (i = 0; i < keylen; i++)
    {
        temp[i] = input[i];
    }
    for (i = 0; i < msglen; i++)
    {
        quot[i] = temp[0];
        if (quot[i] == '0')
        {
            for (j = 0; j < keylen; j++)
                key[j] = '0';
        }
        else
        {
            for (j = keylen - 1; j > 0; j--)
            {
                if (temp[j] == key[j])
                    rem[j - 1] = '0';
                else
                    rem[j - 1] = '1';
            }
        }
        rem[keylen - 1] = input[i + keylen];
        strcpy(temp, rem);
    }
}
void main()
{
    printf("Enter Data: ");
    gets(sendData);
    printf("Enter Key: ");
    gets(key);
    keylen = strlen(key);
    msglen = strlen(sendData);
    strcpy(key1, key);
    division(sendData);
    printf("\nRemainder is ");
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);
    printf("\nFinal data is: ");
    for (i = 0; i < msglen; i++)
        printf("%c", sendData[i]);
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);

    printf("\nEnter Receiver Data: ");
    gets(recData);
    msglen = strlen(sendData);
    division(recData);
    flag = 0;
    printf("\nRemainder is ");
    for (i = 0; i < keylen - 1; i++)
    {
        if (rem[i] == '1')
            flag = 1;
        printf("%c", rem[i]);
    }
    if (flag == 0)
        printf("\nNo error");
    else
        printf("\nError");
}
