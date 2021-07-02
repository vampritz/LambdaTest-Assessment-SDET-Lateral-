#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string,long>a,pair<string,long>b){
    if(a.second<b.second)return true;
    return false;
}
void solve(string input){
 
    vector<pair<string,long>>output;
    int count=0;
    string key;
    string colon = "'";
    for(int i=0;i<input.size();i++){
        key+=input[i];
        if(input[i]==colon[0])count++;
        if(input[i]==colon[0] && count%2 ==0){
            long value=0;
            long index=i+2;
            
            while(index<input.size() && input[index]!=','){
                if(isdigit(input[index]))
                value=value*10+input[index]-'0';
                index++;
                
            }
           
            output.push_back({key,value});
           key="";
           i=index;
        }
    }
    
    //printing sorted output;
     sort(output.begin(),output.end(),cmp);
     for(pair<string,long> p :output){
         cout<<p.first<<","<<p.second<<endl;
     }
}
int main() {
    string input ="samsung,'OEM Samsung Washing Machine Pulsator Washplate Cap Shipped With WA48J7700AW, WA48J7700AW/A2, WA48J7700AW/AA',20916,samsung,'OEM Samsung Chrome Washing Machine Washplate Pulsator Cap Shipped With WA52M7750AV,WA52M7750AV/A4, WA52M7750AW, WA52M7750AW/A4',91995,samsung, 'SAMSUNG Washing Machine Spring Hanger, DC61-01257M', 22970,samsung,'Samsung DC97-17022B Assy Detergent',32959,samsung,'Samsung DC66-00470A DAMPER SHOCK',29981,samsung,'DC64-00519D Samsung Washing Machine Door Lock Washer DryerDishwashe -MP#GH4498 349Y49HBRG9109150',52000,samsung,'Samsung DC97-16991A Assembly Filter',13000";
    solve(input);
}