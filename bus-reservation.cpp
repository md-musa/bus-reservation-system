#include <Windows.h>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

void viewBusList();
void bookTicket();
void cancelBooking();
void busStatus();
void mainMenu();
void addNewBus();
void singleBusView();
void allBusView();
void login();
void printTitle();
void updateBusDetail();
void deleteBus();
const string ADMIN_EMAIL = "mohammad.musa706@gmail.com";
const string ADMIN_PASSWORD = "123456";

typedef struct Bus {
  int id;
  int seats;
  string name;
  string driverName;
} Bus;

int main() {
  login();
  mainMenu();
};

void mainMenu() {
p:
  system("cls");

  printTitle();
  cout << "\n\t 1. Add bus record";
  cout << "\n\t 2. View bus detail";
  cout << "\n\t 3. Delete bus detail";
  cout << "\n\t 4. Routes of buses";
  cout << "\n\t 5. Booking record";
  cout << "\n\t 6. Seat renew";
  cout << "\n\t 7. Search booking record";
  cout << "\n\t 8. Show all booking record";
  cout << "\n\t 9. Show all bus record";
  cout << "\n\n => Enter you choice: ";
  int choice;
  cin >> choice;

  switch (choice) {
    case 1:
      addNewBus();
      break;
    case 2:
      allBusView();
      break;

    default:
      break;
  }
  getch();
  goto p;
}

void login() {
p:
  system("cls");
  string email, password;
  cout << "\n\n\t\t_______Security are required______";
  cout << "\n\t Email: ";
  cin >> email;
  cout << "\n\t Password: ";
  for (int i = 0; i < 6; i++) {
    password += getch();
    cout << "*";
  }

  if (email == ADMIN_EMAIL && password == ADMIN_PASSWORD) {
    system("cls");
    cout << "\n\n\t\t\tLoading";
    for (int i = 0; i < 3; i++) {
      Sleep(500);
      cout << ".";
    }
  } else {
    cout << "\n\n\t\tYour email & password are wrong";
    cout << "\n\t\tPlease press any key to try again...";
    getch();
    goto p;
  }
}
void printTitle() {
  cout << "\n\t\t\t_________BUS MANAGEMENT SYSTEM_________\n";
}
void addNewBus() {
p:
  system("cls");
  printTitle();
  Bus newBus;

  cout << "\n Enter bus number: ";
  cin >> newBus.id;
  cout << "\n Enter number seats: ";
  cin >> newBus.seats;
  cout << "\n Enter bus's name: ";
  cin >> newBus.name;
  cout << "\n Enter driver name: ";
  cin >> newBus.driverName;

  buses[lastIndex++] = newBus;
  cout << "\n\n Do you want to add another bus (y, n): ";
  char ch = getch();
  if (ch == 'y' || ch == 'Y')
    goto p;
  else
    return;
};
void singleBusView() {
p:
  system("cls");
  printTitle();
  int busId;
  cout << "\tEnter bus id: ";
  cin >> busId;

  for (int i = 0; i < lastIndex; i++) {
    if (buses[i].id == busId) {
      cout << "\tID: " << buses[i].id << "\n";
      cout << "\tName: " << buses[i].name << "\n";
      cout << "\tSeats: " << buses[i].seats << "\n";
      cout << "\tDriver Name: " << buses[i].driverName << "\n";
    }
    return;
  }
  cout << "There is no bus with this id, please try again";
  getch();
  goto p;
}
void allBusView() {
  system("cls");
  printTitle();
  printf("ID\t\tBUS NAME\t\tSETS");
  cout << "_________________________________________________\n\n";

  for (int i = 0; i < lastIndex; i++) {
    cout << buses[i].id << "\t\t" << buses[i].name << "\t\t" << buses[i].seats
         << "\n";
  }
  cout << "_________________________________________________\n\n";
}
// void deleteBus() {
//   printTitle();
//   int busId;
//   cout << "\tEnter bus id to delete: ";
//   cin >> busId;

//   for (int i = 0; i < lastIndex; i++) {
//     if (buses[i].id == busId) }
// }
