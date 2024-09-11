#include "Lift.h"


Lift::Lift(size_t lowerFloor, size_t upperFloor)
{
	m_lowerFloor = lowerFloor;
	m_upperFloor = upperFloor;

	m_currentFloor = lowerFloor;
	m_isOn = false;
}

Lift::~Lift()
{
}

void Lift::TurnOn()
{
	m_isOn = true;
}

void Lift::TurnOff()
{
	m_isOn = false;
}

bool Lift::GetStatus() const
{
	return m_isOn;
}

size_t Lift::GetCurrentFloor() const
{
	return m_currentFloor;
}

void Lift::SetRange(size_t lowerFloor, size_t upperFloor)
{
	m_lowerFloor = lowerFloor;
	m_upperFloor = upperFloor;

	if (m_currentFloor < m_lowerFloor) m_currentFloor = m_lowerFloor;
	if (m_currentFloor > m_upperFloor) m_currentFloor = m_upperFloor;
}

void Lift::CallLift(size_t floor)
{
	if (!m_isOn)
	{
		std::cout << "Лифт выключен" << std::endl;
		return;
	}
	
	if(floor < m_lowerFloor || floor > m_upperFloor)
	{
		std::cout << "Лифт может двигаться только в диапазоне " << m_lowerFloor << " - " << m_upperFloor << " этажи" << std::endl;
		return;
	}

	if (floor == m_currentFloor)
	{
		std::cout << "Уже на ходиться на этом этаже" << std::endl;
		return;
	}
	m_currentFloor = floor;
}
