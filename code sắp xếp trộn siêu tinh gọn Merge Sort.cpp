// Yêu cầu:
// 1. cho 2 dãy số thực X và Y
// 2. dãy X có n phần tử
// 3. dãy Y có m phần tử

// 4. nhập n
// 5. nhập m

// 6. nhập dãy X
// 7. nhập dãy Y

// 8. sắp xếp 2 dãy X và Y theo chiều không giảm
// --> chiều không giảm là "CHIỀU TĂNG"
// --> tức là nó bảo mình sắp xếp tăng dần

// 9. nó đòi ghép nối 2 vector
// để tạo ra vector Z có n + m phần tử
// dãy Z được sắp xếp theo chiều tăng dần
// Chú ý: nó không cho nối X và Z, rồi sắp xếp để được Z

// nó bắt làm cái trò như sắp xếp trộn

#include <iostream>
#include <vector>
using namespace std;

// hàm sắp xếp vector
void SapXep(vector<float> &v){
    float temp = 0;
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if(v[i] > v[j]){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }        
    }
}

// hàm sắp xếp trộn (merge sort)
void SapXepTron_MergeSort(vector<float> &v1, vector<float> &v2, vector<float> &v3){
    // tạo chỉ mục index cho v1, v2, v3
    int index_v1 = 0;
    int index_v2 = 0;
    int index_v3 = 0;

    int length_v3 = v1.size() + v2.size();   

    // code thực hiện công việc
    for (int i = 0; i < length_v3; i++)
    {
        // index_v1 == v1.size() thì tức là v1 đã hết phần tử
        // index_v1 == v1.size() - 1 thì mới còn phần tử
        if(index_v1 == v1.size())
        {
            break;
        }else if(index_v2 == v2.size()){
            break;
        }
            
        if(v1[index_v1] <= v2[index_v2]){
            v3.push_back(v1[index_v1]);
            index_v1 ++;
            index_v3 ++;
        }else if(v1[index_v1] > v2[index_v2]){
            v3.push_back(v2[index_v2]);
            index_v2 ++;
            index_v3 ++;
        }
    }        

    if(index_v1 == v1.size())
    {
        for (int i = index_v2; i < v2.size(); i++)
        {
            v3.push_back(v2[i]);
        }      
    }else if(index_v2 == v2.size()){
        for (int i = index_v1; i < v1.size(); i++)
        {
            v3.push_back(v1[i]);
        }
    }
}

int main(){
    cout << "Nhap so phan tu cho day X: ";
    int n;
    cin >> n;

    cout << "Nhap so phan tu cho day Y: ";
    int m;
    cin >> m;

    vector<float> X(n);
    vector<float> Y(m);

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap X[" << i << "] = ";
        cin >> X[i];
    }
    
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Nhap Y[" << i << "] = ";
        cin >> Y[i];
    }

    SapXep(X);
    SapXep(Y);

    cout << "\nday X sau khi sap xep la: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "X[" << i << "] = ";
        cout << X[i] << endl;
    }

    cout << "\nday Y sau khi sap xep la: \n";
    for (int i = 0; i < m; i++)
    {
        cout << "Y[" << i << "] = ";
        cout << Y[i] << endl;
    }

    vector<float> Z;

    SapXepTron_MergeSort(X, Y, Z);

    cout << "\nday Z la:\n";
    for(int i = 0; i < Z.size(); i++){
        cout << "Z[" << i << "] = ";
        cout << Z[i] << endl;
    }

    return 0;
}

// sắp xếp trộn phiên bản xịn
// tác giả: Nguyễn Chí Công