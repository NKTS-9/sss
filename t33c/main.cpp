#include <iostream>
#include <Windows.h>

using namespace std;

class Coffeem {
private:
    bool pwr_;
    bool cof_;
    bool wt_;
    bool wc_;

public:
 Coffeem ()
 {
     pwr_= 0;
     cof_ = 0;
     wt_ = 0;
     wc_ = 0;
 }
void change_pwr(){
 pwr_= !pwr_;
 if(!pwr_)
 {
     cof_ =0;
     wt_  =0;
     wc_  =0;
 }
 }

void change_cof(){
if (pwr_ = 1) cof_= !cof_ ;
else cof_ = 0;
 }

 void change_wt(){
     wc_ = 0;
if (pwr_ = 1) wt_= !wt_;
else wt_ = 0;
 }

 void change_wc(){
     wt_ = 0;
if (pwr_ = 1) wc_= !wc_;
else wc_ = 0;
 }

 void change_exit(){
 pwr_= 0;
     cof_=0;
     wt_=0;
     wc_ =0;
cout << "Вы отключили устройство" << endl;
 }
 void status() {
     cout<< "вкл/вкл" << "\t" << "кофе" << "\t" << "вода" << "\t" << "сливки" << endl;
 cout<< pwr_ << "\t" << cof_ << "\t" << wt_ << "\t" << wc_ << endl;}
    };
int main()
{SetConsoleCP(1251);
SetConsoleOutputCP(1251);

   Coffeem fds;

cout << "Меню:" << endl << "Включить -> 1" << endl << "Эспрессо -> 2" << endl
       << "Американо -> 3" << endl << "Кофе по-венски -> 4" << endl << "Выход -> 5" << endl << endl;

       cout << "Свойство выключино ->0" << endl << "Свойство активировано -> 1" << endl << endl;

   while(1)
   {
    fds.status();
       int ch;
        cout << "Введите номер команды ->";cin >> ch;
       switch(ch) {
       case 1: fds.change_pwr(); break;
       case 2: fds.change_cof(); break;
       case 3: fds.change_wt(); break;
       case 4: fds.change_wc(); break;
       case 5: fds.change_exit(); break;
       }
   }
    return 0;}

