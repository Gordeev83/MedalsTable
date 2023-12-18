#include <iostream>

class medalstable {
private:
    size_t size; // размер таблицы медалей
    unsigned int* table; // указатель на массив медалей

public:
    medalstable(size_t size) : size(size), table(new unsigned int[size]) {
        for (size_t i = 0; i < size; ++i) {
            table[i] = 0; // инициализируем все элементы таблицы нулями
        }
    }

    // Конструктор копирования
    medalstable(const medalstable& other) : size(other.size), table(new unsigned int[other.size]) {
        for (size_t i = 0; i < size; ++i) {
            table[i] = other.table[i];
        }
    }

    // Оператор присваивания копированием
    medalstable& operator=(const medalstable& other) {
        if (this != &other) {
            // Удаляем старые данные
            delete[] table;

            // Создаем новые данные
            size = other.size;
            table = new unsigned int[other.size];

            for (size_t i = 0; i < size; ++i) {
                table[i] = other.table[i];
            }
        }
        return *this;
    }

    // Конструктор перемещения
    medalstable(medalstable&& other) : size(other.size), table(other.table) {
        other.size = 0;
        other.table = nullptr;
    }

    // Оператор присваивания перемещением
    medalstable& operator=(medalstable&& other) {
        if (this != &other) {
            // Удаляем старые данные
            delete[] table;

            // Забираем данные из другого объекта
            size = other.size;
            table = other.table;

            other.size = 0;
            other.table = nullptr;
        }
        return *this;
    }

    // Деструктор
    ~medalstable() {
        delete[] table;
    }

    void add_medals(size_t country, unsigned int medals) {
        if (country >= size) {
            std::cout << "Ошибка! Неверный индекс страны." << std::endl;
            return;
        }
        table[country] += medals;
    }

    void display() {
        for (size_t i = 0; i < size; ++i) {
            std::cout << "Страна " << i + 1 << ": " << table[i] << " медалей." << std::endl;
        }
    }
};

int main() 
{
    setlocale(LC_ALL, "");
    medalstable m1(5);
    m1.add_medals(0, 10);
    m1.add_medals(1, 5);
    m1.display();

    medalstable m2 = m1; // Копирующий конструктор
    medalstable m3(3);
    m3.add_medals(0, 7);
    m3.add_medals(2, 3);
    m3.display();
    m3 = m1; // Оператор присваивания копированием

    return 0;
}