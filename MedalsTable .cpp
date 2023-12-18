#include <iostream>

class medalstable {
private:
    size_t size; // ������ ������� �������
    unsigned int* table; // ��������� �� ������ �������

public:
    medalstable(size_t size) : size(size), table(new unsigned int[size]) {
        for (size_t i = 0; i < size; ++i) {
            table[i] = 0; // �������������� ��� �������� ������� ������
        }
    }

    // ����������� �����������
    medalstable(const medalstable& other) : size(other.size), table(new unsigned int[other.size]) {
        for (size_t i = 0; i < size; ++i) {
            table[i] = other.table[i];
        }
    }

    // �������� ������������ ������������
    medalstable& operator=(const medalstable& other) {
        if (this != &other) {
            // ������� ������ ������
            delete[] table;

            // ������� ����� ������
            size = other.size;
            table = new unsigned int[other.size];

            for (size_t i = 0; i < size; ++i) {
                table[i] = other.table[i];
            }
        }
        return *this;
    }

    // ����������� �����������
    medalstable(medalstable&& other) : size(other.size), table(other.table) {
        other.size = 0;
        other.table = nullptr;
    }

    // �������� ������������ ������������
    medalstable& operator=(medalstable&& other) {
        if (this != &other) {
            // ������� ������ ������
            delete[] table;

            // �������� ������ �� ������� �������
            size = other.size;
            table = other.table;

            other.size = 0;
            other.table = nullptr;
        }
        return *this;
    }

    // ����������
    ~medalstable() {
        delete[] table;
    }

    void add_medals(size_t country, unsigned int medals) {
        if (country >= size) {
            std::cout << "������! �������� ������ ������." << std::endl;
            return;
        }
        table[country] += medals;
    }

    void display() {
        for (size_t i = 0; i < size; ++i) {
            std::cout << "������ " << i + 1 << ": " << table[i] << " �������." << std::endl;
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

    medalstable m2 = m1; // ���������� �����������
    medalstable m3(3);
    m3.add_medals(0, 7);
    m3.add_medals(2, 3);
    m3.display();
    m3 = m1; // �������� ������������ ������������

    return 0;
}