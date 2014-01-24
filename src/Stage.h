
#pragma once

class Stage;

#include "ofMain.h"

#define STAGEDATAPATH "data/stage.txt"
#define BLOCK 32
#define BOUNDS 15
class Stage {
    ///////////start//////////////
private:
	int height, width;
    ofImage _image;
    //	int *chip;
    ////////////end////////////////
public:
	int *chip;
    void selectStage(int mapNum);
    void loadMap();
	void update();
	void draw(float jiki_x, float jiki_y);
    void selectNextStage();
    void selectPrevStage();
    
	Stage(const char* path);
	~Stage();
    
	bool IsAbleToGo(float x, float y);
	int IsDead(float x, float y);
	///////////////start////////////////////
	void delMapChip(float x, float y);
	int getMapChip(float x, float y);
	int getHeight();
	int getWidth();
	//////////////end////////////////
    
};


