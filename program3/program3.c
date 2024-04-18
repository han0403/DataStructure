#include <stdio.h>

struct rule
{
    char SIP;
    char DIP;

};

int main()
{
    int bits, ingressID1, egressID2, switches, links;
    scanf("%d", &bits);
    scanf("%d%d", &ingressID1, &egressID2);
    scanf("%d", &switches);
    int switchID[switches], capacity[switches];
    for (int i=0;i<switches;i++)
    {
        scanf("%d%d", &switchID[i], &capacity[i]);
    }
    scanf("%d", &links);



    return 0;
}
