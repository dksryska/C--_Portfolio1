#include<iostream>
#include<fstream>
#include <string> 
using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signUP();
    void forgot();
}obj;

int main() {
    char choice;
    cout << "\n1- 로그인";
    cout << "\n2- 회원가입";
    cout << "\n3- 비밀번호 찾기";
    cout << "\n4- 나가기";
    cout << "\n번호를 선택해주세요. :: ";
    cin >> choice;

    switch (choice) {
    case '1':
        cin.ignore();
        obj.login();
        break;
    case '2':
        cin.ignore();
        obj.signUP();
        break;
    case '3':
        cin.ignore();
        obj.forgot();
        break;
    case '4':
        return 0;
        break;
    defualt:
        cout << "1번 ~ 4번으로 선택해주세요....!";
    }
}
void temp::signUP() {
    cout << "----------회원가입---------" << endl;
    cout << "\n아이디를 입력해주세요. :: ";
    getline(cin, userName);
    cout << "이메일 주소를 입력해주세여. :: ";
    getline(cin, Email);
    cout << "비밀번호를 입력해주세요. :: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}
void temp::login() {

    cout << "----------로그인---------" << endl;
    cout << "아이디 :: " << endl;
    getline(cin, searchName);
    cout << "비밀번호 :: " << endl;
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');
    while (!file.eof()) {
        if (userName == searchName) {
            if (password == searchPass) {
                cout << "\n로그인 성공l...!";
                cout << "\nUsername :: " << userName << endl;
                cout << "\nEmail :: " << Email << endl;
            }
            else {
                cout << "비밀번호를 다시 입력해주세요....!";
            }
        }
        else {
            cout << "로그인 정보를 찾을 수 없습니다.";
            cout << "\n비밀번호를 까먹으셨으면 비밀번호 찾기를 해주세요.\n";
            forgot();
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
    file.close();
}
void temp::forgot() {
    cout << "----------비밀번호 찾기---------" << endl;
    cout << "\n아이디를 입력해주세요. :: ";
    getline(cin, searchName);
    cout << "\n이메일을 입력해주세요. :: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');
    while (!file.eof()) {
        if (userName == searchName) {
            if (Email == searchEmail) {
                cout << "\n계정을 찾았습니다....!" << endl;
                cout << "비밀번호 :: " << password << endl;
            }
            else {
                cout << "찾을 수 없습니다....!\n";
                forgot();
            }
        }
        else {
            cout << "\n찾을 수 없습니다....!\n";
            forgot();
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
    file.close();
}