#ifndef SPEED_CONTROL_H_
#define SPEED_CONTROL_H_

/**
 * Includes
 */
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_tim.h>
#include <stm32f4xx_rcc.h>
#include <misc.h>
#include "tm_stm32f4_rotary_encoder.h"
#include "pwm_motor.h"
#include "stdint.h"
#include <math.h>
//#include <cmath>
#include "uart_node.h"
#include "uart_camera.h"
#include "localization.h"
#include "tm_stm32f4_hcsr04.h"
#include "tm_stm32f4_gpio.h"
#include "odometry.h"

/**
 * Functions
 */
void InitializeTimer();
void EnableTimerInterrupt();
void TIM2_IRQHandler();
//void TIM5_IRQHandler();
void init_speed_control(void);

void odoInit();
void traSinInit();
void traSinOff();
void traInit(double x, double y, double w, double time);
void traXInit(double x, double time_x);
void traYInit(double y, double time_y);
void traWInit(double w, double time_w);
void pidInit();

void calculatePosition();
void calculateTrj();
void calculatePID();

void motorSpeed(int16_t leftBackSpeed, int16_t leftFrontSpeed, int16_t righFrontSpeed, int rightBackSpeed);
void maju(int32_t pwm);
void mundur(int32_t pwm);
void kanan(int32_t pwm);
void kiri(int32_t pwm);
void timurLaut(int32_t pwm);
void tenggara(int32_t pwm);
void baratLaut(int32_t pwm);
void baratDaya(int32_t pwm);
void rotateClockWise(int32_t pwm);
void rotateAntiClockWise(int32_t pwm);
void stop();
void tesMotor(int rpm);

/**
 * Defines
 */
#define PI 3.14159265
//5 10 0    tuning yang dulu
//1.5 0 1   tuning gagal
#define KP0 2000
#define KD0 10
#define KI0 0

#define KP_W 0
#define KI_W 0
#define KD_W 0

#define KP1 1.5
#define KD1 0
#define KI1 1

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#endif //SPEED_CONTROL_H_
