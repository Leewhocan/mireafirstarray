#include <iostream>


#include <algorithm>

#include <time.h>
#include <vector>
using namespace std;
int perevod(int x)
{

    int answer=0;
    while (x>0)
    {
        if (x%3==2)
        {
            answer+=1;
        }
        if (answer>2)
        {
            break;
        }

        x=x/3;


    };
    if (answer==2)
        return (1);
    else
        return (0);



}

int dobavlenie(int*massiv,int n,int*arrayk)
{
    for (int i=0;i<n;i++)
    {
        massiv[i]=arrayk[i];
    }
    cout<<"Введите элемент который хотите вставить=";
    cin>>massiv[n];
    for (int i = n; i <11; i++)
    {
        massiv[i+1]=arrayk[i];
    }
    for (int i = 0; i <11 ; i++)
        cout<<massiv[i]<<endl;



}
int udalenie(int*n1)
{

    int k = 0;
    int t = 0;

    for (int i = 0; i < 11; i++)
    {


        int f = n1[i];
        f = perevod(f);
        if (f == 1)
        {
            k+=1;
            cout<<"Имеет две двойки в трочиной системе:" << n1[i] << endl;



        }

    }

   int *no = new int[11 - k];
    for (int i = 0; i < 11; i++)
    {
        int b = i;
        int f = n1[i];
        f = perevod(f);
        if (f == 1)
        {
            t=t+1;
        }
        else if (f==0)
        {
            no[b-t]=n1[i];
        }
    }
    for (int i = 0; i < 11-k; i++)
        cout<<no[i]<<endl;



}

int dobavlenievec(vector <int>& b,int x)
{
    int f;
    cout<<"Введите число которое хотите вставить: "<<endl;
    cin>>f;
    vector <int>::iterator it;
    it = b.begin()+x;
    b.insert(it,f);


}
int udalenievec(vector <int>& b) {
    int k=0;
    for (int i = 0; i < 11; i++)
    {


        int f = b[i];
        f = perevod(f);
        vector<int>::iterator it;
        if (f == 1)
        {
            cout<<"Удалаяем:"<<b[i]<<endl;
            k+=1;
            it = b.begin() + i;
            b.erase(it);
        }


    }
    for (int i=0;i<11-k;i++)
    {
        cout<<b[i]<<" ";
    }
}





int generator(int*a)
{
    srand(time(0));
    for (int i=0;i<10;i++)
    {
        a[i]=-1000+rand()%2000;
        cout<<a[i]<<" ";

    }

}
int poisk(int*a)
{
    int flag=0;
    for (int i=0;i<10;i++)
    {
        int n=a[i];
        n = perevod(n);
        if (n==1)

        {
            flag=1;
            cout<<"Индекс "<<i<<endl;
            return i;

        }


    }
    if (flag==0)
    {
        cout<<"Нет такого индекса "<<endl;
        return -1;
    }



}
int generatorvec(vector <int>& b)
{
    srand(time(0));
    for (int i=0;i<10;i++)
    {
        b[i]=-1000+rand()%2000;
        cout<<b[i]<<" ";

    }

}
int poiskvec(vector <int>& b)
{
    int flag=0;
    for (int i=0;i<10;i++)
    {
        int n=b[i];

        n = perevod(n);
        if (n==1)

        {
            flag=1;
            cout<<"Индекс="<<i<<endl;

            return i;

        }


    }
    if (flag==0)
    {

        return -1;
    }
}

int main() {
    setlocale(LC_ALL, "");
    cout << "Практическая работа №1 Мишин Никита " << endl;
    cout << "Выберите массив:" << endl << "1 - статический" << endl << "2 - динамический" << endl << "3 - вектор"
         << endl;
    int mode, size;
    do {
        cin >> mode;
        if (mode < 1 || mode > 3) cout << "Такого режима нет. Введите число от 1 до 3: ";
    } while (mode < 1 || mode > 3);
    switch (mode) {
        case 1: {
            int array[10];
            int newarray[10];
            generator(array);
            int x = poisk(array);
            if (x != -1) {
                dobavlenie(newarray, x, array);
                udalenie(newarray);
            }
            if (x==-1)
                cout<<"Образовлася массив в котором ни один элемент не имеет 2 двойки в троичной системе:"<<endl;
            cout << endl << "Программа завершила работу успешно" << endl;
            break;

        }
        case 2: {
            int *massiv = new int[10];
            int *newmassiv = new int[10];
            generator(massiv);
            int f = poisk(massiv);
            if (f != -1) {
                dobavlenie(newmassiv, f, massiv);
                udalenie(newmassiv);
            }
            if (f==-1)
                cout<<"Образовлася массив в котором ни один элемент не имеет 2 двойки в троичной системе:"<<endl;
            cout << endl << "Программа завершила работу успешно" << endl;
            break;


        }
        case 3: {
            vector<int> ivecor(10);
            generatorvec(ivecor);
            int b = poiskvec(ivecor);
            if (b != -1)
            {
                dobavlenievec(ivecor, b);
                udalenievec(ivecor);
            }
            if (b==-1)
                cout<<"Образовлася массив в котором ни один элемент не имеет 2 двойки в троичной системе:"<<endl;
            cout << endl << "Программа завершила работу успешно" << endl;
            break;
        }


    }
}








































