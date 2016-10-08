#pragma config(Motor,  port2,           lfWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lbWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rfWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rbWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           l1Motor,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           l2Motor,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           l3Motor,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           l4Motor,       tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "rkCompetition.h"

void moveX(pwrF, pwrS, pwrT, pwrL, time) {
	//Moves the X-Drive
	motor[lfWheel] = pwrF;
	motor[lbWheel] = pwrS;
	motor[rfWheel] = pwrT;
	motor[rbWheel] = pwrL;
	wait1Msec(time);	
	
}
void moveF(pwr, s) {
	//Moves the Fork
	motor[l1Motor] = pwr;
	motor[l2Motor] = pwr;
	motor[l3Motor] = pwr;
	motor[l4Motor] = pwr;
	wait1Msec(s);
}

void init() { }
task auton() { 
	//Work In Progress
	moveX(127, 127, -127, -127, 100);
	moveF(63, 250);
	moveX(127, 127, -127, -127, 500);
	moveF(63, 750);
	if(SensorValue[dgtl1]) {
	moveX(127, -127, 127, -127, 1000);
	}
	else {
	moveX(-127, 127, -127, 127, 1000);
	}
	moveF(127, 750);
	
}
task userOp() {

	while(true) {
		//Moves the X-Drive through Joystick
		motor[lfWheel] = vexRT[Ch3] + vexRT[Ch4] + vexRT[Ch1];
		motor[rfWheel] = -(vexRT[Ch3] - vexRT[Ch4] - vexRT[Ch1]);
		motor[lbWheel] = vexRT[Ch3] + vexRT[Ch4] - vexRT[Ch1];
		motor[rbWheel] = -(vexRT[Ch3] - vexRT[Ch4] + vexRT[Ch1]);
		//Moves the Fork Lift through Joystick
		if(vexRT[Btn5U] == 1 || vexRT[Btn6U] == 1) {
			motor[l1Motor] = 63;
			motor[l2Motor] = 63;
			motor[l3Motor] = 63;
			motor[l4Motor] = 63;
		}
		else if(vexRT[Btn5D] == 1 || vexRT[Btn6D] == 1) {
			motor[l1Motor] = -31;
			motor[l2Motor] = -31;
			motor[l3Motor] = -31;
			motor[l4Motor] = -31;
		}
		else {
			motor[l1Motor] = 0;
			motor[l2Motor] = 0;
			motor[l3Motor] = 0;
			motor[l4Motor] = 0;
		}
}

}
void endAuton() { }
void endUserOp() { }
