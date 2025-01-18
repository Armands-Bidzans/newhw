#include<iostream>
#include<string>
using namespace std;

struct VIDEO_STORE {
    string FilmName;
    string Director;
    string Genre;
    string Popularity;
    string Price;
};

const int MAX_RECORDS = 100;
VIDEO_STORE videoStore[MAX_RECORDS];
int recordCount = 0;

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        cout << "Storage is full! Cannot add more records." << endl;
        return;
    }
    VIDEO_STORE newRecord;
    cin.ignore();
    cout << "Enter film name: ";
    getline(cin, newRecord.FilmName);
    cout << "Enter director: ";
    getline(cin, newRecord.Director);
    cout << "Enter genre: ";
    getline(cin, newRecord.Genre);
    cout << "Enter popularity rating: ";
    getline(cin, newRecord.Popularity);
    cout << "Enter price: ";
    getline(cin, newRecord.Price);
    videoStore[recordCount++] = newRecord;
    cout << "Record added successfully!" << endl;
}

void showAllRecords() {
    if (recordCount == 0) {
        cout << "No records to display." << endl;
        return;
    }
    for (int i = 0; i < recordCount; ++i) {
        cout << "Film Name: " << videoStore[i].FilmName << endl;
        cout << "Director: " << videoStore[i].Director << endl;
        cout << "Genre: " << videoStore[i].Genre << endl;
        cout << "Popularity: " << videoStore[i].Popularity << endl;
        cout << "Price: " << videoStore[i].Price << endl;
        cout << "-----------------------------" << endl;
    }
}

void searchByField(const string& field, const string& value) {
    bool found = false;
    for (int i = 0; i < recordCount; ++i) {
        if ((field == "FilmName" && videoStore[i].FilmName == value) ||
            (field == "Director" && videoStore[i].Director == value) ||
            (field == "Genre" && videoStore[i].Genre == value)) {
            found = true;
            cout << "Film Name: " << videoStore[i].FilmName << endl;
            cout << "Director: " << videoStore[i].Director << endl;
            cout << "Genre: " << videoStore[i].Genre << endl;
            cout << "Popularity: " << videoStore[i].Popularity << endl;
            cout << "Price: " << videoStore[i].Price << endl;
            cout << "-----------------------------" << endl;
        }
    }
    if (!found) {
        cout << "No records found for " << field << ": " << value << endl;
    }
}

void mostPopularInGenre(const string& genre) {
    int maxPopularityIndex = -1; // Переменная для хранения индекса фильма с максимальной популярностью
    int maxPopularity = -1; // Переменная для хранения значения максимальной популярности

    for (int i = 0; i < recordCount; ++i) {
        // Проверяем, совпадает ли жанр текущего фильма с указанным
        if (videoStore[i].Genre == genre) {
            string popularityStr = videoStore[i].Popularity; 
            int currentPopularity = 0; // Текущая популярность фильма, начинаем с 0

            // Проходим по каждому символу в строке Popularity
            for (size_t j = 0; j < popularityStr.length(); ++j) {
                if (isdigit(popularityStr[j])) { // Если символ является цифрой
                    // Преобразуем символ в число и добавляем к текущей популярности
                    currentPopularity = currentPopularity * 10 + (popularityStr[j] - '0');
                } else {
                    currentPopularity = -1; // Устанавливаем -1, если найден нецифровой символ
                    break; 
                }
            }

            if (currentPopularity > maxPopularity) {
                maxPopularity = currentPopularity;
                maxPopularityIndex = i; // Запоминаем индекс фильма с максимальной популярностью
            }
        }
    }

    // Проверяем, найден ли фильм с заданным жанром
    if (maxPopularityIndex != -1) {
        cout << "Most popular film in genre " << genre << ":" << endl; 
        cout << "Film Name: " << videoStore[maxPopularityIndex].FilmName << endl; 
        cout << "Director: " << videoStore[maxPopularityIndex].Director << endl; 
        cout << "Genre: " << videoStore[maxPopularityIndex].Genre << endl; 
        cout << "Popularity: " << videoStore[maxPopularityIndex].Popularity << endl; 
        cout << "Price: " << videoStore[maxPopularityIndex].Price << endl; 
    } else {
        cout << "No films found in genre: " << genre << endl;
    }
}



int main() {
    int choice;
    do {
        cout << "\n--- VIDEO STORE MENU ---" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Show All Records" << endl;
        cout << "3. Search by Film Name" << endl;
        cout << "4. Search by Director" << endl;
        cout << "5. Search by Genre" << endl;
        cout << "6. Most Popular Film in Genre" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            showAllRecords();
            break;
        case 3: {
            string name;
            cin.ignore();
            cout << "Enter film name: ";
            getline(cin, name);
            searchByField("FilmName", name);
            break;
        }
        case 4: {
            string director;
            cin.ignore();
            cout << "Enter director: ";
            getline(cin, director);
            searchByField("Director", director);
            break;
        }
        case 5: {
            string genre_search;
            cin.ignore();
            cout << "Enter genre: ";
            getline(cin, genre_search);
            searchByField("Genre", genre_search);
            break;
        }
        case 6: {
            string genre_popular;
            cin.ignore();
            cout << "Enter genre: ";
            getline(cin, genre_popular);
            mostPopularInGenre(genre_popular);
            break;
        }
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}



//struct Person
//{
//	string name;
//	string surname;
//	int age{};
//	string gender;
//	string email;
//	string isMarried;
//};
//
//
//
//
//int main() {
//
//	Person person1;
//	int choice;
//	cout << "Enter the name: ";
//	getline(cin, person1.name);
//	cout << "Enter the surname: ";
//	getline(cin, person1.surname);
//	cout << "Enter the age: ";
//	cin >> person1.age;
//	cout << "Choose your gender:\n1.Male\n2.Female" << endl;
//	cin >> choice;
//	if (choice == 1) person1.gender = "Male";
//	else if (choice == 2) person1.gender = "Female";
//	cin.ignore();
//	cout << "Enter the email: ";
//	getline(cin, person1.email);
//	cout << "You are married? ";
//	getline(cin, person1.isMarried);
//
//
//	cout << person1.name << endl;
//	cout << person1.surname << endl;
//	cout << person1.age << endl;
//	cout << person1.gender << endl;
//	cout << person1.email << endl;
//	cout << person1.isMarried << endl;
//
//
//
//}