#include"Lift.h"

void PrintLiftInfo(Lift const& lift)
{
	std::cout << lift.GetStatus() << std::endl;

	std::cout << "Текущий этаж " << lift.GetCurrentFloor() << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Lift lift(1,5);

	lift.SetRange(1, 5);

	PrintLiftInfo(lift);

	lift.TurnOn();

	PrintLiftInfo(lift);

	lift.CallLift(8);

	PrintLiftInfo(lift);

	lift.TurnOff();

	PrintLiftInfo(lift);

	return 1;
}