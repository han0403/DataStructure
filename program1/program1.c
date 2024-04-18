#include <stdio.h>
#include <math.h>

struct node
{
    int id;
    double x;
    double y;
    double val;
    int neighbor[10000];
    int neighbor_num;
    double val_fin[10000];
    int val_fin_num;
}nodes[10000];

double max(double a, double b)
{
    if (a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int nod, rounds;
double temp=0;

int main()
{

    scanf("%d%d", &nod, &rounds);
    for (int i=0;i<nod;i++)//值存入nodes裡 並將neighbor數初始化為0
    {
        scanf("%d%lf%lf%lf", &nodes[i].id, &nodes[i].x, &nodes[i].y, &nodes[i].val);
        nodes[i].neighbor_num=0;
        nodes[i].val_fin_num=0;
        nodes[i].val_fin[nodes[i].val_fin_num]=nodes[i].val;
        nodes[i].val_fin_num++;
    }

    for (int i=0;i<nod;i++)//跑完nod次 若i,j距離<1 則將各自neighbor存入對方id
    {
        for (int j=0;j<nod;j++)
        {
            if ( sqrt(((nodes[i].x-nodes[j].x)*(nodes[i].x-nodes[j].x))+((nodes[i].y-nodes[j].y)*(nodes[i].y-nodes[j].y)))<1 )
            {
                nodes[i].neighbor[nodes[i].neighbor_num]=nodes[j].id;
                nodes[i].neighbor_num++;
            }
        }
    }

    for (int i=1;i<rounds;i++)//跑rounds-1次 將value算出並存入nodes內的val_fin裡
    {
        for (int j=0;j<nod;j++)
        {
            for (int k=0;k<nodes[j].neighbor_num;k++)
            {
                if (nodes[j].neighbor[k]==j)
                {
                    for (int l=0;l<nodes[j].neighbor_num;l++)
                    {
                        if (nodes[j].neighbor[l]!=j)
                        {
                            temp=temp+(1/(2*max(((double)nodes[nodes[j].neighbor[l]].neighbor_num-1), ((double)nodes[j].neighbor_num-1))));
                        }
                    }
                    nodes[j].val_fin[i]=nodes[j].val_fin[i]+(nodes[j].val_fin[i-1]*(1-temp));
                    temp=0;
                    //nodes[j].val_fin[i]=nodes[j].val_fin[i]+(nodes[j].val_fin[i-1]*(1/((double)nodes[j].neighbor_num-1)));
                }
                else
                {
                    nodes[j].val_fin[i]=nodes[j].val_fin[i]+(nodes[nodes[j].neighbor[k]].val_fin[i-1]*(1/(2*max(((double)nodes[nodes[j].neighbor[k]].neighbor_num-1), ((double)nodes[j].neighbor_num-1)))));
                }
            }
        }
    }

    printf("%d %d\n", nod, rounds);
    for (int i=0;i<rounds;i++)
    {
        for (int j=0;j<nod;j++)
        {
            printf("%.2f ", nodes[j].val_fin[i]);
            //printf("%.2f ", (double)((int)(nodes[j].val_fin[i]*100)/1)/100);//將最終答案保留小數點後兩位 其餘無條件捨去
        }
        printf("\n");
    }

    return 0;
}
