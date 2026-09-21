
#include "main.h"
#include "api.h"
#include "pid.h"
#include "robot.h"
#include "auton.h"
bool stay_clamp = true;

using namespace pros;
using namespace std;

int atn = 0;
string autstr;
// Task colorSortTask;
// bool colorSortActive = false;

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	

//auton selector

}
void disabled() { 
	// imu.tare(); 
	// while(stay_clamp = true){
	// 	MogoMech.set_value(true);
	// }
}

//void autonomous moved into just auton.cpp

void competition_initialize() {
	int pressed = 0;


	
while(true){
	if(selec.get_value() == true){
		pressed ++;
	} else {
		pressed = 0;
	}

	if(pressed ==1){
		atn++;
	}


		if(atn>9){//change number to number of autons
			atn=0;
		}
		if (atn == 0) {
			autstr = "NONE";
			con.print(0,0, "Aut 0:%s", autstr);
		}
		else if (atn ==1) {
			autstr = "RED AWP";
			con.print(0,0, "Aut 1: %s", autstr);
		}
		else if (atn ==2) {
			autstr = "BLUE AWP";
			con.print(0,0, "Aut 2: %s", autstr);
		}
		else if (atn ==3) {
			autstr = "RED GOAL E";
			con.print(0,0, "Aut 3: %s", autstr);
		}
		else if (atn ==4) {
			autstr = "BLUE GOAL E";
			con.print(0,0, "Aut 4: %s", autstr);
		}
		else if (atn ==5) {
			autstr = "BLUE GOAL Q";
			con.print(0,0, "Aut 5: %s", autstr);
		}
		else if (atn ==6) {
			autstr = "RED GOAL Q";
			con.print(0,0, "Aut 6: %s", autstr);
		}
		else if (atn ==7) {
			autstr = "Red Ring Rush";
			con.print(0,0, "Aut 7: %s", autstr);
		} 
		else if (atn ==8) {
			autstr = "Blue Ring Rush";
			con.print(0,0, "Aut 8: %s", autstr);
		}
		else if (atn ==9) {
			autstr = "SKILLS";
			con.print(0,0, "Aut 9: %s", autstr);
		}
	}

}


void opcontrol() {


bool arcToggle = true;
bool tankToggle=false;
bool StakeWingToggle=false;
double liftAngle=true;
int time =0;
bool hooks_Macro = false;
bool  hooks_Macro_Rev = false;
bool fishy_macro = false;
bool return_fishmech = false;
bool MogoMechToggle = false;
bool LBC = false;
int Macro = 0;
bool IntakePiston = false;
eyes.set_led_pwm(100);


while (true) {

//chassis drive 
int power = con.get_analog(ANALOG_LEFT_Y);
int RX = con.get_analog(ANALOG_RIGHT_X);
int turn = int(pow(RX, 3)/ 16129);
int left= power + turn; 
int right = power - turn;

// if(con.get_digital_new_press(E_CONTROLLER_DIGITAL_B)){
// 	arcToggle = !arcToggle;
// 	tankToggle = !tankToggle;
// }

if (tankToggle){
	LF.move(con.get_analog(ANALOG_LEFT_Y));
	LM.move(con.get_analog(ANALOG_LEFT_Y));
	LB.move(con.get_analog(ANALOG_LEFT_Y));
	RF.move(con.get_analog(ANALOG_RIGHT_Y));
	RM.move(con.get_analog(ANALOG_RIGHT_Y));
	RB.move(con.get_analog(ANALOG_RIGHT_Y));
}

if (arcToggle) {
LF.move(left);
LM.move(left);
LB.move(left);
RF.move(right);
RM.move(right);
RB.move(right);
}

double  chasstemp = ((RF.get_temperature() + RB.get_temperature() + LF.get_temperature() + LB.get_temperature())/4);
if (time % 50 == 0 && time % 100 !=0 && time % 150 !=0){
    con.print(0,0,"Time:%f       ", float(time2));//viewTime
} else if (time% 100 == 0 && time % 150 !=0){
    con.print(1,0,"start?%f      ", bool(InitColor));
} else if (time % 150 == 0){
    con.print(2,0,"C:%i H:%i LB:%i      ",int(chasstemp), int(Intake.get_temperature()), int(LadyBrown.get_temperature()));
}

delay(10);
time += 10;

}

}
