#include<iostream>
#include<climits>
int chain_multi(int s,int e,int arr[]){
    if(s==e)return 0;
    int min=INT_MAX;
    for(int r=s;r<e;r++){
        int left=chain_multi(s,r,arr);
        int right=chain_multi(r+1,e,arr);
        int cur=arr[s-1]*arr[r]*arr[e];
        int total=left+right+cur;
        if(total<min)min=total;

    }
    return min;
}




int main(){
    int arr[]={1,2,3,4,3};
    int l=sizeof(arr)/sizeof(arr[0]);
    int ret=chain_multi(1,l-1,arr);
    std::cout<<"output: "<<ret;
    return 0;
}
