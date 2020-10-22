

#ifndef Dungeon_h
#define Dungeon_h

#include <string>
#include <iostream>

class Dungeon
{
	public:		
		void GenerateNoiseMap(int xSize, int ySize, int threshold);
		void DrawNoiseMap();

	private:
		bool NoiseMap[230][60];
		bool DungeonMap[230][60];
		int StartX, StartY;
};

#endif