#include<stdio.h>
#define INF 99999
#define v 4
void floyid_warshall(int arr[v][v]){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                int dist=arr[i][k]+arr[k][j]; 
                if(arr[i][j]>dist){
                    arr[i][j]=dist;
                }
            }
        }
    }
}

int main(){
    
    int graph[v][v] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
    

    floyid_warshall(graph);
    

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
