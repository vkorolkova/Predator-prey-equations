#include<iostream>
using namespace std;

const int  INT = 32766;

class Animals {
public:
	float child;
	float death;
    Animals(){};
    ~Animals(){};
};


class Ecosystem {
private:
	int deers; // �����
	int wlvs; // �����
    int square, years, t; //square - �������� ����������, years - ���������� ������� ����������
public:
    int   results [3];
	// ����������� �� ���������
	Ecosystem(){}
	~Ecosystem(){}
	void getEco() {
        cout << "������� ���������� ������ � ������: ";
        cin >> deers >> wlvs;
		while (deers <= 0 || deers > INT || wlvs <= 0 || wlvs > INT){
            if (deers <= 0 || deers > INT) {
                cout << "������, ������� ������ �������� ������: ";
                cin >> deers;
            }
            if (wlvs <= 0 || wlvs > INT) {
                cout << "������, ������� ������ �������� ������: ";
                cin >> wlvs;
            }
        }

        cout << "������ �������� ������ ��������:" << endl;
        cout << "5 - ��� �������" << endl << "4 - ��� ������" << endl << "3 - ������� �������" << endl << "2 - ��� �����" << endl << "1 - ���� �� ����� ���-�� �������" << endl;
        cout << "��� �����: ";
        cin >> square;
        while (square <= 0 || square > 5){
            if (square <= 0 || square > 5) {
                cout << "������! �� ����� ������������ ��������. ������� ����� �������� ������ �� �������������� ����: ";
                cin >> square;
            }
        }

        cout << "���������� ������� ���������� �� ���-��������: ";
        cin >> years;
        while (years <= 0 || years >= INT){
            if (years <= 0 || years >= INT) {
                cout << "������, ������� ������ ��������: ";
                cin >> years;
            }
        }
	}

    void chooseCoeffs (int square, Animals *D, Animals *W){
        switch (square){
            case 5:
                D->death = 0.001;
                D->child = 0.05;
                W->death = 0.04;
                W->child = 0.0006;
            break;

            case 4:
                D->death = 0.002;
                D->child = 0.05;
                W->death = 0.04;
                W->child = 0.0006;
            break;

            case 3:
                D->death = 0.002;
                D->child = 0.04;
                W->death = 0.04;
                W->child = 0.0006;
            break;

            case 2:
                D->death = 0.003;
                D->child = 0.03;
                W->death = 0.04;
                W->child = 0.0006;
            break;

            case 1:
                D->death = 0.004;
                D->child = 0.02;
                W->death = 0.04;
                W->child = 0.0006;
            break;
        }
    }

	void computeAnimals (){
        Animals D, W;
        Animals *k, *l;
        k = &D; l = &W;
        chooseCoeffs (square, k, l);
        emulateAnimals (deers, wlvs, years, k, l);

        deers =      results [0];
        wlvs  =      results [1];
        years = (int)results [2];

        if ((deers > 0) && (wlvs > 0) ){
            cout << "�� ���������� " << years << " ������� � ����� �������� " << deers << " ������ � " << wlvs << " ������.";
        }
        else if ((deers <= 0) && (wlvs <= 0)){
            cout << "� ���-������� �� " << years << " ����� ��������� ����. ��� ���� �������.";
            }
        else if (deers <= 0){
            cout << "� ��������� �� " << years << " ����� ������� ��� �����, � ����� �������� ������ ����� � ����������� " << wlvs << " ������.";
        }
        else if (wlvs <= 0){
            cout << "� ��������� �� " << years << " ����� ������� ��� �����, � ����� �������� ������ ����� � ����������� " << deers << " �����.";
        }
    }

    void  emulateAnimals (int deers, int wlvs, int years, Animals *D, Animals *W){
        int i = 0;
        while ((i != years) && (deers > 0) && (wlvs > 0)){
            if (wlvs == 1){
                deers = deers + ((D->child)*deers) - ((D->death)*deers*wlvs);
                wlvs  = (wlvs * W->death);
                i++;
            }

            if (deers == 1){
                deers = (deers * D->death);
                wlvs  = wlvs + (wlvs * (W->child) * deers) - ((W->death)*wlvs);
                i++;
            }

            else if (deers >= 2 && wlvs >= 2) {
                deers = deers + ((D->child)*deers) - ((D->death)*deers*wlvs);
                wlvs = wlvs + (wlvs * (W->child) * deers) - (W->death*wlvs);
                i++;
            }
            results [0] = deers;
            results [1] = wlvs;
            results [2] = i;
        }
    }
};

int main(){
    setlocale(LC_ALL, "Rus");

	Ecosystem ecosystem;
    ecosystem.getEco();
    ecosystem.computeAnimals();

    return 0;
}
