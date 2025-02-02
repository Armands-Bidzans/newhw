#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const int MAX_CARS = 100;
const int MAX_CLIENTS = 100;
const int MAX_COLORS = 20; // Максимальное количество цветов

struct Car {
    string brand, model, color, number;
    int year;
};

struct Client {
    string name, middle, surname;
    string rentDate;
    double price;
};

Car cars[MAX_CARS];
Client clients[MAX_CLIENTS];
int carCount = 0, clientCount = 0;

string colors[MAX_COLORS]; // Массив для хранения цветов
int colorCount = 0; // Количество загруженных цветов

void saveData() {
    // Запись автомобилей в cars.txt
    ofstream ofs("cars.txt");
    for (int i = 0; i < carCount; i++) {
        ofs << cars[i].brand << " " << cars[i].model << " " << cars[i].year << " "
            << cars[i].color << " " << cars[i].number << "\n";
    }
    // Запись клиентов в clients.txt
    ofstream ofs2("clients.txt");
    for (int i = 0; i < clientCount; i++) {
        ofs2 << clients[i].name << " " << clients[i].middle << " " << clients[i].surname << " "
            << clients[i].rentDate << " " << clients[i].price << "\n";
    }
}

void loadData() {
    // Загрузка автомобилей из cars.txt
    ifstream ifs("cars.txt");
    while (carCount < MAX_CARS && ifs >> cars[carCount].brand >> cars[carCount].model
        >> cars[carCount].year >> cars[carCount].color >> cars[carCount].number) {
        carCount++;
    }
    // Загрузка клиентов из clients.txt
    ifstream ifs2("clients.txt");
    while (clientCount < MAX_CLIENTS && ifs2 >> clients[clientCount].name >> clients[clientCount].middle
        >> clients[clientCount].surname >> clients[clientCount].rentDate >> clients[clientCount].price) {
        clientCount++;
    }
    // Загрузка цветов из color.txt
    ifstream ifs3("color.txt");
    colorCount = 0;
    string line;
    while (colorCount < MAX_COLORS && getline(ifs3, line)) {
        colors[colorCount++] = line;
    }
}

void addCar() {
    if (carCount >= MAX_CARS) {
        cout << "Список автомобилей заполнен.\n";
        return;
    }
    if (colorCount == 0) {
        cout << "Нет доступных цветов. Проверьте файл color.txt.\n";
        return;
    }
    Car c;
    cout << "Введите марку, модель и год автомобиля: ";
    cin >> c.brand >> c.model >> c.year;

    cout << "Доступные цвета:\n";
    for (int i = 0; i < colorCount; i++) {
        cout << i + 1 << ". " << colors[i] << "  ";
    }
    cout << "\nВыберите цвет (1-" << colorCount << "): ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > colorCount) {
        cout << "Неверный выбор цвета.\n";
        return;
    }
    c.color = colors[choice - 1];

    cout << "Введите номер автомобиля: ";
    cin >> c.number;
    cars[carCount++] = c;
    cout << "Автомобиль добавлен.\n";
}

void addClient() {
    if (clientCount >= MAX_CLIENTS) {
        cout << "Список клиентов заполнен.\n";
        return;
    }
    Client cl;
    cout << "Введите имя, отчество, фамилию, дату аренды (dd/mm/yyyy) и цену за день: ";
    cin >> cl.name >> cl.middle >> cl.surname >> cl.rentDate >> cl.price;
    clients[clientCount++] = cl;
    cout << "Клиент добавлен.\n";
}

void displayCars() {
    if (carCount == 0) {
        cout << "Нет доступных автомобилей.\n";
        return;
    }
    for (int i = 0; i < carCount; i++) {
        cout << cars[i].brand << " " << cars[i].model << " " << cars[i].year << " "
            << cars[i].color << " " << cars[i].number << "\n";
    }
}

void displayClients() {
    if (clientCount == 0) {
        cout << "Нет доступных клиентов.\n";
        return;
    }
    for (int i = 0; i < clientCount; i++) {
        cout << clients[i].name << " " << clients[i].middle << " " << clients[i].surname << " "
            << clients[i].rentDate << " " << clients[i].price << "\n";
    }
}

void searchCar() {
    int choice;
    cout << "Поиск автомобиля по: 1.Марке 2.Цвету 3.Номеру 4.Году\nВыбор: ";
    cin >> choice;
    string key;
    int yr = 0;
    bool first = true;
    for (int i = 0; i < carCount; i++) {
        bool match = false;
        if (first) {
            if (choice == 1) {
                cout << "Введите марку: ";
                cin >> key;
            }
            else if (choice == 2) {
                cout << "Введите цвет: ";
                cin >> key;
            }
            else if (choice == 3) {
                cout << "Введите номер: ";
                cin >> key;
            }
            else if (choice == 4) {
                cout << "Введите год: ";
                cin >> yr;
            }
            else {
                cout << "Неверный выбор.\n";
                return;
            }
            first = false;
        }
        switch (choice) {
        case 1: match = (cars[i].brand == key); break;
        case 2: match = (cars[i].color == key); break;
        case 3: match = (cars[i].number == key); break;
        case 4: match = (cars[i].year == yr); break;
        }
        if (match)
            cout << "Найден: " << cars[i].brand << " " << cars[i].model << "\n";
    }
}

