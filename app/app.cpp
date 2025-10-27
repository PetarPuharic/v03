#include "app.h"
#include <algorithm>
#include <cctype>

namespace vsite::oop::v3 {

    // student class implementation
    student::student(const std::string& name, int grade) : name(name), grade(grade) {}

    // results class implementation
	results::results(size_t capacity) : capacity(capacity), count(0) // constructor
		//size_t => unsigned long long, moze i unsigned int ali cop
    {
        students = new student[capacity];
    }

	results::~results() // destructor, brise heap
    {
        delete[] students;
    }

    void results::add(const student& s)
    {
        if (count < capacity)
        {
            students[count++] = s;
        }
    }

    unsigned int results::has_grade(int grade) const
    {
        unsigned int cnt = 0;
        for (int i = 0; i < count; ++i)
        {
            if (students[i].grade == grade)
            {
                ++cnt;
            }
        }
        return cnt;
    }

    unsigned int results::starts_with_letter(char letter) const
    {
        unsigned int cnt = 0;
        char lower_letter = std::tolower(static_cast<unsigned char>(letter));
        for (int i = 0; i < count; ++i)
        {
            if (!students[i].name.empty())
            {
                char first_char = std::tolower(static_cast<unsigned char>(students[i].name[0]));
                if (first_char == lower_letter)
                {
                    ++cnt;
                }
            }
        }
        return cnt;
    }

    // array class implementation
    array::array() : data(nullptr), length(0) {}

    array::array(size_t size, double value) : length(size)
    {
        data = new double[size];
        std::fill(data, data + size, value);
    }

    array::array(const array& other) : length(other.length)
    {
        data = new double[length];
        std::copy(other.data, other.data + length, data);
    }

    array::array(array&& other) noexcept : data(other.data), length(other.length)
    {
        other.data = nullptr;
        other.length = 0;
    }

    array::~array()
    {
        delete[] data;
    }

    array& array::operator=(const array& other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new double[length];
            std::copy(other.data, other.data + length, data);
        }
        return *this;
    }

    array& array::operator=(array&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }

    unsigned int array::size() const
    {
        return static_cast<unsigned int>(length);
    }

    double array::at(int index) const
    {
        if (index < 0 || static_cast<size_t>(index) >= length)
            return 0.0;
        return data[index];
    }

    void array::push_back(double value)
    {
        double* newData = new double[length + 1];
        if (data)
        {
            std::copy(data, data + length, newData);
        }
        newData[length] = value;
        delete[] data;
        data = newData;
        ++length;
    }

} // namespace vsite::oop::v3