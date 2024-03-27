#include<iostream>
#include<vector>

using namespace std; 

class solution{
    public:
        int remove(vector<int>& nums,int val){
            int count=0;
            int indx=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=val){
                    nums[indx++]=nums[i];
                    count++;
                }
            }
            return count;

        }
};


int main(){
    solution sol;
    vector<int> nums={3,2,2,3};
    int val=3;

    int count=sol.remove(nums,val);

    for(int num : nums){
        cout<<num<<" ";
    }
    cout<<"\n";
    cout<<count<<" ";


    return 0;


}
