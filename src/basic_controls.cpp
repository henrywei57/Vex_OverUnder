#include "basic_control.h"
#include "main.h"
#include "robot-config.h"



void keybind(){
    con.ButtonUp.pressed(puncher);
}

void puncher(){
    con.rumble(".-..-.");
}