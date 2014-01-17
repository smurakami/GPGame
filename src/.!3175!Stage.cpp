#include "Stage.h"
#include <stdlib.h>
#include <stdio.h>

#define STAGE_NUM 5

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

    chip = NULL;
    if(!gOriginChipIsSetted){
        FILE * fp;
        for(int n = 0; n < STAGE_NUM; n++){
            string data_path = gStagePath[n];
            cout << "datapath:" << ofToDataPath(data_path) << endl;
            fp = fopen(ofToDataPath(data_path).c_str(), "r");
            if(!fp){
                printf("Error: File \"%s\" doesn't exist.\n", gStagePath[n]);
                exit(1);
            }
            const int buffersize = 1024;
            char buffer[buffersize];
            fgets(buffer,buffersize,fp);
