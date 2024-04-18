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


    /*��l����children parent��NULL*/
    for (int i=0;i<nodes_num;i++)
    {
        nodes[i].children=NULL;
        nodes[i].parent=malloc(sizeof(node));
    }


    /*��Jinput�`�I*/
    for (int i=0;i<nodes_num;i++)
    {
        scanf("%d", &nodes[i].parent->id);    //�s�i�U�I��parent��id��
        nodes[i].id=i;                        //�s�U�Iid����
        fin[rounds][i]=nodes[i].parent->id;   //��̲׵��G�}�C�Ĥ@����s�i���諸parent��

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


    /*��tree2=lastnode����m,�⨺��m��parent�令tree2*/
    int temp=0, temp_fin=1, temp_last[nodes_num], link_num=0;
    while (1)
    {
        int a=0;                                        //���]a��0,�Y���i�Jloop�̧�parent�ha�|�ܦ�1
        for (int j=0;j<temp_fin;j++)
        {
            last=lastnode[j];                           //�Nlastnode�C�ӳ���L
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
                    temp_last[temp]=k;                  //�N����쪺id�s�itemp_last��,�̫�s�ilastnode��
                    temp++;
                    link_num++;
                }
            }
            link_num=0;
        }

        /*�粒�N�s�i�̫�s���ת��}�C*/
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
