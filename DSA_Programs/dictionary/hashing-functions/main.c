#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 19
#define MAX 50

int hashHundreds(int num)
{
    return (num / 100) % 10;
}

int hashRange(int num)
{
    int x, ret;

    for(x = num, ret = 0; x > 0; x /= 10) {
        ret += x % 10;
    }

    if(ret < NUM && ret >= 0) return ret;
    else return ret = -1;
}

int hashString(char str[])
{
    int length = strlen(str), x, ret;

    for(x = 0, ret = 0; x < length; x++) {
        int val = str[x] + 0;
        ret += val;
    }

    ret /= 49;

    if(ret >= 0 && ret < 49) return ret;
    else return -1;
}

int main()
{   
    int hash1 = hashHundreds(1258);
    int hash2 = hashRange(258);
    int hash3 = hashString("MARK");

    printf("FIRST HASHING FUNCTION RETURNED : %d\n", hash1);
    printf("SECOND HASHING FUNCTION RETURNED : %d\n", hash2);
    printf("THIRD HASHING FUNCTION RETURNED : %d\n", hash3);

    return 0;
}