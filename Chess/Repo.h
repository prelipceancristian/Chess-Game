#pragma once
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <string>

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
	virtual void add(const T& elem) override;
	virtual T& find(int key) override;
	virtual void update(const T& elem) override;
	virtual T remove(int key) override;
	virtual vector<T> get_all() override;
};

