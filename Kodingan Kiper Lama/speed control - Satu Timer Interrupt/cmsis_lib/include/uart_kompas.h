#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include "misc.h"
#include "uart_node.h"
#include <stdint.h>
uint8_t compassDerajat;
void init_compas(void);
void USART4_IRQHandler(void);
