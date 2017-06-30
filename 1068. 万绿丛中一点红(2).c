#include<stdio.h>
#include<string.h>
#include<math.h>
long a[1010][1010];
int u[1010][1010]={0};
int main(){
    long n,m,h;
    int k = 0;
    int c1,c2,c3;
    scanf("%ld %ld %ld",&n,&m,&h);
    int i,j;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            scanf("%ld",&a[i][j]);
        }
    }
    for(i=0;i<=n+1;i++){
        a[0][i] = -(pow(2,24)-1);
    }
    for(i=0;i<=n+1;i++){
        a[m+1][i] = -(pow(2,24)-1);
    }
    for(i=0;i<=m+1;i++){
        a[i][0] = -(pow(2,24)-1);
    }
    for(i=0;i<=m+1;i++){
        a[i][n+1] = -(pow(2,24)-1);
    }
/*    for(int i=0;i<=m+1;i++){
        for(int j=0;j<=n+1;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    int i1,j1;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(!u[i][j]){
                for(i1=i;i1<=m;i1++){
                    for(j1=1;j1<=n;j1++){
                        if(a[i][j]==a[i1][j1]&&(i!=i1||j!=j1)){
                            u[i1][j1] = 1;
                            u[i][j] = 1;
                        }
                    }
                }
            }
            
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(u[i][j])
                continue;
            int b1 = labs(a[i][j]-a[i][j-1]);
            int b2 = labs(a[i][j]-a[i][j+1]);
            int b3 = labs(a[i][j]-a[i+1][j-1]);
            int b4 = labs(a[i][j]-a[i+1][j]);
            int b5 = labs(a[i][j]-a[i+1][j+1]);
            int b6 = labs(a[i][j]-a[i-1][j]);
            int b7 = labs(a[i][j]-a[i-1][j-1]);
            int b8 = labs(a[i][j]-a[i-1][j+1]);
            if(b1>h&&b2>h&&b3>h&&b4>h&&b5>h&&b6>h&&b7>h&&b8>h){
                k++;
                if(k==1){
                    c1 = i;
                    c2 = j;
                    c3 = a[i][j];
                }
            }
        }
    }
    if(k==0){
        printf("Not Exist");
    }else if(k==1){
        printf("(%d, %d): %d",c2,c1,c3);
    }else{
        printf("Not Unique\n");
    }
}
//全部正确 
