
#include "mekanisme_penendang.h"

/*
 * Variables
 */

/*
 * inisialisasi handle
 */
void init_handle(){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

}
void init_extender()
{
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOD, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOD, &GPIO_InitStructure);

}
void init_proximity()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);


	proxyRight = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4);
	proxyUp = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);
	proxyLeft = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6);

}

void extenderLeft()
{
	GPIO_ResetBits(GPIOD,GPIO_Pin_10);
}
void extenderRight()
{
	GPIO_ResetBits(GPIOD,GPIO_Pin_8);
}
void extenderUp()
{
	GPIO_ResetBits(GPIOD,GPIO_Pin_9);
}
void extenderOff()
{
	GPIO_SetBits(GPIOD,GPIO_Pin_8);
	GPIO_SetBits(GPIOD,GPIO_Pin_9);
	GPIO_SetBits(GPIOD,GPIO_Pin_10);
}

void proxy()
{
//	GPIO_SetBits(GPIOC,GPIO_Pin_4);
//	GPIO_SetBits(GPIOC,GPIO_Pin_5);
//	GPIO_SetBits(GPIOC,GPIO_Pin_6);
}
void testExtender()
{
	extenderRight();
//	delayms(1000);
	extenderUp();
//	delayms(1000);
	extenderLeft();
//	delayms(1000);
	extenderOff();
}
void testProxy()
{
	while(proxyLeft==1)
	{
		extenderLeft();
	}
	while(proxyUp==1)
	{
		extenderUp();
	}
	while(proxyRight==1)
	{
		extenderRight();
	}
}

/*
 * inisialisasi penendang
 */
void init_penendang(){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOE, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/*
 * gerakan handle masuk kearah robot
 */
void handleRotateIn(){
	GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	GPIO_SetBits(GPIOB,GPIO_Pin_4);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
}

/*
 * gerakan handle kiri masuk
 */
void leftHandleRotateIn()
{
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	GPIO_ResetBits(GPIOB,GPIO_Pin_1);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);
}

/*
 * gerakan handle kanan masuk
 */
void rightHandleRotateIn()
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	GPIO_ResetBits(GPIOB,GPIO_Pin_1);
	GPIO_SetBits(GPIOB,GPIO_Pin_8);
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);
}

/*
 * gerakan handle keluar robot
 */
void handleRotateOut(){
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	GPIO_SetBits(GPIOB,GPIO_Pin_1);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	GPIO_SetBits(GPIOB,GPIO_Pin_9);
}

/*
 * handle berhenti
 */
void handleOff(){
//	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
//	GPIO_ResetBits(GPIOB,GPIO_Pin_1);
//	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
//	GPIO_ResetBits(GPIOB,GPIO_Pin_9);
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
	GPIO_SetBits(GPIOB,GPIO_Pin_4);
	GPIO_SetBits(GPIOB,GPIO_Pin_8);
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
}

/*
 * gerakan solenoid tendang bola
 */
void kickBall(){
	kick(ON);
	Delayms(1000);
//	kick(OFF);
//	Delayms(50);
}

/*
 * fungsi tendang
 */
void kick(bool mode){
	if(mode == true){
		GPIO_SetBits(GPIOE,GPIO_Pin_11);
	}
	else{
		GPIO_ResetBits(GPIOE,GPIO_Pin_11);
	}
}

/*
 * tes semua gerakan handle
 */
void tesHandle(){
	handleRotateIn();
	Delayms(2000);
	handleRotateOut();
	Delayms(2000);
	leftHandleRotateIn();
	Delayms(2000);
	rightHandleRotateIn();
	Delayms(2000);
	handleOff();
	Delayms(2000);
}
