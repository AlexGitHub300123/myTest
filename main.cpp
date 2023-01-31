#include "Curves.h"
#include <vector> // контейнер
#include <iostream> // cout
#include <cstdlib> // rnd
#include <ctime> // для рандома
#include <memory>
//#include <cmath> // для синусов
//#include <typeinfo> // для typeid
#include <algorithm> //для sort
#define M_PI 3.14159265358979323846
using namespace std;

bool sort_object_r(shared_ptr<TCircle> i, shared_ptr<TCircle> j)  //компаратор для sort
	{
        double r = i->GetR();
        double R = j->GetR();
	    return (r<R);
    }

double SumR(vector <shared_ptr<TCircle>> CircleVec, unsigned int v) //сумма радиусов
    {
        int  sum =0;
        for(unsigned int i = 0; i < v; i++)
        {
            sum+=CircleVec[i]->GetR();
        }
        return sum;
    }
//----------------------------------------------------------------------------------------------------

template <typename T>
shared_ptr<TPoint> create()
{
    return make_shared<T>();
}


int main()
{
    srand(time(0)); //random
    double T = M_PI/4; // шаг в радианах
    const int q = 30; //кол-во кривых в 1ом контейнере

    vector <shared_ptr<TPoint>> Vec;   //1st vector
    for(int i = 0; i < q; i++)
    {
        using CreateT = shared_ptr<TPoint>();
         CreateT* select[] = { &create<TCircle>, &create<TEllipse>, &create<THelix> };
        int r = rand()%3;
        Vec.push_back(select[r]());
    }

    for(int i = 0; i < q; i++)
    {
        Vec[i]->PrintNullPoint();
        Vec[i]->PrintR();
        Vec[i]->SetXYZT(T);
        Vec[i]->PrintPoint();
      //  TPoint *point = Vec[i].get();
       // cout << point << " <--- ptr adress" << endl;
        cout << "___________________________________________" << endl;
    }

    vector <shared_ptr<TCircle>> CircleVec;  //2nd vector
    for(int i = 0; i < q; i++)
    {
        auto ptr = dynamic_pointer_cast<TCircle>(Vec[i]);
    if (ptr)
    {
        CircleVec.push_back(ptr);
    }
    }
    Vec.clear(); Vec.shrink_to_fit(); // очистим вектор

    sort(CircleVec.begin(), CircleVec.end(), sort_object_r);
    unsigned int v = CircleVec.size();
    for( unsigned int i = 0; i < v; i++) //
    {
        cout << "*******************************************" << endl;
        CircleVec[i]->PrintNullPoint();
        CircleVec[i]->PrintR();
        CircleVec[i]->SetXYZT(T);
        CircleVec[i]->PrintPoint();
        cout << CircleVec[i] << endl;
        cout << "*******************************************" << endl;
    }

    cout << endl<< endl<<  "Sum of radiuses of circles in second vector: " << SumR(CircleVec, v) << endl<< endl<< endl<< endl;
    CircleVec.clear(); CircleVec.shrink_to_fit();
    system("pause");
    return 0;
}
