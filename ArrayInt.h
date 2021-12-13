#pragma once
#ifndef ARRAYINT_H
#define ARRAYINT_H
#include <cassert>
#include <algorithm>
class ArrayInt {
private:
	int* m_data;
	int m_length;

	
	void m_sort(int first, int last)
	{
		int i = first;
		int j = last;

		int x = m_data[(first + last) / 2];

		do
		{
			while (m_data[i] < x) i++;
			while (m_data[j] > x) j--;

			if (i <= j)
			{
				swap(m_data[i], m_data[j]);
				i++;
				j--;
			}
		} while (i <= j);

		if (i < last) m_sort(i, last);
		if (first < j) m_sort(first, j);
	}
	
public:
	ArrayInt() : m_length(0), m_data(nullptr) {}

	ArrayInt(int length) : m_length(length) {
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	~ArrayInt() {
		delete[] m_data;
	}
	int size() const {
		return m_length;
	}
	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
		
	void clear() {
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	void resize(int newLength) {
		assert(newLength >= 0);

		if (m_length == newLength)
			return;

		if (newLength == 0)
			clear();

		int* data = new int[newLength];
		if (m_length > 0) {
			int elementToCopy = (newLength > m_length) ? m_length : newLength;
			for (int i = 0; i < elementToCopy; i++) {
				data[i] = m_data[i];
			}
		}
		delete[] m_data;
		m_data = data;
		m_length = newLength;
	}

	void pop_back() {
		
		int* data = new int[m_length--];
		for (int i = 0; i < m_length; ++i)
			data[i] = m_data[i];
				
		delete[] m_data;
		m_data = data;
		m_length;
	}

	void pop_front() {
	
		int* data = new int[--m_length];
		for (int i = 0; i < m_length; ++i)
			data[i] = m_data[i+1];
		
		delete[] m_data;
		m_data = data;
		m_length;
	}

	
	void sort()
	{
		m_sort(0, m_length - 1);
	
	}
		
	
	void print() {
		for (int i = 0; i < m_length; i++) {
			cout << m_data[i] << " ";
		}

	};

};
#endif