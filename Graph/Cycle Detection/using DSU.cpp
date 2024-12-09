#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &par , int x){
    if(par[x]==x) return x;
// path compression

  return par[x] = find(par,par[x]);


}


bool Union(vector<int> &par , vector<int> &rank , int a ,int b){
    a= find(par,a);
    b= find(par,b);
if(a == b) return true;
    if( rank[a] < rank [b] ){
        rank[a]++;
        par[b] = a;

    }else{
        rank[b]++;
        par[a]=b;
    }
    
return false;
}


 int main(){

int n, m;
// n is no of ele and m is no of queries 
cin >>n>>m;
vector<int > parent(n+1);

vector<int> rank (n+1,0);
for(int i =0 ;i<=n ;i++){
    parent[i]=i;
}
while(m--){
        int x ,y;
        cin>>x>>y;
       bool b = Union(parent, rank,x,y);
       if(b) std:: cout<<"cycle exist"<<endl;
    
}


    return 0 ;

 }