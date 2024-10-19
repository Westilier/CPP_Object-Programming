#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Reservoir
{
public:
	Reservoir();
	explicit Reservoir(double number);
	Reservoir(std::string name,std::string type, double length, double width, double depth);
	Reservoir(const Reservoir& other);

	double ÑountVolume() const;
	double CountSquare() const;

	bool CompareType(const Reservoir& other) const;
	bool CompareSquare(const Reservoir& other) const;

	void AddToVector(std::vector<Reservoir>& vector) const;
	void DelFromVector(std::vector<Reservoir>& vector);

	void SaveToFile(std::string const& fileName) const;

	bool operator == (const Reservoir& other) const;

	friend std::ostream& operator<<(std::ostream& out, const Reservoir& Reservoir);

private:
	std::string m_name;
	std::string m_type;
	double m_length;
	double m_width;
	double m_depth;
};
