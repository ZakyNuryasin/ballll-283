#include "lcd_16x2.h"
#include "pwm_motor.h"
#include "stdio.h"
#include "speed_control.h"
#include "uart_node.h"
#include "uart_camera.h"
#include "localization.h"
#include "mekanisme_penendang.h"

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
int counterSrf = 0;
int x, y;
int a, b;

int main(void)
{
	SystemInit();

//	lcd_init();
	TM_DELAY_Init();
//	init_lcdTimer();
//	lcd_clear();
//	init_mode();
	init_proximity();
	init_speed_control();
//	init_node();
	init_camera();
	init_extender();
//	init_handle();
//	init_penendang();
	TM_ADC_Init(ADC1, TM_ADC_Channel_4);
//	init_srf();
	Delayms(5000);
//	if(GPIO_ReadInputDataBit(GPIOE,GPIO_PIN_8) == 1){
////		while(1)
////		{
////			penalty();
////		}
//	};
	fungsiautosudut();
//	else{
//		maju(150);
//		Delayms(3000);
//	}
//	tesMotor(60);

//	kiri(30);
//	Delayms(3989);

//	while(compassHeading != 0)
//	{
//		rotateAntiClockWise(30);
//	}
//
//	theta = 0;
//	Y_pos = 0;
//	X_pos = 0;
//	Y_poscmps = 0;
//	X_poscmps = 0;

//	fungsiautosudut();
//	kickBall();
//	kanan(70);
//	Delayms(1000);
//	kiri(70);
//	Delayms(1000);
//	stop();

    while(1)
    {
    	keeper();

    	readProxy();
    	proxyExtender();

//    	if(Y_pos < 2000.0)
//    		maju(70);
//    		Delayms(3000);
//    		motorSpeed(0,0,0,0);
//    		Delayms(20000);
//    		mundur(70);
//    		Delayms(3000);
//    		motorSpeed(0,0,0,0);
//    		Delayms(20000);
//    		kanan(70);
//    		Delayms(3000);
//    		motorSpeed(0,0,0,0);
//    		Delayms(20000);
//    		kiri(70);
//    		Delayms(3000);
//    		motorSpeed(0,0,0,0);
//    		Delayms(20000);

//    	else


//    	stop();


//    	maju(PID(Y_poscmps, 2000.0, 70));
//    	maju(PID(Y_poscmps, -2000.0, 50));

//    	maju(30);


    	//TES KICKER
//    	rotateClockWise(5);
    	// wajib ga boleh dikomen, bagian dari sistem:
////    	maju(30);
//    	x = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2);
//    	y = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3);
//    	a = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4);
//    	b = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);

//    	if(hindar() == 0)
//    		gotoHeadZero();
//    	handleRotateIn();
//    	kickOff1();
//    	tesRotateMap();
//    	tesMapping();
//    	getProxy();
//    	ballGet();
//    	getBall();
//    	motorSpeed(30,30,30,30);
//    	gotoXY(10,0);
//    	tesKicker();
//    	tesHandle();
//    	tesMotor(30);
//    	kiri(30);
//    	counterSrf++;
//    	if(counterSrf == 1000){
//    		tesSRF();
//    		counterSrf =0;
//    	}
//    	rotateAntiClockWise(15);
//    	gotoxyCoach();
//    	handleOff();
//    	tesSRF();
//    	keeper();
//    	startMain(OFF,OFF);

//    	getBallNew();
//    	outBall1();
//    	outBall2();
//    	Delayms(100);
//    	penalty();
//    	kickBall();
    }
}
