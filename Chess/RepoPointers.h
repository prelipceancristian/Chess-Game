#pragma once
#include <unordered_map>
#include "Repo.h"

using std::unordered_map;

template <typename T>
class IRepoPointers
{
public:
	virtual void add(T* elem) = 0;
	virtual T* find(int id) = 0; // maybe return a copy or an actual T object instead of the pointer?
	virtual T* remove(int id) = 0;
	virtual void update(T* elem) = 0;
	virtual vector<T*> get_all() = 0;
	virtual void clear_all() = 0;
};

template <typename T>
class RepoPointers : public IRepoPointers<T> 
{
private:
	unordered_map<int, T*> elems;
public:
	RepoPointers() {};
	~RepoPointers() {};
	virtual void add(T* elem) override;
	virtual T* find(int id) override; // maybe return a copy or an actual T object instead of the pointer?
	virtual T* remove(int id) override;
	virtual void update(T* elem) override;
	virtual vector<T*> get_all() override;
	virtual void clear_all() override;
};

template <typename T>
void RepoPointers<T>::add(T* elem)
{
	auto it = this->elems.find(elem->get_id());
	if (it != this->elems.end())
		throw RepoException("There already is an entity with this id!");
	this->elems.insert({ elem->get_id(), elem });
}

template <typename T>
T* RepoPointers<T>::find(int id)
{
	auto it = this->elems.find(id);
	if (it == this->elems.end())
		throw RepoException("There is no enitiy with this id");
	return it->second;	
}

template <typename T>
T* RepoPointers<T>::remove(int key)
{
	auto it = this->elems.find(key);
	if (it == this->elems.end())
		throw RepoException("There is no entity with this id!");
	T* elem = (elems.find(key))->second;
	this->elems.erase(key);
	return elem;
}

template <typename T>
void RepoPointers<T>::update(T* elem)
{
	auto it = this->elems.find(elem->get_id());
	if (it == this->elems.end())
		throw RepoException("There is no entity with this id!");
	this->elems.erase(elem->get_id());
	this->elems.insert({ elem->get_id(), elem });
}

template <typename T>
vector<T*> RepoPointers<T>::get_all()
{
	vector<T*> all;
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

template <typename T>
void RepoPointers<T>::clear_all()
{
	this->elems.clear();
}
