#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main(){
    char a[110];
    char b[110];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    char c[110];
    int lena = strlen(a);
    int lenb  = strlen(b);
    int i,j;
    int temp;
    if(lenb-lena>=0){
            for(i=0;i<lenb-lena;i++){
                printf("%c",b[i]);
        }
        j = 0;
        temp = lena;
        for(i=lenb-lena;i<lenb;i++){
            if((temp--)%2==0){
                b[i] = b[i]-a[j];
                if(b[i]<0){
                    b[i] = b[i]+10;
                }
                b[i] = b[i]+'0';
            }
            else{
                if((b[i]-'0'+a[j]-'0')%13>=10){
                    if((b[i]-'0'+a[j]-'0')%13==10)
                        b[i] = 'J';
                    else if((b[i]-'0'+a[j]-'0')%13==11){
                        b[i] = 'Q';
                    }
                    else if((b[i]-'0'+a[j]-'0')%13==12){
                        b[i] = 'K';
                    }
                }
                else{
                    b[i] = (b[i]-'0'+a[j]-'0')%13+'0';
                }
                
            }
            j++;
            printf("%c",b[i]);
        }
    } 
    else{
        temp = lena;
        for(i=0;i<lena-lenb;i++){
            if((temp--)%2==0){
                if(a[i]!='0')
                    printf("%c",'9'+1-a[i]+'0');
                else
                    printf("0");
            }
            else{
                printf("%c",a[i]);
            }
        }
        j = lena-lenb;
        temp = lenb;
        for(i=0;i<lenb;i++){
            if((temp--)%2==0){
                b[i] = b[i]-a[j];
                if(b[i]<0){
                    b[i] = b[i]+10;
                }
                b[i] = b[i]+'0';
            }
            else{
                if((b[i]-'0'+a[j]-'0')%13>=10){
                    if((b[i]-'0'+a[j]-'0')%13==10)
                        b[i] = 'J';
                    else if((b[i]-'0'+a[j]-'0')%13==11){
                        b[i] = 'Q';
                    }
                    else if((b[i]-'0'+a[j]-'0')%13==12){
                        b[i] = 'K';
                    }
                }
                else{
                    b[i] = (b[i]-'0'+a[j]-'0')%13+'0';
                }
                
            }
            j++;
            printf("%c",b[i]);
        }
    }
    
}
