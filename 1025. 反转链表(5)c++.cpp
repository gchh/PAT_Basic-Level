#include <iostream>
#include <cstdio>
using namespace std;
int nextnum[100010],value[100010];
struct Node{
    int value,pos,nnext;
    Node *pnext,*plast,*final;
};
int main() {
    int start,n,k,pos,next,val,count=1;
    
    
    
    /*-------------数据输入，数组纪录下一结点及储存值-------------*/
    scanf("%d%d%d",&start,&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%d%d%d",&pos,&val,&next);
        nextnum[pos]=next;
        value[pos]=val;
    }
    /*------------------------------------------------------*/
    
    
    
    
    
    /*-------------创建链表并储存上下结点“位置”-----------------*/
    pos=start;
    Node *p1,*p2,*head;
    p1=p2=new Node;
    p1->value=value[pos];
    p1->pos=pos;
    head=p1;
    pos=nextnum[pos];
    while (pos!=-1) {
        p1=new Node;
        p2->pnext=p1;
        p1->plast=p2;
        p1->value=value[pos];
        p1->pos=pos;
        p2=p1;
        pos=nextnum[pos];
        count++;
    }
    p1->pnext=NULL;

    if (count==1) {
        printf("%05d %d -1\n",head->pos,head->value);
        return 0;
    }
    /*------------------------------------------------------*/
    
    
    
    
    
    /*-------------反转链表----------------------------------*/
    int cur=0;
    Node *temp,*temp1=NULL;
    temp=head;
    p1=head;
    while (p1) {
        if (cur==k-1) {
            head=p1;
        }//find the head
        
        if (cur%k==0 && cur<count/k*k) {
            p1->nnext=-1;
            p1->final=NULL;
            if (cur%(2*k)==0) temp=p1;
            else temp1=p1;
        }else {
            if (cur<count/k*k) {
                p1->final=p1->plast;
                p1->nnext=p1->final->pos;
            }else {
                p1->final=p1->pnext;
                if (cur<count-1) p1->nnext=p1->final->pos;
                else p1->nnext=-1;
            }
        }
        
        if (cur>k-1 && (cur+1)%k==0) {
            if ((cur+1)%(2*k)==0) {
                temp->final=p1;
                temp->nnext=p1->pos;
            }else {
                temp1->final=p1;
                temp1->nnext=p1->pos;
            }
            
        }
        if (cur==count/k*k) {
            if (cur%(2*k)!=0) {
                temp->final=p1;
                temp->nnext=p1->pos;
            }else {
                temp1->final=p1;
                temp1->nnext=p1->pos;
            }
            
        }
        
        cur++;
        p1=p1->pnext;
        if (cur==count) {
            break;
        }
    }
    /*------------------------------------------------------*/
    
    
    
    
    
    /*-------------输出整条反转完的链表------------------------*/
    p1=head;
    while (p1) {
        if (p1->nnext==-1) printf("%05d %d %d\n",p1->pos,p1->value,p1->nnext);
        else printf("%05d %d %05d\n",p1->pos,p1->value,p1->nnext);
        p1=p1->final;
    }
    
    
    return 0;
}
//全部正确 
