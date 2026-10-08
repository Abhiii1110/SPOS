#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int ParallelMin(vector <int> vec){
    int min_val = vec[0];
    #pragma omp parallel for
    for (int i=1;i<vec.size();i++){
        if(vec[i]<min_val){
            min_val=vec[i];
        }
    }
    return min_val;
}

int ParallelMax(vector<int> vec){
    int max_val = vec[0];
    #pragma omp parallel for
    for (int i=1; i<vec.size();i++){
        if(vec[i]>max_val){
            max_val = vec[i];
        }
    }
    return max_val;
}

int ParallelSum(vector<int> vec){
    int sum = 0;
    #pragma omp parallel for
    for(int i=1;i<vec.size();i++){
        sum +=vec[i];
    }
    return sum;
}

float ParallelAvg(vector <int> vec){
    int sum = ParallelSum(vec);
    float avg = float(sum)/vec.size();
    return avg;
}

int main(){
    int n;
    cout<<"Enter the elements:-";
    cin>>n;

    vector<int> vec(n);
    cout<<"Enter the elements:-";
    for(int i=1;i<n;++i){
        cin>>vec[i];
    }

    int min_val = ParallelMin(vec);
    cout<<"Minimum value is:-"<< min_val <<endl;

    int max_val = ParallelMax(vec);
    cout<<"Maximum value is:-"<< max_val <<endl;

    int sum = ParallelSum(vec);
    cout<<"Sum of values are:-"<<sum<<endl;

    float avg = ParallelAvg(vec);
    cout<<"Average is:-"<<avg<<endl;

    return 0;
}
