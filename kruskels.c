#include<stdlib.h>
#include<stdio.h>

int find(int a,int* b){
    if(b[a]==-1)return a;
    b[a]=find(b[a],b);
    return b[a];
}
int _union(int a,int b,int* arr,int* he){
    int fa=find(a,arr);
    int fb=find(b,arr);

    if(fa==fb)return 0;
    if(he[fa]>he[fb])arr[fb]=fa;
    else if(he[fa]<he[fb])arr[fa]=fb;
    else {
        he[fa]=he[fa]+1;
        arr[fb]=fa;
    }

    return 1;
}
void sort(int ** edges,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(edges[i][2]>edges[j][2]){
                int* temp=edges[i];
                edges[i]=edges[j];
                edges[j]=temp;
            }
        }
    }
}

int kruskals(int** edges,int* arr,int* height,int** graph,int n,int vertics){
    sort(edges,n);
    int edge=0;
    for(int i=0;i<n;i++){
        if(_union(edges[i][0],edges[i][1],arr,height)){
               graph[edges[i][0]][edges[i][1]]=edges[i][2];
               edge++;
        }
    }
    if(edge==vertics-1)return 1;
    return 0;

}
void add_edge(int** edges,int a,int b,int w,int* indx){
    edges[*indx][0]=a;
    edges[*indx][1]=b;
    edges[*indx][2]=w;
    *indx=*indx+1;
}

int main(){
    int n=10; //total number of edges
    int v=6;  //total number of vertices
    int arr[100]={[0 ... 99]=-1};
    int height[100]={0};
    int ** edges=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)edges[i]=malloc(3*sizeof(int));
    int indx=0;
    add_edge(edges,0,1,1,&indx);
    add_edge(edges,1,3,1,&indx);
    add_edge(edges,2,4,1,&indx);   
    add_edge(edges,0,2,2,&indx);
    add_edge(edges,2,3,2,&indx);
    add_edge(edges,3,4,2,&indx);
    add_edge(edges,1,2,3,&indx);
    add_edge(edges,1,4,3,&indx);   
    add_edge(edges,4,5,3,&indx);
    add_edge(edges,3,5,9,&indx);
   
    int ** graph=malloc(v*sizeof(int*));
    for(int i=0;i<v;i++)graph[i]=malloc(v*sizeof(int));


    int result=kruskals(edges,arr,height,graph,n,v);
    if(result){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                printf("%d ",graph[i][j]);
            }
            printf("\n");
        }
    }
    else printf("falied to add all vertices");


    return 0;    
} 
