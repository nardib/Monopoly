//made by: Lorenzo Nardin 2066609

#include "Cell.h"

//constructor with the CellType as argument
Cell::Cell (CellType c) : type {c}, property_check {0}, p1 {false}, p2 {false}, p3 {false}, p4 {false}, b {Building::None}
{
	if(c == CellType::Start)
	{
		p1 == true;
		p2 == true;
		p3 == true;
		p4 == true;
	}

}

//set the new owner
void Cell::buy_property(int p)
{
	if(property_check == 0 && !(p < 1 || p > 4))
		property_check = p;
	else
		throw std::invalid_argument("The player must be valid or the property is already bought");
}

//upgrade the building in that cell
void Cell::upgrade_building()
{	
	//if property is not owned I can't upgrade it
	if(property_check != 0)
	{
		if(b == Building::None)
			b = Building::House;
		else if(b == Building::House)
			b = Building::Hotel;
	}
}

//overload operator<< for enum CellType
std::ostream& operator<< (std::ostream& out, CellType c)
{
	switch (c)
	{
		case CellType::Start:
			return out << 'P';
			break;
		case CellType::Void:
			return out << ' ';
			break;
		case CellType::Economic:
			return out << 'E';
			break;
		case CellType::Standard:
			return out << 'S';
			break;
		case CellType::Luxury:
			return out << 'L';
			break;
		default:
			throw std::invalid_argument("invalid CellType");
			break;
	}
	return out;
}

//overload operator<< for enum Building
std::ostream& operator<< (std::ostream& out, Building b)
{
	switch (b)
	{
		case Building::None:
			return out;
			break;
		case Building::House:
			return out << '*';
		case Building::Hotel:
			return out << '^';
			break;
		default:
			throw std::invalid_argument("invalid Building");
			break;
	}
	return out;
}

//overload operator<< for class Cell
std::ostream& operator<< (std::ostream& out, Cell cell)
{
	std::cout << "| ";
	std::cout << cell.return_type() << cell.what_building();
	if(cell.p1)
		std::cout << '1';
	if(cell.p2)
		std::cout << '2';
	if(cell.p3)
		std::cout << '3';
	if(cell.p4)
		std::cout << '4';
	return out << " |";
}