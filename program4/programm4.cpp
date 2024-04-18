#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

int count;

void init(bool **bits, int m, int r, int **a, int **b, int p)
{
    *bits=(bool*)malloc(sizeof(bool)*m);
    *a=(int*)malloc(sizeof(int)*r);
    srand(1);
    for (int i=0;i<r;i++)
    {
        *(*a+i)=rand()%(p-1)+1;
    }
    *b=(int*)malloc(sizeof(int)*r);
    srand(2);
    for (int i=0;i<r;i++)
    {
        *(*b+i)=rand()%(p-1)+1;
    }
}

int myhash(char *str, int count, int m, int r, int p, int *a, int *b)
{
    std::hash<std::string>hashing;
    size_t key=hashing(str);
    return (a[count]*key+b[count])%p%m;
}

void insert(bool *bits, int m, int r, int p, char *str, int *a, int *b)
{
    for (int i=0;i<r;i++)
    {
        bits[myhash(str, i, m, r, p, a, b)]=true;
    }
}

bool query(bool *bits, int m, int p, int r, char *str, int *a, int *b)
{
    int ans=0;
    for (int i=0;i<r;i++)
    {
        if (bits[myhash(str, i, m, r, p, a, b)]==true)
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
    int bits, hash_func, words, tests, test_prime;
    scanf("%d%d%d%d%d", &bits, &hash_func, &words, &tests, &test_prime);
    bool *bit_array;
    char word[1000][1000], word2[1000][1000];
    int *a, *b;
    init(&bit_array, bits, hash_func, &a, &b, test_prime);
    for (int i=0;i<words;i++)
    {
        scanf("%s", word[i]);
        insert(bit_array, bits, hash_func, test_prime, *(word+i), a, b);
    }
    for (int i=0;i<tests;i++)
    {
        scanf("%s", word2[i]);
        bool num=query(bit_array, bits, test_prime, hash_func, *(word2+i), a, b);
        if (num==1)
        {
            printf("%s: true\n", word2[i]);
        }
        else
        {
            printf("%s: false\n", word2[i]);
        }
    }
}
