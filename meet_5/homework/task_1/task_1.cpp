#include "Reservoir.h"


int main()
{
	std::vector<Reservoir> reservoirs;
	Reservoir reservoir( "1","2",3,4,5 );
	reservoir.AddToVector(reservoirs);
	std::cout<<reservoirs[0]<<std::endl;
	reservoir.DelFromVector(reservoirs);
	//std::cout << reservoirs[0] << std::endl;
	std::cout << reservoir;
	reservoir.SaveToFile("1.txt");
}
