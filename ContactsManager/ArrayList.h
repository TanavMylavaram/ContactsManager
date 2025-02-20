#pragma once
#include <iostream>

using namespace std;

template <typename T> class ArrayList {
public:
    ArrayList() : m_Capacity(0), m_Size(0) { m_Elements = new T[m_Capacity]; }

    ArrayList(int capacity) {
        m_Capacity = capacity;
        m_Elements = new T[m_Capacity];
        m_Size = 0;
    }

    ~ArrayList()
    {
        delete[] m_Elements;
    }

    void addElement(T element) {
        if (m_Size == m_Capacity) {
            updateCapacity();
        }
        m_Elements[m_Size] = element;
        // cout << m_Size << endl;
        m_Size++;
    }

    T& operator[](int index) {
        if (index < 0 || index >= m_Size) {
            throw out_of_range("Index out of bounds");
        }
        return m_Elements[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= m_Size) {
            throw out_of_range("Index out of bounds");
        }
        return m_Elements[index];
    }

    void selectonSort() {
        for (int i = 0; i < m_Size - 1; i++) {
            // Assume the smallest value is located at the current 'i' position
            int minIndex = i;
            // Check the rest of the array to see if there's a smaller element
            for (int j = i + 1; j < m_Size; j++) {
                if (m_Elements[j] < m_Elements[minIndex]) {
                    minIndex =
                        j; // Update the minIndex with the index of the new smallest value
                }
            }

            // If the minimum isn't in the position, swap it with the current 'i'
            // value
            if (minIndex != i) {
                swap(m_Elements[i], m_Elements[minIndex]);
            }
        }
    }

    void removeElement(T element) {
        // Iterate over all elements
        for (int i = 0; i < m_Size; i++) {
            // If we find the element to be removed
            if (m_Elements[i] == element) {
                // Shift all subsequent elements to the left
                for (int j = i; j < m_Size - 1; j++) {
                    m_Elements[j] = m_Elements[j + 1];
                }
                // Decrease the size of the array list
                m_Size--;
                return;
            }
        }
    }

    int size() const {

        return m_Size;
    }

    void clear() {

        if (m_Size == 0) {

            return;
        }
        else {
            for (int i = 0; i < m_Size; i++) {
                removeElement(m_Elements[i]);
            }
        }

    }

private:
    void updateCapacity() {
        // cout << "Increasing Capacity" << endl;

        int newCapacity;
        if (m_Capacity == 0) {
            newCapacity = 1;
        }
        else {
            newCapacity = m_Capacity * 2;
        }

        T* newElements = new T[newCapacity]();
        for (int i = 0; i < m_Size; i++) {
            newElements[i] = m_Elements[i];
        }

        delete[] m_Elements;
        m_Elements = newElements;
        m_Capacity = newCapacity;
    }

protected:
    T* m_Elements; // Pointer to the first element of our dynamic array
private:
    int m_Capacity; // The total size of the currently allocated array
    int m_Size;     // The current number of elements in the array
};