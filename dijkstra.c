#include<stdio.h>

int l=0;
int n=9;
int indx=0;

void enque(int que[10][2],int to,int w){
    for(int i=0;i<=l;i++){
        if(que[i][1]>w){
            for(int j=l;j>=i;j--){
                que[j+1][0]=que[j][0];
                que[j+1][1]=que[j][1];
            }
            que[i][0]=to;
            que[i][1]=w;
            l++;
            return;
        }
    }
    que[l][0]=to;
    que[l][1]=w;
    l++;
    return;
}
int present(int idx,int que[10][2]){
    for(int i=0;i<=l;i++){
        if(que[i][0]==idx)return i;
    }
    return -1;

}
void popque(int que[10][2]){
    for(int i=0;i<=l;i++){
        que[i][0]=que[i+1][0];
        que[i][1]=que[i+1][1];
    }
    l--;
}

void dijkstra(int start,int cw,int graph[10][10],int path[10][2],int visited[10],int que[10][2]){
    visited[start]=1;
    for(int i=0;i<n;i++){
        if(visited[i]!=1 && graph[start][i]!=0){
            int pres=present(i,que);
            if(pres==-1)enque(que,i,graph[start][i]+cw);
            else if(que[pres][1]>graph[start][i]+cw){
                    que[pres][1]=graph[start][i]+cw;
            }

        }
    }
    
    int next=que[0][0];
    int w=que[0][1];
    path[indx][0]=next;
    path[indx][1]=w;
    indx++;
    popque(que);
    if(l==-1)return;
    dijkstra(next,w,graph,path,visited,que);

}

        





int main(){

    int graph[10][10]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

    int path[10][2];
    int que[10][2]={0};
    int visited[10]={0};
    int start=0;

    path[indx][0]=start;
    path[indx][1]=0;
    indx++;

    dijkstra(start,0,graph,path,visited,que);
    for(int i=0;i<n;i++){
        printf("[%d %d]--->  ",path[i][0],path[i][1]);
    }

     return 0;
}
