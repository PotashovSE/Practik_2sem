#include "plant.h"
#include <iostream>
#include <cmath>
#include <unistd.h>

using namespace std;
void vvod(int &k,int L[100], int &N, int &M)
{
    setlocale(LC_ALL, "Russian");
    {
    cout << "������� ����� ������� ����������:";
    cin>>k;
    cout << "������� ������ ������� ����������: ";
    for (int i=0; i<k; i++){
        cin>>L[i];
    }
    cout << "������� ����� ��������� ���������: ";
    cin>> N;
    cout << "������� ����� �������(������ ������): ";
    cin >> M;
    }
}


double srednee_znach (double X[100], int& N){
    double sum = 0;
    double sr_znach;
    for (int i = 0; i < N; i++){
        sum = sum + X[i];
    }
    sr_znach=sum/N;
    return sr_znach;
}



int main()
{
    Plant plant;
    plant_init(plant);
    string flag;
    double sr_znach, C;
    int k, N, M, L[100];
    double U[100], X[100];
    vvod(k, L, N, M);
    setlocale(LC_ALL, "Russian");{
    do{
            cout << "������� ������� ����� �����������: ";
            cin >> C;


           /* for(int j = 0; j<k; j++){
                if (L[j] == 7)
                    Umin[j]=
            }
*/




            for (int j=0; j<k; j++)
                cin>> U[j];
                //U[j]=U[0];
                for (int j=0; j<k; j++){
                plant_control(L[j], U[j], plant);}
            for(int i=0; i<N; i++){
                X[i]= plant_measure(M, plant);
                cout<<"X"<<i+1<<"="<<X[i]<<", ";
            }
            double sr_znach = srednee_znach (X, N);
        cout<<"������� �������� X="<< sr_znach<<'\n';
        cout<<"����������� ����������� ��������� ��� ��������?"<<'\n';
        cin >> flag;
    }
    while (flag == "yes");
}
return 0;
}
