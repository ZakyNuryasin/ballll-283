#include "lcd_16x2.h"
#include "pwm_motor.h"
#include "stdio.h"
#include "speed_control.h"
#include "uart_node.h"
#include "uart_camera.h"
#include "localization.h"
#include "mekanisme_penendang.h"
#include <math.h>


/* Luas Lapangan :
 * Real : 7,2 x 4,8
 * Virtual : 200 x 133
 * */

/*
 * Variables
 */
extern uint8_t ballYCoor;
extern float Y_pos, Y_poscmps;
extern float X_pos, X_poscmps;
extern float theta;
extern float sudut;
int counterSrf = 0;
int w, x, y, z;

double inputx = 50.0;
double inputy = 0.0;
double inputw = 0.0;
double sudutw = 0.707106781;

extern uint8_t robotSelect;
extern uint8_t nomorRobot;
extern uint8_t controlMode;


int main(void)
{
	SystemInit();

	TM_DELAY_Init();

	init_node();
	init_camera();
	init_handle();
	init_proximity();
	init_penendang();
	init_speed_control();

	controlMode = 1;
	stop();

//	init_mode();
//	init_srf();

	Delayms(5000);

	fungsiautosudut();

	resetInit();

	controlMode = 0;

//	traInit(0, 0, 0, 0);
//	motorSpeed(0,0,0,0);

	Delayms(1000);

//	if(GPIO_ReadInputDataBit(GPIOE,GPIO_PIN_8) == 1){
////		while(1)
////		{
////			penalty();
////		}
//	}
//	else{
//		maju(150);
//		Delayms(3000);
//	}

//	for(int i = 0; i < 5; i++)
//	{
//		traInit(0, 100, 0, 0);
//		Delayms(3000);
//		traInit(0, 0, 0, 0);
//		Delayms(3000);
//	}

//	traInit(100, 0, 0, 0);
//	Delayms(3000);
//	traInit(100, 100, 90, 0);
//	Delayms(3000);
//	traInit(100, 100, 0, 0);
//	Delayms(3000);
//	traInit(0, 0, 180, 0);

//	traInit(0, 0, 90,0);
//	Delayms(3000);
//	traInit(0, 0, 180,0);
//	Delayms(3000);
//	traInit(0, 0, 270, 0);
//	Delayms(3000);
//	traInit(0, 0, 0, 0);

//	traInit(-150, -150, 90, 0);
//	Delayms(3000);
//	traInit(0, 0, 180, 0);
//	Delayms(3000);

//	traInit(0, 0, 315, 0);
//	Delayms(2000);
//	traInit(0, 200, 315, 0);

	controlMode = 1;

	stop();

	handleRotateIn();

    while(1)
    {


    	getProxy();
//    	GPIO_SetBits(GPIOC,GPIO_Pin_1);



//    	traInit(0, -100, 0,0);
//    	ballGet();

//		maju(15000);
//
//    	if(ballGet())
//    	{
//    		handleOff(); cx
//    		Delayms(500);
//    		handleRotateOut();
//    		Delayms(100);
//    	}
//    	else {
//    		handleRotateIn();
//		}


//    	moveInput();
//    	kickBall();
//    	maju(100);
//    	Delayms(1000);
    }
}

