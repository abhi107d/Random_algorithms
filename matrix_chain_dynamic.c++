#include <bits/stdc++.h>
#include<iostream>
#include<climits>
int mem[100][100];
int split[100][100];
int chain_multi(int s,int e,int arr[]){
    if(s==e)return 0;
    if(mem[s][e]!=-1)return mem[s][e];
    mem[s][e]=INT_MAX;
    for(int r=s;r<e;r++){
        int left=chain_multi(s,r,arr);
        int right=chain_multi(r+1,e,arr);
        int cur=arr[s-1]*arr[r]*arr[e];
        int total=left+right+cur;
        if(total<mem[s][e]){
            mem[s][e]=total;
            split[s][e]=r;
        }
            

    }
    return mem[s][e];
}




int main(){
    int arr[]={5,4,6,2,7};
    int l=sizeof(arr)/sizeof(arr[0]);
    memset(mem, -1, sizeof mem);
    memset(split, 0, sizeof split);
    int ret=chain_multi(1,l-1,arr);
    std::cout<<"output: "<<ret<<std::endl;
    for(int i=1;i<l;i++){
        for(int j=1;j<l;j++){
            std::cout<<mem[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
        
    std::cout<<std::endl;
 
    for(int i=1;i<l;i++){
        for(int j=1;j<l;j++){
            std::cout<<split[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
            
    return 0;
}
