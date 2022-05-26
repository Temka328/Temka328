#pragma once
#include <vector>
#include <math.h>
#include <initializer_list>
#include <string>

#include "../Exceptions/VectorArithmeticException.h"

template <typename T>
class Vector
{
private:
    int dimension;
    std::vector<T> storage;

    void indexCheck(const int index) const;

public:
    Vector(int dim) : dimension(dim), storage(dim){};

    Vector(int dim, std::vector<T> vector) : dimension(dim), storage(vector){};

    Vector(const Vector &vector) : dimension(vector.dimension), storage(vector.storage){};

    Vector(std::initializer_list<T> list);

    void normalize();

    T size() const;

    int getComponent(const int index) const;

    void setComponent(const int index, T value);

    int getDim() const;

    Vector<T> operator+(const Vector<T> &b) const;

    Vector<T> operator-(const Vector<T> &b) const;

    Vector<T> operator*(const T &value) const;

    Vector<T> operator/(const T &value) const;

    bool operator==(const Vector<T> &b) const;

    T &operator[](const int index);

    const T &operator[](const int index) const;

    Vector<T> &operator=(const Vector<T> &right);

    template <typename F>
    friend std::ostream &operator<<(std::ostream &out, const Vector<F> &vector);

    ~Vector() = default;
};

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) : dimension(list.size()), storage(list.size())
{
    for (int i = 0; i < dimension; i++)
    {
        storage[i] = *(list.begin() + i);
    }
}

template <typename T>
void Vector<T>::indexCheck(const int index) const
{
    if (index >= dimension || index < 0)
    {
        throw std::out_of_range(index + " >= " + dimension);
    }
}

template <typename T>
void Vector<T>::normalize()
{
    T size = this->size();
    *this = *this / size;
}

template <typename T>
T Vector<T>::size() const
{
    T sum = 0;
    for (auto component : storage)
    {
        sum += component * component;
    }
    return sqrt(sum);
}

template <typename T>
int Vector<T>::getComponent(const int index) const
{
    indexCheck(index);
    return storage[index];
}

template <typename T>
void Vector<T>::setComponent(const int index, T value)
{
    indexCheck(index);
    storage[index] = value;
}

template <typename T>
int Vector<T>::getDim() const
{
    return dimension;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &b) const
{
    if (dimension != b.dimension)
        throw VectorArithmeticException("add", dimension, b.dimension);
    Vector<T> newV(dimension);
    for (int i = 0; i < dimension; i++)
    {
        newV.storage[i] = storage[i] + b.storage[i];
    }
    return newV;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &b) const
{
    if (dimension != b.dimension)
        throw VectorArithmeticException("subtract", dimension, b.dimension);
    Vector<T> newV(dimension);
    for (int i = 0; i < dimension; i++)
    {
        newV.storage[i] = storage[i] - b.storage[i];
    }
    return newV;
}

template <typename T>
Vector<T> Vector<T>::operator*(const T &value) const
{
    Vector<T> temp(*this);
    for (auto &component : temp.storage)
    {
        component = component * value;
    }
    return temp;
}

template <typename T>
Vector<T> Vector<T>::operator/(const T &value) const
{
    Vector<T> temp(*this);
    for (auto &component : temp.storage)
    {
        component = component / value;
    }
    return temp;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &b) const
{
    double eps = 1e-6;
    if (dimension == b.dimension)
    {
        for (int i = 0; i < dimension; i++)
            if (fabs(this->storage[i] - b.storage[i]) > eps)
                return false;
        return true;
    }
    return false;
}

template <typename T>
T &Vector<T>::operator[](const int index)
{
    indexCheck(index);
    return storage[index];
}

template <typename T>
const T &Vector<T>::operator[](const int index) const
{
    indexCheck(index);
    return storage[index];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &right)
{
    if (this == &right)
    {
        return *this;
    }
    this->dimension = right.dimension;
    this->storage = right.storage;

    return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Vector<T> &vector)
{
    out << "{ ";
    for (int i = 0; i < vector.dimension - 1; i++)
    {

        out << vector[i] << ", ";
    }
    out << vector[vector.dimension - 1] << " }";
    return out;
}
