#pragma once
#include <iostream>

class Lift
{
public:
	Lift(size_t lowerFloor = 1, size_t upperFloor = 1);
	~Lift();

	void TurnOn();
	void TurnOff();

	bool GetStatus() const;
	size_t GetCurrentFloor() const;

	void SetRange(size_t lowerFloor, size_t upperFloor);
	void CallLift(size_t floor);
private:
	size_t m_upperFloor;
	size_t m_lowerFloor;
	size_t m_currentFloor;
	bool m_isOn;
};

