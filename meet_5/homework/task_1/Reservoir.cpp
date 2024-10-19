#include "Reservoir.h"

Reservoir::Reservoir() :m_name{ "Noname" }, m_type{ "Notype" }, m_length{ 0 }, m_width{ 0 }, m_depth{ 0 }
{
}

Reservoir::Reservoir(double number) :m_name{ "Noname" }, m_type{ "Notype" }, m_length{number}, m_width{number}, m_depth{number}
{
}

Reservoir::Reservoir(std::string name, std::string type, double length, double width, double depth)
	:m_name{ name }, m_type{ type }, m_length{ length }, m_width{ width }, m_depth{ depth }
{
}

Reservoir::Reservoir(const Reservoir& other)
{
	if (this != &other)
	{
		m_name = other.m_name;
		m_type = other.m_type;
		m_length = other.m_length;
		m_width = other.m_width;
		m_depth = other.m_depth;
	}
}

double Reservoir::СountVolume() const
{
	return m_length * m_width * m_depth;
}

double Reservoir::CountSquare() const
{
	return m_length * m_width;
}
//типы одинаковы?
bool Reservoir::CompareType(const Reservoir& other) const
{
	return (m_type == other.m_type);
}
//площадь первого больше второго?
bool Reservoir::CompareSquare(const Reservoir& other) const 
{
	if (CompareType(other))
	{
		if (CountSquare() > other.CountSquare())
		{
			return true;
		}
	}
	return false;
}

void Reservoir::AddToVector(std::vector<Reservoir>& vector) const
{
	vector.push_back(*this);
}

void Reservoir::DelFromVector(std::vector<Reservoir>& vector)
{
	for (size_t i = 0;i< vector.size();i++)
	{
		if (vector[i] == *this)
		{
			vector.erase(vector.begin() + i);
		}
	}

}

void Reservoir::SaveToFile(std::string const& fileName) const
{
	std::ofstream out(fileName);
	out << *this;
}

bool Reservoir::operator==(const Reservoir& other) const
{
	if (m_name == other.m_name
		&& m_type == other.m_type
		&& m_length == other.m_length
		&& m_width == other.m_width
		&& m_depth == other.m_depth)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Reservoir& reservoir)
{
	out << "name:";
	out << reservoir.m_name << std::endl;
	out << "type:";
	out << reservoir.m_type << std::endl;
	out << "length:";
	out << reservoir.m_length << std::endl;
	out << "width:";
	out << reservoir.m_width << std::endl;
	out << "depth:";
	out << reservoir.m_depth << std::endl;
	return out;
}
