#include<iostream>
#include<vector>

using namespace std;

template<class T>
T getscaler(vector<T> &v1,vector<T> &v2){
     T total = 0;
    for(int i=0;i<3;i++){
        total += v1[i]*v2[i];
    }
    return total;
};
int main(){
    vector<int> vect ={1,2,3};
    vector<int> vect1 ={2,3,4};
    cout<<"scaler product is: "<<getscaler(vect,vect1)<<endl;
    vector<float> vect2 ={1.1,2.1,3.1};
    vector<float> vect3 ={1.1,4.2,5.2};
    cout<<"scaler product is: "<<getscaler(vect2,vect3)<<endl;

    return 0;
}
