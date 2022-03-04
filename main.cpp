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
	int deers; // олени
	int wlvs; // волки
    int square, years, t; //square - качество экосистемы, years - количество месяцев наблюдения
public:
    int   results [3];
	// конструктор по умолчанию
	Ecosystem(){}
	~Ecosystem(){}
	void getEco() {
        cout << "Введите количество оленей и волков: ";
        cin >> deers >> wlvs;
		while (deers <= 0 || deers > INT || wlvs <= 0 || wlvs > INT){
            if (deers <= 0 || deers > INT) {
                cout << "Ошибка, введите другое значение оленей: ";
                cin >> deers;
            }
            if (wlvs <= 0 || wlvs > INT) {
                cout << "Ошибка, введите другое значение волков: ";
                cin >> wlvs;
            }
        }

        cout << "Оценка качества района обитания:" << endl;
        cout << "5 - Все отлично" << endl << "4 - Все хорошо" << endl << "3 - Средний уровень" << endl << "2 - Все плохо" << endl << "1 - Вряд ли здесь кто-то выживет" << endl;
        cout << "Ваш выбор: ";
        cin >> square;
        while (square <= 0 || square > 5){
            if (square <= 0 || square > 5) {
                cout << "ОШИБКА! Вы ввели некорректное значение. Введите новое значение только из представленных выше: ";
                cin >> square;
            }
        }

        cout << "Количество месяцев наблюдения за эко-системой: ";
        cin >> years;
        while (years <= 0 || years >= INT){
            if (years <= 0 || years >= INT) {
                cout << "Ошибка, введите другое значение: ";
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
            cout << "По прошествию " << years << " месяцев в живых осталось " << deers << " оленей и " << wlvs << " волков.";
        }
        else if ((deers <= 0) && (wlvs <= 0)){
            cout << "В эко-системе на " << years << " месяц произошел сбой. Оба вида погибли.";
            }
        else if (deers <= 0){
            cout << "К сожалении на " << years << " месяц погибли все олени, в живых остались только волки в количесвтве " << wlvs << " особей.";
        }
        else if (wlvs <= 0){
            cout << "К сожалении на " << years << " месяц погибли все волки, в живых остались только олени в количесвтве " << deers << " голов.";
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
