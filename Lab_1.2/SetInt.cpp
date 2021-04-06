// SetInt.cpp
#include "SetInt.h"
using namespace std;

void SetInt::AddItem(const int& val)
{
	int* tmp = new int[_size + 1];
	if (_size > 0)
		memcpy(tmp, _set, _size * sizeof(int));
	_set = tmp;
	_set[_size] = val;
	++_size;
}

SetInt::SetInt(size_t count, ...) {
	if (count == 0)
		return;

	_set = new int[_size = count];
	for (size_t i = 0; i < _size; i++)
		_set[i] = (&count + 1)[i];
}

bool SetInt::HasItem(const int& val) const
{
	for (size_t i = 0; i < _size; i++)
		if (val == _set[i])
			return true;

	return false;
}

const int* SetInt::GetSet() const
{
	return _set;
}

size_t SetInt::GetSize() const
{
	return _size;
}

SetInt* SetInt::Copy() const
{
	SetInt* tmp = new SetInt();
	tmp->_size = _size;
	tmp->_set = new int[_size];
	memcpy(tmp->_set, _set, _size * sizeof(int));
	return tmp;
}

void SetInt::Display() const
{
	for (size_t i = 0; i < _size; i++)
		cout << _set[i] << ' ';
	cout << endl;
}

void SetInt::Read()
{
	int tmp;
	char is_cnt;
	do
	{
		cout << "Input " << _size + 1 << " item of set: ";
		cin >> tmp;

		if (!HasItem(tmp))
			AddItem(tmp);
		else
			cout << "This num already in set!" << endl;

		cout << "continue(y/n): ";
		cin >> is_cnt;
	} while (is_cnt != 'n');
}

SetInt* SetInt::merge(const SetInt& set, const SetInt& set2)
{
	SetInt* tmp = set.Copy();
	for (size_t i = 0; i < set2._size; i++)
		if (!tmp->HasItem(set2._set[i]))
			tmp->AddItem(set2._set[i]);
	return tmp;
}

SetInt* SetInt::difference(const SetInt& set, const SetInt& set2)
{
	SetInt* tmp = new SetInt();
	for (unsigned int i = 0; i < set._size; i++)
		if (!set2.HasItem(set._set[i]))
			tmp->AddItem(set._set[i]);
	return tmp;
}

SetInt* SetInt::crossing(const SetInt& set, const SetInt& set2)
{
	SetInt* tmp = new SetInt();
	for (unsigned int i = 0; i < set._size; i++)
		if (set2.HasItem(set._set[i]))
			tmp->AddItem(set._set[i]);
	return tmp;
}

SetInt* SetInt::make(size_t count, ...)
{
	SetInt* obj = new SetInt();
	if (count == 0)
		return obj;

	obj->_set = new int[obj->_size = count--];
	for (; count != UINT_MAX; count--)
		obj->_set[count] = (&count + 1)[count];

	return obj;
}

SetInt::~SetInt()
{
	if (_set != nullptr)
		delete[] _set;
}


