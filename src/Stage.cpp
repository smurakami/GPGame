#include "Stage.h"
#include <stdlib.h>
#include <stdio.h>

#define STAGE_NUM 5
#define STAGE_CHIP_SIZE 32
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

//*--------------  GP Tree --------------*//
bool gOriginChipIsSetted = false;
int gSelectedStage = 0;
int * gOriginChip[STAGE_NUM];
int gStageWidth[STAGE_NUM];
int gStageHeight[STAGE_NUM];
char gStagePath[STAGE_NUM][100] = {
    "stage1.txt",
    "stage2.txt",
    "stage3.txt",
    "stage4.txt",
    "stage5.txt",
};

Stage::Stage(const char* path){
    _image.loadImage("block.png");
    chip = NULL;
    if(!gOriginChipIsSetted){
        FILE * fp;
        for(int n = 0; n < STAGE_NUM; n++){
            string data_path = gStagePath[n];
            fp = fopen(ofToDataPath(data_path).c_str(), "r");
            if(!fp){
                printf("Error: File \"%s\" doesn't exist.\n", gStagePath[n]);
                exit(1);
            }
            const int buffersize = 1024;
            char buffer[buffersize];
            fgets(buffer,buffersize,fp);
            gStageWidth[n] = atoi(buffer);//stage.txt‚Ìæ“ª‚ÉgStageWidth
            fgets(buffer,buffersize,fp);
            gStageHeight[n] = atoi(buffer);//ŽŸ‚Ìs‚ÉgStageHeight‚ð‘‚¢‚Ä‚¨‚­
            //ƒ}ƒbƒvƒ`ƒbƒv‚ð“ü‚ê‚é‚½‚ß‚Ì—ÌˆæŠm•Û
            gOriginChip[n] = (int *)calloc(gStageWidth[n]*gStageHeight[n],sizeof(int));
            
            //stage.txt‚©‚çƒ}ƒbƒvƒ`ƒbƒv‚ðŽæ‚èž‚ñ‚Å‚¢‚­
            int i = 0;
            while(fgets(buffer,buffersize,fp) != 0){
                char *buffer_pointer = strtok(buffer,", \n");
                while(buffer_pointer){
                    gOriginChip[n][i] = atoi(buffer_pointer);
                    i++;
                    buffer_pointer = strtok(0, ", \n");
                    ////////for debug////////
                    //printf("gOriginChip[%d] = %d\n",i-1,gOriginChip[i-1]);
                }
            }
            fclose(fp);
        }
        gOriginChipIsSetted = true;
    }
    
    selectStage(gSelectedStage);
    
}

void Stage::selectNextStage(){
    selectStage(gSelectedStage + 1);
}

void Stage::selectPrevStage(){
    selectStage(gSelectedStage - 1);
}


void Stage::selectStage(int mapNum){
    while (mapNum < 0) {
        mapNum += STAGE_NUM;
    }
    mapNum %= STAGE_NUM;
    gSelectedStage = mapNum;
    loadMap();
}

void Stage::loadMap(){
    height = gStageHeight[gSelectedStage];
    width = gStageWidth[gSelectedStage];
    
    //for Macs
    width++;
    
    if(chip != NULL) free(chip);
    
    chip = (int *)calloc(gStageWidth[gSelectedStage]*gStageHeight[gSelectedStage],sizeof(int));
    for(int i = 0; i < width * height; i++){
        chip[i] = gOriginChip[gSelectedStage][i];
    }
    
}

Stage::~Stage()
{
    free(chip);
}
//*------------- End GP Tree ------------*//

void Stage::update(){
    free(chip);
}

bool Stage::IsAbleToGo(float x, float y){
	if( chip[((int)((y-BOUNDS)/32))*width + (int)(x-BOUNDS)/32] == 1 || chip[((int)((y-BOUNDS)/32))*width + (int)(x+BOUNDS)/32] == 1 || chip[((int)((y+BOUNDS)/32))*width + (int)(x-BOUNDS)/32] == 1 || chip[((int)((y+BOUNDS)/32))*width + (int)(x+BOUNDS)/32] == 1)
		return false;
	return true;
}

int Stage::IsDead(float x, float y){
	if( chip[((int)((y-BOUNDS)/32))*width + (int)(x-BOUNDS)/32] == 2 || chip[((int)((y-BOUNDS)/32))*width + (int)(x+BOUNDS)/32] == 2 || chip[((int)((y+BOUNDS)/32))*width + (int)(x-BOUNDS)/32] == 2 || chip[((int)((y+BOUNDS)/32))*width + (int)(x+BOUNDS)/32] == 2)
		return true;
	return false;
}
////////////////start///////////////////////
int Stage::getMapChip(float x, float y){
	if( ((int)(y/32))*width + (int)(x/32) < width*height )
		return chip[((int)(y/32))*width + (int)(x/32)];
	else return 0;
}
/////////////////end//////////////////////
void Stage::draw(float jiki_x, float jiki_y){
	//ƒ}ƒbƒvƒ`ƒbƒv‚ð•`‰æ‚µ‚Ä‚¢‚­
	//‚O‹óŠÔA‚P•ÇA‚QG‚é‚ÆŽ€‚
	ofSetColor(0,255,0);//—ÎF
//	ofSetColor(255,255,255);//—ÎF
  int start_chip_x = (jiki_x - WINDOW_WIDTH/2) / STAGE_CHIP_SIZE;
  start_chip_x--;
  if(start_chip_x < 0) start_chip_x = 0;
  
  int end_chip_x = (jiki_x + WINDOW_WIDTH/2) / STAGE_CHIP_SIZE;
  end_chip_x++;
  if(end_chip_x > width) end_chip_x = width;
	for(int chip_y=0; chip_y< height;chip_y++){
		for(int chip_x = start_chip_x; chip_x < end_chip_x; chip_x++){
			if(chip[chip_y*width + chip_x] == 1)
//				_image.draw( chip_x*32 - jiki_x + ofGetWidth()/2, chip_y*32 - jiki_y + ofGetHeight()/2, 32, 32);
				ofRect( chip_x*32 - jiki_x + ofGetWidth()/2, chip_y*32 - jiki_y + ofGetHeight()/2, 32, 32);
		}
	}
}
////////////////start///////////////////////
void Stage::delMapChip(float x, float y){
	if( ((int)(y/32))*width + (int)(x/32) < width*height )
		chip[((int)(y/32))*width + (int)(x/32)] = 0;
	return ;
}
/////////////////end//////////////////////
/////////////////start///////////////////////////
//-------- Accesser ---------
int Stage::getHeight(){
	return height;
}
int Stage::getWidth(){
	return width;
}
///////////////////end//////////////////////////
