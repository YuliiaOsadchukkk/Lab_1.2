
// SetInt.h
#pragma once
#include <iostream>

class SetInt
{
	int* _set = nullptr;
	size_t _size = 0;

	void AddItem(const int& val);
public:
	SetInt(size_t count = 0, ...);

	bool HasItem(const int& val) const;
	const int* GetSet() const;
	size_t GetSize() const;
	SetInt* Copy() const;
	void Display() const;
	void Read();

	static SetInt* merge(const SetInt& set, const SetInt& set2);
	static SetInt* difference(const SetInt& set, const SetInt& set2);
	static SetInt* crossing(const SetInt& set, const SetInt& set2);

	static SetInt* make(size_t count = 0, ...);
	~SetInt();
};