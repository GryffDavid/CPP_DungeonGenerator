#include "Dungeon.h"

template<class T>
constexpr const T& clamp(const T& v, const T& lo, const T& hi)
{
	assert(!(hi < lo));
	return (v < lo) ? lo : (hi < v) ? hi : v;
}

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

void Dungeon::SmoothDungeon()
{
	for (int x = 0; x < sizeof(NoiseMap) / sizeof(NoiseMap[0]); x++)
	{
		for (int y = 0; y < sizeof(NoiseMap[0]); y++)
		{
			bool alive = NoiseMap[x][y];
			int aliveCount = 0;

			//Count alive neighbours
			for (int xTest = -1; xTest < 2; xTest++)
			{
				for (int yTest = -1; yTest < 2; yTest++)
				{
					if (!(xTest == 0 && yTest == 0))
					{
						int xClamp = clamp(x + xTest, 0, (int)(sizeof(NoiseMap) / sizeof(NoiseMap[0]) - 1));
						int yClamp = clamp(y + yTest, 0, (int)(sizeof(NoiseMap[0]) - 1));

						if (NoiseMap[xClamp][yClamp] == true)
							aliveCount++;
					}
				}
			}

			if (alive == false && aliveCount >= 5)
			{
				NoiseMap[x][y] = true;
			}

			if (alive == true && aliveCount < 4)
			{
				NoiseMap[x][y] = false;
			}
		}
	}
}

