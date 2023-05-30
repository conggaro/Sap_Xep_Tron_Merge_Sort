#include <iostream>
#include <vector>
using namespace std;

int main(){
    // fake vector v1 đã được sắp xếp
    vector<int> v1(5);
    v1 = {1, 8, 9, 10, 12};

    // fake vector v2 đã được sắp xếp
    vector<int> v2(2);
    v2 = {8, 11};

    int length_v3 = v1.size() + v2.size();
    vector<int> v3(length_v3);

    int index_v1 = 0;
    int index_v2 = 0;
    
    // cái index này là dành riêng cho v3
    int index = 0;

    // trường hợp 1: v1 và v2 có độ dài bằng nhau
    if(v1.size() == v2.size()){
        for(; index <= length_v3 - 1;){        
            // nếu v1[index_v1] <= v2[index_v2]
            if(v1[index_v1] <= v2[index_v2]){
                v3[index] = v1[index_v1];
                index ++;
                index_v1 ++;
            }else if(v1[index_v1] > v2[index_v2]){
                v3[index] = v2[index_v2];
                index ++;
                index_v2 ++;
            }      
        }
    }
    
    // trường hợp 2: v1 có độ dài lớn hơn v2
    if(v1.size() > v2.size()){
        for(; index <= length_v3 - 1;){        
            // nếu v1[index_v1] <= v2[index_v2]
            if(v1[index_v1] <= v2[index_v2]){
                v3[index] = v1[index_v1];
                index ++;
                index_v1 ++;
            }else if(v1[index_v1] > v2[index_v2]){
                v3[index] = v2[index_v2];
                index ++;
                index_v2 ++;
            }

            // for sẽ bị break khi tất cả phần tử ở v2 đã được
            // thêm hết vào v3
            if(index_v2 == v2.size()){
                break;
            }
        }

        // thêm những phần tử còn lại của v1 vào v3
        for(int i = index_v1; i < v1.size(); i++){
            v3[index] = v1[i];
            index ++;
        }
    }

    // trường hợp 3: v1 có độ dài bé hơn v2
    if(v1.size() < v2.size()){
        for(; index <= length_v3 - 1;){        
            // nếu v1[index_v1] <= v2[index_v2]
            if(v1[index_v1] <= v2[index_v2]){
                v3[index] = v1[index_v1];
                index ++;
                index_v1 ++;
            }else if(v1[index_v1] > v2[index_v2]){
                v3[index] = v2[index_v2];
                index ++;
                index_v2 ++;
            }

            // for sẽ bị break khi tất cả phần tử ở v1 đã được
            // thêm hết vào v3
            if(index_v1 == v1.size()){
                break;
            }
        }

        // thêm những phần tử còn lại của v2 vào v3
        for(int i = index_v2; i < v2.size(); i++){
            v3[index] = v2[i];
            index ++;
        }
    }

    cout << "Ket qua v3: " << endl;
    for(int i = 0; i < length_v3; i++){
        cout << v3[i] << endl;
    }

    return 0;
}