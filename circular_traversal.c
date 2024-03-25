#include<stdio.h>
#include<stdlib.h>


void circular_traversal(int** arr,int ro,int c){
    int l=0;
    int r=c-1;
    int t=0;
    int b=ro-1;
    int num=0;
    int dir=0;
    while(num<ro*c){
        if(dir==0){
            for(int i=l;i<=r;i++){
               arr[t][i]=num;
               num++;
           }
            t++;
        }
        else if(dir==1){
           for(int i=t;i<=b;i++){
               arr[i][r]=num;
               num++;
           }
            r--;
        }
        else if(dir==2){
           for(int i=r;i>=l;i--){
               arr[b][i]=num;
               num++;
           }
            b--;
        }
        else if(dir==3){
           for(int i=b;i>=t;i--){
               arr[i][l]=num;
               num++;
            }           
           l++;
        }

       dir=(dir+1)%4;
    }
}



int main(){
    int r=3;
    int c=5;
    int** arr=malloc(r*sizeof(int*));
    for(int i=0;i<r;i++)arr[i]=malloc(c*sizeof(int));

    circular_traversal(arr,r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    
}
