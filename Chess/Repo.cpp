#include "Repo.h"
template <typename T>
void Repo<T>::add(const T& elem)
{
	auto it = this->elems.find(elem.get_id());
	if (it != this->elems.end())
		throw RepoException("An entity with this id already exists!");
	this->elems.insert({elem.get_id(), elem});
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
	this->elems.erase(key);
}

template <typename T>
vector<T> Repo<T>::get_all()
{
	vector<T> all;
	for_each(
		this->elems.begin(),
		this->elems.end(),
		[&all](const auto& elem)
		{
			all.push_back(elem.second);
		}
	);
	return all;
}