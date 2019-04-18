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

int main(void)
{
	SystemInit();

	lcd_init();
	TM_DELAY_Init();
	init_lcdTimer();
	lcd_clear();
	init_proximity();
	init_speed_control();
	init_node();
	init_camera();
	init_handle();
	init_penendang();
//	init_mode();
//	init_srf();
	Delayms(5000);

	resetInit();
	traInit(0, 0, 0, 0);
	motorSpeed(0,0,0,0);

	Delayms(3000);
//
//	traInit(0, 0, 90, 0);
//
//	Delayms(3000);
//
//	traInit(0, 0, 0, 0);

//	traInit(100, 100, 0, 0);
//
//	Delayms(3000);
//
//	traInit(0, 0, 180, 0);

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

//    	traInit(100, 0, 0, 0);
//		Delayms(5000);
//    	traInit(100, 100, 0, 0);
//		Delayms(5000);
//    	traInit(0, 0, 0, 0);
//		Delayms(5000);

    while(1)
    {
    	GPIO_SetBits(GPIOC,GPIO_Pin_1);
//    	ballGet();
//    	handleRotateIn();
//    	moveInput();
    	kickBall();
//    	maju(100);
//    	Delayms(1000);

    }
}

