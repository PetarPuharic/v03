#pragma once
#include <string>

namespace vsite::oop::v3 {

    class student {
    public:
        student(const std::string& name = "", int grade = 0);  //default value
        std::string name;
        int grade;
    };

    class results {
    public:
		results(size_t capacity); //size_t -> unigned long long
        ~results(); //destruktor
        void add(const student& s);
        unsigned int has_grade(int grade) const;
        unsigned int starts_with_letter(char letter) const;

    private:
        student* students;
        size_t capacity;
        size_t count;
    };

    class array {
    public:
        array();
        array(size_t size, double value);
        array(const array& other);
        array(array&& other) noexcept;
        ~array();

        array& operator=(const array& other);
        array& operator=(array&& other) noexcept;

        unsigned int size() const;
        double at(int index) const;
        void push_back(double value);

    private:
        double* data;
        size_t length;
    };

} // namespace vsite::oop::v3