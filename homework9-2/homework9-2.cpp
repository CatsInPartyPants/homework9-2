#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

template <typename T, typename T2> //show array
void showArr(T arr[], T2 size)
{
    for (T2 i = 0; i < size; i++)
        cout << arr[i] << endl;
    cout << endl;
}

void makingArray(int* arr, int size);

int main()
{
    setlocale(LC_ALL, "");
    //task 1
    
    int first_arr[10];
    int second_arr[5];
    int third_arr[5];
    makingArray(first_arr, 10);
    for (int i = 0, j =0; i < 10; i++)
    {
        if (i < 5)
        {
            second_arr[i] = first_arr[i];
        }
        else 
        {
            third_arr[j] = first_arr[i];
            j++;
        }
    }
    showArr(second_arr, 5);
    showArr(third_arr, 5);
    

    //task 2
    
    int arr1task2[10];
    int arr2task2[10];
    int arrResult[10];
    makingArray(arr1task2, 10);
    makingArray(arr2task2, 10);
    for (int i = 0; i < 10; i++)
    {
        arrResult[i] = arr1task2[i] + arr2task2[i];
    }
    showArr(arr1task2, 10);
    showArr(arr2task2, 10);

    showArr(arrResult, 10);
    

    //task 3

    
    double arrExpenses[7];
    double weekly_expenses=0;
    int days_more_then_100=0;
    for (int i = 0; i < 7; i++)
    {
        cout << "Введите расходы за " << i + 1 << " день ->";
        cin >> arrExpenses[i];
        system("CLS");

    }
    cout << "Дни, в которых расходы превысили $100: \n";
    for (int i = 0; i < 7; i++)
    {
        weekly_expenses += arrExpenses[i];
        if (arrExpenses[i] > 100)
        {
            days_more_then_100++;
            switch (i)
            {
            case 0: 
                cout << "Понедельник ";
                break;
            case 1:
                cout << "Вторник ";
                break;
            case 2:
                cout << "Среда ";
                break;
            case 3:
                cout << "Четверг ";
                break;
            case 4:
                cout << "Пятница ";
                break;
            case 5:
                cout << "Суббота ";
                break;
            case 6:
                cout << "Воскресение ";
                break;            
            }
        }
    }
    cout << endl;
    cout << "Общие расходы за неделю составили: " << weekly_expenses << endl;
    cout << "Срений расход денежных средств в день составил: " << weekly_expenses / 7 << endl;
    cout << "Количество дней с расходами превышающими $100: " << days_more_then_100 << endl;
    

    //task 4

    double exchange_rate[12]{ 1.19, 1.17, 1.15, 1.16, 1.17, 1.18, 1.19, 1.20, 1.17, 1.11, 1.15, 1.13 };
    double procents[12]{1.5, 5, 7, 3, 10, 5, 5, 10.5, 11, 12, 10, 10};
    double avalible_for_withdraw[12];
    double money_on_deposit[12];
    double deposit;
    int month;
    cout << "Сколько евро на вашем допозитном счете было в начале периода?\n";
    cin >> deposit;
    for (int i = 0; i < 12; i++)
    {
        if (i == 0) {
            money_on_deposit[i] = deposit + (procents[i] / 100);
        }
        else {
            money_on_deposit[i] = money_on_deposit[i - 1] + money_on_deposit[i - 1] * (procents[i]/100);
        }
        
    }

    for (int i = 0; i < 12; i++)
    {
        if (i == 0)
        {
            avalible_for_withdraw[i] = deposit + (procents[i]/100) - deposit;
        }else
        {   
            avalible_for_withdraw[i] = money_on_deposit[i] - money_on_deposit[i - 1];
        }        
    }
    showArr(avalible_for_withdraw, 12);
    cout << "Введите месяц, за который вы хотите проверить количество денежных средств для снятия:\n";
    cin >> month;
    month--;
    if ((avalible_for_withdraw[month] * exchange_rate[month]) > 500)
    {
        cout << "В указанном месяце вы могли снять $" << (avalible_for_withdraw[month] * exchange_rate[month]) / 2 << endl;

    }

}

void makingArray(int* arr, int size)
{
    srand(time(NULL));
    Sleep(1500); // задержка чтобы значение в массивах отличались
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}