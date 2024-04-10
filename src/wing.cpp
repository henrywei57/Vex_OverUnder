#include "vex.h"
#include "robot-config.h"

using namespace vex;

bool Front = 1;
bool Back = 1;

void Front_wings(){
    if(Front){
        ftwing.set(true);
        Front = 0;
    }
    else if(!Front){
        ftwing.set(false);
        Front = 1;
    }
}

void Back_wings(){
    if(Back){
        intawings.set(true);
        Back = 0;
    }
    else if(!Back){
        intawings.set(false);
        Back = 1;
    }
}
void togglePunnett() {

}
