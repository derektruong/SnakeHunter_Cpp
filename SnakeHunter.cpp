#include<iostream>
#include<stdlib.h>
#include<ctime>
#include <iomanip>
#include<algorithm>
#include "myheader.h"
#define MAX 1000
using namespace std;
//Bien toan cuc
int soluong = 4;
float times = 0;
float speed1, speed2;
int kt_dungvatcan = 0;
//Prototypes
void paint_wall();
void DOT_RAN(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void paint_snake(int toadox[], int toadoy[], int x, int y);
void them(int a[], int x);
void xoa(int a[], int x);
void xoa_du_anh1(int x[], int y[]);
void xoaduanh2(int x, int y);
void playing_snake(int toadox[], int toadoy[], int& x, int& y, int& i, int& x_cu, int& y_cu, int& m, int& n, int& m_cu, int& n_cu, int& check, int& check_vatcan, unsigned int& diem, int& p, int& q, int& p_cu, int& q_cu);
bool checkhit(int toadox[], int toadoy[]);
void Menu();
//main
int main() {
    int toadox[MAX], toadoy[MAX];
    while (true) {
        system("cls");
        Menu();
        unsigned int diem = 0;
        srand(time(NULL));
        //Variables
        int i = 1;
        int x = 50, y = 13;//Toạ độ rắn
        int x_cu = x, y_cu = y;
        int m = 15, n = 15;//Toa do cua moi
        int m_cu = m, n_cu = n;
        int p = 54, q = 5; //Toa do vat can
        int p_cu = p, q_cu = q;
        int check = 0, check_vatcan = 0;//Kiểm tra điều hướng
        playing_snake(toadox, toadoy, x, y, i, x_cu, y_cu, m, n, m_cu, n_cu, check, check_vatcan, diem, p, q, p_cu, q_cu);
    }
    _getch();
    return 0;
}
void paint_wall() {
    ShowCur(false);
    for (int x = 0, y = 3; x < 110; x++) { //Vẽ tường trên
        gotoXY(x, y);
        cout << "*";
    }
    for (int x = 0, y = 28; x < 110; x++) { //Vẽ tường dưới
        gotoXY(x, y);
        cout << "*";
    }
    for (int x = 0, y = 3; y < 28; y++) { //Vẽ tường phải
        gotoXY(x, y);
        cout << "*";
    }
    for (int x = 110, y = 3; y < 28; y++) { //Vẽ tường trái
        gotoXY(x, y);
        cout << "*";
    }
}
void DOT_RAN(int toadox[], int toadoy[]) {
    ShowCur(false);
    int x = 50, y = 13;
    for (int i = 0; i < soluong; i++) {
        toadox[i] = x;
        toadoy[i] = y;
        x--;
    }
}
void ve_ran(int toadox[], int toadoy[]) {
    ShowCur(false);
    for (int i = 0; i < soluong; i++) {
        gotoXY(toadox[i], toadoy[i]);
        if (i == 0) cout << (char)238;
        else cout << "o";
    }
}
void paint_snake(int toadox[], int toadoy[], int x, int y) {
    ShowCur(false);
    //Thêm toạ độ mới vào mảng
    them(toadox, x); them(toadoy, y);
    //Xoá toạ độ mới vào mảng
    xoa(toadox, soluong - 1); xoa(toadoy, soluong - 1);
    ve_ran(toadox, toadoy);
}
void them(int a[], int x) {
    for (int i = soluong; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = x;
    soluong++;
}
void xoa(int a[], int x) {
    for (int i = x; i < soluong; i++) {
        a[i] = a[i + 1];
    }
    soluong--;
}
void xoa_du_anh1(int x[], int y[]) {
    for (int i = 0; i < soluong; i++) {
        gotoXY(x[i], y[i]);
        cout << " ";
    }
}
void xoaduanh2(int x, int y) {
    gotoXY(x, y);
    cout << " ";
}
void playing_snake(int toadox[], int toadoy[], int& x, int& y, int& i, int& x_cu, int& y_cu, int& m, int& n, int& m_cu, int& n_cu, int& check, int& check_vatcan, unsigned int& diem, int& p, int& q, int& p_cu, int& q_cu) {
    while (1) {
        system("cls");
        //x = 25, y = 12;
        SetColor(5);
        ShowCur(false);
        DOT_RAN(toadox, toadoy);
        ve_ran(toadox, toadoy);
        SetColor(11);
        gotoXY(0, 1);
        cout << "Maker: Truong Minh Duc";
        gotoXY(0, 2);
        SetColor(13);
        cout << "Diem cua ban: " << diem;
        gotoXY(92, 2);
        SetColor(14);
        cout << "Dieu khien: W A S D ";
        SetColor(7);
        gotoXY(43, 1);
        cout << "Nhan P de tam dung!! ";
        int count = 0;
        diem = 0; times = 0;
        soluong = 4;
        kt_dungvatcan = 0;
        while (1) {
            SetColor(6);
            paint_wall();
            SetColor(i);
            if (i == 15) i = 1;
            else i++;
            xoa_du_anh1(toadox, toadoy);
            paint_snake(toadox, toadoy, x, y);
            //
            if (_kbhit()) {
                char kitu = _getch();
                if (kitu == 'w') {
                    if (check != 0) check = 1;
                }
                else if (kitu == 's') {
                    if (check != 1) check = 0;
                }
                else if (kitu == 'a') {
                    if (check != 3) check = 2;
                }
                else if (kitu == 'd') {
                    if (check != 2) check = 3;
                }
                if (kitu == 'p') { gotoXY(200, 50); system("pause"); }
            }
            //Check điều hướng
            switch (check) {
            case 0: Sleep(speed1); times = times + speed1 / 1000.0; gotoXY(92, 1); cout << "Playing: " << (int)times << "s";  y++; break; //đi xuống
            case 1: Sleep(speed1); times = times + speed1 / 1000.0; gotoXY(92, 1); cout << "Playing: " << (int)times << "s"; y--; break; //đi lên
            case 2: Sleep(speed2); times = times + speed2 / 1000.0; gotoXY(92, 1); cout << "Playing: " << (int)times << "s"; x--; break; //đi qua trái
            case 3: Sleep(speed2); times = times + speed2 / 1000.0; gotoXY(92, 1); cout << "Playing: " << (int)times << "s"; x++; break; //đi qua trái
            }
            //Rắn chạm biên
            if (y == 28) { y = 4, check = 0; }
            else if (y == 3 && check != 0) { y = 27, check = 1; }
            else if (x == 0) { x = 109, check = 2; }
            else if (x == 109 && check != 2) { x = 1, check = 3; }
            //Tạo hình mồi
            if (x != m && y != n) {
                gotoXY(m_cu, n_cu);
                cout << (char)153;
            }
            else if (x == m && y == n) {
                srand(time(NULL));
                xoaduanh2(m_cu, n_cu);
                m = rand() % 106 + 4;
                n = rand() % 22 + 5;
                m_cu = m; n_cu = n;
                gotoXY(m, n);
                cout << (char)153;
                soluong++;
                gotoXY(0, 2);
                diem += 10;
                cout << "Diem cua ban: " << diem;
            }
            //Vật cản
            SetColor(12);
            xoaduanh2(p_cu, q_cu);
            gotoXY(p, q);
            p_cu = p, q_cu = q;
            cout << (char)215;
            switch (check_vatcan) {
            case 0: q++; break; //đi xuống
            case 1: q--; break; //đi lên
            }
            if (q == 5) { check_vatcan = 0; }
            else if (q == 22) { check_vatcan = 1; }
            //Kiểm tra rắn đụng vật cản
            for (int u = 0; u < soluong; u++) {
                if (toadox[u] == 54 && q_cu == toadoy[u] && count > 1) { kt_dungvatcan = 1; count++; break; }
                else continue;
            }
            if (kt_dungvatcan == 1) { break; }
            //
            if (checkhit(toadox, toadoy) == true && count > 1) break;
            count++;
        }
        system("cls");
        SetColor(2);
        paint_wall();
        gotoXY(49, 11);
        SetColor(12);
        cout << "Game Over!!\n";
        gotoXY(46, 13);
        cout << "Diem cua ban la "<<diem<<endl;
        char choose;
        gotoXY(41, 15);
        cout << "Nhan 'x' de tro ve Menu->Enter: "; cin >> choose;
        if (choose == 'x') break;
    }
}
bool checkhit(int toadox[], int toadoy[]) {
    for (int i = 1; i < soluong; i++) {
        if (toadox[0] == toadox[i] && toadoy[0] == toadoy[i]) return true;
    }
}
void Menu() {
    ShowCur(false);
    SetColor(10);
    for (int x = 37, y = 10; x < 70; x++) {
        gotoXY(x, y);
        cout << "^";
    }
    for (int x = 37, y = 18; x < 70; x++) {
        gotoXY(x, y);
        cout << "^";
    }
    for (int x = 37, y = 10; y < 18; y++) {
        gotoXY(x, y);
        cout << "<";
    }
    for (int x = 70, y = 10; y < 18; y++) {
        gotoXY(x, y);
        cout << ">";
    }
    gotoXY(45, 12);
    SetColor(14);
    cout << "GAME SNAKE HUNTER ";
    SetColor(11);
    gotoXY(43, 14);
    cout << "Made By Derek Truong!! ";
    SetColor(13);
    gotoXY(39, 16);
    int chon;
    cout << "Chon Level(1,2,3,4,5)->Enter:"; cin >> chon;
    switch (chon) {
    case 1: speed1 = 115; speed2 = 70; break;
    case 2: speed1 = 105; speed2 = 60; break;
    case 3: speed1 = 95; speed2 = 50; break;
    case 4: speed1 = 85; speed2 = 40; break;
    case 5: speed1 = 70; speed2 = 25; break;
    }
}