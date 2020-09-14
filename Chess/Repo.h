#pragma once
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::runtime_error;
using std::string;

class RepoException : public runtime_error
{
private:
	string message;
public:
	RepoException(string msg) : runtime_error(msg), message(msg) {};
	string what()
	{
		return message;
	}
};

template <typename T>
class IRepo
{
public:
	virtual void add(const T& elem) = 0;
	virtual T& find(int key) = 0;
	virtual void update(const T& elem) = 0;
	virtual T remove(int key) = 0;
	virtual vector<T> get_all() = 0;
};

template <typename T>
class Repo : public IRepo<T>
{
protected:
	unordered_map<int, T> elems;
public:
	Repo() {};
	~Repo() {}
	virtual void add(const T& elem) override;
	virtual T& find(int key) override;
	virtual void update(const T& elem) override;
	virtual T remove(int key) override;
	virtual vector<T> get_all() override;
};

template <typename T>
void Repo<T>::add(const T& elem)
{
	auto it = this->elems.find(elem.get_id());
	if (it != this->elems.end())
		throw RepoException("An entity with this id already exists!");
	this->elems.insert({ elem.get_id(), elem });
}

template <typename T>
T& Repo<T>::find(int key)
{
	auto it = this->elems.find(key);
	if (it == this->elems.end())
		throw RepoException("There is no entity with this id!");
	return it->second;
}

template <typename T>
void Repo<T>::update(const T& elem)
{
	auto it = this->elems.find(elem.get_id());
	if (it == this->elems.end())
		throw RepoException("There is no entity with this id!");
	this->elems.erase(elem.get_id());
	this->elems.insert({ elem.get_id(), elem });
}

template <typename T>
T Repo<T>::remove(int key)
{
	auto it = this->elems.find(key);
	if (it == this->elems.end())
		throw RepoException("There is no entity with this id!");
	T elem = (elems.find(key))->second;
	this->elems.erase(key);
	return elem;
}

template <typename T>
vector<T> Repo<T>::get_all()
{
	vector<T> all;
	std::for_each(
		this->elems.begin(),
		this->elems.end(),
		[&all](const auto& elem)
		{
			all.push_back(elem.second);
		}
	);
	return all;
}