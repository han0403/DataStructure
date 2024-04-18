#include <stdio.h>
#include <stdlib.h>

typedef struct Node* NodePtr;
typedef struct ListNode* ListNodePtr;
typedef struct Node
{
    int id;
    ListNodePtr children;
    NodePtr parent;
}node;
typedef struct ListNode
{
    NodePtr data;
    ListNodePtr link;
}listnode;


int main()
{
    int nodes_num, rounds=0;
    scanf("%d", &nodes_num);

    NodePtr nodes=malloc (sizeof(node)*nodes_num);
    int lastnode[nodes_num], last, tree2[nodes_num], fin[1000][nodes_num];


    /*初始全部children parent為NULL*/
    for (int i=0;i<nodes_num;i++)
    {
        nodes[i].children=NULL;
        nodes[i].parent=malloc(sizeof(node));
    }


    /*輸入input節點*/
    for (int i=0;i<nodes_num;i++)
    {
        scanf("%d", &nodes[i].parent->id);    //存進各點的parent的id裡
        nodes[i].id=i;                        //存各點id的值
        fin[rounds][i]=nodes[i].parent->id;   //把最終結果陣列第一行先存進未改的parent值

        /*linklist children*/
        if (nodes[i].parent->id==-1)
        {
            lastnode[0]=i;
            continue;
        }
        if (nodes[nodes[i].parent->id].children==NULL)
        {
            nodes[nodes[i].parent->id].children=malloc(sizeof(listnode));
            nodes[nodes[i].parent->id].children->link=NULL;
            nodes[nodes[i].parent->id].children->data=&nodes[i];
        }
    }
    rounds++;
    for (int i=0;i<nodes_num;i++)
    {
        scanf("%d", &tree2[i]);
    }


    /*找tree2=lastnode的位置,把那位置的parent改成tree2*/
    int temp=0, temp_fin=1, temp_last[nodes_num], link_num=0;
    while (1)
    {
        int a=0;                                        //先設a為0,若有進入loop裡改parent則a會變成1
        for (int j=0;j<temp_fin;j++)
        {
            last=lastnode[j];                           //將lastnode每個都找過
            for (int k=0;k<nodes_num;k++)
            {
                if((tree2[k]==last))
                {
                    a=1;
                    nodes[k].parent=&nodes[tree2[k]];

                    if ((link_num==0) && (nodes[nodes[k].parent->id].children==NULL))
                    {
                        nodes[nodes[k].parent->id].children=malloc(sizeof(listnode));
                        nodes[nodes[k].parent->id].children->link=NULL;
                        nodes[nodes[k].parent->id].children->data=&nodes[k];
                    }
                    else if ((nodes[nodes[k].parent->id].children==NULL))
                    {
                        nodes[nodes[k].parent->id].children=malloc(sizeof(listnode));
                        nodes[nodes[temp-1].parent->id].children=malloc(sizeof(listnode));
                        nodes[nodes[k].parent->id].children->link=NULL;
                        nodes[nodes[temp-1].parent->id].children->link=nodes[nodes[k].parent->id].children;
                        nodes[nodes[k].parent->id].children->data=&nodes[k];
                    }
                    temp_last[temp]=k;                  //將有改到的id存進temp_last裡,最後存進lastnode裡
                    temp++;
                    link_num++;
                }
            }
            link_num=0;
        }

        /*改完就存進最後存答案的陣列*/
        for (int j=0;j<nodes_num;j++)
        {
            fin[rounds][j]=nodes[j].parent->id;
        }
        for (int j=0;j<temp;j++)
        {
            lastnode[j]=temp_last[j];
        }
        temp_fin=temp;
        temp=0;
        if(a==0)
        {
            break;
        }
        rounds++;
    }

    printf("%d\n", rounds);
    for (int i=0;i<rounds;i++)
    {
        for (int j=0;j<nodes_num;j++)
        {
            printf("%d ", fin[i][j]);
        }
        printf("\n");
    }


    return 0;
}
