//
//  main.cpp
//  子集和的目标值
//
//  Created by HTC on 2018/5/14.
//  Copyright © 2018年 HTC. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    int n,t;
    long long temp=0;
    long long re=2147483647;
    long long in[110];
    cin>>n;
    cin>>t;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    sort(in, in+n);
    long long *right;
    long long *left;
    long long *first;
    long long *last;
    right=in+n-1;
    left=in;
    while(*right>t){
        --right;
        re = *(right+1)-t;
    }
    if(right<left){
        cout<<re<<endl;
        return 0;
    }

    while (temp<t&&left<=right) {
        temp+=*left;
        ++left;
    }
    --left;
    if(temp>t){
        temp -= *left;
        --left;
    }

    if(t-temp<re) re=t-temp;
    if(left==right){
        cout<<re<<endl;
        return 0;
    }
    
    first = in;
    while (left<=right) {
        last = left-1;
        temp = *left;
        while (last>=first) {
            temp += *last;
            if(temp>t){
                re = min(re,temp-t);
                temp -= *last;
                re = min(re,t-temp);
            }
            --last;
        }
        re = min(re,t-temp);
        ++left;
    }
    
    cout<<re<<endl;
    
    return 0;
}