void searchClient() {
    int choice;
    cout << "Поиск клиента по: 1.Фамилии 2.Диапазону цены\nВыбор: ";
    cin >> choice;
    if (choice == 1) {
        string surname;
        cout << "Введите фамилию: ";
        cin >> surname;
        for (int i = 0; i < clientCount; i++) {
            if (clients[i].surname == surname)
                cout << "Найден: " << clients[i].name << " " << clients[i].middle
                << " " << clients[i].surname << "\n";
        }
    }
    else if (choice == 2) {
        double minP, maxP;
        cout << "Введите минимальную и максимальную цену: ";
        cin >> minP >> maxP;
        for (int i = 0; i < clientCount; i++) {
            if (clients[i].price >= minP && clients[i].price <= maxP)
                cout << "Найден: " << clients[i].name << " " << clients[i].middle
                << " " << clients[i].surname << " Цена: " << clients[i].price << "\n";
        }
    }
    else {
        cout << "Неверный выбор.\n";
    }
}

void deleteEntry() {
    int choice;
    cout << "Удалить: 1.Автомобиль 2.Клиента 3.Все\nВыбор: ";
    cin >> choice;
    if (choice == 1) {
        string num;
        cout << "Введите номер автомобиля для удаления: ";
        cin >> num;
        for (int i = 0; i < carCount; i++) {
            if (cars[i].number == num) {
                for (int j = i; j < carCount - 1; j++)
                    cars[j] = cars[j + 1];
                carCount--;
                cout << "Автомобиль удалён.\n";
                return;
            }
        }
        cout << "Автомобиль не найден.\n";
    }
    else if (choice == 2) {
        string surname;
        cout << "Введите фамилию клиента для удаления: ";
        cin >> surname;
        for (int i = 0; i < clientCount; i++) {
            if (clients[i].surname == surname) {
                for (int j = i; j < clientCount - 1; j++)
                    clients[j] = clients[j + 1];
                clientCount--;
                cout << "Клиент удалён.\n";
                return;
            }
        }
        cout << "Клиент не найден.\n";
    }
    else if (choice == 3) {
        carCount = clientCount = 0;
        cout << "Все данные удалены.\n";
    }
    else {
        cout << "Неверный выбор.\n";
    }
}

int convertToDays(const string& date) {
    int d, m, y;
    char sep1, sep2;
    istringstream iss(date);
    if (!(iss >> d >> sep1 >> m >> sep2 >> y)) {
        return 0;
    }
    return y * 365 + m * 30 + d;
}

void calcDebt() {
    string surname;
    cout << "Введите фамилию клиента: ";
    cin >> surname;
    int idx = -1;
    for (int i = 0; i < clientCount; i++) {
        if (clients[i].surname == surname) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "Клиент не найден.\n";
        return;
    }
    string today;
    cout << "Введите сегодняшнюю дату (dd/mm/yyyy): ";
    cin >> today;
    int rentDays = convertToDays(clients[idx].rentDate);
    int todayDays = convertToDays(today);
    int diff = todayDays - rentDays;
    if (diff < 0) diff = 0;
    cout << "Задолженность для " << clients[idx].name << " " << clients[idx].surname
        << " составляет: " << diff * clients[idx].price << "\n";
}

int main() {
    loadData();
    int choice;
    do {
        cout << "\nМеню системы проката автомобилей:\n"
            << "1. Добавить автомобиль\n"
            << "2. Добавить клиента\n"
            << "3. Показать автомобили\n"
            << "4. Показать клиентов\n"
            << "5. Поиск (автомобиль/клиент)\n"
            << "6. Удаление (записи/всех данных)\n"
            << "7. Расчёт задолженности клиента\n"
            << "8. Выход\n"
            << "Введите ваш выбор: ";
        cin >> choice;
        switch (choice) {
        case 1: addCar(); break;
        case 2: addClient(); break;
        case 3: displayCars(); break;
        case 4: displayClients(); break;
        case 5: {
            int sub;
            cout << "Поиск: 1.Автомобиль 2.Клиент\nВыбор: ";
            cin >> sub;
            if (sub == 1)
                searchCar();
            else if (sub == 2)
                searchClient();
            else
                cout << "Неверный выбор.\n";
            break;
        }
        case 6: deleteEntry(); break;
        case 7: calcDebt(); break;
        case 8:
            cout << "Выход и сохранение данных...\n";
            saveData();
            break;
        default:
            cout << "Неверный выбор.\n";
        }
    } while (choice != 8);
    return 0;
}