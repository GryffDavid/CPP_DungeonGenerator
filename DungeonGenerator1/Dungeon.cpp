#include "Dungeon.h"

void Dungeon::GenerateNoiseMap(int xSize, int ySize, int threshold)
{
	int ArrayX = sizeof(NoiseMap) / sizeof(NoiseMap[0]);
	int ArrayY = sizeof(NoiseMap[0]);// / sizeof(bool);

	std::cout << "Array X: " << ArrayX << "\n";
	std::cout << "Array Y: " << ArrayY << "\n";

	for (int x = 0; x < ArrayX; x++)
	{
		for (int y = 0; y < ArrayY; y++)
		{
			NoiseMap[x][y] = true;
		}
	}


	//Percentage of cells that should be floor
	int floorCells = ((ArrayX * ArrayY) / 100) * threshold;

	std::cout << "Floor cells: " << floorCells << std::endl;

	do
	{
		int randX = rand() % ArrayX;
		int randY = rand() % ArrayY;

		if (NoiseMap[randX][randY] == true)
		{
			NoiseMap[randX][randY] = false;
			floorCells--;
		}
	} while (floorCells > 0);
}

void Dungeon::DrawNoiseMap()
{	
	for (int y = 0; y < sizeof(NoiseMap[0]); y++)
	{
		std::string yString = "";

		for (int x = 0; x < sizeof(NoiseMap) / sizeof(NoiseMap[0]); x++)
		{
			if (NoiseMap[x][y] == true)
			{
				yString += 'E';
			}
			else
			{
				yString += ' ';
			}
		}

		std::cout << yString << std::endl;
	}
}

