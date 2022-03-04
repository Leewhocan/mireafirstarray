#include <iostream>
#include <algorithm>
#include <time.h>
#include <vector>
using namespace std;
int perevod(int x)//функция проверки налчия двух 2 в трочиной записи числа
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
    if (answer==2)//если две двойки то возвращаем 1 иначе 0
        return (1);
    else
        return (0);



}
int dobavlenie(int*massiv,int n,int*arrayk)
{
    for (int i=0;i<n+1;i++)//цикл копирующий элементы в новый файл до элемента который мы хотим вставить
    {
        massiv[i]=arrayk[i];
    }
    cout<<"Введите элемент который хотите вставить после элемента с двумя тройками=";
    cin>>massiv[n+1];//вставка нового элемента
    for (int i = n+1; i <11; i++)
    {
        massiv[i+1]=arrayk[i];//копируем дальше
    }
    cout<<"Массив с добавленным элементом:"<<endl;
    for (int i = 0; i <11 ; i++)//вывод
        cout<<massiv[i]<<" ";
    cout<<endl;



}//функция добавления элемента в массив(как статический так и динамический)
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

   int *no = new int[11 - k];//создаем новый массив с меньшим количетсовм элементов
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
            no[b-t]=n1[i];//передача значений в зависимотси от количетсва удаленных элементов
        }
    }
    cout<<"Массив без лишних элементов:"<<endl;
    for (int i = 0; i < 11-k; i++)
        cout<<no[i]<<" ";
    cout<<endl;



}//функция удаления ненужных элементов из массив

int dobavlenievec(vector <int>& b,int x)
{
    int f;
    cout<<"Введите число которое хотите вставить: "<<endl;
    cin>>f;
    vector <int>::iterator it;
    it = b.begin()+x+1;
    b.insert(it,f);//добавлние элемента
    cout<<"Вектор с новым элементом:"<<endl;
    for (int i=0;i<11;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;


}//функция добавления элемента в вектор
int udalenievec(vector <int>& b) //функция удаления ненужных элементов из вектора
{
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
            b.erase(it);//удаление элемента
        }


    }
    cout<<"Вектор без лишних элементов:"<<endl;
    for (int i=0;i<11-k;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
int generator(int*a)
{
    srand(time(0));
    cout<<"Сгенерированный массив:"<<endl;
    for (int i=0;i<10;i++)
    {
        a[i]=-1000+rand()%2000;//генерация числа и передача его в массив
        cout<<a[i]<<" ";

    }
    cout<<endl;

}//функция генерирующая массив
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
            cout<<"Индекс элемента с двумя двойками в троичном коде="<<i<<endl;
            return i;//если нащли элемент то возвращаем его индекс

        }


    }
    if (flag==0)
    {
        cout<<"Нет такого индекса "<<endl;
        return -1;//иначе возвращаем -1
    }



}//функция посика элемента в массиве
int generatorvec(vector <int>& b)
{
    srand(time(0));
    cout<<"Сгенерированный веткор:"<<endl;
    for (int i=0;i<10;i++)
    {
        b[i]=-1000+rand()%2000;//генерация числа и передача его в вектор
        cout<<b[i]<<" ";

    }
    cout<<endl;

}//функция генерирующая вектор
int poiskvec(vector <int>& b)//поиск элемента в векторе
{
    int flag=0;
    for (int i=0;i<10;i++)
    {
        int n=b[i];

        n = perevod(n);
        if (n==1)

        {
            flag=1;
            cout<<"Индекс элемента с двумя 2 в трочином коде="<<i<<endl;

            return i;//если нащли элемент то возвращаем его индекс

        }


    }
    if (flag==0)
    {

        return -1;//иначе возвращаем -1
    }
}//функция посика элемента в векторе

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
                cout<<"Образовлася вектор в котором ни один элемент не имеет 2 двойки в троичной системе:"<<endl;
            cout << endl << "Программа завершила работу успешно" << endl;
            break;
        }


    }
}








































