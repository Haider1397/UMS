#pragma once
#include<UMS/Core/Core.h>
namespace UMS
{
	template <typename T>
	class Management
	{
	public:
		Management(std::string filePath , std::string idPrefix);
		~Management();

		void addData();
		void updateData(std::string id);
		void deleteData(std::string id);
		void displayData(std::string id);
		void saveDataToFile();
		void loadDataFromFile();
		int noOfEnteries(std::ifstream& file);

	private:
		std::string generateId(int id, std::string prefix);
		int  decomposeId(std::string id);

		std::string m_filePath{};
		std::string m_idPrefix{};
		int m_idCounter{};
		int m_enteries{};
		T* m_data_array;

	};

}

template<typename T>
UMS::Management<T>::Management(std::string filePath, std::string idPrefix) :
	m_idPrefix(idPrefix),
	m_filePath(filePath)
{
	m_data_array = new T[1000];
}

template<typename T>
UMS::Management<T>::~Management()
{
	delete[] m_data_array;
}

template<typename T>
void UMS::Management<T>::addData()
{
	m_data_array[m_idCounter].inputData(generateId(m_idCounter, m_idPrefix));
	m_idCounter++;
}

template<typename T>
void UMS::Management<T>::deleteData(std::string id)
{
	if (decomposeId(id) < 0 || decomposeId(id) >= m_enteries)
	{
		std::cout << "\n Invalid ID \n";
		return;
	}
	m_data_array[decomposeId(id)].deleteData();
}

template<typename T>
void UMS::Management<T>::updateData(std::string id)
{
	if (decomposeId(id) < 0 || decomposeId(id) >= m_enteries)
	{
		std::cout << "\n Invalid ID \n";
		return;
	}
	m_data_array[decomposeId(id)].inputData(id);
}
template<typename T>
void UMS::Management<T>::displayData(std::string id)
{
	if (decomposeId(id) < 0 || decomposeId(id) >= m_enteries)
	{
		std::cout << "\n Invalid ID \n";
		return;
	}
	m_data_array[decomposeId(id)].displayData();
}

template<typename T>
void UMS::Management<T>::loadDataFromFile()
{
	std::ifstream file;

	file.open(m_filePath);

	if (!file) return;

	int m_enteries = Management::noOfEnteries(file);

	file.clear();
	file.seekg(0, std::ios::beg);

	for (int i{}; i < m_enteries; i++)
	{
		m_data_array[i].loadDataFromFile(file);
		m_idCounter++;
	}
	file.close();
}

template<typename T>
int UMS::Management<T>::noOfEnteries(std::ifstream& file)
{
	int result{};
	char ch{};
	while (!file.eof())
	{
		file.get(ch);
		if (ch == '{')
			result++;
	}
	return result;
}

template<typename T>
void UMS::Management<T>::saveDataToFile()
{
	std::ofstream file;
	file.open(m_filePath);

	if (!file) return;

	for (int i{}; i < m_idCounter; i++)
	{
		m_data_array[i].saveDataToFile(file);
	}
	file.close();
}

template<typename T>
std::string UMS::Management<T>::generateId(int id, std::string prefix)
{
	return prefix + std::to_string(id);
}

template<typename T>
int UMS::Management<T>::decomposeId(std::string id)
{
	return std::stoi(id.substr(3));
}

