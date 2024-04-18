#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int count;

void init(bool **bits, int m, int r, int **a, int **b, int p)
{
    int array[m];
    **bits=array;
    srand(1);
    for (int i=0;i<r;i++)
    {
        **(a+i)=rand()%(p-2)+1;
    }
    srand(2);
    for (int i=0;i<r;i++)
    {
        **(b+i)=rand()%(p-2)+1;
    }
}

int myhash(char *str, int count, int m, int r, int p, int *a, int *b)
{
    hash<string>hashing;
    size_t key=hashing(str);
    return (a[count]*key+b[count])%p%m;
}

void insert(bool *bits, int m, int r, int p, char *str, int *a, int *b)
{
    for (int i=0;i<r;i++)
    {
        bits[myhash(str, count, m, r, p, a, b)]=true;
    }
}

bool query(bool *bits, int m, int p, int r, char *str, int *a, int *b)
{
    int ans=0;
    for (int i=0;i<r;i++)
    {
        if (bits[myhash(str, count, m, r, p, a, b)]==true)
        {
            ans++;
        }
    }
    if (ans==r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a, b, c, tests, test_prime;
    scanf("%d%d%d%d%d", &a, &b, &c, &tests, &test_prime);
    int bit_array[a];


}
