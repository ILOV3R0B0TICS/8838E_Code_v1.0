#include "main.h"
#include "api.h"
#include "pid.h"
#include "robot.h"
#include "auton.h"
 using namespace pros;


//below is not accurate. I will renumber later
// auton1=red side ring side
// auton2=blue side ring side
// auton3= red side elims goal side
// autons4= blue side elims goal side
// autons5 = auto skills
//1 = no blue rings, 2 = no red rings.
  void DriveStraightAuto(){
 
  }

 void Standard_AWP_red(){// Also retuned
 
 }
 void Goal_Rush_red(){ 
 
 }

 void Ring_Rush_red(){ //done
  
  }

 void goal_safe_side_red(){ //not tested 
 
  }


 void Standard_AWP_blue(){ //done
 
  }


 void Goal_Rush_Blue(){ // incosistent, but done 
 

 }

//blue ring side touch bar bc not doing corner stack
 void goal_safe_side_blue(){
 
  }

  void Ring_Rush_blue(){ 
  
   }
 
 void skill_run(){
 

 }
 
 void autonomous(){
  if (atn == 0) {
  }else if (atn == 0) {
    DriveStraightAuto();
  }
   else if (atn == 1) {
    Standard_AWP_red();
  } 
  else if (atn ==2) {
   Standard_AWP_blue();
  } 
  else if (atn ==3) {
    Goal_Rush_red();
  } 
  else if (atn ==4) {
    Goal_Rush_Blue();
  } 
  else if (atn ==5) {
    goal_safe_side_blue();
  } 
  else if (atn ==6) {
    goal_safe_side_red();
  } 
  else if (atn ==7) {
    Ring_Rush_red();
  }
  else if (atn ==8) {
    Ring_Rush_blue();
  }
  else if (atn ==9) {
    skill_run();
  }
}