#include<iostream>
#include<vector>
#include <algorithm>
#include<unordered_map>
#include<set>
using namespace std;
bool solve(vector<int>&nums,vector<int>quantity,unordered_map<int,int>&customer,vector<int>unique_values){
    int i = 0;//for the set values
    int j = 0;//for the qunatity vector
    if(quantity.size()==0){
        return true;
    }
    while(true){
        if(customer[unique_values[i]]>=quantity[j]){
            customer[unique_values[i]] -= quantity[j];
            j++;
        }
        if(customer[unique_values[i]]<quantity[j]){
            i++;
        }
        if(j>=quantity.size()){
            return true;
        }
        if(i>=unique_values.size()){
            return false;
        }
    }
}
int main(){
    vector<int>nums = {1,2,2,2};
    vector<int>quantity = {};
    vector<int>unique_values;


    unordered_map<int,int>customer;
    for(int i=0;i<nums.size();i++){
        //unique_numbers.insert(nums[i]);
        if(customer[nums[i]]==0){
            unique_values.push_back(nums[i]);
            customer[nums[i]] = 1;

        }
        else{
            customer[nums[i]]++;
        }
    }

    bool isPossible = solve(nums,quantity,customer,unique_values);
    if(isPossible){
        cout<<"All Customer Happy"<<endl;
    }
    else{
        cout<<"Not satisfied";
    }
}